#include <bits/stdc++.h>
using namespace std;

// Each state is represented as (x, y) => x liters in jug1, y liters in jug2
struct State {
    int x, y;
};

// Print path from start to goal
void printPath(map<pair<int,int>, pair<int,int>> parent, pair<int,int> goal) {
    vector<pair<int,int>> path;
    while (goal.first != -1 && goal.second != -1) {
        path.push_back(goal);
        goal = parent[goal];
    }
    reverse(path.begin(), path.end());

    cout << "\nPath to reach goal:\n";
    for (auto &p : path)
        cout << "(" << p.first << ", " << p.second << ")\n";
}

void waterJug(int jug1, int jug2, int target) {
    queue<State> q;
    set<pair<int,int>> visited;
    map<pair<int,int>, pair<int,int>> parent; // for path tracking

    q.push({0, 0});
    visited.insert({0, 0});
    parent[{0,0}] = {-1, -1};

    while (!q.empty()) {
        State curr = q.front(); q.pop();

        // Check if goal reached
        if (curr.x == target || curr.y == target) {
            cout << "\n✅ Goal reached: (" << curr.x << ", " << curr.y << ")\n";
            printPath(parent, {curr.x, curr.y});
            return;
        }

        // Generate all possible next moves
        vector<State> nextStates = {
            {jug1, curr.y},                // Fill jug1
            {curr.x, jug2},                // Fill jug2
            {0, curr.y},                   // Empty jug1
            {curr.x, 0},                   // Empty jug2
            {curr.x - min(curr.x, jug2 - curr.y), curr.y + min(curr.x, jug2 - curr.y)}, // Pour jug1 -> jug2
            {curr.x + min(curr.y, jug1 - curr.x), curr.y - min(curr.y, jug1 - curr.x)}  // Pour jug2 -> jug1
        };

        for (auto &next : nextStates) {
            if (!visited.count({next.x, next.y})) {
                visited.insert({next.x, next.y});
                parent[{next.x, next.y}] = {curr.x, curr.y};
                q.push(next);
            }
        }
    }

    cout << "\n❌ No solution found!\n";
}

int main() {
    int jug1 = 4, jug2 = 3, target = 2;
    cout << "Water Jug Problem (Jug1 = " << jug1 << "L, Jug2 = " << jug2 << "L, Target = " << target << "L)\n";
    waterJug(jug1, jug2, target);
    return 0;
}