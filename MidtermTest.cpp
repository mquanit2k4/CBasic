#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main()
{
	string date , time , user , question;
	int i = 0;
	map <string , int> mp;
	while (cin >> date && date != "*")
	{
		i = 0;
		cin >> time >> user >> question;
		cin.ignore();
		if (user != " ")
		{
			if (mp.count(date) != 0 )
				mp[date] += 1;
			else
			{
				i++;
				mp.insert({date,i});
			}
		}
	}
	
	for (auto it : mp)
		cout << it.first << " " << it.second << endl;
	return 0;	
}
