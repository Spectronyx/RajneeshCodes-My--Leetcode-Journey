class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones_indices;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '1'){
                ones_indices.push_back(i);
            }
        }

        if(ones_indices.size() < k) return "";

        int min_length = s.size()+1;
        string best_substring = "";

        for(int i = 0;i <= (int)ones_indices.size()-k;i++){
            int start_index = ones_indices[i];
            int end_index = ones_indices[i+k-1];
            int current_size = end_index-start_index+1;

            string current_sub = s.substr(start_index,current_size);

            // using lexicographically sorting
            if(current_size< min_length){
                min_length = current_size;
                best_substring = current_sub;
            }else if(current_size == min_length){
                if(current_sub < best_substring){
                    best_substring = current_sub;
                }
            }
        }
        return best_substring;
    }
};