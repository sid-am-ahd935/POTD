// ***    2870. Minimum Number of Operations to Make Array Empty    *** //

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans = 0;

        for(int &n:nums) {
            count[n]++;
        }

        for(auto &c:count) {
            if(c.second == 1) return -1;

            // --------- Intuitive --------- //
            // // To represent n as 3x + 2y, i.e., 3x + 2y = n
            // // And minimum operations are possible only when x is more 
            // // So running a small for-loop from n/3 to 0 for x to find out y
            // for(double x=n/3; x>=0; x--) {
            //     double y = (n-3*x)/2;
            //     if(y == floor(y)) {
            //         // y is a whole number
            //         ans += x + y;
            //         break;
            //     }
            // }

            // --------- Optimal --------- //
            // x = n/3; and y = n%3;
            // if y is 0;
            // - operations = n/3
            // if y is 1:
            // - there will be one 3 less with the addition of two 2
            // - hence operations = n/3 - 1 + 2
            // if y is 2:
            // - there will be addition of one 2
            // - hence operations = n/3 + 1
            // in cases where there is a remainder, thre is just an addition of one operation
            // else in cases where n is perfectly divisible by 3, there are no additioinal operations

            ans += ((c.second/3) + (c.second%3 > 0));
        }

        return ans;
    }
};
