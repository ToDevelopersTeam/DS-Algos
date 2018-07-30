class Solution {
    public:
        int ladderLength(string start, string end, vector<string> &dictV) {
            unordered_set<string> dict(dictV.begin(), dictV.end());
            unordered_map<string, int> distance; // store the distancetance from start to the current word
            queue<string> q; // FIFO for bfs purpose
            distance[start] = 1;
            q.push(start);
            while (!q.empty()) {
                string word = q.front(); 
                q.pop();
                if (word == end) break;
                for (int i = 0; i < word.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string newWord = word;
                        newWord[i] = 'a' + j;
                        if (dict.find(newWord) != dict.end() && distance.find(newWord) == distance.end()) {
                            distance[newWord] = distance[word] + 1;
                            q.push(newWord);
                        }
                    }
                }
            }
            if (distance.find(end) == distance.end()) return 0; // not found
            return distance[end];
        }
};