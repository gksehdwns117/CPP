����ü�� �̿��ؼ� ����
������� : �̸�/����/����/����
3���� ����ü ������ ������ ����,�Է�
������ ���(�Ҽ��� 2�ڸ�)���
#include<stdio.h>
void test_result(int kor, int eng, int math, int*, double*);
int main() {
	int sum;
	double avr;
	int kor, eng, math;
	printf("�����:"); scanf_s("%d", &kor);
	printf("�����:"); scanf_s("%d", &eng);
	printf("���м���:"); scanf_s("%d", &math);
	test_result(kor,eng,math,&sum, &avr);
	printf("���� ����:%d\n", sum);
	printf("���� ���:%.2lf\n", avr);
	return 0;
}
void test_result(int kor,int eng,int math,int* a, double* b) {
	*a = kor + eng + math;
	*b = (double)* a / 3;
}


 1. 1~10 ������ ��
 2. 1~n ������ ��
 3. n~m������ ��
 4. �������α׷�
#include<stdio.h>
int program1();
int program2(int n);
int program3(int n, int m);
int main() {
	int cho;
	int result = 0;
	printf("1.1~10������ ��\n2.1~n������ ��\n3.n~m������ ��\n4.����\n=================================\n");

	while (1) {
		printf("����:"); scanf_s("%d", &cho);
		if (cho == 1) {
			result = program1();
			printf("1~10������ ��:%d\n", result);
			printf("=================================\n");
		}
		else if (cho == 2) {
			int n;
			printf("1~n������ �տ��� n:"); scanf_s("%d", &n);
			result = program2(n);
			printf("1~%d������ ��:%d\n", n, result);
			printf("=================================\n");
		}
		else if (cho == 3) {
			int n, m;
			printf("n~m������ �տ��� n:"); scanf_s("%d", &n);
			printf("n~m������ �տ��� m:"); scanf_s("%d", &m);
			result = program3(n, m);
			printf("%d~%d������ ��:%d\n", n, m, result);
			printf("=================================\n");
		}
		else if (cho == 4) {
			break;
		}
	}
	printf("���α׷��� ����Ǿ����ϴ�.\n");
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
		printf("5���� �迭 �Է�:"); scanf_s("%d", (arr+i));
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	printf("�ִ�:%d\n�ּڰ�:%d\n", max, min);
	return 0;
}

������ ���� ������ ������ 12byte. ���� ������� ������ �ּҰ��� �� ũ��.
�迭 �� ������ �ڷᱸ���� ���� �ܼ��� �������� �н�
1.�迭 :	�迭�� �޸��� ���� ���̱� ���ؼ� ����Ѵ�.
		�ϳ��� �̸����� ������ ó���� ����.
		�迭�� ���� �ڷ��������� ���� �� �ִ�.
2.�迭 �̸��� ������ �ǹ�.
-�迭�� ���� �ּҰ�
-�迭�� �� ũ�⸦ �ǹ�.