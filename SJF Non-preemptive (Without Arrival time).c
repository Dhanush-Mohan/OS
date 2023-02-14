#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int pid[n],bt[n],wt[n],tat[n];
	int i,j,temp;
	float twt,ttat,awt,atat;
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
	//Sorting the pid and bt using bubble sort....
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(bt[j]>bt[i])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=pid[i];
				pid[i]=pid[j];
				pid[j]=temp;
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
		twt+=wt[i];
		
	}
	printf("\nProcess ID\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		tat[i]=(wt[i]+bt[i]);
		ttat+=tat[i];
		printf("%d\t\t\t",pid[i]);
		printf("%d\t\t\t",bt[i]);
		printf("%d\t\t\t\t",wt[i]);
		printf("%d",tat[i]);
		printf("\n");
	}
	awt=twt/n;
	atat=ttat/n;
	printf("Average Waiting Time: %f",awt);
	printf("\nAverage Turnaround Time: %f",atat);
	return 0;
	
}
