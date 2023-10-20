#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Vui long nhap dung cu phap fileread <input_file> \n";
		return 1;
	}
	FILE *input;
	input = fopen(argv[1],"r");
	if (input == NULL)
	{
		cout << "Loi khi mo tep.\n";
		return 1;
	}
	char soDienThoai[15];
	while (fgets(soDienThoai , sizeof(soDienThoai), input))
		printf("%s", soDienThoai);
	fclose(input);
	return 0;	
}
