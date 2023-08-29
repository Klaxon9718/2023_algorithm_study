#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000
typedef long long ll;
ll sum[MAX + 1] = { 0, }; // 누적합 저장 배열
ll arr[MAX + 1]; // 해당 약수의 합 저장 배열

void initSum()
{
	fill_n(arr, MAX + 1, 1); //memset은 -1이나 0 아니면 초기화 불가. => fill_n std 함수 사용.
	for (int i = 2; i <= MAX; i++)//2부터 배수정함.
	{
		for (int j = 1; i * j <= MAX; j++)//범위 안의 2의배수 모든 수에 해당 i 더해줌.
		{
			arr[i * j] += i;
			/*if (i < 10&&j<10)
				cout <<"arr["<<i*j<<"] = " << arr[i * j] << '\n';*/
		}
	}
	for (int i = 1; i <= MAX; i++)
	{
		sum[i] = sum[i - 1] + arr[i];//누적합 더해줌.
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	initSum();
	while (n--)
	{
		int x;
		cin >> x;
		cout << sum[x] << '\n';
	}


	return 0;
}