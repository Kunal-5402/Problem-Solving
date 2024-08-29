class Solution {
public:
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>> adj;

        int i = 0;
        for(auto &it: edges){
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;
        }

        vector<double> result(n,0.0);
        result[start_node] = 1;
        priority_queue<P> pq;

        pq.push({1.0, start_node});

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for(auto &temp : adj[currNode]) {
                double adjProb = temp.second;
                int adjNode = temp.first;
                if(result[adjNode] < currProb * adjProb){
                    result[adjNode] = currProb * adjProb;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result[end_node];
    }
};