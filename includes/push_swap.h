/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:53:46 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/09/16 16:38:38 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct	s_stack
{
	int		num;
	int		diff;
	struct	s_stack *next;
}				t_stack;

typedef struct	s_com
{
	int		rotator;
	char	*final;
}				t_com;

static void	free_memory(char **tmp, char **origin, char **result);
void		print_final_result(char *origin);
int			do_operations(char *line, t_stack **first, t_stack **second);
int			return_errors(char **line, t_stack **stack1, t_stack **stack2);
int			stack_is_sorted(t_stack *first);
void		print_checker_res(t_stack **first, t_stack **second);
void		swap_three_a(t_stack **stack, t_com **res);
void		swap_three_b(t_stack **stack, t_com **res);
void		swap_three(t_stack **stack, t_com **result);
void		swap_two(t_stack **stack, t_com **result);
static int	len_a_creator(t_stack **stack1, t_com **result, int len);
static int	len_b_creator(t_stack **stack1, t_com **result, int len);
static void	swap_for_len1_two(t_stack **stack1, t_stack **stack2,
								t_com **result, int len);
static void	swap_for_len1_three(t_stack **stack1, t_stack **stack2,
								t_com **result, int len);
void		swap_elements(t_stack **stack1, t_stack **stack2,
							t_com **result, int len);
void		stack_del(t_stack **stack);
t_stack		*create_new_node(void);
t_stack		*copy_args_in_stack(int argc, char **argv);
void		ft_swap(int *a, int *b);
int			partition(int *stack1, int start, int end);
void		quick_sort(int *stack1, int start, int end);
void		rotate_back(t_stack **stack, t_com **result, int back);
void		push_back(t_stack **stack1, t_stack **stack2, t_com **result, int half);
int			add_pa_pb(char **origin, char **res, int i);
int			add_ra_rra(char **origin, char **res, int i);
int			add_rb_rrb(char **origin, char **res, int i);
int			add_others(char **tmp, char **res, int i);
char		*add_to_string(char *to, char *add);
int			*create_array_from_list(t_stack *stack, int len);
t_com		*new_result(void);
int			find_mid_value(t_stack *stack, int len);
void		doubles_checker(t_stack **stack);
int			s_len(t_stack *stack);
int			check_int_overflow(char *str);
int			check_argv(char *str);
static int	stack_rotator(t_stack **stack, t_com **result, int rot);
static int	stack_pusher(t_stack **stack1, t_stack **stack2,
						t_com **result, int half);
int			div_stack_a(t_stack **stack1, t_stack **stack2,
						t_com **result, int len);
int			div_stack_b(t_stack **stack1, t_stack **stack2,
						t_com **result, int len);
int			sab(t_stack **head);
int			pab(t_stack **head_to, t_stack **head_from);
int			rab(t_stack **head);
int			rrab(t_stack **head);
int			ss(t_stack **stack1, t_stack **stack2);
int			rr(t_stack **stack1, t_stack **stack2);
int			rrr(t_stack **stack1, t_stack **stack2);
void		comb_1(t_stack **stack, t_com **result);
void		comb_2(t_stack **stack, t_com **result);
void		comb_3(t_stack **stack, t_com **result);
void		comb_4(t_stack **stack, t_com **result);
void		comb_5(t_stack **stack, t_com **result);
void		comb_6(t_stack **stack, t_com **result);
void		comb_7(t_stack **stack, t_com **result);
void		comb_8(t_stack **stack, t_com **result);
void		comb_9(t_stack **stack, t_com **result);
static void	three_in_a(t_stack **stack);
void		short_sort(t_stack **stack, int len);
void		sort_stacks(t_stack **stack1, t_stack **stack2, t_com **result,
						int len);


#endif