#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if (i % 4 == 0)
			printf("%dÄêÊÇÈòÄê\n", i);
	}
	system("pause");
	return 0;
}