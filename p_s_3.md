
### Even and Odd
Given an array **arr[]** of size **N** containing equal number of odd and even numbers. Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.  
**Note:** There are multiple possible solutions, Print any one of them. Also, 0-based indexing is considered.

**Example 1:**

**Input:** N = 6
arr[] = {3, 6, 12, 1, 5, 8}
**Output:**
1
**Explanation:** 6 3 12 1 8 5 is a possible solution.
The output will always be 1 if your
rearrangement is correct.

**Example 2:**

**Input:** N = 4
arr[] = {1, 2, 3, 4}
**Output :**
1

  
**Your Task:**  
You don't need to read input or print anything. Your task is to complete the function **reArrange()** which takes an integer N and an array arr of size N as input and reArranges the array in Place without any extra space.

  
**Expected Time Complexity:** O(N)  
**Expected Auxiliary Space:** O(1)

  
**Constraints:**  
1 ≤ N ≤ 105  
1 ≤ arr[i] ≤ 105


```cpp
class Solution {
  public:
    void reArrange(int arr[], int N) {
        int o =0;
        int e =0;
        int ev[N/2]; //  initiating the even array
        int od[N/2]; // initiating the odd array
        
        
        for(int i=0; i<N; i++){
            if(arr[i]%2 == 0){
                ev[e++] = arr[i];
            }
            else{
                od[o++] = arr[i];
            }
        }
        
        
        //int out[N];
        int ee =0;
        int oo = 1;
        for(int j =0; j<e; j++){
               arr[ee] = ev[j];
               ee = ee+2;
           }
           
        for(int j =0; j<o; j++){
               arr[oo] = od[j];
               oo = oo+2;
           }
        
           
        
    }
};