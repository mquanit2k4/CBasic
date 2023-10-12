#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
char* subStr(char* s1, int offset, int number)
{
	if (s1 == NULL || offset < 0 || number <= 0)
		return NULL;
	int size = strlen(s1);
	if (offset > size )
		return "";
	if (number > size - offset)
		number = size - offset;
	char *result = (char*)malloc(number + 1);
	if (result == NULL)
		return NULL;
	strncpy(result , s1 + offset , number);
	result[number] = '\0';
	return result;
}
int main()
{
	char s1[1000];
	int offset , number;
	cout << "Vui long nhap xau ki tu: ";
	fgets(s1, sizeof(s1), stdin);
	cout << "Nhap vi tri can tach: ";
	cin >> offset;
	cout << "Nhap so luong ky tu can tach: ";
	cin >> number;
	char *ketqua = subStr(s1, offset , number);
	cout << "Xau da tach la: "<< ketqua ;
	return 0;	
}
