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
int main() {
	struct CAR info[5];
	int i, cho, cnt = 0;
	char search[30];
	char del[30];
	while (1) {
		cout << "1.정보입력 2.정보출력 3.검색 4.삭제\n>>>";
		cin >> cho;
		if (cho == 1) {
			cnt++;
			cout << "회사이름:"; cin >> info[cnt-1].company;
			cout << "자동차이름:"; cin >> info[cnt-1].name;
			cout << "연식:"; cin >> info[cnt-1].year;
			cout << "가격:"; cin >> info[cnt-1].cost;
			cout << "==================================" << endl;
			if (cnt > 5) {
				cout << "더 이상 입력 할 수 없습니다." << endl;
				cout << "==================================" << endl;
				continue;
			}
		}
		else if (cho == 2) {
			for (i = 0; i < cnt; i++) {
				cout << "-회사이름:" << info[i].company << endl;
				cout << "-자동차이름:" << info[i].name << endl;
				cout << "-연식:" << info[i].year << "년도" << endl;
				cout << "-가격:" << info[i].cost << " 만원" << endl;
				cout << "==================================" << endl;
			}
		}
		else if (cho == 3) {
			cout << "자동차 정보 검색:"; cin >> search;
			for (i = 0; i < cnt; i++) {
				if (!(strcmp(search, info[i].name))==0) {
					cout << "입력하신 정보가 존재하지 않습니다." << endl;
				}
				else {
					cout << "------검색하신 " << info[i].name << " 정보-------" << endl;
					cout << "->회사이름:" << info[i].company << endl;
					cout << "->연식:" << info[i].year << "년도" << endl;
					cout << "->가격:" << info[i].cost << " 만원" << endl;
				}
			}
		}
		else if (cho == 4) {
			cout << "삭제할 자동차 정보:"; cin >> del;
			int k = 0;
			for (i = 0; i < cnt; i++) {
				if (!strcmp(del, info[i].name)) {
					for (k = i; k < cnt; k++) {
						strcpy(info[i].name, info[i + 1].name);
						strcpy(info[i].company, info[i + 1].company);
						info[k].year = info[k + 1].year;
						info[k].cost = info[k + 1].cost;
					}
				}
			}
		}
	}

	return 0;
}
