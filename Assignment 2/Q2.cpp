#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class ZumaGame {
public:
    int minBallsToClear(string board, string hand) {
        return simulate(board, hand);
    }

private:
    int simulate(string board, string hand) {
        queue<pair<string, string>> q;
        q.push({board, hand});

        while (!q.empty()) {
            auto [curBoard, curHand] = q.front();
            q.pop();

            if (curBoard.empty()) {
                return board.size() - hand.size();
            }

            for (char ball : curHand) {
                for (size_t i = 0; i <= curBoard.size(); ++i) {
                    string newBoard = curBoard.substr(0, i) + ball + curBoard.substr(i);
                    string newHand = curHand;
                    newHand.erase(newHand.find(ball), 1);

                    simplifyBoard(newBoard);
                    if (!newBoard.empty()) {
                        q.push({newBoard, newHand});
                    }
                }
            }
        }

        return -1;
    }

    void simplifyBoard(string& board) {
        stack<pair<char, int>> st;
        for (char ball : board) {
            if (!st.empty() && st.top().first == ball) {
                st.top().second++;
            } else {
                st.push({ball, 1});
            }

            while (!st.empty() && st.top().second >= 3) {
                int count = st.top().second;
                while (count--) {
                    st.pop();
                }
            }
        }

        board.clear();
        while (!st.empty()) {
            board = string(st.top().second, st.top().first) + board;
            st.pop();
        }
    }
};

int main() {
    ZumaGame game;
    string board = "RRGGWY";
    string hand = "YB";
    int result = game.minBallsToClear(board, hand);
    cout << "Minimum balls to clear: " << result << endl;  // Output: 2
    return 0;
}
