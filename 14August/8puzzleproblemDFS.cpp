#include <bits/stdc++.h>
using namespace std;

string goal = "123456780"; // Goal state

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to print board
void printState(string s) {
    for (int i = 0; i < 9; i++) {
        cout << s[i] << " ";
        if (i % 3 == 2) cout << endl;
    }
    cout << "-------\n";
}

// DFS function with depth limit
bool dfs(string state, set<string> &visited, int depth, int limit) {
    // Print current state (for visibility)
    cout << "Depth " << depth << ":\n";
    printState(state);

    // Check if goal reached
    if (state == goal) {
        cout << "\n✅ Goal found at depth " << depth << "!\n";
        printState(state);
        return true;
    }

    // Stop if depth exceeds limit
    if (depth >= limit) return false;

    visited.insert(state);

    int pos = state.find('0'); // Blank tile position
    int x = pos / 3, y = pos % 3;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            string newState = state;
            swap(newState[pos], newState[nx * 3 + ny]);
            if (!visited.count(newState)) {
                if (dfs(newState, visited, depth + 1, limit))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    string start = "125340678"; // Example start state
    set<string> visited;

    int depthLimit = 20; // Limit DFS depth to avoid infinite recursion

    cout << "Starting DFS with depth limit = " << depthLimit << "\n\n";

    if (!dfs(start, visited, 0, depthLimit))
        cout << "\n❌ Goal not found within depth limit.\n";
}
