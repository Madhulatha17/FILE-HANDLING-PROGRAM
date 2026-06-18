#include <stdio.h>
#include <stdlib.h>

void createFile() {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(fp);
}

void writeFile() {
    FILE *fp = fopen("data.txt", "w");
    char text[200];

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to write: ");
    getchar();
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);
    printf("Data written successfully.\n");

    fclose(fp);
}

void appendFile() {
    FILE *fp = fopen("data.txt", "a");
    char text[200];

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to append: ");
    getchar();
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);
    printf("Data appended successfully.\n");

    fclose(fp);
}

void readFile() {
    FILE *fp = fopen("data.txt", "r");
    char ch;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- File Content ---\n");

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    printf("\n---------------------\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE HANDLING MENU =====\n");
        printf("1. Create File\n");
        printf("2. Write File\n");
        printf("3. Append File\n");
        printf("4. Read File\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: appendFile(); break;
            case 4: readFile(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
