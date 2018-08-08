/*




*/

#include <apc.h>

int check_greater(dig **No1, dig **No2)
{

	/*local variable declaration*/
	dig *ptr1 = *No1, *ptr2 = *No2;
	int count1 = 0, count2 = 0, high_flag = 0, idx, flag = 0;

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

	if(count1 > count2)
	{
		return 100;
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



#if 0
{

	/*local variable declaration*/
	dig *ptr1 = *No1, *ptr2 = *No2;
	int count1 = 0, count2 = 0, high_flag = 0, dig_ptr, flag = 0;
	//printf("no2 %d no1 %d\n", ptr2->cur, ptr1->cur);
	/*count number of nodes in list1*/
	while (ptr1 != NULL)
	{
		++count1;
		ptr1 = ptr1->nextDD;
	}

	/*count number of nodes in list2*/
	while (ptr2 != NULL)
	{
		++count2;
		ptr2 = ptr2->nextDD;
	}
	dig *optr1 = *No1, *optr2 = *No2;
	//printf("%d          %d\n", optr1->cur, optr2->cur);
	//printf("%d %d\n", count1, count2);

	int check1 = optr1->cur;
	int check2 = optr2->cur;
	//printf("%d    %d\n", check1, check2);
	if(count1 ==  count2)
	{
	//	printf("%d\n", optr1->cur);
		if(check1 < check2)
		{
	//		printf("%d\n", optr1->cur);
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(count1 > count2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
#if 0
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
					ptr2 = ptr2->nextDD;
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
			while(tmp2->cur >= tmp1->cur && tmp1->nextDD != NULL)
			{
				tmp1 = tmp1->nextDD;
				tmp2 = tmp2->nextDD;
			}

			/*swapping the numbers*/
			if (tmp1->nextDD != NULL && tmp2->cur < tmp1->cur)
			{
				dig *tmp = *No1;
				*No1 = *No2;
				*No2 = tmp;
				high_flag = 1;
			}

			/*swapping the numbers*/
			else if (tmp1->nextDD == NULL && tmp2->cur < tmp1->cur)
			{

				dig *tmp = *No1;
				*No1 = *No2;
				*No2 = tmp;
				high_flag = 1;
			}
		}

	}
	return high_flag;
#endif
}
#endif