// ���� 1. ����� �̿��Ͽ� ����
// -�θ�Ŭ���� : ��� ��� - �̸� / �ֹι�ȣ
// - �ڽ�Ŭ����1 : ������ - ��� �ڵ� / �⺻�� / ����
// ->����ڵ� ����� / �⺻�� ����� / ���� �����
// - �ڽ�Ŭ����2 : �ӽ��� - �ϴ� / �ٹ��ϼ�
// ->�ϴ� ����� / �ٹ��ϼ� �����
// ���� ��� ���α׷�
#include<iostream>
using namespace std;
class Company {
	char* staff_name;
	int* front_num;
	int* back_num;
public:
	Company() {
		staff_name = new char[10];
		front_num = new int;
		back_num = new int;
	}
	~Company() {
		delete[] staff_name;
		delete front_num;
		delete back_num;
	}
	void set() {
		cout << "����̸� : "; cin >> staff_name;
		cout << "�ֹι�ȣ ���ڸ� : "; cin >> *front_num;
		cout << "�ֹι�ȣ ���ڸ� : "; cin >> *back_num;
	}
};
class full_Time : public Company {
	char code[5];
	int fee;
	int bonus;
public:
	void set() {
		cout << "ȸ���ڵ� : "; cin >> code;
		cout << "�⺻�޿� : "; cin >> fee;
		cout << "��  ���� : "; cin >> bonus;
	}
	void get() {
		cout << "================ ������ ================\n";
	}
};
class Part_Time : public Company {
	int day_fee;
	int day;
public:
	void set() {
		cout << "�Ϸ�޿� : "; cin >> day_fee;
		cout << "�Ѵ��ϼ� : "; cin >> day;
	}
};

�������̵�
- �Լ��� ������ �ǹ��Ѵ�.
- ��ӹ��� �ڽ� Ŭ������ �θ� Ŭ������ ����Լ��� ������ �ϴ� ���� �ǹ��Ѵ�.
- �̹� ����ϰ� �ִ� Ŭ������ ����Լ������� �� ��� �� Ŭ������ �ǵ帮�� �ʰ� �����Ͽ� ����� �� �ִ�.

���� 2. �Լ��� �������̵��� �̿��Ͽ� ����
- �θ� Ŭ���� : �̸� / �ּ�
- �ڽ� Ŭ���� : Ű / ������
- �θ� Ŭ���� : �̸� / �ּ� �����
- �ڽ� : �̸� / Ű / ������ �����

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	char* addr;
public:
	Info1() {
		name = new char[10];
		addr = new char[30];
	}
	~Info1() {
		delete[]name;
		delete[]addr;
	}
	void set() {
		cout << "�̸��Է� : "; cin >> name;
		getchar();
		cout << "�ּ��Է� : "; cin.get(addr, 30);
	}
	void get() {
		cout << "�̸� : " << name << endl;
		cout << "�ּ� : " << addr << endl;
	}
};
class Info2 : public Info1 {

	double* hei;
	double* wei;
public:
	Info2() {
		hei = new double;
		wei = new double;
	}
	~Info2() {
		delete hei;
		delete wei;
	}
	void set() {
		cout << "�̸�  �Է� : "; cin >> name;
		cout << "Ű     �Է� : "; cin >> *hei;
		cout << "������ �Է� : "; cin >> *wei;
	}
	void get() {
		cout << "�̸�   : " << name << endl;
		cout << "Ű     : " << *hei << "cm" << endl;
		cout << "������ : " << *wei << "kg" << endl;
	}
};
int main() {
	Info1 p1;
	p1.set();
	cout << "======================================" << endl;
	p1.get();
	cout << "======================================" << endl;
	Info2 p2;
	p2.set();
	cout << "======================================" << endl;
	p1.get();
	cout << "======================================" << endl;
	p2.get();
	cout << "======================================" << endl;
}
// �ڽ�Ŭ�������� �θ�Ŭ������ ����� �����ٰ� ���� �ʱ�ȭ�Ͽ��� �θ�Ŭ�������� ������ ���� �ʴ´�.

�����ͺ����� Ŭ����
- �����ͺ����� �ڷ���: ����� �ּҷκ��� ������ ������ ũ��� ������ ������ �����Ѵ�.
- �����ͺ����� ��� �ڷ����� �ּҰ����� �����ϱ� ������ ������� ������ 4byte�� �Ǿ��ִ�.

Ŭ���� ������
class A {
};
int main() {
	A* p = new A;
}
- Ŭ���� �ڷ����� ���ؼ� �� Ŭ������ ����� ������ �����ϴ�.
- Ŭ������ �����ͺ��� ���� Ŭ������ ũ��� ������ ������ 4byte�̴�.

���� 3. Ŭ���� �����͸� �̿��Ͽ� ����
- Ŭ���� ������� : �̸� / ����
- �����Լ� : Ŭ������ �����ͺ��� 3���� �Է� ���

#include<iostream>
using namespace std;
class Info {
	char* name;
	int* age;
public:
	Info() {
		name = new char[10];
		age = new int;
	}
	~Info() {
		delete[]name;
		delete age;
	}
	void set() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�����Է� : "; cin >> *age;
	}
	void get() {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << *age << " ��" << endl;
	}
};
int main() {
	Info* I = new Info;
	I->set();
	I->get();
}

�����ͺ����� Ŭ���� ���
- Ŭ���� �ڷ����� ���� ���� �� �� �ִ� Ŭ������ ������ ������ �ִ�.

1. �θ�Ŭ���� �ڷ��� �����ͺ����� �θ� Ŭ���� ������ �ּ� ����
-> �θ�Ŭ���� ����� ������ ����.
2. �θ�Ŭ���� �ڷ��� �����ͺ����� �ڽ� Ŭ���� ������ �ּ� ����
-> �θ�Ŭ���� ����� ������ ����.
3. �ڽ�Ŭ���� �ڷ��� �����ͺ����� �ڽ�Ŭ���� ������ �ּ� ����
-> �θ�� �ڽ� Ŭ���� ��� ������ ����.

#include <iostream>
using namespace std;
class A {
public:
	int a;
	void set() {
		cout << "a" << endl;
	}
};
class B : public A {
public:
	int b;
	void set() {
		cout << "b" << endl;
	}
};
int main() {
	A a1;
	B b1;
	A* pa = &a1;	//�θ�Ŭ���� �����ͺ����� �θ�Ŭ���� ������ �ּ�����.
	A* pb = &b1;	//�θ�Ŭ���� �����ͺ����� �ڽ�Ŭ���� ������ �ּ�����.
	B* pc = &b1;	//�ڽ�Ŭ���� �����ͺ����� �ڽ�Ŭ���� ������ �ּ�����
	
	pa->a = 10;
	pa->set();
	pb->a = 10;
	pb->set();
	//pb->b = 100;	//�ڽ�Ŭ������ ��������� ���ٺҰ���.
	//pb->get();

}