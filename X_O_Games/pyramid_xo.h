#ifndef pyramid_xo_h
#define pyramid_xo_h

#include "BoardGame_Classes.h"
#include <iomanip>

using namespace std;

template<typename T>
class pyramid_xo_board : public Board<T>{
public:
    pyramid_xo_board (){
        this->rows = 3;
        this->columns = 5;
        this->board = new char*[this->rows];
        for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++){
                this->board[i][j] = 0;}
        }
        this->n_moves = 0;}

    bool update_board (int x , int y , T symbol){
        // this is y if the matrix was normal 
        y = y - (x - this->rows + 1);    
        if(x >= 0 && x < this->rows && y <= this->columns/2 + x && y >= this->columns/2 - x && this->board[x][y] == 0){
            this->board[x][y] = symbol;
            this->n_moves ++;
            return true;}
        return false;}
    
    void display_board (){
        for(int i = 0 ; i < this->rows ; i++){
            int x = 0;
            for(int j = 0 ; j < this->columns/2 + i + 1 ; j++){
                if(j >= this->columns/2 - i && j <= this->columns/2 + i){
                    if(this->board[i][j] != 0){cout << "| ( " << this->board[i][j] << " ) ";}
                    else{cout << "| (" << i << ',' << x << ") ";}
                    x++;}
                    
                else{cout << setfill(' ') << setw(8) << "";}
            }
            cout << "|\n";

            for(int j = 0 ; j < this->columns/2 + i + 1 ; j++){
                if(j >= this->columns/2 - i && j <= this->columns/2 + i){cout << setfill('-') << setw(8) << "";}    
                else{cout << setfill(' ') << setw(8) << "";}
            }
            cout << "-\n";}
    }
    
    bool is_win(){
        // both possible diagonal wins
        if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0){return true;}
        else if(this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4] && this->board[2][4] != 0){return true;}
        
        // only winning column
        else if(this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[2][2] != 0){return true;}
        
        // all possible winning rows
        int sides = 1;
        for(int i = 1 ; i < this->rows ; i++){
            for(int j = 0 ; j < this->columns-2 ; j++){
                if(j >= this->columns/2 - sides && j <= this->columns/2 + sides){
                    if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2] && this->board[i][j+1] != 0){return true;}
                }
            }
            sides ++;}
        return false;}

    bool is_draw(){return ( this->n_moves == 9 && !is_win() );}
    
    bool game_is_over(){return ( is_win() || is_draw()) ;}    
};

template <typename T>
class pyramid_xo_player : public Player <T> {
    public:
    pyramid_xo_player(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int &x, int &y){
        cout << "Enter your move x and y (0 to 2) separated by spaces: ";
        cin >> x >> y;}
};

template <typename T>
class pyramid_random_xo_player : public RandomPlayer<T>{
    public:
    pyramid_random_xo_player(T symbol): RandomPlayer <T>(symbol) {}

    void getmove(int &x, int &y){
        x = rand() % 3;
        y = rand() % 5;}    
};

#endif