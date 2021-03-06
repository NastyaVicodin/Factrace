/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:42:57 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 13:21:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

void	ft_strdel(char **as)
{
	if (as)
		ft_memdel((void **)as);
}
