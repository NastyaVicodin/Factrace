/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:48:53 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/21 15:48:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

void	print_factor(mpz_t x, mpz_t end)
{
	mpz_t	div;

	mpz_init(div);
	mpz_cdiv_q(div, x, end);
	gmp_printf("%Zd=" "%Zd*" "%Zd\n", x, end, div);
	mpz_clear(div);
}

void	calc_power(mpz_t *power, int pow, mpz_t end)
{
	int		i;

	i = 1;
	while (i++ < pow)
		mpz_mul(*power, *power, end);
}

ULL		time_rdtsc()
{
	union ticks
	{
		ULL tx;
		struct	dblword { 
		ULL tl;
		ULL th; 
		} dw;
	} t;
	t.tx = 0;
	asm("rdtsc\n": "=a"(t.dw.tl),"=d"(t.dw.th));
	t.tx = ((ULL)t.dw.th << 32) | t.dw.tl;
	return (t.tx);
}

ULL		time_stop(ULL tact)
{
	ULL current;
	ULL res;

	current = time_rdtsc();
	res = current >= tact ? current - tact : tact - current;
	return (res);
}

void	ft_wizard(char *time)
{
	char *str;

	while (get_next_line(0, &str))
	{
		if (decomp_num(str, atoi(time)))
		{
			free(str);
			break ;
		}
		free(str);
	}
}
