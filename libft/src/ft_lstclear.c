/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:21:48 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/19 16:31:03 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

void	ft_lstclear(void *content, size_t size)
{
	size = 0;
	free(content);
	content = NULL;
}
