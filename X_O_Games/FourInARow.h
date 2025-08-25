
#ifndef _FOUR_IN_A_ROW_H
#define _FOUR_IN_A_ROW_H

#include "BoardGame_Classes.h"

template <typename T>
class FourInARow_Board : public Board<T> {
public:
    FourInARow_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class FourInARow_Player : public Player<T> {
public:
    FourInARow_Player(string name, T symbol);
    void getmove(int& x, int& y);
};

template <typename T>
class FourInARow_Random_Player : public RandomPlayer<T> {
public:
    FourInARow_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// Constructor for FourInARow_Board
template <typename T>
FourInARow_Board<T>::FourInARow_Board() {
    this->rows = 6;
    this->columns = 7;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

// Update board with lowest available square in the column
template <typename T>
bool FourInARow_Board<T>::update_board(int x, int y, T symbol) {
    if (y < 0 || y >= this->columns) return false;
    for (int i = this->rows - 1; i >= 0; i--) {
        if (this->board[i][y] == 0) {
            this->board[i][y] = toupper(symbol);
            this->n_moves++;
            return true;
        }
    }
    return false;
}

// Display the board
template <typename T>
void FourInARow_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << (this->board[i][j] ? this->board[i][j] : '.') << " |";
        }
    }
    cout << "\n-----------------------------\n";
}

// Check for win conditions (horizontal, vertical, diagonal)
template <typename T>
bool FourInARow_Board<T>::is_win() {
    // Horizontal
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] && this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j + 1] == this->board[i][j + 2] &&
                this->board[i][j + 2] == this->board[i][j + 3]) {
                return true;
            }
        }
    }
    // Vertical
    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] && this->board[i][j] == this->board[i + 1][j] &&
                this->board[i + 1][j] == this->board[i + 2][j] &&
                this->board[i + 2][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }
    // Diagonal (\)
    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] && this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i + 1][j + 1] == this->board[i + 2][j + 2] &&
                this->board[i + 2][j + 2] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }
    // Diagonal (/)
    for (int i = 3; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] && this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i - 1][j + 1] == this->board[i - 2][j + 2] &&
                this->board[i - 2][j + 2] == this->board[i - 3][j + 3]) {
                return true;
            }
        }
    }
    return false;
}

// Check if the game is a draw
template <typename T>
bool FourInARow_Board<T>::is_draw() {
    return (this->n_moves == this->rows * this->columns && !is_win());
}

template <typename T>
bool FourInARow_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

// Constructor for FourInARow_Player
template <typename T>
FourInARow_Player<T>::FourInARow_Player(string name, T symbol) : Player<T>(name, symbol) {}

// Get move from user
template <typename T>
void FourInARow_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move column (0 to 6): ";
    cin >> y;
    x = 0; // Row is determined automatically.
}

// Constructor for FourInARow_Random_Player
template <typename T>
FourInARow_Random_Player<T>::FourInARow_Random_Player(T symbol) : RandomPlayer<T>(symbol) {}

template <typename T>
void FourInARow_Random_Player<T>::getmove(int& x, int& y) {
    y = rand() % 7;
    x = 0; // Row is determined automatically.
}

#endif //_FOUR_IN_A_ROW_H
