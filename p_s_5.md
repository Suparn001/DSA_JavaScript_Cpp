
### Intersection of Two Arrays


Given two integer arrays `nums1` and `nums2`, return _an array of their_

intersection

. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**

**Input:** nums1 = [1,2,2,1], nums2 = [2,2]
**Output:** [2]

**Example 2:**

**Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
**Output:** [9,4]
**Explanation:** [4,9] is also accepted.

**Constraints:**

-   `1 <= nums1.length, nums2.length <= 1000`
-   `0 <= nums1[i], nums2[i] <= 1000`

```cpp
class  Solution {
public:
vector<int> intersection(vector<int>&  nums1, vector<int>&  nums2) {
unordered_set<int> u;
unordered_set<int> result;
int x = nums1.size();
for(int i=0; i<x;i++){
u.insert(nums1[i]);
}
// checking elements
for(auto ele:nums2){
if(u.find(ele) != u.end()){
result.insert(ele);
}
}
vector<int>d(result.begin(), result.end());
return d;
}
};
