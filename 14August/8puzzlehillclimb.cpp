#include <bits/stdc++.h>
using namespace std;

string goal3 = "123456780";
int dx3[] = {-1, 1, 0, 0};
int dy3[] = {0, 0, -1, 1};

int manhattan(string state) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (state[i] != '0') {
            int val = state[i] - '1';
            dist += abs(i / 3 - val / 3) + abs(i % 3 - val % 3);
        }
    }
    return dist;
}

void hillClimb(string start) {
    string curr = start;
    int currCost = manhattan(curr);

    while (true) {
        int pos = curr.find('0');
        int x = pos / 3, y = pos % 3;

        string nextState = curr;
        int bestCost = currCost;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx3[i], ny = y + dy3[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string temp = curr;
                swap(temp[pos], temp[nx * 3 + ny]);
                int cost = manhattan(temp);
                if (cost < bestCost) {
                    bestCost = cost;
                    nextState = temp;
                }
            }
        }

        if (bestCost == currCost) {
            cout << "Local minimum reached or Goal found!\n";
            for (int i = 0; i < 9; i++) {
                cout << curr[i] << " ";
                if (i % 3 == 2) cout << endl;
            }
            return;
        }

        curr = nextState;
        currCost = bestCost;

        cout << "Current Heuristic: " << currCost << endl;
        for (int i = 0; i < 9; i++) {
            cout << curr[i] << " ";
            if (i % 3 == 2) cout << endl;
        }
        cout << "-------\n";

        if (curr == goal3) {
            cout << "Goal Reached!\n";
            break;
        }
    }
}

int main() {
    string start = "125340678";
    hillClimb(start);
}
