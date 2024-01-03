// ***    2125. Number of Laser Beams in a Bank    *** //

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0, laser;

        for(string &b: bank){
            laser = count(b.begin(), b.end(), '1');
            if(!laser) continue;
            ans += laser * prev;
            prev = laser;    
        }
        return ans; 
    }
};
