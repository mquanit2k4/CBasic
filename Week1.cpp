#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
double avg (int a[] , int n)
{
	double sum = 0;
	rep(i,0,n-1)
	{
		sum+=a[i];
	}
	return sum/n;
}
int main()
{
	int n, a[10000];
	cin >> n;
	rep(i,0,n-1)
	{
		cin>>a[i];
	}
	int tb = avg(a,n);
	int min = 1e6;
	int vt;
	rep(i,0,n-1)
	{
		int tmp = abs(tb - a[i]);
		if (tmp < min)
		{
			min = tmp;
			vt = i;
		}
	}
	cout << a[vt];
	
	return 0;	
}
