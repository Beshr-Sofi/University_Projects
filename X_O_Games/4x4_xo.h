
#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "BoardGame_Classes.h"
#include <ctime>
#include <cstdlib>

template <typename T>
class xo_4x4_board: public Board<T> {
private:
    Player<char>* names[2];
public:
    xo_4x4_board (Player<char>* players[2]);
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class xo_4x4_player : public Player<T> {
public:
    xo_4x4_player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class xo_4x4_random : public RandomPlayer<T>{
public:
    xo_4x4_random (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for xo_4x4_board
template <typename T>
xo_4x4_board<T>::xo_4x4_board(Player<char>* players[2]) {
    names[0] = players[0];
    names[1] = players[1];
    this->rows = this->columns = 4;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    this->board[0][0] = this->board[0][2]= this->board[3][1] = this ->board[3][3] = 'O';
    this->board[0][1] = this->board[0][3]= this->board[3][0] = this ->board[3][2] = 'X';
}

template <typename T>
bool xo_4x4_board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    int counter = 1,cnt=1;
    int choice;
    vector<bool>checker(4, false);
    int temp = time(0);
    srand(x);
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns)) {
        if (this->n_moves%2==1 && (this->board[x][y] != 'O')){
            if (names[1]->getname()!="Random Computer Player")
                cout << "Please enter O index!!\n";
            return false;
        }
        else if(this->n_moves%2==0 && (this->board[x][y] != 'X')){
            if (names[0]->getname()!="Random Computer Player")
                cout << "Please enter X index!!\n";
            return false;
        }
        if(x==0 && y == 0 && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O') && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (x == 3 && y==0 && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (x == 0 && y==3 && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O') && (this->board[x][y-1]=='X' || this->board[x][y-1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (x == 3 && y==3 && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x][y-1]=='X' || this->board[x][y-1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if(x==0 && y-1>=0 && y+1 < 4 && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O') && (this->board[x][y-1]=='X' || this->board[x][y-1]=='O') && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (y==0 && x+1 < 4 && x-1>=0 && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O') && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if(x==3 && y-1>=0 && y+1 < 4 && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x][y-1]=='X' || this->board[x][y-1]=='O') && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (y==3 && x+1 < 4 && x-1>=0 && (this->board[x][y-1]=='X' || this->board[x][y-1]=='O') && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        else if (x-1>=0 && x+1<4 && y-1 >= 0 && y+1< 4 && (this->board[x-1][y]=='X' || this->board[x-1][y]=='O') && (this->board[x+1][y]=='X' || this->board[x+1][y]=='O') &&
                 (this->board[x][y-1]=='X' || this->board[x][y-1]=='O') && (this->board[x][y+1]=='X' || this->board[x][y+1]=='O')){
            if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2==0) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2))
                cout << "You can't move this\n";
            return false;
        }
        this->n_moves++;
        if ((names[0]->getname()!="Random Computer Player" && this->n_moves%2) || (names[1]->getname()!="Random Computer Player" && this->n_moves%2==0))
            cout << "Please choose a move: \n";
        if (x-1>=0 && this->board[x-1][y]!='X' && this->board[x-1][y]!='O'){
            checker[0]= true;
            cout << counter++ << "- Up\n";
        }
        if (x+1<4 && this->board[x+1][y]!='X' && this->board[x+1][y]!='O'){
            checker[1]= true;
            cout << counter++ <<"- Down\n";
        }
        if (y-1>=0 && this->board[x][y-1]!='X' && this->board[x][y-1]!='O'){
            checker[2]= true;
            cout << counter++ << "- Left\n";
        }
        if (y+1<4 && this->board[x][y+1]!='X' && this->board[x][y+1]!='O'){
            checker[3]= true;
            cout << counter++ <<"- Right\n";
        }
        if (names[0]->getname()=="Random Computer Player" && this->n_moves%2){
            choice = 1 + rand() % (counter-1);
        }
        else if (names[1]->getname()=="Random Computer Player" && this->n_moves%2==0){
            choice = 1 + rand() % (counter-1);
        }
        else{
            cin >> choice;
            while(cin.fail() || choice<1 || choice > counter){
                cout << "Invalid input!!\n please enter your choice(1 to "<<counter-1<<")\n";
                cin.ignore();
                cin >> choice;
            }
        }
        this->board[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            if (checker[i]){
                if (cnt==choice){
                    cnt = i+1;
                    break;
                }
                else cnt++;
            }
        }
        if (cnt-1==0) this->board[x-1][y] = mark;
        else if(cnt-1 == 1) this->board[x+1][y] = mark;
        else if(cnt-1 == 2) this->board[x][y-1] = mark;
        else if(cnt-1 == 3) this->board[x][y+1] = mark;
        return true;
    }
    else return false;
}

// Display the board and the pieces on it
template <typename T>
void xo_4x4_board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool xo_4x4_board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; ++j) {
            if ((this->board[i][j]=='X' || this->board[i][j]=='O')){
                if ((j-1>=0 && j+1<4 && this->board[i][j] == this->board[i][j-1] && this->board[i][j+1]==this->board[i][j]) ||
                    (i-1>=0&& i+1<4 && this->board[i][j] == this->board[i-1][j] && this->board[i+1][j] == this->board[i][j]) ||
                    (j-1>=0 && j+1<4 && i-1>=0 && i+1<4 && this->board[i-1][j-1] == this->board[i][j] && this->board[i][j] == this->board[i+1][j+1]) ||
                    (j-1>=0 && j+1<4 && i-1>=0 && i+1<4 && this->board[i-1][j+1] == this->board[i][j] && this->board[i][j] == this->board[i+1][j-1])) {
                    return true;
                }
            }
        }
    }
    return false;
}
template <typename T>
bool xo_4x4_board<T>::is_draw() {
    return false;
}

template <typename T>
bool xo_4x4_board<T>::game_is_over() {
    return is_win();
}

//--------------------------------------

// Constructor for xo_4x4_player
template <typename T>
xo_4x4_player<T>::xo_4x4_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void xo_4x4_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 3) separated by spaces: ";
    cin >> x >> y;
}

// Constructor for xo_4x4_random
template <typename T>
xo_4x4_random<T>::xo_4x4_random(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void xo_4x4_random<T>::getmove(int& x, int& y) {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    x = rand() % this->dimension;  // Random number between 0 and 3
    y = rand() % this->dimension;
}







#endif //_3X3X_O_H

