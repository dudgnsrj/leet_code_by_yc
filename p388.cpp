class Solution {
public:
    bool fileExistance(string input){
        if (input.find('.') != std::string::npos)
            return true; // found
        else
            return false; // not found
    }
    
    int lengthLongestPath(string input) {
        int answer = 0;
        // cout << input << endl;
        
        if (fileExistance(input) == false){
            return 0;
        }
        
        vector<string> dir_level;
        dir_level.push_back("init");
        
        // cout << dir_level[0] << endl;
        string current_string;
        int it_count = 1;
        for (char s: input){
            // cout << s << endl;
            current_string.push_back(s);
            if (s == '\n' || it_count == input.size()){
                // cout << it_count << '/' << input.size() << endl;
                int num_tab = count(current_string.begin(), current_string.end(), '\t');
                
                if (dir_level.size() > num_tab){
                    dir_level[num_tab] = current_string;
                    // cout << dir_level[num_tab] << endl;
                }
                else{
                    dir_level.push_back(current_string);
                }
                
                // cout << current_string << ',' << num_tab << endl;
                
                if (fileExistance(current_string) == true){
                    string current_file = dir_level[0];
                    for (int i=1; i<=num_tab; i++){
                        current_file += '/';
                        current_file += dir_level[i];
                    }
                    current_file.erase(remove(current_file.begin(), current_file.end(), '\n'), current_file.end());
                    current_file.erase(remove(current_file.begin(), current_file.end(), '\t'), current_file.end());
                    
                    if (current_file.length() > answer){
                        answer = current_file.length();
                    }
                    // cout << current_file << endl;
                }
                
                current_string.clear();
            }
            it_count++;
        }
        
        return answer;
    }
};
