/*




*/

#include <apc.h>

int takeNum(char * expr, dig **No1, dig **No2)
{
	int dig_ptr = strlen(expr) - 1;	
	int other_ptr = 7;
	char operator;
	int operator_flag = 0, num = 0, high_flag = 0;
	int till_buff = 0;
	char buff[8];
	int i;
	for(i = 0; i < 8; i++)
	{
		buff[i] = '0';
	}
	dig *res = NULL;
	
		
	while (dig_ptr >= 0)
	{
/*
		if (dig_ptr == 0)
		{
			if ( expr[dig_ptr] == '-')
			{
				minus_flag = 1;
				break;
			}
		}
*/

		/*if the character is not an operator*/
		if (expr[dig_ptr] != '+' && expr[dig_ptr] != '-' && expr[dig_ptr] != '*' && expr[dig_ptr] != '/' && expr[dig_ptr] != '%' && expr[dig_ptr] != '^')
		{
			if (till_buff == 8)
			{

				/*performing atoi on variable 1*/
				if (operator_flag == 0)
				{
					num = atoi(buff);
					dl_insert_first(No1, num);
				}

				/*performing atoi on variable 2*/
				if (operator_flag == 1)
				{
					num = atoi(buff);
					dl_insert_first(No2, num);
				}

				till_buff = 0;

				/*moving 8 characters in to a buffer*/
				for (other_ptr = 0; other_ptr < 8; other_ptr++)
					buff[other_ptr] = '0';

				other_ptr = 7;

			}

			buff[other_ptr] = expr[dig_ptr];
			--other_ptr;
			++till_buff;

		}

		/*if the character is an operator*/
		else
		{

			if (till_buff != 0)
			{
				num = atoi(buff);
				dl_insert_first(No1, num);
			}

			operator = expr[dig_ptr];
			operator_flag = 1;
			till_buff = 0;

			for (other_ptr = 0; other_ptr < 4; other_ptr++)
				buff[other_ptr] = '0';

			other_ptr = 7;
		}

		--dig_ptr;
	}
	
	num = atoi(buff);
	dl_insert_first(No2, num);

	if (operator == '+' || operator == '-')
	{

		/*if op is -, check for greater num and swap*/
		
		if (operator == '-')
		{
			high_flag = check_greater(No1, No2);
			//printf("\nhigh = %d\n", high_flag);
		}
		

		res = eval_sum(No1, No2, operator);

		if (operator == '+')
			printf("\nres = ");

		if (operator == '-')
		{

			/*if the 1st num is less than 2nd num, print - sign*/
			if (high_flag == 1)
				printf("\nres = -");

			else
				printf("\nres = ");

		}

		dl_print_list(res);
		printf("\n");
	}

	if (operator == '*')
	{
		res = eval_mul(No1, No2, operator);
		printf("\nResult : ");
		dl_print_list(res);
	}

	if (operator == '/')
	{
		int count = apc_evaluation_div(No1, No2, operator);
		printf("\nResult is %d\n", count);
	}
}
