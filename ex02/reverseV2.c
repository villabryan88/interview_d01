/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:17:32 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 13:33:25 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_stack *stackInit(void){
    struct s_stack *new;

    if (!(new = malloc(sizeof(struct s_stack))))
        return (NULL);
    new->item = NULL;
    return (new);
}

void *pop(struct s_stack *stack){
    struct s_stack *ret;

    ret = stack->item;
    if (stack->item)
        stack->item = stack->item->next;

    return (ret);
}
void push(struct s_stack *stack, char *word){
    struct s_item *new;

    if (!(new = malloc(sizeof(struct s_item))))
        return (NULL);
    new->word = word;
    new->next = stack->item;
    stack->item = new;
}

void printReverseV2(struct s_node *lst) {
    struct s_stack *stack = stackInit();
    char            first = 1;

    for(struct s_node *i = lst; i; i = i->next)
        push(stack, i->word);
    for(struct s_item *i = pop(stack); i; i = pop(stack))
    {
        if (!first)
            ft_printf(" ");
        else
            first = 0;
        ft_printf("%s");
    }
    ft_printf("\n");
}