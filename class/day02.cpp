#include<stdio.h>
void input();
char output();
char search();
char del();
char name[5][10];
int main() {
	int cho;
	while(1){
		printf("����:"); scanf_s("%d", &cho);
		if (cho == 1) {
			for (int i = 0; i < 5; i++) {
				printf("�̸��Է�:"); scanf_s("%s", name[i], 10);
			}
		}
		else if (cho == 2) {
			for (int i = 0; i < 5; i++) {
				printf("%s", name[i]);
			}
		}
		else if (cho == 3) {
			char search[5];
			printf("ã�� �̸��� �˻�:"); scanf_s("%s", search,5);
			for (int i = 0; i < 5; i++) {
				if (search == name[i]) {
					printf("�˻��� �̸��� �ֽ��ϴ�.");
				}
				else {
					printf("�˻��� �̸��� �����ϴ�.");
				}
			}
		}
		else if (cho == 4) {
			break;
		}
		return 0;
	}
}
void input() {
	
}


//cpp
#include : ��ó����-��� �� �Լ��� ȣ��.
������: ��ǻ�Ͱ� ������ �� �ִ� ���� ��ȯ(����)

#include<iostream>		��,��¿� ���� �Լ��� ����
input output stream
iostream -> stdio.h / stdlib.h(malloc) / windows.h
int main() {
	int a = 10;
	double b = 2.1;
	char c = 'c';
	printf("%d\n", a); printf("%lf\n", b); printf("%c\n", c);
	system("calc.exe");
}

#include<iostream>
int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	char name[10] = "ȫ�浿";
	std::cout << "���� �ΰ� �Է�:";
	std::cin >> a >> b;
	std::cout << a << " " << b << "\n";
	std::cout << a << std::endl;		//a�� ���� cout�� ���� cout�� ����Լ�
	std::cin >> a;						//a�� cin�� �Է��Լ��� ����Ͽ� ���� ����.
	std::cout << a << std::endl;
	std::cout << a <<" "<< b <<" "<< c << " "<< std::endl; //���� ������ �ѹ��� ����ϴ� ���
	std::cout << a << "\n" << b << "\n" << c << "\n" << std::endl; //�̽������� ���ڵ� ��°���.
	std::cout << "���� ���� ��������\n";						//���ڿ� ������� ���
	std::cout << "���� �Է�\n:";								//�����
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << name << std::endl;
	std::cout << "���ڿ� �Է�:";
	std::cin >> name;
	std::cout << name << std::endl;
	 
����	c���� �߰��� ���� ������ ����
c++�� �Լ��߹ݺο� ���� ������ �ص� ��� ����.
//int aa;
}