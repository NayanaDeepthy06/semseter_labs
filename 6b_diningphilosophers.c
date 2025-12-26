#include <stdio.h>

int main() {
    int n, i, choice, phil;

    printf("Enter number of philosophers: ");
    scanf("%d", &n);

    int chopstick[n];

    // Initialize all chopsticks as FREE (1)
    for (i = 0; i < n; i++)
        chopstick[i] = 1;

    while (1) {
        printf("\n--- Dining Philosophers Menu ---");
        printf("\n1. Philosopher Eats");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Program terminated.\n");
            break;
        }

        printf("Enter philosopher number (0 to %d): ", n - 1);
        scanf("%d", &phil);

        int left = phil;
        int right = (phil + 1) % n;

        if (chopstick[left] == 1 && chopstick[right] == 1) {
            chopstick[left] = 0;
            chopstick[right] = 0;

            printf("Philosopher %d is EATING using chopsticks %d and %d\n",
                   phil, left, right);

            // Release chopsticks after eating
            chopstick[left] = 1;
            chopstick[right] = 1;

            printf("Philosopher %d finished eating and released chopsticks\n", phil);
        } else {
            printf("Philosopher %d is WAITING (chopsticks busy)\n", phil);
        }
    }

    return 0;
}
