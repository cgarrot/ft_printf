/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:24:10 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 14:54:41 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	unsigned int		hashtag;
	unsigned int		zero;
	unsigned int		minus;
	unsigned int		plus;
	unsigned int		point;
	unsigned int		space;
	char				flag;
	unsigned int		width;
	unsigned int		precision;
	unsigned int		percent;
	unsigned int		_l;
	unsigned int		_h;
	unsigned int		_L;
	unsigned int		nb_caract;
	int					tmp;
}				t_flags;

typedef struct	s_compt
{
	int					i;
	int					j;
	int					m;
	int					nb;
	char				*num;
	char				*num2;
}				t_compt;

typedef struct	s_args
{
	char				*_s;
	int					_d;
	long long			_ld;
	char				_c;
	unsigned int		_u;
	unsigned long long	_lu;
	long long			_x;
	unsigned long		_o;
	void				*_p;
	double				_f;
}				t_args;

typedef struct s_check_str
{
	unsigned int		precision;
	unsigned int		width;
	unsigned int		minus;
	unsigned int		zero;
	int					size;
	char				*str;
}				t_check_str;

typedef struct s_check_digit
{
	char				*num;
	int					yn;
	int					unplus;
	int					space;
	long long			negdig;
}				t_check_digit;

typedef struct s_check_octa
{
	int					size;
	char				*str;
	int					surplus;
	int					tmp;
}				t_check_octa;

typedef struct s_check_hexa
{
	int					size;
	char				*str;
	int					surplus;
}				t_check_hexa;

//parse
int				chose_flag(t_flags flags, va_list va, int nb);
int				parse(char *str, va_list va);
t_flags			compt_flags(t_flags flags, t_compt compt, char *str);
int				give_info(t_compt *compt, t_flags flags,
		va_list va, char *str);
t_compt			print_car(t_compt compt, char *str);
int				chose_for_digit(t_flags flags, va_list va,
		int nb, t_args args);
int				chose_other_digit(t_flags flags, va_list va,
		int nb, t_args args);

//init
t_check_str		init_str(t_flags flags, int size, char *str);
t_flags			init(t_flags flags);
t_check_digit	init_digit(t_check_digit c_dig, long long digit);

//utils
int				ft_isflags(char c);
int				ft_atoi_2(char const *str);
char			*ft_strrev(char *str);
void			ft_putnstr(char const *s, int size);
void			ft_putncaract(char c, int size);
char			*ft_strcapitalize(char *str);
int				put_ret(char *str, int len);
void			put_init(char *str, t_check_octa *c_octa);
char			*cut_str_long(char *seg, t_flags flags);

//utils octa hexa
char			*dectoocta(unsigned long n, t_flags flags);
void			ft_putstro(char *str, t_flags flags);
char			*dectohexa(unsigned long long n, t_flags flags);
void			ft_putstrx(char *str, t_flags flags);
void			ft_puthash(t_flags flags);

//%s
int				precision_width_str(t_check_str c_str);
int				is_precision_str(t_check_str c_str);
int				is_width_str(t_check_str c_str);
int				is_width_no_precision_other_str(t_check_str c_str, int chose);
int				check_p_w_str(char *str, t_flags flags);

//%d
int				check_p_w_digit(long long digit, t_flags flags);
char			*make_str(long long digit, t_flags flags, char *str);
void			is_space(long long digit, t_flags *flags, t_check_digit *c_dig);
void			digit_upper_0(long long digit, t_check_digit *c_dig, int chose);
void			digit_lower_0(long long digit, t_check_digit *c_dig, t_flags flags);
int				digit_plus_prec(long long digit, t_flags flags, t_check_digit c_dig);
int				digit_plus_width(long long digit, t_flags flags, t_check_digit c_dig);
int				digit_plus_width2(long long digit, t_flags flags, t_check_digit c_dig);
int				is_digit_plus(long long digit, t_flags flags, t_check_digit c_dig);
int				is_digit_minus(long long digit, t_flags flags, t_check_digit c_dig);
int				prec_digit_no_op(long long digit, t_flags flags, t_check_digit c_dig);
int				width_digit_no_op(long long digit, t_flags flags, t_check_digit c_dig);

//%c
int				check_p_w_caract(int c, t_flags flags);

//%o
int				is_octa_hash(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_width_no_op(unsigned long dec, t_flags flags, t_check_octa *c_octa);
void			octa_print_space_0(unsigned long dec, t_flags flags, t_check_octa *c_octa, int chose);
int				is_octa_width_lower_no_op(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_width_lower(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_width(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_width_up_prec(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_width_prec(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				is_octa_no_width_prec(unsigned long dec, t_flags flags, t_check_octa *c_octa);
int				check_p_w_octa(unsigned long dec, t_flags flags);

//%x
int				check_p_w_hexa(unsigned long long dec, t_flags flags);

//%p
int				check_p_w_ptr(void *ptr, t_flags flags);

int				ft_printf(const char *format,
			...) __attribute__((format(printf,1,2)));

#endif
