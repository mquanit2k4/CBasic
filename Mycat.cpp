#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc < 2 || argc > 3)
	{
		cout << "Nhap dung cu phap: mycat <filename> [-p]" <<endl;
		return 1;
	}
	
	FILE *f1;
	f1 = fopen(argv[1],"r");
	if (f1 == NULL)
	{
		perror("Loi khi mo tep tin");
		return 1;
	}
	int page = 0;
	if (argc == 3)
	{
		if (strcmp(argv[2], "-p") == 0)
			page = 1;
		else
		{
			cout << "Nhap dung cu phap: mycat <filename> [-p]" <<endl;
			return 1;	
		}
	}
	
	char c;
	int line = 0;
	int pause = 0;
	int dem = 1;
	while ((c = fgetc(f1)) != EOF)
	{
		putchar(c);
		if ( c == '\n')
		{
			line++;
			if (page && line >= 24)
			{
				pause = 1;
				line = 0;	
			}
		}
	
		if (pause)
		{
			cout << "-----------------------------------------";
			cout << "\nNhan phim Enter de xem trang tiep theo\n";
			cout << "--------------Het trang " <<dem<<" --------------";
			char t = getchar();
			if (t == '\n')
				dem++;
			pause = 0;
		}
	}
	fclose(f1);
	return 0;	
}
