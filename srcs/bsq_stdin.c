/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:55:39 by amarzial          #+#    #+#             */
/*   Updated: 2016/09/20 19:41:54 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int		read_stdin(void)
{
	int		red;
	int		fd;
	char	buffer[B_SIZE];

	fd = -1;
	if ((fd = open(TMP_FILE, O_RDWR | O_CREAT | O_TRUNC, 0666)) != -1)
	{
		red = 0;
		while ((red = read(0, buffer, B_SIZE)) > 0)
		{
			write(fd, buffer, red);
		}
		close(fd);
		if ((fd = open(TMP_FILE, O_RDONLY)) <= 0)
			return (0);
		return (fd);
	}
	return (fd);
}
