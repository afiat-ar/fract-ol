/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:28:30 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/31 12:05:42 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	aux;
	unsigned char	*dst;
	size_t			i;

	aux = (unsigned char) c;
	dst = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*dst == aux)
			return (dst);
		i++;
		dst++;
	}
	return (NULL);
}
