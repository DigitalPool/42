/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:41:21 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/10 17:02:38 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_skip_whitespace(char *str);
int	ft_parse_sign(char *str, int *min_num);
int	ft_convert_to_int(char *str);

bool	is_plus_minus_or_digit(char c)
{
	return (c == '+' || c == '-' || isdigit(c));
}

int	ft_atoi(char *str)
{
	int	min_num;
	int	return_val;

	min_num = 0;
	return_val = 0;
	str += ft_skip_whitespace(str);
	str += ft_parse_sign(str, &min_num);
	return_val = ft_convert_to_int(str);
	if (min_num % 2 != 0)
	{
		return_val = return_val * -1;
	}
	return (return_val);
}

int	ft_skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (isspace(*str))
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_parse_sign(char *str, int *min_num)
{
	int	i;

	i = 0;
	while (*str && is_plus_minus_or_digit(*str))
	{
		if (*str == '-')
		{
			(*min_num)++;
			str++;
			i++;
		}
		else if (*str == '+')
		{
			str++;
			i++;
		}
		else
		{
			break ;
		}
	}
	return (i);
}

int	ft_convert_to_int(char *str)
{
	int	return_val;

	return_val = 0;
	while (*str)
	{
		if (isdigit(*str))
		{
			return_val = return_val * 10 + (*str - '0');
			str++;
		}
		else if ((isdigit(*(str - 1))) && (!isdigit(*str)))
		{
			break ;
		}
		else
		{
			str++;
		}
	}
	return (return_val);
}

// int main (void)
// {
// 	printf ("%i\n", ft_atoi("   ++---+-++---234535dfg--tege343"));
// 	printf ("%i\n", ft_atoi("   ---+--+1234ab567"));
// }
