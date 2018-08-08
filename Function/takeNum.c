/*




*/

#include <apc.h>

int takeNum(char * expr, dig **No1, dig **No2)
{

	/*local variable declaration*/
	int idx = strlen (expr) - 1;
	char operator, buff[4] = {'0' , '0', '0', '0'};
	int slice_flag = 0, op_flag = 0, sum = 0;
	int jdx = 3, minus_flag = 0, high_flag;
	dig *Result = NULL;

	while (idx >= 0)
	{

		if (idx == 0)
		{
			if ( expr[idx] == '-')
			{
				minus_flag = 1;
				break;
			}
		}
		/*if the character is not an operator*/
		if (expr[idx] != '+' &&expr[idx] != '-' && expr[idx] != '*' && expr[idx] != '/' && expr[idx] != '%' && expr[idx] != '^')
		{
			if (slice_flag == 4)
			{

				/*performing atoi on variable 1*/
				if (op_flag == 0)
				{
					sum = atoi(buff);
					dl_insert_first(No1, sum);
				}

				/*performing atoi on variable 2*/
				if (op_flag == 1)
				{
					sum = atoi(buff);
					dl_insert_first(No2, sum);
				}

				slice_flag = 0;

				/*moving 4 characters in to a buffer*/
				for (jdx = 0; jdx < 4; jdx++)
					buff[jdx] = '0';

				jdx = 3;

			}

			buff[jdx] = expr[idx];
			--jdx;
			++slice_flag;

		}

		/*if the character is an operator*/
		else
		{

			if (slice_flag != 0)
			{
				sum = atoi(buff);
				dl_insert_first(No1, sum);
			}

			operator = expr[idx];
			op_flag = 1;
			slice_flag = 0;

			for (jdx = 0; jdx < 4; jdx++)
				buff[jdx] = '0';

			jdx = 3;
		}

		--idx;
	}

	sum = atoi(buff);
	dl_insert_first(No2, sum);
/*
	/*printing No1
	("\nNo1 : ");
	dl_print_list(*No2);
	/*printing No2
	printf("\nNo2 : ");
	dl_print_list(*No1);
*/
	/*calling addition function block for + and - operators*/
	if (operator == '+' || operator == '-')

	{

		/*if op is -, check for greater num and swap*/
		if (operator == '-')
		{
			high_flag = check_greater(No1, No2);
			//printf("\nhigh = %d\n", high_flag);
		}
		if( high_flag == 100)
		{
			Result = eval_sum(No2, No1, operator);
		}
		else
		{
			Result = eval_sum(No1, No2, operator);
		}

		if (operator == '+')
			printf("\nResult = ");

		if (operator == '-')
		{

			/*if the 1st num is less than 2nd num, print - sign*/
			if (high_flag == 1)
				printf("\nResult = -");

			else
				printf("\nResult = ");

		}

		dl_print_list(Result);
		printf("\n");
	}

	/*if the operator is "*"*/
	if (operator == '*')
	{
		Result = eval_mul(No1, No2, operator);
		printf("\nResult : ");
		dl_print_list(Result);
	}

	/*if the operator is "/"*/
	if (operator == '/')
	{
		int count = apc_evaluation_div(No1, No2, operator);
		printf("\nResult is %d\n", count);
	}

	/*if the operator is "%"*/
	if (operator == '%')
	{
		apc_evaluation_div(No1, No2, operator);
	}

	
}






#if 0
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

			for (other_ptr = 0; other_ptr < 8; other_ptr++)
				buff[other_ptr] = '0';

			other_ptr = 7;
		}

		--dig_ptr;
	}

	//dig *ptr1 = *No1, *ptr2 = *No2;

	//printf("from take %d\n", ptr2->cur);
	num = 0;
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
		
		if(high_flag == 1)
		{
			res = eval_sum(No2, No1, operator);
		}
		else
		{
			res = eval_sum(No1, No2, operator);
		}

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
	
	if (operator == '%')
	{
		int count = apc_evaluation_div(No1, No2, operator);
		//printf("\nResult is %d\n", count);
	}
}
#endif