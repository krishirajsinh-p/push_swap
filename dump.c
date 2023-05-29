// void	leaks(void)	//remove
// {
// 	ft_putstr("====================================\n");
// 	system("leaks push_swap");
// }
	// atexit(leaks);	//remove

// static void	print_stack(t_stack *stack)	//remove
// {
// 	t_node	*node;

// 	ft_putstr("====================================\n");
// 	ft_printf("size: %d\n", stack->size);
// 	if (stack->size == 0)
// 	{
// 		ft_putstr("-> [NULL]\n");
// 		return ;
// 	}
// 	node = stack->top;
// 	while (node)
// 	{
// 		ft_printf("-> [%d]", node->data);
// 		node = node->next;
// 	}
// 	ft_putstr("-> [NULL]\n");
// }

	// print_stack(&stack.a);	//remove
	// print_stack(&stack.b);
	// ft_printf("sorted: %d\n", is_stack_sorted(&stack.a));