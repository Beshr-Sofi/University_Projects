#ifndef _NUMERICAL_TIC_TAC_TOE_H
#define _NUMERICAL_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// Numerical Tic-Tac-Toe Board
class NumericalBoard : public Board<int> {
public:
    NumericalBoard() : board(3, vector<int>(3, 0)), rows(3), columns(3), n_moves(0) {}

    bool update_board(int x, int y, int number) override {
        if (x >= 0 && x < rows && y >= 0 && y < columns && board[x][y] == 0) {
            board[x][y] = number;
            n_moves++;
            return true;
        }
        return false;
    }

    void display_board() override {
        for(int i = 0 ; i < this->rows ; i++){    
            for(int j = 0 ; j < this->columns ; j++){
                if(this->board[i][j] != 0){cout << "| ( " << this->board[i][j] << " ) ";}
                else{cout << "| (" << i << ',' << j << ") ";}}

            cout << "|\n";
            cout << setfill('-') << setw(8*3 + 2) << "\n";}
    }

    bool is_win() override {
        for (int i = 0; i < rows; ++i) {
            if (is_sum_15(board[i][0], board[i][1], board[i][2]) ||
                is_sum_15(board[0][i], board[1][i], board[2][i])) {
                return true;
            }
        }
        return is_sum_15(board[0][0], board[1][1], board[2][2]) ||
               is_sum_15(board[0][2], board[1][1], board[2][0]);
    }

    bool is_draw() override {
        return (n_moves == 9 && !is_win());
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }

private:
    bool is_sum_15(int a, int b, int c) {
        return (a + b + c == 15 && a != 0 && b != 0 && c != 0);
    }

    vector<vector<int>> board;
    int rows, columns, n_moves;
};

// Numerical Tic-Tac-Toe Player
class NumericalPlayer : public Player<int> {
private:
    unordered_set<int> available_numbers; // Track used numbers

public:
    NumericalPlayer(string name, int symbol) : Player<int>(name, symbol) {
        for (int i = (symbol == 1 ? 1 : 2); i <= 9; i += 2) {
            available_numbers.insert(i);
        }
    }

    void getmove(int& x, int& y) override {
        int number;
        do {
            cout << this->name << ", enter your move (row col number): ";
            cin >> x >> y >> number;
        } while (available_numbers.find(number) == available_numbers.end() || x < 0 || x > 3 || y < 0 || y > 3);
        this->symbol = number;
        available_numbers.erase(number);
    }
};

class random_numerical_player : public RandomPlayer<int>{
    private:
    unordered_set<int> available_numbers; // Track used numbers

    public:
    random_numerical_player(int symbol) : RandomPlayer(symbol) {
        for (int i = (symbol == 1 ? 1 : 2); i <= 9; i += 2) {
            available_numbers.insert(i);
        }
        srand(static_cast<unsigned int>(time(0)));}

    void getmove(int &x, int &y){
        int number;
        do {
        number;
        x = rand() % 3;
        y = rand() % 3;
        number = rand() % 9;
        } while (available_numbers.find(number) == available_numbers.end() || x < 0 || x > 3 || y < 0 || y > 3);
        this->symbol = number;
        available_numbers.erase(number);}        

};


#endif //_NUMERICAL_TIC_TAC_TOE_H