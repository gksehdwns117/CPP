����1.
�̸�,����,����,���� ������ �Է�
����,����� ���
�̸�,����,��� ���
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	char name[30];
	int kor, eng, math;
	int sum = 0;
	double avr;
	cout << "�̸�:";
	cin >> name;
	cout << "���� ����:";
	cin >> kor;	
	cout << "���� ����:";
	cin >> eng;
	cout << "���� ����:";
	cin >> math;

	sum = kor + eng + math;
	avr = (double)sum / 3;
	cout << "==========================================\n";
	cout << "�̸�:" << name << "\n����:" << sum << "\n���:" << setprecision(4) << avr << endl;
}


�Լ��� �����ε�
- c��� ���� ��� ���� �̸��� �Լ��� ��� �� ���� ����.
- c++������ �Լ��� �����ε��̶�� �ؼ� ���� �̸��� �Լ��� ��� �� �� �ִ�.
- ��, ȣ�� �Ҷ��� ��� �� �Ű������� ���̷� ���� �� �� �ִ�.
- �Ű������� ���� �� �ڷ����� �ٸ��� ����� �����ϴ�.
#include<iostream>
using namespace std;
void output() {
	cout << "output() ����" << endl;
}
void output(int a) {
	cout << "output(int a) ����" << endl;
}
void output(int a, int b) {
	cout << "output(int a,int b) ����" << endl;
}
void output(char a) {
	cout << "output(char a) ����" << endl;
}
void output(char a,char b) {
	cout << "output(char a,char b) ����" << endl;
}
void output(int a, char b) {
	cout << "output(int a,char b) ����" << endl;
}
void output(char a, int b) {
	cout << "output(char a,int b) ����" << endl;
}
int main() {
	output();
	output(10);
	output(20, 30);
	output('a');
	output('a', 'b');
	output(10, 'b');
	output('a', 20);
}


����2. �Լ��� �����ε� ���
1. 1~10������ ���� ���
2. 1~n ������ ���� ���
3. n~m ������ ���� ���
#include<iostream>
using namespace std;
void sum() {
	int i;
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	cout << "1~10������ �� :" << sum << endl;
}
void sum(int n) {
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	cout << "1~"<< n << "������ �� :" << sum << endl;
}
void sum(int m,int n) {
	int i;
	int sum = 0;
	for (i = m; i <= n; i++) {
		sum += i;
	}
	cout << m << "~" << n << "������ �� :" << sum << endl;
}
int main() {
	int a, b;
	cout << "���۰� �Է�:";
	cin >> a;
	cout << "���� �Է�:";
	cin >> b;

	sum();
	sum(b);
	sum(a, b);
	return 0;
}


����Ʈ �Ű�����
- �Ű������� �⺻���� ���� �� �� �ִ�.
- �Ű��������� ���� �������� ������ �⺻���� ����Ѵ�.
- ����Ʈ �Ű������� ����ϸ� �Ű����� ���� �Լ��� �����ε��� �Ұ����ϴ�.
#include<iostream>
using namespace std;
void func(int a=1000) {
	cout << a << endl;
}
void func() {
	cout << "func()" << endl;
}
void func(int a = 1000, int b = 2000) {
	cout << a << ":" << b << endl;
}
int main() {
	//func(10);		// ->�Ű������� 10�� �����ؼ� ���
	//func();		// ->�Ű������� �⺻���� ���
	func(100, 200); // ->�⺻���� �ΰ��� ��
	func(200);		// ->�ڿ����� �����̰���.
	func();			// ->��� ����.
}


����3. ����Ʈ �Ű������� �̿��Ͽ� ����
1. �ϴ� �⺻��: 10����
2. �Ѵ� ���� �ϼ�: 20��
3. �ϴ�/�ϼ� �Է� - ����
4. �ϴ縸 �Է�-����
5. �ϼ��� �Է�-����
6. �ϴ�/�ϼ� �Է�X
#include<iostream>
using namespace std;
int salary(int sal_d = 10, int day = 20) {
	return sal_d * day;
}
int main() {
	int sal_d = 0, sal_m = 0, day = 0;
	int cho = 0;
	while(1){
		cout << "1.�ϴ�/�ϼ� �Է� 2.�ϴ縸 �Է� 3.�ϼ��� �Է� 4.�⺻��\n(�ϼ�-20�ϱ���,�ϴ�-10���� ����)\n";
		cout << ">>>"; cin >> cho;
		switch (cho) {
		case 1:
			cout << "�Ϸ� �ϴ��Է�:"; cin >> sal_d;
			cout << "�Ѵ� �ϼ��Է�:"; cin >> day;
			sal_m = salary(sal_d, day);
			cout << "�Ѵ� ����:" << sal_m << "����" << endl;
			break;
		case 2:
			cout << "�Ϸ� �ϴ��Է�:"; cin >> sal_d;
			sal_m = salary(sal_d);
			cout << "�Ѵ� ����:" << sal_m << "����" << endl;
			break;
		case 3:
			cout << "�Ѵ� �ϼ��Է�:"; cin >> day;
			sal_m = salary(10, day);
			cout << "�Ѵ� ����:" << sal_m << "����" << endl;
			break;

		case 4:
			sal_m = salary();
			cout << "�Ѵ� ����:" << sal_m << "����" << endl;
			break;
		}
	}
}


����4. �Լ��� �����ε� ���
- �̸��� �Է� �޾Ƽ� ���� �Լ�
- ���̸� �Է� �޾Ƽ� ���� �Լ�
- Ű��   �Է� �޾Ƽ� ���� �Լ�
#include<iostream>
using namespace std;

void input(int *su) {
	cout << "���� �Է�:"; cin >> *su;
}
void input(double *su) {
	cout << "Ű  �Է�:";  cin >> *su;
}
void input(char *su) {
	cout << "�̸� �Է�:"; cin >> *su;
}
void output(int a, double b, char *c) {
	cout << "�̸�:" << *c << "\n����:" << a << "\nŰ:" << b << "cm\n";
}
int main() {
	int age = 0;
	double cm = 0.0;
	char name[10];

	input(&age);
	input(&cm);
	input(name);
	output(age, cm, name);
	return 0;
}


//��ũ��
//- ���� ����ϴ� ���� �Ǵ� ���� ���� ��ų �� ����Ѵ�.
//- �ڷ����� ������ ����.
//- ������ �������� ���� �� �� ����.
#include<iostream>
#define MAX 100
#define MIN 0
#define spa(x) x*x
using namespace std;
int main() {
	cout << MAX << endl;
	cout << MIN << endl;
	cout << spa(3);
	cout << endl;
	cout << spa(1.1); cout << endl;
	cout << spa('A'); cout << endl;
}