#include <stdio.h>
#include <string.h>

struct Submission {
    char userID[11];
    char problemID[4];
    char timePoint[9];
    char status[4];
    int point;
};

void swap(struct Submission *a, struct Submission *b) {
    struct Submission temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Submission arr[], int low, int high) {
    int pivot = arr[high].point;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].point >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(struct Submission arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
	
    const int maxSubmissions = 10000;
    const int maxQueries = 10000;

    struct Submission list[maxSubmissions];
    int n = 0;

    while (1) {
        char line[100];
        fgets(line, sizeof(line), stdin);

        if (line[0] == '#') {
            break;
        }

        sscanf(line, "%s %s %s %s %d",
               list[n].userID,
               list[n].problemID,
               list[n].timePoint,
               list[n].status,
               &list[n].point);

        n++;
    }

    char query[100];
    while(1)
    {
    	scanf("%s", query);
    	if (strcmp(query,"#") == 0)
    		break;
    	else if (strcmp(query,"?total_number_submissions") == 0)
    		printf("%d\n", n);
    	else if (strcmp(query,"?number_error_submision") == 0)
    	{
    		int errorCount = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].status, "ERR") == 0) {
                    errorCount++;
                }
            }
            printf("%d\n", errorCount);
		}
		else if (strcmp(query,"?number_error_submision_of_user") == 0)
		{
			char nameUser[11];
			scanf("%s", nameUser);
			int errorCount = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].userID, nameUser) == 0 && strcmp(list[i].status, "ERR") == 0) {
                    errorCount++;
                }
            }
            printf("%d\n", errorCount);
		}
		else if (strcmp(query,"?total_point_of_user") == 0)
		{
			char nameUser[11];
			scanf("%s", nameUser);
			quickSort(list, 0,n-1);
            for (int i = 0 ; i < n ; i++)
            {
                printf("%s %s %s %s %d\n", list[i].userID, list[i].problemID, list[i].timePoint, list[i].status, list[i].point);
            }
			int totalPoints;
			if (strcmp(list[0].userID, nameUser) == 0)
				totalPoints = list[0].point;
			else
				totalPoints = 0;
            for (int i = 0; i < n-1 ; i++) {
                if (strcmp(list[i].userID, nameUser) == 0 && strcmp(list[i].problemID,list[i+1].problemID) != 0 )
                        totalPoints += list[i+1].point;
        	}
            printf("%d\n", totalPoints);
		}else if (strcmp(query,"?number_submission_period") == 0)
		{
			char timeS[21];
			char timeE[21];
			scanf("%s %s", timeS, timeE);
			int periodCount = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].timePoint, timeS) >= 0 && strcmp(list[i].timePoint, timeE) <= 0) {
                    periodCount++;
                }
            }
            printf("%d\n", periodCount);
        }
	}
    return 0;
}
