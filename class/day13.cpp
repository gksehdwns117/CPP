문제1. 객체를 이용한 프로그램 구현
- MP3 플레이어
- 재생 / 이전곡 / 다음곡 / 정지 / 곡추가 / 곡삭제 / 플레이어 종료

-->다시구현
#include<iostream>
using namespace std;
class MP3 {
	char name[50];
	char singer[50];
public:
	void set() {
		cout << "가수이름: "; cin >> singer;
		cout << "노래제목: "; cin >> name;
	}
	void play() {
		cout << name << "이(가) 현재 재생중입니다." << endl;
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
		cout << "1.재생 2.이전곡 3.다음곡 4.정지 5.곡추가 6.곡삭제 7.플레이어 종료\n>>>";
		cin >> cho;
		system("cls");
		switch (cho) {
		case 1:
			if (cnt <= 0) {
				cout << "재생 할 곡이 없습니다." << endl;
			}
			else {
				for (int k = 0; k < cnt; k++) {
					cout << k + 1 << ".";
					player[k].list();
				}
				cout << "재생 할 곡을 고르세요\n선택:"; cin >> i;
				player[i-1].play();
			}
			break;
		case 2:
			if (cnt <= 0) {
				cout << "재생 할 곡이 없습니다." << endl;
			}
			else if (cnt == 1) {
				cout << "현재 곡이 하나밖에 없습니다." << endl;
			}
			else {
				i--;
				player[i-1].play();
			}
			break;
		case 3:
			if (cnt <= 0) {
				cout << "재생 할 곡이 없습니다." << endl;
			}
			else if (cnt == 1) {
				cout << "현재 곡이 하나밖에 없습니다." << endl;
			}
			else {
				i++;
				player[i-1].play();
			}
			break;
		case 4:
			i = 0;
			cout << "플레이어가 정지됩니다." << endl;
			break;
		case 5:
			cnt++;
			cout << "추가 할 곡명과 가수를 선택하세요." << endl;
			player[cnt-1].set();
			break;
		case 6:
			int n;
			cout << "삭제할 곡을 선택하세요: "; cin >> del;
			for (int k = 0; k < cnt; k++) {
				n=player[k].dele(del);
			}
			if (n == 0) {
				cout << "선택한 곡의 정보가 없습니다." << endl;
			}
			else if (n == 1) {
				cnt--;
				for (int k = 0; k < cnt; k++) {
					player[k] = player[k + 1];
				}
			}
			break;
			if (cho == 7) {
				cout << "플레이어가 종료됩니다." << endl;
				break;
			}
		}
	}
}

const 멤버
- 변수를 상수화 시키는 것을 의미한다.
- 변수 : 값을 변경 할 수 있는 값 또는 공간
- 상수 : 값을 변경 할 수 없는 값
- 즉, 값을 변경 할 수 없도록 하는 것을 의미한다.
- 만일 const 를 지정해 줬는데 초기화를 하지 않으면 에러 발생
const int a = 100;
a = 200; // 변경 불가능

#include<iostream>
using namespace std;
int main() {
	int a = 10;
	cout << a << endl;
	a = 20;
	cout << a << endl;
	const int b = 10;
	cout << b << endl;
	 b = 30;		상수형변수 변경 불가능
	 const int c;  꼭!초기화필요
	 c = 10;
	int d = 50;
	int* pa = &a;
	cout << *pa << endl;
	const int* pb = &a;
	 포인터변수에 const가 자료형 앞에 붙으면 주소값은 변경이 가능. 
	cout << *pb << endl;
	pb = &d;
	cout << *pb << endl;
	 *pb = 100; 하지만,주소값이 가진 값은 변경이 불가능.
	int* const pc = &a;
	 포인터변수에 const가 변수명 앞에 붙으면 주소값은 변경이 불가능.
	cout << *pc << endl;
	 pc = &d; 불가능
	*pc = 100;
	 주소값이 가진 값은 변경이 가능.
	const int* const pd = &a;
	cout << *pd << endl;
	 주소값도 값도 변경이 불가능.
}

멤버변수의 상수화
1. 클래스에서 멤버변수 생성시 상수화 시킬 수 있다.
2. 상수화 된 멤버변수는 반드시 생성자에서 콜론의 초기화를 이용해서 초기화 해야 된다.

콜론의 초기화
- 생성자는 콜론을 이용해서 멤버변수를 초기화 할 수 있다.
- '='은 사용 할 수 없고, 반드시 '()'를 사용해야 한다.
- 콜론의 초기화는 오로지 생성자에서만 가능하다.
- 오로지 일반변수와 포인터변수만 사용이 가능하고 배열은 불가능하다.
- 상속받은 부모클래스의 생성자를 호출 할 때도 사용 할 수 있다.

생성자(매개변수) :멤버변수(매개변수) {
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
 const 멤버변수는 생성과 동시에 바로 초기화를 해줘야한다. 따라서 대입연산자(=)은 사용이 불가능하고,
 콜론의 초기화 ()소괄호를 이용하여 초기화를 동시에 해야한다.