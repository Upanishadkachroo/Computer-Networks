#include<stdio.h>
#include<stdlib.h>

void stop_wait(int total_packts, int loss_probablity){
    
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