#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
void split (double num , int *int_part , double *frac_part)
{
	*int_part = (int) num;
	*frac_part = num - *int_part;
}
int main()
{
	double num , fraction;
	int integer;
	cin>>num;
	split (num, &integer, &fraction);
	cout<< integer << ' ' << fraction;
	return 0;	
}
