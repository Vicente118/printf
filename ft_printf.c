/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:25:52 by vdarras           #+#    #+#             */
/*   Updated: 2024/04/16 20:18:56 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find_format(va_list arg_list, char c)
{
	int	result;

	result = 0;
	if (c == 'i' || c == 'd')
		result = ft_putnbr(va_arg(arg_list, int));
	else if (c == 'u')
		result = ft_unsigned_putnbr(va_arg(arg_list, unsigned int));
	else if (c == 'c')
		result = ft_putchar(va_arg(arg_list, int));
	else if (c == 's')
		result = ft_putstr(va_arg(arg_list, char *));
	else if (c == 'x')
		result = ft_print_hexa_min(va_arg(arg_list, size_t));
	else if (c == 'X')
		result = ft_print_hexa_maj(va_arg(arg_list, size_t));
	// else if (c == 'p')
	// {
	// 	result = ft_putstr("0x");
	// 	result += ft_print_adress(va_arg(arg_list, void *));
	// }
	else if (c == '%')
		result = ft_putchar('%');
	return (result);
}

int	check_next_char(char *str)
{
	char	c;

	c = *(str + 1);
	if (c == 'i' || c == 'd' || c == 'u' || c == 'c'
		|| c == 's' || c == 'x' || c == 'X' || c == 'p'
		|| c == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	char	*str;
	va_list	arg_list;

	result = 0;
	str = (char *)format;
	va_start(arg_list, format);
	while (*str)
	{
		if (*str == '%' && check_next_char(str))
		{
			if (*(str + 1) != '\0')
			{
				result += ft_find_format(arg_list, *(str + 1));
				str++;
			}
		}
		else
			result += ft_putchar(*(str));
		str++;
	}
	va_end(arg_list);
	return (result);
}
/*
int main(void)
{
	int	a = 65819;
	int	*ptr = &a; 
	ft_printf("Bonjour j'ai %p ans", 'G', ptr);
	//printf("Bonjour j'ai %c %d %u %d ans", 'G', 1616, 58671987);
	return (0);
}
*/