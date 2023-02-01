#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	char	**stack_a;
	//char	**stack_b;
	int	i = 0;
	
	stack_a = (char **)malloc(sizeof(char *) * argc);
	if (!stack_a)
		return (0);
	while (argv[i + 1])
	{
		stack_a[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	stack_a[i] = 0;
	stack_a[4] = 0;
	i = 0;
	while (stack_a[i])
		ft_printf("%s\n", stack_a[i++]);
	i = 0;
	while (stack_a[i])
		free(stack_a[i++]);
	free(stack_a[i + 1]);
	free(stack_a);
	return (0);
}