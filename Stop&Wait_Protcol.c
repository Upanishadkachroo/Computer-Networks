#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int send_packet(int packt) {
    printf("Sender: Sending packet %d ..\n", packt);
    return packt;
}

int recieve_packt(int packt, float loss_probabilty) {
    if ((rand() % 100) < (loss_probabilty * 100)) {
        printf("Receiver: packet %d lost\n", packt);
        return 0;
    }
    printf("Receiver: packet %d received successfully\n", packt);
    return 1;
}

void send_ack(int packt) {
    printf("Receiver: sending ack for the packet %d\n", packt);
}

int recieve_ack(int packt, float loss_probablity) {
    if ((rand() % 100) < (loss_probablity * 100)) {
        printf("Sender: ack for packet %d lost\n", packt);
        return 0;
    }
    printf("Sender: ack for packet %d received\n", packt);
    return 1;
}

void stop_wait(int total_packts, float loss_probablity) {
    int packt = 1;
    while (packt <= total_packts) {
        int sent = send_packet(packt);
        if (recieve_packt(sent, loss_probablity)) {
            send_ack(sent);
            if (recieve_ack(sent, loss_probablity)) {
                packt++;
            } else {
                printf("Sender: Resending packet %d due to ack loss\n", packt);
            }
        } else {
            printf("Sender: Resending packet %d due to packet loss\n", packt);
        }
    }
    printf("All packets sent and acknowledged successfully\n");
}

int main() {
    int total_packts;
    float loss_probability;
    printf("Enter the number of packets to be sent: ");
    scanf("%d", &total_packts);
    printf("Enter the probability of packet/ACK (scale: 0-1): ");
    scanf("%f", &loss_probability);
    srand(time(0));
    stop_wait(total_packts, loss_probability);
}
