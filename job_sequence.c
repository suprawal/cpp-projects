#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

// Sort jobs in descending order of profit
int compare(const void *a, const void *b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;
    return j2->profit - j1->profit;
}

int main() {
    int n;
 int m;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    // Input jobs
    for (int i = 0; i < n; i++) {
        printf("\nJob %d\n", i + 1);
        printf("Enter Job ID: ");
        scanf("%d", &jobs[i].id);
        printf("Enter Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Enter Profit: ");
        scanf("%d", &jobs[i].profit);
    }

    // Sort jobs by profit
    qsort(jobs, n, sizeof(jobs[0]), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    // Job sequencing
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output
    printf("\nSelected Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%d ", jobs[slot[i]].id);
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}
