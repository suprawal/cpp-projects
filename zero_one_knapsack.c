#include <stdio.h>

int n, W;
int weight[20], value[20];
int maxValue = 0;

// Backtracking function
void knapsack(int i, int currWeight, int currValue) {
    if (i == n) {  // all items considered
        if (currValue > maxValue)
            maxValue = currValue;
        return;
    }

    // Include item i if it doesn't exceed capacity
    if (currWeight + weight[i] <= W) {
        knapsack(i + 1, currWeight + weight[i], currValue + value[i]);
    }

    // Exclude item i
    knapsack(i + 1, currWeight, currValue);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(0, 0, 0);

    printf("Maximum value in knapsack = %d\n", maxValue);

    return 0;
}