����1. ��ũ�θ� �̿��� ����
- ���� �ָ� 2�� ���� ����
- ���� �ָ� ��*���� ����
- ���� �ָ� ��+100�� ����
#include<iostream>
#define mec1(x) 2*x
#define mec2(x) x*x
#define mec3(x) x+100
using namespace std;
int main() {
	int x;
	cout << "��ũ�� ���� �Է�:";
	cin >> x;

	cout << "2�� �� ����:" << mec1(x) << endl;
	cout << "��*��  ����:" << mec2(x) << endl;
	cout << "��+100 ����:" << mec3(x) << endl;
}
��ũ�δ� �ڷ����� ������ ���� �ʴ´�.


inline �Լ�
- ���α׷� ���� �ӵ��� ���̱� ���ؼ� �߰��� ���
- c������ ��ũ�ο� �񱳵Ǵ� �Լ���.

#include<iostream>
using namespace std;
void func() {

}
inline void func1() {

}


�Ϲ��Լ��� inline �Լ� ������
- ȣ������ �ٸ���.
- ���α׷��� ���� �ӵ��� ������.

��ũ�ο� inline �Լ� ������
- ��ũ�δ� �ڷ����� ������ ����.
- inline �Լ��� �⺻������ �Լ��� �����̱� ������ �ڷ����� �����Ѵ�.
- ��ũ�δ� �ܼ��� ������ ���Ǹ� �����ϴ�.
- inline �Լ��� �Լ��� �����̱� ������ ������ ������ ���ǵ� �����ϴ�.

#include<iostream>
using namespace std;
int add(int n) {
	return n + n;
}
inline int add1(int n) {
	return n + n;
}
int main() {
	cout << add(10) << endl;
	cout << add1(10) << endl;	//cout << 10+10 << endl;
}

#include<iostream>
using namespace std;
#define SPA(s) s*s
inline int SPA1(int s) {
	return s * s;
}
inline int SPA1(double s) {
	return s + 100;
}
inline int SPA1(char s) {
	return s + 1;
}

int main() {
	cout << SPA(10) << endl;
	cout << SPA('A') << endl;
	cout << SPA(1.1) << endl;
	//��ũ�δ� �ڷ��������� ���� �ʱ� ������ ��� ������ �����ϴ�.
	cout << SPA1(10) << endl;
	cout << SPA1('A') << endl;
	cout << SPA1(1.1) << endl;

}


inline �Լ� �������
- ���α׷��Ӱ� inline �Լ��� �����ص� �����Ϸ��� �ź� �� �� �ִ�.
- ���α׷��Ӱ� inline �Լ��� �������� �ʾƵ� �ʿ信 ���� �����Ϸ��� inline ȭ ��ų �� �ִ�.
- �Լ��� �ҽ� ũ�Ⱑ ũ�ų� ��� ȣ���̸� inline �䱸�� �����Ϸ��� �ź� �� �� �ִ�.
- �Լ��� �ҽ� ũ�Ⱑ ũ�� ���� ������ �׸�ŭ Ŀ�� �� �ִٴ� ������ �ִ�.
- �Լ��� �ڵ��� ���� �ð��� ª�� ����ϰ� ȣ��Ǵ� �Լ��� �ƴϸ� �������� �ð��� ������� �ʴ´�.

inline �Լ��� Ư¡
- �����غ��� �Ϲ��Լ��� ũ�� �ٸ��� �ʴ�.
- ��, �Ϲ��Լ��� inline �̶�� �̸��� �߰� �ϸ� �ȴ�.
- ������ inline �Լ��� ȣ������ �ʰ� �Լ��� �ڵ带 �� �ڸ��� �����Ѵ�.
- ��, ������ �� �� inline �Լ��� ȣ�� �ϴ� �Լ��� �ڵ� �ȿ� ���Եȴ�.
- ȣ�� ������ ���� ������ ���� �ӵ��� �������� �ȴ�.
- �Լ��� �ڵ尡 ���� �Ǳ� ������ ���� ������ Ŀ���ٴ� ������ ������.

