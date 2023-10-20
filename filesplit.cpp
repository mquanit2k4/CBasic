#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc != 5)
	{
		cout << "Vui long nhap dung cu phap filesplit <input_file> <N> <output_file1> <output_file2>\n";
		return 1;
	}
	
	FILE *input , *output1 , *output2;
	input = fopen(argv[1] , "rb");
	int N = atoi(argv[2]);
	output1 = fopen(argv[3], "wb");
	output2 = fopen(argv[4], "wb");
	
	if (input == NULL || output1 == NULL || output2 == NULL)
	{
		cout << "Loi khi mo file.\n";
		return 1;
	}
	
	char soDienThoai[15];
	int count = 0 ;
	while(fgets(soDienThoai, sizeof(soDienThoai) , input))
	{
		if (count < N)
			fprintf(output1, "%s" , soDienThoai);
		else
			fprintf(output2, "%s" , soDienThoai);
		count ++ ;
	}
	fclose(input);
	fclose(output1);
	fclose(output2);
	cout << "Tach thanh cong.\n";
	return 0;	
}
