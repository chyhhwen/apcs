#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,t;
	float ab,cc;
	
	printf("輸入三邊長: 例如:3 4 5\n");
	scanf(" %d %d %d",&a,&b,&c);
	
	if(a>b){t=a; a=b; b=t;}
	if(b>c){t=b; b=c; c=t;}
	if(a>b){t=a; a=b; b=t;}
	
	if(a+b<=c)
	{
		printf("No");
		return 0;
	}
	
	ab=pow(a,2)+pow(b,2);
	cc=pow(c,2);
	
	if(ab<cc){printf("Obtuse");}
	else
	{
		if(ab!=cc)
		{
			printf("Acute");
		}
		else
		{
			printf("Right");
		}
	}
	return 0;
 } 
