#include<bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;

inline double dist(pdd a,pdd b){
  return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int uf[800];

int find(int i){
  while(uf[i] != 0){
    i = uf[i];
  }
  return i;
}

void my_union(int i, int j){
  int a = find(i);
  int b = find(j);
  if(a < b) uf[b] = a;
  else if( a > b ) uf[a] = b;
}



int main(int argc, char const *argv[]) {

  int n;

  cin >> n;

  for(int i = 0; i < n; ++i){

    int m;

    cin >> m;

    vector<pdd> points(m);

    for(int j = 0; j < m; ++j){
      cin >> points[j].first >> points[j].second;
    }

    double cost = 0.0;

    // Prim
    // priority_queue<pair<double,int>> pq;
    // vector<bool> visited(m,false);
    //
    // pq.push(make_pair(0.0,0));
    // while(!pq.empty()){
    //   auto curr = pq.top(); pq.pop();
    //   if(!visited[curr.second]){
    //     visited[curr.second] = true;
    //     cost -= curr.first;
    //     for(int j = 0; j < m; ++j)
    //       if(!visited[j]) pq.push( make_pair( -dist(points[curr.second], points[j]) , j) );
    //   }
    //
    // }

    // Kruskal

    priority_queue< pair<double, pair<int,int> > > pq;
    memset(uf,0,800*sizeof(int));

    for (size_t j = 0; j < m; j++) {
      for (size_t k = 0; k < j; k++) {
        pq.push(make_pair(-dist(points[j],points[k]),make_pair(j+1,k+1)));
      }
    }


    while(!pq.empty()){
      auto curr = pq.top(); pq.pop();

      int a = find(curr.second.first);
      int b = find(curr.second.second);

      if( a != b){
        cost -= curr.first;
        my_union(a,b);
      }
    }

    cout << cost << endl;
  }


  return 0;
}
