문제1.
이름,국어,영어,수학 성적을 입력
총점,평균을 계산
이름,총점,평균 출력
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	char name[30];
	int kor, eng, math;
	int sum = 0;
	double avr;
	cout << "이름:";
	cin >> name;
	cout << "국어 성적:";
	cin >> kor;	
	cout << "영어 성적:";
	cin >> eng;
	cout << "수학 성적:";
	cin >> math;

	sum = kor + eng + math;
	avr = (double)sum / 3;
	cout << "==========================================\n";
	cout << "이름:" << name << "\n총점:" << sum << "\n평균:" << setprecision(4) << avr << endl;
}


함수의 오버로딩
- c언어 같은 경우 같은 이름의 함수를 사용 할 수가 없다.
- c++에서는 함수의 오버로딩이라고 해서 같은 이름의 함수를 사용 할 수 있다.
- 단, 호출 할때의 사용 할 매개변수의 차이로 구분 될 수 있다.
- 매개변수의 갯수 및 자료형이 다르면 사용이 가능하다.
#include<iostream>
using namespace std;
void output() {
	cout << "output() 실행" << endl;
}
void output(int a) {
	cout << "output(int a) 실행" << endl;
}
void output(int a, int b) {
	cout << "output(int a,int b) 실행" << endl;
}
void output(char a) {
	cout << "output(char a) 실행" << endl;
}
void output(char a,char b) {
	cout << "output(char a,char b) 실행" << endl;
}
void output(int a, char b) {
	cout << "output(int a,char b) 실행" << endl;
}
void output(char a, int b) {
	cout << "output(char a,int b) 실행" << endl;
}
int main() {
	output();
	output(10);
	output(20, 30);
	output('a');
	output('a', 'b');
	output(10, 'b');
	output('a', 20);
}


문제2. 함수의 오버로딩 사용
1. 1~10까지의 합이 출력
2. 1~n 까지의 합이 출력
3. n~m 까지의 합이 출력
#include<iostream>
using namespace std;
void sum() {
	int i;
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	cout << "1~10까지의 합 :" << sum << endl;
}
void sum(int n) {
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	cout << "1~"<< n << "까지의 합 :" << sum << endl;
}
void sum(int m,int n) {
	int i;
	int sum = 0;
	for (i = m; i <= n; i++) {
		sum += i;
	}
	cout << m << "~" << n << "까지의 합 :" << sum << endl;
}
int main() {
	int a, b;
	cout << "시작값 입력:";
	cin >> a;
	cout << "끝값 입력:";
	cin >> b;

	sum();
	sum(b);
	sum(a, b);
	return 0;
}


디폴트 매개변수
- 매개변수의 기본값을 지정 할 수 있다.
- 매개변수에게 값을 전달하지 않으면 기본값을 사용한다.
- 디폴트 매개변수를 사용하면 매개변수 없는 함수의 오버로딩이 불가능하다.
#include<iostream>
using namespace std;
void func(int a=1000) {
	cout << a << endl;
}
void func() {
	cout << "func()" << endl;
}
void func(int a = 1000, int b = 2000) {
	cout << a << ":" << b << endl;
}
int main() {
	//func(10);		// ->매개변수에 10을 복사해서 사용
	//func();		// ->매개변수의 기본값을 사용
	func(100, 200); // ->기본값이 두개일 때
	func(200);		// ->뒤에값만 생략이가능.
	func();			// ->모두 생략.
}


문제3. 디폴트 매개변수를 이용하여 구현
1. 일당 기본값: 10만원
2. 한달 일한 일수: 20일
3. 일당/일수 입력 - 월급
4. 일당만 입력-월급
5. 일수만 입력-월급
6. 일당/일수 입력X
#include<iostream>
using namespace std;
int salary(int sal_d = 10, int day = 20) {
	return sal_d * day;
}
int main() {
	int sal_d = 0, sal_m = 0, day = 0;
	int cho = 0;
	while(1){
		cout << "1.일당/일수 입력 2.일당만 입력 3.일수만 입력 4.기본금\n(일수-20일기준,일당-10만원 기준)\n";
		cout << ">>>"; cin >> cho;
		switch (cho) {
		case 1:
			cout << "하루 일당입력:"; cin >> sal_d;
			cout << "한달 일수입력:"; cin >> day;
			sal_m = salary(sal_d, day);
			cout << "한달 월급:" << sal_m << "만원" << endl;
			break;
		case 2:
			cout << "하루 일당입력:"; cin >> sal_d;
			sal_m = salary(sal_d);
			cout << "한달 월급:" << sal_m << "만원" << endl;
			break;
		case 3:
			cout << "한달 일수입력:"; cin >> day;
			sal_m = salary(10, day);
			cout << "한달 월급:" << sal_m << "만원" << endl;
			break;

		case 4:
			sal_m = salary();
			cout << "한달 월급:" << sal_m << "만원" << endl;
			break;
		}
	}
}


문제4. 함수의 오버로딩 사용
- 이름을 입력 받아서 리턴 함수
- 나이를 입력 받아서 리턴 함수
- 키를   입력 받아서 리턴 함수
#include<iostream>
using namespace std;

void input(int *su) {
	cout << "나이 입력:"; cin >> *su;
}
void input(double *su) {
	cout << "키  입력:";  cin >> *su;
}
void input(char *su) {
	cout << "이름 입력:"; cin >> *su;
}
void output(int a, double b, char *c) {
	cout << "이름:" << *c << "\n나이:" << a << "\n키:" << b << "cm\n";
}
int main() {
	int age = 0;
	double cm = 0.0;
	char name[10];

	input(&age);
	input(&cm);
	input(name);
	output(age, cm, name);
	return 0;
}


//매크로
//- 자주 사용하는 연산 또는 값을 고정 시킬 때 사용한다.
//- 자료형의 구분이 없다.
//- 복잡한 내용으로 정의 할 수 없다.
#include<iostream>
#define MAX 100
#define MIN 0
#define spa(x) x*x
using namespace std;
int main() {
	cout << MAX << endl;
	cout << MIN << endl;
	cout << spa(3);
	cout << endl;
	cout << spa(1.1); cout << endl;
	cout << spa('A'); cout << endl;
}