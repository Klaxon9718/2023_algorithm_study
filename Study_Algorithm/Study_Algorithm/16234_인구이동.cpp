#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
int Arr[51][51] = { 0, };
int canMove[51][51] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int Total[10000] = { 0, };
queue<pair<int, int>> q;
int N, L, R;
int a;
int idx = 1;
void BFS(int startx, int starty)
{
	a = 0;
	int cnt = 0;
	int total = 0;

	canMove[startx][starty] = idx;	//번호 표시해서 영역 다름 확인.
	q.push({ startx,starty });
	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		total += Arr[x][y];
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && canMove[nx][ny] == 0)
			{
				if (abs(Arr[nx][ny] - Arr[x][y]) >= L && abs((Arr[nx][ny] - Arr[x][y])) <= R)
				{
					canMove[nx][ny] = idx;
					q.push({ nx,ny });
				}
			}
		}
	}
	a = total / cnt;
	if (cnt == 1)
	{
		canMove[startx][starty] = -1;
		return;
	}
	else
	{
		Total[idx] = a;
		idx++;
	}



}

int main()
{
	cin >> N >> L >> R;
	int gap = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Arr[i][j];
		}
	}
	int answer = 0;
	while (true)
	{
		int x = 0;
		bool repeat = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (canMove[i][j] == 0)
				{
					BFS(i, j);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (canMove[i][j] != -1)
				{
					int q = canMove[i][j];
					Arr[i][j] = Total[q];
				}
			}
		}
		idx = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (canMove[i][j] != -1)
				{
					repeat = true;
					break;
				}
			}
		}
		if (repeat == false)break;
		memset(canMove, 0, sizeof(canMove));
		answer++;

	}



	cout << answer;
	return 0;
}