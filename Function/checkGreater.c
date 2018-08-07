/*




*/

#include <apc.h>

int check_greater(dig **No1, dig **No2)
{

	/*local variable declaration*/
	dig *ptr1 = *No1, *ptr2 = *No2;
	int count1 = 0, count2 = 0, high_flag = 0, dig_ptr, flag = 0;

	/*count number of nodes in list1*/
	while (ptr1 != NULL)
	{
		++count1;
		ptr1 = ptr1->nextD;
	}

	/*count number of nodes in list2*/
	while (ptr2 != NULL)
	{
		++count2;
		ptr2 = ptr2->nextD;
	}

	ptr1 = *No1;
	ptr2 = *No2;

	/*if the count2 is greater than count1*/
	if (count2 > count1)
	{

		/*if the number in the first node is 0*/
		if (ptr2->cur == 0)
		{
			while (ptr2 != NULL)
			{

				if (ptr2->cur == 0)
				{
					--count2;
					ptr2 = ptr2->nextD;
				}

				else
				{
					if (ptr2->cur < ptr1->cur && count2 == count1)
						flag = 1;
					break;

				}
				if (count2 == 0)
					flag = 1;

			}
		}

		/*swapping the numbers*/
		if (flag == 1)
		{
			dig *tmp = *No1;
			*No1 = *No2;
			*No2 = tmp;
			high_flag = 1;
		}

	}

	/*if the number of nodes are equal in both the nodes*/
	else if (count1 == count2)
	{
		dig *tmp1 = *No1, *tmp2 = *No2;

		if (tmp2->cur <= tmp1->cur)
		{
			while(tmp2->cur >= tmp1->cur && tmp1->nextD != NULL)
			{
				tmp1 = tmp1->nextD;
				tmp2 = tmp2->nextD;
			}

			/*swapping the numbers*/
			if (tmp1->nextD != NULL && tmp2->cur < tmp1->cur)
			{
				dig *tmp = *No1;
				*No1 = *No2;
				*No2 = tmp;
				high_flag = 1;
			}

			/*swapping the numbers*/
			else if (tmp1->nextD == NULL && tmp2->cur < tmp1->cur)
			{

				dig *tmp = *No1;
				*No1 = *No2;
				*No2 = tmp;
				high_flag = 1;
			}
		}

	}
	return high_flag;
}