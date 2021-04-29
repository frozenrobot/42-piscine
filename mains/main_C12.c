#include<stdio.h>
int main(void)
{
	char data[] = "hello";
	char data2[] = "cello";
	t_list *hi = ft_create_elem(data);
	ft_list_push_front(&hi, data2);
	while ((hi))
	{
		printf("%s\n", hi->data);
		hi = hi->next;
	}
}









#include <stdlib.h>
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	if (*begin_list)
	{
		t_list *temp;

		temp = ft_create_elem(data);
		temp->next = (*begin_list);
		(*begin_list) = temp;
	}
	else
		*begin_list = ft_create_elem(data);
}

int main(void)
{
	char data[] = "hello";
	char data2[] = "cello";
	t_list *hi = ft_create_elem(data);
	ft_list_push_front(&hi, data2);
    printf("%i", ft_list_size(hi));
}









#include <stdlib.h>
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	if (*begin_list)
	{
		t_list *temp;

		temp = ft_create_elem(data);
		temp->next = (*begin_list);
		(*begin_list) = temp;
	}
	else
		*begin_list = ft_create_elem(data);
}

int main(void)
{
	char data[] = "aaa";
	char data2[] = "bbb";
	char data3[] = "ccc";
	t_list *hi = ft_create_elem(data);
	ft_list_push_front(&hi, data2);
	ft_list_push_front(&hi, data3);
    printf("%s\n", (ft_list_last(hi))->data);
}










#include<stdio.h>
int main(void)
{
	char data[] = "aaa";
	char data2[] = "bbb";
	t_list *hi = ft_create_elem(data);
	ft_list_push_back(&hi, data2);
	while ((hi))
	{
		printf("%s\n", hi->data);
		hi = hi->next;
	}
}








#include<stdio.h>

int main(int argc, char *argv[])
{
	t_list *hi = ft_list_push_strs(argc, argv);
	while ((hi))
	{
		printf("%s\n", hi->data);
		hi = hi->next;
	}
}










#include <stdlib.h>

t_list *ft_create_elem(char *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void ft_list_push_front(t_list **begin_list, char *data)
{
	if (*begin_list)
	{
		t_list *temp;

		temp = ft_create_elem(data);
		temp->next = (*begin_list);
		(*begin_list) = temp;
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list *ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*newlist;

	i = 1;
    newlist = ft_create_elem(strs[0]);
    while (i < size)
    {
        ft_list_push_front(&newlist, strs[i]);
        i++;
    }
    return (newlist);
}


#include<stdio.h>

int main(int argc, char *argv[])
{
	t_list *hi = ft_list_push_strs(argc, argv);
	printf("%s\n", (ft_list_at(hi, 3))->data);
}









#include <stdlib.h>
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->data = data;
	element->next = NULL;
	return (element);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	if (*begin_list)
	{
		t_list *temp;

		temp = ft_create_elem(data);
		temp->next = (*begin_list);
		(*begin_list) = temp;
	}
	else
		*begin_list = ft_create_elem(data);
}

int main(void)
{
	char data[] = "aaa";
	char data2[] = "bbb";
	char data3[] = "ccc";
	t_list *hi = ft_create_elem(data);
	ft_list_push_front(&hi, data2);
	ft_list_push_front(&hi, data3);
    ft_list_reverse(&hi);
	while (hi)
	{
		printf("%s\n", hi->data);
		hi = hi->next;
	}
}