#include<stdio.h>
int main(){
    int i,j,n;
    int bt[10],wt[10],tat[10],temp;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number of process:");
    scanf("%d",&n);
    wt[0]=0;
    for(i=0;i<n;i++){
        printf("Enter the burst time for the  P%d",i);
        scanf("%d",&bt[i]);
    }
    // sorting the burst time 
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    // calculating the waiting time 
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
    // calculating turning around time 
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avg_wt+= wt[i];
        avg_tat+=tat[i];

    }
    avg_wt = avg_wt/n;
    avg_tat = avg_tat/n;
    printf("Process\tBurst time\twaiting time \tturn around time\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time is :%f",avg_wt);
    printf("Average turn around time :%f",avg_tat);
}