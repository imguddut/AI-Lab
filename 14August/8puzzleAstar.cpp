#include <bits/stdc++.h>
using namespace std;

string goal4 = "123456780";
int dx4[] = {-1, 1, 0, 0};
int dy4[] = {0, 0, -1, 1};

int heuristic(string state) {
    int dist = 0;
    for (int i = 0; i < 9; i++) {
        if (state[i] != '0') {
            int val = state[i] - '1';
            dist += abs(i / 3 - val / 3) + abs(i % 3 - val % 3);
        }
    }
    return dist;
}

struct Node {
    string state;
    int g, h;
    bool operator<(const Node &other) const {
        return (g + h) > (other.g + other.h);
    }
};

void aStar(string start) {
    priority_queue<Node> pq;
    map<string, string> parent;
    set<string> visited;

    pq.push({start, 0, heuristic(start)});
    parent[start] = "";

    while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        if (visited.count(node.state)) continue;
        visited.insert(node.state);

        if (node.state == goal4) {
            cout << "Goal Found using A*!\n";
            vector<string> path;
            string s = node.state;
            while (s != "") {
                path.push_back(s);
                s = parent[s];
            }
            reverse(path.begin(), path.end());
            for (auto &p : path) {
                for (int i = 0; i < 9; i++) {
                    cout << p[i] << " ";
                    if (i % 3 == 2) cout << endl;
                }
                cout << "-------\n";
            }
            return;
        }

        int pos = node.state.find('0');
        int x = pos / 3, y = pos % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx4[i], ny = y + dy4[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string next = node.state;
                swap(next[pos], next[nx * 3 + ny]);
                if (!visited.count(next)) {
                    parent[next] = node.state;
                    pq.push({next, node.g + 1, heuristic(next)});
                }
            }
        }
    }
    cout << "Goal not reachable.\n";
}

int main() {
    string start = "125340678";
    aStar(start);
}
