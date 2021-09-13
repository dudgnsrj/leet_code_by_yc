class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0;
        int sum = 0;
        cout << nums.size() << endl;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                sum = 0;
            }
            else{
                sum += 1;
            }
            if (sum > answer){
                answer = sum;
            }
        }
        return answer;
    }
};
