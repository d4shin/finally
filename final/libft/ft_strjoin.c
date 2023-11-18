/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:12:29 by amasrour          #+#    #+#             */
/*   Updated: 2023/11/18 01:12:30 by amasrour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_norm_lol(char *s1, char *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free (s1);
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (s1)
		str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		str = malloc(ft_strlen(s2) + 1);
	if (!str)
		return (0);
	ft_norm_lol(s1, s2, str);
	free(s2);
	return (str);
}
