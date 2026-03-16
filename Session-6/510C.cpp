#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);

    for(int i = 0; i < n-1; i++){
        string a = s[i];
        string b = s[i+1];

        int len = min(a.size(), b.size());
        bool found = false;

        for(int j = 0; j < len; j++){
            if(a[j] != b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                indegree[b[j]-'a']++;
                found = true;
                break;
            }
        }

        if(!found && a.size() > b.size()){
            cout << "Impossible";
            return 0;
        }
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int nbr : adj[node]){
            indegree[nbr]--;
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    if(topo.size() != 26){
        cout << "Impossible";
        return 0;
    }

    for(int x : topo)
        cout << char(x + 'a');

    return 0;
}
