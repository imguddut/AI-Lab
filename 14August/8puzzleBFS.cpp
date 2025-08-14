#include <bits/stdc++.h>
using namespace std;

string goal2 = "123456780";
int dx2[] = {-1, 1, 0, 0};
int dy2[] = {0, 0, -1, 1};

void printPath(map<string, string> &parent, string state) {
    vector<string> path;
    while (state != "") {
        path.push_back(state);
        state = parent[state];
    }
    reverse(path.begin(), path.end());
    for (auto &s : path) {
        for (int i = 0; i < 9; i++) {
            cout << s[i] << " ";
            if (i % 3 == 2) cout << endl;
        }
        cout << "-------\n";
    }
}

void bfs(string start) {
    queue<string> q;
    map<string, string> parent;
    set<string> visited;
    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string curr = q.front(); q.pop();
        if (curr == goal2) {
            cout << "Goal Found!\n";
            printPath(parent, curr);
            return;
        }

        int pos = curr.find('0');
        int x = pos / 3, y = pos % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx2[i], ny = y + dy2[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string next = curr;
                swap(next[pos], next[nx * 3 + ny]);
                if (!visited.count(next)) {
                    visited.insert(next);
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }
    }
    cout << "Goal not reachable\n";
}

int main() {
    string start = "125340678";
    bfs(start);
}
