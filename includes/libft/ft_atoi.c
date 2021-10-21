/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:25:42 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/06/02 13:45:07 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_jump_spcs(char *aux)
{
	while (*aux == ' ' || *aux == '\t' || *aux == '\r'
		|| *aux == '\f' || *aux == '\v' || *aux == '\n')
		aux++;
	return (aux);
}

int	ft_check_nb_max(unsigned long long result, int mult)
{
	unsigned long long	i;

	i = 9223372036854775807;
	if (result > i)
	{
		if (mult == -1 && result != i++)
			result = 0;
		else
			result = -1;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	char				*aux;
	int					mult;
	unsigned long long	result;

	mult = 1;
	aux = (char *)str;
	result = 0;
	aux = ft_jump_spcs(aux);
	if (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			mult = -1;
		aux++;
	}
	while (*aux)
	{
		if (*aux < 48 || 57 < *aux)
			return (result * mult);
		else
			result = (result * 10) + (long long int)(*aux - '0');
		aux++;
	}
	result = ft_check_nb_max(result, mult);
	return (result * mult);
}
