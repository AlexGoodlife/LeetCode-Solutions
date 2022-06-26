/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. 
The richest customer is the customer that has the maximum wealth.

Runtime: 3 ms | beats 98.2% of other submissions
Memory Usage: 6.3 | beats 36.3 % of other submissions

*/


#include <stdio.h>
#include <stdlib.h>

int max(int *a, int n)
{
  int result = a[0];
  for (int i = 1; i < n; i++)  // i = 1
    if (result < a[i])
      result = a[i];
  return result;
} 

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int wealth[accountsSize];
    int sum = 0;
    for(int i = 0; i < accountsSize;i++){
        sum = 0;
        for(int j = 0; j < *accountsColSize;j++){
            sum += accounts[i][j];
        }
        wealth[i] = sum;
    }
    
    return max(wealth, accountsSize);
}


int main(void){
    return 0;
}