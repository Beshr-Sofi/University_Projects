#ifndef word_xo_h
#define word_xo_h

#include "BoardGame_Classes.h"
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
class word_x_o_board : public Board<T>{
    vector <string> three_letter_words;

    bool find_word(string word){
        int higher = three_letter_words.size() - 1;
        int lower = 0;
        while(lower <= higher){
            int middle = (higher+lower) / 2;
            if(word == three_letter_words[middle]){return true;}

            else if(word > three_letter_words[middle]){lower = middle + 1;}

            else if(word < three_letter_words[middle]){higher = middle - 1;}
        }
        // word not found
        return false;}

    public:
    word_x_o_board (){
        this->rows = 3;
        this->columns = 3;
        this->board = new char*[this->rows];
        for (int i = 0; i < this->rows; i++){
        this->board[i] = new char[this->columns];
            for (int j = 0; j < this->columns; j++){
                this->board[i][j] = 0;}
        }
        fstream file("dic.txt");
        string word;
        
        while(getline(file, word)){three_letter_words.push_back(word);}

        this->n_moves = 0;}

    bool update_board (int x , int y , T symbol){
        if(x >= 0 && x < this->rows && y <= this->columns && y >= 0 && this->board[x][y] == 0){
            if((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')){this->board[x][y] = (symbol);
            this->n_moves++;
            return true;}}

        return false;}
    
    void display_board (){
        for(int i = 0 ; i < this->rows ; i++){    
            for(int j = 0 ; j < this->columns ; j++){
                if(this->board[i][j] != 0){cout << "| ( " << this->board[i][j] << " ) ";}
                else{cout << "| (" << i << ',' << j << ") ";}}

            cout << "|\n";
            cout << setfill('-') << setw(8*3 + 2) << "\n";}
    }    
    
    bool is_win(){
        // get the word
        string word = "";

        // check all rows
        for(int i = 0 ; i < this->rows ; i++){
            word += this->board[i][0];
            word += this->board[i][1];
            word += this->board[i][2];
            if(find_word(word)){return true;}
            word = "";}

        // check all columns
        for(int j = 0 ; j < this->columns ; j++){
            word = "";
            word += this->board[0][j];
            word += this->board[1][j];
            word += this->board[2][j];
            if(find_word(word)){return true;}
            word = "";}

        // check left diagonal
        word = "";
        word += this->board[0][0];
        word += this->board[1][1];
        word += this->board[2][2];
        if(find_word(word)){return true;}
        
        // check left diagonal
        word = "";
        word += this->board[0][2];
        word += this->board[1][1];
        word += this->board[2][0];
        if(find_word(word)){return true;}

        return false;}

    bool is_draw(){return (this->n_moves == 9 && !is_win());}
    
    bool game_is_over(){return (is_draw() || is_win());}    
};

template <typename T>
class word_x_o_player : public Player<T>{ 
    public:
    word_x_o_player(string name) : Player<T>(name, 0){}
    

    void getmove(int &x, int &y){
        char c;
        cout << "Enter the letter you want then your move x and y (0 to 2) separated by spaces: ";
        cin >> c >> x >> y;
        this->symbol = (toupper(c));}
};

template <typename T>
class random_word_x_o_player : public RandomPlayer <T> {
    public:
    random_word_x_o_player(char non = 0) : RandomPlayer <T> (non) {
        srand(static_cast<unsigned int>(time(0)));
        this->name = "Random Computer Player";}
    
    void set_symbol(char c){this->symbol = c;}

    void getmove(int &x, int &y){
        char c = (rand() % 26) + 65;
        this->set_symbol(c); 
        x = rand() % 3;
        y = rand() % 3;}      
};

#endif