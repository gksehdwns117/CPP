����1. Ŭ������ �̿��Ͽ� ����
- �̸�/����/�ּ� �Է�
- �̸�/����/�ּ� ���
- ������ �� �ִ� ����� ���� 5��


#include<iostream>
using namespace std;

class Person {
private:
	char name[10];
	int age;
	char address[30];
public:
	void set() {
		cout << "�̸��Է�: "; cin >> name;
		cout << "�����Է�: "; cin >> age;
		getchar();
		cout << "�ּ��Է�: "; cin.get(address, 30);
		cout << "-------------------------------" << endl;
	}
	void get() {
		cout << "�̸�:" << name << endl;
		cout << "����:" << age << endl;
		cout << "�ּ�:" << address << endl;
		cout << endl;
	}
};
int main() {
	class Person p[5];
	int i = 0;

	for (i = 0; i < 5; i++) {
		p[i].set();
		system("pause");
		system("cls");
	}
	
	for (i = 0; i < 5; i++) {
		p[i].get();
	}
	return 0;
}


��������� �����ϴ� ����
1. �Ϲݺ��� ����
class Test {
public:
	int a;
};
int main() {
	Test tt;	//Ŭ���� ���� ����
	tt.a = 10;	//�� �ʱ�ȭ1
	tt.a(10)	//�� �ʱ�ȭ2
}
2. �����ͺ��� ����
class Test {
public:
	int a;

};
int main() {
	Test tt;		//Ŭ���� ��������
	Test* pt = &tt;	//Ŭ���� ������ �����ͺ���
	pt->a = 10;		//�� �ʱ�ȭ
}
3. �����Ҵ� ����
class Test {
public:
	int a;

};
int main() {
	Test* tt = new Test;		//Ŭ���� ������ �����ͺ����� ����
	tt->a = 10;					//�� �ʱ�ȭ
	delete(tt);					//�����Ҵ�� �� ����
}

����2.
1.Ŭ������ �̿��ؼ� ����
2.private �� �̿��ؼ� ����
- Ŭ���� ������� : int start, end;
- start ���� ����/ end �� ����
- start(�����ϴ� ��) / end(������ ��)
- ������ ���

#include<iostream>
using namespace std;

class Table {
private:
	int start;
	int end;
	int i,k;
public:
	void set() {
		cout << "�����ϴ� �� �Է�:"; cin >> start;
		cout << "������ �� �Է�:"; cin >> end;
	}
	void get() {
		for (i = 1; i <= 9; i++) {
			for (k = start; k <= end; k++) {
				cout << k << "*" << i << "=" << i * k << "\t";
			}
			cout << endl;
		}
	}
};
int main() {
	class Table multi;
	cout << "##### ������ ���� ######" << endl;
	multi.set();
	system("cls");
	multi.get();
	return 0;
}


this
- ����Լ��� ȣ���� ��ü�� �ּҸ� �����ϴ� ����Լ��� ��� ��ü�� �����Ѵ�.
- ��, ����Լ��� ��ü���� ���� ������� �ʰ� ��� ��ü�� �����Ѵ�.
- ����Լ��� ȣ��ÿ� � ��ü�� ȣ�� �ߴ��� �����ϱ� ���� 0��° �Ű������� �����.
- 0��° �Ű������� �ڵ����� �����Ǿ� �������� ������ �ǹ��Ѵ�.
- �� �Ű������� ���ؼ� �� ��ü�� �ּ�(���� ����� ��ġ)�� ���޹޴´�.
- �׷��� �� �ּҸ� ���ؼ� ��ü�� ��������� ���� ���� �� �� �ִ�.*/

this ����
- Ŭ������ *this
- �Ϲ������� this �����ͺ����� �����ϹǷ� this �����ͺ����� �Ű������� ����ϸ� ������ �߻��Ѵ�.
- ��, ���½�Ű�� �Ű������� �ƴ϶�� �ǹ̵� ������ �ִ�.
- ��쿡 ���󼭴� ���� ���Ѿ� �ϴ� ��쵵 �ִ�.

**��ü ������ ��������� stack������ ������ ��ü�� ����ŭ �����.
**�׷����� ����Լ��� code������ �Ѱ��� �����ǰ� ��� ��ü�� �����ȴ�.

#include<iostream>
using namespace std;

class Test {
public:
	int a;
	void set() {
		cout << this << endl;
		cout << "set" << endl;
	}
	void get() {
		cout << "get" << endl;
	}
};
int main() {
	Test aa;		//aa��� ��ü����
	Test bb;		//bb��� ��ü����
	aa.a = 10;		//aa.a��� ������ ���� ���� ����
	bb.a = 20;		//bb.b��� ������ ���� ���� ����
	aa.set(); aa.get(); //aa�� bb�� �Լ��� �������� ����
	bb.set(); bb.get();
	return 0;
}


#include<iostream>
using namespace std;

class Test {
private:		// private�� �����ص� �ȴ�.
	int a;
	char b;
public:
	void set(int a1,char b1) {
		a = a1;	//this->a=a1;
		b = b1;
	}
	void set() {
		cout << "�����Է�:";
		cin >> a;
		cout << "�����Է�";
		cin >> b;
	}
	void get() {
		cout << a << ":" << b << endl;
	}
};
int main() {
	Test aa;
	Test bb;
	aa.set(10, 'a');
	aa.get();
	aa.set();
	aa.get();
}


����3. this �̿��Ͽ� ����
- ������� : �й�/�̸�
- ����Լ� : �Է�/���
- ��ü 2�� ���� �ؼ� �����
#include<iostream>
using namespace std;
class student {
	int num;
	char name[10];
public:
	void set(int _num,char _name[10]) {
		num = _num;
		strcpy(name, _name);
		cout << this << endl;
		cout << endl;
	}
	void get() {
		cout << "�й�:" << num << endl;
		cout << "�̸�:" << name << endl;
		cout << this << endl;
		cout << endl;
	}
};
int main() {
	student s1;
	student s2;
	int n;
	char str[10];
	cout << "�й��Է�:"; cin >> n;
	cout << "�̸��Է�:"; cin >> str;
	s1.set(n, str);
	s1.get();
	cout << "�й��Է�:"; cin >> n;
	cout << "�̸��Է�:"; cin >> str;
	s2.set(n, str);
	s2.get();
}

������
- ��ü�� �����Ǵ� �������� �ڵ����� ȣ��Ǵ� ����Լ�
- ������ �Լ��� ���Ǵ� ������ ��������� �ʱ�ȭ �ϴµ� �ִ�.
- set()�Լ��� ���� ��������� �ʱ�ȭ�� �����ڰ� ����� �Ŀ� ����Ǵ� �ʱ�ȭ
- �����ڸ� ���� �ʱ�ȭ�� ��ü�� �����ɶ� �ڵ����� �Ҵ�ȴ�.
#include<iostream>
using namespace std;

class Test {
	int a;
public:
	Test() {
		a = 1000;
		//default ������
	}
	Test(int _a) {		//�����ڵ� �����ε��� �����ϴ�.
		a = _a;
	}
	void set(int _a) {
		a = _a;
	}
	void get() {
		cout << a << endl;
	}
};
int main() {
	Test test(10000000);
	//�����ڴ� ó�� ��������� ȣ�� �����ϰ�, ���߿��� set()�Լ��� ȣ���Ͽ� ���� �����ؾ��Ѵ�.
	test.get();
	test.set(10);
	test.get();

}