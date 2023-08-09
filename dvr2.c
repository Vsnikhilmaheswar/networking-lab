#include <stdio.h>

#define MAX_NODES 10
#define INFINITY 9999

void distanceVector(int graph[MAX_NODES][MAX_NODES], int distance[MAX_NODES][MAX_NODES], int nodes) {
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

int main() {
    int nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int distance[MAX_NODES][MAX_NODES];
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            distance[i][j] = graph[i][j];
        }
    }

    distanceVector(graph, distance, nodes);

    printf("Shortest distances and paths:\n");
    for (int i = 0; i < nodes; i++) {
        printf("From node %d:\n", i);
        for (int j = 0; j < nodes; j++) {
            printf("To node %d: Distance = %d, Path = ", j, distance[i][j]);
            if (distance[i][j] == INFINITY) {
                printf("Unreachable");
            } else {
                printf("%d", i);
                int next = i;
                while (next != j) {
                    next = distance[next][j];
                    printf(" -> %d", next);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
