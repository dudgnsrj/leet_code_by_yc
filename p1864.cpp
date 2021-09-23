class Solution {
public:
    int minSwaps(string s) {
        int zero_count = 0;
        int one_count = 0;
        for (char num: s){
            // cout << num << endl;
            if (num=='0'){
                zero_count++;
            }
            else {
                one_count++;
            }
        }
        
        if (abs(zero_count-one_count) > 1){
            return -1;
        }
        
        if (s.length() % 2 == 0){
            string alter_0;
            string alter_1;
            int answer_0 = 0;
            int answer_1 = 0;
            for (int i=0; i<s.length(); i++){
                alter_0 += to_string(i%2);
                alter_1 += to_string((i+1)%2);
            }
            for (int i=0;  i<s.length(); i++){
                if (s[i]!=alter_0[i]){
                    answer_0++;
                }
            }
            for (int i=0;  i<s.length(); i++){
                if (s[i]!=alter_1[i]){
                    answer_1++;
                }
            }
            // cout << alter_0 << ',' << alter_1 << endl;
            // cout << answer_0 << ',' << answer_1 << endl;
            int answer = min(answer_0, answer_1);
            return answer/2;
        }
        else{
            string alter;
            int answer = 0;
            if (zero_count > one_count){
                for (int i=0; i<s.length(); i++){
                    alter += to_string(i%2);
                }
            }
            else{
                for (int i=0; i<s.length(); i++){
                    alter += to_string((i+1)%2);
                }
            }
            for (int i=0;  i<s.length(); i++){
                if (s[i]!=alter[i]){
                    answer++;
                }
            }
            return answer/2;
        }
        return 0;
    }
};
