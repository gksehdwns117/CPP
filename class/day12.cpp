����1.������, �Ҹ��ڸ� �̿��Ͽ� �����Ҵ����� ����
- �Է� / ��� / ���� �Լ�
- �̸��� ���� �Է�
- �̸��� ���� ���
- �� ���� ������ 5��
- �Ѳ����� �Է� ��� �ƴ� �Է��ϰ��� �� �� �Է� ����ϰ��� �� �� ��� �ǵ��� �� ��.

#include<iostream>
using namespace std;
class Person {
private:
	char* name;
	int* age;
public:
	Person() {
		name = new char[10];
		age = new int;
	}
	void set() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�����Է� : "; cin >> *age;
	}
	void get() {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << *age << endl;
	}
	~Person() {
		delete[]name;
		delete(age);
	}
};
int main() {
	Person info[5];
	int cho = 0;
	int cnt = 0;
	while (1) {
		cout << "1.�Է� 2.��� 3.����\n>>>"; cin >> cho;
		if (cho == 1) {
			info[cnt].set();
			cnt += 1;
		}
		else if (cho == 2) {
			for (int i = 0; i < cnt; i++) {
				info[i].get();
			}
		}
		else if (cho == 3) {
			for (int i = 0; i < cnt; i++) {
				info[i].~Person();
			}
			break;
		}
	}
	return 0;
}


���� ������
- �Ű������� Ŭ���� ���۷��� ������ ������
- ��ü�� ������ ��ü�� �ʱ�ȭ �� �� �ڵ����� ȣ��Ǵ� ����Լ�
- ����ڰ� ������ ������ default ���� �����ڰ� �����Ͽ� ���� �ڵ����� ȣ��ȴ�.
Ŭ������(Ŭ������& ������) {

}
Test(Test& r) {

}

���� ������ Ư¡
- Ŭ���� ���۷������� ���ڷ� ���� �����ڸ� ���� �����ڶ�� �Ѵ�.
- ���� �����ڴ� �������� �� ������ ������ ������� ��ü�� �ʱ�ȭ �Ѵ�.
- ���� �����ڰ� ȣ��Ǵ� ���
1> ��ü�� ��ü�� �ʱ�ȭ �Ҷ� �ڵ����� ȣ�� �ȴ�.
2> �Լ��� ���� ���� ȣ���� �ϸ鼭 ��ü�� �Լ��� �Ű������� �����Ҷ� �ڵ����� ȣ��ȴ�.
3> �Լ����� ��ü�� �����ϴ� ��� �ڵ����� ȣ��ȴ�. ->�ӽú����� ����

����Ʈ ���� ������
- ���� �����ڰ� ȣ��Ǿ�� �ϴ� ������ Ŭ���� �ȿ� ��������ڰ� ���� �� �ڵ����� ������� ȣ��ȴ�.
- ����Ʈ ���� �����ڴ� ��������� bit������ 1:1�� �����Ѵ�.

���� ����: �ϳ��� ���� ���� ������ �ٸ� �������� ����
���� ����: �ϳ��� ���� ���� ���� ��ü�� ����


#include<iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "������" << endl;
	}
	~Test() {
		cout << "�Ҹ���" << endl;
	}
};
void ex1(Test t) { // main.t -> ex1.t�� ����
	// �Ϲݺ����� �Ű�����
	Test tt = t;
	// tt�� t�� �ʱ�ȭ
	cout << &tt << endl;
	cout << &t << endl;
}
void ex2(Test& r) {
	// ���۷��� ������ �Ű�����(���������� ������ ����)
	Test rr = r;
}
void ex3(Test* p) {

}
int main() {
	Test t;
	ex1(t);
	ex2(t);
	ex3(&t);
}


#include<iostream>
using namespace std;
class Test {
	int val;
public:
	Test(int v = 0) {
		cout << "Test(int v) ȣ��" << endl;
		val = v;
	}
	Test(Test& r) {
		cout << "Test(Test& r)ȣ��" << endl;
		this->val = r.val;
	}
	~Test() {
		cout << "�Ҹ��� ����" << endl;
	}
	void set(int v) {
		val = v;
	}
	void get() {
		cout << this->val << endl;
	}
};
int main() {
	Test tt1(10);
	// tt1.Test(10);
	tt1.get();
	Test tt2 = tt1;	//��������
	// tt2.Test(tt2);
	Test& tt3 = tt1;
	tt2.get();
	cout << "tt1: " << &tt1 << endl;
	cout << "tt2: " << &tt2 << endl;

}


/*����2.
- ������� : ����/�̸�/��ȭ��ȣ
- �Լ�: ���/���/����/�˻�/���α׷� ����*/

#include<iostream>
using namespace std;
class Student {
	int *num;
	char* name;
	char* p_num;
public:
	Student() {
		num = new int;
		name = new char[10];
		p_num = new char[15];
	}
	~Student() {
		delete(num);
		delete[](name);
		delete[](p_num);
	}
	void set() {
		cout << "----------- �������� �Է� -----------\n" << endl;
		cout << "���� �Է� : "; cin >> *num;
		cout << "�̸� �Է� : "; cin >> name;
		cout << "��ȭ��ȣ �Է� : "; cin >> p_num;
	}
	int ret_num() {
		return *num;
	}
	void get() {
		
		cout << *num << ".";
		cout << "�̸� :" << name;
		cout << " (" << p_num <<")" << endl;
	}
};
int main() {
	Student stu[5];
	int cho = 0;
	int cnt = 0;
	int num;
	while (1) {
		cout << "----------- �������� -----------\n" << endl;
		cout << "1.��� 2.��� 3.���� 4.�˻� 5.���α׷� ����\n>>>"; cin >> cho;
		system("cls");
		switch (cho) {
		case 1:
			stu[cnt].set();
			cnt++;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "----------- �������� ��� -----------\n" << endl;
			for (int i = 0; i < cnt; i++) {
				stu[i].get();
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "���� �� ���� �Է� : "; cin >> num;
			int a;
			for (int i = 0; i < cnt; i++) {
				a = stu[i].ret_num();
				if (num == a) {
					cnt--;
					for (int j = i; j < cnt; j++) {
						stu[j] = stu[j+1];
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "�˻� �� ���� �Է� : "; cin >> num;
			a = 0;
			for (int i = 0; i < cnt; i++) {
				a = stu[i].ret_num();
				if (num == a) {
					cout << "------ �˻��� �л� -------" << endl;
					stu[i].get();
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "���α׷��� ����˴ϴ�." << endl;
			break;
		}	
	}
}