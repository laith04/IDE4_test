#ifndef NODE_H
#define NODE_H

template <typename DataType>
class Node {
private:
    DataType data;
    Node<DataType>* right;
    Node<DataType>* left;
    Node<DataType>* prev;

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

};


#endif // NODE_H

