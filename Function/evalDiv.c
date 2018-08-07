/*




*/

#include <apc.h>

int apc_evaluation_div(dig **No1, dig **No2, char operator)
{

	/*local variable declatation*/
	unsigned long long int count = 0;
	int  flag = 0;
	int high_flag, idx = 0, stop = 0;
	dig *diff = NULL, *Result = NULL, *copy = NULL, *temp_No2 = *No2;
	dig *ptr = NULL;
	high_flag = check_greater(No1, No2);

	while (1)
	{
		/*if the divisor is greater than the dividend*/
		if (flag == 0)
		{

			if (high_flag == 1)
			{
				flag = 2;
				break;
			}

			flag = 1;
		}

		/*repetitively performing the subtraction*/
		Result = eval_sum(No1, &temp_No2, '-');

		/*repetitive subtraction is stopped when the remainder goes less than the divisor*/
		stop = check_greater(No1, &Result);

		if (stop == 0)
		{

			/*keep count on subtraction*/
			++count;
			printf("%lld\n", count);

			/*deleting the list not needed*/
			dl_delete_list(&temp_No2);
			temp_No2 = Result;
		}

		else
		{
			break;
		}
	}

	/*if the operator is %, print the result*/
	if (operator == '%')
	{
		printf("\nRemainder is ");

		dl_print_list(*No1);

		printf("\n");
	}

	/*if the operator is /, print the count*/
	if (operator == '/')
	{
		if (flag == 2)
		{
			return 0;
		}

		else
			return count + 1;
	}
}