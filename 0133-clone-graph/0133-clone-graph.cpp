/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* node, map<Node*, Node*>& copies) {
        if (node == nullptr) {
            return nullptr;
        }

        if (copies.count(node)) {
            return copies[node];
        }

        Node* copy = new Node(node -> val);
        copies[node] = copy;

        for (Node* n: node -> neighbors) {
            copy -> neighbors.push_back(dfs(n, copies));
        }

        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> copies;
        return dfs(node, copies);
    }
};