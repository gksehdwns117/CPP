문제1.생성자, 소멸자를 이용하여 동적할당으로 구현
- 입력 / 출력 / 종료 함수
- 이름과 나이 입력
- 이름과 나이 출력
- 총 저장 공간은 5개
- 한꺼번에 입력 출력 아닌 입력하고자 할 때 입력 출력하고자 할 때 출력 되도록 할 것.

#include<iostream>
using namespace std;
class Person {
private:
	char* name;
	int* age;
public:
	Person() {
		name = new char[10];
		age = new int;
	}
	void set() {
		cout << "이름입력 : "; cin >> name;
		cout << "나이입력 : "; cin >> *age;
	}
	void get() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << *age << endl;
	}
	~Person() {
		delete[]name;
		delete(age);
	}
};
int main() {
	Person info[5];
	int cho = 0;
	int cnt = 0;
	while (1) {
		cout << "1.입력 2.출력 3.종료\n>>>"; cin >> cho;
		if (cho == 1) {
			info[cnt].set();
			cnt += 1;
		}
		else if (cho == 2) {
			for (int i = 0; i < cnt; i++) {
				info[i].get();
			}
		}
		else if (cho == 3) {
			for (int i = 0; i < cnt; i++) {
				info[i].~Person();
			}
			break;
		}
	}
	return 0;
}


복사 생성자
- 매개변수가 클래스 레퍼런스 변수인 생성자
- 객체를 동일한 객체로 초기화 할 때 자동으로 호출되는 멤버함수
- 사용자가 만들지 않으면 default 복사 생성자가 컴파일에 의해 자동으로 호출된다.
클래스명(클래스명& 변수명) {

}
Test(Test& r) {

}

복사 생성자 특징
- 클래스 레퍼런스형을 인자로 갖는 생성자를 복사 생성자라고 한다.
- 복사 생성자는 생성자의 한 종류로 복사의 방법으로 객체를 초기화 한다.
- 복사 생성자가 호출되는 경우
1> 객체로 객체를 초기화 할때 자동으로 호출 된다.
2> 함수를 값에 의한 호출을 하면서 객체를 함수의 매개변수로 전달할때 자동으로 호출된다.
3> 함수에서 객체를 리턴하는 경우 자동으로 호출된다. ->임시변수가 생성

디폴트 복사 생성자
- 복사 생성자가 호출되어야 하는 시점에 클래스 안에 복사생성자가 없을 때 자동으로 만들어져 호출된다.
- 디폴트 복사 생성자는 멤버변수를 bit단위로 1:1로 대입한다.

깊은 복사: 하나의 값을 가진 공간을 다른 공간에서 복사
얕은 복사: 하나의 값을 가진 공간 자체를 복사


#include<iostream>
using namespace std;

class Test {
public:
	Test() {
		cout << "생성자" << endl;
	}
	~Test() {
		cout << "소멸자" << endl;
	}
};
void ex1(Test t) { // main.t -> ex1.t에 복사
	// 일반변수를 매개변수
	Test tt = t;
	// tt는 t로 초기화
	cout << &tt << endl;
	cout << &t << endl;
}
void ex2(Test& r) {
	// 레퍼런스 변수를 매개변수(같은공간을 가지고 있음)
	Test rr = r;
}
void ex3(Test* p) {

}
int main() {
	Test t;
	ex1(t);
	ex2(t);
	ex3(&t);
}


#include<iostream>
using namespace std;
class Test {
	int val;
public:
	Test(int v = 0) {
		cout << "Test(int v) 호출" << endl;
		val = v;
	}
	Test(Test& r) {
		cout << "Test(Test& r)호출" << endl;
		this->val = r.val;
	}
	~Test() {
		cout << "소멸자 실행" << endl;
	}
	void set(int v) {
		val = v;
	}
	void get() {
		cout << this->val << endl;
	}
};
int main() {
	Test tt1(10);
	// tt1.Test(10);
	tt1.get();
	Test tt2 = tt1;	//깊은복사
	// tt2.Test(tt2);
	Test& tt3 = tt1;
	tt2.get();
	cout << "tt1: " << &tt1 << endl;
	cout << "tt2: " << &tt2 << endl;

}


/*문제2.
- 멤버변수 : 순번/이름/전화번호
- 함수: 등록/출력/삭제/검색/프로그램 종료*/

#include<iostream>
using namespace std;
class Student {
	int *num;
	char* name;
	char* p_num;
public:
	Student() {
		num = new int;
		name = new char[10];
		p_num = new char[15];
	}
	~Student() {
		delete(num);
		delete[](name);
		delete[](p_num);
	}
	void set() {
		cout << "----------- 인적사항 입력 -----------\n" << endl;
		cout << "순번 입력 : "; cin >> *num;
		cout << "이름 입력 : "; cin >> name;
		cout << "전화번호 입력 : "; cin >> p_num;
	}
	int ret_num() {
		return *num;
	}
	void get() {
		
		cout << *num << ".";
		cout << "이름 :" << name;
		cout << " (" << p_num <<")" << endl;
	}
};
int main() {
	Student stu[5];
	int cho = 0;
	int cnt = 0;
	int num;
	while (1) {
		cout << "----------- 인적사항 -----------\n" << endl;
		cout << "1.등록 2.출력 3.삭제 4.검색 5.프로그램 종료\n>>>"; cin >> cho;
		system("cls");
		switch (cho) {
		case 1:
			stu[cnt].set();
			cnt++;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "----------- 인적사항 출력 -----------\n" << endl;
			for (int i = 0; i < cnt; i++) {
				stu[i].get();
			}
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "삭제 할 순번 입력 : "; cin >> num;
			int a;
			for (int i = 0; i < cnt; i++) {
				a = stu[i].ret_num();
				if (num == a) {
					cnt--;
					for (int j = i; j < cnt; j++) {
						stu[j] = stu[j+1];
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "검색 할 순번 입력 : "; cin >> num;
			a = 0;
			for (int i = 0; i < cnt; i++) {
				a = stu[i].ret_num();
				if (num == a) {
					cout << "------ 검색한 학생 -------" << endl;
					stu[i].get();
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "프로그램이 종료됩니다." << endl;
			break;
		}	
	}
}