/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 03:24:41 by amarzial          #+#    #+#             */
/*   Updated: 2016/10/22 20:20:10 by alessandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "bsq.h"
#include <stdlib.h>
#include <stdio.h>

int			min_of(int a, int b, int c)
{
	int min;

	if (a <= b && a <= c)
		min = a;
	else if (b <= a && b <= c)
		min = b;
	else
		min = c;
	return (min);
}

int			proc_line(t_myint *ln[], int y, t_map *mymap, t_square *sqr)
{
	int			x;
	char		*input;
	int			block;

	if ((input = map_getline(mymap)) == 0)
		return (0);
	x = -1;
	while (++x <= (int)mymap->width)
	{
		block = input[x] == mymap->props[0];
		if (x == 0 || y == 0)
			ln[0][x] = block;
		else if (block)
			ln[0][x] = 1 + min_of(ln[0][x - 1], ln[1][x], ln[1][x - 1]);
		else
			ln[0][x] = 0;
		if (ln[0][x] > sqr->size)
		{
			sqr->size = ln[0][x];
			sqr->x = x - (sqr->size - 1);
			sqr->y = y - (sqr->size - 1);
		}
	}
	free(input);
	return (1);
}

void		init_line(t_myint *line, int size)
{
	int	cnt;

	cnt = size;
	while (--cnt)
		line[cnt] = 0;
}

t_square	*alg_bsq(t_map *mymap)
{
	int			y;
	t_myint		*lines[3];
	t_square	*sqr;

	y = -1;
	sqr = malloc(sizeof(t_square));
	lines[0] = malloc(sizeof(t_myint) * (mymap->width + 1));
	lines[1] = malloc(sizeof(t_myint) * (mymap->width + 1));
	if (!sqr || !lines[0] || !lines[1])
		return (0);
	sqr->size = 0;
	init_line(lines[1], mymap->width + 1);
	while (++y < (int)mymap->height)
	{
		if (proc_line(lines, y, mymap, sqr) == 0)
			return (0);
		lines[2] = lines[1];
		lines[1] = lines[0];
		lines[0] = lines[2];
	}
	free(lines[0]);
	free(lines[1]);
	return (sqr);
}
