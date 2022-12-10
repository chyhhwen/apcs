#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define false 0
#define true 1

typedef unsigned int bool;
int max(int,int);

int main(void)
{
	int k;
	int i;
	char str[100000];
	bool capital;
	int big=0;
	int small=0;
	int length=0;
	int answer=0;
	
	scanf("%d",&k);
	scanf("%s",str);
	
	if(islower(str[0]))
	{
		capital=false;
		small=1;
		if(k==1)
		{
			length=1;
			answer=1;
		}
		else
		{
			capital=true;
			big=1;
			if(k==1)
			{
				length=1;
				answer=1;
			}
		}
	}
	for(i=1;i<strlen(str);i++)
	{
		if(islower(str[i])&&capital==false)
		{
			small+=1;
			big=0;
			if(small==k)
			{
				length+=k;
				answer=max(length,answer);
			}
			if(small>k){length=k;}
		}
		else if(islower(str[i])&&capital==true)
		{
			if(big<k){length=0;}
			small=1;
			big=0;
			if(k==1)
			{
				length+=k;
				answer=max(length,answer);
			}
			capital=false;
		}
		else if(isupper(str[i])&&capital==true)
		{
			big+=1;
			small=0;
			if(big==k)
			{
				length+=k;
				answer=max(length,answer);
			}
			if(big>k){length=k;}
		}
		else if(isupper(str[i])&&capital==false)
		{
			if(small<k){length=0;}
			big=1;
			small=0;
			if(big==k)
			{
				length+=k;
				answer=max(length,answer);
			}
			capital=true;
		}
	}
	printf("%d\n",answer);
	return 0;
}

int max(int x,int y)
{
	if(x>=y){return x;}
	else{return y;}
}
