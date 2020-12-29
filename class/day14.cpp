 문제 1. const 를 이용하여 구현
 - 학번 / 이름 을 저장하는 class 구현
 - 학번은 한번 결정되면 변경 불가능
 - 5명의 객체를 만들고 입력 및 출력

#include<iostream>
using namespace std;
class Student {
	const int cla_num;
	char *name;
public:
	Student(int n1) :cla_num(n1) {
		name = new char[10];
	};
	~Student() {
		delete[] name;
	}
	void set() {
		cout << "이름입력 : "; cin >> name;
	}
	void get() {
		cout << "학번 : " << cla_num << endl;
		cout << "이름 : " << name << endl;
		cout << "---------------------------------" << endl;
	}
};

int main() {
	//Student info1(20183131);
	//Student info2(20192020);
	//Student info3(20181111);
	//Student info4(20171111);
	//Student info5(20161111);
	//
	//info1.set(); info2.set(); info3.set(); info4.set(); info5.set();
	//info1.get(); info2.get(); info3.get(); info4.get(); info5.get();

	Student info[5] = { 20191111,20191112,20191113,20191114,20191115 };

	for (int i = 0; i < 5; i++) {
		info[i].set();
	}
	for (int i = 0; i < 5; i++) {
		info[i].get();
	}
}

멤버함수 상수화
- 클래스의 멤버함수를 상수화 시킬 수 있다.
- 멤버함수명 뒤에 const 를 붙여주면 된다.
- 원형이 같은 함수라도 const 를 붙이면 오버로딩이 되기 때문에 멤버함수를 선언할 경우
	함수 선언부와 함수 정의부 모두 const 를 붙여줘야 한다.
- const 멤버함수는 멤버변수의 값을 변경할 수 없다.
- const 멤버함수는 const 멤버함수만 호출이 가능하다.
- const 멤버함수는 멤버변수의 주소리턴이 불가능하다. -> 결과 자료형앞에 const 를 붙이면 리턴 할 수 있다.
- const 멤버함수는 주로 출력에서만 사용한다.
int func() const {} //일반적인 const 함수
const int func() const //리턴값을 주기 위한 const 함수

#include<iostream>
using namespace std;
class Test {
	const int a;
	char b;
	int c;
public:
	Test(int ia, char ib) :a(ia) {
		b = ib;
		c = 100;
	}
	void show() const {
		cout << a << " : " << b << endl;
		//c = 200;	//const함수는 멤버변수의 값을 변경 할 수 없다.
	}
};
int main() {
	Test t1(1, 'A');
	t1.show();
}

static 멤버의 특징
- 클래스에서 static 을 붙여 선언한 변수와 함수를 의미한다.
- 클래스 안에서 선언된 멤버지만 클래스의 멤버는 아니다.
- 독자적인 변수와 함수이다.
- static 멤버는 접근 지정자로 초기화를 해준다.(::)
- static 멤버는 프로그램 시작시에 메모리공간에 저장되고 프로그램이 종료되면 소멸된다.
- 객체 생성과는 상관없이 사용할 수 있다.
- static 변수는 모든 객체가 공유해서 사용 할 수 있다.
- static 멤버는 외부 정의시에는 선언부에만 static 을 사용한다.
- static 멤버함수는 static 멤버변수만 사용 할 수 있다.
- static 멤버변수의 초기화는 클래스의 멤버함수에서는 할 수 없다.
-> 객체 생성 이전에 메모리에 생성되는 static 변수를 초기화 할 수 없다.
- static 멤버변수는 자동으로 초기화 되지 않는다.
-> 무조건 초기화를 해 줘야 하는데 클래스 밖에서 해야 한다.

#include<iostream>
using namespace std;

void func() {
	static int a = 1;
	cout << a << endl;
	a++;
}
int main() {
	func();
	func();
	func();
	// cout<<a<<endl; -> static변수는 생성된 위치에서만 사용이 가능.
}


