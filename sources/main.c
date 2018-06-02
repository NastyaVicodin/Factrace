/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:28:51 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/21 15:28:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_wizard(argv[1]);
	else
		ft_putstr("usage: factrace time");
	return (0);
}
