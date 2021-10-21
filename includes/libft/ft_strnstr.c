/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:55:07 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/31 12:49:26 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (*needle == '\0' || haystack == needle)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			x = 0;
			while (needle[x] && haystack[i + x] && i + x < len
				&& haystack[i + x] == needle[x])
				x++;
			if (needle[x] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
