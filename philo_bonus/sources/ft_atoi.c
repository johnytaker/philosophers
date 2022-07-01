/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:31:35 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/29 09:42:27 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	check_digit(char c)
{
	if (!ft_isdigit(c) && c != '\0')
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

static int	check_max_int(unsigned long number)
{
	if (number > 2147483647)
		return (-2);
	return (number);
}

int	ft_atoi_unsigned(const char *str)
{
	unsigned long	number;

	number = 0;
	if (check_digit(*str))
		return (-2);
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		if (check_digit(*str))
			return (-2);
	}
	return (check_max_int(number));
}
