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
int main() {
	struct CAR info[5];
	int i, cho, cnt = 0;
	char search[30];
	char del[30];
	while (1) {
		cout << "1.�����Է� 2.������� 3.�˻� 4.����\n>>>";
		cin >> cho;
		if (cho == 1) {
			cnt++;
			cout << "ȸ���̸�:"; cin >> info[cnt-1].company;
			cout << "�ڵ����̸�:"; cin >> info[cnt-1].name;
			cout << "����:"; cin >> info[cnt-1].year;
			cout << "����:"; cin >> info[cnt-1].cost;
			cout << "==================================" << endl;
			if (cnt > 5) {
				cout << "�� �̻� �Է� �� �� �����ϴ�." << endl;
				cout << "==================================" << endl;
				continue;
			}
		}
		else if (cho == 2) {
			for (i = 0; i < cnt; i++) {
				cout << "-ȸ���̸�:" << info[i].company << endl;
				cout << "-�ڵ����̸�:" << info[i].name << endl;
				cout << "-����:" << info[i].year << "�⵵" << endl;
				cout << "-����:" << info[i].cost << " ����" << endl;
				cout << "==================================" << endl;
			}
		}
		else if (cho == 3) {
			cout << "�ڵ��� ���� �˻�:"; cin >> search;
			for (i = 0; i < cnt; i++) {
				if (!(strcmp(search, info[i].name))==0) {
					cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�." << endl;
				}
				else {
					cout << "------�˻��Ͻ� " << info[i].name << " ����-------" << endl;
					cout << "->ȸ���̸�:" << info[i].company << endl;
					cout << "->����:" << info[i].year << "�⵵" << endl;
					cout << "->����:" << info[i].cost << " ����" << endl;
				}
			}
		}
		else if (cho == 4) {
			cout << "������ �ڵ��� ����:"; cin >> del;
			int k = 0;
			for (i = 0; i < cnt; i++) {
				if (!strcmp(del, info[i].name)) {
					for (k = i; k < cnt; k++) {
						strcpy(info[i].name, info[i + 1].name);
						strcpy(info[i].company, info[i + 1].company);
						info[k].year = info[k + 1].year;
						info[k].cost = info[k + 1].cost;
					}
				}
			}
		}
	}

	return 0;
}
