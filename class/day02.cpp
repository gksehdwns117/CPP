#include<stdio.h>
void input();
char output();
char search();
char del();
char name[5][10];
int main() {
	int cho;
	while(1){
		printf("선택:"); scanf_s("%d", &cho);
		if (cho == 1) {
			for (int i = 0; i < 5; i++) {
				printf("이름입력:"); scanf_s("%s", name[i], 10);
			}
		}
		else if (cho == 2) {
			for (int i = 0; i < 5; i++) {
				printf("%s", name[i]);
			}
		}
		else if (cho == 3) {
			char search[5];
			printf("찾을 이름을 검색:"); scanf_s("%s", search,5);
			for (int i = 0; i < 5; i++) {
				if (search == name[i]) {
					printf("검색한 이름이 있습니다.");
				}
				else {
					printf("검색한 이름이 없습니다.");
				}
			}
		}
		else if (cho == 4) {
			break;
		}
		return 0;
	}
}
void input() {
	
}


//cpp
#include : 전처리기-사용 할 함수를 호출.
컴파일: 컴퓨터가 이해할 수 있는 언어로 변환(번역)

#include<iostream>		입,출력에 관한 함수를 제어
input output stream
iostream -> stdio.h / stdlib.h(malloc) / windows.h
int main() {
	int a = 10;
	double b = 2.1;
	char c = 'c';
	printf("%d\n", a); printf("%lf\n", b); printf("%c\n", c);
	system("calc.exe");
}

#include<iostream>
int main() {
	int a = 10;
	int b = 20;
	int c = 30;
	char name[10] = "홍길동";
	std::cout << "정수 두개 입력:";
	std::cin >> a >> b;
	std::cout << a << " " << b << "\n";
	std::cout << a << std::endl;		//a의 값을 cout에 전달 cout은 출력함수
	std::cin >> a;						//a에 cin의 입력함수를 사용하여 값을 전달.
	std::cout << a << std::endl;
	std::cout << a <<" "<< b <<" "<< c << " "<< std::endl; //여러 변수를 한번에 출력하는 방법
	std::cout << a << "\n" << b << "\n" << c << "\n" << std::endl; //이스케이프 문자도 출력가능.
	std::cout << "내가 쓰고 싶은내용\n";						//문자열 상수로의 사용
	std::cout << "정수 입력\n:";								//입출력
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << name << std::endl;
	std::cout << "문자열 입력:";
	std::cin >> name;
	std::cout << name << std::endl;
	 
본래	c언어는 중간에 변수 선언이 금지
c++은 함수중반부에 변수 선언을 해도 상관 없다.
//int aa;
}