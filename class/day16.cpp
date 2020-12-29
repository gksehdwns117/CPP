// 문제 1. 상속을 이용하여 구현
// -부모클래스 : 사원 명부 - 이름 / 주민번호
// - 자식클래스1 : 정규직 - 사원 코드 / 기본급 / 수당
// ->사원코드 입출력 / 기본급 입출력 / 수당 입출력
// - 자식클래스2 : 임시직 - 일당 / 근무일수
// ->일당 입출력 / 근무일수 입출력
// 월급 계산 프로그램
#include<iostream>
using namespace std;
class Company {
	char* staff_name;
	int* front_num;
	int* back_num;
public:
	Company() {
		staff_name = new char[10];
		front_num = new int;
		back_num = new int;
	}
	~Company() {
		delete[] staff_name;
		delete front_num;
		delete back_num;
	}
	void set() {
		cout << "사원이름 : "; cin >> staff_name;
		cout << "주민번호 앞자리 : "; cin >> *front_num;
		cout << "주민번호 뒷자리 : "; cin >> *back_num;
	}
};
class full_Time : public Company {
	char code[5];
	int fee;
	int bonus;
public:
	void set() {
		cout << "회원코드 : "; cin >> code;
		cout << "기본급여 : "; cin >> fee;
		cout << "총  수당 : "; cin >> bonus;
	}
	void get() {
		cout << "================ 정규직 ================\n";
	}
};
class Part_Time : public Company {
	int day_fee;
	int day;
public:
	void set() {
		cout << "하루급여 : "; cin >> day_fee;
		cout << "한달일수 : "; cin >> day;
	}
};

오버라이딩
- 함수의 재정의 의미한다.
- 상속받은 자식 클래스에 부모 클래스의 멤버함수를 재정의 하는 것을 의미한다.
- 이미 사용하고 있는 클래스의 멤버함수를수정 할 경우 그 클래스를 건드리지 않고 변경하여 사용할 수 있다.

문제 2. 함수의 오버라이딩을 이용하여 구현
- 부모 클래스 : 이름 / 주소
- 자식 클래스 : 키 / 몸무게
- 부모 클래스 : 이름 / 주소 입출력
- 자식 : 이름 / 키 / 몸무게 입출력

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	char* addr;
public:
	Info1() {
		name = new char[10];
		addr = new char[30];
	}
	~Info1() {
		delete[]name;
		delete[]addr;
	}
	void set() {
		cout << "이름입력 : "; cin >> name;
		getchar();
		cout << "주소입력 : "; cin.get(addr, 30);
	}
	void get() {
		cout << "이름 : " << name << endl;
		cout << "주소 : " << addr << endl;
	}
};
class Info2 : public Info1 {

	double* hei;
	double* wei;
public:
	Info2() {
		hei = new double;
		wei = new double;
	}
	~Info2() {
		delete hei;
		delete wei;
	}
	void set() {
		cout << "이름  입력 : "; cin >> name;
		cout << "키     입력 : "; cin >> *hei;
		cout << "몸무게 입력 : "; cin >> *wei;
	}
	void get() {
		cout << "이름   : " << name << endl;
		cout << "키     : " << *hei << "cm" << endl;
		cout << "몸무게 : " << *wei << "kg" << endl;
	}
};
int main() {
	Info1 p1;
	p1.set();
	cout << "======================================" << endl;
	p1.get();
	cout << "======================================" << endl;
	Info2 p2;
	p2.set();
	cout << "======================================" << endl;
	p1.get();
	cout << "======================================" << endl;
	p2.get();
	cout << "======================================" << endl;
}
// 자식클래스에서 부모클래스의 멤버를 가져다가 새로 초기화하여도 부모클래스에는 영향을 주지 않는다.

포인터변수와 클래스
- 포인터변수의 자료형: 저장된 주소로부터 참조할 변수의 크기와 변수의 성격을 결정한다.
- 포인터변수는 모두 자료형의 주소값만을 저장하기 떄문에 사이즈는 무조건 4byte로 되어있다.

클래스 포인터
class A {
};
int main() {
	A* p = new A;
}
- 클래스 자료형에 의해서 그 클래스의 멤버에 접근이 가능하다.
- 클래스의 포인터변수 역시 클래스의 크기와 별개로 무조건 4byte이다.

문제 3. 클래스 포인터를 이용하여 구현
- 클래스 멤버변수 : 이름 / 나이
- 메인함수 : 클래스의 포인터변수 3개로 입력 출력

#include<iostream>
using namespace std;
class Info {
	char* name;
	int* age;
public:
	Info() {
		name = new char[10];
		age = new int;
	}
	~Info() {
		delete[]name;
		delete age;
	}
	void set() {
		cout << "이름입력 : "; cin >> name;
		cout << "나이입력 : "; cin >> *age;
	}
	void get() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << *age << " 살" << endl;
	}
};
int main() {
	Info* I = new Info;
	I->set();
	I->get();
}

포인터변수와 클래스 상속
- 클래스 자료형에 따라서 접근 할 수 있는 클래스의 범위가 정해져 있다.

1. 부모클래스 자료형 포인터변수에 부모 클래스 변수의 주소 저장
-> 부모클래스 멤버만 접근이 가능.
2. 부모클래스 자료형 포인터변수에 자식 클래스 변수의 주소 저장
-> 부모클래의 멤버만 접근이 가능.
3. 자식클래스 자료형 포인터변수에 자식클래스 변수의 주소 저장
-> 부모와 자식 클래서 멤버 접근이 가능.

#include <iostream>
using namespace std;
class A {
public:
	int a;
	void set() {
		cout << "a" << endl;
	}
};
class B : public A {
public:
	int b;
	void set() {
		cout << "b" << endl;
	}
};
int main() {
	A a1;
	B b1;
	A* pa = &a1;	//부모클래스 포인터변수에 부모클래스 변수의 주소저장.
	A* pb = &b1;	//부모클래스 포인터변수에 자식클래스 변수의 주소저장.
	B* pc = &b1;	//자식클래스 포인터변수에 자식클래스 변수의 주소저장
	
	pa->a = 10;
	pa->set();
	pb->a = 10;
	pb->set();
	//pb->b = 100;	//자식클래스의 멤버변수에 접근불가능.
	//pb->get();

}