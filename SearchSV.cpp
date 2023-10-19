#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef struct SinhVien {
	int mssv;
	char hoten[50];
	float diem;
} SV;
int numOfSinhVien;
SV* docFileBangDiem (char *nameOfFile)
{
	FILE *f1;
	f1 = fopen(nameOfFile,"r");
	if (f1 == NULL)
		return NULL;
	
	fscanf(f1, "%d" , &numOfSinhVien);
	SV *list = (SV*)malloc(numOfSinhVien * sizeof(SV));
	if (list == NULL)
	{
		fclose(f1);
		return NULL;
	}
	
	for (int i = 0 ; i < numOfSinhVien ; i++)
		fscanf(f1, "%d %s %f" , &list[i].mssv , list[i].hoten , &list[i].diem);
	fclose(f1);
	return list;
}

void ghiDuLieu (char* dataFile , SV* list , int numOfSinhVien )
{
	FILE* f2;
	f2 = fopen(dataFile,"wb");
	if (f2 == NULL)
		return;
	fwrite(&numOfSinhVien, sizeof(int), 1 , f2);
	fwrite(list, sizeof(SV) , numOfSinhVien , f2);
	fclose(f2);
}

void hienThiData (char* dataFile)
{
	FILE* f2;
	f2 = fopen(dataFile,"rb");
	if (f2 == NULL)
		return;
		
	int numOfSinhVien;
	fread(&numOfSinhVien , sizeof(int) , 1 , f2);
	SV* list = (SV*)malloc(numOfSinhVien *sizeof(SV));
	cout << numOfSinhVien<<endl;
	fread(list , sizeof(SV) , numOfSinhVien , f2);
	for (int i = 0 ; i < numOfSinhVien ; i++)
		printf("MSSV: %d, Ho va ten: %s , Diem: %.2f\n" , list[i].mssv , list[i].hoten, list[i].diem);
	free(list);
	fclose(f2);
}

void findSinhVien (SV* list, int numOfSinhVien , int MSSV , float diemMoi)
{
	for (int i = 0 ; i < numOfSinhVien ; i++)
		if (list[i].mssv == MSSV)
		{
			list[i].diem = diemMoi;
			break;
		}
}
int main()
{
	SV* list = NULL;
	int numOfSinhVien = 0;
	int choice;
	while (1)
	{
		cout << "Chon chuc nang: \n";
		cout << "1. TextToDat\n";
		cout << "2. Display Dat\n";
		cout << "3. Search and Update\n";
		cout << "4. Quit\n";
		cout << "Vui long chon: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
 				list = docFileBangDiem("bangdiem.txt");
//				numOfSinhVien = list[0].mssv;
				ghiDuLieu("grade.dat", list , numOfSinhVien);
				free(list);
				cout << "Chuyen du lieu sang tep Dat thanh cong. \n";
				break;
			case 2:
				hienThiData("grade.dat");
				break;
			case 3:
				int MSSV;
				float diemMoi;
				cout << "Nhap MSSV can tim kiem: ";
				cin >> MSSV;
				cout << "Nhap diem moi: ";
				cin >> diemMoi;
				findSinhVien(list , numOfSinhVien , MSSV , diemMoi);
				ghiDuLieu("grade.dat", list , numOfSinhVien);
				cout << "Da cap nhat diem cho sinh co MSSV " << MSSV <<".\n";
				break;
			case 4:
				free(list);
				return 0;
			default:
				cout << "Lua chon khong hop le. \n";
				break;
		}		
	}
	return 0;	
}
