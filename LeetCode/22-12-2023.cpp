// ***    1422. Maximum Score After Splitting a String    *** //

class Solution {
public:
    int maxScore(string &s) {
        // We cannot count the leftmost one to point nor the rightmost zero to the point as both side of strings has to be at least size of one
        // i will contain the left part, outside i is right part

        short ones = 0, zero = 0, ans = 0;
        for(char c:s) {
            if(c == '1') ones++;
            // including the leftmost one to point as next for loop will immediately decrease point for one at i
        }

        for(short i=0; i<s.size()-1; i++) {
            if(s[i] == '0') zero++;
            else ones--;

            if(zero+ones > ans) ans = zero+ones;
        }

        return ans;
    }
};
