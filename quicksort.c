#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 30000
#define NTIMES 5000

int partition(int a[], int low, int high) {
    int p = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && a[i] <= p)
            i++;
        while (j >= low && a[j] > p)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int s = partition(a, low, high);
        quicksort(a, low, s - 1);
        quicksort(a, s + 1, high);
    }
}

int main() {
    int a[MAXSIZE], i, n, k;
    clock_t start, end;
    double runtime = 0.0;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    if (n > MAXSIZE) {
        printf("Size should be less than or equal to %d\n", MAXSIZE);
        return 1;
    }

    srand(time(NULL));
    for (k = 0; k < NTIMES; k++) {
        for (i = 0; i < n; i++) {
            a[i] = rand();
        }

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        runtime += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    runtime /= NTIMES;

    printf("\nSorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    printf("Time taken for sorting is %lf seconds\n", runtime);

    return 0;
}
