/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:06:21 by outaouss           #+#    #+#             */
/*   Updated: 2025/07/28 03:04:34 by outaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	x;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
			{
				ft_putchar('\\');
				x = (unsigned char)str[i];
				ft_putchar("0123456789abcdef"[x / 16]);
				ft_putchar("0123456789abcdef"[x % 16]);
			}
			i++;
		}
	}
}
