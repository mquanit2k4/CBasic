#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

struct SinhVien
{
	int stt;
	int mssv;
	char hoten[100];
	char sdt[11];
	float diem;
};
int main()
{
	FILE *f1, *f2;
	f1 = fopen("danhsach.txt", "r");
	f2 = fopen("bangdiem.txt","w");
	if (f1 == NULL || f2 == NULL)
	{
		cout << "Khong the mo tep tin\n";
		return 1;
	}
	struct SinhVien list[1000];
	int count = 0;
	while (fscanf(f1, "%d %d %s %s", &list[count].stt , &list[count].mssv , &list[count].hoten , &list[count].sdt) != EOF)
		count ++ ;
	for (int i = 0 ; i < count ; i++)
	{
		printf("Nhap diem cho sinh vien %d [MSSV: %d] :", i+1, list[i].mssv);
		scanf("%f", &list[i].diem);	
	}
	for (int i = 0 ; i < count ; i++)
		fprintf(f2, "%d %d %s %s %.2f\n", list[i].stt , list[i].mssv , list[i].hoten , list[i].sdt , list[i].diem);
	
	fclose(f1);
	fclose(f2);
	cout << "Ghi diem thanh cong";
	// Danh sach test voi ten tep la "danhsach.txt"
//1 20225910 Vu_Minh_Quan 0359739393
//2 20225595 Mach_Ngoc_Duc_Anh 0359723414
//3 20225124 Pham_Viet_Anh 0358744376
//4 20225932 Do_Hoang_Dong 0963569126
//5 20224465 Nguyen_Duc_Hau 0371289964
//6 20226423 Nguyen_Manh_Hung 0882134521
	return 0;	
}
