문제1. 다중 상속을 이용하여 구현
- 클래스1 : 이름 / 나이 / 주소
- 클래스2 : 전공점수 / 비전공점수 / 총점 / 평균
- 클래스3 : 학년 / 학번 / 전공
- 클래스4 : 동아리명 / 동아리활동

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	int age;
	char* addr;
public:
	Info1() {
		name = new char[10];
		addr = new char[20];
	}
	~Info1() {
		delete[] name;
		delete[]addr;
	}
	void set() {
		cout << "이름입력 : "; cin >> name;
		cout << "나이입력 : "; cin >> age;
		getchar();
		cout << "주소입력 : "; cin.get(addr, 20);
	}
	void get() {
		cout << "이름 : " << name << endl;
		cout << "나이 :" << age << endl;
		cout << "주소 : " << addr << endl;
	}
};
class Info2 {
	int n_major;
	int major;
	double avr;
public:
	void set() {
		cout << "전공과목 점수 입력   : "; cin >> major;
		cout << "비전공과목 점수 입력 : "; cin >> n_major;
	}
	void get() {
		cout << "전공과목 점수   : " << major << endl;
		cout << "비전공과목 점수 : " << n_major << endl;;
		avr = (double)(major + n_major) / 3;
		cout << "------------------------------------------" << endl;
		cout << "평균점수 : " << avr;
	}
};
class Info3 {
	int grade;
	int sch_num;
	char *sch_major;
public:
	Info3() {
		sch_major = new char[30];
	}
	~Info3() {
		delete[] sch_major;
	}
	void set() {
	Info1:set();
	Info2:set();
		cout << "학년입력 : "; cin >> grade;
		cout << "학번입력 : "; cin >> sch_num;
		cout << "전공입력 : "; cin >> sch_major;
	}
	void get() {
	Info1:get();
	Info2:get();
		cout << "학년 : " << grade << endl;
		cout << "학번 : " << sch_num << endl;
		cout << "전공 : " << sch_major << endl;
	}
};
class Info4 {
	char* cir;
	char* cir_do;
public:
	Info4() {
		cir = new char[10];
		cir_do = new char[100];
	}
	~Info4() {
		delete[] cir;
		delete[] cir_do;
	}
	void set() {
		cout << "동아리명 입력 : "; cin >> cir;
		getchar();
		cout << "동아리 주요 활동 입력 : "; cin.get(cir_do, 100);
	}
	void get() {
		cout << "동아리명 : " << cir << endl;
		cout << "-> '" << cir_do << ".'" << endl;
	}
};

가상함수 - 다형성
- 가상함수는 virtual 이라는 키워드를 사용해서 만든다.
- 부모클래스에서는 선언만 하고, 자식클래스에서 정의되는 함수
- 동적할당에 의해서 처리된다.


#include<iostream>
using namespace std;
class P {
public:
	void get1() {
		cout << "부모클래스..." << endl;
	}
};
class C :public P {
public:
	void get2() {
		cout << "자식클래스..." << endl;
	}
};

//오버로딩 : 매개변수가 다르면 함수의 이름이 같아도 된다.
int main() {
	P* pa = new P;
	pa->get1();
	//pa->get2();   >>> 자식클래스 접근 불가능 
	P* pb = new C;
	C* pc = new C;
//오버라이딩 :
}

#include<iostream>
using namespace std;
class Test {
protected:
	int a;
	int b;
public:
	void set() {
		cout << "a값입력:"; cin >> a;
		cout << "b값입력:"; cin >> b;
	}
	//void get() {
	//	cout << "a가가진수 : " << a << endl;
	//	cout << "b가가진수 : " << b << endl;
	//}
	virtual void get() {};
};
class child1 :public Test {
public:
	void get() {
		cout << "총점 : " << a+b << endl;
	}
};
class child2 :public Test {
public:
	void get() {
		cout << "평균 : " << (a+b)/2 << endl;
	}
};
int main() {
	Test t1;
	t1.set(); t1.get();
	Test* pt1 = new child1;
	pt1->set();
	pt1->get();
	Test* pt2 = new child2;
	pt2->set();
	pt2->get();
}


문제2. 가상함수를 이용하여 구현
-클래스1 : 정수형1개
-클래스2 : 정수형 값 만큼 *를 찍기
-클래스3 : 정수형 값 만큼의 합을 출력

#include<iostream>
using namespace std;
class Num {
protected:
	int a;
public:
	void set() {
		cout << "정수입력 : "; cin >> a;
	}
	virtual void get(){}
};
class Star :public Num {
public:
	void get() {
		for (int i = 0; i < a; i++) {
			for (int k = 1; k <= i + 1; k++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};
class Sum :public Num {
	int sum;
public:
	void get() {
		sum = 0;
		for (int i = 1; i <= a; i++) {
			sum += i;
		}
		cout << "1 ~ " << a << "까지의 합 : " << sum << endl;
	}
};
int main() {
	Num* t1 = new Star;
	t1->set();
	t1->get();
	Num* t2 = new Sum;
	t2->set();
	t2->get();
}
- 부모클래스 포인터변수로 객체 생성 한 후 사용한다.
- **부모클래스 포인터변수가 자식클래스를 사용 할 수 있는 두가지 조건
1.자식클래스의 함수가 부모클래스에도 존재해야한다.
2.부모클래스의 함수의 자식 함수 앞에는 virtual (가상함수 키워드) 를 붙여야한다.

다형성
- 상속된 클래스를 동적 할당해서 사용할 때 부모클래스로 자식클래스를 제어하는 것을 의미한다.
- 부모클래스로 포인터변수를 만들고 동적할당은 자식클래스로 하면 부모클래스로 자식클래스를 제어할수있다.

가상함수
- virtual 키워드를 붙여서 정의된 함수는 런타임시 포인터가 가리키는 타입에 따라 호출 함수를 결정하게된다.
- 포인터가 어떤 객체를 가리키고 있는지에 따라서 호출 된 함수를 결정하고 실행한다.
- 따라서 이를 통해서 다형성을 구현할 수 있다.