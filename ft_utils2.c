/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:25:56 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/16 20:16:30 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	result;

	result = 0;
	if (nb > 9)
	{
		result += ft_putnbr(nb / 10);
		result += ft_putnbr(nb % 10);
	}
	else
		result += ft_putchar(nb + 48);
	return (result);
}
/*
int	ft_putnbr_(unsigned int nb, int i, size_t *len)
{
	
}
*/