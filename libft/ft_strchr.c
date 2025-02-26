/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:53:08 by anvincen          #+#    #+#             */
/*   Updated: 2023/01/06 11:43:16 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buf;

	buf = (char *) s;
	while (*buf)
	{
		if (*buf == (char)c)
			return (buf);
		buf++;
	}
	if (c == 0)
		return (buf);
	return (NULL);
}
