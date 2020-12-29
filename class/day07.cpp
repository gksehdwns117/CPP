**** 문제1.동적할당 및 포인터 변수를 사용하여 구현 ****
- 정수 2개를 입력 받아서 두개의 값을 서로 변환
- 정수 2개를 입력 받아서 값을 나눈후 실수로 출력
- 정수 2개를 입력 받아서 값을 곱한 후 역순으로 출력

#include<iostream>
using namespace std;
void change(int *n1,int *n2) {
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void dou_ch(int *n1, int *n2) {
	
}
int main() {
	int su1, su2;
	cout << "su1의 입력:"; cin >> su1;
	cout << "su2의 입력:"; cin >> su2;

	change(&su1, &su2);
	cout << "--------바뀐 정수--------\nsu1:" << su1 << "  su2:" << su2 << endl;
	return 0;
}



//c++ 동적할당
자료형 포인터변수 = new 자료형;
int* pa = new int;
delete pa;

new와 delete 연산자
-c++에서는 동적 메모리 할당과 해제를 위해서는 new 와 delete 연산자를 사용한다.
-new: 동적 할당을 하고 할당된 변수의 주소를 리턴한다.
-delete: 동적 할당을 해제한다.


#include<iostream>
using namespace std;
int main() {
	int* pa = new int;
	char* pb = new char;
	double* pc = new double;
	char* pd = new char[10];

	*pa = 100;
	*pb = 'a';
	*pc = 1.1;
	strcpy(pd, "홍길동");
	cout << *pa << " : " << *pb << " : " << *pc << " : " << pd << endl;

	delete pa; delete pb; delete pc; delete[] pd;
}


포인터
- 메모리에 있는 data의 위치 주소값을 의미한다.
- 메모리에 저장하는 모든 data는 포인터를 갖고 있다.
- 즉, data는 저장하는 위치 주소값이 존재한다.
- 포인터는 기본적으로 변수 이름을 통해서 호출 하기 때문에 주소값을 잘 사용하지 않는다.
- 변수 이름으로 호출 할 경우 변수안에 있는 data를 사용하는 것을 의미한다.
- 동적할당을 사용한 포인터변수를 이용할 경우 data가 아닌 주소값으로 data를 호출한다.

포인터변수
- 일반적인 변수는 data를 저장할 수 있는 공간을 가지고 있다.
- 그러나 포인터변수는 data를 저장하는 위치 주소값을 저장하는 공간을 가지고 있다.
- 즉, 포인터변수는 위치 주소값을 저장하는 변수이다.
- 포인터변수는 값을 저장 할 수 없다.c++에서 값을 저장할 경우 에러가 발생한다.
- 사용하는 방식은 배열과 유사점을 가지고 있다.
- 포인터변수의 data는 data를 저장하는 시작 주소값을 의미한다.

//포인터변수의 특징
- 포인터변수를 만들때는 자료형 뒤 또는 변수 이름 앞에* 을 붙여야 한다.
- 포인터변수의 값은 오직 값의 위치 주소값만 저장 가능하다.
- data와 동일한 자료형으로 포인터변수를 만들어야 한다.
- 포인터 변수의 사이즈는 4byte 이다.
- 4byte = 8bit*4 =32bit  -> 32bit os에서 사용하는 메모리 위치 주소값
- 값을 참조할때는 포인터변수 앞에 *(역참조 연산자)을 붙여야 한다.
- 역참조는 포인터변수가 가지고 있는 위치 주소값의 값을 참조하도록 한다.

문제2. c++ 스타일의 동적할당을 이용하여 구현
- 포인터변수 3개 선언
- 동적할당 해서 값을 입력
- 최대값과 최소값을 출력
- 동적할당을 해제
#include<iostream>
using namespace std;
void compare(int n1, int n2,int n3) {
	int max, min;
	max = n1; min = n1;

	if (max < n2) {
		max = n2;
	}
	if (max < n3) {
		max = n3;
	}

	if (min > n2) {
		min = n2;
	}
	if (min > n3) {
		min = n3;
	}

	cout << "최댓값:" << max << endl;
	cout << "최솟값:" << min << endl;

}
int main() {
	int* pa1 = new int;
	int* pa2 = new int;
	int* pa3 = new int;

	cout << "첫번째 포인터변수 값:"; cin >> *pa1;
	cout << "두번째 포인터변수 값:"; cin >> *pa2;
	cout << "세번째 포인터변수 값:"; cin >> *pa3;

	compare(*pa1, *pa2, *pa3);

	delete(pa1);
	delete(pa2);
	delete(pa3);
}


구조체
- 단순구조(int,double,char),배열이라는 자료 구조를 학습.
- 배열>> 같은 자료형을 묶음으로 여러 데이터를 처리하는 자료 구조.
- 단순구조나 배열은 자료구조의 한계가 존재한다.
- 단순구조 : 자료를 하나만 저장 할 수 있다는 한계
- 배열: 여러개의 자료를 저장 할 수 있지만 같은 자료형이여야 한다는 한계
- 단순구조와 배열의 한계를 없애기 위해서 사용하는 자료구조가 구조체이다.
- 구조체는 프로그램에서 사용해야 하는 자료형을 하나로 묶어서 하나의 자료형으로 만드는 것을 의미한다.
- 다양한 자료구조 형태로 처리 할 수 있는 자료형이다.
- 구조체에서 자료형을 생성할때 사용하는 변수를 멤버변수 또는 필드라고 한다.

//구조체 형식
struct 구조체이름 {
	자료형 멤버변수1;
	자료형 멤버변수2;
	...;
};
- 자료형은 int, char, double, 배열, 다른 구조체도 가능하다.

구조체 선언
struct 구조체이름 구조체변수;

구조체 초기화
struct 구조체이름 구조체변수 = (멤버변수1값, 멤버변수2값, ....);

구조체 재정의
typedef struct 구조체이름 {
	자료형 멤버변수1;
	자료형 멤버변수2;
	...;
}; 별칭;(==struct 구조체이름)
별칭 구조체변수;

- 멤버변수를 표현할 때[구조체변수].[멤버변수이름] 으로 표현
- 구조체로 만든 포인터변수로 구조체 멤버에게 접근이 가능하다.
- 이 때는 간접접근연산자로 접근한다.
- 간접접근연산자로 접근 할때는 [구조체변수] -> [멤버변수]로 표현
- 구조체의 자료형은 data들을 집단 처리할 목적으로 사용한다.
- 구조체는 사용자 정의 자료형이다.

#include<iostream>
using namespace std;
struct st1 {
	int a;
	char b;
	double c;
	int d[3];
	char e[10];
};
int main() {
	struct st1 s1;
	s1.a = 10;
	s1.b = 'a';
	s1.c = 1.1;
	s1.d[0] = 100; s1.d[2] = 300; s1.d[1] = 200;
	strcpy(s1.e, "홍길동");
	cout << s1.a << endl;
	cout << s1.b << endl;
	cout << s1.c << endl;
	cout << s1.d[0] << endl;		//직접접근
	cout << s1.d[1] << endl;
	cout << s1.d[2] << endl;
	cout << s1.e << endl;
}

문제3. 구조체를 이용하여 구현
- 이름/ 국어/ 영어/ 수학/ 총점/ 평군을 가진 구조체 생성
- 3명의 성적을 입력하여 이름/ 총점 / 평균을 출력
#include<iostream>
#include<iomanip>
using namespace std;
struct st {
	char name[30];
	int kor;
	int eng;
	int math;
	int sum;
	double avr;
};
int main() {
	struct st grade;
	cout << "이름입력:"; cin >> grade.name;
	cout << "국어성적:"; cin >> grade.kor;
	cout << "영어성적:"; cin >> grade.eng;
	cout << "수학성적:"; cin >> grade.math;
	grade.sum = grade.kor + grade.eng + grade.math;
	grade.avr = (double)grade.sum / 3;

	cout << "-------------------------------" << endl;
	cout << "이름	:" << grade.name << endl;
	cout << "총점	:" << grade.sum << endl;
	cout << "평균	:" << setprecision(4) << grade.avr << endl;
	return 0;
}

