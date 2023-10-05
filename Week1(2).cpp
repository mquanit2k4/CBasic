#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main()
{
	string s;
	int d[1000]={0};
	getline(cin , s);
	int n = s.size();
	for (int i = 0 ; i < n ; i++)
	{
		if(s[i]>'a' && s[i] <= 'z')
			d[s[i]]++;
	}
	for (char i = 'a' ; i <= 'z' ; i++)
		if (d[i] > 0)
			cout << "The letter " << i << " appears " << d[i] << " time(s)" <<endl;
	return 0;	
}
