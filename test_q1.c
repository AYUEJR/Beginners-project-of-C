#include<stdio.h>
#include<stdlib.h>

#define SIZEE(a) (sizeof(a)/sizeof(a[0]))
int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int s[128] = { 0 };
	int d[128] = { 0 };
	int i ;
	int counts = 0,countd=0;
	for (i = 0; i < SIZEE(a);++i){
		if (a[i] % 2) {
			s[counts++] = a[i];
		}
		else {
			d[countd++] = a[i];
		}
	}
	for (i = 0; i <counts; ++i) {
		a[i] = s[i];
	}
	for (; i < SIZEE(a); ++i) {
		a[i] = d[i-counts];
	}
	for (i = 0; i < SIZEE(a); ++i) {
		printf("%d ", a[i]);
	}

	putchar('\n');
	system("pause");
	return 0;
}