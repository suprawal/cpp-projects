#include <stdio.h>
#include <stdbool.h>

int set[20], subset[20];
int n;

// Function to print subset
void printSubset(int k) {
    printf("{ ");
    for (int i = 0; i < k; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

// Function to check subset sum and store elements
bool subsetSum(int sum, int index, int k) {
    // Base case: reached end of array
    if (index == n)
        return false;

    // If current element equals remaining sum
    if (set[index] == sum) {
        subset[k] = set[index];
        printSubset(k + 1);
        return true;
    }

    // Iterate from current index to end
    for (int i = index; i < n; i++) {
        if (set[i] > sum)
            continue;  // skip elements greater than sum

        subset[k] = set[i];
        // recursively call for next index with remaining sum
        if (subsetSum(sum - set[i], i + 1, k + 1))
            return true;  // stop at first valid subset
    }

    return false;
}

int main() {
    int target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubset(s) with sum %d:\n", target);
    if (!subsetSum(target, 0, 0))
        printf("No subset found.\n");

    return 0;
}