����1. ��ü�� �̿��� ���α׷� ����
- MP3 �÷��̾�
- ��� / ������ / ������ / ���� / ���߰� / ����� / �÷��̾� ����

-->�ٽñ���
#include<iostream>
using namespace std;
class MP3 {
	char name[50];
	char singer[50];
public:
	void set() {
		cout << "�����̸�: "; cin >> singer;
		cout << "�뷡����: "; cin >> name;
	}
	void play() {
		cout << name << "��(��) ���� ������Դϴ�." << endl;
	}
	void list() {
		cout << name << endl;
	}
	int dele(char *c) {
		if (strcmp(c, name)) {
			return 0;
		}
		else {
			return 1;
		}
	}
};
int main() {
	MP3 player[10];
	int cho, cnt = 0;
	int i = 0;
	char del[50];
	while (1) {
		cout << "1.��� 2.������ 3.������ 4.���� 5.���߰� 6.����� 7.�÷��̾� ����\n>>>";
		cin >> cho;
		system("cls");
		switch (cho) {
		case 1:
			if (cnt <= 0) {
				cout << "��� �� ���� �����ϴ�." << endl;
			}
			else {
				for (int k = 0; k < cnt; k++) {
					cout << k + 1 << ".";
					player[k].list();
				}
				cout << "��� �� ���� ������\n����:"; cin >> i;
				player[i-1].play();
			}
			break;
		case 2:
			if (cnt <= 0) {
				cout << "��� �� ���� �����ϴ�." << endl;
			}
			else if (cnt == 1) {
				cout << "���� ���� �ϳ��ۿ� �����ϴ�." << endl;
			}
			else {
				i--;
				player[i-1].play();
			}
			break;
		case 3:
			if (cnt <= 0) {
				cout << "��� �� ���� �����ϴ�." << endl;
			}
			else if (cnt == 1) {
				cout << "���� ���� �ϳ��ۿ� �����ϴ�." << endl;
			}
			else {
				i++;
				player[i-1].play();
			}
			break;
		case 4:
			i = 0;
			cout << "�÷��̾ �����˴ϴ�." << endl;
			break;
		case 5:
			cnt++;
			cout << "�߰� �� ���� ������ �����ϼ���." << endl;
			player[cnt-1].set();
			break;
		case 6:
			int n;
			cout << "������ ���� �����ϼ���: "; cin >> del;
			for (int k = 0; k < cnt; k++) {
				n=player[k].dele(del);
			}
			if (n == 0) {
				cout << "������ ���� ������ �����ϴ�." << endl;
			}
			else if (n == 1) {
				cnt--;
				for (int k = 0; k < cnt; k++) {
					player[k] = player[k + 1];
				}
			}
			break;
			if (cho == 7) {
				cout << "�÷��̾ ����˴ϴ�." << endl;
				break;
			}
		}
	}
}

const ���
- ������ ���ȭ ��Ű�� ���� �ǹ��Ѵ�.
- ���� : ���� ���� �� �� �ִ� �� �Ǵ� ����
- ��� : ���� ���� �� �� ���� ��
- ��, ���� ���� �� �� ������ �ϴ� ���� �ǹ��Ѵ�.
- ���� const �� ������ ��µ� �ʱ�ȭ�� ���� ������ ���� �߻�
const int a = 100;
a = 200; // ���� �Ұ���

#include<iostream>
using namespace std;
int main() {
	int a = 10;
	cout << a << endl;
	a = 20;
	cout << a << endl;
	const int b = 10;
	cout << b << endl;
	 b = 30;		��������� ���� �Ұ���
	 const int c;  ��!�ʱ�ȭ�ʿ�
	 c = 10;
	int d = 50;
	int* pa = &a;
	cout << *pa << endl;
	const int* pb = &a;
	 �����ͺ����� const�� �ڷ��� �տ� ������ �ּҰ��� ������ ����. 
	cout << *pb << endl;
	pb = &d;
	cout << *pb << endl;
	 *pb = 100; ������,�ּҰ��� ���� ���� ������ �Ұ���.
	int* const pc = &a;
	 �����ͺ����� const�� ������ �տ� ������ �ּҰ��� ������ �Ұ���.
	cout << *pc << endl;
	 pc = &d; �Ұ���
	*pc = 100;
	 �ּҰ��� ���� ���� ������ ����.
	const int* const pd = &a;
	cout << *pd << endl;
	 �ּҰ��� ���� ������ �Ұ���.
}

��������� ���ȭ
1. Ŭ�������� ������� ������ ���ȭ ��ų �� �ִ�.
2. ���ȭ �� ��������� �ݵ�� �����ڿ��� �ݷ��� �ʱ�ȭ�� �̿��ؼ� �ʱ�ȭ �ؾ� �ȴ�.

�ݷ��� �ʱ�ȭ
- �����ڴ� �ݷ��� �̿��ؼ� ��������� �ʱ�ȭ �� �� �ִ�.
- '='�� ��� �� �� ����, �ݵ�� '()'�� ����ؾ� �Ѵ�.
- �ݷ��� �ʱ�ȭ�� ������ �����ڿ����� �����ϴ�.
- ������ �Ϲݺ����� �����ͺ����� ����� �����ϰ� �迭�� �Ұ����ϴ�.
- ��ӹ��� �θ�Ŭ������ �����ڸ� ȣ�� �� ���� ��� �� �� �ִ�.

������(�Ű�����) :�������(�Ű�����) {
}
class Test {
	int a;
public:
	Test(int a1) :a(a1) {};
	Test(int a1) {a=a1};
};

#include<iostream>
using namespace std;
class Test {
	int a;
	int b;	
public:
	/*Test(int a1) {
		a = a1;
	}*/
	//Test(int a1) :a(a1) {};

	/*Test(int a1, int b1) {
		a = a1;
		b = b1;
	}*/
	Test(int a1, int b1) : a(a1), b(b1) {};
	Test(int a1, int b1) :a(a1) {
		b = b1;
	}
	void get() {
		cout << a << endl;
		cout << b << endl;
	}

};
int main() {
	//Test t1(10);
	//t1.get();
	Test t2(10, 20);
	t2.get();
	Test t3(20, 30);
}

#include<iostream>
using namespace std;
class Test {
	const int c;
	const int d;
public:
	Test(int c1, int d1) : c(c1), d(d1) {};
	
	void get() {
		cout << c << endl;
		cout << d << endl;
	}
};
int main() {
	Test t1(10, 20);
	t1.get();
}
 const ��������� ������ ���ÿ� �ٷ� �ʱ�ȭ�� ������Ѵ�. ���� ���Կ�����(=)�� ����� �Ұ����ϰ�,
 �ݷ��� �ʱ�ȭ ()�Ұ�ȣ�� �̿��Ͽ� �ʱ�ȭ�� ���ÿ� �ؾ��Ѵ�.