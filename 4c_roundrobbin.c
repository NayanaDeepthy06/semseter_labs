#include<stdio.h>
int main(){
    int n,i;
    int bt[10],wt[10],tat[10],rt[10];
    int time =0,completed =0;
    int tq;
    float avg_wt=0,avg_tat=0;
    printf("enter the number of processes:");
    scanf("%d",&n);
    printf("enter the time quantum :");
    scanf("%d",&tq);
    // taking burst time values 
    for(i=0;i<n;i++){
        printf("enter the burst time for each process P%d",i);
        scanf("%d",&bt[i]);
    }
    // assinging intially rt = bt and wt =0
    for(i=0;i<n;i++){
        rt[i]=bt[i];
        wt[i]=0;
    }
    while(completed<n){
        for(i=0;i<n;i++){
            if(rt[i]>0){
                if(rt[i]>tq){
                    rt[i]-=tq;
                    time+=tq;
                }
                else{
                    time+=rt[i];
                    wt[i]=time-bt[i];
                    rt[i]=0;
                    completed++;
                }
            }
        }
    }
    // calculating turn around time 
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }

    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time is :%f\n",avg_wt/n);
    printf("Average turn around time is :%f\n",avg_tat/n);
    return 0;
}