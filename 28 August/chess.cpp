#include <bits/stdc++.h>
using namespace std;

const int N = 8;

// Print the chessboard
void printBoard(vector<vector<char>> &board) {
    cout << "\n   a b c d e f g h\n";
    for (int i = 0; i < N; i++) {
        cout << 8 - i << "  ";
        for (int j = 0; j < N; j++) cout << board[i][j] << " ";
        cout << " " << 8 - i << "\n";
    }
    cout << "   a b c d e f g h\n\n";
}

bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Convert chess notation like 'e2' -> coordinates
pair<int,int> notationToCoord(string pos) {
    int y = pos[0] - 'a';
    int x = 8 - (pos[1] - '0');
    return {x, y};
}

int main() {
    vector<vector<char>> board(N, vector<char>(N, '.'));

    // Place Kings and Pawns only
    board[7][4] = 'K'; // White King
    board[6][4] = 'P'; // White Pawn
    board[0][4] = 'k'; // Black King
    board[1][4] = 'p'; // Black Pawn

    cout << "♟️ Simple Chess Demo (Kings and Pawns only)\n";
    printBoard(board);

    string from, to;
    char turn = 'W';

    while (true) {
        cout << (turn == 'W' ? "White" : "Black") << "'s move (e.g., e2 e3): ";
        cin >> from >> to;

        pair<int,int> f = notationToCoord(from);
        pair<int,int> t = notationToCoord(to);
        char piece = board[f.first][f.second];

        if (piece == '.') { cout << "No piece at source!\n"; continue; }
        if ((turn == 'W' && islower(piece)) || (turn == 'B' && isupper(piece))) {
            cout << "Not your piece!\n"; continue;
        }

        // Simplified move check (only pawn and king)
        bool validMove = false;
        if (toupper(piece) == 'P') {
            int dir = (isupper(piece) ? -1 : 1);
            if (t.first == f.first + dir && t.second == f.second && board[t.first][t.second] == '.')
                validMove = true;
        } else if (toupper(piece) == 'K') {
            if (abs(f.first - t.first) <= 1 && abs(f.second - t.second) <= 1)
                validMove = true;
        }

        if (!validMove) {
            cout << "Invalid move!\n";
            continue;
        }

        // Make move
        board[t.first][t.second] = piece;
        board[f.first][f.second] = '.';
        printBoard(board);

        // Switch turn
        turn = (turn == 'W' ? 'B' : 'W');
    }
}
