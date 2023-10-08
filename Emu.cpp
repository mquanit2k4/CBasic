#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char *argv[])
{
	if (argc != 3 )
		return 1;
	else
	{
		double x = atof(argv[1]);
		double epsilon = atof(argv[2]);
		double result = 1.0;
		double term = 1.0;
		int n = 1;
		while (abs(term) > epsilon)
		{
			term *= x/n;
			result += term;
			n++;
		}
		cout << "e^" << x << " voi sai so " << epsilon << " la: "<<result;
	}

	return 0;	
}
