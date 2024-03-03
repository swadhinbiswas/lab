#include <stdio.h>

#define MAX_TRAIN_LENGTH 50

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solve_train_swapping(int current_order[], int length) {
    int swaps = 0;
    for (int i = 0; i < length - 1; i++) {
        if (current_order[i] != i + 1) {
            // Find the index of the carriage with the correct value
            int correct_index = -1;
            for (int j = i + 1; j < length; j++) {
                if (current_order[j] == i + 1) {
                    correct_index = j;
                    break;
                }
            }

            // Swap the carriages and increment swaps
            if (correct_index != -1) {
                swap(&current_order[i], &current_order[correct_index]);
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int i = 0; i < num_test_cases; i++) {
        int length;
        scanf("%d", &length);

        int current_order[MAX_TRAIN_LENGTH];
        for (int j = 0; j < length; j++) {
            scanf("%d", &current_order[j]);
        }

        int swaps = solve_train_swapping(current_order, length);

        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }

    return 0;
}
