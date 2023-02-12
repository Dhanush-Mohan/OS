#include<stdio.h>
int main()
{
	int n;
	float tat=0,twt=0;
	float awt,atat;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int pid[n];
	int bt[n];
	int wt[n];
	int i;
	printf("\nEnter the process id of all the processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);		
	}
	printf("\nEnter the burst time of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	printf("\nProcess ID\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t",pid[i]);
		printf("%d\t\t\t",bt[i]);
		printf("%d\t\t\t\t",wt[i]);
		printf("%d",bt[i]+wt[i]);
		printf("\n");
		twt+=wt[i];
		tat+=(wt[i]+bt[i]);
	}
	awt=twt/n;
	atat=tat/n;
	printf("Average Waiting Time: %f",awt);
	printf("\nAverage Turnaround Time: %f",atat);
	
	return 0;
}
