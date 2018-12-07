//
//  preorderNTree.cpp
//  
//
//  Created by Brad Duvall on 12/2/18.
//


#include <iostream>
#include <vector>

using namespace std;

class Node {

public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr)
        {
            vector<int> empty;
            return empty;
        }

        if(root != nullptr)
        {
            vector<int> notEmpty = {root->val};
        
            for(int i = 0; i < root->children.size(); i++)
            {
                vector<int> childVector = preorder(root->children[i]);

                for(int j = 0; j < childVector.size(); j++)
                {
                    notEmpty.push_back(childVector[j]);
                }
            }

            return notEmpty;
        }

    }
};

int main(int argc, char * const argv[])
{

    

    return 0;
};