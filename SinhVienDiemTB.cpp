#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef struct SinhVien 
{    
	char hoTen[100];
	int diemToan, diemLy, diemHoa;    
	float diemTB;	
	}SV;
void docData ( char *fileName , SV list[] , int *soSinhVien)
{    
	FILE* fileIn = fopen(fileName ,"r");    
	if (fileIn == NULL)    
	{        
		cout << "Khong the mo tep. \n";        
		return;    
	}    
	fscanf(fileIn , "%d" , soSinhVien);    
	fgetc(fileIn);    
	for (int i = 0 ; i < *soSinhVien ; i++)    
	{        
		fscanf(fileIn , "%[^0-9] %d %d %d" ,list[i].hoTen , &list[i].diemToan , &list[i].diemLy , &list[i].diemHoa );        
		list[i].diemTB = (float)(list[i].diemToan + list[i].diemLy + list[i].diemHoa )/3.0 ;        
	}    
	fclose(fileIn);
}
void ghiData (SV list[] , int soSinhVien , char *fileName)
{    
	FILE* fileOut = fopen(fileName , "wb");    
	if (fileOut == NULL)    
	{        
		printf("Khong the mo file.\n");
		return;    
	}    
	for (int i = 0 ;i < soSinhVien ; i ++)   
	{           
		fwrite(&list[i].hoTen ,sizeof(list), 1, fileOut);        
		fwrite(&list[i].diemTB, sizeof(float) , 1 ,fileOut);    
	}    
	fclose(fileOut);
}
int compare (const void*a ,const void*b)
{    
	SV *A = (SV*)a;    
	SV *B = (SV*)b;    
	return ((B->diemTB > A->diemTB) - (B->diemTB < A->diemTB));
}
int main()
{    
	struct SinhVien list[300];    
	int soSinhVien = 0 ;    
	docData("student.txt", list , &soSinhVien);    
	if(soSinhVien == 0)        
		return 1;    
	ghiData(list , soSinhVien , "student.dat");    
	qsort(list, soSinhVien , sizeof(struct SinhVien), compare);   
	printf("Danh sach sinh vien sap xep theo diem trung binh giam dan:\n");    
	for (int i = 0 ; i < soSinhVien ; i++)        
		printf("%s, co diem trung binh la: %.2f", &list[i].hoTen, list[i].diemTB);
//file student.txt
//5
//Nguyen Hong Phuong 8 8 9
//Nguyen Van An 6 9 7
//Nhu Thi Nga 4 5 7
//Tran Thi Dung 5 8 6
//Quach Manh Hao 9 6 5
	return 0;
}