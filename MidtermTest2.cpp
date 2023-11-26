#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int sum (int a[], int n)
{
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans += a[i];
	return ans;
}

int maxN(int a[], int n)
{
	int tmp = a[1];
	for (int i = 2 ; i <= n ; i++)
		if (a[i] > tmp)
			tmp = a[i];
	return tmp;
}

int minN(int a[], int n)
{
	int tmp = a[1];
	for (int i = 2 ; i <= n ; i++)
		if (a[i] < tmp)
			tmp = a[i];
	return tmp;
}

int maxSub(int a[], int i , int j)
{
	int tmp = a[i];
	for (int t = i+1 ; t <= j ; t++)
		if (tmp < a[t])
			tmp = a[t];
	return tmp;
}

int minSub(int a[] , int i , int j)
{
	int tmp = a[i];
	for (int t = i+1 ; t <= j ; t++)
		if (tmp > a[t])
			tmp = a[t];
	return tmp;
}
int main()
{
	int n,a[10001];
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];
	string s;
	while (cin >> s && s != "***")
	{
		if (s == "find-max")
			cout << maxN(a,n) << endl;
		else if (s == "find-min")
			cout << minN(a,n) << endl;
		else if (s == "sum")
			cout << sum(a,n) <<endl;
		else if (s == "find-max-segment")
		{
			int i , j;
			cin >> i >> j;
			cout << maxSub(a,i,j) << endl;
		}
		else if (s == "find-min-segment")
		{
			int i , j;
			cin >> i >> j;
			cout << minSub(a,i,j) << endl;
		}
	}

	return 0;	
}
