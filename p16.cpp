class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::vector<int>::iterator result = std::min_element(nums.begin(), nums.end());
        int min_num = nums[std::distance(nums.begin(), result)];
        
        std::vector<int> new_nums;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - min_num <= target - 3*min_num)
                new_nums.push_back(nums[i] - min_num);
        }
        
        if(new_nums.size() <= 3){
            sort(nums.begin(), nums.end());
            return nums[0]+nums[1]+nums[2];
        }
            
        std::vector<int> diffs;
        std::vector<int> sums;
        for(int i=0;i<new_nums.size();i++){
            for(int j=i+1;j<new_nums.size();j++){
                for(int k=j+1;k<new_nums.size();k++){
                    diffs.push_back(abs(new_nums[i]+new_nums[j]+new_nums[k]-target+3*min_num));
                    sums.push_back(new_nums[i]+new_nums[j]+new_nums[k]-target+3*min_num);
                }
            }
        }
        
        std::vector<int>::iterator result1 = std::min_element(diffs.begin(), diffs.end());
        int answer = sums[std::distance(diffs.begin(), result1)];
        
        return answer + target;
    }
};