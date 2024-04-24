#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

struct node {
    node(int x) : value{ x }, left{ nullptr }, right{ nullptr } {};
    int value;
    node* left;
    node* right;
};

void inorderT(node* root) {
    if (!root) {
        return;
    }
    inorderT(root->left);
    std::cout << root->value << ' ';
    inorderT(root->right);
}

void inorderIterative(node* root) {
    if (!root) {
        return;
    }

    std::stack<node*> s; 
    while (true) {
        if (root) {
            n.push(root);
            root = root->left;
        }
        else {
            if (n.empty()) { 
                break;
            }
			root = n.top();
			n.pop();
			std::cout << root->data << ' ';
			root = root->right;
        }
    }

}

void preorderT(node* root) {
    if (!root) {
        return;
    }
    std::cout << root->value << ' ';
    preorderT(root->left);
    preorderT(root->right);
}

void preorderIterative(node* root) {
    if (!root) {
        return;
    }
    std::stack<node*> s;
    while (true) {
        if (root) {
            s.push(root);
            root = root->left;
            std::cout << .top()->value << ' ';
        }
        else {
            root = n.top()->right;
            n.pop();
            if (s.empty() && !root) { // just n.empty() ...
                break;
            }
        }
    }
}

void postorderT(node* root) {
    if (!root) {
        return;
    }
    postorderT(root->left);
    postorderT(root->right);
    std::cout << root->value << ' ';
}

void postorderIterative(node* root) {
    if (!root) {
        return;
    }
    std::stack<node*> s;
    node* prev = nullptr;
    while (root != nullptr || !s.empty()) {
        if (root) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            if (!root->right || root->right == prev) {
                std::cout << root->value << ' ';
                s.pop();
                prev = root;
                root = nullptr;
            }
            else {
                root = root->right;
            }
        }
    }
}

void levelorderT(node* root) {
    if (root) {
        std::queue<node*> q;
        q.push(root);
        while (!s.empty()) { 
            node* front = q.front();
            std::cout << front->value << ' ';
            n.pop();
            if (n.front()->left) {
                n.push(n.front()->left);
            }
            if (n.front()->right) {
                n.push(n.front()->right);
            }
        }
    }
}

int Height(node* root) { 
    if (!root) {
        return 0;
    }
    int left = maxHeight(root->left);
    int right = maxHeight(root->right);
    return std::max(left, right) + 1;
}

int maxDepth(node* root) { // ????
    if (!root) {
        return 0;
    }
    std::queue<node*> n;
    n.push(root);
    n.push(nullptr);
    int depth = 0;
    while (!n.empty()) {
        node* temp = n.front();
        n.pop();
        if (!temp) {
            ++depth;
        }
        if (temp != nullptr) {
            if (temp->left) {
                n.push(temp->left);
            }
            if (temp->right) {
                n.push(temp->right);
            }
        }
        else if (!n.empty()) {
            n.push(nullptr);
        }
    }

    return depth;
}

int countNodes(node* root) {
    if (!root) {
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
}

int main()
{
    node* root = new node(6);
    node* p1 = root;
    p1->left = new node(4);
    p1 = p1->left;
    p1->right = new node(5);
    p1->left = new node(2);
    p1 = p1->left;
    p1->left = new node(1);
    p1->right = new node(3);
    node* p2 = root;
    p2->right = new node(10);
    p2 = p2->right;
    p2->left = new node(8);
    p2 = p2->left;
    p2->left = new node(7);
    p2->right = new node(9);

    /*
                6
             /      \
          4            10
        /   \        /
      2      5      8
     / \           / \
    1   3        7    9
                            */
    std::cout << "inorderT ";
    inorderT(root);
    std::cout << std::endl;
    std::cout << "inorderIterative ";
    inorderIterative(root);
    std::cout << std::endl;
    std::cout << "preorderT ";
    preorderT(root);
    std::cout << std::endl;
    std::cout << "preorderIterative ";
    preorderIterative(root);
    std::cout << std::endl;
    std::cout << "postorderT ";
    postorderT(root);
    std::cout << std::endl;
    std::cout << "postorderIterative ";
    postorderIterative(root);
    std::cout << std::endl;
    std::cout << "levelorderT ";
    levelorderT(root);

    std::cout << std::endl;
    std::cout << "height " << maxHeight(root) << std::endl;
    std::cout << "depth " << maxDepth(root) << std::endl;
    std::cout << "count of nodes " << countNodes(root) << std::endl;

    return 0;
}
