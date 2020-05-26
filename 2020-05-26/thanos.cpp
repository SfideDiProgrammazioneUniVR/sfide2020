#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

long long int tot_dead = 0;
vector<long long int> vec;

int thanos(int N){
    if(N == 1)
        return 0;
    if(vec[N-1] < N-1)
        return 1;   // thanos kills himself
    else {
        if(vec[N-2]>=vec[N-1]){
            long long int dead = vec[N-2] - vec[N-1] + 1;
            tot_dead+=dead;
            vec[N-2] = vec[N-2] - dead;
        }
        return thanos(N-1);
            
    }
       
}


int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        long long int a;
        cin >> a;
        vec.push_back(a);
    }
       

    if(thanos(N) == 0)
        cout << tot_dead << endl;
    else
        cout << 1 << endl;
    
    
    return 0;
}
