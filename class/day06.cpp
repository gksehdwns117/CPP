����1. inline �� define �� �̿��Ͽ� ����.
 inline
- ������ �Է��ϸ� �� ������ 3���� �� ��ȯ o
- �Ǽ��� �Է��ϸ� �� �Ǽ��� *2�� �� ��ȯ
- ���ڸ� �Է��ϸ� �� ������ �빮�� <> �ҹ��� ��ȯ�� �� ��ȯ
 define
- ���� �Է��ϸ� �� ���� +100�� ��ȯ
- �Է��� �� �ִ� �ִ� ���� 100�� MAX�� ����
- �Է��� �� �ִ� �ּ� ���� 0  �� MIN���� ����

�Լ� 
- ������ 0~100 ���� �� �ϳ��� ���� �Է� ����

#include<iostream>
#define MAX 100
#define MIN 0
#define SPA(x) x+100
using namespace std;
int input() {
	int n;
	cout << "0 ~ 100 ���� �� ������ �Է�:";
	cin >> n;
	if (n<MIN || n>MAX) {
		cout << "�Է��� ������ ��ȯ���� �ʽ��ϴ�." << endl;
	}
	else {
		return n;
	}
}
inline int test(int a) {
	return a * a * a;
}
inline double test(double a) {
	return a * 2;
}
inline char test(char n) {
	if (n > 64 && n < 97) {
		return n + 32;
	}
	else if (n > 97 && n < 130) {
		return n - 32;
	}
}
int main() {
	int res1 = 0;
	res1 = input();
	cout << SPA(res1) << endl;

	cout << test(res1) << endl;
	cout << test(1.3) << endl;
	cout << test('b') << endl;

	return 0;
}


 ���۷��� ����
:������ �� �ٸ� �̸��� �ο��ϴ� ���۷��� ������ �̿�.
- ���۷��� ������ ������ ������ ��� �߿��� �Ű������� ���Ǿ� ȣ��� �Լ����� ȣ���� �Լ��� ��������
  �ٲٴ� ����� ����ϰ� �ȴ�.
- ���� ������ ������ �ּҰ��� �����ϰ� �ȴ�.
- �����͸� ��ü �� �� �־ c++������ �����ͺ��� ���� ����Ѵ�.
- �迭���� ��� �� �� ����.
- ���۷����� �Ϲ� ���� ���¸� �����ϴ�.

 ���۷��� ������ Ư¡
- ���۷��� ������ ����� '&' �����ڸ� ����Ѵ�.
- ����� ���ÿ� �ʱ�ȭ �Ǿ�� �Ѵ�.
- ����� ���۷��� ������ �ʱ�ȭ �� �� ����. -> �ٸ� ������ �ּҰ��� �����Ͽ� �ʱ�ȭ
- �Լ��� �Ű������� �ַ� ���ȴ�.

#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int& r = a;
	//r = a;  ������ �������� ���ϸ� ���� �� �� ���� ������ ���� �� �ʱ�ȭ �Ұ���.
	int* p = &a;
	// �����ͺ����� �����ȿ� ������ �ּҰ��� �����ϰ� �� �ּҰ��� �����ϵ��� �Ǿ��ִ�.
	cout << "a�� ��ġ �ּҰ�:" << &a << endl;
	cout << "r�� ��ġ �ּҰ�:" << &r << endl;
	cout << "������ p�� ��ġ �ּҰ�:" << &p << endl;
	cout << "������ p�� ���� ��ġ��:" << p << endl;

	cout << "a�� ���� ��	:" << a << endl;
	cout << "r�� ���� ��	:" << r << endl;
	cout << "p�� �����ϴ� ��	:" << *p << endl;

	a = 20;
	cout << "a�� ���� ��	:" << a << endl;
	cout << "r�� ���� ��	:" << r << endl;
	cout << "p�� �����ϴ� ��	:" << *p << endl;

	r = 30;
	cout << "a�� ���� ��	:" << a << endl;
	cout << "r�� ���� ��	:" << r << endl;
	cout << "p�� �����ϴ� ��	:" << *p << endl;

	*p = 50;
	cout << "a�� ���� ��	:" << a << endl;
	cout << "r�� ���� ��	:" << r << endl;
	cout << "p�� �����ϴ� ��	:" << *p << endl;
	return 0;
}


���۷��� �Ű������� ���� �ڷ����� �Ϲ� �Ű������� ������ �Լ��� �����ε��� �Ұ����ϴ�.
#include<iostream>
using namespace std;
int ex1() {
	int a = 100;
	return a;
}
void ex1(int& r) {
	r = 200;
}
void ex1(int* p) {
	*p = 300;
}
int main() {
	int a;
	a = ex1();
	cout << a << endl;
	ex1(a);
	cout << a << endl;
	ex1(&a);
	cout << a << endl;
}


����2.���۷��� ������ �����ͺ����� ���
- ������ 3���� �Է� �ޱ�
- �ִ밪�� �ּڰ��� ���
- ���۷��� ������ �̿��ϱ� ���ؼ��� �Ϲ� ������ ����
- �����ͺ����� �̿��ϱ� ���ؼ��� �迭�� ���

#include<iostream>
using namespace std;
void compare(int a1, int a2, int a3,int &max,int &min) {
	max = a1; min = a1;
	if (a2 > max) {
		max = a2;
	}
	if (a3 > max) {
		max = a3;
	}

	if(a2<min){
		min = a2;
	}
	if (a3 < min) {
		min = a3;
	}

	
}
void compare(int *p,int *max,int *min) {
	int i;
	*max = 0;
	*min = 100;
	for (i = 0; i < 3; i++) {
		if (p[i] > * max) {
			*max = p[i];
		}
		if (p[i] < *min) {
			*min = p[i];
		}
	}
}

int main() {
	int n1, n2, n3;
	int res1 = 0, res2 = 0;
	int arr[3];
	int i, cho = 0;
	while (1) {
		cout << "ù��° ���� �Է�:"; cin >> n1;
		cout << "�ι�° ���� �Է�:"; cin >> n2;
		cout << "����° ���� �Է�:"; cin >> n3;
		cout << "1.���۷��� ���� �̿� 2.�����ͺ��� �̿�\n>>>"; cin >> cho;
		switch (cho) {
		case 1:
			compare(n1, n2, n3, res1, res2);
			cout << "�ִ�:" << res1 << endl;
			cout << "�ּڰ�:" << res2 << endl;
			break;
		case 2:
			arr[0] = n1; arr[1] = n2; arr[2] = n3;
			compare(arr, &res1, &res2);
			cout << "�ִ�:" << res1 << endl;
			cout << "�ּڰ�:" << res2 << endl;
			break;
		}
}

	return 0;
}


//C��� �迭 �޸� ����
//1.�ڵ念��
/*
- ������ �� ���α׷� �ҽ��� ����� ��ȯ�Ǿ� ����Ǵ� ����
- ������ �ϸ� �Լ����� ����� ��ȯ�ȴ�.
*/

//2.data�� ����
/*
- ���������� static ������ ����Ǵ� ����
- ���α׷��� ���۵� �� �����ǰ�, ���α׷��� ����Ǹ� �Ҹ�ȴ�.
- ���α׷��Ӱ� ���� �� �Ҹ� �ñ⸦ ���� �� �� ����.
*/

//3.heap�� ����
/*
- �����Ҵ� �� ������ ����Ǵ� ����
- �̸��� �ִ� ������ ���� �� �� ����.
- �ּҰ����� ���� ������ �����ϴ�.
- ������ ������ �̿��ؼ� ȣ�� �� �� �ִ� ����
- ���α׷��Ӱ� ���� �� �Ҹ�ñ⸦ ���� �� �� �ִ� ����
- �� �� �����Ҵ��� ������ �Ҹ��� ��Ű�� ������ ��� �����ȴ�.
*/

//4.stac�� ����
/*
- ��������,�Ű�����,�����ͺ��� ���� �̸��� �ִ� ������ �����ϴ� ����
- �Լ��� ���۵� �� �����ǰ�, �Լ��� ����Ǹ� �Ҹ�ȴ�.
- ���α׷��Ӱ� ���� �� �Ҹ� �ñ⸦ ���� �� �� ����.
- ���α׷��� �ۼ��� �� �̹� ���� �� �Ҹ� �ñⰡ �����Ǿ� �ִ�.
*/
  

//2.data�� ���� ���� (��������, static����)
/*#include<iostream>
using namespace std;
int a=100;		
//��������:�Լ� ��� �ȿ� ������ �ʰ� �ܺο� ���������.
//		  �ʱ�ȭ���� ������ 0���� �ڵ��ʱ�ȭ �ȴ�.
//        ��� �Լ��������� ��� �� �� �ִ� ����
void func() {
	cout << a << endl;
	//�Լ����� ���������� ������(�����߻�),������ ���� ������ ���������� ó���ϱ� �����̴�.
	a += 100;
	//���������� ���� ����Ǹ� ��� ���� �ϰ� �ȴ�.
}
void func1() {
	static int a = 0;
	//static ����
	//�Լ� �������� ����� ����.
	//�ٸ� �Լ������� ����� �Ұ���
	cout << a << endl;
	a++;
}
int main() {
	int a=10;	//��������
	cout << a << endl;
	//�������� ��� - �Լ� ���� ���Ǵ� ���������� �켱������ �ִ�.
	func();
	func();
	func1(); func1(); func1(); func1(); func1();
}
*/

//3.heap�� ���� ���� (�����Ҵ�)
#include<iostream>
using namespace std;

int main() {
	int* su = (int*)malloc(sizeof(int));
	int* su1 = (int*)malloc(sizeof(int) * 4);
	// �����Ҵ����
	*su = 100;
	cout << *su << endl;
	cout << su << endl;
	free(su);
	cout << *su << endl;
	cout << su << endl;
	cout << sizeof(su1) << endl;
	su1[0] = 100;
	su1[1] = 200;
	su1[2] = 300;
}