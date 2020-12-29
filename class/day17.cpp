// 문제1.클래스 객체 동적할당을 이용하여 구현
// - 부모클래스 : 이름 / 주민번호 / 나이
// - 자식클래스 : 전화번호 / 회원번호
// - 입력 할 객체 갯수 동적할당
// - 입력 / 출력 / 검색 / 삭제 / 종료 프로그램 생성

/*#include<iostream>
using namespace std;
class Personal_info {
protected:
	char name[10];
	char head_number[7];
	char back_number[8];
	int age;
public:
	void set() {
		cout << "이름입력 : "; cin >> name;
		cout << "주민번호 앞자리 입력(6자리) : "; cin >> head_number;
		cout << "주민번호 뒷자리 입력(7자리) : "; cin >> back_number;
		cout << "나이입력 : "; cin >> age;
	}
	void get() {
		cout << "이름 : " << name << endl;;
		cout << "주민번호 : " << head_number << "-" << back_number  << endl;
		cout << "나이 : " << age << endl;
	}
};
class Official_info : public Personal_info {
	char p_number[20];
	int guest_number;
public:
	void set() {
		Personal_info::set();
		cout << "전화번호 입력(-입력): "; cin >> p_number;
		cout << "회원번호 입력(8자리) : "; cin >> guest_number;
	}
	void get() {
		Personal_info::get();
		cout << "전화번호 : " << p_number << endl;
		cout << "회원번호 : " << guest_number << endl;
	}
	int search(const int& s1) {
		if (s1 == guest_number) return 1;
		else return 0;
	}
	int del(const int& s2) {
		if (s2 == guest_number) return 1;
		else return 0;
	}
};

int main() {
	int list;
	cout << "몇 명의 정보를 입력하십니까? "; cin >> list;
	Official_info* p = new Official_info[list];
	int cho, i, res1 = 0, res2 = 0;
	int cnt = 0;
	int search_num, del_num;
	while (1) {
		cout << "1.입력 2.출력 3.검색 4.삭제 5.종료" << endl;
		cout << "---------------------------" << endl;
		cout << "메뉴선택: "; cin >> cho;
		cout << endl;
		if (cho == 1) {
			p[cnt].set();
			cnt++;
		}
		else if (cho == 2) {
			for (i = 0; i < cnt; i++) {
				p[i].get();
				cout << "---------------------------" << endl;
			}
		}
		else if (cho == 3) {
			cout << "검색 할 회원번호 입력(8자리) : "; cin >> search_num;
			for (i = 0; i < cnt; i++) {
				res1 = p[i].search(search_num);
				if (res1 == 1) {
					cout << "---------------------------" << endl;
					p[i].get();
					res1 = 0;
				}
				else if (res1 == 0) {
					cout << "찾으시는 회원의 정보가 없습니다." << endl;
					cout << "---------------------------" << endl;
				}
			}
		}
		else if (cho == 4) {
			cout << "삭제 할 회원번호 입력(8자리) : ", cin >> del_num;
			for (i = 0; i < cnt; i++) {
				res2 = p[i].del(del_num);
				if (res2 == 1) {
					cnt--;
					for (int j = i; j < cnt; j++) {
						p[j] = p[j + 1];
					}
					res2 = 0;
				}
				else if (res2 == 0) {
					cout << "찾으시는 회원의 정보가 없습니다." << endl;
					cout << "---------------------------" << endl;
				}
			}
		}
		else if (cho == 5) {
			cout << "프로그램이 종료됩니다." << endl;
			break;
		}
	}
	delete[] p;
}

다중 상속
- 지금까지 했던 상속은 단일 상속이다.
- 다중상속은 둘 이상의 부모클래스를 가진 자식 클래스를 의미한다.
- 여러 클래스를 동시에 상속받을 수 있기 때문에 프로그램의 재사용성이 좋다.

#include<iostream>
using namespace std;
class A {	//부모클래스
public:
	void func1() {
		cout << "A::func1()" << endl;
	}
};
class B{	//부모클래스
public:
	void func2() {
		cout << "B::func2()" << endl;
	}
};
class C : public A, B {
public:
	void func3() {
		func1();
		func2();
		cout << "C::func3()" << endl;
	}
};
int main() {
	C c;
	c.func3;
}
*/

