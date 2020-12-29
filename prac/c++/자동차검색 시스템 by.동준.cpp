//문제1. 구조체 포인터를 이용하여 구현
//- 제조사/자동차이름/년식/가격
//- 입력/출력/검색/삭제 기능을 가진 프로그램으로 구현
//- 최대 입력 대수는 5대로 5를 초과하여 입력할 수 없음.
//- 최소 입력 대수는 0대로 0   미만으로 입력할 수 없음.

#include<iostream>
using namespace std;
struct CAR {
	char company[30];
	char name[30];
	int  year;
	int  cost;
};
int cnt, i;
struct CAR info[5];
void input() {
	cnt++;
	cout << "회사이름:"; cin >> info[cnt - 1].company;
	cout << "자동차이름:"; cin >> info[cnt - 1].name;
	cout << "연식:"; cin >> info[cnt - 1].year;
	cout << "가격:"; cin >> info[cnt - 1].cost;
	cout << "==================================" << endl;
}
void output() {
	for (i = 0; i < cnt; i++) {
		cout << "-회사이름:" << info[i].company << endl;
		cout << "-자동차이름:" << info[i].name << endl;
		cout << "-연식:" << info[i].year << "년도" << endl;
		cout << "-가격:" << info[i].cost << " 만원" << endl;
		cout << "==================================" << endl;
	}
}
void searching() {
	char search[30];
	cout << "자동차 정보 검색:"; cin >> search;
	system("cls");
	for (i = 0; i < cnt; i++) {
		if (!(strcmp(search, info[i].name)) == 0) {
			cout << "입력하신 정보가 존재하지 않습니다." << endl;
			continue;
		}
		else {
			cout << "------검색하신 " << info[i].name << " 정보-------" << endl;
			cout << "->회사이름:" << info[i].company << endl;
			cout << "->연식:" << info[i].year << "년도" << endl;
			cout << "->가격:" << info[i].cost << " 만원" << endl;
			break;
		}
	}
}
void remove() {
	char del[30];
	cout << "삭제할 자동차 정보:"; cin >> del;
	int k = 0;
	for (i = 0; i < cnt; i++) {
		if (!strcmp(del, info[i].name)) {
			for (k = i; k < cnt; k++) {
				cout << info[i].name << " 차량의 정보가 삭제되었습니다." << endl;
				strcpy(info[i].name, info[i + 1].name);
				strcpy(info[i].company, info[i + 1].company);
				info[k].year = info[k + 1].year;
				info[k].cost = info[k + 1].cost;
				cnt--;
			}
		}
	}
}
int main() {
	int cho = 0;
	while (1) {
		cout << "######### 5/" << cnt << " #########\n" << endl;
		cout << "1.정보입력 2.정보출력 3.검색 4.삭제\n>>>";
		cin >> cho;
		system("cls");
		if (cho == 1) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			if (cnt == 5) {
				cout << "더 이상 입력 할 수 없습니다." << endl;
				system("pause");
				system("cls");
				continue;
			}
			input();
			system("cls");
		}
		else if (cho == 2) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			output();
			system("pause");
			system("cls");
		}
		else if (cho == 3) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			searching();
			system("pause");
			system("cls");
		}
		else if (cho == 4) {
			cout << "######### 5/" << cnt << " #########\n" << endl;
			if (cnt == 0) {
				cout << "더 이상 삭제 할 정보가 없습니다." << endl;
				system("pause");
				system("cls");
				continue;
			}
			remove();
			system("pause");
			system("cls");
		}
	}
	return 0;
}
