문제1. inline 과 define 을 이용하여 구현.
 inline
- 정수를 입력하면 그 정수의 3승의 값 반환 o
- 실수를 입력하면 그 실수의 *2의 값 반환
- 문자를 입력하면 그 문자의 대문자 <> 소문자 변환한 값 반환
 define
- 값을 입력하면 그 값의 +100을 반환
- 입력할 수 있는 최대 수를 100을 MAX로 규정
- 입력할 수 있는 최소 수를 0  을 MIN으로 규정

함수 
- 정수는 0~100 까지 중 하나의 값만 입력 가능

#include<iostream>
#define MAX 100
#define MIN 0
#define SPA(x) x+100
using namespace std;
int input() {
	int n;
	cout << "0 ~ 100 까지 중 정수를 입력:";
	cin >> n;
	if (n<MIN || n>MAX) {
		cout << "입력한 정수가 반환되지 않습니다." << endl;
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


 레퍼런스 변수
:변수에 또 다른 이름을 부여하는 레퍼런스 변수를 이용.
- 레퍼런스 변수는 포인터 변수의 기능 중에서 매개변수로 사용되어 호출된 함수에서 호출한 함수의 변수값을
  바꾸는 기능을 대신하게 된다.
- 먼저 생성된 변수의 주소값을 참조하게 된다.
- 포인터를 대체 할 수 있어서 c++에서는 포인터보다 많이 사용한다.
- 배열에는 사용 할 수 없다.
- 레퍼런스는 일반 변수 형태만 가능하다.

 레퍼런스 변수의 특징
- 레퍼런스 변수는 선언시 '&' 연산자를 사용한다.
- 선언과 동시에 초기화 되어야 한다.
- 상수로 레퍼런스 변수를 초기화 할 수 없다. -> 다른 변수의 주소값을 참조하여 초기화
- 함수의 매개변수로 주로 사용된다.

#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int& r = a;
	//r = a;  변수를 참조하지 못하면 생성 할 수 없기 때문에 선언 후 초기화 불가능.
	int* p = &a;
	// 포인터변수는 변수안에 변수의 주소값을 저장하고 그 주소값을 참조하도록 되어있다.
	cout << "a의 위치 주소값:" << &a << endl;
	cout << "r의 위치 주소값:" << &r << endl;
	cout << "포인터 p의 위치 주소값:" << &p << endl;
	cout << "포인터 p의 가진 위치값:" << p << endl;

	cout << "a가 가진 값	:" << a << endl;
	cout << "r가 가진 값	:" << r << endl;
	cout << "p가 참조하는 값	:" << *p << endl;

	a = 20;
	cout << "a가 가진 값	:" << a << endl;
	cout << "r가 가진 값	:" << r << endl;
	cout << "p가 참조하는 값	:" << *p << endl;

	r = 30;
	cout << "a가 가진 값	:" << a << endl;
	cout << "r가 가진 값	:" << r << endl;
	cout << "p가 참조하는 값	:" << *p << endl;

	*p = 50;
	cout << "a가 가진 값	:" << a << endl;
	cout << "r가 가진 값	:" << r << endl;
	cout << "p가 참조하는 값	:" << *p << endl;
	return 0;
}


레퍼런스 매개변수는 같은 자료형의 일반 매개변수와 같으면 함수의 오버로딩이 불가능하다.
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


문제2.레퍼런스 변수와 포인터변수를 사용
- 정수값 3개를 입력 받기
- 최대값과 최솟값을 출력
- 레퍼런스 변수를 이용하기 위해서는 일반 변수로 구성
- 포인터변수를 이용하기 위해서는 배열을 사용

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
		cout << "첫번째 정수 입력:"; cin >> n1;
		cout << "두번째 정수 입력:"; cin >> n2;
		cout << "세번째 정수 입력:"; cin >> n3;
		cout << "1.레퍼런스 변수 이용 2.포인터변수 이용\n>>>"; cin >> cho;
		switch (cho) {
		case 1:
			compare(n1, n2, n3, res1, res2);
			cout << "최댓값:" << res1 << endl;
			cout << "최솟값:" << res2 << endl;
			break;
		case 2:
			arr[0] = n1; arr[1] = n2; arr[2] = n3;
			compare(arr, &res1, &res2);
			cout << "최댓값:" << res1 << endl;
			cout << "최솟값:" << res2 << endl;
			break;
		}
}

	return 0;
}


//C언어 계열 메모리 구조
//1.코드영역
/*
- 컴파일 된 프로그램 소스가 기계어로 변환되어 저장되는 영역
- 컴파일 하면 함수들이 기계어로 변환된다.
*/

//2.data의 영역
/*
- 전역변수와 static 변수가 저장되는 영역
- 프로그램이 시작될 때 생성되고, 프로그램이 종료되면 소멸된다.
- 프로그래머가 생성 및 소멸 시기를 결정 할 수 없다.
*/

//3.heap의 영역
/*
- 동적할당 된 변수가 저장되는 영역
- 이름이 있는 변수를 생성 할 수 없다.
- 주소값으로 간접 접근이 가능하다.
- 포인터 변수를 이용해서 호출 할 수 있는 영역
- 프로그래머가 생성 및 소멸시기를 결정 할 수 있는 영역
- 한 번 동적할당한 공간은 소멸을 시키지 않으면 계속 유지된다.
*/

//4.stac의 영역
/*
- 지역변수,매개변수,포인터변수 같이 이름이 있는 변수를 저장하는 영역
- 함수가 시작될 때 생성되고, 함수가 종료되면 소멸된다.
- 프로그래머가 생성 및 소멸 시기를 결정 할 수 없다.
- 프로그램을 작성할 때 이미 생성 및 소멸 시기가 결정되어 있다.
*/
  

//2.data의 영역 예시 (전역변수, static변수)
/*#include<iostream>
using namespace std;
int a=100;		
//전역변수:함수 블록 안에 만들지 않고 외부에 만들어진다.
//		  초기화하지 않으면 0으로 자동초기화 된다.
//        모든 함수영역에서 사용 할 수 있는 변수
void func() {
	cout << a << endl;
	//함수내에 지역변수는 없지만(에러발생),에러가 없는 이유는 전역변수로 처리하기 때문이다.
	a += 100;
	//전역변수는 값이 변경되면 계속 유지 하게 된다.
}
void func1() {
	static int a = 0;
	//static 변수
	//함수 내에서만 사용이 가능.
	//다른 함수에서는 사용이 불가능
	cout << a << endl;
	a++;
}
int main() {
	int a=10;	//지역변수
	cout << a << endl;
	//지역변수 출력 - 함수 내에 사용되는 지역변수가 우선순위가 있다.
	func();
	func();
	func1(); func1(); func1(); func1(); func1();
}
*/

//3.heap의 영역 예시 (동적할당)
#include<iostream>
using namespace std;

int main() {
	int* su = (int*)malloc(sizeof(int));
	int* su1 = (int*)malloc(sizeof(int) * 4);
	// 동적할당생성
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