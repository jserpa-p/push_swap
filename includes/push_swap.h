/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jserpa-p <jserpa-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:53:46 by jserpa-p          #+#    #+#             */
/*   Updated: 2021/09/14 15:15:00 by jserpa-p         ###   ########.fr       */
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



#endif