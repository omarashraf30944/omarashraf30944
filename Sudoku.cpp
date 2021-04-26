#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ValidSudoku(vector<vector<char>>& board) {
    bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            int n = board[i][j] - '1', k = i / 3 + 3 * (j / 3);
            if (cols[i][n] || rows[j][n] || boxes[k][n]) //checking if the number already exists in the row, column or sub-box
                return false;
            cols[i][n] = rows[j][n] = boxes[k][n] = true;
        }
    return true;
}
bool solveBoard(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(ValidSudoku(board)){
                            board[i][j]=c;
                            if(solveBoard(board))//cheacking every possibility in the spot board[i][j] that will be valid
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
           
    return true;
    }

int main()
{
    
     vector<vector<char>> board { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                                  { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                  { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                  { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                  { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                  { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                  { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                  { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                  { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
                                  
    if(solveBoard(board) == true){
        cout<<"Solved Board " <<endl;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout<<board[i][j]<<", ";
        }
        cout<<endl;
    }
    }else{
        cout<<"Board cannot be solved"<<endl;
    }
    

    
return 0;    
}