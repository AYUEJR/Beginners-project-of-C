#include<stdio.h>
int main() {
	int i = 0;
	int a = 1;
	for (a = 1; a <= 100; ++a) {
		if (a %10 == 9)
			i++;
		if (a / 10 == 9)
			i++;
	}
	printf("1-100中出现9 %d 次\n", i);

	return 0;
}