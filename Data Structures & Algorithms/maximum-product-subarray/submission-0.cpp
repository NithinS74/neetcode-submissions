class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxout =nums[0];
        pair<int,int> out = maxp(nums,0,maxout);
        return maxout;           
    }

    pair<int,int> maxp(vector<int>&nums, int i,int &maxout){
        if(i>=nums.size()){
            return {1,1};
        }
        pair<int,int> tmp = maxp(nums,i+1,maxout);
        pair<int,int> out;
        if(nums[i]<0){
        out.first = max(tmp.second*nums[i],nums[i]);
        out.second = min(tmp.first*nums[i],nums[i]);
        maxout = max(out.first,maxout);
        return out;
        }
        out.first = max(tmp.first*nums[i],nums[i]);
        out.second = min(tmp.second*nums[i],nums[i]);
        maxout = max(out.first,maxout);
        return out;
    }
};
