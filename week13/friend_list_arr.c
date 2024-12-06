// friend_list_arr.c
#include <stdio.h>

#define MAX_COUNT 5 // ģ�� ��� ������ �ִ� ��

typedef char NAME_TYPE[14]; // 13�� ���� + NULL ����
typedef unsigned short int US;

int AddFriend(NAME_TYPE* p_name, US* p_age, float* p_height, float* p_weight, int count) {
	// �Է� ������ �ִ� ���� �Ѿ����� üũ��
	if (count < MAX_COUNT) {
		printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
		printf("1. �̸�: ");
		scanf_s("%s", *(p_name + count), sizeof(*(p_name + count)));

		printf("2. ����: ");
		scanf_s("%hu", p_age + count); // age �迭�� count ��ġ�� ���̸� ������

		printf("3. Ű: ");
		scanf_s("%f", p_height + count);

		printf("4. ������: ");
		scanf_s("%f", p_weight + count);

		printf("�Է��� �Ϸ��߽��ϴ�.\n\n");

		return 1;
	}
	else { // �Է� ������ �ִ� ���� �Ѿ��� �� ������ �����
		printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�.\n");
		printf("�ִ� %d������� ���� �����մϴ�.\n\n", MAX_COUNT);

		return 0;
	}
}

void ShowFriendList(NAME_TYPE* p_name, US* p_age, float* p_height, float* p_weight, int count) {
	
	if (count > 0) {
		printf("\n��ϵ� ģ�� ���\n");
		printf("=================================\n");
		for (int i = 0; i < count; i++) {
			printf("%14s, %3d, %6.2f, %6.2f\n",
				*(p_name + i),
				*(p_age + i),
				*(p_height + i),
				*(p_weight + i));
		}
		printf("=================================\n");
	}
	else { // ��ϵ� ģ���� ������ ������ �����
		printf("\n��ϵ� ģ���� �����ϴ�.\n\n");
	}
}

int main(void) {
	// �迭 ����ϱ�
	NAME_TYPE name[MAX_COUNT];
	US age[MAX_COUNT];
	float height[MAX_COUNT];
	float weight[MAX_COUNT];
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
			if (1 == AddFriend(name, age, height, weight, count))
				count++;
			break;
		case 2:
			ShowFriendList(name, age, height, weight, count);
			break;
		default:
			// ��ȣ�� ��ȿ���� ���� ��� ���� �޽����� ���
			printf("1~3 ��ȣ�� ������ �� �ֽ��ϴ�.\n\n");

		}
	}
	return 0;
}