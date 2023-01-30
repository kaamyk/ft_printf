/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:03:43 by anvincen          #+#    #+#             */
/*   Updated: 2023/01/30 20:03:42 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

void	ft_select_arg(char *par, char last_c, va_list arg_ptr, int *ctr)
{
	/*if (last_c == 'c')
		print_c(par, va_arg(arg_ptr, int), ctr);
	else if (last_c == 'd' || last_c == 'i')
		print_d(par, va_arg(arg_ptr, int), ctr);
	else if (last_c == 's')
		print_s(par, va_arg(arg_ptr, char *), ctr);
	else if (last_c == 'p')
		print_p(par, va_arg(arg_ptr, size_t), ctr);
	else if (last_c == 'x' || last_c == 'X')
		print_x(par, va_arg(arg_ptr, unsigned int), ctr);
	else if (last_c == 'o')
		print_o(par, va_arg(arg_ptr, unsigned int), ctr);
	else if (last_c == 'u')
		print_u(par, va_arg(arg_ptr, unsigned int), ctr);
	else if (last_c == '%')
		print_pc(ctr);*/
	(void)ctr;
	(void)arg_ptr;
	printf("ft_select_arg :\n	- par == %s\n	- last_c == %c\n", par, last_c);
	return ;
}

void	ft_printpar(const char *s, int *start, va_list arg_ptr, int *ctr)
{
	char	last_c;
	char	*par;
	int		end;

	(void)arg_ptr;
	(void)ctr;
	end = *start + 1;
	while (ft_strchr("cdispxou%", s[end]))
		++end;
	par = malloc(end - *start + 2);
	par[end - *start + 1] = 0;
	last_c = s[end];
	ft_select_arg(par, last_c, arg_ptr, ctr);
	free(par);
}

void	print_non_par(const char *s, int *i, int *ctr)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] != '%' && ++(*i))
		++len;
	ctr += len;
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
	ft_printf("Bonjour %d", 10);
	return (0);
}
