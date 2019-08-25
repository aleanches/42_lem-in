/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:22:44 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:22:46 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long int n)
{
	int		i;
	int		j;
	int		sign;
	char	nbr1[20];
	char	*nbr2;

	i = 0;
	j = 0;
	sign = n >= 0 ? 1 : -1;
	while (sign * n > 9 || sign * n < 0)
	{
		nbr1[i++] = '0' + sign * (n % 10);
		n = n / 10;
	}
	nbr1[i++] = '0' + sign * n;
	if (sign < 0)
		nbr1[i++] = '-';
	if ((nbr2 = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	nbr2[i] = '\0';
	while (i--)
		nbr2[i] = nbr1[j++];
	return (nbr2);
}
