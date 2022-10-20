/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:30:32 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/20 14:00:05 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define FT_NULL '\0'

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != FT_NULL)
	{
		ft_putchar(*str);
		str += 1;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc >= 1)
		ft_putstr(argv[0]);
	return (0);
}
