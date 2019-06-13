/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:01:10 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 20:29:09 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_stack *stackInit(void){
	struct s_stack *new;

	if (!(new = malloc(sizeof(struct s_stack))))
		return (NULL);
	new->elem = NULL;
    new->sum = 0;
	return (new);
}

int pop(struct s_stack *stack){
    struct s_elem *del;
    int            energy = 0;

    del = stack->elem;
    if (stack->elem){
        energy = stack->elem->energy;
        stack->elem = stack->elem->next;
    }
    free(del);
    return (energy);
}
void push(struct s_stack *stack, int energy){
    struct s_elem *new;

    if (!(new = malloc(sizeof(struct s_elem))))
        return ;
    new->energy = energy;
    new->next = stack->elem;
    stack->elem = new;
}

struct s_tank *initTank(void){
	struct s_tank *new;

	if (!(new = malloc(sizeof(struct s_tank))))
		return (NULL);
	new->stacks = NULL;
    new->n = 0;
	return (new);
}

void tankPush(struct s_tank *tank, int energy){
	struct s_elem *new;
    struct s_stack *new_stack = NULL;

	if (!(new = malloc(sizeof(struct s_elem))))
		return ;
	new->energy = energy;
	new->next = stack->elem;
	stack->elem = new;
}

int tankPop(struct s_tank *tank){
	struct s_elem *del;
	int     ret = 0;
	del = stack->elem;

	if (stack->elem)
	{
		ret = stack->elem->idx;
		stack->elem = stack->elem->next;
	}
	free (del);
	return (ret);
}
