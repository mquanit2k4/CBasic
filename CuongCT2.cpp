#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	char anh[21];
	char viet[21];
} Dictionary;


Dictionary dic[1001];

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void sortD(Dictionary dic[], int n)
{
	Dictionary tmp;
	for(int i = 0 ; i < n-1 ; i++)
		for(int j = i+1 ; j < n ; j++)
		{
			if (strcmp(dic[i].anh,dic[j].anh) > 0)
			{
				tmp = dic[i];
				dic[i] = dic[j];
				dic[j] = tmp;
			}
		}
}

int findWord(Dictionary dic[], int n, char x[])
{
	int lo = 0, hi = n-1;
	while(lo <= hi)
	{
		int mid = lo + (hi - lo)/2;
		if (strcmp(dic[mid].anh,x) == 0)
			return mid;
		else if(strcmp(dic[mid].anh,x) < 0)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return -1;
}
int main()
{
	char anh[21];
    char viet[21];
	FILE *f3 = fopen("C:\\Users\\admin\\Desktop\\C Basic\\data.txt", "r");
	if (f3 == NULL) {
		printf("Khong the mo tep.");
		return 1;
	}
	int i = 0;
		    
	char line[1001];
	
	while (fgets(line, sizeof(line), f3) != NULL) {
		sscanf(line, "%s\t%[^\n]", dic[i].anh, dic[i].viet);
		i++;	
    }
    int n = i;
	sortD(dic,n);
   	fclose(f3);    
    while(1)
    {
    	printf("-------------------------\n");
    	printf("1. Hien thi du lieu theo thu tu giam dan\n");
    	printf("2. Tra cuu tu dien\n");
    	printf("3. Dich Anh->Viet\n");
    	printf("4. Ghi lai thong tin vao file data.txt\n");
    	printf("5. Exit\n");
    	printf("-------------------------\n");
    	printf("Vui long chon chuc nang:\n");
    	int choice;
    	scanf("%d", &choice);
    	while (getchar() != '\n');
    	if (choice == 1)
    	{
    		for (int j = n-1 ; j > 0 ; j--)
		    	printf("%s\t%s\n", dic[j].anh , dic[j].viet);
		}
		else if (choice == 2)
		{
			char x[21];
		    printf("Vui long nhap tu can tra: ");
		    scanf("%s", x);
		    int res = findWord(dic,n,x);
		    if(res == -1)
		    {
		    	printf("Khong tim thay tu!\n");
			}
			else
			{
				printf("%s\t%s\n", dic[res].anh, dic[res].viet);
			}
		}
		else if (choice == 3)
		{
			char cau[1000];
			printf("Vui long nhap cau can dich: ");
			fgets(cau, sizeof(cau), stdin);
			toLowerCase(cau);
			char *token = strtok(cau, " \t\n");
			while (token != NULL) {
        		printf("%s\n", token);
        		token = strtok(NULL, " \t\n");
   			}
   			
   			char *check = strtok(cau, " \t\n");
   			while (check != NULL) {
		        int tmp = findWord(dic, n, check);
		        if (tmp == -1) {
		            char newWord[21];
		            printf("Thieu tu %s, vui long bo sung!\n", check);
		            n++;
		            // Nhập từ mới từ bàn phím
		            printf("Nhap dich cho tu %s: ", check);
		            scanf("%s\t%[^\n]", dic[n-1].anh, dic[n-1].viet);
		        }
		        check = strtok(NULL, " \t\n");
    		}
			   
		}
		else if (choice == 5)
		{
			return 0;
		}
	}
    
}