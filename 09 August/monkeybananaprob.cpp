#include <bits/stdc++.h>
using namespace std;

struct State {
    string monkeyPos;
    string boxPos;
    bool monkeyOnBox;
    bool hasBanana;
};

void printState(const State &s) {
    cout << "Monkey at: " << s.monkeyPos
         << ", Box at: " << s.boxPos
         << ", OnBox: " << (s.monkeyOnBox ? "Yes" : "No")
         << ", HasBanana: " << (s.hasBanana ? "Yes" : "No") << endl;
}

void monkeyBanana() {
    State s = {"door", "window", false, false};
    cout << "Initial State:\n";
    printState(s);
    cout << "------------------\n";

    // Step 1: Walk to box
    cout << "Action: Walk to window\n";
    s.monkeyPos = "window";
    printState(s);

    // Step 2: Push box to middle
    cout << "Action: Push box to middle\n";
    s.boxPos = "middle";
    s.monkeyPos = "middle";
    printState(s);

    // Step 3: Climb box
    cout << "Action: Climb on box\n";
    s.monkeyOnBox = true;
    printState(s);

    // Step 4: Grasp banana
    cout << "Action: Grasp banana\n";
    s.hasBanana = true;
    printState(s);

    cout << "\n✅ Goal achieved! Monkey has the banana.\n";
}

int main() {
    monkeyBanana();
    return 0;
}
