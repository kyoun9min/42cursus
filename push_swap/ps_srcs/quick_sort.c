/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:43:28 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/26 10:45:15 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	q_sort_swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int	partition(int *arr, int start, int end)
{
	int	value;
	int	i;
	int	j;

	value = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < value)
			q_sort_swap(arr, ++i, j);
		j++;
	}
	q_sort_swap(arr, i + 1, end);
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	middle;

	if (start >= end)
		return ;
	middle = partition(arr, start, end);
	quick_sort(arr, start, middle - 1);
	quick_sort(arr, middle + 1, end);
}
