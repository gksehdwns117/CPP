 ���� 1. const �� �̿��Ͽ� ����
 - �й� / �̸� �� �����ϴ� class ����
 - �й��� �ѹ� �����Ǹ� ���� �Ұ���
 - 5���� ��ü�� ����� �Է� �� ���

#include<iostream>
using namespace std;
class Student {
	const int cla_num;
	char *name;
public:
	Student(int n1) :cla_num(n1) {
		name = new char[10];
	};
	~Student() {
		delete[] name;
	}
	void set() {
		cout << "�̸��Է� : "; cin >> name;
	}
	void get() {
		cout << "�й� : " << cla_num << endl;
		cout << "�̸� : " << name << endl;
		cout << "---------------------------------" << endl;
	}
};

int main() {
	//Student info1(20183131);
	//Student info2(20192020);
	//Student info3(20181111);
	//Student info4(20171111);
	//Student info5(20161111);
	//
	//info1.set(); info2.set(); info3.set(); info4.set(); info5.set();
	//info1.get(); info2.get(); info3.get(); info4.get(); info5.get();

	Student info[5] = { 20191111,20191112,20191113,20191114,20191115 };

	for (int i = 0; i < 5; i++) {
		info[i].set();
	}
	for (int i = 0; i < 5; i++) {
		info[i].get();
	}
}

����Լ� ���ȭ
- Ŭ������ ����Լ��� ���ȭ ��ų �� �ִ�.
- ����Լ��� �ڿ� const �� �ٿ��ָ� �ȴ�.
- ������ ���� �Լ��� const �� ���̸� �����ε��� �Ǳ� ������ ����Լ��� ������ ���
	�Լ� ����ο� �Լ� ���Ǻ� ��� const �� �ٿ���� �Ѵ�.
- const ����Լ��� ��������� ���� ������ �� ����.
- const ����Լ��� const ����Լ��� ȣ���� �����ϴ�.
- const ����Լ��� ��������� �ּҸ����� �Ұ����ϴ�. -> ��� �ڷ����տ� const �� ���̸� ���� �� �� �ִ�.
- const ����Լ��� �ַ� ��¿����� ����Ѵ�.
int func() const {} //�Ϲ����� const �Լ�
const int func() const //���ϰ��� �ֱ� ���� const �Լ�

#include<iostream>
using namespace std;
class Test {
	const int a;
	char b;
	int c;
public:
	Test(int ia, char ib) :a(ia) {
		b = ib;
		c = 100;
	}
	void show() const {
		cout << a << " : " << b << endl;
		//c = 200;	//const�Լ��� ��������� ���� ���� �� �� ����.
	}
};
int main() {
	Test t1(1, 'A');
	t1.show();
}

static ����� Ư¡
- Ŭ�������� static �� �ٿ� ������ ������ �Լ��� �ǹ��Ѵ�.
- Ŭ���� �ȿ��� ����� ������� Ŭ������ ����� �ƴϴ�.
- �������� ������ �Լ��̴�.
- static ����� ���� �����ڷ� �ʱ�ȭ�� ���ش�.(::)
- static ����� ���α׷� ���۽ÿ� �޸𸮰����� ����ǰ� ���α׷��� ����Ǹ� �Ҹ�ȴ�.
- ��ü �������� ������� ����� �� �ִ�.
- static ������ ��� ��ü�� �����ؼ� ��� �� �� �ִ�.
- static ����� �ܺ� ���ǽÿ��� ����ο��� static �� ����Ѵ�.
- static ����Լ��� static ��������� ��� �� �� �ִ�.
- static ��������� �ʱ�ȭ�� Ŭ������ ����Լ������� �� �� ����.
-> ��ü ���� ������ �޸𸮿� �����Ǵ� static ������ �ʱ�ȭ �� �� ����.
- static ��������� �ڵ����� �ʱ�ȭ ���� �ʴ´�.
-> ������ �ʱ�ȭ�� �� ��� �ϴµ� Ŭ���� �ۿ��� �ؾ� �Ѵ�.

#include<iostream>
using namespace std;

void func() {
	static int a = 1;
	cout << a << endl;
	a++;
}
int main() {
	func();
	func();
	func();
	// cout<<a<<endl; -> static������ ������ ��ġ������ ����� ����.
}


