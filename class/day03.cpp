#include<iostream>
int main() {
	char name[10];
	int age;
	char address[100];
	char blood_type[10];

	std::cout << "�̸��Է�:";
	std::cin >> name;
	
	std::cout << "�����Է�:";
	std::cin >> age;
	
	std::cout << "�ּ��Է�:";
	std::cin >> address;
	
	std::cout << "�������Է�:";
	std::cin >> blood_type;
	
	std::cout << "=====================" << std::endl;
	std::cout << "�̸�	:" << name << std::endl;
	std::cout << "����	:" << age << std::endl;
	std::cout << "�ּ�	:" << address << std::endl;
	std::cout << "������	:" << blood_type << std::endl;

	std::cout << "�����Է�:";
	std::cin >> age;
	getchar();					//getchar()�� ���͸� �ӽ�����
	std::cout << "�ּ��Է�:";	
	std::cin.get(address, 50);	//cin.get(������,���ڿ�����) : �����̽��� �ϳ��� ���ڷ� ���, ���ʹ� ���Ḧ �ǹ�
								//cin     >> ���� �ִ� �Է� ���۸� ������ ����.
								//cin.get >> ���� �ִ� �Է� ���۸� �״�� ����.
	return 0;
}
cin
a>>1
\n(����) b>>2
\n(����) c>>3

cin.get()
a>>1
\n b>>\n
c=>2

namespace
-���α׷��� ȥ�ڼ� �� �� ���� ���, ������ ������ �����Ѵ�.
-�̶�,���� �̸��� �Լ��� �������� ��� �� �� �ֱ� ������ ���߿� ������ �����.
-����,������ ����� �Լ��� ������ ���� �� �� �ֵ��� �Ѵ�.
-namespace�� ������ ������ ������ ����ϴ� �̸� �״�� ����� �����ϴ�.

#include<iostream>
namespace test1 {
void input() {
		std::cout << "test1 ����\n";
		//test2:output();
}
	void output() {
		std::cout << "test1 output()\n";
	}
}
using test1::output;						//using namespace�� :: �Լ��� >> ������ ���� �ڵ�����
											//���ӽ����̽����� ������ �� �ִ�.
namespace test2 {
	void input(){
		std::cout << "test2 ����\n";
		output();							//test1:output()���� ���ӽ����̽����� test1�� ���� �� �� ����.
	}
	void output() {
		std::cout << "test2 output()\n";
	}
}
int main() {
	test1::input();
	test2::input();
}

#include<iostream>
using namespace std;			//����� cout,cin�� namespace
namespace pm{
	int p(int n1,int n2) {
		return n1 + n2;
	}
	int m(int n1, int n2) {
		if (n1 >= n2) {
			return n1 - n2;
		}
		else {
			return n2 - n1;
		}
	}
}
namespace md {
	int m(int n1, int n2) {
		return n1 * n2;
	}
	int d(int n1, int n2) {
		return n1 / n2;
	}
}
using namespace pm;
//using pm::m;
using md::d;
//using md::m;
int main() {
	int a = 10, b = 2;
	int res = 0;
	
	res = p(a, b);
	cout << "�� ������ ��:" << res << std::endl;
	res = pm::m(a, b);
	cout << "�� ������ ��:" << res << std::endl;
	res = md::m(a, b);
	cout << "�� ������ ��:" << res << std::endl;
	res = d(a, b);
	cout << "�� ������ ��:" << res << std::endl;

	return 0;
}

cast ������
- ������� ����ȯ �� �� ����ϴ� ������
- ���α׷��Ӱ� ��ȯ�ϰ��� �ϴ� �ڷ����� ��������ν� �ڷ����� ��ȯ.
#include<iostream>
using namespace std;
int main() {
	int a = 65;
	cout << a << endl;
	cout << (char)a << endl;
	cout << (double)a << endl;

	char c = 'A';
	cout << c << endl;
	cout << (int)c << endl;
	cout << (double)c << endl;
}

����3>cast������ ����Ͽ� ����
	   ���� 3���� �Է��ϰ� �� ����� ���
#include<iostream>
using namespace std;
int main() {
	int n1, n2, n3;
	int sum = 0;
	double avr;
	cout << "�����Է�:"; cin >> n1;
	cout << "�����Է�:"; cin >> n2;
	cout << "�����Է�:"; cin >> n3;
	sum = n1 + n2 + n3;
	avr = (double)sum / 3;

	cout << "3���� ���� ���:" << avr << endl;

	return 0;
}

//��������
//-ȭ�鿡 ��µǴ� ������ �����Ű�ų� �߰��ϴ� ���
//-����Ȯ�� / ����ä��� / ������ȯ
#include<iostream>
#include<iomanip>
//iomanip : �������ڿ� ���� �Լ��� ������ ����.
using namespace std;
int main() {
	int a = 100; int b = 200;
	cout << a << endl;
	cout << setw(10) << a << endl;
	//setw(n) : nĭ��ŭ ������ Ȯ���ϰ� ����������. (�ѹ� ������ ���Ǹ� ����)
	cout << a << endl; 
	cout << setw(10) <<setfill('a') << a << endl;
	//setfill(����) : ���鿡 ���ڸ� ä���.(�ѹ� ������ �Ǹ� ��� ����)
	cout << setw(10) << a << endl;
	cout << setfill(' ');
	//setfill(���鹮��) - setfill�� �ٽ� �ʱ�ȭ
	cout << setw(10) << a << endl;
	//cout << b << endl;
	//cout << setw(10) << b << endl;

	cout << setprecision(3) << a << endl;
	double c = 5.6789;
	//setprecision(n) : ���ڸ�ŭ ���ڸ� ��� (������ �״�� ,�Ǽ��� n������ŭ ����� �Ҽ����ؿ��� ����.)
	cout << setprecision(3) << c << endl;
	cout << c << endl;
	c = 5678.123;
	cout << c << endl;
	cout << setprecision(NULL);
	cout << c << endl;
	cout << setbase(8) << a << endl;
	//setbase��(����):���� ��ȯ -�ѹ� �����ϸ� ����. >>2������ȭ�� �ȵ�.
	cout << a << endl;
	cout << setbase(2) << a << endl;
	cout << a << endl;
	cout << setbase(16) << a << endl;
	cout << a << endl;
	cout << setbase(10) << a << endl;
	cout << a << endl;

}