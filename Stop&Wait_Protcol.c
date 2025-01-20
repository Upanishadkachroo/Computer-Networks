#include<stdio.h>
#include<stdlib.h>

int send_packet(int packt){
    printf("Sender: Sending packet %d ..", packt);
    return packt;
}

int recieve_packt(int packt, float loss_probabilty){
    if((rand()%100) < (loss_probabilty*100)){
        printf("Receiver: packet %d lost", packt);
        return 0;
    }

    printf("Receiver: packet %d received successfully", packt);
    return 1;
}

void send_ack(int  packt){
    printf("Receiver: sending ack for the packet %d", packt);
}

int recieve_ack(int pakct, int loss_probablity){
    if((rand()%100) < (loss_probablity*100)){
        printf("Sender: ack for packet %d lost", pakct);
        return 0;
    }
    else{
        printf("Sender: ack for packet %d received", pakct);
        return 1;
    }
}

void stop_wait(int total_packts, int loss_probablity){
    int packt=1;

    while(packt <= total_packts){
        int sent=send_packt(packt);

        if(recieve_packt(sent, loss_probablity)){
            send_ack(sent);

            if(recieve_ack(sent, loss_probablity)){
                packt++;
            }else{
                printf("Sender: Resending packt %d due to ack loss", packt);
            }
        }
        else{
            printf("Sender: Resending packet %d due to packet loss", packt);
        }
    }
    printf("All packets send and acknowledged successfully");
}

int main(){
    int total_packts;
    float loss_probability;
    
    printf("Enter the number of packets to be send: ");
    scanf("%d", &total_packts);

    printf("Enter the probability of packet/ACK (scale: 0-1)");
    scanf("%f", &loss_probability);

    srand(time(0));//for random number generation

    stop_wait(total_packts, loss_probability);
}