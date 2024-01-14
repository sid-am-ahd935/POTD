// ***    1657. Determine if Two Strings Are Close    *** //


class Solution {
public:
    bool closeStrings(string &word1, string &word2) {
        // As we can swap elements' positions freely, no need to worry about the order anymore
        // Just use the 2nd operation logic to determine the countof the strings equal or not...

        // For this, we just have to check whether the counts of former is similar to counts of the latter

        // First check if all characters exist between
        // Then check if all counts are are same, i.e., sorting the frequency array would be same

        if(word1.size() != word2.size()) {
            return false;
        }

        vector<int> a(26, 0), b(26, 0);

        for(char &c:word1) {
            a[c-'a']++;
        }
        for(char &c:word2) {
            b[c-'a']++;
        }

        for(int i=0; i<26; i++) {
            // Checking if a new element is there in word1 not present in word2 or vice versa
            if((a[i]==0 && b[i]!=0) || (b[i]==0 && a[i] != 0)) return false;
        }

        // For checking the similarity in frequencies
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        return a==b;
    }
};
