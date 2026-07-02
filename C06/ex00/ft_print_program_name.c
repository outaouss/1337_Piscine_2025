/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:57:35 by outaouss           #+#    #+#             */
/*   Updated: 2025/07/30 23:14:57 by outaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	argc += 0;
	while (argv[0][i] != '\0')
		i++;
	write(1, argv[0], i);
	write(1, "\n", 1);
	return (0);
}
