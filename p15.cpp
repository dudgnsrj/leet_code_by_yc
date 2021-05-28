class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int diff = INT_MAX;
        vector<vector<int>> answers;
        vector<int> answer;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int lower = i+1;
            int higher = nums.size()-1;
            while(lower < higher){
                int sum = nums[i] + nums[lower] + nums[higher];

                if(sum == 0){
                    answer.push_back(nums[i]);
                    answer.push_back(nums[lower]);
                    answer.push_back(nums[higher]);
                    answers.push_back(answer);
                    ++lower;
                    answer.clear();
                }
                else if(sum < 0)
                    ++lower;
                else
                    --higher;
            }
                
        }
        std::sort(answers.begin(), answers.end());
        answers.erase(std::unique(answers.begin(), answers.end()), answers.end());

        return answers;
    }
};