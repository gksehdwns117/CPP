// ����1.Ŭ���� ��ü �����Ҵ��� �̿��Ͽ� ����
// - �θ�Ŭ���� : �̸� / �ֹι�ȣ / ����
// - �ڽ�Ŭ���� : ��ȭ��ȣ / ȸ����ȣ
// - �Է� �� ��ü ���� �����Ҵ�
// - �Է� / ��� / �˻� / ���� / ���� ���α׷� ����

/*#include<iostream>
using namespace std;
class Personal_info {
protected:
	char name[10];
	char head_number[7];
	char back_number[8];
	int age;
public:
	void set() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�ֹι�ȣ ���ڸ� �Է�(6�ڸ�) : "; cin >> head_number;
		cout << "�ֹι�ȣ ���ڸ� �Է�(7�ڸ�) : "; cin >> back_number;
		cout << "�����Է� : "; cin >> age;
	}
	void get() {
		cout << "�̸� : " << name << endl;;
		cout << "�ֹι�ȣ : " << head_number << "-" << back_number  << endl;
		cout << "���� : " << age << endl;
	}
};
class Official_info : public Personal_info {
	char p_number[20];
	int guest_number;
public:
	void set() {
		Personal_info::set();
		cout << "��ȭ��ȣ �Է�(-�Է�): "; cin >> p_number;
		cout << "ȸ����ȣ �Է�(8�ڸ�) : "; cin >> guest_number;
	}
	void get() {
		Personal_info::get();
		cout << "��ȭ��ȣ : " << p_number << endl;
		cout << "ȸ����ȣ : " << guest_number << endl;
	}
	int search(const int& s1) {
		if (s1 == guest_number) return 1;
		else return 0;
	}
	int del(const int& s2) {
		if (s2 == guest_number) return 1;
		else return 0;
	}
};

int main() {
	int list;
	cout << "�� ���� ������ �Է��Ͻʴϱ�? "; cin >> list;
	Official_info* p = new Official_info[list];
	int cho, i, res1 = 0, res2 = 0;
	int cnt = 0;
	int search_num, del_num;
	while (1) {
		cout << "1.�Է� 2.��� 3.�˻� 4.���� 5.����" << endl;
		cout << "---------------------------" << endl;
		cout << "�޴�����: "; cin >> cho;
		cout << endl;
		if (cho == 1) {
			p[cnt].set();
			cnt++;
		}
		else if (cho == 2) {
			for (i = 0; i < cnt; i++) {
				p[i].get();
				cout << "---------------------------" << endl;
			}
		}
		else if (cho == 3) {
			cout << "�˻� �� ȸ����ȣ �Է�(8�ڸ�) : "; cin >> search_num;
			for (i = 0; i < cnt; i++) {
				res1 = p[i].search(search_num);
				if (res1 == 1) {
					cout << "---------------------------" << endl;
					p[i].get();
					res1 = 0;
				}
				else if (res1 == 0) {
					cout << "ã���ô� ȸ���� ������ �����ϴ�." << endl;
					cout << "---------------------------" << endl;
				}
			}
		}
		else if (cho == 4) {
			cout << "���� �� ȸ����ȣ �Է�(8�ڸ�) : ", cin >> del_num;
			for (i = 0; i < cnt; i++) {
				res2 = p[i].del(del_num);
				if (res2 == 1) {
					cnt--;
					for (int j = i; j < cnt; j++) {
						p[j] = p[j + 1];
					}
					res2 = 0;
				}
				else if (res2 == 0) {
					cout << "ã���ô� ȸ���� ������ �����ϴ�." << endl;
					cout << "---------------------------" << endl;
				}
			}
		}
		else if (cho == 5) {
			cout << "���α׷��� ����˴ϴ�." << endl;
			break;
		}
	}
	delete[] p;
}

���� ���
- ���ݱ��� �ߴ� ����� ���� ����̴�.
- ���߻���� �� �̻��� �θ�Ŭ������ ���� �ڽ� Ŭ������ �ǹ��Ѵ�.
- ���� Ŭ������ ���ÿ� ��ӹ��� �� �ֱ� ������ ���α׷��� ���뼺�� ����.

#include<iostream>
using namespace std;
class A {	//�θ�Ŭ����
public:
	void func1() {
		cout << "A::func1()" << endl;
	}
};
class B{	//�θ�Ŭ����
public:
	void func2() {
		cout << "B::func2()" << endl;
	}
};
class C : public A, B {
public:
	void func3() {
		func1();
		func2();
		cout << "C::func3()" << endl;
	}
};
int main() {
	C c;
	c.func3;
}
*/

