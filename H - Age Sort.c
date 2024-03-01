#include <stdio.h>

#define MAX_AGE 100

void sort_ages(int ages[], int n) {
    int counts[MAX_AGE + 1] = {0};  // Initialize counts array

    // Count the occurrences of each age
    for (int i = 0; i < n; i++) {
        counts[ages[i]]++;
    }

    // Accumulate counts for efficient retrieval of sorted ages
    for (int i = 1; i <= MAX_AGE; i++) {
        counts[i] += counts[i - 1];
    }

    int sorted_ages[n];  // Initialize output array

    // Fill sorted_ages in reverse order for stability
    for (int i = n - 1; i >= 0; i--) {
        sorted_ages[counts[ages[i]] - 1] = ages[i];
        counts[ages[i]]--;  // Decrement count for the next occurrence of the same age
    }

    // Copy sorted_ages back to the original array (optional)
    for (int i = 0; i < n; i++) {
        ages[i] = sorted_ages[i];
    }
}

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int ages[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &ages[i]);
        }

        sort_ages(ages, n);

        for (int i = 0; i < n; i++) {
            printf("%d ", ages[i]);
        }
        printf("\n");
    }

    return 0;
}
