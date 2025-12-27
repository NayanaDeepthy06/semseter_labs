#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], work[m], finish[n], safe[n];

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Max Matrix
    printf("\nEnter Max Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Available Resources
    printf("\nEnter Available Resources:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Calculate Need Matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Step 1: Work = Available
    for(int j = 0; j < m; j++)
        work[j] = avail[j];

    // Step 2: Finish = false
    for(int i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    // Step 3–5: Safety Algorithm
    while(count < n) {
        int found = 0;

        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m) {  // Need ≤ Work
                    for(int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state\n");
            return 0;
        }
    }

    // Safe State
    printf("\nSystem is in SAFE state\nSafe sequence: ");
    for(int i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}