// ����2.���� ����� �̿��Ͽ� ����
// - Ŭ����1 : �̸� / �г� / ��
// - Ŭ����2 : ���� / ���� / ����
// - Ŭ����3 : �ֹι�ȣ / �ּ�
// ���� Ŭ������ �̿��Ͽ�
// - �̸� / �г� / �� / ���� / ���� / ������ �Է� �� �� �ִ� Ŭ����
// - �̸� / �г� / �� / �ֹι�ȣ / �ּҸ� �Է� �� �� �ִ� Ŭ����
// - Ŭ���� 1,2,3�� ��� �̿� �� �� �ִ� Ŭ������ ����

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	int *sch_year;
	int *ban;
public:
	Info1() {
		name = new char[10];
		sch_year = new int;
		ban = new int;
	}
	~Info1() {
		delete[]name;
		delete sch_year;
		delete ban;
	}
	void set1() {
		cout << "�̸��Է� : "; cin >> name;
		cout << "�г��Է� : "; cin >> *sch_year;
		cout << "��  �Է� : "; cin >> *ban;
	}
	void get1() {
		cout << "�̸� : " << name << endl;
		cout << "�г� : " << *sch_year << "�г�" << endl;
		cout << "��  : " << *ban << "��" << endl;
	}
};
class Info2{
protected:
	int *kor;
	int *eng;
	int *math;
public:
	Info2() {
		kor = new int;
		eng = new int;
		math = new int;
	}
	~Info2() {
		delete kor;
		delete eng;
		delete math;
	}
	void set2() {
		cout << "����� : "; cin >> *kor;
		cout << "����� : "; cin >> *eng;
		cout << "���м��� : "; cin >> *math;
	}
	void get2() {
		cout << "���� : " << *kor << "��" << endl;
		cout << "���� : " << *eng << "��" << endl;
		cout << "���� : " << *math << "��" << endl;
	}
};
class Info3{
protected:
	char* personal_num;
	char* address;
public:
	Info3() {
		personal_num = new char[20];
		address = new char[20];
	}
	~Info3() {
		delete[] personal_num;
		delete[] address;
	}
	void set3() {
		cout << "�ֹι�ȣ�Է�('-'����) : "; cin >> personal_num;
		getchar();
		cout << "�ּ��Է� : "; cin.get(address, 20);
		
	}
	void get3() {
		cout << "�ֹι�ȣ : " << personal_num << endl;
		cout << "�ּ� : " << address;
	}
};
class A : public Info1, Info2 {
public:
	void set() {
		set1();
		set2();
	}
	void get() {
		get1();
		get2();
	}
};
class B : public Info1, Info3 {
public:
	void set() {
		set1();
		set3();
	}
	void get() {
		get1();
		get3();
	}
};
class C : public Info1, Info2, Info3 {
public:
	void set() {
		set1();
		set2();
		set3();
	}
	void get() {
		get1();
		get2();
		get3();
	}
};
int main() {
	int cho;
	cout << "1.�̸�,���� ��/��� 2.�̸�,�ּ� ��/��� 3.�̸�,����,�ּ� ��/��� 4.���α׷� ����" << endl;
	cout << "���� : "; cin >> cho;
	A a;
	B b;
	C c;
	while (1) {
		if (cho == 1) {
			a.set();
			a.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 2) {
			b.set();
			b.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 3) {
			c.set();
			c.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 4) {
			cout << "���α׷��� ����˴ϴ�." << endl;
			break;
		}
		else {
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
	}
}


