/*
1551. Minimum Operations to Make Array Equal
You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n).

In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. It is guaranteed that all the elements of the array can be made equal using some operations.

Given an integer n, the length of the array, return the minimum number of operations needed to make all the elements of arr equal.

 

Example 1:

Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
Example 2:

Input: n = 6
Output: 9

most importain link is https://leetcode.ca/2020-02-28-1551-Minimum-Operations-to-Make-Array-Equal/#:~:text=Minimum%20Operations%20to%20Make%20Array%20Equal%20(Medium),%5By%5D%20%2B%3D%201%20).

https://leetcode.ca/2020-02-28-1551-Minimum-Operations-to-Make-Array-Equal/#:~:text=Minimum%20Operations%20to%20Make%20Array%20Equal%20(Medium),%5By%5D%20%2B%3D%201%20).
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n >> 1; ++i) {
            ans += n - (i << 1 | 1);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int minOperations(int n) {
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=((2*i)+1);
        }
        // each element should be to make all element equal totalSum/n;
        int element = totalSum/n;
        
        int min_op = 0;
        for(int i=n-1;i>=n/2;i--){
            if((2*i)+1>element){
               min_op += ((2*i)+1)-element;
            }else{
                break;
            }
        }
        return min_op;
    }
};

/*
class Solution {
public:
    int minOperations(int n) {
       int ans=0;
       for(int i=0;i<n/2;i++)
       {
           ans+=n-((2*i) + 1);
       }
       return ans;
    }
};

class Solution {
public:
    int minOperations(int n) {
        return ( n/2 ) * ( n - (n/2));
    }
}; 

class Solution {
public:
    int minOperations(int n) {
   
     
      // just write the series fro n=1 to n==6;
      //notice the mid elemnt is equal to n for every series
      // try to make every element equal to the mid element (which will be n)
      //and  that diffeerence will be a series of odd numbers
      //and calculate the sum of this series 
       // and sum of m odd numbers is m*m 
       
                 // if n is even then      //if n is odd
      
      return (n%2==0) ? (n/2)*(1ll)*(n/2) :  ((n/2)+1)*(1ll)*(n/2);


    }
};
*/