/*
#include <stdio.h>
#include <string.h>
void input();
void output();
void search();
void del();
char name[5][20];
int main() {
	while(1){
		int cho;
		printf("1.이름입력\n2.이름출력\n3.이름검색\n4.이름삭제\n5.종료\n");
		printf("선택>>>"); scanf("%d", &cho);
		if (cho == 1) {
			input();
		}
		else if (cho == 2) {
			output();
		}
		else if (cho == 3) {
			search();
		}
		else if (cho == 4) {
			del();
		}
		else if (cho == 5) {
			printf("프로그램종료\n");
			break;
		}
		else {
			printf("잘못입력하셨습니다.\n");
		}
	}
	
}
void input() {
	for (int i = 0; i < 5; i++) {
		printf("%d 번째 이름 입력 : ", i + 1);
		scanf("%s", name[i], 20);
	}
}
void output() {
	for (int i = 0; i < 5; i++) {
		printf("%d 번째 이름: %s\n", i + 1, name[i]);
	}
}
void search() {
	char f_name[20];
	printf("찾으실 이름 입력 : ");
	scanf("%s", &f_name,20);
	for (int i = 0; i < 5; i++) {
		if (!strcmp(name[i], f_name)) {
			printf("%s 님이 있습니다.\n", name[i]);
		}
	}
}
void del() {
	char f_name[20];
	printf("삭제할 이름 입력 : ");
	scanf("%s", &f_name,20);
	for (int i = 0; i < 5; i++) {
		if (!strcmp(name[i], f_name)) {
			printf("%s 님이 있습니다.\n", name[i]);
			for (int j = i; j < 5; j++) {
				strcpy(name[j], name[j + 1]);
			}
			strcpy(name[4], "");
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d 번째 이름 입력 : %s\n", i + 1, name[i]);
	}
}
*/
//cpp
// #include : 전처리기-사용 할 함수를 호출.
// 컴파일: 컴퓨터가 이해할 수 있는 언어로 변환(번역)

#include<iostream>		//입,출력에 관한 함수를 제어
// input output stream
int main() {
	int a = 10;
	double b = 2.1;
	char c = 'c';
	printf("%d\n", a); printf("%lf\n", b); printf("%c", c);
}