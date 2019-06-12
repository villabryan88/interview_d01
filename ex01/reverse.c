/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 00:53:12 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 01:05:00 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void printReverse(struct s_node *lst){
    static char    first_holder = 1;
    char            first = 0;
    if (first_holder)
    {
        first_holder = 0;
        first = 1;
    }
    if (lst->next)
    {
        printReverse(lst->next);
        printf(" ");
    }
    printf("%s", lst->word);
    if (first)
    {
        printf("\n");
        first_holder = 1;
    }
}