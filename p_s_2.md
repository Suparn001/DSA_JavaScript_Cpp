
### Array Duplicates
Given an array **arr** of size **n** which contains elements in range from **0** to **n-1**, you need to find all the elements occurring more than once in the given array. Return the answer in ascending order. If no such element is found, return list containing **[-1]**.

**Note:** Try and perform all operations within the provided array. The extra (non-constant) space needs to be used only for the array to be returned.

**Examples:**

**Input:** arr[] = {0,3,1,2}, n = 4
**Output:** -1 **Explanation:** There is no repeating element in the array. Therefore output is -1.

**Input:** arr[] = {2,3,1,2,3}, n = 5
**Output:** 2 3 **Explanation:** 2 and 3 occur more than once in the given array.

**Expected Time Complexity:** O(n).  
**Expected Auxiliary Space:** O(n).

**Constraints:  
**0 <= arr[i] <= n-1, for each valid i  
1 <= n <= 105

**Solution** is: 


```cpp
class Solution {
  public:
    vector<int> duplicates(vector<long long> arr) {
        
        long long s = arr.size();
        
         vector<int> ans; //  this is just to store the answers.
        vector<int> freq(s,0);
         for(int i =0; i<s;i++){
              int y = arr[i];
              
              freq[y]++;
         }
         
         for(int i =0; i<s;i++){
             if(freq[i]>1){
                 ans.push_back(i);
             }
         }
         
        if(ans.empty()) {
             ans.push_back(-1);
         }
      
      
      
      return ans;
    }
};
