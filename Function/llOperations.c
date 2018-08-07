/*




*/

#include <apc.h>

void dl_print_list(dig *head)

{
	dig *temp = head;

	while(temp)
	{
		printf("%d ", temp -> cur);
		temp = temp -> nextD;
	}
	printf("\n");
}


void dl_delete_list(dig **head)
{
	/* take a local reference of head */
	dig *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}
	/* iterate through the list and delete from the head till the tail */
	else
	{

		while(temp -> nextD)
		{

			dl_delete_first(&temp);
		}
		// update the linked list as empty list
		(*head) = NULL;


		return ;
	}
	return ;

}


void dl_insert_first(dig **head, int data)
{
	dig *new = malloc(sizeof(dig));

	dig *temp;
	temp = (*head);

	if (NULL == new)
	{
		return ;
	}

	//update newnode data and links
	new -> cur = data;
	new -> prevD = NULL;
	new -> nextD = NULL;

	//if list is empty
	if ( NULL == (*head))
	{
		(*head) = new;
		return;
	}

	//if non empty list
	temp -> prevD = new;
	new -> nextD = temp;
	(*head) = new;

	return ;
}

void dl_delete_first(dig **head)
{
	/* take a local reference of head */
	dig *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}

	/* check for if list has only one node */
	if ( ((*head) -> nextD) == NULL)
	{
		/* free the node, and update head with null */
		free(*head);
		(*head) = NULL;
		return ;
	}
	else
	{
        /* if list has multiple nodes then, update head and free the first node */
		(*head) = ((*head) -> nextD);
        /* update the head -> prev to null */
        (*head) -> prevD = NULL;
		free(temp);
		return ;
	}
}