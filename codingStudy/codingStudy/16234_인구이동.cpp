/*
16234 백준
https://www.acmicpc.net/problem/16234

1. 값이 들어 있는 배열 (값 배열)과 방문을 확인하는 배열 선언(방문 배열)
2. 값 배열을 차례대로 돌면서 범위 내의 값인지 판단 후
3. 맞을 경우 주변 값들을 확인하며 방문 배열을 표시한다.
4. 2, 3번을 반복하다가 끝을 감지할 경우, 값을 평균으로 나눈 뒤, 값들을 넣어준다.
5. 1 ~ 4를 반복하면서 카운트르 하고
6. 완료시, 기간을 표시한다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
#define ll long long
#define INF 1e9
using namespace std;

int n, L, R;
int map[52][52];	// 값을 넣는 배열
int open[52][52];	// 방문 표시 배열

//상하좌우 탐색 위한 변수
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

int day = 0;
int unions = 0;
vector<int> avgs;


bool needMove() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 상하좌우 탐색
			for (int d = 0; d < 4; ++d) {
				int ni, nj;

				ni = i + dr[d];
				nj = j + dc[d];

				int home = map[i][j];
				int adj = map[ni][nj];
				if (L <= abs(home - adj) && abs(home - adj) <= R) {
					return true;
				}
			}
		}
	}

	return false;
}


// 주변을 탐색하면서 범위 안에 있는 경우, queue에 넣는다.
// 연합국의 카운트와 인구 수를 더하고
// 방문한 연합국에 방문처리한다. (해당하는 연합국 번호를 배열에 넣어주는 작업)
// queue의 값이 없어졌을 때 bfs를 탈출한다.
void bfs(int r, int c) {
	int countries = 1;
	int population = map[r][c];

	queue<pair<int, int> > q;
	q.push(make_pair(r, c));	// make_pair( , ) : 오직 두 객체(세개 이상 X )를 하나의 객체로 취급 할 수 있게 묶어주는 클래스
	open[r][c] = unions;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();

		r = p.first;
		c = p.second;

		for (int d = 0; d < 4; ++d) {
			int nr, nc;
			nr = r + dr[d];
			nc = c + dc[d];

			if (open[nr][nc]) {
				continue;
			}

			int home = map[r][c];
			int adj = map[nr][nc];
			if (L <= abs(home - adj) && abs(home - adj) <= R) {
				open[nr][nc] = unions;	// 해당하는 연합국 번호를 바꿔준다
				countries++;
				population += map[nr][nc];
				q.push(make_pair(nr, nc));
			}
		}
	}

	avgs.push_back(population / countries);

	return;
}

void sol() {

	while (true) {
		memset(open, 0, sizeof(open));
		// needMove 함수로 칸의 값이 범위 내의 값인지 판별
		// 참 일경우 이어서 실행
		if (!needMove()) {
			break;
		}

		day++;
		unions = 0;
		avgs.clear();
		avgs.push_back(-1); // 마지막에 새로운 값 추가

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (!open[i][j]) {
					for (int d = 0; d < 4; ++d) {
						int ni, nj;

						ni = i + dr[d];
						nj = j + dc[d];

						int home = map[i][j];
						int adj = map[ni][nj];
						// 범위 내의 값이고 방문 처리가 되지 않았을 경우
						// 연합국의 번호(unions)를 바꿔주고
						// bfs()를 이용해 주변을 탐색한다.
						if (L <= abs(home - adj) && abs(home - adj) <= R) {
							if (!open[ni][nj]) {
								unions++;  
								bfs(i, j);
							}
						}
					}
				}
			}
		}

		// 인구 평균 구하기
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (open[i][j]) {
					int unionNum = open[i][j];
					map[i][j] = avgs[unionNum];
				}
			}
		}

	}

	return;
}

int main(void) {
	
	// 값 입력받기
	scanf("%d%d%d", &n, &L, &R);
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < 52; ++j) {
			map[i][j] = INF;
		}
	}

	// map에 값 입력
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	sol();
	printf("%d\n", day);

	return 0;
}