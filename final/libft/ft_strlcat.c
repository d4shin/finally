/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:12:38 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 01:12:40 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	i = 0;
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (size == 0)
		return (lens);
	if (size <= lend)
		return (lens + size);
	else
	{
		i = lend;
		while (*src && i + 1 < size)
		{
			dst[i++] = *(src++);
		}
		dst[i] = 0;
		return (lens + lend);
	}
}
