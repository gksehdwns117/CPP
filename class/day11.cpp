문제1.생성자를 이용하여 구현
- 생성자의 값이 없으면 1~10까지의 합을 구하는 객체 생성
- 생성자의 값이 하나일경우 1~값 까지의 합을 구하는 객체 생성
- 생성자의 값이 두개이면 작은 값~큰값 까지의 합을 구하는 객체 생성
#include<iostream>
using namespace std;
class Sum {
private:
	int a;
	int b;
	int i;
	int sum = 0;
public:
	Sum() {
		for (i = 0; i <= 10; i++) {
			sum += 1;
		}
		cout << "1~10까지의 합: " << sum << endl;
	}
	Sum(int n1) {
		for (i = 0; i <= n1; i++) {
			sum += i;
		}
		cout << "1~" << n1 << "까지의 합: " << sum << endl;
	}
	Sum(int n1, int n2) {
		for (i = n1; i <= n2; i++) {
			sum += i;
		}
		cout << n1 << n2 << "까지의 합: " << sum << endl;
	}
};
int main() {
	int n1, n2;
	while (1) {
		int cho = 0;
		cout << "1.입력없음 2.한개의 정수만 입력 3.두개 모두 입력 0.종료\n>>>"; cin >> cho;
		if(cho==1)
			Sum s();
		else if (cho == 2) {
			cout << "첫번째 정수 입력:"; cin >> n1;
			Sum sum(n1);
		}
		else if (cho == 3) {
			cout << "첫번째 정수 입력:"; cin >> n1;
			cout << "두번째 정수 입력:"; cin >> n2;
			if (n1 > n2) {
				Sum s(n2, n1);
			}
			else if (n2 > n1) {
				Sum s(n1, n2);
			}
		}
		else if (cho == 0) {
			break;
		}
		else {
			cout << "잘못입력하셨습니다." << endl;
			continue;
		}
	}
	return 0;
}


클래스 기본개념
- 기본적으로 private 이 public 으로 변경되었을때도 동일하게 동작되어야 한다.
- 동작을 함수로 변경해서 사용한다.

생성자의 기능
- 객체를 생성할 때 멤버변수를 원하는 값으로 초기화 할 수 있다.
- 일반변수처럼 초기화를 시키고 싶어서 만들어진것
AAA(클래스 태그) aaa(객체);
aaa.set(3) : 함수에 의한 초기화
AAA aaa(3) : 생성자에 의한 초기화
- 생성자가 만들어지지 않으면 함수에 의한 초기화만 가능하다.
- 그래서 생성자가 만들어지면 객체를 선언과 동시에 초기화 할 수 있다.

생성자의 특징
- 생성자의 이름은 클래스명과 동일하다.
- 객체의 멤버변수를 초기화 하기 위해서 만든 함수
- 객체가 생성 될 때, 자동으로 호출되는 멤버함수
- 객체가 생성 될 때, 자동으로 실행되는 함수이기 때문에 별도로 호출하지 않아도 된다.
- 그리고 생성된 이후에 호출 할 수 없다.
- 생성된 이후에는 set()함수를 통해서 초기화 할 수 있다.
- return 값이 존재하지 않기 때문에 return 자료형을 쓸 필요가 없다.
- 생성자도 오버로딩이 가능하다.
- 오버로딩은 매개변수의 자료형 및 갯수가 다르면 가능하다.
- 객체가 생성 될 때, 단 한번만 수행하기 때문에 차후 멤버변수를 변경하고 싶다면 set()함수를 사용해야 한다.

default 생성자
- 생성자를 만들지 않으면 디폴트 생성자가 자동 호출 된다.
- 소스코드에서는 보이지 않아도 자동 호출된다.
- 디폴트 생성자란 아무 명령도 없는 함수를 의미한다.
- 클래스를 생성하면 자동 생성된다.

문제2.생성자와 클래스를 이용해서 구현
- 멤버변수 : work_day, work_pay
- 기본일자 : 20일
- 기본일당 : 10만원
- 일자를 입력 * 기본 일당 = 월급
- 일당을 입력 * 기본 일자 = 월급
- 일당을 입력 * 일자를 입력 = 월급

