// ***    2225. Find Players With Zero or One Losses    *** //

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // vector increases time and memory consumption
        // 100001 was the constraint given to the problem
        int scores[100001+1] = {0}, won[100001+1] = {0};
        // if you want to use only one array, then use memset to set scores to default -1, win changes it to 0, lose changes it to 1 or increases
        vector<vector<int>> res(2);

        for(auto &m:matches) {
            ++won[m[0]];
            ++scores[m[1]];
        }

        for(int i=0; i<=100001; i++) {
            if(won[i] && !scores[i]) {
                res[0].push_back(i);
            } else if(scores[i] == 1) {
                res[1].push_back(i);
            } 
        }

        return res;
    }
};
