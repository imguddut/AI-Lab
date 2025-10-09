#include <bits/stdc++.h>
using namespace std;

struct State {
    vector<vector<char>> stacks; // Each stack represents a pile of blocks
    string path;                 // Path of moves made to reach this state
};

// Function to print a state
void printState(const vector<vector<char>>& stacks) {
    cout << "------\n";
    for (int i = 0; i < stacks.size(); i++) {
        cout << "Stack " << i + 1 << ": ";
        for (auto b : stacks[i]) cout << b << " ";
        cout << endl;
    }
    cout << "------\n";
}

// Compare two states
bool isGoal(const vector<vector<char>>& s1, const vector<vector<char>>& s2) {
    return s1 == s2;
}

// Serialize the state into a string for visited-checking
string serialize(const vector<vector<char>>& stacks) {
    string key = "";
    for (auto st : stacks) {
        for (auto b : st) key += b;
        key += "|"; // separator between stacks
    }
    return key;
}

// BFS to reach goal configuration
void solve(vector<vector<char>> start, vector<vector<char>> goal) {
    queue<State> q;
    set<string> visited;

    q.push({start, ""});
    visited.insert(serialize(start));

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // Goal check
        if (isGoal(cur.stacks, goal)) {
            cout << "\n✅ Goal Reached!\n";
            printState(cur.stacks);
            cout << "Moves: " << cur.path << endl;
            return;
        }

        // Try moving top block from one stack to another
        for (int i = 0; i < cur.stacks.size(); i++) {
            if (cur.stacks[i].empty()) continue; // no block to move

            char block = cur.stacks[i].back();
            for (int j = 0; j < cur.stacks.size(); j++) {
                if (i == j) continue;

                vector<vector<char>> newStacks = cur.stacks;
                newStacks[i].pop_back();     // remove from source
                newStacks[j].push_back(block); // add to destination

                string key = serialize(newStacks);
                if (!visited.count(key)) {
                    visited.insert(key);
                    string move = cur.path + "Move " + block + " from " + 
                                   to_string(i+1) + " to " + to_string(j+1) + " | ";
                    q.push({newStacks, move});
                }
            }
        }
    }

    cout << "❌ Goal not reachable!\n";
}

int main() {
    // Define start configuration
    vector<vector<char>> start = {
        {'B', 'A'},  // Stack 1
        {'C'}        // Stack 2
    };

    // Define goal configuration
    vector<vector<char>> goal = {
        {'A'},       // Stack 1
        {'C', 'B'}   // Stack 2
    };

    cout << "🏁 Starting Block World Problem...\n";
    cout << "Initial State:\n";
    printState(start);
    cout << "Goal State:\n";
    printState(goal);

    solve(start, goal);

    return 0;
}
