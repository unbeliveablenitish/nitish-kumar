#include<stdio.h>
int main()
{
	int process,resource,i,j,temp1=0,k=0,temp2=0,n;
	printf("Enter number of process::");
	scanf("%d",&process);
	printf("Enter number of resources::");
	scanf("%d",&resource);
	int max[process][resource],allocation[process][resource],available[resource],need[process][resource],instance,finish[process],request[process][resource];
	for(i=0;i<process;i++)
	{
		finish[i]=0;
	}
	printf("Enter Max matrix::\n");
	for(i=0;i<process;i++)
	{
		printf("P[%d]\t",i);
		for(j=0;j<resource;j++)
		{
			scanf("\n%d",&instance);
			max[i][j]=instance;
		}
	}
	
	printf("Enter allocation matrix::\n");
	for(i=0;i<process;i++)
	{
		printf("P[%d]\t",i);
		for(j=0;j<resource;j++)
		{
			scanf("\n%d",&instance);
			allocation[i][j]=instance;
		}
	}
	printf("Enter available matrix::\n");
	for(j=0;j<resource;j++)
	 {
			scanf("\n%d",&instance);
			available[j]=instance;
	 } 
	for(i=0;i<process;i++)
	{
		
		for(j=0;j<resource;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	printf("The need matrix is::");
	for(i=0;i<process;i++)
	{
		printf("\nP[%d]\t",i);
		for(j=0;j<resource;j++)
		{
			printf("%d\t",need[i][j]);
		
		}
	}
	printf("\n\n");
	printf("Enter 1 to check a normal safe sequence\n");
	printf("Enter 2 to check the sequence when additional resources are requested by P[0]\n");
	printf("Enter 3 to check the sequence when additional resources are requested by P[1]\n");
	scanf("\n%d",&n);
	
	switch(n)
	{
	case 1:
		
		
	printf("\n\n");
	printf("The safe sequence for the above given processes if additional instances are not requested ::\n");
	printf("\n");
	while(temp1!=process)
	{
		for(i=0;i<process;i++)
		{
			for(j=0;j<resource;j++)
		   {
		   	 if(need[i][j]<=available[j])
		   	 {
		   	 
		   	 	k++;
		   	
		   	 }
	       }
	       if(k==resource && finish[i]==0)
	       {
	       	printf("P[%d]\t",i);
	       	finish[i]=1;
	       	for(j=0;j<resource;j++)
	       	{
	       		available[j]=available[j]+allocation[i][j];
	       	}
	       	temp1++;
	       }
	        k=0;
	    }
		  	
		
	}
	break;
    //For P[0] requesting additional resources:
	case 2:
		
		
	printf("Enter additional request by P0 processs\n");
	printf("request[0]::\t");
	for(j=0;j<resource;j++)
	{
		
		scanf("%d",&instance);
		request[0][j]=instance;
	}
	for(j=0;j<resource;j++)
	{
		if(request[0][j]<=need[0][j])
		{
			if(request[0][j]<=available[j])
			{
				available[j]=available[j]-request[0][j];
				allocation[0][j]=allocation[0][j]+request[0][j];
				need[0][j]=need[0][j]-request[0][j];
			}
			else
			{
				printf("P[0] must wait because resources are not available\n");
			}
		}
		else
		{
			printf("The process has exceeded the maximum claim\n");
		}
	}
	printf("The sequence after additional request by P[0] is::::<<");
	while(temp1!=process)
	{
		temp2=temp1;
		for(i=0;i<process;i++)
		{
			for(j=0;j<resource;j++)
			{
				if(need[i][j]<=available[j])
				{
					k++;
				}
			}
			if(k==resource && finish[i]==0)
			{
				printf("P[%d]",i);
				finish[i]=1;
				for(j=0;j<resource;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
				temp1++;
			}
			k=0;
		}
		if(temp1==temp2)
		{
			printf("\tStop after this system is unsafe...there is a deadlock>>\n\n");
			printf("So Reenas operating system is unsafe if there is a additional request by P[0]\n");
			break;
		}
	}
	break;
	
	//For P[1] requesting additional resources
	case 3:
		printf("Enter additional request by P[1] processs\n");
		printf("request[0]::\t");
	for(j=0;j<resource;j++)
	{
		scanf("%d",&instance);
		request[0][j]=instance;
	}
	for(j=0;j<resource;j++)
	{
		if(request[0][j]<=need[1][j])
		{
			if(request[0][j]<=available[j])
			{
				available[j]=available[j]-request[0][j];
				allocation[1][j]=allocation[1][j]+request[0][j];
				need[1][j]=need[1][j]-request[0][j];
			}
			else
			{
				printf("P[0] must wait because resources are not available\n");
			}
		}
		else
		{
			printf("The process has exceeded the maximum claim\n");
		}
	}
	printf("The sequence after additional request by P[1] is::::");
	while(temp1!=process)
	{
		temp2=temp1;
		for(i=0;i<process;i++)
		{
			for(j=0;j<resource;j++)
			{
				if(need[i][j]<=available[j])
				{
					k++;
				}
			}
			if(k==resource && finish[i]==0)
			{
				printf("P[%d]\t",i);
				finish[i]=1;
				for(j=0;j<resource;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
				temp1++;
			}
			k=0;
		}
	
		if(temp1==temp2)
		{
			printf("\tStop after this system is unsafe...there is a deadlock>>\n\n");
			printf("So Reenas operating system is unsafe if there is a additional request by P[0]\n");
			break;
		}
		
	}
	break;		 
}
	
	return 0;
}

