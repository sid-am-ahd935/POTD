// ***    1496. Path Crossing    *** //

/*
class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_set<int>> visited;
        int x = 0, y = 0;

        visited[x].insert(y);
        for(char c:path) {
            switch(c) {
                case 'N': y += 1; break;
                case 'S': y -= 1; break;
                case 'E': x += 1; break;
                case 'W': x -= 1; break;
                default: return -1;
            }
            // cout << c << "::" << x << ", " << y << endl;
            if(visited.find(x) != visited.end()){
                if(visited[x].find(y) != visited[x].end()) {
                    // cout << x << ", " << y << "TRUE" << endl;
                    
                    // ========= I don't know why adding this line reduces the time for running to 0ms....
                    // cout << ((int) *visited[x].find(y)) << endl;

                    return true;
                }
            }
            visited[x].insert(y);
        }
        return false;
    }
};
*/

// New solution

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;
        int x = 0, y = 0;

        visited.insert("0-0");
        for(char c:path) {
            switch(c) {
                case 'N': y += 1; break;
                case 'S': y -= 1; break;
                case 'E': x += 1; break;
                case 'W': x -= 1; break;
                default: return -1;
            }
            // cout << c << "::" << x << ", " << y << endl;
            string key = to_string(x) + "-" + to_string(y);
            if(visited.find(key) != visited.end()){
                return true;
            }
            visited.insert(key);
        }
        return false;
    }
};
