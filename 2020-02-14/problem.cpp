#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T &first) { cin >> first; }
template<typename T, typename... Args>
inline void read(T &first, Args&... args) { cin >> first; read(args...); }

template<typename T>
inline void print(T &first) { cout << first << "\n"; }
template<typename T, typename... Args>
inline void print(T &first, Args&... args) { cout << first << " "; print(args...); }

template<typename T>
inline void printV(vector<T> &v) { for(auto elem: v) cout << elem << " "; cout << "\n"; }

template<typename T>
inline void dbg(T &first) { cerr << first << "\n"; }
template<typename T, typename... Args>
inline void dbg(T &first, Args&... args) { cerr << first << " "; dbg(args...); }


typedef unsigned long long int ull;

#define maxr(a,b) (a) = max((a),(b));
#define minr(a,b) (a) = min((a),(b));

#define MAXN 300000

int tree[2*MAXN + 10];


// root: first free position
int read1help(int n_child, int root, int deep){
  tree[root++] = deep;
  for(int i = 0; i < n_child; ++i){
    int child;
    cin >> child;
    root = read1help(child,root,deep + 1);
  }
  tree[root++] = deep;
  return root;
}

void reader1(){
  int root;
  cin >> root;
  read1help(root,0,0);
}

int reader2help(int n_nodes, int root, int deep){
  tree[root++] = deep;
  n_nodes--;
  while(n_nodes > 0){
    int child;
    cin >> child;
    root = reader2help(child,root,deep +1);
    n_nodes -= child;
  }
  tree[root++] = deep;
  return root;
}

void reader2(){
  int root;
  cin >> root;
  reader2help(root,0,0);
}

void reader3(){
  int i = 0;
  while(cin >> tree[i++]){}
}

void solve(){
  int r = 1;
  int w = 1;
  while(tree[r]!= 0){
    if(tree[r] % 2 == 0){
      tree[w++] = tree[r]/2;
    }
    r++;
  }
  tree[w] = 0;
  return;
}

// return root_read
pair<int,int> print1help(int root_read,int root_write){
  int deep = tree[root_read];
  pair<int,int> roots;
  roots.first = root_read + 1;
  roots.second = root_write + 1;
  int n_child = 0;
  while (tree[roots.first] > deep){
    roots = print1help(roots.first,roots.second);
    n_child++;
  }
  roots.first++;
  tree[root_write] = n_child;
  return roots;
}

void print1(){
  pair<int,int> roots = print1help(0,0);
  cout << "1 ";
  for(int i = 0; i < roots.second; ++i){
    cout << tree[i] << " ";
  }
  cout << endl;
}

// return root_read
pair<int,int> print2help(int root_read,int root_write){
  int deep = tree[root_read];
  pair<int,int> roots;
  roots.first = root_read + 1;
  roots.second = root_write + 1;
  int n_nodes = 1;
  while (tree[roots.first] > deep){
    int child_root = roots.second;
    roots = print2help(roots.first,roots.second);
    n_nodes += tree[child_root];
  }
  roots.first++;
  tree[root_write] = n_nodes;
  return roots;
}

void print2(){
  pair<int,int> roots = print2help(0,0);
  cout << "2 ";
  for(int i = 0; i < roots.second; ++i){
    cout << tree[i] << " ";
  }
  cout << endl;
}

void print3(){
  int i = 0;
  cout << "3 " <<  tree[i++] << " ";
  while(tree[i] != 0){
    cout << tree[i++] << " ";
  }
  cout << tree[i] << endl;
  return;
}

int main(int argc, char const *argv[]) {

  // Read Input
  int type;
  cin >> type;

  switch(type){
    case 1:
      reader1();
      break;
    case 2:
      reader2();
      break;
    case 3:
      reader3();
      break;
    default:
      exit(-1);
  }

  solve();

  switch(type){
    case 1:
      print1();
      break;
    case 2:
      print2();
      break;
    case 3:
      print3();
      break;
    default:
      exit(-1);
  }


  // Print output


  return 0;
}
