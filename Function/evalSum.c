/*




*/

#include <apc.h>

dig *eval_sum(dig **No1, dig **No2, char operator)
{

	/*local variable declaration*/
	dig *Result = NULL;
	dig *ptr1 = *No1, *ptr2 = *No2, *ptr = NULL;
	int carry_flag = 0, result, dig_ptr = 0;

	/*point the pointer to the last node, that is where the operation should be started from*/
	while(ptr1->nextD != NULL)
	{

		/*if the operator is "-", take 2's complement of the number*/
		if (operator == '-')
		{
			ptr1->cur = ~(ptr1->cur) + 1;
		}

		ptr1 = ptr1->nextD;

	}

	/*2's complement of the last node*/
	if (operator == '-')
	{
		ptr1->cur = ~(ptr1->cur) + 1;
	}

	if ( ptr2 == *No2 && ptr2->cur < 0)
	{
		ptr2->cur = ptr2->cur * -1;
	}

	/*move the pointer to the last node*/
	while(ptr2->nextD != NULL)
	{
		ptr2 = ptr2->nextD;
	}

	if (operator == '+' || operator == '-')
	{
		while (ptr1 != NULL || ptr2 != NULL)
		{
			if (ptr1 != NULL && ptr2 != NULL)
			{

				/*if the number to be subtracted from is smaller take care of borrow*/
				if (operator == '-' && ptr2 != *No2 && ptr2->cur < (ptr1->cur * -1))
				{
					ptr = ptr2;

					/*take borrow from node which is not zero*/
					while (ptr->prevD->cur == 0 && ptr != NULL)
					{
						ptr = ptr->prevD;

						if (ptr == *No2)
						{
							break;
						}
					}

					if (ptr != NULL)
					{

						if (ptr != *No2)
							ptr = ptr->prevD;

						ptr->cur = ptr->cur - 1;

						ptr = ptr->nextD;

						while (ptr != ptr2)
						{
							ptr->cur = ptr->cur + 100000000 - 1;
							ptr = ptr->nextD;
						}
						ptr->cur = ptr->cur + 100000000;
					}
				}
				result = ptr1->cur + ptr2->cur + carry_flag;
			}

			/*if there are no nodes available in list1*/
			else if (ptr1 == NULL && ptr2 != NULL)
			{
				result = ptr2->cur + carry_flag;
			}

			/*if there are no nodes available in list2*/
			else if (ptr2 == NULL && ptr1 != NULL)
				result = ptr1->cur + carry_flag;

			carry_flag = 0;
			/*checking the node for over flow*/
			if (result > 99999999)
			{
				carry_flag = 1;
				result = result - 100000000;
			}

			dl_insert_first(&Result, result);

			if (ptr1 != NULL)
				ptr1 = ptr1->prevD;

			if (ptr2 != NULL)
				ptr2 = ptr2->prevD;

		}

	}

	/*if there is a carry from the last node*/
	if (carry_flag == 1 && operator == '+')
	{
		dl_insert_first(&Result, 1);
	}

	if (operator == '-')
	{
		ptr = Result->nextD;
		while(ptr!= NULL)
		{
			if (ptr->cur < 0)
				ptr->cur = ptr->cur * -1;

			ptr = ptr->nextD;
		}

		ptr1 = *No1;

		/*reversing the 2's complement done*/
		while(ptr1 != NULL)
		{
			if (operator == '-')
			{
				ptr1->cur = ~(ptr1->cur) + 1;
			}

			ptr1 = ptr1->nextD;

		}

	}
	/*returning the result*/
	return Result;

}