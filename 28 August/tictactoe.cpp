#include <bits/stdc++.h>
using namespace std;

// Print the Tic Tac Toe board
void printBoard(vector<vector<char>> &board) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check if someone won
bool checkWin(vector<vector<char>> &b, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == player && b[i][1] == player && b[i][2] == player) return true;
        if (b[0][i] == player && b[1][i] == player && b[2][i] == player) return true;
    }
    // Check diagonals
    if (b[0][0] == player && b[1][1] == player && b[2][2] == player) return true;
    if (b[0][2] == player && b[1][1] == player && b[2][0] == player) return true;
    return false;
}

// Check if board full
bool isFull(vector<vector<char>> &board) {
    for (auto &row : board)
        for (auto c : row)
            if (c == ' ') return false;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int row, col;

    cout << "🎮 Tic Tac Toe Game\n";
    printBoard(board);

    while (true) {
        cout << "Player " << player << ", enter row and column (1-3): ";
        cin >> row >> col;

        // Adjust index (1-based input)
        row--; col--;

        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "❌ Invalid move! Try again.\n";
            continue;
        }

        // Make move
        board[row][col] = player;
        printBoard(board);

        // Check win or draw
        if (checkWin(board, player)) {
            cout << "🏆 Player " << player << " wins!\n";
            break;
        }
        if (isFull(board)) {
            cout << "😅 It's a draw!\n";
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
