class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowel_list;
        vector<int> vowel_idx;
        
        int idx = 0;
        for (char c: s){
            // cout << c << endl;
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                vowel_list.push_back(c);
                vowel_idx.push_back(idx);
                // cout << c << ',' << idx << endl;
            }
            idx++;
        }
        for (int i=0; i<vowel_list.size(); i++){
            // cout << vowel_list[i] << ',' << vowel_idx[i] << ',' << vowel_idx[vowel_idx.size()-i-1] << endl;
            s[vowel_idx[vowel_idx.size()-i-1]] = vowel_list[i];
        }
        return s;
    }
};
