/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:50:54 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/15 11:57:26 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/fract_ol.h"

static void	ft_julia_list()
{
	int		fd;
	char	*fract;

	fd = open("files/julia_types.txt", O_RDONLY);
	if (fd < 0)
		return ;
	ft_purple();
	printf("\nSome julia's interesting fractals\n");
	printf("Try to execute\n\n");
	ft_yellow();
	printf("	./fractol.a julia <x_position> <y_position>\n");
	while (1)
	{
		fract = get_next_line(fd);
		if (!fract)
			break ;
		fract = ft_clear_str(fract);
		printf("			%s\n",fract);
	}
	ft_white();
	printf("-----------------------------------------------------------------------\n");
	close(fd);
}

static void	ft_print_list()
{
	int		fd;
	char	*fract;
	int		i;

	i = 1;
	fd = open("files/types.txt", O_RDONLY);
	if (fd < 0)
		return ;
	ft_purple();
	printf("Here some fractals ready to print then\n\n");
	ft_cyan();
	while (1)
	{
		fract = get_next_line(fd);
		if (!fract)
			break ;
		fract = ft_clear_str(fract);
		printf("%d -	%s\n",i, fract);
		i++;
	}
	ft_white();
	printf("-----------------------------------------------------------------------\n");
	ft_julia_list();
	close(fd);

}

void	ft_initials_errors()
{
	ft_red();
	printf("Error, invalid arguments\n");
	ft_white();
	printf("-----------------------------------------------------------------------\n");
	ft_green();
	printf("Try to execute: ");
	ft_purple();
	printf("./fractol.a <fractal_name>'\n");
	ft_white();
	printf("-----------------------------------------------------------------------\n");
	ft_print_list();
}