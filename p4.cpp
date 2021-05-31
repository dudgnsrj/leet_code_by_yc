class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());
        
        if(nums.size() % 2 == 0){
            double ans = (nums[nums.size()/2 - 1] + nums[nums.size()/2]) / 2.0;
            return ans;
        }
        else
            return nums[nums.size()/2];
    }
};