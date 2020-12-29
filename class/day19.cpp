//문제1.다형성을 이용하여 구현
//-부모클래스 : 정수의 값,문자 값
//-자식클래스 : 정수의 값 만큼 반복해서 문자로 출력

#include<iostream>
#include<iomanip>
using namespace std;
class Setting {
protected:
	int n;
	char c;
public:
	void set() {
		cout << "반복할 횟수 결정 : "; cin >> n;
		cout << "반복할 문자 결정 : "; cin >> c;
	}
	virtual void get(){}
};
class Stair : public Setting {
	int i;
	int k;
public:
	void get() {
		for (i = 0; i < n; i++) {
			for (k = 1; k <= i + 1; k++) {
				cout << c;
			}
			cout << endl;
		}
	}
};
class Pyramid : public Setting {
	int i, k;
public:
	void get() {
		for (i = 0; i < n; i += 1) {
			cout << setw(n - i);
			for (k = 1; k <= 1 + (2 * i); k += 1) {
				cout << c;
			}
			cout << endl;
		}
	}
};
int main() {
	Setting* t1 = new Stair;
	t1->set();
	t1->get();
	cout << "===============================" << endl;
	Setting* t2 = new Pyramid;
	t2->set();
	t2->get();
	
}


friend 함수
- 멤버함수가 아니다.
- 전역함수도 아니다.
- 클래스의 친구 함수
- 매개변수로 객체(클래스 변수)를 가진다.
-> 그객체를 통해서 멤버변수에 값을 저장하거나 참조할 수 있다.
- friend 함수는 this 포인터를 가지고 있지 않다.

#include<iostream>
using namespace std;
class Test{
	int a, b;
public:
	void set(int ia,int ib) {
		a = ia;
		b = ib;
	}
	void get() {
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
	}
	friend void add(Test& r);
};
void add(Test& r) {
	r.a += 10;
	r.b += 10;
}
int main() {
	Test t1;
	t1.set(10, 20);
	t1.get();
	//t1.add(); 내부함수가 아니기 때문에, 객체를 통해서 접근할수가 없다.(this를 가지고 있지 않기 때문에)
}


연산자 오버로딩
- 연산자에 또 다른 기능을 추가하는 것을 의미한다.
- C++에서는 연산자에 기능 추가를 함수로 정의 할 수 있다.
- 객체도 일반변수처럼 연산을 가능하게 해주는 것이다.
- C++언어의 확장성을 증가시키고, 자연스럽게 프로그램을 표현 할 수 있게 하기 위해서 사용한다.

선언방법
- 일반멤버함수와 같다.
- 프로그램의 내용과 적용되는 자료형에 따라 문제중심으로 표현하기 위해서 기존 C언어에서 제공되는
  연산자의 의미를 변경하여 사용 할 수 있는 기능이다.

연산자 오버로딩의 특징
- 기본 자료형에서 사용하고 있는 연산자 의미를 변경하여 재정의 하는것을 의미한다.
- 반드시 기존 C언어의 연산자를 사용해야 한다.
- 연산자가 취하는 항목의 수는 변경이 불가능하다.
- 연산자 오버로딩시 우선순위는 원래 연산자의 우선순위가 그대로 정해진다.
- 연산자 함수는 디폴트 매개변수를 가질 수가 없다.
- 연산자에 있어서 피연산자가 함수를 오버로딩 할 때는 전달인자로 구현된다.
- 객체가 연산자를 만나면 operator 함수를 호출식으로 인식되며, 연산자 오버로딩은 함수에서 정의된 방법과
  동일하다.
- 연산자 정의 시 전달인자의 자료형에 의해 그 연산자를 사용 할 수 있는 자료형이 결정된다.
- 연산자 오버로딩은 operator 함수로 구현된다.
-> 멤버함수와 friend 함수로도 표현할 수 있다.

연산자 오버로딩을 할 때 주의사항
- 연산자를 재정희 하게 되면 어떤 경우에는 복잡한것을 간단하게 또는 산만한것을 좀더 간단하게 논리적으로 표현가능.
- 부작용
1> 연산자를 여러 형태로 다중정의 해놓으면 코드 자체가 이해가 어렵게 된다.
2> 다른사람이 자신의 소스를 분석할때 일일히 그 연산자가 어떻게 정의되어 있는지 확인해야 하는 경우가 생긴다.
3> 그 코드가 정의되어 있는 소스파일이 없이 라이브러리 형태로 되어있다면 연산자의 정의내용을 파악 할 수 없다.
4> 주석을 달아서 3번의 문제를 해결 할 수 있지만 너무 복잡하게 되면 일정시간이 지나면 자신도 이해 할 수 없는
   경우가 생길 수 있다.
5> 때문에 연산자 오버로딩은 꼭 필요한 경우가 아니면 자제하는 것이 좋으며 우리가 연사자 오버로딩을 공부하는
   이유는 라이브러리나 I/O stream 또는 남이 구현해 놓은 클래스를 좀더 신속하게 이해하고, 적극적으로 활용
   하기 위해서 공부한다.


//문제2. 연산자 오버로딩을 이용하여 구현
//- time 클래스 : 시간 / 분 멤버변수
//- 두개의 계단객체 : 3시간 30분 / 2시간 40분
//- 두개의 객체를 더하면 시간은 시간끼리 더하고 분은 분끼리 더하기
//- 두개의 객체를 빼면 시간은 시간끼리 빼고 분은 분끼리 빼기
#include<iostream>
using namespace std;
class Time {
	int hour;
	int min;
public:
	void set(int n1, int n2) {
		hour = n1;
		min = n2;
	}
	int operator+(Time& r) {
		return ((r.hour) * 60 + (r.min)) + ((this->hour) * 60 + (this->min));
	}
	int operator-(Time& r) {
		return ((r.hour) * 60 + (r.min)) - ((this->hour) * 60 + (this->min));
	}
};
int main() {
	int res1, res2;
	Time t1;
	Time t2;
	t1.set(3, 30);
	t2.set(2, 40);
	res1 = t1 + t2;
	cout << (res1 / 60) << "시 " << (res1 % 60) << "분 " << endl;
	res2 = t2 - t1;
	cout << (res2 / 60) << "시 " << (res2 % 60) << "분 " << endl;
}
// -> friend 함수로 구현;