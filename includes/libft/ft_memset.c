/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:27:57 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/28 10:25:24 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	aux;
	unsigned int	i;

	aux = (unsigned char) c;
	i = 0;
	while (i < (unsigned int) n)
	{
		((unsigned char *) s)[i] = aux;
		i++;
	}
	return (s);
}
