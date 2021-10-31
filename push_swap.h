/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:55:14 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:17:21 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define BUFFER_SIZE 5

/* --- libft_utils --- */
int			ft_error(int status);
int			ft_isint(char *str);
char		*ft_join(char **strs, char *sep);

/* --- gnl --- */
char	    *get_next_line(char **maker);

/* --- guidelines --- */
void    	process_guidelines(char *cmd, t_list **stack1, t_list **stack2, int nb);

/* --- sort_out --- */
void		sort(t_list **stack);

/* --- sort_out_utils --- */
int			stack_min(t_list *stack);
int			stack_max(t_list *stack);
int			arranged(t_list *stack);
int			min(int a, int b);

/* --- sort_out_utils_2 --- */
int			min_max_index(t_list *stack, int nb);
void		find_min_rotate(t_list *stack1, t_list *stack2, int *nb1, int *nb2);
void		rotate_same(t_list **stack1, t_list **stack2, int nb1, int nb2);
void		rotate_diff(t_list **stack1, t_list **stack2, int nb1, int nb2);

/* --- certify --- */
int			converter(char **str, int **nb);
void		check(char **argv);
void		wipe_up1(char *str, char **str2);
void		wipe_up2(int *nb, t_list *stack);

#endif