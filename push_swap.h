/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:55:14 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 13:25:09 by fmota            ###   ########.fr       */
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

/* --- GNL --- */
static void	gnl_read(char *buf, char **maker);
static char	*gnl_development(char **maker);
char	    *get_next_line(char **maker);

/* --- guidelines --- */
static void	sx(t_list **stack1, t_list **stack2);
static void	px(t_list **stack1, t_list **stack2);
static void	rx(t_list **stack1, t_list **stack2);
static void	rrx(t_list **stack1, t_list **stack2);
void    process_guidelines(char *cmd, t_list **stack1, t_list **stack2, int nb);

/* --- sort_out --- */


/* --- sort_out_utils --- */
/* --- sort_out_utils_2 --- */


#endif