//문제1.
//1>아메리카노 2>카푸치노 3>쥬스 4>까페라떼
//멤버함수 : 주문 / 5초후 주문제작 완료 / 가격
//주문 -> 주문음료완료 -> 가격
/*#include<iostream>
#include<window.h>			//Sleep(1000) : 1초동작멈춤
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
		cout << "메뉴 입력 : "; cin >> order;
		if (strcmp(order, "아메리카노") == 0) {
			return 1;
		}
		else if (strcmp(order, "카푸치노") == 0) {
			return 2;
		}
		else if (strcmp(order, "쥬스") == 0) {
			return 3;
		}
		else if (strcmp(order, "카페라떼") == 0) {
			return 4;
		}
	}
	void complete(int n) {
		cout << "해당음료가 나올때까지 잠시만 기다려주십시오.." << endl;
		cout << "..........5초후.............." << endl;
		if (n == 1) {
			cout << "주문하신 아메리카노 나왔습니다." << endl;
		}
		else if (n == 2) {
			cout << "주문하신 카푸치노 나왔습니다." << endl;
		}
		else if (n == 3) {
			cout << "주문하신 쥬스 나왔습니다." << endl;
		}
		else if (n == 4) {
			cout << "주문하신 까페라떼 나왔습니다." << endl;
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
		cout << "해당음료의 가격은 " << cost << "원입니다." << endl;
	}
	char plus_order() {
		cout << "추가주문하시겠습니까(y,n)?"; cin >> ans;
		return ans;
	}
	
};
int main() {
	Cafe con;
	int cho;
	char ans;
	while (1) {
		cout << "주문받겠습니다..." << endl;
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


템플릿
- 사전적 의미 : 형틀 또는 형태,모형을 의미한다.
- c++에서의 템플릿은 어떤 내용을 찍어낼 수 있는 형태를 의미한다.
- 템플릿에는 함수 템플릿과 클래스 템플릿이 존재한다.

함수 템플릿 : 함수를 만들기 위한 형틀
- 코드는 동일하고 자료형만 다른 함수를 정의 할 때 사용한다.
- 함수를 만들기 위한 형틀일뿐 실제 함수는 아니다.
- 즉, 함수가 호출되는 순간 함수로 전달되는 인수의 타입을 보고 그 자료형의
  함수를 자체생성한다.
- 함수 템플릿으로부터 만들어진 함수를 템플릿 함수라고 한다.
- 템플릿 함수의 생성은 컴파일시에 이루어진다.
형식
template <typename 자료형별칭>
함수정의{
	함수내용
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
	//swap('a', 10);	//다른 자료형도 사용가능 -> 단, 매개변수 템플릿형을 2개이상 만들어야 가능.
}

함수템플릿의 특징
- 함수 템플릿은 기존의 함수와 같이 사용할 수 있다.
- 기존 함수의 우선순위가 함수 템플릿보다 높다.
- 함수템플릿에 사용되는 자료형에는 구조체나 클래스도 가능하다.
- 함수템플릿이 유용하게 쓰이는 경우는 자료형은 다양하지만, 알고리즘이 동일한 함수를 만들고자 할 때 사용한다.
- 동일한 함수가 많을때만 권장하고 중복 사용되지 않는 함수에는 사용하는 것을 권장하지 않는다.

클래스 템플릿 : 클래스를 만들기위한 형틀
- 클래스 템플릿으로 생성되는 클래스를 템플릿 클래스라고 한다.
- 클래스 템플릿은 클래스가 아니다.

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


//문제2. 템플릿 클래스를 이용하여 구현
//멤버변수 : 2개의 다른 자료형
//멤버함수 : 입력 / 출력

#include<iostream>
using namespace std;
template<typename ex1,typename ex2>
class Test {
	ex1 a;
	ex2 b;
public:
	void set() {
		cout << "템플릿형 값 입력1 : "; cin >> a;
		cout << "템플릿형 값 입력2 : "; cin >> b;
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


예외처리
- 프로그램 실행중에 에러가 발생하여 프로그램이 멈추는 것을 예외 상황이 발생했다라고 한다.
- 이런 예외상황을 처리하여 프로그램이 멈추는 것을 방지 하는 것을 예외처리라고 한다.

1>제어문을 이용하는 방법
2>try -- catch 
#include<iostream>
using namespace std;
int main() {
	int a, b;
	cout << "첫번째 정수 입력 : "; cin >> a;
	cout << "두번째 정수 입력 : "; cin >> b;
	try {
		if (b == 0)throw b;
		cout << "a/b = " << a / b << endl;
	}
	catch (int x) {
		cout << "0으로 나눌 수 없습니다." << endl;
	}
}
*/