#include<iostream>
using namespace std;
class Point {
	int x, y;	//멤버변수
	static int cnt;	//static 변수
public:
	Point(int ix, int iy) :x(ix), y(iy) {};
	void output() const {
		cout << "x=" << x << " : " << "y=" << y << endl;
	}
	static void outcnt() {	//static 함수
		//cout << x << endl;
		//cout << y << endl;
		//-> static 함수는 static 변수만 사용이 가능.
		cout << "생성된 좌표의 수: " << cnt << endl;
		cnt++;
	}
	void get();	//클래서 멤버함수를 선언만 한 경우
};
int Point::cnt = 1;	//static 변수의 초기화
void Point::get() {
	output();
	outcnt();
}
int main() {
	Point p1(10,20);
	p1.get();
	Point p2(30, 40);
	p2.get();
	return 0;
}


 문제2.클래스를 이용하여 구현
 - 은행 클래스
 - 멤버변수 : 이름/은행아이디/잔액/이율
 - 멤버함수 : 생성자/get함수/소멸자
 - 객체 : 3개 생성 - 배열이 아닌 클래스 객체로 만들기

#include<iostream>
using namespace std;
class Bank {
	char* name;
	char* id;
	int *balance;
	static double f;
public:
	Bank() {
		name = new char[10];
		id = new char[10];
		balance = new int;
	}
	~Bank() {
		delete[] name;
		delete[] id;
		delete balance;
	}
	void get() {
		cout << "이름입력: "; cin >> name;
		cout << "아이디입력: "; cin >> id;
		cout << "잔액입력: "; cin >> *balance;
		cout << endl;

		cout << "이름: " << name << endl;
		cout << "아이디: " << id << endl;
		cout << "잔액: " << *balance << " 만원" << endl;
		cout << "이율: " << f << "%" << endl;
		cout << endl;
	}
};
double Bank::f = 0.9;
int main() {
	Bank user1;
	Bank user2;
	Bank user3;
	user1.get();
	user2.get();
	user3.get();

	return 0;

}
static 변수사용은 공동으로 변경 해야 하는 변수에 사용하면 편하다.

상속
- 위에서 아래로 어떤 권한이나 재산등을 물려 주는 행위
- 기존에 클래서에서 사용하던 기능이다 특성을 다른 클래스에게 물려줘서 새로운
  클래스를 만들어 사용하는 것이다.
- 상속의 개념이 없다면 기존의 클래스에 새로운 멤버함수나 멤버변수가 필요한 경우
  새롭게 다시 클래스를 정의해야 한다.
- 하지만, 이미 기존 클래스가 있다면 이 클래슬를 상속받아서 새로 클래스를 만들면
  기존의 코드는 그대로 사용하면서 새로운 내용만 추가하면 된다.
- 코드의 재활용 측면이나 개발기간 단축이라는 큰 효과를 얻을 수 있다.
- 상속을 사용하는 이유는 객체지향에서 중요시 하는 것 중에 하나인 요구사항에 따른
  프로그램의 유연성에 있다.
- 즉, 회사업무의 형태나 업무의 특성 등이 바뀌어서 프로그램 기능의 변경요구에 맞춰서
  필요한 기능을 추가 할 수 있다.
- 상속에서 생각 해야할 것은 작은기능을 큰 기능으로 발전시킬 것인지,
  큰 기능을 작은 기능으로 나눌 것인지 생각해야한다.

class Score {
protected:
	국,영,수
public:
	tot() {
		국+영+수
	}
	avg() {
		국 + 영 + 수 / 3.0;
	}
};
class Score1 : Score {

};

상속받는 방법
- class 자식클래스이름 : 접근지정자 부모클래스이름 {
	// 자식클래스정의
};

상속받은 클래스 사용 방법
- 상속으로 자식 클래스는 자식클래스와 부모 클래스를 하나로 결합한다.
- 자식 클래스로 객체 생성 후 사용하면 상속을 사용할 수 있다.
- 부모 클래스를 사용하는 것보다 자식 클래스를 사용한다.