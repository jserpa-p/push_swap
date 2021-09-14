/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:47:00 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/09/14 15:15:39 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_in_a(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num && (*stack)->next->num <
		(*stack)->next->next->num)
		return ;
	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num <
		(*stack)->next->next->num &&
		(*stack)->num < (*stack)->next->next->num)
		ft_printf("sa\n");
	else if ((*stack)->num < (*stack)->next->num && (*stack)->next->num >
		(*stack)->next->next->num &&
		(*stack)->num < (*stack)->next->next->num)
		ft_printf("rra\nsa\n");
	else if ((*stack)->num > (*stack)->next->num && (*stack)->next->num >
		(*stack)->next->next->num)
		ft_printf("ra\nsa\n");
	else if ((*stack)->num > (*stack)->next->num && (*stack)->num >
		(*stack)->next->next->num &&
		(*stack)->next->num < (*stack)->next->next->num)
		ft_printf("ra\n");
	else if ((*stack)->num < (*stack)->next->num && (*stack)->num >
		(*stack)->next->next->num &&
		(*stack)->next->num > (*stack)->next->next->num)
		ft_printf("rra\n");
}

void		short_sort(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	if (len == 2 && (*stack)->num > (*stack)->next->num)
		ft_printf("sa\n");
	if (len == 3)
		three_in_a(stack);
	return ;
}

void		sort_stacks(t_stack **stack1, t_stack **stack2, t_com **result,
	int len)
{
	int		rot;

	if (len == 2 || len == 3)
		return ;
	if ((*stack1)->diff == 1)
		rot = div_stack_a(stack1, stack2, result, len);
	else
		rot = div_stack_b(stack1, stack2, result, len);
	if ((*result)->rotator == 1)
		rotate_back(stack1, result, rot);
	if ((*stack1)->diff == 1 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	else if ((*stack1)->diff == 2 && (len / 2 == 3 || len / 2 == 2))
		swap_elements(stack1, stack2, result, len);
	sort_stacks(stack1, stack2, result, (*stack1)->diff != 1 ?
		len / 2 : len - len / 2);
	sort_stacks(stack2, stack1, result, (*stack1)->diff == 1 ?
		len / 2 : len - len / 2);
	if ((*stack1)->diff == 1)
		push_back(stack1, stack2, result, len / 2);
	else
		push_back(stack1, stack2, result, len - len / 2);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_com	*result;
	int		len;

	if (!(a = copy_args_in_stack(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	len = s_len(a);
	b = NULL;
	result = new_result();
	if (len < 4)
	{
		short_sort(&a, len);
		stack_del(&a);
		return (0);
	}
	else
		sort_stacks(&a, &b, &result, len);
	print_final_result(result->final);
	stack_del(&a);
	free(result);
	return (0);
}