#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main()
{
	string s;
	getline(cin,s); 
	stringstream ss(s);
	string tmp;
	while (ss >> tmp)
	{
		cout << tmp <<endl;
	}

	return 0;	
}
