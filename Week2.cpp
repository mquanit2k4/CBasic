#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
string replaceChar (string s , char a , char b)
{
	int n = s.size();
	for (int i = 0 ; i < n ; i++)
		if (s[i] == a)
			s[i] = b;
	return s;
}
int main()
{
	string s;
	char a,b;
	cin>>s;
	cin>>a>>b;
	cout<<replaceChar(s, a, b);

	return 0;	
}
