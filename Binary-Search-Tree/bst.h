//
// Created by genius on 18-8-16.
//

#ifndef ALGORITHMS_BST_H
#define ALGORITHMS_BST_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key =key;
            this->value = value;
            this->left = this->right=NULL;
        }

        Node(Node* node){
            this->key = node-key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;

        }
    };

    Node *root; //根节点
    int count;  //节点个数

    Node* insert(Node *node, Key key, Value value);   //在二叉树中插入一个节点
    bool contain(Node* node, Key key);                // 判断某个节点是否在二叉树中
    Value* search(Node* node, Key key);               //查找某个节点，并返回相应的value
    void preOrder(Node* node);                        //前序遍历递归
    void inOrder(Node* node);                         //中序遍历递归
    void postOrder(Node* node);                       //后序遍历递归
    void destroy(Node* node);                         //后续递归释放二叉树
    void preOrderbystack(Node* node);                 //先序遍历 （stack）
    void inOrderbystack(Node* node);                  //中序遍历（stack）
    void postOrderbystack(Node* node);                //后序遍历（stack）
    Node* minimum(Node* node);                        //得到最小值
    Node* maximum(Node* node);                        //得到最大值
    Node* removeMin(Node* node);                      //删除最小值
    Node* removeMax(Node* node);                      //删除最大值
    Node* remove(Node* node, Key key);                //删除key节点

public:
    BST();

    ~BST();

    int size()const{ return count;}
    bool isEmpty(){return count == 0;}
    void insert(Key key, Value value);
    bool contain(Key key){return contain(root,key);}
    Value* search(Key key){return search(root, key);}
    void preOrder(){preOrder(root);}
    void inOreder(){inOrder(root);}
    void postOrder(){postOrder(root);}
    void levelOrder(Node* node);
    Key minimum();
    Key maximum();
    void removeMin();
    void removeMax();
    void remove(Key key){if(root) root = remove(root,key)};

};
template <typename Key, typename Value>
inline BST<Key,Value>::BST() :root(NULL),count(0){};

template <typename Key ,typename Value>
inline BST<Key, Value>::~BST(){destroy(root);};

template <typename Key,typename Value>
inline void BST<Key,Value>::insert(Key key, Value value){
    root = insert(root, key, value);
};
template <typename Key,typename Value>
inline typename BST<Key,Value>::Node* BST<Key,Value>::insert(Node *node, Key key, Value value) {
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    if(node ==NULL) {
        count++;
        return new Node(key,value);
    }
    if(key == node->key)
        node->value = value;
    else if(key < node->key)
        node->left = insert(node->left,key,value);
    else
        node->right = insert(node->right, key, value);
    return node;
}

template <typename Key, typename Value>
inline bool BST<Key, Value>::contain(Node* node ,Key key){
    if(node == NULL)
        return false;
    if(key == node->key)
        return true;
    else if(key < node->key)
        return contain(node->left,key);
    else return contain(node->right, key);
};

template <typename Key, typename Value>
inline Value* BST<Key, Value>::search(Node* node,Key key) {
    if (node == NULL)
        return NULL;
    if(key == node-> key)
        return &(node->value);
    else if(key< node->key)
        return search(node->left, key);
    else return search(node->right, key);
};

template <typename Key, typename Value>
inline void BST<Key,Value>::preOrder(BST<Key, Value>::Node *node) {
    if (node!=NULL)
    {
        cout << node->key << endl;
        inOrder(node->left);
        inOrder(node->right);
    }

}

template <typename Key, typename Value>
inline void BST<Key, Value>::inOrder(BST<Key, Value>::Node *node) {
    if (node!=NULL){
        inOrder(node->left);
        cout<< node->key << endl;
        inOrder(node->left);
    }
}

template <typename Key, typename Value>
inline void BST<Key,Value>::postOrder(BST<Key, Value>::Node *node) {
    if(node!= NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key<< endl;
    }
}
template <typename Key ,typename Value>
inline void BST<Key,Value>::destroy(BST<Key, Value>::Node *node) {
    if(node!=NULL){
        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
    }
}
template <typename Key, typename Value>
inline void BST<Key, Value>::preOrderbystack(BST<Key, Value>::Node *node) {
    if (node==NULL)
        return;
    stack<Node*> m_stack;
    m_stack.push(node);
    while(!m_stack.empty())
    {
        Node* cur = m_stack.top();
        cout << cur->key <<endl;
        m_stack.pop();
        if (cur->right)
            m_stack.push(cur->right);
        if(cur->left)
            m_stack.push(cur->left);
    }

}

