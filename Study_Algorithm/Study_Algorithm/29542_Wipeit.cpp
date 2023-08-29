#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	string ans = "";
	cin >> s;
	set<char> se;
	for (int i = 0; i < s.size(); i++)
	{
		if (se.find(s[i]) == se.end())
		{
			se.insert(s[i]);
			ans += s[i];
		}
	}
	cout << ans;


	return 0;
}