#include<iostream>
using namespace std;
class Fee {
private:
	int work_day;
	int work_pay;
public:
	Fee() {
		work_day = 20;
		work_pay = 10;
	}
	Fee(int n1) {
		if (n1 == 1) {
			cout << "변경 할 기본일자: "; cin >> work_day;
			work_pay = 10;
		}
		else if (n1 == 2) {
			cout << "변경 할 기본일당: "; cin >> work_pay;
			work_day = 20;
		}
	}
	Fee(int n1, int n2) {
		work_day = n1;
		work_pay = n2;
	}
	void get() {
		int fee = 0;
		fee = work_day * work_pay;
		cout << "이번달 월급은 " << fee << " (만원)입니다.\n" << endl;
	}
};
int main() {
	Fee f1;
	int n1, n2;
	while (1) {
		int cho1, cho2;
		cout << "1.기본금 계산 2.기본일자 or 기본일당 변경 3.기본일자 and 기본일당 둘다 변경 4.종료\n>>>";
		cin >> cho1;
		if (cho1 == 1) {
			f1.get();
			system("pause");
			system("cls");
		}
		else if (cho1 == 2) {
			cout << "1.기본일자 변경 2.기본일당 변경\n>>>"; cin >> cho2;
			system("cls");
			Fee f2(cho2);
			f2.get();
			system("pause");
			system("cls");
		}
		else if (cho1 == 3) {
			cout << "변경 할 기본일자: "; cin >> n1;
			cout << "변경 할 기본일당: "; cin >> n2;
			Fee f3(n1, n2);
			f3.get();
			system("pause");
			system("cls");
		}
		else if (cho1 == 0) {
			break;
		}
		else {
			cout << "잘못입력하셨습니다." << endl;
			continue;
		}
	}
}

소멸자
1. 객체가 정의 되는 순간
- 생성자를 통해 동적 메모리 영역을 할당 받으면 할당된 변수는 메모리의 힙영역에 존재
- 할당된 변수는 객체가 프로그램의 실행 범위를 벗어나거나 프로그램이 종료되어도 메모리에 남게된다.
2. 객체가 소멸 되는 순간
- 일반변수와 마찬가지로 객체가 선언되어 사용되는 블록이 끝날때 자동으로 소멸된다.
- 동적할당 된 변수를 제거하기 위해 객체가 소멸될때 자동으로 호출되는 멤버함수가 소멸자이다.

~클래스명() {

}


기능
- 동적할당 된 변수를 해제할때 주로 사용한다.
- 생성자에서 new 에 의해 동적으로 메모리를 할당 하면 반드시 소멸자에서 delete 로 할당된 메모리를 제거한다.

특징
- 소멸자도 멤버함수이다.
- 소멸자의 함수이름은 클래스 이름이랑 동일해야한다.
- 소멸자 함수는 생성자 함수와 구분하기 위해 이름앞에 '~' 를 사용한다.
- return 값이 없기 때문에 반환 자료형이 없다.
- 객체가 소멸될때 자동으로 호출 된다.
- 생성자와 다른점은 매개변수를 가지지 못한다.

#include<iostream>
using namespace std;
class Test {
private:
	int* su;
public:
	Test() {
		cout << "생성자" << endl;
		su = new int;
	}
	~Test() {
		cout << "소멸자" << endl;
		delete(su);
	}
};
int main() {
	Test t1;
}

디폴트 소멸자
- 소멸자를 만들지 않으면 디폴트 소멸자가 호출된다.
- 디폴트 소멸자에는 아무 명령도 존재하지 않는다.
- 일반변수일 경우에는 default 소멸자를 사용한다.

생성자와 소멸자의 유의사항
- 반드시 초기화 되어야 하는 멤버변수는 생성자를 통해서 초기화 해야한다.
- 생성자와 소멸자에서 하는 일을 최대한 줄여야 한다.
- 별도의 초기화나 소멸함수를 만들지 않는다.

#include<iostream>
using namespace std;
class Test {
public:
	Test() {
		cout << this << "생성자 호출" << endl;
	}
	~Test() {
		cout << this << "소멸자 호출" << endl;
	}
};
int main() {
	Test t1;	//t1.Test();
	Test t2;	//t2.Test();
	Test t3;	//t3.Test();
	cout << "t1:" << &t1 << endl;	//t3.~Test();
	cout << "t2:" << &t2 << endl;	//t2.~Test();
	cout << "t3:" << &t3 << endl;	//t1.~Test();
}


#include<iostream>
using namespace std;

class Test {
	int* su;
public:
	Test() {
		cout << this << "생성자" << endl;
		su = new int;
	}
	void set() {
		cout << "정수입력:"; cin >> *su;
	}
	void get() {
		cout << "입력받은정수:" << *su << endl;
	}
	~Test() {
		cout << this << "소멸자" << endl;
		delete(su);
	}
};
int main() {
	Test t1, t2;
	t1.set();
	t1.get();
	t2.set();
	t2.get();
}

//먼저 생성된 객체보다 나중에 생성된 객체 더 먼저 소멸된다. firo , rifo
