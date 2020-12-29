구조체를 이용해서 구현
멤버변수 : 이름/국어/영어/수학
3개의 구조체 포인터 변수를 생성,입력
총점과 평균(소수점 2자리)출력
#include<stdio.h>
void test_result(int kor, int eng, int math, int*, double*);
int main() {
	int sum;
	double avr;
	int kor, eng, math;
	printf("국어성적:"); scanf_s("%d", &kor);
	printf("영어성적:"); scanf_s("%d", &eng);
	printf("수학성적:"); scanf_s("%d", &math);
	test_result(kor,eng,math,&sum, &avr);
	printf("성적 총점:%d\n", sum);
	printf("성적 평균:%.2lf\n", avr);
	return 0;
}
void test_result(int kor,int eng,int math,int* a, double* b) {
	*a = kor + eng + math;
	*b = (double)* a / 3;
}


 1. 1~10 까지의 합
 2. 1~n 까지의 합
 3. n~m까지의 합
 4. 종료프로그램
#include<stdio.h>
int program1();
int program2(int n);
int program3(int n, int m);
int main() {
	int cho;
	int result = 0;
	printf("1.1~10까지의 합\n2.1~n까지의 합\n3.n~m까지의 합\n4.종료\n=================================\n");

	while (1) {
		printf("선택:"); scanf_s("%d", &cho);
		if (cho == 1) {
			result = program1();
			printf("1~10까지의 합:%d\n", result);
			printf("=================================\n");
		}
		else if (cho == 2) {
			int n;
			printf("1~n까지의 합에서 n:"); scanf_s("%d", &n);
			result = program2(n);
			printf("1~%d까지의 합:%d\n", n, result);
			printf("=================================\n");
		}
		else if (cho == 3) {
			int n, m;
			printf("n~m까지의 합에서 n:"); scanf_s("%d", &n);
			printf("n~m까지의 합에서 m:"); scanf_s("%d", &m);
			result = program3(n, m);
			printf("%d~%d까지의 합:%d\n", n, m, result);
			printf("=================================\n");
		}
		else if (cho == 4) {
			break;
		}
	}
	printf("프로그램이 종료되었습니다.\n");
	return 0;
}
int program1() {
	int i, sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	return sum;
}
int program2(int n) {
	int i, sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}
int program3(int n, int m) {
	int i, sum = 0;
	for (i = n; i <= m; i++) {
		sum += i;
	}
	return sum;
}


#include<stdio.h>
int main(){
	int arr[5];
	int max = 0, min = 1000;
	int i;
	for (i = 0; i < 5; i++) {
		printf("5개의 배열 입력:"); scanf_s("%d", (arr+i));
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("최댓값:%d\n최솟값:%d\n", max, min);
	return 0;
}

변수와 변수 사이의 간격은 12byte. 먼저 만들어진 변수가 주소값이 더 크다.
배열 전 까지는 자료구조의 제일 단순한 구조들을 학습
1.배열 :	배열은 메모리의 낭비를 줄이기 위해서 사용한다.
		하나의 이름으로 데이터 처리가 가능.
		배열은 같은 자료형끼리만 묶을 수 있다.
2.배열 이름이 가지는 의미.
-배열의 시작 주소값
-배열의 총 크기를 의미.