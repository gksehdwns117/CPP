//����1. ����ü �����͸� �̿��Ͽ� ����
//- ������/�ڵ����̸�/���/����
//- �Է�/���/�˻�/���� ����� ���� ���α׷����� ����
//- �ִ� �Է� ����� 5��� 5�� �ʰ��Ͽ� �Է��� �� ����.
//- �ּ� �Է� ����� 0��� 0   �̸����� �Է��� �� ����.

#include<iostream>
using namespace std;
struct CAR {
	char company[30];
	char name[30];
	int  year;
	int  cost;
};
int cnt, i;
struct CAR info[5];
void input() {
	cnt++;
	cout << "ȸ���̸�:"; cin >> info[cnt - 1].company;
	cout << "�ڵ����̸�:"; cin >> info[cnt - 1].name;
	cout << "����:"; cin >> info[cnt - 1].year;
	cout << "����:"; cin >> info[cnt - 1].cost;
	cout << "==================================" << endl;
}
void output() {
	for (i = 0; i < cnt; i++) {
		cout << "-ȸ���̸�:" << info[i].company << endl;
		cout << "-�ڵ����̸�:" << info[i].name << endl;
		cout << "-����:" << info[i].year << "�⵵" << endl;
		cout << "-����:" << info[i].cost << " ����" << endl;
		cout << "==================================" << endl;
	}
}
void searching() {
	char search[30];
	cout << "�ڵ��� ���� �˻�:"; cin >> search;
	system("cls");
	for (i = 0; i < cnt; i++) {
		if (!(strcmp(search, info[i].name)) == 0) {
			cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�." << endl;
			continue;
		}
		else {
			cout << "------�˻��Ͻ� " << info[i].name << " ����-------" << endl;
			cout << "->ȸ���̸�:" << info[i].company << endl;
			cout << "->����:" << info[i].year << "�⵵" << endl;
			cout << "->����:" << info[i].cost << " ����" << endl;
			break;
		}
	}
}
void remove() {
	char del[30];
	cout << "������ �ڵ��� ����:"; cin >> del;
	int k = 0;
	for (i = 0; i < cnt; i++) {
		if (!strcmp(del, info[i].name)) {
			for (k = i; k < cnt; k++) {
				cout << info[i].name << " ������ ������ �����Ǿ����ϴ�." << endl;
				strcpy(info[i].name, info[i + 1].name);
				strcpy(info[i].company, info[i + 1].company);
				info[k].year = info[k + 1].year;
				info[k].cost = info[k + 1].cost;
				cnt--;
			}
		}
	}
}
int main() {
	int cho = 0;
	while (1) {
		cout << "######### 5/" << cnt << " #########\n" << endl;
		cout << "1.�����Է� 2.������� 3.�˻� 4.����\n>>>";
		cin >> cho;
		system("cls");
		if (cho == 1) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			if (cnt == 5) {
				cout << "�� �̻� �Է� �� �� �����ϴ�." << endl;
				system("pause");
				system("cls");
				continue;
			}
			input();
			system("cls");
		}
		else if (cho == 2) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			output();
			system("pause");
			system("cls");
		}
		else if (cho == 3) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			searching();
			system("pause");
			system("cls");
		}
		else if (cho == 4) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			if (cnt == 0) {
				cout << "�� �̻� ���� �� ������ �����ϴ�." << endl;
				system("pause");
				system("cls");
				continue;
			}
			remove();
			system("pause");
			system("cls");
		}
	}
	return 0;
}
