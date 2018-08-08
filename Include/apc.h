/*




*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct digits
{
	int cur;
	struct digits *nextD;
	struct digits *prevD;
}dig;

int takeNum(char * expr, dig **No1, dig **No2);
int check_greater(dig **No1, dig **No2);
dig *eval_sum(dig **No1, dig **No2, char operator);
dig *eval_mul(dig **No1, dig **No2, char operator);
int eval_div(dig **No1, dig **No2, char operator);



void dl_print_list(dig *head);
void dl_delete_list(dig **head);
void dl_insert_first(dig **head, int val);
void dl_delete_first(dig **head);
