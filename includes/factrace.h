/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:39:28 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/21 15:39:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRACE_H
# define FACTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <gmp.h>

# define BUFF_SIZE 128
# define ULL unsigned long long

typedef struct		s_op
{
	char			*buff;
	int				f_desu;
	struct s_op		*next;
}					t_op;

void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				*ft_memset(void *mem, int val, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memalloc(size_t size);
char				*ft_strchr(char *str, int symbol);
char				*ft_strdup(const char *src);
void				ft_wizard(char *time);
int					get_next_line(const int fd, char **line);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);
size_t				ft_count_c(char const *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putstr(char const *s);
unsigned long long	time_rdtsc();
unsigned long long	time_stop(unsigned long long tact);
void				calc_power(mpz_t *power, int pow, mpz_t end);
void				print_factor(mpz_t x, mpz_t end);
int					decomp_num(char *str, unsigned long long time);

#endif
