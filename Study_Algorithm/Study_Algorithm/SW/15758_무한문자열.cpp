#include <iostream>
#include <string>
using namespace std;
int GCD(int x, int y)
{
    while (y > 0)
    {
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}
int LCM(int x, int y)
{
    return x * y / GCD(x, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int R;
    cin >> R;
    int idx = 1;
     
    while (R--)
    {
        bool check = false;
        string a;
        string b;
        string tmp = "";
        cin >> a >> b;
        int aSize = a.size();
        int bSize = b.size();
        int aIdx = LCM(aSize, bSize) / aSize;
        int bIdx = LCM(aSize, bSize) / bSize;
        //cout << aIdx << bIdx << '\n';
        //cout << a << '\n' << b << '\n';
        tmp = a;
        for (int i = 1; i < aIdx; i++)
        {
            a += tmp;
        }
        tmp = b;
        for (int i = 1; i < bIdx; i++)
        {
            b += tmp;
        }
        //cout << a << "size : " << a.size() << '\n';
        //cout << b << "size : " << b.size() << '\n';
        if (a == b)check = true;
        if (check)
            cout << "#" << idx << " yes" << '\n';
        else
            cout << "#" << idx << " no" << '\n';
        idx++;
 
    }
 
    return 0;
}