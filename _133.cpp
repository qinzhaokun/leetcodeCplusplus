/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int,UndirectedGraphNode*> m;
        return dfs(node,m);
    }
    
    UndirectedGraphNode * dfs(UndirectedGraphNode *node, map<int,UndirectedGraphNode*> &m){
        if(node == NULL) return NULL;
        int label = node->label;
        UndirectedGraphNode *newNode;
        if(m.find(label) != m.end()){
            newNode = m[label];
        }
        else{
            newNode = new UndirectedGraphNode(label);
            m[label] = newNode;
        }
        
        vector<UndirectedGraphNode *> neighbors = node->neighbors;
        for(int i = 0;i < neighbors.size();i++){
            int l = neighbors[i]->label;
            if(m.find(l) != m.end()){
                newNode->neighbors.push_back(m[l]);
            }
            else{
                newNode->neighbors.push_back(dfs(neighbors[i],m));
            }
        }
        return newNode;
    }
};
