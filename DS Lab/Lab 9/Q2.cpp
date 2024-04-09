#include <iostream>
#include<vector>
using namespace std;

string direction = "DLRU";
int dr[4] = { 1, 0, 0, -1 };
int dc[4] = { 0, -1, 1, 0 };

	bool isValid(int row, int col, int n, vector<vector<int> >& maze)
	{
	    return row >= 0 && col >= 0 && row < n && col < n
	           && maze[row][col];
	}
	
	void findPath(int row, int col, vector<vector<int> >& maze,
	              int n, vector<string>& ans,
	              string& currentPath)
	{
	    if (row == n - 1 && col == n - 1) {
	        ans.push_back(currentPath);
	        return;
	    }
	    maze[row][col] = 0;
	
	    for (int i = 0; i < 4; i++) {
	        int nextrow = row + dr[i];
	        int nextcol = col + dc[i];
	
	        if (isValid(nextrow, nextcol, n, maze)) {
	            currentPath += direction[i];
	            findPath(nextrow, nextcol, maze, n, ans,
	                     currentPath);
	            currentPath.pop_back();
	        }
	    }
	    maze[row][col] = 1;
	}

int main()
{
    vector<vector<int> > maze = { { 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 1, 1, 0, 0 }, { 0, 1, 1, 1 } };

    int n = maze.size();
    vector<string> result;
    string currentPath = "";

    if (maze[0][0] != 0 && maze[n - 1][n - 1] != 0) {
        findPath(0, 0, maze, n, result, currentPath);
    }

    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
    return 0;
}