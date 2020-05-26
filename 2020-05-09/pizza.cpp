#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;



int col, row;


int man(int r, int c, vector<vector<int>> mat){

    int sum = 0;
    for (int i = 0; i < mat.size(); i++) { 
        for (int j = 0; j < mat[i].size(); j++) 
            sum += ( mat[i][j] * (abs(r-i) + abs(c-j)) ); 
    }

    return sum;


    // for(vector<int> one_row : mat)
    // {
    //     for(int one_cell_in_this_row : one_row)
    //     {
    //         cout << one_cell_in_this_row << ' ';
    //     }   
    //     cout << endl;
    // } 


    // int sum = 0;
    // for (int i = 0; i < row; i++) 
    //     for (int j = 0; j < col; j++) 
    //         sum += ( mat[i][j] * (abs(r-i) + abs(c-j)) ); 
    // return sum; 

}


int main(){
    int test_case;
    cin >> test_case;
    // cout << test_case;
    for(int i=0; i<test_case; i++){
        
        cin >> col;
        cin >> row;

        // int mat[row][col];
        vector<vector<int>> mat(row, vector<int>(col));
        

        for(int i=0; i<row; ++i)                 
        {                                        
            for(int j=0; j<col; ++j)             
            {                                    
                int current_entry;
                cin>>current_entry;
                mat.at(i).at(j) = current_entry;
            }
        }
        int s = 0;
        int best_s = 0;
        int index1 = 0;
        int index2 = 0;

        vector<array<int, 2> > q; 
        q.push_back({{0,0}});


        while(!q.empty()){
            array<int, 2> tmp = q.back(); 
            q.pop_back();
            // cout << tmp[0] << "," << tmp[1];
            s = man(tmp[0], tmp[1], mat);
            if(s<best_s || best_s == 0){
                best_s = s;
                q.push_back({{tmp[0]+1,tmp[1]}});
                q.push_back({{tmp[0],tmp[1]+1}});
            }
        }

        
        // for(int i=1; i<row; ++i)                                                       
        //     for(int j=1; j<col; ++j){
        //         // if(mat[i][j] == 0 || mat[i][j] == 1)
        //         //     continue;
        //         s = man(i, j, mat);
        //         if(s<best_s || best_s == 0){
        //             best_s = s;
        //             index1 = i;
        //             index2=j;
        //         }
        //     }
        
        cout << best_s << " blocks" << endl;
        // cout << index1 << ", " << index2 << endl;
        


    }






    
    return 0;
}
