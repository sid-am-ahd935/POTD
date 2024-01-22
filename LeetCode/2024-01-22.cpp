// ***    645. Set Mismatch    *** //

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // I remember this question... as the integers are just indexes incremented, use them to mark the array itself as visited;
        int a, b;
        for(int n:nums) {
            if(nums[abs(n)-1]<0) {
                // already marked
                a = abs(n);
                continue;
            }
            nums[abs(n)-1] = -nums[abs(n)-1];
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) {
                // still not marked, hence missing
                b = i+1;    // as index is decremented indexes
            }
        }
        return {a, b};
    }
};
