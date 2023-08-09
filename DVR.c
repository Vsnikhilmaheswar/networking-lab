#include <stdio.h>

#define MAX_NODES 10
#define INFINITY 9999

void distanceVector(int graph[MAX_NODES][MAX_NODES], int distance[MAX_NODES], int nodes, int source) {
    for (int i = 0; i < nodes; i++) {
        distance[i] = INFINITY;
    }
    distance[source] = 0;

    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (distance[i] + graph[i][j] < distance[j]) {
                    distance[j] = distance[i] + graph[i][j];
                }
            }
        }
    }
}

int main() {
    int nodes, source;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    int distance[MAX_NODES];
    distanceVector(graph, distance, nodes, source);

    printf("Shortest distances from node %d:\n", source);
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

    return 0;
}
