class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        queue<pair<int,int>> q;
        q.push({src, 0});
        
        int stops = 0;
        
        while(!q.empty() && stops <= k){
            int size = q.size();
            
            while(size--){
                auto [node, cost] = q.front();
                q.pop();
                
                for(auto &it : adj[node]){
                    int nextNode = it.first;
                    int price = it.second;
                    
                    if(cost + price < dist[nextNode]){
                        dist[nextNode] = cost + price;
                        q.push({nextNode, dist[nextNode]});
                    }
                }
            }
            
            stops++;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
