//문제1. 동적할당을 이용하여 구현
//- 이름 5개를 입력
//- 입력 / 출력 / 검색 / 삭제 기능 구현 *****

/*#include<iostream>
using namespace std;
void input(); void output(); void search(); void del();
int main() {
	char** name = new char*[5];
	for (int i = 0; i < 5; i++) {
		name[i] = new char[10];
	}
	// 동적할당 2차원배열 이용 ***
	while (1) {
		int cho;
		cout << "1.이름입력 2.이름출력 3.이름검색 4.이름삭제 0.종료"; cin >> cho;
		system("cls");
		if (cho == 1) {
			cout << "##### 5개의 이름 입력 #####" << endl;
			input(name);
		}
		else if (cho == 2) {
			output(name);
		}
		else if (cho == 3) {
			search(name);
		}
		else if (cho == 4) {
			del(name);
		}
	}
	return 0;
}
void input() {
	
}
*/
// string 자료형
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string* str = new string[5];

	str[0] = "홍길동";
	str[1] = "변학도";
	str[2] = "이몽룡";

	cout << str[0] << endl;
}
*/
//클래스
//- c에서는 사용하지 못하는 기능
//- c++에서 c와 대비되는 기능 중 가장 큰 특징이다.
//- 클래스는 하나의 완벽한 프로그램을 하나의 블록으로 묶어놓은 것을 의미한다.
//- 클래스를 만든다는 것은 프로그램을 만드는 것과 동일하다.
//- 프로그램에서 필요에 따라 여러 클래스를 조립하여 사용 한다.

//클래스의 특징
//1.캡슐화
//- 데이터와 함수를 하나의 블록으로 묶어놓은 것.
//- 멤버변수와 메소드를 통해서 프로그램 구현.
//2.정보은닉
//- 데이터를 보호하기 위해서 외부함수에 데이터를 공개하지 않는 것을 의미한다.
//- 직접적인 데이터를 보여 주지 않기 위해서 사용한다.
//- 클래스에 있는 변수를 외부에서 볼 수 없도록 처리한다.
//- 프로그램의 안정적인 구현과 보안에 관련되어 있다.
//3.다형성
//- 클래스에서 사용 할 수 있는 다양한 형태들이 있다.
//- 그런 다양한 형태를 사용하는 걸 다형성이라고 한다.
//- 가상함수 같은 형태가 있다.
//4.상속성
//- 클래스의 자료형이나 함수 변수를 물려받거나 물려주는 것을 의미한다.

//객체 지향 프로그램
//1.객체
//- 현실세계에 존재하는 모든 것을 의미한다.
//- 추상적인 것과 상세적인 부분도 포함된다.
//- 값과 행동도 포함된다.
//- 완전한 대상체 라는 의미도 포함된다.
//- 객체 프로그래밍에서는 루틴 및 데이터의 양쪽을 포함하는 개별적인 개체로서 취급하는 변수
//- 클래스를 이용해서 정의된 자료형의 변수 즉,클래스변수를 객체라고 한다.
//2.객체 지향 프로그램
//- 객체 위주로 프로그램을 작성한다는 의미를 가지게 된다.
//- 클래스 변수 위주로 프로그램을 작성한다는 의미이다.
//- 객체를 이용해서 프로그램을 작성하는 것을 객체 지향 프로그램이라고 한다.

//자료형의 발전
//- 단순구조(int,char,double) :  하나의 값을 저장 할 수 있다 -> 여러개의 값을 저장 할 수 없다. 
//- 배열 : 여러 개의 값을 저장 할 수 있다. -> 다른 자료형과 같이 묶을 수 없다.
//- 구조체 : 다른 자료형과 같이 묶을 수 있다. -> 함수를 포함하여 지정 할 수 없다.
//- 클래스 : 함수를 포함하여 다른 자료형과 같이 묶을 수 있다.

//클래스 형태
/*
#include<iostream>
using namespace std;
class Class {
	//클래스의 이름 첫글자 대문자 (관례)
	//다른 다언와 합쳐질때는 그 첫글자도 대문자 Web_Broser (관례)
public: // 접근 지정자( 접근 제한자 )
		// - 클래스에 접근 할 수 있는 함수를 알 수 있도록 지정.
		// - 누구나 접근이 가능
	int aa;
	char bb;
	double cc;
	//멤버 변수 또는 변수
	void set() {
		//입력함수
	}
	void get() {
		//출력함수
	}
};
int main() {
	Class cl1; //객체 - 클래스 변수
	cl1.set();
	cl1.get();
	cl1.aa;
	cl1.bb;
	cl1.cc;
	//객체호출
}
*/

/*#include<iostream>
using namespace std;
class Test {
public:
	int su;
	void set(){
		cout << "정수 입력:";
		cin >> su;
	}
	int get() {
		return su;
	}
};
int main() {
	Test t1;
	t1.set();
	cout << "t1.su:" <<t1.get() << endl;
	Test t2;
	t2.set();
	cout << "t2.su:" << t2.get() << endl;
}
*/

//문제2. 클래스로 구현
//- 멤버변수 : 이름 / 나이 / 주소
//- 3개의 클래스 변수를 만들고 입력 후 출력

/*#include<iostream>
using namespace std;
class Person {
public:
	char name[10];
	int age;
	char address[30];
	void set() {
		cout << "이름입력:"; cin >> name;
		cout << "나이입력:"; cin >> age;
		getchar();
		cout << "주소입력:"; cin.get(address, 30);
		cout << "--------------------------------------" << endl;
	}
	void get() {
		cout << "이름:" << name << endl;
		cout << "나이:" << age << endl;
		cout << "주소:" << address << endl;
		cout << "--------------------------------------\n" << endl;
	}
};
int main() {
	Person p1; 
	Person p2;
	Person p3;
	//Person p1,p2,p3;
	p1.set();
	p1.get();
	p2.set();
	p2.get();
	p3.set();
	p3.get();
	return 0;
}


클래스 변수명
- 멤버 변수를 대표하는 이름이 된다.
- 멤버 함수를 호출 할 수 있는 권한을 가진다.

클래스 구성
- Data + 함수 + 보안
- 멤버변수 + 멤버함수 + 접근지정자(제한자)

접근지정자(제한자)
:외부함수에서 클래스의 멤버들에게 접근허용 여부를 결정하는데 사용.
1.public
- 클래스 내부와 외부 함수에서 모두 접근 가능하다.
2.private
- 클래스 내부 함수에서만 접근 가능하다.
3.protected
- 클래스 내부 함수와 상속한 클래스에서 접근이 가능하다.
*/

#include<iostream>
using namespace std;

class AA {
public:
	int a;
	void set() {
		cout << "AA" << endl;
	}
};
class BB {
private:
	int b;
public:
	void set() {
		cin >> b;
	}
	void get() {
		cout << b << endl;
	}
};
class CC {
protected:
	int su;
};
class DD :CC {
public:
	void set() {
		cout << "정수입력:"; cin >> su;
	}
	void get() {
		cout << su << endl;
	}
};
int main() {
	AA a;
	a.a = 10;
	cout << a.a << endl;
	a.set();
	BB b;
	b.set();
	b.get();
	CC c;
	DD d;
	d.set();
	d.get();
	
}