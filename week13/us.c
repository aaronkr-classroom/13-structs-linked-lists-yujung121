// us.c
#include <stdio.h>

// unsigned short int형을 us라는 새로운 이름으로 정의함
typedef unsigned short int US;

int main(void) {
	US data = 5;
	US temp; // unsiged short int temp; 와 같음

	temp = data;
	printf("temp = %d\n", temp);

	return 0;
}	