#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc != 4)
		return 1;
	int offset = atoi(argv[2]);
	FILE *f1, *f2;
	f1 = fopen(argv[1],"r+");
	f2 = fopen(argv[3],"r+");
//	int sel;
//	cout << "Ban can MA HOA[1] hay GIAI MA[2]: ";
//	cin >> sel;
//	if (sel == 1)
//	{
//		
//	}

	char c;
	int i = 0;
	char result[10000];
		while ((c = fgetc(f1)) != EOF)
		{
			if (c >= 'a' && c <= 'z')
				result[i++] = ((c - 65) + offset) % 26 + 65;
			else if (c >= 'A' && c <= 'Z')
				result[i++] = ((c - 97) + offset) % 26 + 97;
			else
				result[i++] = c;	
		}
	fprintf(f2, "%s", result);
	if (offset > 0)
		cout << "Ma hoa thanh cong";
	else
		cout << "Giai ma thanh cong";
	fclose(f1);
	fclose(f2);
	return 0;	
}
