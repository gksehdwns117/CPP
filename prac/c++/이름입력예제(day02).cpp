/*
#include <stdio.h>
#include <string.h>
void input();
void output();
void search();
void del();
char name[5][20];
int main() {
	while(1){
		int cho;
		printf("1.�̸��Է�\n2.�̸����\n3.�̸��˻�\n4.�̸�����\n5.����\n");
		printf("����>>>"); scanf("%d", &cho);
		if (cho == 1) {
			input();
		}
		else if (cho == 2) {
			output();
		}
		else if (cho == 3) {
			search();
		}
		else if (cho == 4) {
			del();
		}
		else if (cho == 5) {
			printf("���α׷�����\n");
			break;
		}
		else {
			printf("�߸��Է��ϼ̽��ϴ�.\n");
		}
	}
	
}
void input() {
	for (int i = 0; i < 5; i++) {
		printf("%d ��° �̸� �Է� : ", i + 1);
		scanf("%s", name[i], 20);
	}
}
void output() {
	for (int i = 0; i < 5; i++) {
		printf("%d ��° �̸�: %s\n", i + 1, name[i]);
	}
}
void search() {
	char f_name[20];
	printf("ã���� �̸� �Է� : ");
	scanf("%s", &f_name,20);
	for (int i = 0; i < 5; i++) {
		if (!strcmp(name[i], f_name)) {
			printf("%s ���� �ֽ��ϴ�.\n", name[i]);
		}
	}
}
void del() {
	char f_name[20];
	printf("������ �̸� �Է� : ");
	scanf("%s", &f_name,20);
	for (int i = 0; i < 5; i++) {
		if (!strcmp(name[i], f_name)) {
			printf("%s ���� �ֽ��ϴ�.\n", name[i]);
			for (int j = i; j < 5; j++) {
				strcpy(name[j], name[j + 1]);
			}
			strcpy(name[4], "");
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ��° �̸� �Է� : %s\n", i + 1, name[i]);
	}
}
*/
//cpp
// #include : ��ó����-��� �� �Լ��� ȣ��.
// ������: ��ǻ�Ͱ� ������ �� �ִ� ���� ��ȯ(����)

#include<iostream>		//��,��¿� ���� �Լ��� ����
// input output stream
int main() {
	int a = 10;
	double b = 2.1;
	char c = 'c';
	printf("%d\n", a); printf("%lf\n", b); printf("%c", c);
}