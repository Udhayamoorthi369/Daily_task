/**

*sort the array in ascending order first half and sort the median 

*sort the array in decending order

**/
					
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num,i,j,temp;
/* type the size you want */
	printf("Enter size :");
	scanf("%d",&num);

	int *a=malloc(sizeof(int)*num);
/* enter the elemens */
	printf("Enter the Elements:",n);
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
/* sorting first half in ascending order */
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num/2;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
/* sorting second half in decending order */
		for(j=num/2;j<num-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
/* print the value */
	for(i=0;i<num;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
				
}
	
