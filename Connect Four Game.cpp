#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

// Function to print the Connect Four board
void printBoard(const vector<vector<char>>& board) {
    cout << " 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << "|";
        for (int j = 0; j < COLS; ++j) {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check for horizontal win
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Check for vertical win
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check for diagonal (top-left to bottom-right) win
    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check for diagonal (bottom-left to top-right) win
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, ' '));
    char currentPlayer = 'X';
    int column;

    cout << "Connect Four Game" << endl;

    int moves = 0;
    while (true) {
        printBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (column[1-7]): ";
        cin >> column;

        // Convert to 0-based index
        --column;

        // Check if the column is valid
        if (column < 0 || column >= COLS || board[0][column] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Find the row to place the disc
        int row;
        for (row = ROWS - 1; row >= 0; --row) {
            if (board[row][column] == ' ') {
                board[row][column] = currentPlayer;
                break;
            }
        }

        // Check if the current player wins
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game is a draw
        if (++moves == ROWS * COLS) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
