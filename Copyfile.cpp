#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)

// Sao cheo theo ky tu
void saoChepKyTu (FILE *nguon, FILE *dich)
{
	char result[1024];
	clock_t start = clock();
	while (!feof(nguon))
	{
		size_t dungluong = fread(result , 1 , sizeof(result) , nguon);
		if (dungluong > 0)
			fwrite(result , 1 , dungluong , dich);			
	}
	clock_t end = clock();
	double runTime = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Sao chep thanh cong ky tu trong %.2lf ms.\n", runTime);
}

// Sao chep theo dong
void saoChepDong (FILE *nguon, FILE *dich)
{
	char line[1024];
	clock_t start = clock();
	while (fgets(line, sizeof(line), nguon) != NULL)
		fputs(line, dich);
	clock_t end = clock();
	double runTime = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Sao chep thanh cong dong trong %.2lf ms.\n", runTime);
}

void saoChepBlock (FILE *nguon, FILE *dich , size_t blockSize)
{
	char *buffer = (char *)malloc(blockSize);
	clock_t start = clock();
	size_t dungluong;
	while ((dungluong  = fread(buffer, 1, blockSize , nguon)) > 0)
		fwrite(buffer, 1, dungluong, dich);
	clock_t end = clock();
	double runTime = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
	printf("Sao chep thanh cong block (%zu bytes) trong %.2lf ms.\n", blockSize, runTime);
}
int main()
{
	char sourceFileName[256];
    char destinationFileName[256];
    int choice;
    size_t blockSize = 1024;

    printf("Nhap ten tap tin nguon: ");
    scanf("%s", sourceFileName);
    printf("Nhap ten tap tin dich: ");
    scanf("%s", destinationFileName);

    FILE *source = fopen(sourceFileName, "rb");
    if (source == NULL) {
        printf("Loi: Khong the mo tap tin nguon.\n");
        return 1;
    }

    FILE *destination = fopen(destinationFileName, "wb");
    if (destination == NULL) {
        printf("Loi: Khong the mo tap tin dich.\n");
        fclose(source);
        return 1;
    }

    if (fseek(source, 0, SEEK_END) != 0) {
        printf("Loi: Khong the di chuyen con tro tap tin nguon.\n");
        fclose(source);
        fclose(destination);
        return 1;
    }

    long fileSize = ftell(source);

    fseek(source, 0, SEEK_SET);

    while (1) {
        printf("\nChon chuc nang sao chep:\n");
        printf("1. Copy by character\n");
        printf("2. Copy by line\n");
        printf("3. Copy by block - optional size\n");
        printf("4. Quit\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                saoChepKyTu(source, destination);
                break;
            case 2:
                saoChepDong(source, destination);
                break;
            case 3:
                printf("Nhap kich thuoc block (bytes): ");
                scanf("%zu", &blockSize);
                saoChepBlock (source, destination, blockSize);
                break;
            case 4:
                fclose(source);
                fclose(destination);
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    }


	return 0;	
}
