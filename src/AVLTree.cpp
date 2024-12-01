#include "../includes/AVLTree.h"

TreeNode* AVLTree::get_root()
{
    return root;
}

void AVLTree::insert(string key) {
    root = insertNode(root, key);
}

bool AVLTree::search(string key)  const{
    return searchNode(root, key);
}

void AVLTree::remove(string key) {
    root = removeNode(root, key);
}

void AVLTree::print() const{
    printNode(root, 0);
}

int AVLTree::getHeight(TreeNode* node) const{
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

TreeNode* AVLTree::minValueNode(TreeNode* node) const{
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int AVLTree::getBalance(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* AVLTree::insertNode(TreeNode* node, string key) {
    if (node == nullptr) {
        node = new TreeNode();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
    } else if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node;
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);
    if (balance > 1) {
        if (key < node->left->key) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (key > node->right->key) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

bool AVLTree::searchNode(TreeNode* node, string key) const{
    if (node == nullptr) {
        return false;
    }
    if (key < node->key) {
        return searchNode(node->left, key);
    } else if (key > node->key) {
        return searchNode(node->right, key);
    } else {
        return true;
    }
}

TreeNode* AVLTree::removeNode(TreeNode* node, string key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->key) {
        node->left = removeNode(node->left, key);
    } else if (key > node->key) {
        node->right = removeNode(node->right, key);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = removeNode(node->right, temp->key);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);
    if (balance > 1) {
        if (getBalance(node->left) >= 0) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if (balance < -1) {
        if (getBalance(node->right) <= 0) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::printNode(TreeNode* node, int level) const{
    if (node == nullptr) {
        return;
    }

    printNode(node->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "\t";
    }

    cout << "|" << endl;

    for (int i = 0; i < level; i++) {
        cout << "\t";
    }

    cout << "--" << node->key << " (h=" << node->height << ")" << endl;

    printNode(node->left, level + 1);
}

TreeNode* AVLTree::rotateRight(TreeNode* node) {
    TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

    return temp;
}

TreeNode* AVLTree::rotateLeft(TreeNode* node) {
    TreeNode* rtTemp = node->right;
    TreeNode* temp = rtTemp->left;

    rtTemp->left = node;
    node->right = temp;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rtTemp->height = max(getHeight(rtTemp->left), getHeight(rtTemp->right)) + 1;

    return rtTemp;
}

string AVLTree::to_string_tree() const{
    if (root == nullptr) {
        return "";
    }

    string result = root->to_string_node();
    return result;
}

string TreeNode::to_string_node() {
    string result = key + " ";
    result += (left != nullptr ? left->to_string_node() : "");
    result += (right != nullptr ? right->to_string_node() : "");
    return result;
}
