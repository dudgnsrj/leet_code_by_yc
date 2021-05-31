class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int ans = 0;
        string substring;
        for(int i=0;i<s.length();i++){
            // cout<<"==========="<<endl;
            // cout<<i<<endl;
            if(substring.find(s[i]) == std::string::npos){
                count++;
                substring += s[i];
                // cout<<count<<endl;
                if(count > ans)
                    ans = count;
            }
            else{
                int idx = distance(substring.begin(),std::find(substring.begin(), substring.end(), s[i]));
                substring = substring.substr(idx+1,substring.size()-idx-1);
                substring += s[i];
                count = substring.length();
                // cout<<"reset, "<<count<<endl;
            }
            // cout<<substring<<endl;
        }
        return ans;
    }
};