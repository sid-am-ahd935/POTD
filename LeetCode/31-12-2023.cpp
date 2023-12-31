class Solution {
public:
    // Brute Force Approach
    /*
    int maxLengthBetweenEqualCharacters(string s) {
        // Brute force approach
        // Remember to use (int) before comparing ans with temp.size()... brings out all sorts of errors
        // Even if not error, it gives -1 > any value inside temp.size()...
        int ans = -1;
        for(int i=0; i<s.size()-1; i++) {
            for(int j=2; j<=s.size()-i; j++) {
                string temp = s.substr(i, j);
                // cout << temp << "(" << temp.size() << "):";
                if(temp[0] == temp[temp.size()-1]) {
                    // cout << "True >> Ans= " << ans;
                    ans = max((int) temp.size()-2, ans);
                    // cout << "[" << temp.size()-2 << "]" << ans;
                } else {
                    // cout << "False";
                }
                // cout << endl;
            }
        }

        // return ans > 0 ? ans : -1;
        return ans;
    }
    */

    // Better Approach
    /*
    int maxLengthBetweenEqualCharacters(string s) {
        // Optimal approach
        int ans = -1;
        unordered_map<char, int> index;

        for(int i=0; i<s.size(); i++) {
            if(index.find(s[i]) != index.end()) {
                // Already been through this character once
                // Find characters between the first appearance of this character and this index
                ans = max(ans, abs(i - index[s[i]]) - 1);
            } else {
                index[s[i]] = i;
            }
        }
        return ans;
    }
    */
    // THe above approach can be tweaked for getting more optimised in space, like for example adding vector reduces space by a little...
    // Adding short instead of int... etc

    int maxLengthBetweenEqualCharacters(string &s) {
        // Optimal approach
        short ans = -1;
        vector<short> index(26, -1);

        for(short i=0; i<s.size(); i++) {
            short key = s[i] - 'a';
            if(index[key] != -1) {
                // Adding ans - 0 causes explicit type casting hence max() works
                short res = i - index[key] - 1;
                if(ans < res) ans = res;
            } else {
                index[key] = i;
            }
        }
        return ans;
    }
};
