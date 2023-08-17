#include <iostream>
using namespace std;
int row[200001];
int col[200001];
int arr[10000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ts;
    int idx = 1;
    cin >> ts;
    while (ts--)
    {
        int answer = 0;
        int result = 0;
        int n, m, q;
        cin >> n >> m >> q;
         
         
         
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int val;
                cin >> val;
                if (row[i] < val) row[i] = val;
                if (col[j] < val) col[j] = val;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            arr[row[i]]++;
        }
        for (int j = 1; j <= m; j++)
        {
            arr[col[j]]++;
            if (arr[col[j]] == 2)
            {
                result++;
            }
        }
 
        //q번 반복
        for (int k = 0; k < q; k++)
        {
            int r, c, x;
            cin >> r >> c >> x;
            if (row[r] < x)
            {
                if (arr[row[r]] == 2) result--;
                arr[row[r]]--;
                row[r] = x;
                arr[x]++;
                if (arr[x] == 2) result++;
            }
 
            if (col[c] < x)
            {
                if (arr[col[c]] == 2) result--;
                arr[col[c]]--;
                col[c] = x;
                arr[x]++;
                if (arr[x] == 2) result++;
            }
            answer += result;
             
        }
        cout << "#" << idx << " " << answer << '\n';
        idx++;
        for (int i = 1; i <= n; i++)
        {
            arr[row[i]] = 0;
            row[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            arr[col[i]] = 0;
            col[i] = 0;
        }
    }
 
    return 0;
}