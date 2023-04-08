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
public:
    unordered_map<Node* , Node*>mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL)  //edge case
        {
            return NULL;
        }

        Node *first = new Node(node->val,{});
        mp[node] = first;  //this is bcz to mark the visited node

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for(auto adj : curr->neighbors)  //neighbors is the adjacent nodes
            {
                if(!mp[adj])
                {
                    mp[adj] = new Node(adj->val,{});
                    q.push(adj);
                }
                mp[curr]->neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
        
    }
};
