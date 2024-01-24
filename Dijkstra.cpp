#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 100001;

int n,m,s,t;
vector<pair<int,int>> adj[maxn];

const int INF = 1e9;

void dijkstra(int s, int t){
    vector <ll> d(n+1,INF);
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    Q.push({0,s});
    while(!Q.empty()){
        pair<int,int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u])  continue;
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.push({d[v],v});

            }
        }
    }
	cout << d[t];

}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    int s,t;
    cin >> s >> t;
    dijkstra(s,t);
    return 0;
}