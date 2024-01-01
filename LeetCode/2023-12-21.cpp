// ***    1637. Widest Vertical Area Between Two Points Containing No Points    *** //

class Solution {
// private:
//     bool search(int key, vector<int> &nums) {
//         int s = 0, e = nums.size()-1;

//         while(s <= e) {
//             int mid = s + (e-s)/2;

//             if(key == nums[mid]) {
//                 return true;
//             } else if(key < nums[mid]) {
//                 e = mid - 1;
//             } else {
//                 s = mid + 1;
//             }
//         }
//         return false;
//     }
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // vector<int> x_axis;

        // // Brute Force Logic
        // // Make an array with only x_axis points
        // // Sort the array
        // // Check i and i+1 elements, the distance between them
        // // Max distance between i and i+1 is the answer

        // // Optimised Logic
        // // While inserting elements in the x_axis array
        // // use insertion sort logic to insert the elements
        // // Don't insert any duplicate elements
        // // Checking case same

        // for(auto p:points) {
        //     // using insertion sort logic for inserting elements
        //     int key = p[0];
        //     if(search(key, x_axis)) {
        //         // cout << "key found: " << key << endl;
        //         continue;
        //     }
        //     x_axis.push_back(key);

        //     int key_i = x_axis.size()-1;
        //     int i = key_i - 1;
        //     // i is the place for key to be inserted
        //     // currently i is 1 before where key initially is

        //     while(i>=0 && (x_axis[i] > key)) {
        //         x_axis[i+1] = x_axis[i];
        //         i--;
        //     }
            
        //     x_axis[i+1] = key;
        // }

        // for(int x:x_axis) {
        //     cout << x << ", ";
        // } cout << endl;

        // sort(points.begin(), points.end());

        // int ans = 0;
        // for(int i=0; i<points.size()-1; i++) {
        //     ans = max(ans, abs(points[i][0]-points[i+1][0]));
        // }

        // Got this solution from LeetCode discuss section's top answer

        int ans = 0;
        set<int> x;
        for(auto &p:points) {
            x.insert(p[0]);
        }
        for(auto it = x.begin(); next(it) != x.end(); it++) {
            ans = max(ans, *next(it) - *it);
        }
        return ans;
    }
};
