#include<stdio.h>
int main()
{
	int n;
	float ttat=0,twt=0;
	float awt,atat;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int pid[n];
	int bt[n];
	int at[n];
	int wt[n];
	int ct[n];
	int tat[n];
	int i,j,temp,idle_time;
	printf("\nEnter the process id of all the processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);		
	}
	printf("\nEnter the arrival time of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nEnter the burst time of each process: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//Sorting the pid and bt using bubble sort....
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(at[j]>at[i])
			{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
				
			}
		}
	}
	int sum=0;
	sum+=at[0];
	for(i=0;i<n;i++)
	{
		sum+=bt[i];
		ct[i]=sum;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		if(sum<at[i+1])
		{
			int t=at[i+1]-sum;
			sum+=t;
		}
		
	}
	printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\t\tCompletion Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t",pid[i]);
		printf("%d\t\t\t",at[i]);
		printf("%d\t\t\t",bt[i]);
		printf("%d\t\t\t\t",wt[i]);
		printf("%d\t\t\t\t",tat[i]);
		printf("%d\t\t\t\t",ct[i]);
		printf("\n");
		twt+=wt[i];
		ttat+=tat[i];
	}
	awt=twt/n;
	atat=ttat/n;
	printf("Average Waiting Time: %f",awt);
	printf("\nAverage Turnaround Time: %f",atat);
	
	return 0;
}
