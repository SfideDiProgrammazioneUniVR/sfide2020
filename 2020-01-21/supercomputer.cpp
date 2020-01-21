#include <bits/stdc++.h>

using namespace std;

#define LSB(x) ((x) & (-x))

#define MAXN 1000010

int p_sum[MAXN];

void update(int pos, int val){
  while(pos < MAXN){
    p_sum[pos] += val;
    pos += LSB(pos);
  }
}

int query(int pos){
  int sum = 0;
  while(pos > 0){
    sum += p_sum[pos];
    pos -= LSB(pos);
  }
  return sum;
}

int main(int argc, char const *argv[]) {

  int N,K;
  cin >> N >> K;

  for(int i = 0; i < K; ++i){

    char command;

    cin >> command;

    if(command == 'F'){
      int pos;
      cin >> pos;

      int old_val = query(pos) - query(pos-1);
      int new_val = (old_val?-1:1);

      update(pos,new_val);
    }else{
      int l,r;
      cin >> l>> r;

      int res = query(r)-query(l-1);

      cout << res << endl;
    }


  }

  return 0;
}
