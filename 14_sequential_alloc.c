#include <stdio.h>

int main() {
    int n;

    printf("Enter number of records: ");
    scanf("%d", &n);

    char records[n][50];

    printf("Enter records:\n");
    for (int i = 0; i < n; i++) {
        printf("Record %d: ", i);
        scanf("%s", records[i]);
    }

    while (1) {
        int choice, k;
        printf("\nMenu:\n");
        printf("1. Display all records\n");
        printf("2. Access a record (sequential)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Stored Records:\n");
            for (int i = 0; i < n; i++)
                printf("%d: %s\n", i, records[i]);
        }
        else if (choice == 2) {
            printf("Enter record number to access: ");
            scanf("%d", &k);

            if (k < 0 || k >= n) {
                printf("Invalid record number!\n");
                continue;
            }

            printf("\nSequential access simulation:\n");
            for (int i = 0; i <= k; i++)
                printf("Reading record %d: %s\n", i, records[i]);

            printf("Successfully accessed record %d.\n", k);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
