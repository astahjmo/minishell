/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:23:34 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 11:28:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024
# define BUFFER_SIZE 1024
# define MASK_CONVERSION "cspdiuxX"
# define MASK_HEX "0123456789abcdef"

typedef unsigned long long	t_ull;

// Io
int							ft_printf(const char *str, ...);
int							fparser(const char *s, va_list ap);
int							fmt_to_decimal(int nbr);
int							fmt_to_udecimal(unsigned int nbr);
int							fmt_to_char(char s);
int							fmt_to_string(char *s);
int							fmt_to_hex(unsigned int nb, int is_upper);
int							fmt_to_pointer(void *pointer);
char						*ft_ithex(unsigned int n);
char						*ft_ubase(unsigned long n, unsigned long base);
char						*get_next_line(int fd);
char						*ft_alloc(size_t mem, size_t size);
char						*ft_new_buffer(char *s1, char *s2);

// Memory
int							ft_memcmp(const void *s1, const void *s2, size_t n);
void						ft_bzero(void *s, size_t n);
void						*ft_calloc(size_t nb, size_t size);
void						*ft_memchr(const void *str, int c, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memset(void *s, int c, size_t n);

// utils
int							ft_atoi(const char *str);
int							ft_isalnum(int n);
int							ft_isalpha(int n);
int							ft_isdigit(int n);
int							ft_isprint(int n);
int							ft_isascii(int n);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int							ft_tolower(int c);
int							ft_toupper(int c);
t_ull						ft_atoull(char *str);

// STR
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						*ft_interpol(char *pattern, ...);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char *s1, char *set);
char						**ft_split(char const *s, char c);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
char						*ft_strchr(char *str, int find);
char						*ft_strdup(const char *src);
char						*ft_strnstr(const char *str, const char *find,
								size_t size);
char						*ft_strrchr(const char *str, int find);
size_t						ft_strlen(const char *str);
size_t						ft_strlcat(char *dest, const char *str,
								size_t size);
size_t						ft_strlcpy(char *dest, const char *str,
								size_t size);
int							ft_strcmp(char *str1, char *str2);

// FD
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);

// BONUS
#endif
