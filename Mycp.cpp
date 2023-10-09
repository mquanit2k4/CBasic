#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc != 3)
		return 1;
	char c;
	FILE *f1 , *f2;
	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "w");
	while ((c = fgetc(f1)) != EOF)
	{
		fputc(c,f2);
	}
	cout<<"Success";
	return 0;	
}
