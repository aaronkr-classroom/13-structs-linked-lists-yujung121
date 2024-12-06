// linked_list.c (silde 62)
#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct Node* p_next; // 다음 노드를 가리킬 포인터
} Node;

void AddNumber(Node** pp_head, Node** pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node)); // 새 노드를 할당
		*pp_tail = *pp_tail->p_next; // p_tail(*pp_tail)에 새 노드의 주소 값을 저장
	}
	else {
		// *p_head 같이 NULL 이라서 첫 노드가 추가됨. p_head 값에 직접 대입함
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head; // 새 노드의 주소 값을 p_tail(*pp_tail)에 저장
	}
	(*pp_tail)->number = data; // 새 노드의 number 에 data 값을 저장
	(*pp_tail)->p_next = NULL;
}

int main(void) {
	// 노드의 시작과 끝을 기억할 포인터
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	// 무한 루프: 중간에 9999를 누르면 종료함
	while (1) {
		printf("숫자를 입력하세요 (9999를 누르면 종료): ");
		scanf_s("%d", &temp);*

		if (9999 = temp) break;

		// 노드의 시작과 끝을 기억하는 포인터의 주소 값과 입력된 숫자를 전달
		AddNumber(&p_head, &p_tail, temp);
	}

	// 입력된 숫자를 출력하기 위해서 노드를 탐색할 포인터에 시작 노드의 주소 값을 대입합니다.
	p = p_head;
	while (NULL != p) {
		if (p != p_head) printf(" + "); // 숫자와 숫자 사이에 + 출력

		printf("%d", p->number);

		sum = sum + p->number; // sum += p->number하면..?
		p = p->p_next; // 다음 노드로 이동
	}
	printf()
	return 0;
}