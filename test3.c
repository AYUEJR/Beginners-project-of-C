
#include <stdio.h>
#include<stdlib.h>
//һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
void find(int arr[], int len) {
	int a = 0;
	int i = 0;
	int b = 0;
	int s1 = 0;
	int s2 = 0;
	for (i = 0; i < len; i++) {
		a = a ^ (arr[i]);  //aΪ�����������,s1��s2�����ֵ
	}
	for (i = 1; i <= 32; i++) {
		if (1 &&(a >> i) == 1) {  //���������a�����Ϊ1��ʱ,���Ƶ�λ��i��ֵ
			b = i;
		}
	}
	for (i = 0; i < len; i++) {
		if ((arr[i] >> b) && 1 == 1) {  //���������������е�iλΪ1����
			s1 ^= arr[i];//
		}
		else { //���������������е�iλΪ0����
			s2 ^= arr[i];
		}
	}
	printf("s1=%d\n s2=%d\n", s1, s2);
}
int main() {
	int arr[] = { 1,2,3,4,5,6,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	find(arr, len);
	system("pause");
	return 0;
}