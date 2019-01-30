#include<stdio.h>
#include<stdlib.h>


int max,min;
int a[100];

void minmax(int i, int j)
{
		int max1,min1,mid;
		if(i==j)
			max=min=a[i];
			else
			{
				if(i==j-1)
					{
						if(a[i]<a[j])
							{
								max=a[j];
								min=a[i];
							}
						else 
							{
								max=a[i];
								min=a[j];
							}
					}
					else
						{
							mid = (i+j)/2;
							minmax(i,mid);
							max1=max;
							min1=min;
							minmax(mid+1,j);
							if(max<max1)
							max=max1;
							if(min>min1)
							min=min1;
						}
					}
	}
	
int main()
  {
  		int k,num;
  		printf("\nEnter the length of the array\n");
  		scanf("%d",&num);
  		printf("\nEnter the numbers");
  		for(k=0;k<num;k++)
  		scanf("%d",&a[k]);
  		max=a[0];
  		min=a[0];
  		minmax(1,num);
  		printf("\nMinimum element in the array is %d",min);
  		printf("\nMaximum element in the array is %d\n",max);
  		return 0;
  	}

							
				
