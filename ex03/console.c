/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:49:54 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 14:42:29 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct s_stack *stackInit(void){
	struct s_stack *new;

	if (!(new = malloc(sizeof(struct s_stack))))
		return (NULL);
	new->item = NULL;
	return (new);
}

int pop(struct s_stack *stack){
	struct s_item *del;
	int     ret = 0;
	del = stack->item;

	if (stack->item)
	{
		ret = stack->item->idx;
		stack->item = stack->item->next;
	}
	free (del);
	return (ret);
}
void push(struct s_stack *stack, int idx){
	struct s_item *new;

	if (!(new = malloc(sizeof(struct s_item))))
		return ;
	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

char *console(void){
	struct s_stack *stack = stackInit();
	char *msg;
	char *input = NULL;
	size_t size;
	size_t in_len;
	int  i = 0;

	if (!(msg=malloc(256)))
		return NULL;
	bzero(msg, 256);

	printf("?: ");
	while (getline(&input, &size, stdin) > 0)
	{
		if (strcmp(input, "UNDO\n"))
		{
			i = pop(stack);
			bzero(msg + i, 256 - i);
		}
		else if (strcmp(input, "SEND\n"))
		{
			break ;
		}
		else
		{
			in_len = (int)strlen(input) - 1;
			strncpy(msg + i, input, in_len);
			push(stack, i);
			i += in_len;
			if (in_len)
				msg[i++] = ' ';
			printf("?: ");
		}
	}
	free(input);
	return (msg);
}