#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {

  int n,m,q,s;

  cin >> n >> m >> q >> s;

  while(n!=0 || m != 0 || q != 0 || s != 0){

    vector<vector<pair<int, int> > > adj(n);

    for(int i = 0; i < m; ++i){
      int u,v,w;

      cin >> u >> v >> w;

      adj[u].push_back(make_pair(v,w));
    }

    vector<int> min_dist(n,-1);

    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
      auto curr = pq.top(); pq.pop();
      if(min_dist[curr.second] == -1){
        min_dist[curr.second] = -curr.first;
        for(auto elem: adj[curr.second]){
          if(min_dist[elem.first] == -1){
            pq.push(make_pair(curr.first - elem.second, elem.first));
          }
        }
      }
    }

    for(int i = 0; i < q; ++i){
      int t;
      cin >> t;

      if(min_dist[t] != -1){
        cout << min_dist[t] << endl;
      }else{
        cout << "Impossible" << endl;
      }
    }



    cin >> n >> m >> q >> s;

    if(n!=0 || m != 0 || q != 0 || s != 0) cout << endl;
  }

  return 0;
}
