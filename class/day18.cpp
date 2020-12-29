����1. ���� ����� �̿��Ͽ� ����
- Ŭ����1 : �̸� / ���� / �ּ�
- Ŭ����2 : �������� / ���������� / ���� / ���
- Ŭ����3 : �г� / �й� / ����
- Ŭ����4 : ���Ƹ��� / ���Ƹ�Ȱ��

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	int age;
	char* addr;
public:
	Info1() {
		name = new char[10];
		addr = new char[20];
	}
	~Info1() {
		delete[] name;
		delete[]addr;
	}
	void set() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�����Է� : "; cin >> age;
		getchar();
		cout << "�ּ��Է� : "; cin.get(addr, 20);
	}
	void get() {
		cout << "�̸� : " << name << endl;
		cout << "���� :" << age << endl;
		cout << "�ּ� : " << addr << endl;
	}
};
class Info2 {
	int n_major;
	int major;
	double avr;
public:
	void set() {
		cout << "�������� ���� �Է�   : "; cin >> major;
		cout << "���������� ���� �Է� : "; cin >> n_major;
	}
	void get() {
		cout << "�������� ����   : " << major << endl;
		cout << "���������� ���� : " << n_major << endl;;
		avr = (double)(major + n_major) / 3;
		cout << "------------------------------------------" << endl;
		cout << "������� : " << avr;
	}
};
class Info3 {
	int grade;
	int sch_num;
	char *sch_major;
public:
	Info3() {
		sch_major = new char[30];
	}
	~Info3() {
		delete[] sch_major;
	}
	void set() {
	Info1:set();
	Info2:set();
		cout << "�г��Է� : "; cin >> grade;
		cout << "�й��Է� : "; cin >> sch_num;
		cout << "�����Է� : "; cin >> sch_major;
	}
	void get() {
	Info1:get();
	Info2:get();
		cout << "�г� : " << grade << endl;
		cout << "�й� : " << sch_num << endl;
		cout << "���� : " << sch_major << endl;
	}
};
class Info4 {
	char* cir;
	char* cir_do;
public:
	Info4() {
		cir = new char[10];
		cir_do = new char[100];
	}
	~Info4() {
		delete[] cir;
		delete[] cir_do;
	}
	void set() {
		cout << "���Ƹ��� �Է� : "; cin >> cir;
		getchar();
		cout << "���Ƹ� �ֿ� Ȱ�� �Է� : "; cin.get(cir_do, 100);
	}
	void get() {
		cout << "���Ƹ��� : " << cir << endl;
		cout << "-> '" << cir_do << ".'" << endl;
	}
};

�����Լ� - ������
- �����Լ��� virtual �̶�� Ű���带 ����ؼ� �����.
- �θ�Ŭ���������� ���� �ϰ�, �ڽ�Ŭ�������� ���ǵǴ� �Լ�
- �����Ҵ翡 ���ؼ� ó���ȴ�.


#include<iostream>
using namespace std;
class P {
public:
	void get1() {
		cout << "�θ�Ŭ����..." << endl;
	}
};
class C :public P {
public:
	void get2() {
		cout << "�ڽ�Ŭ����..." << endl;
	}
};

//�����ε� : �Ű������� �ٸ��� �Լ��� �̸��� ���Ƶ� �ȴ�.
int main() {
	P* pa = new P;
	pa->get1();
	//pa->get2();   >>> �ڽ�Ŭ���� ���� �Ұ��� 
	P* pb = new C;
	C* pc = new C;
//�������̵� :
}

#include<iostream>
using namespace std;
class Test {
protected:
	int a;
	int b;
public:
	void set() {
		cout << "a���Է�:"; cin >> a;
		cout << "b���Է�:"; cin >> b;
	}
	//void get() {
	//	cout << "a�������� : " << a << endl;
	//	cout << "b�������� : " << b << endl;
	//}
	virtual void get() {};
};
class child1 :public Test {
public:
	void get() {
		cout << "���� : " << a+b << endl;
	}
};
class child2 :public Test {
public:
	void get() {
		cout << "��� : " << (a+b)/2 << endl;
	}
};
int main() {
	Test t1;
	t1.set(); t1.get();
	Test* pt1 = new child1;
	pt1->set();
	pt1->get();
	Test* pt2 = new child2;
	pt2->set();
	pt2->get();
}


����2. �����Լ��� �̿��Ͽ� ����
-Ŭ����1 : ������1��
-Ŭ����2 : ������ �� ��ŭ *�� ���
-Ŭ����3 : ������ �� ��ŭ�� ���� ���

#include<iostream>
using namespace std;
class Num {
protected:
	int a;
public:
	void set() {
		cout << "�����Է� : "; cin >> a;
	}
	virtual void get(){}
};
class Star :public Num {
public:
	void get() {
		for (int i = 0; i < a; i++) {
			for (int k = 1; k <= i + 1; k++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};
class Sum :public Num {
	int sum;
public:
	void get() {
		sum = 0;
		for (int i = 1; i <= a; i++) {
			sum += i;
		}
		cout << "1 ~ " << a << "������ �� : " << sum << endl;
	}
};
int main() {
	Num* t1 = new Star;
	t1->set();
	t1->get();
	Num* t2 = new Sum;
	t2->set();
	t2->get();
}
- �θ�Ŭ���� �����ͺ����� ��ü ���� �� �� ����Ѵ�.
- **�θ�Ŭ���� �����ͺ����� �ڽ�Ŭ������ ��� �� �� �ִ� �ΰ��� ����
1.�ڽ�Ŭ������ �Լ��� �θ�Ŭ�������� �����ؾ��Ѵ�.
2.�θ�Ŭ������ �Լ��� �ڽ� �Լ� �տ��� virtual (�����Լ� Ű����) �� �ٿ����Ѵ�.

������
- ��ӵ� Ŭ������ ���� �Ҵ��ؼ� ����� �� �θ�Ŭ������ �ڽ�Ŭ������ �����ϴ� ���� �ǹ��Ѵ�.
- �θ�Ŭ������ �����ͺ����� ����� �����Ҵ��� �ڽ�Ŭ������ �ϸ� �θ�Ŭ������ �ڽ�Ŭ������ �����Ҽ��ִ�.

�����Լ�
- virtual Ű���带 �ٿ��� ���ǵ� �Լ��� ��Ÿ�ӽ� �����Ͱ� ����Ű�� Ÿ�Կ� ���� ȣ�� �Լ��� �����ϰԵȴ�.
- �����Ͱ� � ��ü�� ����Ű�� �ִ����� ���� ȣ�� �� �Լ��� �����ϰ� �����Ѵ�.
- ���� �̸� ���ؼ� �������� ������ �� �ִ�.