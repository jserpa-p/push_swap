/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:47:00 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/09/10 14:59:39 by jserpa-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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