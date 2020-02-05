#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int M; // Maximum number of pizza slices
int N; // The number of different types of pizza
vector<int> slices;
vector<long long int> p_sum;

vector<map<int, ll> > op;

ll opt(int m,int n){
  if(m == 0 || n == 0){
    return 0;
  }

  auto it = op[n].find(m);
  if(it != op[n].end()){
    return op[n][m];
  }

  if(m>p_sum[n-1]){
    return p_sum[n-1];
  }

  ll not_taken = opt(m,n-1);

  if(m>=slices[n-1]){
    ll taken = opt(m-slices[n-1],n-1);
    taken += slices[n-1];
    if(not_taken > (taken) ){
      op[n][m] = not_taken;
    }else{
      op[n][m] = taken;
    }
  }else{
    op[n][m] = not_taken;
  }

  return op[n][m];
}

vector<int> reconstruct_sol(int m,int n){

  vector<int> sol;
  while(n>0){
    if(m>p_sum[n-1]){
      for(int i = 0; i < n; ++i){
        sol.push_back(i);
      }
      n = 0;
    }else{

      ll not_taken = op[n-1][m];

      if(m>=slices[n-1]){
        ll taken = op[n-1][m-slices[n-1]];
        if(not_taken <= (taken) ){
          sol.push_back(n);
        }
      }
      n--;
    }

  }

  return sol;
}


int main(int argc, char const *argv[]) {


  cin >> M >> N;

  long long int sum = 0;
  for(int i = 0; i < N; ++i){
    int tmp;
    cin >> tmp;
    slices.push_back(tmp);
    sum += tmp;
    p_sum.push_back(sum);
    op.push_back(map<int, ll >());
  }
  op.push_back(map<int, ll >());

  ll score = opt(M,N);
  vector<int> res = reconstruct_sol(M,N);

  cout << res.size() << endl;
  for(auto elem: res){
    cout << elem << " ";
  }
  cout << endl;

  cerr << "Score: " << score << endl;
  return 0;
}
