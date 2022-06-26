/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n))

Pretty sure this isnt O(log(m+n)) and you are supposed to use merge sort but this is how I did it

Runtime: 16 ms | beats 82 % of other submissions
Memory usage: 7.1 MB
*/


#include <stdio.h>
#include <stdlib.h>

void ints_copy(const int *a, int n, int *b)
{
  if (n < 0)
    n = 0;
  memmove(b, a, n * sizeof(int));
}


int *merge_arrays(int *a, int n, int *b, int m){
    int *c = (int*)malloc(sizeof(int)*(n+m));
    int result = 0;
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            c[result++] = a[i++];
        }
        else
            c[result++] = b[j++];
    }
    ints_copy(a+i,n-i,c+result);
    ints_copy(b+j,m-j,c+result);
    return c;
}

int cmp(const void *x, const void *y){
    return ( *(int*)x - *(int*)y );
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result = 0;
    qsort(nums1, (size_t)nums1Size, sizeof(int),cmp);
    qsort(nums2, (size_t)nums2Size, sizeof(int),cmp);
    int *merged = merge_arrays(nums1, nums1Size, nums2, nums2Size);
    int m = (nums1Size + nums2Size);
    int middle = m /2;
    if(m % 2 == 0)
        result = m == 0 ? merged[middle] : (double)((merged[middle-1] + merged[middle])) / 2;
    else
        result = merged[middle];
    return result;
}



int main(void){
    return 0;
}