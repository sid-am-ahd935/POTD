// ***    1758. Minimum Changes To Make Alternating Binary String    *** //

class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0, ans2 = 0;
        int count = 0;


        // its either 010101..... or 101010.....
        // Regardless of size, check for both cases and return smallest

        int ideal1 = 0, ideal2 = 1;
        for(char c:s) {
            int actual = c - '0';
            ans1 += abs(ideal1-actual);
            ans2 += abs(ideal2-actual);

            ideal1 = abs(ideal1 - 1); // if ideal was 1 then now 0, vice versa
            ideal2 = abs(ideal2 - 1);
        }

        return min(ans1, ans2);
    }
};
