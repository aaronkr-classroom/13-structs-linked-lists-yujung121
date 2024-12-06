// 2d_ppl_age_step.c
#include <stdio.h>
#include <malloc.h>

int main(void) {
	// ����
	int age_step, ages, member, temp, sum;
	// ���ɺ��ο����� ������ ������ - ����ڿ��� �Է¹���
	unsigned char *p_limit_table;
	// ���ɺ� ��������Ű�� Ƚ���� ������ 2���� ������
	unsigned char **p;

	printf("20����� �����ؼ�(?����) �������� �� ���ΰ���: ");
	scanf_s("%d", &age_step);

	// ���ɺ� �ο����� ������ �޸𸮸� ����
	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);

	// ���ɺ��� ��������Ű�� Ƚ���� �Է� ����
	for (ages = 0; ages < age_step; ages++) {
		// �� ������ ��������Ű�� Ƚ����� �����
		printf("\n%d0�� ������ ��������Ű�� Ƚ��\n", ages + 2);
		printf("�� ���ɴ�� �� ���Դϱ�?");

		scanf_s("%d", &temp); 
		*(p_limit_table + ages) = (unsigned char)temp;

		// �Է� ���� �ο�����ŭ �޸𸮸� �Ҵ�
		*(p + ages) = (unsigned char*)malloc(*(p_limit_table + ages));

		// �ش� ���ɿ� �Ҽӵ� ������� ������� �Է� ����
		for (member = 0; member < *(p_limit_table + ages); member++) {
			// #1, #2, ... ��� ���
			printf("#%d: ", member + 1);

			// ��������Ű�� Ƚ���� ������ �Է� ����
			scanf_s("%d", &temp);
			*(*(p + ages) + member) = (unsigned char)temp;
		}
	}

	printf("\n\n���ɺ� ��� ��������Ű�� Ƚ��\n");

	// ���ɺ��� �Էµ� Ƚ���� �ջ��Ͽ� ��� ���� �����
	for (ages = 0; ages < age_step; ages++) {
		sum = 0;
		// 20��: 30��: 40��: ��� ���
		printf("%d0��: ", ages + 2);

		// �ش� ���ɿ� �Ҽӵ� ������� Ƚ���� �ջ���
		for (member = 0; member < *(p_limit_table + ages); member++) {
			sum = sum + *(p[ages] + member);
		}

		// �ջ� ���� �ο����� ����� ����� ��
		printf("%5.2f\n", (double)sum / *(p_limit_table + ages));

		// �� ���ɿ� �Ҵ��ߴ� ���� �޸𸮸� ������
		free(*(p + ages));
	}

	// ��������Ű�� Ƚ���� �����ϱ� ���ؼ� �����ߴ� �޸𸮸� ������
	free(p);
	// ���ɺ� �ο����� ����ϱ� ���ؼ� ����ߴ� �޸𸮸� ������
	free(p_limit_table);

	return 0;
}