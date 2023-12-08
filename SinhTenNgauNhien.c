#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateRandomDOB(int *day, int *month, int *year) {
    *day = rand() % 28 + 1;
    *month = rand() % 12 + 1;
    *year = rand() % 20 + 1980;
}

void generateRandomName(char *name) {
    char *firstNames[] = {"Nguyen", "Tran", "Le", "Pham", "Hoang", "Vo", "Dang", "Vu", "Bui", "Do"};
    char *middleNames[] = {"Van", "Thi", "Duc", "Quang", "Anh", "Thi"};
    char *lastNames[] = {"Hoa", "Linh", "Tuan", "Minh", "Nam", "Trung", "Quyen", "Giang"};
    strcat(name, firstNames[rand() % 10]);
    strcat(name, " ");
    strcat(name, middleNames[rand() % 6]);
    strcat(name, " ");
    strcat(name, lastNames[rand() % 8]);
}

int main() {
    int n;
    printf("Nhap so luong ho so: ");
    scanf("%d", &n);
    srand(time(NULL));
    FILE *file = fopen("profile-n.txt", "w");
    for (int i = 1; i <= n; i++) {
        char name[100] = "";
        generateRandomName(name);
        int day, month, year;
        generateRandomDOB(&day, &month, &year);
        fprintf(file, "%s\n%04d-%02d-%02d\n", name, year, month, day);
    }
    fprintf(file, "#");
    fclose(file);
    printf("Da tao file profile-n.txt thanh cong.\n");
    
    return 0;
}
