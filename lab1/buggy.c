#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* get_name() {
    char *name = malloc(20);
    if (name == NULL) {
        exit(1);
    }
    printf("Enter a name: ");
    scanf("%19s", name);
    return name;
}

int main() {
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);

    if (n <= 0) {
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    double avg = (double)sum / n;

    char *name = get_name();

    printf("Hello %s!\n", name);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    free(name);
    free(arr);
    
    return 0;
}
