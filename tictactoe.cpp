#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    
public:
    // Constructor - initializes the game
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
    
    // Display the current board state
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
            if (i < 2) {
                cout << "---|---|---\n";
            }
        }
        cout << "\n";
    }
    
    // Display the position guide
    void displayGuide() {
        cout << "\nPosition guide:\n";
        cout << " 1 | 2 | 3\n";
        cout << "---|---|---\n";
        cout << " 4 | 5 | 6\n";
        cout << "---|---|---\n";
        cout << " 7 | 8 | 9\n\n";
    }
    
    // Make a move at the given position
    bool makeMove(int position) {
        // Convert position (1-9) to row and column (0-2)
        position--;
        int row = position / 3;
        int col = position % 3;
        
        // Check if position is valid and empty
        if (position < 0 || position > 8 || board[row][col] != ' ') {
            return false;
        }
        
        // Place the current player's mark
        board[row][col] = currentPlayer;
        return true;
    }
    
    // Check if there's a winner
    bool checkWinner() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && 
                board[i][1] == currentPlayer && 
                board[i][2] == currentPlayer) {
                return true;
            }
        }
        
        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == currentPlayer && 
                board[1][i] == currentPlayer && 
                board[2][i] == currentPlayer) {
                return true;
            }
        }
        
        // Check diagonals
        if (board[0][0] == currentPlayer && 
            board[1][1] == currentPlayer && 
            board[2][2] == currentPlayer) {
            return true;
        }
        
        if (board[0][2] == currentPlayer && 
            board[1][1] == currentPlayer && 
            board[2][0] == currentPlayer) {
            return true;
        }
        
        return false;
    }
    
    // Check if the board is full (draw condition)
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Switch to the other player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    // Get the current player
    char getCurrentPlayer() {
        return currentPlayer;
    }
    
    // Play the game
    void play() {
        cout << "Welcome to Tic-Tac-Toe!\n";
        displayGuide();
        
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << "'s turn.\n";
            cout << "Enter position (1-9): ";
            
            int position;
            cin >> position;
            
            // Input validation
            if (cin.fail() || position < 1 || position > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
                continue;
            }
            
            // Try to make the move
            if (!makeMove(position)) {
                cout << "That position is already taken or invalid! Try again.\n";
                continue;
            }
            
            // Check for winner
            if (checkWinner()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            
            // Check for draw
            if (isBoardFull()) {
                displayBoard();
                cout << "It's a draw! The board is full.\n";
                break;
            }
            
            // Switch to the other player
            switchPlayer();
        }
        
        cout << "\nThanks for playing!\n";
    }
};

int main() {
    char playAgain;
    
    do {
        TicTacToe game;
        game.play();
        
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Goodbye!\n";
    return 0;
}