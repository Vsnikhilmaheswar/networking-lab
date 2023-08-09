#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main() {
    int bucketCapacity, outputRate, incomingRate;
    int bucketLevel = 0;

    printf("Congestion Control using Leaky Bucket\n");
    printf("------------------------------------\n");

    printf("Enter bucket capacity: ");
    scanf("%d", &bucketCapacity);

    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    printf("Enter incoming packet rate: ");
    scanf("%d", &incomingRate);

    printf("\nSimulation starting...\n");

    while (true) {
        if (bucketLevel > 0) {
            printf("Packet sent. Bucket size: %d\n", bucketLevel);
            bucketLevel--;
        }

        if (bucketLevel < bucketCapacity && incomingRate > 0) {
            bucketLevel++;
            printf("Packet added. Bucket size: %d\n", bucketLevel);
            incomingRate--;
        } else if (bucketLevel == bucketCapacity) {
            printf("Bucket full. Packet dropped.\n");
        }

        sleep(1); // Simulate time passing
    }

    return 0;
}
