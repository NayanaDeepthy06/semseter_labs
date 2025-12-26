#include<stdio.h>
int full =0;
int buffer =0;
int main(){
    int item,choice;
    while(1){
        printf("Producer consumer menu!!.....\n");
        printf("1.produce an item\n");
        printf("2.consume an item\n");
        printf("3.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(full==1){
                    printf("buffer is full ,producer is waiting \n");
                }
                else{
                    printf("enter the item u want to produce :");
                    scanf("%d",&item);
                    buffer = item;
                    full =1;
                    printf("produced item is :%d\n",buffer);
                }
                break;
            case 2:
                 if(full == 0){
                    printf("buffer is empty,consumer is waiting\n");
                 } 
                 else{
                    printf("consumed item is :%d\n",buffer);
                    full =0;
                 }   
                 break;
            case 3:
                printf("exiting the proggarm\n");
                return 0;
            default:
            printf("entered wrong choice\n");
        }


    }
  
}