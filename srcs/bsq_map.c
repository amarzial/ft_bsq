/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:51:03 by amarzial          #+#    #+#             */
/*   Updated: 2016/09/20 22:32:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		map_get_properties(t_map *mymap)
{
	int		offset;
	char	buffer[B_SIZE];

	offset = 0;
	while (offset < B_SIZE && read(mymap->file_desc, buffer + offset, 1) > 0)
		if (buffer[offset++] == '\n')
		{
			buffer[offset] = '\0';
			break ;
		}
	if (buffer[--offset] != '\n' || ft_strlen(buffer) < 5)
		return (1);
	mymap->offset = offset + 1;
	buffer[offset] = '\0';
	offset -= 3;
	ft_strcpy(mymap->props, buffer + (offset));
	buffer[offset] = '\0';
	while (--offset)
		if (buffer[offset] < '0' || buffer[offset] > '9')
			return (2);
	mymap->height = ft_atoi(buffer);
	if (mymap->height > 0)
		return (0);
	return (3);
}

int		map_getwidth(t_map *mymap)
{
	int		bytes_read;
	char	buff[B_SIZE + 1];
	int		size;
	int		tmp;

	size = 0;
	close(mymap->file_desc);
	mymap->file_desc = open(mymap->filename, O_RDONLY);
	read(mymap->file_desc, buff, mymap->offset);
	while ((bytes_read = read(mymap->file_desc, buff, B_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		tmp = 0;
		while (buff[tmp] != '\0')
		{
			if (buff[tmp] == '\n')
				return (size);
			size++;
			tmp++;
		}
	}
	return (0);
}

t_map	*map_load(char *filename, int from_stdin)
{
	t_map	*new_map;
	char	buf[16];

	if ((new_map = (t_map*)malloc(sizeof(t_map))))
	{
		if (!from_stdin)
			new_map->file_desc = open(filename, O_RDONLY);
		else
			new_map->file_desc = read_stdin();
		if (new_map->file_desc > 0)
		{
			new_map->filename = filename;
			if (map_get_properties(new_map) != 0)
				return (0);
			if (!(new_map->width = map_getwidth(new_map)))
				return (0);
			close(new_map->file_desc);
			if ((open(new_map->filename, O_RDONLY)) <= 0)
				return (0);
			read(new_map->file_desc, buf, new_map->offset);
			return (new_map);
		}
	}
	return (0);
}

char	*map_getline(t_map *mymap)
{
	char	*line;
	int		b_read;
	t_myint	cnt;

	if ((line = (char*)malloc(sizeof(char) * (mymap->width + 1))))
	{
		b_read = read(mymap->file_desc, line, mymap->width + 1);
		cnt = -1;
		while (++cnt < mymap->width)
		{
			if (line[cnt] != mymap->props[0] && line[cnt] != mymap->props[1])
				return (0);
		}
		if (b_read != (int)mymap->width + 1 || line[mymap->width] != '\n')
			return (0);
	}
	return (line);
}

void	map_close(t_map *mymap)
{
	if (mymap->file_desc > 0)
		close(mymap->file_desc);
	free(mymap);
}
