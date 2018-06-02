/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:39:48 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:48:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

size_t	ft_count_c(char const *str, char c)
{
	size_t i;

	i = 0;
	while (*str)
		if (*str++ == c)
			i++;
	return (i);
}
