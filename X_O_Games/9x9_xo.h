#ifndef xo_9x9_h
#define xo_9x9_h

#include "BoardGame_Classes.h"
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

class xo_9x9_board : public Board <char> {
    public:
    // if a player wins in a board inset it's index in his set
    set<int> player1_wins;
    set<int> player2_wins;

    // true = someone won in the board
    bool done_boards[9] = {0};

    xo_9x9_board(){
        this->rows = 9;
        this->columns = 9;
        this->board = new char*[this->rows];
        for(int i = 0 ; i < this->rows ; i++){
            this->board[i] = new char[this->columns];
            for(int j = 0 ; j < this->columns ; j++){
                this->board[i][j] = 0;}
        
        this->n_moves = 0;}
    }

    void check_all_boards(){
        int board_num = 0;
        for(int i : {0,3,6}){
            for(int j : {0,3,6}){
                // someone already won in this board so don't check it
                if(done_boards[board_num]){board_num ++; continue;}

                // check all possible outcomes
                int x = i;
                // rows
                for(int i : {x,x+1,x+2}){
                    if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j] != 0){
                        add_to_set(board_num, this->board[i][j]);
                        done_boards[board_num] = true;}
                }
                x = j;
                // columns
                for(int j : {x,x+1,x+2}){
                    if(this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j] && this->board[i][j] != 0){
                        add_to_set(board_num, this->board[i][j]);
                        done_boards[board_num] = true;}
                }
                // diagonals
                if(this->board[i][j] == this->board[i+1][j+1] && this->board[i][j] == this->board[i+2][j+2] && this->board[i][j] != 0){
                    add_to_set(board_num, this->board[i][j]);
                    done_boards[board_num] = true;    
                }
                if(this->board[i][j+2] == this->board[i+1][j+1] && this->board[i][j+2] == this->board[i+2][j] && this->board[i][j+2] != 0){
                    add_to_set(board_num, this->board[i][j+2]);
                    done_boards[board_num] = true;
                }
                board_num ++;}
        }
    }
    
    bool update_board (int x , int y , char symbol){
        if(x >= 0 && x < this->rows && y <= this->columns && y >= 0 && this->board[x][y] == 0){
            this-> board[x][y] = symbol;
            this->n_moves ++;
            return true;}
        else{return false;}    
        check_all_boards();}

    // fill the winning board with the winning symbol
    void fill_the_board(){
        int board_num = 0;
        for(int i : {0,3,6}){
            for(int j : {0,3,6}){
                // the board is found in one of the 2 sets
                if(player1_wins.find(board_num) != player1_wins.end()){
                    for(int x : {i,i+1,i+2}){
                        for(int y : {j, j+1, j+2}){
                            if(this->board[x][y] == 0){this->n_moves ++;}
                            this->board[x][y] = 'X';}
                    }
                }
                else if(player2_wins.find(board_num) != player2_wins.end()){
                    for(int x : {i,i+1,i+2}){
                        for(int y : {j, j+1, j+2}){
                            if(this->board[x][y] == 0){this->n_moves ++;}
                            this->board[x][y] = 'O';}
                    }                    
                }
                board_num++;
            }
        }
    }

    void display_board(){
        fill_the_board();
        int threes_rows = 0;
        for(int i = 0 ; i<this->rows ; i++){
            if(threes_rows % 3 == 0){threes_rows = 0; cout << endl;}
            int threes = 0;
            for(int j = 0 ; j < this->columns ; j++){
                if(threes % 3 == 0){threes = 0; cout << " ";}
                if(this->board[i][j] != 0){cout << "( " << this->board[i][j] << " ) ";}
                else{cout << "(" << i << ',' << j << ") ";}
                threes ++;}

            threes_rows ++;
            cout << "\n";
            cout << setfill('-') << setw(8*7 + 2) << "\n";}
    }

    void add_to_set(int num, char symbol){
        if(symbol == 'X'){player1_wins.insert(num);}
        else{player2_wins.insert(num);}
    }

    // returns true if a possible winning outcome is found 
    bool find_set(set<int>& winningPosition, set<int>& player){
        for(const int& elem : winningPosition){
            if (player.find(elem) == player.end()){
                return false;}
        }
         return true;}    

    bool is_win(){
        check_all_boards();
        fill_the_board();
        //all Possible 9x9 winning positions
        set<set<int>> winningPositions = {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},  
            {1, 4, 7},  
            {2, 5, 8},  
            {0, 4, 8}, 
            {2, 4, 6} 
        };
        for(set<int> win_pos : winningPositions){
            if(find_set(win_pos, player1_wins)){return true;}
            else if(find_set(win_pos, player2_wins)){return true;}
        }
        return false;}

    bool is_draw(){
        return (this->n_moves == 9*9 && !is_win());}

    bool game_is_over(){
        return (is_win() || is_draw());}
};

class xo_9x9_player : public Player <char>{
    public:
    xo_9x9_player(string name, char symbol) : Player<char>(name, symbol){};
 
    void getmove(int &x, int &y){
        cout << "Enter your move x and y (0 to 8) separated by spaces: ";
        cin >> x >> y;
    }
};

class random_xo_9x9_player : public RandomPlayer <char>{
    public:
    random_xo_9x9_player (char symbol) : RandomPlayer <char> (symbol){};

    void getmove(int &x, int &y){
        x = rand() % 9;
        y = rand() % 9;}     
};

#endif