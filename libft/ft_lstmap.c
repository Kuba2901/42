/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakubnenczak <jakubnenczak@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:56:29 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/01/12 20:30:52 by jakubnencza      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

#include <stdio.h> // for printf function

// Example function to apply to each element in the linked list
void *example_function(void *content)
{
    // This is just an example, you should replace it with your own logic
    int *num = (int *)content;
    int *result = (int *)malloc(sizeof(int));
    *result = (*num) * 2;
    return result;
}

// Example function to delete an element (free memory in this case)
void example_delete_function(void *content)
{
    // This is just an example, you should replace it with your own logic
    free(content);
}

int main()
{
    // Create a linked list for testing
    t_list *original_list = ft_lstnew((void *)1);
    ft_lstadd_back(&original_list, ft_lstnew((void *)2));
    ft_lstadd_back(&original_list, ft_lstnew((void *)3));

    // Apply the ft_lstmap function with example_function
    t_list *new_list = ft_lstmap(original_list, &example_function, &example_delete_function);

    // Print the original and new lists
    printf("Original list: ");
    t_list *current = original_list;
    while (current)
    {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");

    printf("New list (after applying example_function): ");
    current = new_list;
    while (current)
    {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");

    // Clean up memory
    ft_lstclear(&original_list, &example_delete_function);
    ft_lstclear(&new_list, &example_delete_function);

    return 0;
}
