// ***    380. Insert Delete GetRandom O(1)    *** //

class RandomizedSet {
private:
    unordered_set<int> numbers;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);    // Apparently I cannot beat the other guys without this....
    }
    
    bool insert(int val) {
        if(numbers.find(val) != numbers.end()) return false;
        numbers.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(numbers.find(val) == numbers.end()) return false;
        numbers.erase(val);
        return true;
    }
    
    int getRandom() {
        // int index = rand() % numbers.size();
        auto it = numbers.begin();
        advance(it, rand() % numbers.size());
        return *it;

        // return *next(numbers.begin(), index); // slower as pointer increments 1 by 1
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
