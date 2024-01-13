// ***    1704. Determine if String Halves Are Alike    *** //

// Beats 100% in time and space

class Solution {
public:
    bool halvesAreAlike(string &s) {
        int p1 = 0, p2 = s.size()-1, count = 0;
        for(int p1=0, p2=s.size()-1; p1<p2; p1++, p2--) {
            count += (s[p1] == 'a' || s[p1] == 'e' || s[p1] == 'i' || s[p1] == 'o' || s[p1] == 'u' || s[p1] == 'A' || s[p1] == 'E' || s[p1] == 'I' || s[p1] == 'O' || s[p1] == 'U');
            count -= (s[p2] == 'a' || s[p2] == 'e' || s[p2] == 'i' || s[p2] == 'o' || s[p2] == 'u' || s[p2] == 'A' || s[p2] == 'E' || s[p2] == 'I' || s[p2] == 'O' || s[p2] == 'U');
        }

        return !count;
    }
};


// Clean code but slightly less efficient

// class Solution {
// public:
//     bool halvesAreAlike(string s) {
//         int count = 0, n = s.size();
//         unordered_set<short> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

//         for(int i=0; i<n; i++) {
//             count += (vowels.find(s[i]) != vowels.end()) * (2*(i<n/2) -1);
//         }

//         return !count;
//     }
// };
