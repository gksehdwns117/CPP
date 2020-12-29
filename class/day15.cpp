 ����1. Ŭ������ �̿��Ͽ� ����
 - ù��° Ŭ���� : �̸� / �г�
 - �ι�° Ŭ���� : �̸� / �г� / ���� / �ּ�
 - ù��° Ŭ���� : 2�� �Է� �� ��� �Լ�
 - �ι�° Ŭ���� : 2�� �Է� �� ��� �Լ�

#include<iostream>
using namespace std;

class Student1 {
protected:
	char *name;
	int *grade;
public:
	Student1() {
		name = new char[10];
		grade = new int;
	}
	~Student1() {
		delete[]name;
		delete grade;
	}
	void set1() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�г��Է� : "; cin >> *grade;
	}
	void get1() {
		cout << "�̸� : " << name << endl;
		cout << "�г� : " << *grade << "�г�" << endl;
	}
};
class Student2 : public Student1 {
	int *age;
	char *addr;
public:
	Student2(){
		age = new int;
		addr = new char[30];
	}
	~Student2() {
		delete age;
		delete[]addr;
	}
	void set2() {
		cout << "�����Է� : "; cin >> *age;
		getchar();
		cout << "�ּ��Է� : "; cin.get(addr, 30);
	}
	void get2() {
		cout << "���� : " << *age << "��" << endl;
		cout << "�г� : " << addr << endl;
	}
};
int main() {
	Student1 info1;
	Student2 info2;
	info1.set1();
	cout << "------------------" << endl;
	info1.get1();
	cout << "------------------" << endl;
	info2.set1();
	info2.set2();
	cout << "------------------" << endl;
	info2.get1();
	info2.get2();
	cout << "------------------" << endl;
}


��ӿ��� �������� ȣ�� ����
class A {
public:
	A();
};
class B : public A {
public:
	B();
};
int main() {
	B b;
	// ȣ���� BŬ������ ���� ȣ���ϰ�, A�� ȣ���Ѵ�.
	// ������ AŬ������ ���� �����ϰ�, B�� �����Ѵ�.
}
- B Ŭ������ �����ڰ� ȣ��� ���� A Ŭ������ �����ڰ� �ݷ��� �ʱ�ȭ�� ȣ�� �ȴ�.
- A Ŭ������ �����ڰ� ����� ���� �ٽ� BŬ������ �����ڷ� ���ƿͼ� ����ȴ�.

//��ӿ��� �Ҹ����� ȣ�� ����
class A {
public:
	A();
	~A();
};
class B : public A {
public:
	B();
	~B();
};
int main() {
	B b;
	// ~B()�� ����ǰ�, ~A()�� �����.
}
- ��ü�� �Ҹ�ÿ��� �Ҹ��ڰ� �ڽ� Ŭ������ �Ҹ��ڰ� ����� ��, �θ� Ŭ������ �Ҹ��ڰ� ����ȴ�.
- stack �����̶� ���߿� ������� ���� ���� �Ҹ��Ѵ�.


#include<iostream>
using namespace std;

class A {
protected:
	A(){
		cout << "A()�� ������" << endl;
	}
	~A() {
		cout << "A()�� �Ҹ���" << endl;
	}
};
class B : public A {
public:
	B() {
		cout << "B()�� ������" << endl;
	}
	~B() {
		cout << "B()�� �Ҹ���" << endl;
	}
};
int main() {
	B b;
}


����2. ����� �̿��Ͽ� ����
- �θ�Ŭ���� : �̸� / ���� / ���
- �ڽ�Ŭ���� : ���� / ���� / ����
- �ڽ�Ŭ���� ��ü�� ���� �� �̸� / ���� / ����� ���

#include<iostream>
using namespace std;
class Stu_Info {
protected:
	char* name;
	int* sum;
	double *avr;
public:
	Stu_Info() {
		name = new char[10];
		sum = new int;
		avr = new double;
	}
	~Stu_Info() {
		delete[] name;
		delete sum;
		delete avr;
	}
	void set_name() {
		cout << "�̸� : "; cin >> name;
	}
};
class Subject : public Stu_Info {
	int *kor;
	int *eng;
	int *math;
public:
	Subject() {
		kor = new int;
		eng = new int;
		math = new int;
	}
	~Subject() {
		delete kor;
		delete eng;
		delete math;
	}
	void set() {
		//cout << "�̸� : "; cin >> name;
		cout << "���� : "; cin >> *kor;
		cout << "���� : "; cin >> *eng;
		cout << "���� : "; cin >> *math;
	}
	void get() {
		cout << "�̸� : " << name << endl;
		cout << "----------------------------------------" << endl;
		cout << "���� : " << *kor << endl;
		cout << "���� : " << *eng << endl;
		cout << "���� : " << *math << endl;
		*sum = *kor + *eng + *math;
		*avr = (double)*sum / 3;
		cout << "���� : " << *sum << endl;
		cout << "��� : " << *avr << endl;
	}
};
int main() {
	Subject stu;
	stu.set_name();
	cout << "--------------- �����Է� ---------------" << endl;
	stu.set();
	stu.get();
	return 0;
}
����� ������� �Ӹ� �ƴ϶� ����Լ��� ��ӵȴ�.


#include<iostream>
using namespace std;
class Test1 {
protected:
	int a;
	char* n;
public:
	Test1(int ia,char*in) {
		a = ia;
		n = new char[10];
		strcpy(n, in);
	}
	~Test1() {
		delete[]n;
	}
};
class Test2 :public Test1 {
	int b;
public:
	Test2(int ia,char *in,int ib):Test1(ia,in) {
		//�ݷ��� �ʱ�ȭ�� ���ؼ� �θ�Ŭ������ ������ ȣ��
		//���� �θ�Ŭ������ �Ű������� ���� ������ default �����ڰ� ȣ��ȴ�.
		b = ib;
	}
	void get() {
		cout << "a:" << a << endl;
		cout << "n:" << n << endl;
		cout << "b:" << b << endl;
	}
};
int main() {
	Test2 t1(10,"ȫ",20)
}

// �ڽ�Ŭ���� �Լ����� �θ�Ŭ���� �Լ��� ȣ���Ҷ�, (::)�� ����Ͽ� ȣ���Ѵ�.
// ex> Test1::set();  �θ�Ŭ����(Test1)�� �Լ�(set)�� ȣ��


