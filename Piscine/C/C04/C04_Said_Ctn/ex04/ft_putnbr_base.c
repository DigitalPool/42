/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:44:14 by ashobajo          #+#    #+#             */
/*   Updated: 2024/03/10 13:58:48 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
void	ft_putnbr_base(int nbr, char *base);
void	ft_convert_to_base(long long num, char *base);
int		main(void);
int		contains_plus_minus(char *base);

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	contains_plus_minus(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_base(char *base)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(base);
	while (i < len)
	{
		if (!isalnum(base[i]))
		{
			return (0);
		}
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		if (!contains_plus_minus(&base[i]))
			i++;
	}
	return (1);
}

void	ft_convert_to_base(long long num, char *base)
{
	int			base_len;
	char		buffer[65];
	int			i;

	base_len = ft_strlen(base);
	i = 0;
	while (num > 0)
	{
		buffer[i++] = base[num % base_len];
		num /= base_len;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	num;

	if (!ft_check_base(base))
	{
		return ;
	}
	num = nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_convert_to_base(num, base);
}

// int		main(void)
// {
// 	ft_putnbr_base(123, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(255, "poneyvif");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(49, "++--");
// 	return (0);
// }
