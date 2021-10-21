/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:55:43 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/06/01 10:56:36 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while ((i < n) && ((unsigned char)ss1[i] == (unsigned char)ss2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
