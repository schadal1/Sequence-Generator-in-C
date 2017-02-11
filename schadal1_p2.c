#include <stdio.h>
#include <stdlib.h>
static int g_arr[20];
void permute(int v_arr[],int input,int start)
{
        int j,temp;
        if(start==input)
        {
                j=0;
		while(j<input)
                {
                        printf("%d ",v_arr[j]);
			j++;
                }
                printf("\n");
        }
        else
        {
		j=start;
		while(j<input)
                {
                        temp = v_arr[start];
                        v_arr[start] = v_arr[j];
                        v_arr[j] = temp;

                        permute(v_arr,input,start+1);
                        temp = v_arr[start];
                        v_arr[start] = v_arr[j];
                        v_arr[j] = temp;
			j++;
                }
        }

}
int main (int argc, char *argv[]) 
{
	int input,i;
	input = atoi(argv[1]);
	for (i=0; i<input; i++)
	{
	 	g_arr[i] = i+1;
	}
	permute(g_arr,input, 0);
	return 0;
}
