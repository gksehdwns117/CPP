문제1. 매크로를 이용해 구현
- 값을 주면 2개 값을 리턴
- 값을 주면 값*값을 리턴
- 값을 주면 값+100을 리턴
#include<iostream>
#define mec1(x) 2*x
#define mec2(x) x*x
#define mec3(x) x+100
using namespace std;
int main() {
	int x;
	cout << "매크로 정수 입력:";
	cin >> x;

	cout << "2배 값 리턴:" << mec1(x) << endl;
	cout << "갑*값  리턴:" << mec2(x) << endl;
	cout << "값+100 리턴:" << mec3(x) << endl;
}
매크로는 자료형을 구분을 하지 않는다.


inline 함수
- 프로그램 실행 속도를 높이기 위해서 추가된 기능
- c언어에서의 매크로와 비교되는 함수다.

#include<iostream>
using namespace std;
void func() {

}
inline void func1() {

}


일반함수와 inline 함수 차이점
- 호출방식이 다르다.
- 프로그램의 실행 속도가 빠르다.

매크로와 inline 함수 차이점
- 매크로는 자료형의 구분이 없다.
- inline 함수는 기본적으로 함수의 형태이기 때문에 자료형이 존재한다.
- 매크로는 단순한 형태의 정의만 가능하다.
- inline 함수는 함수의 형태이기 때문에 복잡한 형태의 정의도 가능하다.

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
	//매크로는 자료형구분을 하지 않기 때문에 모두 실행이 가능하다.
	cout << SPA1(10) << endl;
	cout << SPA1('A') << endl;
	cout << SPA1(1.1) << endl;

}


inline 함수 참고사항
- 프로그래머가 inline 함수를 선언해도 컴파일러가 거부 할 수 있다.
- 프로그래머가 inline 함수를 선언하지 않아도 필요에 따라 컴파일러가 inline 화 시킬 수 있다.
- 함수의 소스 크기가 크거나 재귀 호출이면 inline 요구를 컴파일러가 거부 할 수 있다.
- 함수의 소스 크기가 크면 실행 파일이 그만큼 커질 수 있다는 단점이 있다.
- 함수의 코드의 실행 시간이 짧고 빈번하게 호출되는 함수가 아니면 절대적인 시간은 절약되지 않는다.

inline 함수의 특징
- 실행해보면 일반함수와 크게 다르지 않다.
- 즉, 일반함수에 inline 이라는 이름만 추가 하면 된다.
- 하지만 inline 함수는 호출하지 않고 함수의 코드를 그 자리에 실행한다.
- 즉, 컴파일 될 때 inline 함수는 호출 하는 함수의 코드 안에 포함된다.
- 호출 과정이 없기 때문에 실행 속도가 빨라지게 된다.
- 함수의 코드가 복제 되기 때문에 실행 파일이 커진다는 단점을 가진다.

문제2. inline 함수를 이용하여 구현
- 정수형이 입력 되면 정수값의 곱하기 100 한 값을 리턴
- 실수형이 입력 되면 실수값의 더하기 100 한 값을 리턴
- 문자형이 입력 되면 문자값의 대<>소 변경한 값을 리턴
- 정수형과 실수형이 입력 되면 곱한 값을 리턴
- 실수형과 정수형이 입력 되면 더한 값을 리턴
- 정수형과 문자형이 입력 되면 더한 값을 리턴
- 문자형과 정수형이 입력 되면 뺀   값을 리턴

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


bool 자료형
- 1byte 자료형
- true, false 를 저장하는 자료형

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


문제3. bool 자료형을 이용하여 구현
- 문자열 두개를 입력
- 동일하면 동일하다고 출력
- 동일 하지 않으면 동일하지 않다고 출력
- true 와 false 값을 bool 자료형에 저장

#include<iostream>
// <string.h>
using namespace std;

int main() {
	char s1[30];
	char s2[30];
	bool bo;

	cout << "문자열1 입력:";
	cin.get(s1, 30);
	getchar();
	cout << "문자열2 입력:";
	cin.get(s2, 30);

	bo = strcmp(s1, s2);

	if (bo == 0) {
		cout << "두 문자열은 동일합니다." << endl;
	}
	else {
		cout << "두 문자열은 동일하지 않습니다." << endl;
	}
}


c언어 초기화
/*1. 선언 후 초기화
int a;
a = 10;
2. 선언과 동시에 초기화
int a = 10;*/

c++ 언어 초기화-선언과 동시에 초기화만 가능
int a(10);
int b(20);

#include<iostream>
using namespace std;
int main() {
	int a = 10;
	int b(20);
	클래스로 초기화(객체 초기화)
	cout << a << ":" << b << endl;
	b(30);  b는 함수가 아니기 때문에 선언 후 초기화는 불가능(함수 호출 방식과 동일하므로)
	b = 30;
	cout << a << ":" << b << endl;
}

- 이 방식은 클래스에서 생성자를 초기화 할 때 사용하는 방법
- 그냥도 사용하기는 하지만 잘 사용하는 방법은 아니다.
- 즉, 이런 방식은 사용을 권장하지는 않는다.

레퍼런스 변수
- 포인터 대신에 사용한다.
- 레퍼런스는 참조를 의미: 참조변수
- 기존에 있는 변수명에 다른 이름을 부여 할 수 있다.
- 같은 위치에 저장하는 변수의 이름이 여러개다.
- 서로 다른 이름으로 하나의 변수(공간)에 접근이 가능하다.
- 즉, 변수하나에 여러개의 이름을 부여하는 것이다.

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

