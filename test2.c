#include<stdio.h>
#include<stdlib.h>

//查重函数
int checkRank(int*player, int n) {
	int i, res = 0;
	for (i = 0; i < n; ++i) {
		res |= 1 << player[i];
	}
	return res == 0x3e;
}
int main() {
	int murder = 0;
	for (murder = 'A'; murder <= 'E'; ++murder) {
		if((murder!=='A')+(murder=='C')+(murder=='D')){
			printf("%c是凶手\n",murder)
		}
	}
	system("pause");
	return 0;
}