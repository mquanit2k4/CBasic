#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc != 2)
	{
		cout << "Nhap dung cu phap: Addline <file_name>\n";
		return 1;
	}
	FILE *f1;
	f1 = fopen(argv[1],"r");
	if (f1 == NULL)
	{
		perror("Loi khi mo tep tin");
		return 1;
	}
	char result[81];
	char line[81];
	result[0] = '\0';
	while (fgets(line, sizeof(line), f1))
	{
		strncat(result, line, 1);
		if (strlen (result) + 1 > 80)
			break;
	}
	fclose(f1);
	f1 = fopen(argv[1],"a");
	fputc('\n',f1);
	fputs(result ,f1);
	fclose(f1);
	cout << "Success";
	return 0;	
}
