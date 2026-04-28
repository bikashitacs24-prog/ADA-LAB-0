#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print the current permutation
void printPermutation(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Find the largest mobile integer
int getMobile(int a[], int dir[], int n) {
    int mobile = 0;
    for(int i = 0; i < n; i++) {
        if(dir[a[i]-1] == LEFT && i != 0 && a[i] > a[i-1] && a[i] > mobile)
            mobile = a[i];
        if(dir[a[i]-1] == RIGHT && i != n-1 && a[i] > a[i+1] && a[i] > mobile)
            mobile = a[i];
    }
    return mobile;
}

// Generate permutations using Johnson–Trotter
void generatePermutations(int n) {
    int a[n], dir[n];
    for(int i = 0; i < n; i++) {
        a[i] = i+1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    for(int count = 1; count < n; count++) {
        int mobile;
        while((mobile = getMobile(a, dir, n)) != 0) {
            int pos;
            for(pos = 0; pos < n; pos++)
                if(a[pos] == mobile) break;

            // Swap according to direction
            if(dir[mobile-1] == LEFT) {
                int temp = a[pos];
                a[pos] = a[pos-1];
                a[pos-1] = temp;
            } else {
                int temp = a[pos];
                a[pos] = a[pos+1];
                a[pos+1] = temp;
            }

            // Update directions
            for(int i = 0; i < n; i++)
                if(a[i] > mobile)
                    dir[a[i]-1] = (dir[a[i]-1] == LEFT) ? RIGHT : LEFT;

            printPermutation(a, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    generatePermutations(n);
    return 0;
}
