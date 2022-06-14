/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:31:35 by iugolin           #+#    #+#             */
/*   Updated: 2022/06/14 17:47:00 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	check_digit(char c)
{
	if (!ft_isdigit(c) && c != '\0')
		error("Error. Digits only\n");
}

static void	check_max_min_int(unsigned long number, int sign)
{
	if ((number > 2147483648 && sign == -1)
		|| (number > 2147483647 && sign == 1))
		error("Error. MIN/MAX_INT size only\n");
}

int	ft_atoi(const char *str)
{
	unsigned long	number;
	int				sign;

	number = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	check_digit(*str);
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
		check_digit(*str);
	}
	check_max_min_int(number, sign);
	return (number * sign);
}
