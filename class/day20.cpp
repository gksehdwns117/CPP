//����1.
//1>�Ƹ޸�ī�� 2>īǪġ�� 3>�꽺 4>�����
//����Լ� : �ֹ� / 5���� �ֹ����� �Ϸ� / ����
//�ֹ� -> �ֹ�����Ϸ� -> ����
/*#include<iostream>
#include<window.h>			//Sleep(1000) : 1�ʵ��۸���
using namespace std;
class Cafe {
	char* order;
	int cost;
	char ans;
public:
	Cafe() {
		order = new char[10];
	}
	~Cafe() {
		delete[] order;
	}
	int input_order() {
		cout << "�޴� �Է� : "; cin >> order;
		if (strcmp(order, "�Ƹ޸�ī��") == 0) {
			return 1;
		}
		else if (strcmp(order, "īǪġ��") == 0) {
			return 2;
		}
		else if (strcmp(order, "�꽺") == 0) {
			return 3;
		}
		else if (strcmp(order, "ī���") == 0) {
			return 4;
		}
	}
	void complete(int n) {
		cout << "�ش����ᰡ ���ö����� ��ø� ��ٷ��ֽʽÿ�.." << endl;
		cout << "..........5����.............." << endl;
		if (n == 1) {
			cout << "�ֹ��Ͻ� �Ƹ޸�ī�� ���Խ��ϴ�." << endl;
		}
		else if (n == 2) {
			cout << "�ֹ��Ͻ� īǪġ�� ���Խ��ϴ�." << endl;
		}
		else if (n == 3) {
			cout << "�ֹ��Ͻ� �꽺 ���Խ��ϴ�." << endl;
		}
		else if (n == 4) {
			cout << "�ֹ��Ͻ� ����� ���Խ��ϴ�." << endl;
		}
	}
	void output_cost(int n) {
		if (n == 1) {
			cost = 3500;
		}
		else if (n == 2) {
			cost = 4000;
		}
		else if (n == 3) {
			cost = 2000;
		}
		else if (n == 4) {
			cost = 4500;
		}
		cout << "�ش������� ������ " << cost << "���Դϴ�." << endl;
	}
	char plus_order() {
		cout << "�߰��ֹ��Ͻðڽ��ϱ�(y,n)?"; cin >> ans;
		return ans;
	}
	
};
int main() {
	Cafe con;
	int cho;
	char ans;
	while (1) {
		cout << "�ֹ��ްڽ��ϴ�..." << endl;
		cho = con.input_order();
		switch (cho) {
		case 1:
			con.complete(cho);
			con.output_cost(cho);
			ans = con.plus_order();
			if (ans == 'y') {
				continue;
			}
			else if (ans == 'n') {
				return 1;
			}
			break;
		case 2:
			con.complete(cho);
			con.output_cost(cho);
			ans = con.plus_order();
			if (ans == 'y') {
				continue;
			}
			else if (ans == 'n') {
				return 1;
			}
			break;
		case 3:
			con.complete(cho);
			con.output_cost(cho);
			ans = con.plus_order();
			if (ans == 'y') {
				continue;
			}
			else if (ans == 'n') {
				return 1;
			}
			break;
		case 4:
			con.complete(cho);
			con.output_cost(cho);
			ans = con.plus_order();
			if (ans == 'y') {
				continue;
			}
			else if (ans == 'n') {
				return 1;
			}
			break;
		}
	}
}


���ø�
- ������ �ǹ� : ��Ʋ �Ǵ� ����,������ �ǹ��Ѵ�.
- c++������ ���ø��� � ������ �� �� �ִ� ���¸� �ǹ��Ѵ�.
- ���ø����� �Լ� ���ø��� Ŭ���� ���ø��� �����Ѵ�.

�Լ� ���ø� : �Լ��� ����� ���� ��Ʋ
- �ڵ�� �����ϰ� �ڷ����� �ٸ� �Լ��� ���� �� �� ����Ѵ�.
- �Լ��� ����� ���� ��Ʋ�ϻ� ���� �Լ��� �ƴϴ�.
- ��, �Լ��� ȣ��Ǵ� ���� �Լ��� ���޵Ǵ� �μ��� Ÿ���� ���� �� �ڷ�����
  �Լ��� ��ü�����Ѵ�.
- �Լ� ���ø����κ��� ������� �Լ��� ���ø� �Լ���� �Ѵ�.
- ���ø� �Լ��� ������ �����Ͻÿ� �̷������.
����
template <typename �ڷ�����Ī>
�Լ�����{
	�Լ�����
}
// ex>
#include<iostream>
using namespace std;
template<typename T>
void swap(T a, T b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << a << endl;
	cout << b << endl;
}
int main() {
	swap(10, 20);
	swap('a', 'b');
	swap(1.1, 2.2);
	//swap('a', 10);	//�ٸ� �ڷ����� ��밡�� -> ��, �Ű����� ���ø����� 2���̻� ������ ����.
}

�Լ����ø��� Ư¡
- �Լ� ���ø��� ������ �Լ��� ���� ����� �� �ִ�.
- ���� �Լ��� �켱������ �Լ� ���ø����� ����.
- �Լ����ø��� ���Ǵ� �ڷ������� ����ü�� Ŭ������ �����ϴ�.
- �Լ����ø��� �����ϰ� ���̴� ���� �ڷ����� �پ�������, �˰����� ������ �Լ��� ������� �� �� ����Ѵ�.
- ������ �Լ��� �������� �����ϰ� �ߺ� ������ �ʴ� �Լ����� ����ϴ� ���� �������� �ʴ´�.

Ŭ���� ���ø� : Ŭ������ ��������� ��Ʋ
- Ŭ���� ���ø����� �����Ǵ� Ŭ������ ���ø� Ŭ������� �Ѵ�.
- Ŭ���� ���ø��� Ŭ������ �ƴϴ�.

#include<iostream>
using namespace std;
template<typename T>
class Test {
	T a;
public:
	Test(T ia) {
		a = ia;
	}
	void set(T ia) {
		a = ia;
	}
	void get() {
		cout << a << endl;
	}
};
int main() {
	Test<int>t1(10);
	t1.get();
	Test<double>t1(1.1);
	t1.get();
}


//����2. ���ø� Ŭ������ �̿��Ͽ� ����
//������� : 2���� �ٸ� �ڷ���
//����Լ� : �Է� / ���

#include<iostream>
using namespace std;
template<typename ex1,typename ex2>
class Test {
	ex1 a;
	ex2 b;
public:
	void set() {
		cout << "���ø��� �� �Է�1 : "; cin >> a;
		cout << "���ø��� �� �Է�2 : "; cin >> b;
	}
	void get() {
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}
};
int main() {
	Test<int,double> t1;
	t1.set();
	t1.get();
	Test<char, char[10]>t2;
	t2.set();
	t2.get();
}


����ó��
- ���α׷� �����߿� ������ �߻��Ͽ� ���α׷��� ���ߴ� ���� ���� ��Ȳ�� �߻��ߴٶ�� �Ѵ�.
- �̷� ���ܻ�Ȳ�� ó���Ͽ� ���α׷��� ���ߴ� ���� ���� �ϴ� ���� ����ó����� �Ѵ�.

1>����� �̿��ϴ� ���
2>try -- catch 
#include<iostream>
using namespace std;
int main() {
	int a, b;
	cout << "ù��° ���� �Է� : "; cin >> a;
	cout << "�ι�° ���� �Է� : "; cin >> b;
	try {
		if (b == 0)throw b;
		cout << "a/b = " << a / b << endl;
	}
	catch (int x) {
		cout << "0���� ���� �� �����ϴ�." << endl;
	}
}
*/
