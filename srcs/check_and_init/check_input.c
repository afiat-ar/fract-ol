/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andoni <andoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:29:23 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/22 10:18:29 by andoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fract_ol.h"

char	*ft_clear_str(char *fract)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(fract) + 1);
	while (i < ft_strlen(fract))
	{
		if (fract[i] == '\n')
		{
			new_str[i] = '\0';
			break ;
		}
		new_str[i] = fract[i];
		i++;
	}
	new_str[i] = '\0';
	free(fract);
	return (new_str);
}

char	*ft_check_input(char *argv)
{
	int		fd;
	char	*fract;

	fd = open("files/types.txt", O_RDONLY);
	if (!argv || fd < 0)
		return (NULL);
	while (1)
	{
		fract = get_next_line(fd);
		if (!fract)
			break ;
		fract = ft_clear_str(fract);
		if (!ft_strncmp(fract, argv, ft_strlen(fract) + 1))
		{
			close(fd);
			return (fract);
		}
	}
	close(fd);
	return (NULL);
}
