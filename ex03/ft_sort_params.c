/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:04:11 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/20 13:47:47 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_NULL '\0'

void	ft_swap(int *x, int i, int j)
{
	int	tmp;

	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void	ft_putstr(char *str)
{
	char	c;

	while (*str != FT_NULL)
	{
		c = *str;
		write(1, &c, 1);
		str += 1;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1 += 1;
		s2 += 1;
	}
	if (*s1 < *s2)
		return (-1);
	else
		return (1);
}

void	quicksort(int *tab, int left, int right, char *argv[])
{
	char	*pivot;
	int		i;
	int		j;

	i = left;
	j = right;
	pivot = argv[tab[(left + right) / 2]];
	while (1)
	{
		while (ft_strcmp(argv[tab[i]], pivot) == -1)
			i += 1;
		while (ft_strcmp(argv[tab[j]], pivot) == 1)
			j -= 1;
		if (i >= j)
			break ;
		ft_swap(tab, i, j);
		i += 1;
		j -= 1;
	}
	if (left < i - 1)
		quicksort(tab, left, i - 1, argv);
	if (j + 1 < right)
		quicksort(tab, j + 1, right, argv);
}

int	main(int argc, char **argv)
{
	int	i;
	int	tab[1000000];

	i = 1;
	while (i < argc)
	{
		tab[i] = i;
		i += 1;
	}
	if (argc == 2)
		ft_putstr(argv[1]);
	else if (argc >= 3)
	{
		quicksort(tab, 1, argc - 1, argv);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[tab[i]]);
			i += 1;
		}
	}
	return (0);
}
