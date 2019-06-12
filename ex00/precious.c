/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:23:57 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 00:48:16 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"
#include <stdio.h>

void rotate(struct s_node **rotator, int turns)
{
    if (turns > 0)
    {
        for(int i = 0; i < turns; i++);
            *rotator = (*rotator)->next;
    }
    else if (turns < 0)
    {
          for(int i = 0; i > turns; i--);
            *rotator = (*rotator)->prev;
    }
}

char *precious(int *text, int size) {
    int     len = strlen(CS);
    struct s_node nodes[len];
    struct s_node *rotator = nodes;
    char    *answer;

    if(!(answer = malloc(sizeof(char) * (size + 1))))
        return NULL;

    nodes[0].c = CS[0];
    nodes[0].prev = nodes + len - 1;
    nodes[0].next = nodes + 1;
    for(int i = 1; i < len; i++)
    {       
        nodes[i].c = CS[i];
        nodes[i].prev = CS[i - 1];
        nodes[i].next = CS[(i + 1) % len];
    }

    for(int i = 0; i < size; i++)
    {
        rotate(&rotator, text[i]);
        answer[i] = rotator->c;
    }
    return answer;
}