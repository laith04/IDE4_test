#ifndef BST_H
#define BST_H

//#include "Node.h"
#include <iostream>

using namespace std;

template <typename DataType>
class BST {
private:

// start node class
class Node {
private:
    DataType data;
    Node* right;
    Node* left;
    Node* prev;

public:
    //constructors
    Node() {
        data = 0;
        right = nullptr;
        left = nullptr;
        prev = nullptr;
    }

    Node(int initialData) {
        data = initialData;
        right = nullptr;
        left = nullptr;
        prev = nullptr;
    }

    //mutator functions
    void SetRight(Node* Next){
        right = Next;
    }

    void SetLeft(Node* Previous){
        left = Previous;
    }

    void SetData(int Data){
        data = Data;
    }

    void SetPrev(Node* Previous){
        prev = Previous;
    }

    // accessor functions
    Node* GetRight(){
        return right;
    }

    Node* GetLeft(){
        return left;
    }

    Node* GetPrev(){
        return prev;
    }

    DataType GetData(){
        return data;
    }

    //destructor
    ~Node(){
        delete right;
        delete left;
    }

}; //end node class

     Node* myRoot = 0;
     Node* searched = 0;
    int leafCount = 0;

public:
    void InsertNode(DataType input);

    void TraversePreorderHelper(Node* yes);

    void TraversePreorder() {
        cout << "Node Info\t Left Child Info\t Right Child Info\n";
        TraversePreorderHelper(myRoot);
    }

    bool Search(DataType itemChecking);

    int LeafCount(){
        leafCount = 0; //resets it
        LeafCountHelper(myRoot);
        return leafCount;
    }

    void LeafCountHelper(Node* yes);

    void GetSibling(DataType itemChecking);

    int Delete(DataType itemDeleting);

    bool Empty(){
        return (myRoot == nullptr);
    }
};


#endif // BST_H