// 문제2.다중 상속을 이용하여 구현
// - 클래스1 : 이름 / 학년 / 반
// - 클래스2 : 국어 / 영어 / 수학
// - 클래스3 : 주민번호 / 주소
// 위의 클래스를 이용하여
// - 이름 / 학년 / 반 / 국어 / 영어 / 수학을 입력 할 수 있는 클래스
// - 이름 / 학년 / 반 / 주민번호 / 주소를 입력 할 수 있는 클래스
// - 클래스 1,2,3을 모두 이용 할 수 있는 클래스를 생성

#include<iostream>
using namespace std;
class Info1 {
protected:
	char* name;
	int *sch_year;
	int *ban;
public:
	Info1() {
		name = new char[10];
		sch_year = new int;
		ban = new int;
	}
	~Info1() {
		delete[]name;
		delete sch_year;
		delete ban;
	}
	void set1() {
		cout << "이름입력 : "; cin >> name;
		cout << "학년입력 : "; cin >> *sch_year;
		cout << "반  입력 : "; cin >> *ban;
	}
	void get1() {
		cout << "이름 : " << name << endl;
		cout << "학년 : " << *sch_year << "학년" << endl;
		cout << "반  : " << *ban << "반" << endl;
	}
};
class Info2{
protected:
	int *kor;
	int *eng;
	int *math;
public:
	Info2() {
		kor = new int;
		eng = new int;
		math = new int;
	}
	~Info2() {
		delete kor;
		delete eng;
		delete math;
	}
	void set2() {
		cout << "국어성적 : "; cin >> *kor;
		cout << "영어성적 : "; cin >> *eng;
		cout << "수학성적 : "; cin >> *math;
	}
	void get2() {
		cout << "국어 : " << *kor << "점" << endl;
		cout << "영어 : " << *eng << "점" << endl;
		cout << "수학 : " << *math << "점" << endl;
	}
};
class Info3{
protected:
	char* personal_num;
	char* address;
public:
	Info3() {
		personal_num = new char[20];
		address = new char[20];
	}
	~Info3() {
		delete[] personal_num;
		delete[] address;
	}
	void set3() {
		cout << "주민번호입력('-'포함) : "; cin >> personal_num;
		getchar();
		cout << "주소입력 : "; cin.get(address, 20);
		
	}
	void get3() {
		cout << "주민번호 : " << personal_num << endl;
		cout << "주소 : " << address;
	}
};
class A : public Info1, Info2 {
public:
	void set() {
		set1();
		set2();
	}
	void get() {
		get1();
		get2();
	}
};
class B : public Info1, Info3 {
public:
	void set() {
		set1();
		set3();
	}
	void get() {
		get1();
		get3();
	}
};
class C : public Info1, Info2, Info3 {
public:
	void set() {
		set1();
		set2();
		set3();
	}
	void get() {
		get1();
		get2();
		get3();
	}
};
int main() {
	int cho;
	cout << "1.이름,성적 입/출력 2.이름,주소 입/출력 3.이름,성적,주소 입/출력 4.프로그램 종료" << endl;
	cout << "선택 : "; cin >> cho;
	A a;
	B b;
	C c;
	while (1) {
		if (cho == 1) {
			a.set();
			a.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 2) {
			b.set();
			b.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 3) {
			c.set();
			c.get();
			cout << "--------------------------\n" << endl;
		}
		else if (cho == 4) {
			cout << "프로그램이 종료됩니다." << endl;
			break;
		}
		else {
			cout << "잘못입력하셨습니다." << endl;
		}
	}
}


