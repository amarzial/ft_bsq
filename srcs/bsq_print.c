/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:40:26 by amarzial          #+#    #+#             */
/*   Updated: 2016/09/21 19:55:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "bsq.h"
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

void	print_bsq(t_map *mymap, t_square *sqr)
{
	int		x;
	int		y;
	char	*line;

	y = -1;
	close(mymap->file_desc);
	if ((mymap->file_desc = open(mymap->filename, O_RDONLY)) <= 0)
		return ;
	if (!(line = malloc(sizeof(char) * (mymap->width))))
		exit(1);
	read(mymap->file_desc, line, mymap->offset);
	while (++y < mymap->height)
	{
		line = map_getline(mymap);
		x = -1;
		while (++x < mymap->width)
		{
			if (x >= sqr->x && x < sqr->x + sqr->size && \
					y >= sqr->y && y < sqr->y + sqr->size)
				line[x] = mymap->props[2];
		}
		write(1, line, mymap->width);
		write(1, "\n", 1);
	}
	free(line);
}
