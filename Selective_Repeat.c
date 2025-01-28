#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    srand(time(NULL));

    int total_frames, window_size;

    printf("Enter the total number of total frames: ");
    scanf("%d", &total_frames);

    printf("Enter the window size: ");
    scanf("Z%d", &window_size);

    int window_start=0;
    int window_end=window_size-1;
    bool ack[total_frames];

    for(int i=0; i<total_frames; i++){
        ack[i]=false;
    }

    printf("\nSelective Repeat Protocol Simulation\n");

    while(window_start<total_frames){
        for(int i=window_start; i<=window_end && i<total_frames; i++){
            if(!ack[i]){
                printf("Sending frame: %d\n", i);
            }
        }
    }
}