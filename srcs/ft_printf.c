/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:03:43 by anvincen          #+#    #+#             */
/*   Updated: 2023/01/31 15:55:15 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_non_par(const char *s, int *i, int *ctr)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] != '%' && ++(*i))
		++len;
	printf("len == %d\n", len);
	*ctr += len;
	printf("%d\n", len);
	write(1, s, len);
	write(1, "\n", 1);
}

int	ft_printf(const char *s, ...)
{
	int		ctr;
	va_list	arg_ptr;
	int		i;

	ctr = 0;
	i = 0;
	va_start(arg_ptr, s);
	while (s[i])
	{
		printf("printf i == %d\n", i);
		if (s[i] != '%')
			print_non_par(s + i, &i, &ctr);
		else
			ft_printpar(s + i, &i, arg_ptr, &ctr);
	}
	va_end(arg_ptr);
	return (ctr);
}

int	main(void)
{
	printf("ft = %d\n", ft_printf("Bonjour %d", 10));
	return (0);
}
