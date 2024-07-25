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
