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
public:
    Node *build_nodes(vector<vector<int>>& grid, int i, int j, int n) {
        bool val = (grid[i][j] == 1);
        if (n == 1)
            return get_node(val);
        int len = n / 2;
        Node *tl = build_nodes(grid, i, j, len);
        Node *tr = build_nodes(grid, i, j + len, len);
        Node *bl = build_nodes(grid, i + len, j, len);
        Node *br = build_nodes(grid, i + len, j + len, len);
        if (tl->isLeaf && tr->isLeaf &&
            bl->isLeaf && br->isLeaf &&
            (tl->val == tr->val) &&
            (bl->val == br->val) && (tl->val == bl->val)) {
            return get_node(val);
        }
        return new Node(val, false, tl, tr, bl, br);
    }
    
    Node *get_node(bool val) {
        Node *node = new Node();
        node->val = val;
        node->isLeaf = true;
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return nullptr;
        return build_nodes(grid, 0, 0, grid.size());        
    }
};
