/*




*/

#include <apc.h>

int main(int argv, char *argc[])
{
	if(argv == 2)
	{
		dig *No1 = NULL, *No2 = NULL;
		takeNum(argc[1], &No1, &No2);
	}
	else
	{
		printf("error no arguments passed: \npass expression as one argument\neg: ./main.out <expr>\n");
	}
}