����2. inline �Լ��� �̿��Ͽ� ����
- �������� �Է� �Ǹ� �������� ���ϱ� 100 �� ���� ����
- �Ǽ����� �Է� �Ǹ� �Ǽ����� ���ϱ� 100 �� ���� ����
- �������� �Է� �Ǹ� ���ڰ��� ��<>�� ������ ���� ����
- �������� �Ǽ����� �Է� �Ǹ� ���� ���� ����
- �Ǽ����� �������� �Է� �Ǹ� ���� ���� ����
- �������� �������� �Է� �Ǹ� ���� ���� ����
- �������� �������� �Է� �Ǹ� ��   ���� ����

#include<iostream>
using namespace std;
inline int test(int n) {
	return n * 100;
}
inline double test(double n) {
	return n + 100;
}
inline char test(char n) {
	if (n > 64 && n < 97) {
		return n + 32;
	}
	else if (n > 97 && n < 130) {
		return n - 32;
	}
}
inline double test(int n1,double n2) {
	return n1 * n2;
}
inline double test(double n1, int n2) {
	return n1 + n2;
}
inline int test(int n1, char n2) {
	return n1 + n2;
}
inline int test(char n1, int n2) {
	return n1 - n2;
}

int main() {
	cout << test(3) << endl;
	cout << test(3.2) << endl;
	cout << test('h') << endl;
	cout << test(3, 3.2) << endl;
	cout << test(3.2, 3) << endl;
	cout << test(3,'h') << endl;
	cout << test('h',3) << endl;
}


bool �ڷ���
- 1byte �ڷ���
- true, false �� �����ϴ� �ڷ���

#include<iostream>
using namespace std;
int main() {
	bool bl = true;
	if (bl) {
		cout << "true" << endl;
	}
	bl = false;
	if (bl == false) {
		cout << "false" << endl;
	}
}


����3. bool �ڷ����� �̿��Ͽ� ����
- ���ڿ� �ΰ��� �Է�
- �����ϸ� �����ϴٰ� ���
- ���� ���� ������ �������� �ʴٰ� ���
- true �� false ���� bool �ڷ����� ����

#include<iostream>
// <string.h>
using namespace std;

int main() {
	char s1[30];
	char s2[30];
	bool bo;

	cout << "���ڿ�1 �Է�:";
	cin.get(s1, 30);
	getchar();
	cout << "���ڿ�2 �Է�:";
	cin.get(s2, 30);

	bo = strcmp(s1, s2);

	if (bo == 0) {
		cout << "�� ���ڿ��� �����մϴ�." << endl;
	}
	else {
		cout << "�� ���ڿ��� �������� �ʽ��ϴ�." << endl;
	}
}


c��� �ʱ�ȭ
/*1. ���� �� �ʱ�ȭ
int a;
a = 10;
2. ����� ���ÿ� �ʱ�ȭ
int a = 10;*/

c++ ��� �ʱ�ȭ-����� ���ÿ� �ʱ�ȭ�� ����
int a(10);
int b(20);

#include<iostream>
using namespace std;
int main() {
	int a = 10;
	int b(20);
	Ŭ������ �ʱ�ȭ(��ü �ʱ�ȭ)
	cout << a << ":" << b << endl;
	b(30);  b�� �Լ��� �ƴϱ� ������ ���� �� �ʱ�ȭ�� �Ұ���(�Լ� ȣ�� ��İ� �����ϹǷ�)
	b = 30;
	cout << a << ":" << b << endl;
}

- �� ����� Ŭ�������� �����ڸ� �ʱ�ȭ �� �� ����ϴ� ���
- �׳ɵ� ����ϱ�� ������ �� ����ϴ� ����� �ƴϴ�.
- ��, �̷� ����� ����� ���������� �ʴ´�.

���۷��� ����
- ������ ��ſ� ����Ѵ�.
- ���۷����� ������ �ǹ�: ��������
- ������ �ִ� ������ �ٸ� �̸��� �ο� �� �� �ִ�.
- ���� ��ġ�� �����ϴ� ������ �̸��� ��������.
- ���� �ٸ� �̸����� �ϳ��� ����(����)�� ������ �����ϴ�.
- ��, �����ϳ��� �������� �̸��� �ο��ϴ� ���̴�.

#include<iostream>
using namespace std;

int main() {
	int a = 10;
	cout << a << endl;
	int& r1 = a;
	int r2 = a;
	cout << r1 << endl;
	cout << r2 << endl;
	cout << &a << endl;
	cout << &r1 << endl;
	cout << &r2 << endl;
	r1 = 20;
	cout << a << endl;
}

