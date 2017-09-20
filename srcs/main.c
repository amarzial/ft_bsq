/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:36:26 by amarzial          #+#    #+#             */
/*   Updated: 2016/10/22 20:11:06 by alessandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"
#include "bsq.h"
#include <stdlib.h>

void	printerror(void)
{
	char	*err;

	err = "map error\n";
	write(2, err, ft_strlen(err));
}

void	process_map(char *filename, int from_stdin)
{
	t_map		*mymap;
	t_square	*sqr;
	char		*buff[16];

	if ((mymap = map_load(filename, from_stdin)) == 0)
	{
		printerror();
		return ;
	}
	if ((sqr = alg_bsq(mymap)) == 0)
	{
		printerror();
		return ;
	}
	if ((read(mymap->file_desc, buff, 16)) > 0)
	{
		printerror();
		return ;
	}
	print_bsq(mymap, sqr);
	free(sqr);
	map_close(mymap);
}

int		main(int argc, char *argv[])
{
	int			cnt;

	if (argc == 1)
		process_map(TMP_FILE, 1);
	else
	{
		cnt = 0;
		while (++cnt < argc)
		{
			process_map(argv[cnt], 0);
			if (cnt < argc - 1)
				ft_putchar('\n');
		}
	}
	return (0);
}
