#include<stdio.h> 

int main() 
{ 
 
  int i,j,n,Time,process,Boole=0,slice; 
  int waitTime=0,turnTime=0,arrival_Time[10],burst_Time[10],remaining_Time[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  process=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time for Process Number %d :",i+1); 
    scanf("%d",&arrival_Time[i]); 
    printf("Enter Burst Time for Process Number %d :",i+1);
    scanf("%d",&burst_Time[i]); 
    remaining_Time[i]=burst_Time[i]; 
  } 
  printf("Enter Time slice:\t"); 
  scanf("%d",&slice); 
printf("\n the turnaround Time and waiting Time for the given data is\n");
printf("\nprocess\t|Arrival Time\t|burst Time \n\n");
for(i=0;i<n;i++)
{
   printf("%d\t|\t%d\t|\t%d",i+1,arrival_Time[i],burst_Time[i]);
   printf("\n");
}
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(Time=0,i=0;process!=0;) 
  { 
    if(remaining_Time[i]<=slice && remaining_Time[i]>0) 
    { 
      Time=Time+remaining_Time[i]; 
      remaining_Time[i]=0; 
      Boole=1; 
    } 
    else if(remaining_Time[i]>0) 
    { 
      remaining_Time[i]=remaining_Time[i]-slice; 
      Time=Time+slice; 
    } 
    if(remaining_Time[i]==0 && Boole==1) 
    { 
      process=process-1; 
      printf("Process[%d]\t|\t%d\t|\t%d\n",i+1,Time-arrival_Time[i],Time-arrival_Time[i]-burst_Time[i]); 
      waitTime=waitTime+Time-arrival_Time[i]-burst_Time[i]; 
      turnTime=turnTime+Time-arrival_Time[i]; 
      Boole=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(arrival_Time[i+1]<=Time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",waitTime*1.0/n); 
  printf("Avg Turnaround Time = %f",turnTime*1.0/n); 
  
  return 0; 
}
