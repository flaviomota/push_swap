/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:55:14 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 15:57:32 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 5

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* --- utils --- */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);

/* --- utils_2 --- */
int	    ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	    ft_abs(int num);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* --- utils_3 --- */
int	ft_error(int status);
long	ft_atol(const char *str);
int	ft_isint(char *str);
char	*ft_join(char **strs, char *sep);

/* --- utils_4 --- */
char	**ft_split(const char *s, char c);
t_list	*ft_lstnew(void *content);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* --- utils_5 --- */
t_list	*ft_lstlast(t_list *lst);
void	ft_putendl_fd(char *s, int fd);
int	ft_isspace(int c);
int	ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

/* --- utils_6 --- */
void	ft_putchar_fd(char c, int fd);
int	ft_atoi(const char *str);


/* --- GNL --- */
char	    *get_next_line(char **maker);

/* --- guidelines --- */
void    process_guidelines(char *cmd, t_list **stack1, t_list **stack2, int nb);

/* --- sort_out --- */
void	sort(t_list **stack);

/* --- sort_out_utils --- */
int	stack_min(t_list *stack);
int	stack_max(t_list *stack);
int	arranged(t_list *stack);
int	min(int a, int b);

/* --- sort_out_utils_2 --- */
int	min_max_index(t_list *stack, int nb);
void	find_min_rotate(t_list *stack1, t_list *stack2, int *nb1, int *nb2);
void	rotate_same(t_list **stack1, t_list **stack2, int nb1, int nb2);
void	rotate_diff(t_list **stack1, t_list **stack2, int nb1, int nb2);

/* --- certify --- */
int	converter(char **str, int **nb);
void	checker(char **argv);
void	wipe_up1(char *str, char **str2);
void	wipe_up2(int *nb, t_list *stack);

#endif