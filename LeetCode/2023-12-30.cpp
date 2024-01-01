class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // unordered_map<char, int> chars;
        int chars[26], n = words.size();

        for(int i=0; i<26; i++) {
            chars[i] = 0;
        }

        // Removing '&' from here (&w) makes copies of each item in words, hence increase in space
        for(string &w:words) {
            // Removing '&' from here (&c) makes adds an additional step to the process, i.e., to get value of c
            // By keeping '&' it keeps the value at the same memory, and references this c to that memory, hnce here saving more time than memory
            for(char &c:w) {
                chars[c-'a']++;
            }
        }

        for(int i=0; i<26; i++) {
            if(chars[i] % n) {
                return false;
            }
        }
        return true;
    }
};
