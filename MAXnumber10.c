#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int num[10];
	int i=0;
	int max = 0;
	printf("依次输入10个数：\n");
	for (i = 0; i < 10; i++) {
		
			scanf("%d", &num[i]);
	}
	for (i = 0,max=num[0]; i < 10; i++) {
		if (num[i] >max) {
			max = num[i];
		}

	}
	printf("最大数为%d\n", max);
    return 0;
}