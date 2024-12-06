// friend_list_struct.c
#include <stdio.h>

#define MAX_COUNT 5 // ģ�� ��� ������ �ִ� ��

typedef char NAME_TYPE[14]; // 13�� ���� + NULL ����
typedef unsigned short int US;
typedef struct {
	NAME_TYPE name;
	US age;
	float  height;
	float weight;
} Person;

int AddFriend(Person *p_friend, int count) {
	// �Է� ������ �ִ� ���� �Ѿ����� üũ��
	if (count < MAX_COUNT) {
		// friends �迭�� count ��ġ�� �̵���
		p_friend = p_friend + count;

		printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
		printf("1. �̸�: ");
		scanf_s("%s", p_friend->name, sizeof(p_friend->name));

		printf("2. ����: ");
		scanf_s("%hu", &p_friend->age + count); 

		printf("3. Ű: ");
		scanf_s("%f", &p_friend->height);

		printf("4. ������: ");
		scanf_s("%f", &p_friend->weight);

		printf("�Է��� �Ϸ��߽��ϴ�.\n\n");

		return 1;
	}
	else { // �Է� ������ �ִ� ���� �Ѿ��� �� ������ �����
		printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�.\n");
		printf("�ִ� %d������� ���� �����մϴ�.\n\n", MAX_COUNT);
	}
}

void ShowFriendList(Person *p_friend, int count) {

	if (count > 0) {
		printf("\n��ϵ� ģ�� ���\n");
		printf("=================================\n");
		for (int i = 0; i < count; i++) {
			printf("%14s, %3d, %6.2f, %6.2f\n", 
				p_friend->name,
				p_friend->age,
				p_friend->height,
				p_friend->weight);
			p_friend++;// ���� ��ġ�� �ִ� ģ�� ������ �ּҸ� �̾����
		}
		printf("=================================\n");
	}
	else { // ��ϵ� ģ���� ������ ������ �����
		printf("\n��ϵ� ģ���� �����ϴ�.\n\n");
	}
}

int main(void) {
	// ����ü ����ϱ�
	Person friends[MAX_COUNT];
	int count = 0, menu_num;

	// ���� ����: ����ڰ� 3�� ������ break ������ �����Ŵ
	while (1) {
		// �޴��� ȭ�鿡 �����
		printf("\t[ �޴�]\t\n");
		printf("=================================\n");
		printf("1. ģ�� �߰�\n");
		printf("2. ģ�� ��� ����\n");
		printf("3. ����\n");
		printf("=================================\n");
		printf("��ȣ ����: \n");
		scanf_s("%d", &menu_num);

		// while ������ ��������..
		if (menu_num == 3) break;

		switch (menu_num) {
		case 1:
			/*
			AddFriend �Լ��� 1�� ��ȯ�ϸ� ���������� ģ�� ������ �߰��� ���Դϴ�.
			���� 1�� ��ȯ���� ���� ��ϵ� ģ�� ���� ������ŵ�ϴ�.
			*/
			if (1 == AddFriend(friends, count))
				count++;
			break;
		case 2:
			ShowFriendList(friends, count);
			break;
		default:
			// ��ȣ�� ��ȿ���� ���� ��� ���� �޽����� ���
			printf("1~3 ��ȣ�� ������ �� �ֽ��ϴ�.\n\n");

		}
	}
	return 0;
}