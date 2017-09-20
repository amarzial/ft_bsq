/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 03:20:49 by amarzial          #+#    #+#             */
/*   Updated: 2017/09/20 19:50:28 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define B_SIZE 1024
# define TMP_FILE "/tmp/harambe"

typedef int		t_myint;

typedef struct	s_map
{
	char	*filename;
	char	props[4];
	int		file_desc;
	int		offset;
	t_myint	height;
	t_myint	width;
}				t_map;

typedef struct	s_square
{
	t_myint	x;
	t_myint	y;
	t_myint	size;
}				t_square;

t_square	*alg_bsq(t_map *mymap);

int		map_get_properties(t_map *mymap);
int		map_getwidth(t_map *mymap);
t_map	*map_load(char *filename, int from_stdin);
char	*map_getline(t_map *mymap);
void	map_close(t_map *mymap);

void	print_bsq(t_map *mymap, t_square *sqr);

int	    read_stdin(void);
#endif
