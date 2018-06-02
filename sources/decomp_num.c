/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:34:18 by alukyane          #+#    #+#             */
/*   Updated: 2018/04/21 18:04:25 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <factrace.h>

void	var_clean(mpz_t x, mpz_t y)
{
	mpz_clear(x);
	mpz_clear(y);
}

int		if_perfect(mpz_t x, mpz_t end, ULL time, ULL tact_first)
{
	mpz_t	power;
	int		pow;
	ULL		tact_count;

	pow = 2;
	tact_count = 0;
	while (1)
	{
		mpz_init_set(power, end);
		calc_power(&power, pow, end);
		if (mpz_cmp(x, power) == 0)
		{
			print_factor(x, end);
			mpz_clear(power);
			break ;
		}
		else
			mpz_root(end, x, ++pow);
		mpz_clear(power);
		tact_count += time_stop(tact_first);
		if (tact_count / 440000000 > (double)(time) - 150)
			return (1);
	}
	return (0);
}

void	init_vars(ULL *tact_count, mpz_t *y, mpz_t *zero)
{
	*tact_count = 0;
	mpz_init_set_str(*y, "2", 10);
	mpz_init_set_str(*zero, "0", 10);
}

int		not_perfect(mpz_t x, mpz_t end, ULL time, ULL tact_first)
{
	mpz_t	y_mod_zero[3];
	ULL		tact_count;

	init_vars(&tact_count, &y_mod_zero[0], &y_mod_zero[2]);
	while (mpz_cmp(y_mod_zero[0], end) <= 0)
	{
		mpz_init(y_mod_zero[1]);
		mpz_mod(y_mod_zero[1], x, y_mod_zero[0]);
		if (mpz_cmp(y_mod_zero[1], y_mod_zero[2]) == 0)
		{
			mpz_clear(y_mod_zero[1]);
			break ;
		}
		mpz_nextprime(y_mod_zero[0], y_mod_zero[0]);
		mpz_clear(y_mod_zero[1]);
		tact_count += time_stop(tact_first);
		if (tact_count / 440000000 > (double)(time) - 150)
		{
			var_clean(y_mod_zero[0], y_mod_zero[2]);
			return (1);
		}
	}
	print_factor(x, y_mod_zero[0]);
	var_clean(y_mod_zero[0], y_mod_zero[2]);
	return (0);
}

int		decomp_num(char *str, ULL time)
{
	mpz_t	x_end[2];
	ULL		tact_first;

	tact_first = time_rdtsc();
	mpz_init_set_str(x_end[0], str, 10);
	mpz_init(x_end[1]);
	mpz_root(x_end[1], x_end[0], 2);
	if (mpz_perfect_power_p(x_end[0]))
	{
		if (if_perfect(x_end[0], x_end[1], time, tact_first))
		{
			var_clean(x_end[1], x_end[0]);
			return (1);
		}
	}
	else
	{
		if (not_perfect(x_end[0], x_end[1], time, tact_first))
		{
			var_clean(x_end[1], x_end[0]);
			return (1);
		}
	}
	var_clean(x_end[1], x_end[0]);
	return (0);
}
