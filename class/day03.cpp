#include<iostream>
int main() {
	char name[10];
	int age;
	char address[100];
	char blood_type[10];

	std::cout << "이름입력:";
	std::cin >> name;
	
	std::cout << "나이입력:";
	std::cin >> age;
	
	std::cout << "주소입력:";
	std::cin >> address;
	
	std::cout << "혈액형입력:";
	std::cin >> blood_type;
	
	std::cout << "=====================" << std::endl;
	std::cout << "이름	:" << name << std::endl;
	std::cout << "나이	:" << age << std::endl;
	std::cout << "주소	:" << address << std::endl;
	std::cout << "혈액형	:" << blood_type << std::endl;

	std::cout << "나이입력:";
	std::cin >> age;
	getchar();					//getchar()은 엔터를 임시저장
	std::cout << "주소입력:";	
	std::cin.get(address, 50);	//cin.get(변수명,문자열길이) : 스페이스를 하나의 문자로 취급, 엔터는 종료를 의미
								//cin     >> 남아 있는 입력 버퍼를 버리고 저장.
								//cin.get >> 남아 있는 입력 버퍼를 그대로 저장.
	return 0;
}
cin
a>>1
\n(무시) b>>2
\n(무시) c>>3

cin.get()
a>>1
\n b>>\n
c=>2

namespace
-프로그램을 혼자서 할 수 없는 경우, 구역을 나눠서 개발한다.
-이때,같은 이름의 함수와 변수명을 사용 할 수 있기 때문에 개발에 오류가 생긴다.
-따라서,구역을 나누어서 함수나 변수를 구분 할 수 있도록 한다.
-namespace는 구역을 나누기 때문에 사용하는 이름 그대로 사용이 가능하다.

#include<iostream>
namespace test1 {
void input() {
		std::cout << "test1 실행\n";
		//test2:output();
}
	void output() {
		std::cout << "test1 output()\n";
	}
}
using test1::output;						//using namespace명 :: 함수명 >> 앞으로 쓰는 코딩에서
											//네임스페이스명을 생략할 수 있다.
namespace test2 {
	void input(){
		std::cout << "test2 실행\n";
		output();							//test1:output()에서 네임스페이스명인 test1을 생략 할 수 있음.
	}
	void output() {
		std::cout << "test2 output()\n";
	}
}
int main() {
	test1::input();
	test2::input();
}

#include<iostream>
using namespace std;			//입출력 cout,cin의 namespace
namespace pm{
	int p(int n1,int n2) {
		return n1 + n2;
	}
	int m(int n1, int n2) {
		if (n1 >= n2) {
			return n1 - n2;
		}
		else {
			return n2 - n1;
		}
	}
}
namespace md {
	int m(int n1, int n2) {
		return n1 * n2;
	}
	int d(int n1, int n2) {
		return n1 / n2;
	}
}
using namespace pm;
//using pm::m;
using md::d;
//using md::m;
int main() {
	int a = 10, b = 2;
	int res = 0;
	
	res = p(a, b);
	cout << "두 정수의 합:" << res << std::endl;
	res = pm::m(a, b);
	cout << "두 정수의 차:" << res << std::endl;
	res = md::m(a, b);
	cout << "두 정수의 곱:" << res << std::endl;
	res = d(a, b);
	cout << "두 정수의 몫:" << res << std::endl;

	return 0;
}

cast 연산자
- 명시적인 형변환 할 때 사용하는 연산자
- 프로그래머가 변환하고자 하는 자료형을 명시함으로써 자료형을 변환.
#include<iostream>
using namespace std;
int main() {
	int a = 65;
	cout << a << endl;
	cout << (char)a << endl;
	cout << (double)a << endl;

	char c = 'A';
	cout << c << endl;
	cout << (int)c << endl;
	cout << (double)c << endl;
}

예제3>cast연산자 사용하여 구현
	   정수 3개를 입력하고 그 평균을 출력
#include<iostream>
using namespace std;
int main() {
	int n1, n2, n3;
	int sum = 0;
	double avr;
	cout << "정수입력:"; cin >> n1;
	cout << "정수입력:"; cin >> n2;
	cout << "정수입력:"; cin >> n3;
	sum = n1 + n2 + n3;
	avr = (double)sum / 3;

	cout << "3개의 정수 평균:" << avr << endl;

	return 0;
}

//조정문자
//-화면에 출력되는 내용을 변경시키거나 추가하는 기능
//-공간확보 / 공간채우기 / 진법변환
#include<iostream>
#include<iomanip>
//iomanip : 조정문자에 대한 함수를 가지고 있음.
using namespace std;
int main() {
	int a = 100; int b = 200;
	cout << a << endl;
	cout << setw(10) << a << endl;
	//setw(n) : n칸만큼 공간을 확보하고 오른쪽정렬. (한번 설정이 사용되면 종료)
	cout << a << endl; 
	cout << setw(10) <<setfill('a') << a << endl;
	//setfill(문자) : 공백에 문자를 채운다.(한번 설정이 되면 계속 유지)
	cout << setw(10) << a << endl;
	cout << setfill(' ');
	//setfill(공백문자) - setfill을 다시 초기화
	cout << setw(10) << a << endl;
	//cout << b << endl;
	//cout << setw(10) << b << endl;

	cout << setprecision(3) << a << endl;
	double c = 5.6789;
	//setprecision(n) : 숫자만큼 숫자를 출력 (정수는 그대로 ,실수는 n갯수만큼 남기고 소수점밑에는 버림.)
	cout << setprecision(3) << c << endl;
	cout << c << endl;
	c = 5678.123;
	cout << c << endl;
	cout << setprecision(NULL);
	cout << c << endl;
	cout << setbase(8) << a << endl;
	//setbase는(진수):진수 변환 -한번 설정하면 유지. >>2진수변화는 안됨.
	cout << a << endl;
	cout << setbase(2) << a << endl;
	cout << a << endl;
	cout << setbase(16) << a << endl;
	cout << a << endl;
	cout << setbase(10) << a << endl;
	cout << a << endl;

}