#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>// for sleep function i.e sleep()

bool send_packt(int packt){
    if(rand()%10 < 2){
        printf("Packet %d lost during transmission\n", packt);
        return false;
    }
    printf("Packet %d sent successfully\n", packt);
    return true;
}

int main(){
    int window_size, total_packts;

    printf("Enter the window size: ");
    scanf("%d", &window_size);

    printf("Enter the totla number of packets: ");
    scanf("%d", &total_packts);

    int base=0;
    int nxt_sq_no=0;
    
    srand(time(NULL));
    while(base<total_packts){
        while(nxt_sq_no < base+window_size && nxt_sq_no<total_packts){
            if(send_packt(nxt_sq_no)){
                printf("Waiting for the ack of the packet %d \n", nxt_sq_no);
            }
            nxt_sq_no++;
        }

        int ack=base + (rand()%(nxt_sq_no-base+1));//random ack generation
        printf("Ack recieved from packet %d\n", ack);

        if(ack>=base){
            base=ack+1;//slide the window
        }
        else{
            printf("Ack for packet %d not recieved, retransmitting from packet %d\n", base, base);
            nxt_sq_no=base;
        }
        sleep(1);//to simulate delay
    }
    printf("All packets successfully sent\n");
    return 0;
}