#include<iostream>
using namespace std;
class Point {
	int x, y;	//�������
	static int cnt;	//static ����
public:
	Point(int ix, int iy) :x(ix), y(iy) {};
	void output() const {
		cout << "x=" << x << " : " << "y=" << y << endl;
	}
	static void outcnt() {	//static �Լ�
		//cout << x << endl;
		//cout << y << endl;
		//-> static �Լ��� static ������ ����� ����.
		cout << "������ ��ǥ�� ��: " << cnt << endl;
		cnt++;
	}
	void get();	//Ŭ���� ����Լ��� ���� �� ���
};
int Point::cnt = 1;	//static ������ �ʱ�ȭ
void Point::get() {
	output();
	outcnt();
}
int main() {
	Point p1(10,20);
	p1.get();
	Point p2(30, 40);
	p2.get();
	return 0;
}


 ����2.Ŭ������ �̿��Ͽ� ����
 - ���� Ŭ����
 - ������� : �̸�/������̵�/�ܾ�/����
 - ����Լ� : ������/get�Լ�/�Ҹ���
 - ��ü : 3�� ���� - �迭�� �ƴ� Ŭ���� ��ü�� �����

#include<iostream>
using namespace std;
class Bank {
	char* name;
	char* id;
	int *balance;
	static double f;
public:
	Bank() {
		name = new char[10];
		id = new char[10];
		balance = new int;
	}
	~Bank() {
		delete[] name;
		delete[] id;
		delete balance;
	}
	void get() {
		cout << "�̸��Է�: "; cin >> name;
		cout << "���̵��Է�: "; cin >> id;
		cout << "�ܾ��Է�: "; cin >> *balance;
		cout << endl;

		cout << "�̸�: " << name << endl;
		cout << "���̵�: " << id << endl;
		cout << "�ܾ�: " << *balance << " ����" << endl;
		cout << "����: " << f << "%" << endl;
		cout << endl;
	}
};
double Bank::f = 0.9;
int main() {
	Bank user1;
	Bank user2;
	Bank user3;
	user1.get();
	user2.get();
	user3.get();

	return 0;

}
static ��������� �������� ���� �ؾ� �ϴ� ������ ����ϸ� ���ϴ�.

���
- ������ �Ʒ��� � �����̳� ������ ���� �ִ� ����
- ������ Ŭ�������� ����ϴ� ����̴� Ư���� �ٸ� Ŭ�������� �����༭ ���ο�
  Ŭ������ ����� ����ϴ� ���̴�.
- ����� ������ ���ٸ� ������ Ŭ������ ���ο� ����Լ��� ��������� �ʿ��� ���
  ���Ӱ� �ٽ� Ŭ������ �����ؾ� �Ѵ�.
- ������, �̹� ���� Ŭ������ �ִٸ� �� Ŭ������ ��ӹ޾Ƽ� ���� Ŭ������ �����
  ������ �ڵ�� �״�� ����ϸ鼭 ���ο� ���븸 �߰��ϸ� �ȴ�.
- �ڵ��� ��Ȱ�� �����̳� ���߱Ⱓ �����̶�� ū ȿ���� ���� �� �ִ�.
- ����� ����ϴ� ������ ��ü���⿡�� �߿�� �ϴ� �� �߿� �ϳ��� �䱸���׿� ����
  ���α׷��� �������� �ִ�.
- ��, ȸ������� ���³� ������ Ư�� ���� �ٲ� ���α׷� ����� ����䱸�� ���缭
  �ʿ��� ����� �߰� �� �� �ִ�.
- ��ӿ��� ���� �ؾ��� ���� ��������� ū ������� ������ų ������,
  ū ����� ���� ������� ���� ������ �����ؾ��Ѵ�.

class Score {
protected:
	��,��,��
public:
	tot() {
		��+��+��
	}
	avg() {
		�� + �� + �� / 3.0;
	}
};
class Score1 : Score {

};

��ӹ޴� ���
- class �ڽ�Ŭ�����̸� : ���������� �θ�Ŭ�����̸� {
	// �ڽ�Ŭ��������
};

��ӹ��� Ŭ���� ��� ���
- ������� �ڽ� Ŭ������ �ڽ�Ŭ������ �θ� Ŭ������ �ϳ��� �����Ѵ�.
- �ڽ� Ŭ������ ��ü ���� �� ����ϸ� ����� ����� �� �ִ�.
- �θ� Ŭ������ ����ϴ� �ͺ��� �ڽ� Ŭ������ ����Ѵ�.