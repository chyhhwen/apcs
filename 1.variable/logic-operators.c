#include<stdio.h>
int main()
{
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	char result[3];
	
	if(a>0){a=1;}
	if(b>0){b=1;}
	
	if((a&b)==c){result[0]='Y';}
	else{result[0]='N';}
	if((a|b)==c){result[1]='Y';}
	else{result[1]='N';}
	if((a^b)==c){result[2]='Y';}
	else{result[2]='N';}
	
	if(result[0]=='Y'){printf("AND\n");}
	if(result[1]=='Y'){printf("OR\n");}
	if(result[2]=='Y'){printf("XOR\n");}
	
	if(result[0]=='N' && result[1]=='N' && result[2]=='N')
	{
		printf("IMPOSSIBLE\n");
	}
	
	return 0;
}
