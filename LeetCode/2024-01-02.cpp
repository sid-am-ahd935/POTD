// ***    2610. Convert an Array Into a 2D Array With Conditions    *** //

/*
---- Easy to understand ----
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        int max_m;

        // In the constraints, the numbers are limited to nums[i] <= n;
        // Which means even if all the numbers are distinct, it won't be exceeding N, the size of nums..

        vector<int> count(n+1, 0);

        for(int a:nums) {
            count[a]++;
        }
        max_m = *max_element(count.begin(), count.end());

        vector<vector<int>> ans(max_m);

        for(int i=1; i<count.size(); i++) {
            for(int j=0; j<count[i]; j++) {
                ans[j].push_back(i);
            }
        }


        return ans;
    }
};
*/

/*
--- Most Optimal ---
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int max_c = INT_MIN;

        // In the constraints, the numbers are limited to nums[i] <= n;
        // Which means even if all the numbers are distinct, it won't be exceeding N, the size of nums..

        vector<int> count(nums.size()+1, 0);

        for(int &a:nums) {
            count[a]++;
            if(count[a] > max_c) {
                ans.push_back({});
                max_c = count[a];
            }
            ans[count[a]-1].push_back(a);
        }
        return ans;
    }
};
*/
