#include<stdio.h>
#include<stdlib.h>

//���غ���
int checkRank(int*player, int n) {
	int i, res = 0;
	for (i = 0; i < n; ++i) {
		res |=  1 << player[i];
	}
	return res == 0x3e;
}
int main() {
	int player[5] = { 0 };
	for (player[0] = 1; player[0] <= 5; ++player[0]) {
		for (player[1] = 1; player[1] <= 5; ++player[1]) {
			for (player[2] = 1; player[2] <= 5; ++player[2]) {
				for (player[3] = 1; player[3] <= 5; ++player[3]) {
					for (player[4] = 1; player[4] <= 5; ++player[4]) {
						//Aѡ��˵��B�ڶ����ҵ����� 
						//Bѡ��˵���ҵڶ���E���ģ�
						//Cѡ��˵���ҵ�һ��D�ڶ���
						//Dѡ��˵��C����ҵ�����
						//Eѡ��˵���ҵ��ģ�A��һ��
						if ((player[0] == 3) + (player[1] == 2) == 1 &&
							(player[1] == 2) + (player[4] == 4) == 1 &&
							(player[2] == 1) + (player[3] == 2) == 1 &&
							(player[2] == 5) + (player[3] == 3) == 1 &&
							(player[4] == 4) + (player[0] == 1) == 1 &&
							checkRank(player, 5)){
							printf("a   %d\n",player[0]);
							printf("b   %d\n",player[1]);
							printf("c   %d\n",player[2]);
							printf("d   %d\n",player[3]);
							printf("e   %d\n",player[4]);
                         }
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}