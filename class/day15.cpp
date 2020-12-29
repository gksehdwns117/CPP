 문제1. 클래스를 이용하여 구현
 - 첫번째 클래스 : 이름 / 학년
 - 두번째 클래스 : 이름 / 학년 / 나이 / 주소
 - 첫번째 클래스 : 2개 입력 및 출력 함수
 - 두번째 클래스 : 2개 입력 및 출력 함수

#include<iostream>
using namespace std;

class Student1 {
protected:
	char *name;
	int *grade;
public:
	Student1() {
		name = new char[10];
		grade = new int;
	}
	~Student1() {
		delete[]name;
		delete grade;
	}
	void set1() {
		cout << "이름입력 : "; cin >> name;
		cout << "학년입력 : "; cin >> *grade;
	}
	void get1() {
		cout << "이름 : " << name << endl;
		cout << "학년 : " << *grade << "학년" << endl;
	}
};
class Student2 : public Student1 {
	int *age;
	char *addr;
public:
	Student2(){
		age = new int;
		addr = new char[30];
	}
	~Student2() {
		delete age;
		delete[]addr;
	}
	void set2() {
		cout << "나이입력 : "; cin >> *age;
		getchar();
		cout << "주소입력 : "; cin.get(addr, 30);
	}
	void get2() {
		cout << "나이 : " << *age << "살" << endl;
		cout << "학년 : " << addr << endl;
	}
};
int main() {
	Student1 info1;
	Student2 info2;
	info1.set1();
	cout << "------------------" << endl;
	info1.get1();
	cout << "------------------" << endl;
	info2.set1();
	info2.set2();
	cout << "------------------" << endl;
	info2.get1();
	info2.get2();
	cout << "------------------" << endl;
}


상속에서 생성자의 호출 순서
class A {
public:
	A();
};
class B : public A {
public:
	B();
};
int main() {
	B b;
	// 호출은 B클래스를 먼저 호출하고, A를 호출한다.
	// 실행은 A클래스를 먼저 실행하고, B를 실행한다.
}
- B 클래스의 생성자가 호출된 이후 A 클래스의 생성자가 콜론의 초기화로 호출 된다.
- A 클래스의 생성자가 실행된 이후 다시 B클래스의 생성자로 돌아와서 실행된다.

//상속에서 소멸자의 호출 순서
class A {
public:
	A();
	~A();
};
class B : public A {
public:
	B();
	~B();
};
int main() {
	B b;
	// ~B()가 실행되고, ~A()가 실행됨.
}
- 객체가 소멸시에는 소멸자가 자식 클래스의 소멸자가 실행된 후, 부모 클래스의 소멸자가 실행된다.
- stack 개념이라서 나중에 만들어진 것을 먼저 소멸한다.


#include<iostream>
using namespace std;

class A {
protected:
	A(){
		cout << "A()의 생성자" << endl;
	}
	~A() {
		cout << "A()의 소멸자" << endl;
	}
};
class B : public A {
public:
	B() {
		cout << "B()의 생성자" << endl;
	}
	~B() {
		cout << "B()의 소멸자" << endl;
	}
};
int main() {
	B b;
}


문제2. 상속을 이용하여 구현
- 부모클래스 : 이름 / 총점 / 평균
- 자식클래스 : 국어 / 영어 / 수학
- 자식클래스 객체를 생성 후 이름 / 총점 / 평균을 출력

#include<iostream>
using namespace std;
class Stu_Info {
protected:
	char* name;
	int* sum;
	double *avr;
public:
	Stu_Info() {
		name = new char[10];
		sum = new int;
		avr = new double;
	}
	~Stu_Info() {
		delete[] name;
		delete sum;
		delete avr;
	}
	void set_name() {
		cout << "이름 : "; cin >> name;
	}
};
class Subject : public Stu_Info {
	int *kor;
	int *eng;
	int *math;
public:
	Subject() {
		kor = new int;
		eng = new int;
		math = new int;
	}
	~Subject() {
		delete kor;
		delete eng;
		delete math;
	}
	void set() {
		//cout << "이름 : "; cin >> name;
		cout << "국어 : "; cin >> *kor;
		cout << "영어 : "; cin >> *eng;
		cout << "수학 : "; cin >> *math;
	}
	void get() {
		cout << "이름 : " << name << endl;
		cout << "----------------------------------------" << endl;
		cout << "국어 : " << *kor << endl;
		cout << "영어 : " << *eng << endl;
		cout << "수학 : " << *math << endl;
		*sum = *kor + *eng + *math;
		*avr = (double)*sum / 3;
		cout << "총점 : " << *sum << endl;
		cout << "평균 : " << *avr << endl;
	}
};
int main() {
	Subject stu;
	stu.set_name();
	cout << "--------------- 성적입력 ---------------" << endl;
	stu.set();
	stu.get();
	return 0;
}
상속은 멤버변수 뿐만 아니라 멤버함수도 상속된다.


#include<iostream>
using namespace std;
class Test1 {
protected:
	int a;
	char* n;
public:
	Test1(int ia,char*in) {
		a = ia;
		n = new char[10];
		strcpy(n, in);
	}
	~Test1() {
		delete[]n;
	}
};
class Test2 :public Test1 {
	int b;
public:
	Test2(int ia,char *in,int ib):Test1(ia,in) {
		//콜론의 초기화를 통해서 부모클래스의 생성자 호출
		//만약 부모클래스의 매개변수를 주지 않으면 default 생성자가 호출된다.
		b = ib;
	}
	void get() {
		cout << "a:" << a << endl;
		cout << "n:" << n << endl;
		cout << "b:" << b << endl;
	}
};
int main() {
	Test2 t1(10,"홍",20)
}

// 자식클래스 함수에서 부모클래스 함수를 호출할때, (::)을 사용하여 호출한다.
// ex> Test1::set();  부모클래스(Test1)의 함수(set)을 호출


