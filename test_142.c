#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int find(char* a, char* b) {
	char*tmp = (char*)calloc(strlen(a) * 2 + 1, sizeof(char));
	if (tmp == NULL) {
		return 1;
	}
	strcpy(tmp, a);
	strcat(tmp, a);
	if (strstr(tmp, b)) {
		return 1;
	}
	free(tmp);
	return 0;
}

int main() {
	char a[] = "AABCD";
	char b[] = "BCDAA";
	if (find(a, b)) {
		printf("found!\n");
	}
	else {
		printf("no found!\n");
	}

	system("pause");
	return 0;
}