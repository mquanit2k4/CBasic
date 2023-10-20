#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(int argc , char *argv[])
{
	if (argc != 4)
	{
		cout << "Vui long nhap dung cu phap filemerge <input_file1> <input_file2> <output_file>\n";
		return 1;
	}
	FILE *input1 , *input2 , *output;
	input1 = fopen(argv[1],"rb");
	input2 = fopen(argv[2],"rb");
	output = fopen(argv[3],"wb");
	
	if (input1 == NULL || input2 == NULL || output == NULL)
	{
		cout << "Khong the mo file.\n";
		return 1;
	}
	
	char soDienThoai[15];
	while (fgets(soDienThoai , sizeof(soDienThoai), input1))
		fprintf(output, "%s" , soDienThoai);
	
	while (fgets(soDienThoai , sizeof(soDienThoai), input2))
		fprintf(output, "%s" , soDienThoai);
	
	fclose(input1);
	fclose(input2);
	fclose(output);
	cout << "Ghep 2 file thanh cong.\n";
	return 0;	
}
