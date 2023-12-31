class Solution {
public:
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
};
