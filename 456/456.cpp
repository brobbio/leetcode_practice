    bool find132pattern(vector<int>& nums) {
        vector<int> premin;
        stack<int> s;
        premin.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            premin.push_back(min(premin[i-1], nums[i]));
        }
        stack<int> right;
        for(int j=nums.size()-1;j>=1;j--){
            while(right.size()>0 && right.top()<=premin[j-1]){
                right.pop();
            }
            if(premin[j-1]<nums[j] && right.size()>0 && right.top()<nums[j]){
                return true;
            }
            right.push(nums[j]);
        }
        return false;
    }
