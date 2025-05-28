#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SMALL_SIZE 1000
#define MEDIUM_SIZE 10000
#define LARGE_SIZE 20000

static const void	*cmp_int_asc(const void *a, const void *b)
{
	return (*(int *)a <= *(int *)b ? (const void *)1 : 0);
}

static const void	*cmp_int_desc(const void *a, const void *b)
{
	return (*(int *)a >= *(int *)b ? (const void *)1 : 0);
}

static void	print_int_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

static t_list	*create_test_list(int *arr, int size)
{
	t_list	*lst;
	t_list	*new;
	int		*content;
	int		i;

	lst = NULL;
	i = 0;
	while (i < size)
	{
		content = malloc(sizeof(int));
		if (!content)
			return (NULL);
		*content = arr[i];
		new = ft_lstnew(content);
		if (!new)
		{
			free(content);
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

static t_list	*create_random_list(size_t size)
{
	t_list	*lst;
	t_list	*tail;
	int		*content;
	size_t	i;

	lst = NULL;
	tail = NULL;
	i = 0;
	while (i < size)
	{
		content = malloc(sizeof(int));
		if (!content)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		*content = rand() % (size * 10);  // Random numbers between 0 and size*10
		if (!ft_lstnew_back_eff(&lst, &tail, content))
		{
			free(content);
			ft_lstclear(&lst, free);
			return (NULL);
		}
		i++;
	}
	return (lst);
}

static bool	verify_sort(t_list *lst, const void *(*cmp)(const void *, const void *))
{
	while (lst && lst->next)
	{
		if (!cmp(lst->content, lst->next->content))
			return (false);
		lst = lst->next;
	}
	return (true);
}

static void	run_performance_test(size_t size, const char *test_name)
{
	t_list	*lst;
	clock_t	start, end;
	double	cpu_time_used;

	printf("\n=== %s (size: %zu) ===\n", test_name, size);

	// Create and sort ascending
	lst = create_random_list(size);
	if (!lst)
	{
		printf("Failed to create list\n");
		return ;
	}
	start = clock();
	ft_lstsort_bubble(&lst, cmp_int_asc);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Ascending sort time: %f seconds\n", cpu_time_used);
	printf("%s\n", verify_sort(lst, cmp_int_asc) ? "OK" : "FAIL");
	ft_lstclear(&lst, free);

	// Create and sort descending
	lst = create_random_list(size);
	if (!lst)
	{
		printf("Failed to create list\n");
		return ;
	}
	start = clock();
	ft_lstsort_bubble(&lst, cmp_int_desc);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Descending sort time: %f seconds\n", cpu_time_used);
	printf("%s\n", verify_sort(lst, cmp_int_desc) ? "OK" : "FAIL");
	ft_lstclear(&lst, free);
}

int	main(void)
{
	t_list	*lst;
	int		test1[] = {4, 2, 1, 5, 3};
	int		test2[] = {1, 1, 1, 1, 1};
	int		test3[] = {-5, 12, 0, -3, 8};

	// Test 1: Basic sorting
	printf("Test 1 - Basic sorting (ascending):\n");
	lst = create_test_list(test1, 5);
	printf("Before: ");
	print_int_list(lst);
	ft_lstsort_bubble(&lst, (const void *(*)(const void *, const void *))cmp_int_asc);
	printf("After:  ");
	print_int_list(lst);
	ft_lstclear(&lst, free);
	printf("\n");

	// Test 2: All equal elements
	printf("Test 2 - All equal elements:\n");
	lst = create_test_list(test2, 5);
	printf("Before: ");
	print_int_list(lst);
	ft_lstsort_bubble(&lst, (const void *(*)(const void *, const void *))cmp_int_asc);
	printf("After:  ");
	print_int_list(lst);
	ft_lstclear(&lst, free);
	printf("\n");

	// Test 3: Negative numbers (descending)
	printf("Test 3 - Mixed numbers (descending):\n");
	lst = create_test_list(test3, 5);
	printf("Before: ");
	print_int_list(lst);
	ft_lstsort_bubble(&lst, cmp_int_desc);
	printf("After:  ");
	print_int_list(lst);
	ft_lstclear(&lst, free);
	printf("\n");

	// Test 4: Edge cases
	printf("Test 4 - Edge cases:\n");
	lst = NULL;
	ft_lstsort_bubble(&lst, (const void *(*)(const void *, const void *))cmp_int_asc);
	printf("Empty list: %s\n", lst == NULL ? "OK" : "FAIL");

	lst = ft_lstnew(malloc(sizeof(int)));
	*(int *)lst->content = 42;
	ft_lstsort_bubble(&lst, (const void *(*)(const void *, const void *))cmp_int_asc);
	printf("Single element: %s\n", *(int *)lst->content == 42 ? "OK" : "FAIL");
	ft_lstclear(&lst, free);


	srand(time(NULL));  // Initialize random seed

	// Run performance tests with different sizes
	run_performance_test(SMALL_SIZE, "Small List Test");
	run_performance_test(MEDIUM_SIZE, "Medium List Test");
	
	printf("\nWarning: Large list test might take several minutes...\n");
	printf("Do you want to proceed? (y/n): ");
	if (getchar() == 'y')
		run_performance_test(LARGE_SIZE, "Large List Test");

	return (0);
}
