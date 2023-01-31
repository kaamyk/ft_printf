/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:09:46 by anvincen          #+#    #+#             */
/*   Updated: 2023/01/31 16:34:27 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_define_prange_d(int *prange, char *par, int n, int len_n)
{
	int		precision;
	char	last_c;

	precision = 0;
	last_c = par[ft_strlen(par) - 1];
	read_field(par, prange, len_n, last_c);
	if (ft_strchr(par, '.'))
		ft_read_precision(par, &precision, len_n, last_c);
	if (*field > len_n && *field > precision)
		*prange = *field;
	if (precision > len_n && precision >= *field)
		*prange = *precision;
	if (precision == *len_n && precision == *field)
		*prange = len_n;
	if (ft_strchr_str(par, " +")
		&& (*prange == len_n && n > 0) || ft_strchr_str(par, "."))
		++(*prange);
}

void	set_n(char *res, int field, char *nb, int len_n)
{
	int	i;

	i = 0;
	while (i < field && !res[i])
		res[i++] = ' ';
	i = 0;
	while (i <= len_n)
	{
		res[field - i] = nb[len_n - i];
		++i;
	}
	free(nb);
}

void	set_minus_d(char *res, char *nb, int field)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (res[i])
		++i;
	while (nb[j] && i < field)
	{
		res[i] = nb[j];
		++i;
		++j;
	}
	while (i < field)
		res[i++] = ' ';
	free(nb);
}

char	*ft_set_res(char *par, int *field, int n, int len_n)
{
	char	*res;
	int		precision;

	read_precision(par, &precision, field, len_n);
	res = NULL;
	res = ft_calloc(*field + 1, 1);
	if (!res)
		return (NULL);
	if (ft_strchr(par, '+'))
		res = set_plus(par, res, *field, &n);
	if ((ft_strchr(par, '.') && *field <= precision) || ft_strchr(par, '0'))
		set_0(res, field, &n);
	if (ft_strchr(par, ' '))
		set_space(res, par, field, &n);
	if (!ft_strchr(par, '-'))
		set_n(res, *field, ft_itoa(n), len_n);
	else
		set_minus_d(res, ft_itoa(n), *field);
	return (res);
}

void	print_d(char *par, int n, int *ctr)
{
	char	*res;
	int		len_n;
	int		field;
	int		print_range;

	len_n = ft_nblen(n);
	field = 0;
	ft_define_prange_d(&field, par, n, len_n);
	*ctr += print_range;
	res = ft_set_res(par, &field, n, len_n);
	ft_print_result(res, field);
	free(res);
}
