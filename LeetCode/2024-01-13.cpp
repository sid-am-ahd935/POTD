// ***    1347. Minimum Number of Steps to Make Two Strings Anagram    *** //

class Solution {
public:
    int minSteps(string &s, string &t) {
        int ans = 0;
        vector<int> diff(26, 0);

        for(int i=0; i<s.size(); i++) {
            ++diff[s[i]-'a'];
            --diff[t[i]-'a'];
        }

        for(int &d:diff) ans += abs(d);

        return ans/2;
    }
};
