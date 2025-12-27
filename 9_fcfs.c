#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i;
    int request[20];
    int total_seek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Head Movement:\n");
    for(i = 0; i < n; i++) {
        int seek = abs(request[i] - head);
        printf("Disk head moves from %d to %d with seek %d\n",
                head, request[i], seek);
        total_seek += seek;
        head = request[i];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
