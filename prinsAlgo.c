#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, ne = 1;
    int min, mincost = 0;
    int a = -1, b = -1;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input cost adjacency matrix
    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (no edge)
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Start from first vertex
    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(ne < n) {
        min = INF;
        a = -1;
        b = -1;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        // Check if graph is disconnected
        if(a == -1 || b == -1) {
            printf("\nGraph is not connected!\n");
            break;
        }

        printf("%d -> %d = %d\n", a, b, min);

        visited[b] = 1;
        mincost += min;
        ne++;
    }

    printf("\nMinimum cost of spanning tree = %d\n", mincost);

    return 0;
}
