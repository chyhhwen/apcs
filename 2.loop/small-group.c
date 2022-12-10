#include<stdio.h>

int main(void)
{
	int number[50000];
	int visited[50000];
	int counter;
	int i,n;
	int success=0;
	int leader=0;
	
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&number[i]);
		visited[i]=0;
	}
	i=0;
	counter=0;
	while(success==0)
	{
		leader=i;
		while(number[i]!=leader && visited[i]==0)
		{
			visited[i]=1;
			i=number[i];
		}
		counter++;
		visited[i]=1;
		success=1;
		for(i=0;i<=n-1;i++)
		{
			if(visited[i] == 0)
			{
				success=0;
				break;
			}
		}
	}
	printf("%d",counter);
	return 0;
}
