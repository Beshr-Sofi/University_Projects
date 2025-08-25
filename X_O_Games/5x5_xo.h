#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>

using namespace std;

template<typename T>
class xo_5x5_board : public Board<T> {
private:
    Player<char>* names[2];
    vector<vector<bool>> FirstPlayer;
    vector<vector<bool>> SecondPlayer;
    int FirstPlayerPoints;
    int SecondPlayerPoints;
public:
    xo_5x5_board (Player<char>* players[2]){
        names[0] = players[0];
        names[1] = players[1];

        FirstPlayer = vector<vector<bool>>(25, vector<bool>(4, false));
        SecondPlayer = vector<vector<bool>>(25, vector<bool>(4, false));
        FirstPlayerPoints = 0;
        SecondPlayerPoints = 0;

        this->rows = this->columns = 5;
        this->board = new char*[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = 0;
            }
        }
        this->n_moves = 0;
    }

    bool update_board (int x , int y , T mark) override{
        // this is y if the matrix was normal
        if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
            if (mark == 0){
                this->n_moves--;
                this->board[x][y] = 0;
            }
            else {
                this->n_moves++;
                this->board[x][y] = toupper(mark);
            }

            return true;
        }
        return false;
    }

    void display_board () override{
        for (int i = 0; i < this->rows; i++) {
            cout << "\n| ";
            for (int j = 0; j < this->columns; j++) {
                if (this -> board[i][j]=='X' || this-> board[i][j]=='O'){
                    cout << "( " << this->board[i][j] << " ) | ";
                }
                else{
                    cout << "(" << i << "," << j << ") | ";
                }
            }
            cout << "\n-----------------------------------------";
        }
        cout << endl;
    }

    bool is_win() override{
        if (this->n_moves == 24){
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (this->board[i][j]=='X'&& j-1>=0 && j+1 < 5 && this->board[i][j-1]== this->board[i][j] && this -> board[i][j+1] == this->board[i][j]){
                        FirstPlayerPoints++;
                    }
                    if (this->board[i][j]=='X'&& i-1>=0 && i+1 < 5 && this->board[i-1][j]== this->board[i][j] && this -> board[i+1][j] == this->board[i][j]){
                        FirstPlayerPoints++;
                    }
                    if (this->board[i][j]=='X'&& i-1>=0 && i+1 < 5 &&j-1>=0 && j+1 < 5 && this->board[i-1][j-1]== this->board[i][j] && this -> board[i+1][j+1] == this->board[i][j]){
                        FirstPlayerPoints++;
                    }
                    if (this->board[i][j]=='X'&& i-1>=0 && i+1 < 5 &&j-1>=0 && j+1 < 5 && this->board[i-1][j+1]== this->board[i][j] && this -> board[i+1][j-1] == this->board[i][j]){
                        FirstPlayerPoints++;
                    }
                }
            }

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (this->board[i][j]=='O'&& j-1>=0 && j+1 < 5 && this->board[i][j-1]== this->board[i][j] && this -> board[i][j+1] == this->board[i][j]){
                        SecondPlayerPoints++;
                    }
                    if (this->board[i][j]=='O'&& i-1>=0 && i+1 < 5 && this->board[i-1][j]== this->board[i][j] && this -> board[i+1][j] == this->board[i][j]){
                        SecondPlayerPoints++;
                    }
                    if (this->board[i][j]=='O'&& i-1>=0 && i+1 < 5 &&j-1>=0 && j+1 < 5 && this->board[i-1][j-1]== this->board[i][j] && this -> board[i+1][j+1] == this->board[i][j]){
                        SecondPlayerPoints++;
                    }
                    if (this->board[i][j]=='O'&& i-1>=0 && i+1 < 5 &&j-1>=0 && j+1 < 5 && this->board[i-1][j+1]== this->board[i][j] && this -> board[i+1][j-1] == this->board[i][j]){
                        SecondPlayerPoints++;
                    }
                }
            }

            return SecondPlayerPoints > FirstPlayerPoints;
        }
        else{
            return false;
        }
    }

    bool is_draw() override{
        if (this->n_moves == 24){
            if (SecondPlayerPoints==FirstPlayerPoints){
                return true;
            }
        }
        return false;
    }

    bool game_is_over() override{
        if (this->n_moves == 24){
            if (FirstPlayerPoints > SecondPlayerPoints){
                cout << this->names[0]->getname() << " is win\n";
            }
            return true;
        }
        return false;
    }
};

template <typename T>
class xo_5x5_player : public Player <T> {
public:
    xo_5x5_player(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int &x, int &y) override{
        cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
        cin >> x >> y;
    }
};

template <typename T>
class random_xo_5x5_player : public RandomPlayer<T> {
public:
    random_xo_5x5_player(T symbol): RandomPlayer <T>(symbol) {
        this->dimension = 5;
        this->name = "Random Computer Player";
        srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    }

    void getmove(int &x, int &y){
        x = rand() % this->dimension;  // Random number between 0 and 4
        y = rand() % this->dimension;
    }
};