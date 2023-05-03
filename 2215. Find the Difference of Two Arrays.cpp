class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& num1, vector<int>& num2) {

        unordered_set<int> set1;  //store the element of nums1
        
        vector<vector<int>> ans;  //store the answer
        
        unordered_set<int> set2;   //store the element of nums2
        
        //insert the element in set1
        for(int i=0;i<num1.size();i++){
            set1.insert(num1[i]);
        }
        
        for(int i=0;i<num2.size();i++){
            set1.erase(num2[i]);     //delete the element from set1 which is in list of nums2
            set2.insert(num2[i]);
        }
        
        vector<int> ans1;  //dummy vector
        
        for(auto it:set1){
            ans1.push_back(it);
        }
        
        ans.push_back(ans1);  //store in ans vector
        
        ans1.clear();  //delete the element of ans1 vector
        
        for(int i=0;i<num1.size();i++){
            set2.erase(num1[i]);
        }
        
        for(auto it:set2){
            ans1.push_back(it);
        }
        
        ans.push_back(ans1);
        return ans;
    }
};
