#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mover = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    vector<vector<char>> board;
    
    bool dfs(int x, int y, string& s, vector<vector<bool>> vis)
    {
        if (s.length() == 0)
            return true;
        vis[x][y] = true;
        bool sol = false;
        
        for (int i = 0; i < mover.size(); i++) {
            int curr_x = mover[i][0] + x;
            int curr_y = mover[i][1] + y;
            
            if (curr_x >= 0 && curr_x < board.size()) {
                if (curr_y >= 0 && curr_y < board[0].size()) {
                    if (board[curr_x][curr_y] == s[0] && !vis[curr_x][curr_y]) {
                        string k = s.substr(1);
                        sol |= dfs(curr_x, curr_y, k, vis);
                    }
                }
            }
        }
        return sol;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        this->board = board;
        vector<string> ans;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        
        for (auto& word : words) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (board[i][j] == word[0]) {
                        string s = word.substr(1);
                        if (dfs(i, j, s, vis)) {
                            ans.push_back(word);
                            break;
                        }
                    }
                }
                if (!ans.empty() && ans.back() == word)
                    break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solver;
    vector<vector<char>> board = { { 'o', 'a', 'a', 'n' },
                                   { 'e', 't', 'a', 'e' },
                                   { 'i', 'h', 'k', 'r' },
                                   { 'i', 'f', 'l', 'v' } };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    vector<string> ans = solver.findWords(board, words);
    
    cout << "words present:\n";
    for (auto& part : ans)
        cout << part << endl;
    return 0;
}
