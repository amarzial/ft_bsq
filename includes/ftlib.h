/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:13:53 by amarzial          #+#    #+#             */
/*   Updated: 2016/09/15 20:19:40 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H
# include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_atoi(char *str);

void	ft_putnbr(int nb);

int		ft_strcmp(char *s1, char *s2);

int		ft_strlen(char *str);

char	*ft_strlowcase(char *str);

char	*ft_strcpy(char *dest, char *src);

char	*ft_strstr(char *src, char *to_find);

char	*ft_strupcase(char *str);

void	ft_swap(int *a, int *b);

#endif
