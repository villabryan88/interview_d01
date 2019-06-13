/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:01:10 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/13 12:00:34 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

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
		stack->sum -= energy;
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
	stack->sum += energy;
}

void visualize_tank(struct s_tank *tank){
	for(int j = 0; j < tank->n; j++)
	{
		if (j == 0)
			printf("normal");
		else
			printf(" nitro%d", j);
	}
	printf("\n");
	for(int j = 0; j < tank->n; j++)
	{
		if (j == 0)
			printf("______");
		else
			printf(" ______");	
	}
	printf("\n");
	for(int j = 0; j < tank->n; j++)
	{
		if (j == 0)
			printf("|%-4d|", tank->stacks[j]->sum);
		else
			printf(" |%-4d|", tank->stacks[j]->sum);	
	}
	printf("\n");
	for(int j = 0; j < tank->n; j++)
	{
		if (j == 0)
			printf("|    |");
		else
			printf(" |    |");	
	}
	printf("\n");
}

struct s_tank *initTank(void){
	struct s_tank *new;
	struct s_stack **stacks;

	if (!(new = malloc(sizeof(struct s_tank))))
		return (NULL);
	if (!(stacks = malloc (sizeof(struct s_stack*))))
	{
		free(new);
		return (NULL);
	}
	if (!(*stacks = stackInit()))
	{
		free(stacks);
		free(new);
		return (NULL);
	}
	new->stacks = stacks;
    new->n = 1;
	return (new);
}

void tankPush(struct s_tank *tank, int energy){
	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
	{
		if (!(tank->stacks = realloc(tank->stacks, sizeof(struct s_stack*) * (tank->n + 1))))
			return ;
		if(!(tank->stacks[tank->n] = stackInit()))
			return ;
		tank->n++;
	}
	push(tank->stacks[tank->n - 1], energy);
	visualize_tank(tank);
}

int tankPop(struct s_tank *tank){
	int energy;


	energy = pop(tank->stacks[tank->n - 1]);
	if(tank->stacks[tank->n - 1]->sum == 0 && tank->n > 1)
	{
		while(tank->stacks[tank->n - 1]->elem)
			pop(tank->stacks[tank->n - 1]);
		free(tank->stacks[tank->n - 1]);
		tank->stacks[tank->n - 1] = NULL;
		tank->n--;
	}
	visualize_tank(tank);
	return (energy);
}
