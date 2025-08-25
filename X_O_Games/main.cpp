#include "BoardGame_Classes.h"
#include "pyramid_xo.h"
#include "FourInARow.h"
#include "5x5_xo.h"
#include "word_xo.h"
#include "Numerical_xo.h"
#include "inverse_xo.h"
#include "4x4_xo.h"
#include "9x9_xo.h"

int main(){
    while (true){
        int choice, player1, player2;
        Player<char>* players[2];
        Board<char>* B;
        Board<int> *B_int;
        Player<int>* int_players[2];
        string playerXName, player2Name;

        cout << "Choose a game to play \n";
        cout << "1) pyramid XO\n" << "2) four-in-a-row XO\n" << "3) 5x5 XO\n" << "4) word XO\n" << "5) Numerical XO\n" << "6) Misery XO\n" 
        << "7) 4x4 XO\n" << "8 ultimate 9x9 XO \n" << " --> ";
        cin >> choice;

        // checking the game choice 
        while(cin.fail()){
            cin.clear(); fflush(stdin);
            cout << "error\n";
            cout << "Choose a game to play \n";
            cout << "1) pyramid XO\n" << "2) four-in-a-row XO\n" << "3) 5x5 XO\n" << "4) word XO\n" << "5) Numerical XO\n" << "6) Misery XO\n" 
            << "7) 4x4 XO\n" << "8 ultimate 9x9 XO \n" << " --> ";
            cin >> choice;}

        // Set up player 1
        cout << "Enter Player X name: ";
        cin >> playerXName;
        cout << "Choose Player X type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> player1;

        // Set up player 2
        cout << "Enter Player O name: ";
        cin >> player2Name;
        cout << "Choose Player O type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cin >> player2;

        // setting up the game
        switch (choice){
            case 1 :
                B = new pyramid_xo_board<char>();
                switch(player1){
                    case 1:
                        players[0] = new pyramid_xo_player<char>(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new pyramid_random_xo_player<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
             
                switch(player2){
                    case 1:
                        players[1] = new pyramid_xo_player<char>(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new pyramid_random_xo_player<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }
                break;
            case 2 :
                B = new FourInARow_Board<char>();
                switch(player1){
                    case 1:
                        players[0] = new FourInARow_Player<char>(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new FourInARow_Random_Player<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
             
                switch(player2){
                    case 1:
                        players[1] = new FourInARow_Player<char>(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new FourInARow_Random_Player<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }
                break;
            case 3 :
                switch(player1){
                    case 1:
                        players[0] = new xo_5x5_player<char>(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new random_xo_5x5_player<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
             
                switch(player2){
                    case 1:
                        players[1] = new xo_5x5_player<char>(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new random_xo_5x5_player<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }
                B = new xo_5x5_board<char>(players);            
                break;
            case 4 :
                B = new word_x_o_board<char>();
                switch(player1){
                    case 1:
                        players[0] = new word_x_o_player<char>(playerXName);
                        break;
                    case 2:
                        players[0] = new random_word_x_o_player<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
        
                switch(player2){
                    case 1:
                        players[1] = new word_x_o_player<char>(player2Name);
                        break;
                    case 2:
                        players[1] = new random_word_x_o_player<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }                
                break;
            case 5 :
            B_int = new NumericalBoard();
                switch(player1){
                    case 1:
                        int_players[0] = new NumericalPlayer(playerXName, 1);
                        break;
                    case 2:
                        int_players[0] = new random_numerical_player(1);
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
                
                switch(player2){
                    case 1:
                        int_players[1] = new NumericalPlayer(playerXName, 2);
                        break;
                    case 2:
                        int_players[1] = new random_numerical_player(2);
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }              
                break;
            case 6 :
                B = new Inverse_X_O_Board<char>();
                switch(player1){
                    case 1:
                        players[1] = new Inverse_X_O_Player<char>(playerXName, 'O');
                        break;
                    case 2:
                        players[1] = new Inverse_X_O_Random_Player<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
        
                switch(player2){
                    case 1:
                        players[0] = new Inverse_X_O_Player<char>(player2Name, 'X');
                        break;
                    case 2:
                        players[0] = new Inverse_X_O_Random_Player<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }                
                break;                
            case 7 :
                switch(player1) {
                    case 1:
                        players[0] = new xo_4x4_player<char>(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new xo_4x4_random<char>('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }                

                switch(player2) {
                    case 1:
                        players[1] = new xo_4x4_player<char>(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new xo_4x4_random<char>('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }

                B = new xo_4x4_board<char>(players);
                break;
            case 8 :
                B = new xo_9x9_board();
                switch(player1){
                    case 1:
                        players[0] = new xo_9x9_player(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new random_xo_9x9_player('X');
                        break;
                    default:
                        cout << "Invalid choice for Player 1\n";
                        break;
                }
        
                switch(player2){
                    case 1:
                        players[1] = new xo_9x9_player(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new random_xo_9x9_player('O');
                        break;
                    default:
                        cout << "Invalid choice for Player 2\n";
                        break;
                }                    
                break;
            default :
                break;
        }

        if(choice == 5){
            GameManager<int> x_o_game(B_int, int_players);
            x_o_game.run();

            // Clean up
            delete B_int;
            for (int i = 0; i < 2; ++i) {
                delete int_players[i];}
        }
        else{
            GameManager<char> x_o_game(B, players);
            x_o_game.run();

            // Clean up
            delete B;
            for (int i = 0; i < 2; ++i) {
                delete players[i];}
        }
    }
    return 0;}
