/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:51:25 by wquirrel          #+#    #+#             */
/*   Updated: 2020/01/17 21:51:31 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_htoi(const char *hex)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (hex[i] == '\0' || hex[i] == 27 || hex[i] == '\200'
	|| (hex[i] != '0' && hex[i + 1] != 'x'))
		return (0);
	i = 2;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			res = 16 * res + (hex[i] - '0');
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			res = 16 * res + (hex[i] - 87);
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			res = 16 * res + (hex[i] - 55);
		else
			return (0);
		i++;
	}
	return (res);
}
