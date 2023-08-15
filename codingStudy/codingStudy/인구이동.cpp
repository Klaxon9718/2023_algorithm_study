#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int row, L, R;
	cin >> row;
	cin >> L;
	cin >> R;

	// 이중 배열 선언
	int** valArr = new int*[row];
	for (int i = 0; i < row; i++) { valArr[i] = new int[row]; }

	int** visited = new int* [row];
	for (int i = 0; i < row; i++) { valArr[i] = new int[row]; }

	// 방향 탐색 : 좌 > 우 > 상 > 하
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	// 값 입력
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++)
		{
			cin >> valArr[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++)
		{
			// 상하좌우 탐색
			for (int k = 0; k < 4; k++) {
				if (visited[i][j] == NULL) {
						visited[i][j] = valArr[i][j];

					}
				}
			}

		}
	}
	


}

void (int valArr[][]) {

}