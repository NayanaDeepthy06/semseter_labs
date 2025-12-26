#include <stdio.h>

int readCount = 0;   // number of readers
int writing = 0;     // writer status

int main() {
    int choice;

    while (1) {
        printf("\n--- Readers Writers Menu ---");
        printf("\n1. Reader wants to read");
        printf("\n2. Writer wants to write");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Reader
            if (writing == 1) {
                printf("Reader is WAITING (Writer is writing)\n");
            } else {
                readCount++;
                printf("Reader is READING (Readers count = %d)\n", readCount);

                // Reader finishes reading
                readCount--;
                printf("Reader finished reading (Readers count = %d)\n", readCount);
            }
            break;

        case 2: // Writer
            if (readCount > 0 || writing == 1) {
                printf("Writer is WAITING (Readers are reading)\n");
            } else {
                writing = 1;
                printf("Writer is WRITING\n");

                // Writer finishes writing
                writing = 0;
                printf("Writer finished writing\n");
            }
            break;

        case 3:
            printf("Program terminated.\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

