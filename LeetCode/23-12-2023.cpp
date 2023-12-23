// ***    1496. Path Crossing    *** //

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
                    return true;
                }
            }
            visited[x].insert(y);
        }
        return false;
    }
};
