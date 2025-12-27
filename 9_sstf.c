#include <stdio.h>
#include <stdlib.h>   // for abs()

int main() {
    int n, head, i, j;
    int request[20];
    int visited[20] = {0};
    int total_seek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Head Movement:\n");

    for(i = 0; i < n; i++) {
        int min = 9999;
        int pos = -1;

        // find nearest request
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(request[j] - head);
                if(distance < min) {
                    min = distance;
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        total_seek += min;

        printf("Disk head moves from %d to %d with seek %d\n",
               head, request[pos], min);

        head = request[pos];
    }

    printf("\nTotal Seek Time = %d\n", total_seek);
    printf("Average Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
