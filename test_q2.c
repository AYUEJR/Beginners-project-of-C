#include<stdio.h>
#include<stdlib.h>
//    1  3  5
//    3  6  7
//    7  8  9
//从右上角的5开始向左和向下找数
int findnum(int a[][3], int x, int y, int find) {
	int i, j;
	for (i = 0, j = x - 1; j >= 0 && i < y;) {
		if (a[i][j]<find){
			i++;
		}
		else if(a[i][j] > find){
			j--;
		}
		else {
			return 1;
		}
	}
}
int main() {
	int a[3][3] = { {1,3,5},
					{3,6,7},
					{7,8,9} };
	if (findnum(a, 3, 3, 6)) {
		printf("been found\n");
	}
	else {
		printf("no found\n");
	}
	system("pause");
	return 0;
}