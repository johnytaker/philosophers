/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:58:02 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 17:48:49 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}