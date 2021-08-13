#include<stdio.h>

int  merge(int a[], int left, int mid, int right)
 {
    
 int count =0;  
    if(right <= left)
	return 0 ;
 int i = left;
 int j = mid+1;
 int k = left;
 int b[right+2];
    while(i <= mid && j <= right)
    {
     if(a[i] <= a[j])
        {
         b[k] = a[i];
         ++i;
                 
        }
     else
        {

         b[k] = a[j];
         ++j;
	count += mid - i + 1; 
        }

        ++k;
    }

    while(i <= mid)
    {
        b[k] = a[i];
        ++i;
        ++k;
             
    }
    while(j <= right)
    {
        b[k] = a[j];
        ++j;
        ++k;
    }
    for( i = left ; i <= right ; ++i)
        a[i] = b[i];

    return count;
    } int mergeSort( int a[], int left, int right)
{
    
    if(right <= left)
       return 0;
 int m =(left + right)/2;
 int count = 0;
    count += mergeSort(a,left , m);
    count += mergeSort(a, m+1 , right);
    count += merge(a, left , m, right);
    return count; 
    
}

    
 

int main()
{  int  n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
	    scanf("%d", &a[i]);
	    
    }
 printf("%d\n", mergeSort(a, 0, n-1) );
}