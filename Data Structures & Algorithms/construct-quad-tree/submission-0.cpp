/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    bool allSame(vector<vector<int>>& grid, int n, int i, int j){
        for(int r = i; r < i + n; r++){
            for(int c = j; c < j + n; c++){
                if(grid[r][c] != grid[i][j])
                    return false;
            }
        }
        return true;
    }

    Node* solve(vector<vector<int>>& grid, int n, int i, int j){
        if(allSame(grid, n, i, j))
            return new Node(grid[i][j] == 1 ? true : false, true);

        Node* topLeft = solve(grid, n/2, i, j);
        Node* topRight = solve(grid, n/2, i, j + n/2);
        Node* bottomLeft = solve(grid, n/2, i + n/2, j);
        Node* bottomRight = solve(grid, n/2, i + n/2, j + n/2);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return solve(grid, n, 0, 0);
    }
};