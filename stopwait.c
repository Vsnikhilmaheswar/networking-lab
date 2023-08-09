#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void sender(int seq) {
    printf("SENDER: Sending packet with sequence number: %d\n", seq);
    sleep(1);
    int ack = rand() % 2;  

    if (ack) {
        printf("SENDER: Received ACK for packet %d\n", seq);
    } else {
        printf("SENDER: Packet %d lost, retransmitting...\n", seq);
    }
}
void receiver(int seq) {
printf("RECEIVER: Received packet with sequence number: %d\n", seq);
    sleep(1);  

    
    int ack = rand() % 2;  // 0 for not sending ACK, 1 for sending ACK

    if (ack) {
        printf("RECEIVER: Sending ACK for packet %d\n", seq);
    } else {
        printf("RECEIVER: Not sending ACK for packet %d\n", seq);
    }
}

int main() {
    int totalPackets = 5;  

    
    for (int seq = 0; seq < totalPackets; seq++) {
        sender(seq);   
        receiver(seq);
    }

    return 0;
}
