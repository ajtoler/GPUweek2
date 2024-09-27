#include <iostream>
using namespace std;

void result(const string player1, const string player2) {
    if (player1 == player2)
        cout << "Draw!" << endl;
    
    // player 1 wins
    else if ((player1 == "rock" && player2 == "scissors") || (player1 == "paper" && player2 == "rock") || (player1 == "scissors" && player2 == "paper"))
        cout << "Player 1 wins!" << endl;
    
    // player 2 wins
    else if ((player2 == "rock" && player1 == "scissors") || (player2 == "paper" && player1 == "rock") || (player2 == "scissors" && player1 == "paper"))
        cout << "Player 2 wins!" << endl;

    else
        cout << "Error" << endl;
}

int main() {
    string player1;
    string player2;
    
    cout << "Player 1, please enter rock, paper, or scissors: ";
    cin >> player1;
    cout << "Player 2, please enter rock, paper, or scissors: ";
    cin >> player2;
    
    result(player1, player2);

    return 0;
}
