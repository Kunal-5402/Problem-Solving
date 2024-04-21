class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(i==parent[i]){
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;

        if(rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else{
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        rank.resize(n,0);
        parent.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            Union(u,v);
        }

        int src_parent = find(source);
        int dest_parent = find(destination);

        if(src_parent == dest_parent)
            return true;
        
        return false;
    }
};