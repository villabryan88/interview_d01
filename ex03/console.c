/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:49:54 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 13:56:11 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void){
    struct s_stack *new;

    if (!(new = malloc(sizeof(struct s_stack))))
        return (NULL);
    new->item = NULL;
    return (new);
}

void *pop(struct s_stack *stack){
    struct s_item *ret;

    ret = stack->item;
    if (stack->item)
        stack->item = stack->item->next;

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
    char input[255];

    scanf("%s\n", &input);
    printf("%s\n", input);
}