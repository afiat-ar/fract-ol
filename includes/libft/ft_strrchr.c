/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:40:11 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/31 10:07:50 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + size);
	while (size--)
	{
		if (*(s + size) == (char) c)
			return ((char *)(s + size));
	}
	return (NULL);
}
