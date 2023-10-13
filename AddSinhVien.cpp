#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
struct SinhVien 
{
	int stt;
	int mssv;
	char hoten[100];
	char sdt[15];
	float diem;
};
int main()
{
	FILE *f1 , *f2;
	f1 = fopen("danhsach.txt","r");
	f2 = fopen("bangdiem.txt","w");
	if (f1 == NULL || f2 == NULL)
	{
		cout << "Khong the mo tep tin/n";
		return 1;
	}
	int maxSV = 10;
	struct SinhVien *list = (struct SinhVien*)malloc(maxSV * sizeof(struct SinhVien));
	int count = 0;
	while (fscanf(f1, "%d %d %s %s", &list[count].stt , &list[count].mssv , &list[count].hoten , &list[count].sdt) != EOF)
	{
		count ++ ;
		if (count >= maxSV)
		{
			maxSV *= 2;
			list = (struct SinhVien*)realloc(list, maxSV * sizeof(struct SinhVien));
		}
	}
	for (int i = 0 ; i < count ; i++)
	{
		printf("Nhap diem cho sinh vien %d [MSSV: %d] :", i+1, list[i].mssv);
		scanf("%f", &list[i].diem);	
	}
	cout << "Ban co muon nhap them thong tin sinh vien? [Y]/[N]: ";
	char c;
	cin >> c;
	if (c == 'Y')
	{
		int addSV;
		cout << "Nhap so luong sinh vien can them: ";
		cin >> addSV;
		for (int i = 0 ; i < addSV ; i++)
		{
			printf("Nhap thong tin cho sinh vien %d:\n", count + 1);
	        printf("Nhap STT: ");
	        scanf("%d", &list[count].stt);
	        printf("Nhap Ma SV: ");
	        scanf("%d", &list[count].mssv);
	        printf("Nhap Ho va ten: ");
	        scanf("%s", &list[count].hoten);
	        printf("Nhap So dien thoai: ");
	        scanf("%s", &list[count].sdt);
	        printf("Nhap Diem: ");
	        scanf("%f", &list[count].diem);
	        count++;
		}
	}
	for (int i = 0 ; i < count ; i++ )
		fprintf(f2, "%d %d %s %s %.2f\n", list[i].stt , list[i].mssv , list[i].hoten , list[i].sdt , list[i].diem);
	
	fclose(f1);
	fclose(f2);
	cout << "Success";
	return 0;	
}
