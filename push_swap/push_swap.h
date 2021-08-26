/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:41:37 by kyounkim          #+#    #+#             */
/*   Updated: 2021/08/26 13:00:02 by kyounkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

typedef struct s_op
{
	char		*s;
	struct s_op	*next;
}				t_op;

void		operation_rr_checker(t_stack **a, t_stack **b, char *s);
void		operation_checker(t_stack **a, t_stack **b, char *s);

int			get_next_line(char **line);

int			ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
int			ft_strlcpy(char *dst, char *src, int dstsize);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_atoll(char *str);
int			ft_strcmp(char *s1, char *s2);

int			write_error(void);
int			check_isdigit(char *str);
int			check_int_range(long long n);
int			check_duplication(t_stack **a);
int			check_argv_and_add_stack(t_stack **a, int argc, char **argv);

void		free_stack(t_stack **a);
void		free_operation(t_op **op);

t_op		*create_op_list_node(char *s);
void		add_op_list_front(t_op **head, t_op *new_node);
void		add_op_list_back(t_op **head, t_op *new_node);
void		add_op_list_middle(t_op **head, t_op *new_node, int n);
void		del_op_list(t_op **head, int n);

t_stack		*create_stack_node(int n);
int			get_stack_size(t_stack **head);
void		add_stack_top(t_stack **head, t_stack *new_node);
void		add_stack_bottom(t_stack **head, t_stack *new_node);

void		swap(t_stack **head);
void		push(t_stack **dest, t_stack **src);
void		rotate(t_stack **head);
void		reverse_rotate(t_stack **head);

int			sorted_check_a(t_stack **a, int stack_size);
int			sorted_check_b(t_stack **b, int stack_size);

void		get_op_list(t_op **op, char *s, t_stack **a, t_stack **b);

int			get_hivalue_pivot(t_stack **head, int len);
int			get_lowvalue_pivot(t_stack **head, int len);

int			*get_stack_array(t_stack **head, int stack_size);
int			get_mid_value(t_stack **head, int stack_size);
int			get_min_value(t_stack **head, int stack_size);
int			get_max_value(t_stack **head, int stack_size);
int			get_value_index(t_stack **head, int value);

void		sort(t_stack **a, t_stack **b, t_op **op,
				int stack_size, int *push, int *count_ra, int *count_rb);
int			return_case_a(t_stack **a, t_stack **b, t_op **op, int stack_size);
void		sort_main_a(t_stack **a, t_stack **b, t_op **op, int stack_size);

void		sort(t_stack **a, t_stack **b, t_op **op,
				int stack_size, int *push, int *count_ra, int *count_rb);
int			return_case_b(t_stack **a, t_stack **b, t_op **op, int stack_size);
void		sort_main_b(t_stack **a, t_stack **b, t_op **op, int stack_size);

int			get_merge_case(t_op *op);
int			get_merge_operation(t_op **op);
int			get_delete_case(t_op *op);
int			get_delete_operation(t_op **op);
void		minimize_op_list(t_op **op);

void		print_op_list(t_op **op);

void		q_sort_swap(int *arr, int i, int j);
int			partition(int *arr, int start, int end);
void		quick_sort(int *arr, int start, int end);

void		size_discord_case_two_a(t_stack **a, t_op **op);
void		common_op_case_three_a(t_stack **a, t_op **op);
void		size_discord_case_three_a(t_stack **a, t_op **op, int stack_size);
void		size_discord_a(t_stack **a, t_op **op, int stack_size);

void		size_discord_case_two_b(t_stack **b, t_op **op);
void		common_op_case_three_b(t_stack **b, t_op **op);
void		size_discord_case_three_b(t_stack **b, t_op **op, int stack_size);
void		size_discord_b(t_stack **a, t_stack **b, t_op **op, int stack_size);

void		sort_just_six(t_stack **a, t_stack **b, t_op **op, int stack_size);

void		case_two_a(t_stack **a, t_op **op);
void		case_three_a(t_stack **a, t_op **op, int stack_size);
void		sort_just_three_a(t_stack **a, t_op **op, int stack_size);

void		case_two_b(t_stack **b, t_op **op);
void		case_three_b(t_stack **b, t_op **op, int stack_size);
void		sort_just_three_b(t_stack **b, t_op **op, int stack_size);

#endif
