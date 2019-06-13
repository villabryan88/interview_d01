/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:04:31 by bvilla            #+#    #+#             */
/*   Updated: 2019/06/12 18:38:11 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int isEmpty(struct s_queue *queue)
{
	return (!queue->first);
}

char *peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return (queue->first->message);
}

struct s_queue *queueInit(void)
{
	struct s_queue *new;

	if(!(new = malloc(sizeof(struct s_queue))))
        return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new;

	if (!(new = malloc(sizeof(struct s_node))))
        return (NULL);
	new->message = message;
	new->next = NULL;
	if(isEmpty(queue))
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
}

char *dequeue(struct s_queue *queue)
{
	void	*ret;
	struct s_node	*tmp;

	if (isEmpty(queue))
		return (NULL);
	ret = peek(queue);
	tmp = queue->first;
	queue->first = queue->first->next;
	if(isEmpty(queue))
		queue->last = NULL;
	free(tmp);
	return (ret);
}