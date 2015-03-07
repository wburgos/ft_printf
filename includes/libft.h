/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:51:39 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:29:44 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <wchar.h>
# include <stdint.h>

typedef	unsigned char	t_byte;

void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putchar(char c);
int					ft_putstr(char const *s);
void				ft_putunbr(uintmax_t n);
int					ft_nbdigits(intmax_t n);
char				*ft_strrev(char *str);
void				ft_swap(char *a, char *b);
void				ft_strtolower(char *str);
void				ft_putnchar(char c, int n);
int					ft_inarray(char c, char *arr);
int					ft_wclen(wchar_t wchar);
int					ft_wcslen(wchar_t *str);
wchar_t				*ft_strwdup(wchar_t *src);
wchar_t				*ft_wcscpy(wchar_t *dst, const wchar_t *src);
wchar_t				*ft_wcsnew(size_t size);
wchar_t				*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);
int					ft_putwstr(wchar_t *str);
int					ft_putwchar(wchar_t c);
int					ft_wcutf8(wchar_t wchar, char *conv_temp);
#endif
