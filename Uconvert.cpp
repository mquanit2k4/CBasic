#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	FILE *f1;
	f1 = fopen(argv[1],"r+");
	char c;
	char result[10000];
	int i = 0 ;
	while ((c = fgetc(f1)) != EOF)
	{
		result[i++] = toupper(c);
	}
	fclose(f1); // Xoa du lieu hien co trong file
	
	f1 = fopen(argv[1],"r+"); // Mo lai file de ghi thong tin
	fprintf(f1, "%s", result);
	fclose(f1);
	cout << "Success";

	return 0;	
}
