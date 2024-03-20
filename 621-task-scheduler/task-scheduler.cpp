class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int f = 0;
        int X = 0;
        int totalJobs = tasks.size();

        unordered_map<char,int> _m;

        for (char &c : tasks) {
            _m[c]++;

            if (f < _m[c])
                f = _m[c];
        }

        for (auto &a : _m) {
            if (a.second == f) {
                X++;
            }
        }

        return max((f - 1) * (n + 1) + X, totalJobs);
    }
};