template <typename Key, typename Value>
inline void BST<Key, Value>::inOrderbystack(BST<Key, Value>::Node *node) {
    if(node == NULL)
        return;
    Node *cur = node;
    stack<Node*>m_stack;
    while(cur!=NULL || !m_stack.empty())
    {
        while( cur!=NULL)
        {
            m_stack.push(cur);
            cur = cur->left;
        }
        if(!m_stack.empty())
        {
            cur = m_stack.top();    //左孩子为空的时间取出，栈顶元素，同事讲右孩子入站
            m_stack.pop();
            cout << cur->key << "";
            cur = cur->right;

        }
    }
}

template <typename Key, typename  Value>
inline void BST<Key, Value>::postOrderbystack(BST<Key, Value>::Node *node) {
    if(node == NULL)
        return;
    Node *pre = NULL,*cur = node;
    stack<Node*>m_stack;

    while (cur!=NULL || !m_stack.empty()) {
        while (cur != NULL) {
            m_stack.push(cur);
            cur = cur->left;
        }
        cur = m_stack.top();
        if (cur->right == NULL || cur->right == pre){
            cout << cur->key << " ";
            pre = cur;
            m_stack.pop();
            cur = NULL;
        }
        else cur = cur->right;

    }
}

template <typename Key, typename Value>
inline void BST<Key,Value>::levelOrder(BST<Key, Value>::Node *node)  {
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node * node = q.front();
        q.pop();
        cout << node->key <<endl;
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

template <typename Key, typename Value>
inline Key BST<Key, Value>::minimum() {
    assert(count!=0);
    Node* minNode = minimum(root);
    return minNode->key;
}

template <typename Key, typename Value>
inline Key BST<Key, Value>::maximum() {
    assert(count!=0);
    Node* maxNode = maximum(root);
    return maxNode->key;
}

template <typename Key,typename Value>
inline typename BST<Key,Value>::Node* BST<Key, Value>::minimum(BST<Key, Value>::Node *node) {
    if(node->left == NULL)
        return node;
    return minimum(node->left);
}


template <typename Key,typename Value>
inline typename BST<Key,Value>::Node* BST<Key, Value>::maximum(BST<Key, Value>::Node *node) {
    if(node->right == NULL)
        return node;
    return maximum(node->right);
}

template <typename Key, typename Value>
inline void BST<Key, Value>::removeMin(){
    if(root)
        root = removeMin(root);

};

template <typename Key, typename Value>
inline void BST<Key, Value>::removeMax(){
    if(root)
        root = removeMax(root);
};

template <typename Key, typename Value>
inline typename BST<Key,Value>::Node* BST<Key,Value>::removeMin(BST<Key, Value>::Node *node) {
    if(node->left == NULL) {
        Node *rightnode = node->right;
        delete node;
        count --;
        return rightnode;
    }
    node->left = removeMin(node->left);
    return node;

}

template <typename Key, typename Value>
inline typename BST<Key,Value>::Node* BST<Key,Value>::removeMax(BST<Key, Value>::Node *node) {
    if(node->right ==NULL)
    {
        Node* leftNode = node->left;
        delete node;
        count--;
        return leftNode;
    }
    node->right = removeMax(node->right);
    return node;

}
template <typename Key, typename Value>
inline typename BST<Key, Value>::Node *  BST<Key,Value>::remove(BST<Key, Value>::Node *node, Key key) {
    if(node ==NULL)
        return NULL;
    if(key < node->key){
        node->left = remove(node->left, key);
        return node;
    }
    else if(key >node->key){
        node->right = remove(node->right,key);
        return node;
    }
    else{
        if(node->left == NULL){
            Node* rightnode = node->right;
            delete node;
            count --;
            return rightnode;
        }
        if(node->right ==NULL){
            Node* leftnode = node->left;
            delete node;
            count--;
            return leftnode;
        }


        Node* successor = new Node(minimum(node->right));
        count ++;
        successor->right = removeMin(node->right);
        successor->left = node->left;

        delete node;
        count--;

        return successor;

    }

}





#endif //ALGORITHMS_BST_H
