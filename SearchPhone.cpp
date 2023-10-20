#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODEL_LEN 50

struct PhoneData {
    char phoneModel[MAX_MODEL_LEN];
    int memorySpace;
    float screenSize;
    float price;
};

void printPhoneData(struct PhoneData phone) {
    printf("%-30s%-15d%-15.2f%-15.2f\n", phone.phoneModel, phone.memorySpace, phone.screenSize, phone.price);
}

struct PhoneData* loadPhoneData(int* numPhones) {
    FILE* file = fopen("PhoneDB.txt", "r");
    if (file == NULL) {
        printf("Khong the mo tep PhoneDB.txt.\n");
        return NULL;
    }

    struct PhoneData* phoneDatabase = NULL;
    *numPhones = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) {
        (*numPhones)++;
        phoneDatabase = (struct PhoneData*)realloc(phoneDatabase, (*numPhones) * sizeof(struct PhoneData));

        sscanf(line, "%s %d %f %f", phoneDatabase[*numPhones - 1].phoneModel,
               &phoneDatabase[*numPhones - 1].memorySpace,
               &phoneDatabase[*numPhones - 1].screenSize,
               &phoneDatabase[*numPhones - 1].price);
    }

    fclose(file);
    return phoneDatabase;
}

void printEntireDatabase(struct PhoneData* phoneDatabase, int numPhones) {
    if (phoneDatabase == NULL || numPhones == 0) {
        printf("Co so du lieu trong.\n");
        return;
    }

    printf("%-30s%-15s%-15s%-15s\n", "Model", "Memory Space (GB)", "Screen Size (inches)", "Price");
    for (int i = 0; i < numPhones; i++) {
        printPhoneData(phoneDatabase[i]);
    }
}

void searchByModelName(struct PhoneData* phoneDatabase, int numPhones, const char* modelName) {
    if (phoneDatabase == NULL || numPhones == 0) {
        printf("Co so du lieu trong.\n");
        return;
    }

    for (int i = 0; i < numPhones; i++) {
        if (strcmp(phoneDatabase[i].phoneModel, modelName) == 0) {
            printf("Tim thay dien thoai:\n");
            printf("%-30s%-15s%-15s%-15s\n", "Model", "Memory Space (GB)", "Screen Size (inches)", "Price");
            printPhoneData(phoneDatabase[i]);
            return;
        }
    }

    printf("Khong tim thay dien thoai co model: %s\n", modelName);
}

int main() {
    struct PhoneData* phoneDatabase = NULL;
    int numPhones = 0;
    int userChoice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Import DB from text\n");
        printf("2. Import from DB\n");
        printf("3. Print Entire Database\n");
        printf("4. Search by Phone Model Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        getchar();
        
        switch (userChoice) {
            case 1:
                phoneDatabase = loadPhoneData(&numPhones);
                if (phoneDatabase != NULL) {
                    printf("Import successful.\n");
                }
                break;
            case 2:
                if (phoneDatabase != NULL) {
                    printf("1. Read the entire database\n");
                    printf("2. Read a part of the database\n");
                    printf("Enter your choice: ");
                    int subChoice;
                    scanf("%d", &subChoice);
                    getchar(); 

                    if (subChoice == 1) {
                        printEntireDatabase(phoneDatabase, numPhones);
                    } else if (subChoice == 2) {
                        int start, end;
                        printf("Enter the starting record number: ");
                        scanf("%d", &start);
                        printf("Enter the ending record number: ");
                        scanf("%d", &end);

                        if (start < 1 || end > numPhones || start > end) {
                            printf("Khoang khong hop le.\n");
                        } else {
                            printf("%-30s%-15s%-15s%-15s\n", "Model", "Memory Space (GB)", "Screen Size (inches)", "Price");
                            for (int i = start - 1; i < end; i++) {
                                printPhoneData(phoneDatabase[i]);
                            }
                        }
                    }
                } else {
                    printf("Co so du lieu chua duoc nap.\n");
                }
                break;
            case 3:
                printEntireDatabase(phoneDatabase, numPhones);
                break;
            case 4:
                if (phoneDatabase != NULL) {
                    char modelName[MAX_MODEL_LEN];
                    printf("Enter the model to search for: ");
                    fgets(modelName, sizeof(modelName), stdin);
                    modelName[strcspn(modelName, "\n")] = 0; 

                    searchByModelName(phoneDatabase, numPhones, modelName);
                } else {
                    printf("Co so du lieu chua duoc nap.\n");
                }
                break;
            case 5:
                if (phoneDatabase != NULL) {
                    free(phoneDatabase);
                }
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
// Du lieu chay thu
//iPhone_13_Pro 128 6.1 999
//Samsung_Galaxy_S21 256 6.2 899
//Oppo_F19 64 6.5 329
//Huawei_P50 128 6.3 799
//iPhone_12 64 6.1 799
//Samsung_Galaxy_Note_20_Ultra 512 6.9 1299
//Oppo_Reno_6 128 6.4 449
//Huawei_Nova_7i 128 6.4 329
//iPhone_SE 64 4.7 399
//Samsung_Galaxy_A52 128 6.5 349
//Oppo_A74 128 6.43 299
//Huawei_P40 128 6.1 699
//iPhone_11 128 6.1 699
//Samsung_Galaxy_Z_Fold_3 256 7.6 1799
//Oppo_A15 32 6.52 169
//Huawei_Y9a 128 6.63 279
//iPhone_XR 64 6.1 599
//Samsung_Galaxy_M32 64 6.4 249
//Oppo_Find_X3_Pro 256 6.7 1199
//Huawei_Mate_40_Pro 256 6.76 1199
