// us.c
#include <stdio.h>

// unsigned short int���� us��� ���ο� �̸����� ������
typedef unsigned short int US;

int main(void) {
	US data = 5;
	US temp; // unsiged short int temp; �� ����

	temp = data;
	printf("temp = %d\n", temp);

	return 0;
}	