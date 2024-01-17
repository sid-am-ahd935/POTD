// ***    1207. Unique Number of Occurrences    *** //

// Fastest solution lowest memory
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        unordered_set<int> unique_counts;

        for(int &n:arr) {
            counts[n]++;
        }
        for(auto c:counts) {
            if(unique_counts.find(c.second) != unique_counts.end()) {
                return false;
            }
            unique_counts.insert(c.second);
        }
        return true;
    }
};

// Efficient memory 
/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       int i = 0;
      sort(arr.begin(),arr.end());
     vector<int> ans;
    while (i < arr.size()){
         int count = 1;
         for (int j = i+1; j< arr.size(); j++){
         if (arr[i] == arr[j])
            count++;
            }
      ans.push_back(count);
            i = i + count;
        }
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size() - 1; i++){
            if (ans[i] == ans [i+1])
                return false;
        }
        return true;
    }
};
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> No_count;
        int count=1 ;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i=i+count){ 
            count=1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j] ){
                    
                    count++;
                } 
            }
           
            No_count.push_back(count);
        }

       sort( No_count.begin(),No_count.end());
        for(int i=0;i<No_count.size();i++){
            for(int j=i+1;j<No_count.size();j++){
                if(No_count[i]==No_count[j]){
                    return false;
                }
            }
        }

        return true;
    }
};
