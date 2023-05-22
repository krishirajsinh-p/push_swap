/*
functions
-push_node
-pop_node
-free (pop while stack is empty)
-operations {push swap rev rev_rot do_op}
-sort arr

init data
-operation functions already has static pointers to stack
-free methods also has static pointers to stack for popping

parsing
-no parameters then exit without any output
-no duplicates
-check if all are number
-check if all are int within int range

stack
-a elements from argument, first argument at top
-b empty

output
-operations list ending with '\n'
-cases of error output "Error\n" on stderr
*/

//===============================================================

// static void	init_data(t_data *stack)
// {
// 	stack->a.size = 0;
// 	stack->a.top = NULL;
// 	stack->b.size = 0;
// 	stack->b.top = NULL;
// 	// ft_error(stack);	//maybe make function for free for static, sperate error with free
// }

//===============================================================

// //push_swap.c
// void			init_data(t_data *stack);

// //operations.c
// void			swap(t_stack **ptr);
// void			push(t_stack **to, t_stack **from);
// void			rotate(t_stack **ptr);
// void			reverse_rotate(t_stack **ptr);

// //praser_utils.c
// bool			ft_stoi(t_string str, int *num);
// bool			check_dup(int *arr, int size);

// //stack.c
// t_node			*create_node(int data, int index, t_node *next);
// void			push_node(t_stack *stack, t_node	*node);
// t_node			*pop_node(t_stack *stack);

// //error.c
// void			ft_error(t_data *recv_data);
// void			throw_error(void);