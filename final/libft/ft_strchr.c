/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:11:51 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 01:11:52 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	ch;

	i = 0;
	str = (char *)s;
	ch = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (ch == '\0')
		return (str + i);
	return (NULL);
}
