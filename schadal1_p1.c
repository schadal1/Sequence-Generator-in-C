#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int g_arr[20],count1=0;
static int count2=0;

void recursive(int input,int start)
{	
	int j,i;
	int nextline = input * input,flag=input*input*input;
	
	if(start<input)
	{
		for(j=1;j<=input;j++)
		{
			g_arr[start] = j;
			recursive(input,start+1);
		}
	}
	else
	{
		count1++;
		count2++;
		for(i=0;i<input;i++)
		{
			printf("%d",g_arr[i]);
		}
		if(count2==flag)
		{
			printf(" ``\n");

		}
		else
		{
			printf(", ");
			if(count1==nextline)
			{
				printf("\n");
				count1 = 0;
			}
		}
	}
}
int main(int argc,char *argv[])
{
	int input,i;
	clock_t start,end;
	input = atoi(argv[1]);
	float micro;
	time(&start);
	for(i=0;i<input;i++)
	{
		g_arr[i]=i;
	}
	recursive(input,0);
	time(&end);
	micro = end  - start;
	printf("\nThe time elapsed to execute sequence the code is %f seconds\n",difftime(end,start));
	return 0;
}
