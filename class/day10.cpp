문제1. 클래스를 이용하여 구현
- 이름/나이/주소 입력
- 이름/나이/주소 출력
- 저장할 수 있는 사람의 수는 5명


#include<iostream>
using namespace std;

class Person {
private:
	char name[10];
	int age;
	char address[30];
public:
	void set() {
		cout << "이름입력: "; cin >> name;
		cout << "나이입력: "; cin >> age;
		getchar();
		cout << "주소입력: "; cin.get(address, 30);
		cout << "-------------------------------" << endl;
	}
	void get() {
		cout << "이름:" << name << endl;
		cout << "나이:" << age << endl;
		cout << "주소:" << address << endl;
		cout << endl;
	}
};
int main() {
	class Person p[5];
	int i = 0;

	for (i = 0; i < 5; i++) {
		p[i].set();
		system("pause");
		system("cls");
	}
	
	for (i = 0; i < 5; i++) {
		p[i].get();
	}
	return 0;
}


멤버변수에 접근하는 형태
1. 일반변수 형태
class Test {
public:
	int a;
};
int main() {
	Test tt;	//클래스 변수 선언
	tt.a = 10;	//값 초기화1
	tt.a(10)	//값 초기화2
}
2. 포인터변수 형태
class Test {
public:
	int a;

};
int main() {
	Test tt;		//클래스 변수선언
	Test* pt = &tt;	//클래스 변수의 포인터변수
	pt->a = 10;		//값 초기화
}
3. 동적할당 형태
class Test {
public:
	int a;

};
int main() {
	Test* tt = new Test;		//클래스 변수의 포인터변수로 선언
	tt->a = 10;					//값 초기화
	delete(tt);					//동적할당된 값 삭제
}

문제2.
1.클래스를 이용해서 구현
2.private 을 이용해서 구현
- 클래스 멤버변수 : int start, end;
- start 시작 정수/ end 끝 정수
- start(시작하는 단) / end(끝나는 단)
- 구구단 출력

#include<iostream>
using namespace std;

class Table {
private:
	int start;
	int end;
	int i,k;
public:
	void set() {
		cout << "시작하는 단 입력:"; cin >> start;
		cout << "끝나는 단 입력:"; cin >> end;
	}
	void get() {
		for (i = 1; i <= 9; i++) {
			for (k = start; k <= end; k++) {
				cout << k << "*" << i << "=" << i * k << "\t";
			}
			cout << endl;
		}
	}
};
int main() {
	class Table multi;
	cout << "##### 구구단 시작 ######" << endl;
	multi.set();
	system("cls");
	multi.get();
	return 0;
}


this
- 멤버함수를 호출한 객체의 주소를 저장하는 멤버함수는 모든 객체가 공유한다.
- 즉, 멤버함수는 객체별로 따로 저장되지 않고 모든 객체가 공유한다.
- 멤버함수는 호출시에 어떤 객체가 호출 했는지 구분하기 위해 0번째 매개변수를 만든다.
- 0번째 매개변수란 자동으로 생성되어 보내지는 변수를 의미한다.
- 그 매개변수를 통해서 그 객체의 주소(값이 저장된 위치)를 전달받는다.
- 그래서 그 주소를 통해서 객체의 멤버변수에 값을 저장 할 수 있다.*/

this 형식
- 클래스명 *this
- 암묵적으로 this 포인터변수가 존재하므로 this 포인터변수를 매개변수로 사용하면 에러가 발생한다.
- 즉, 오픈시키는 매개변수가 아니라는 의미도 가지고 있다.
- 경우에 따라서는 오픈 시켜야 하는 경우도 있다.

**객체 생성시 멤버변수는 stack영역에 선언한 객체의 수만큼 생긴다.
**그렇지만 멤버함수는 code영역에 한개만 생성되고 모든 객체에 공유된다.

#include<iostream>
using namespace std;

class Test {
public:
	int a;
	void set() {
		cout << this << endl;
		cout << "set" << endl;
	}
	void get() {
		cout << "get" << endl;
	}
};
int main() {
	Test aa;		//aa라는 객체생성
	Test bb;		//bb라는 객체생성
	aa.a = 10;		//aa.a라는 변수를 저장 공간 생성
	bb.a = 20;		//bb.b라는 변수를 저장 공간 생성
	aa.set(); aa.get(); //aa와 bb는 함수를 공동으로 공유
	bb.set(); bb.get();
	return 0;
}


#include<iostream>
using namespace std;

class Test {
private:		// private은 생략해도 된다.
	int a;
	char b;
public:
	void set(int a1,char b1) {
		a = a1;	//this->a=a1;
		b = b1;
	}
	void set() {
		cout << "정수입력:";
		cin >> a;
		cout << "문자입력";
		cin >> b;
	}
	void get() {
		cout << a << ":" << b << endl;
	}
};
int main() {
	Test aa;
	Test bb;
	aa.set(10, 'a');
	aa.get();
	aa.set();
	aa.get();
}


문제3. this 이용하여 대입
- 멤버변수 : 학번/이름
- 멤버함수 : 입력/출력
- 객체 2개 생성 해서 입출력
#include<iostream>
using namespace std;
class student {
	int num;
	char name[10];
public:
	void set(int _num,char _name[10]) {
		num = _num;
		strcpy(name, _name);
		cout << this << endl;
		cout << endl;
	}
	void get() {
		cout << "학번:" << num << endl;
		cout << "이름:" << name << endl;
		cout << this << endl;
		cout << endl;
	}
};
int main() {
	student s1;
	student s2;
	int n;
	char str[10];
	cout << "학번입력:"; cin >> n;
	cout << "이름입력:"; cin >> str;
	s1.set(n, str);
	s1.get();
	cout << "학번입력:"; cin >> n;
	cout << "이름입력:"; cin >> str;
	s2.set(n, str);
	s2.get();
}

생성자
- 객체가 생성되는 시점에서 자동으로 호출되는 멤버함수
- 생성자 함수가 사용되는 목적은 멤버변수를 초기화 하는데 있다.
- set()함수에 의한 멤버변수의 초기화는 생성자가 실행된 후에 실행되는 초기화
- 생성자를 통한 초기화는 객체가 생성될때 자동으로 할당된다.
#include<iostream>
using namespace std;

class Test {
	int a;
public:
	Test() {
		a = 1000;
		//default 생성자
	}
	Test(int _a) {		//생성자도 오버로딩이 가능하다.
		a = _a;
	}
	void set(int _a) {
		a = _a;
	}
	void get() {
		cout << a << endl;
	}
};
int main() {
	Test test(10000000);
	//생성자는 처음 만들어질때 호출 가능하고, 나중에는 set()함수를 호출하여 값을 변경해야한다.
	test.get();
	test.set(10);
	test.get();

}