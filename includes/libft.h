/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:40:59 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/17 15:28:55 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

/*	---------- LIST STRUCT ---------- */

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*	---------- FT_PRINTF STRUCT ---------- */

typedef struct	s_struct
{
	int			pos;
	int			len;
	int			fd;

	int			minus;
	int			zero;

	int			width;
	int			precision;
	int			precision_val;

	int			total_pad;
}				t_struct;

/*	---------- LIBFT ---------- */

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *p, const char *q, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(const void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));

/*	---------- GET NEXT LINE ---------- */

# define	BUFFER_SIZE 1

int				get_next_line(int fd, char **line);

/*	---------- FT_PRINTF ---------- */

int				ft_printf(const char *string, ...);

void			process_string(const char *str, t_struct *f, va_list args);
void			parse_modifiers(const char *str, t_struct *f, va_list args);

void			print_char(char type, t_struct *f, va_list args);
void			print_string(char type, t_struct *f, va_list args);
void			print_pointer(char type, t_struct *f, va_list args);
void			print_integer(char type, t_struct *f, va_list args);
void			print_unsigned_integer(char type, t_struct *f, va_list args);
void			print_hexadecimal(char type, t_struct *f, va_list args);

char			*ft_utoa(uintmax_t nbr);
char			*ft_xtoa(uintmax_t nbr);
int				ft_nbrlen(uintmax_t nbr, int base);

#endif
