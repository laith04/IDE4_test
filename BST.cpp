#ifndef BST_CPP
#define BST_CPP

#include "BST.h"
using namespace std;

template <typename DataType>
void BST<DataType>::InsertNode(DataType input) {
    if (Search(input)){
        cout << input << " is already in BST.\n";
        return;
        //this means that it is already in the BST. no need to add it again
    }

    Node* node = new Node(input);
    Node* current = nullptr;

    if((myRoot == 0)){
        myRoot = node;
    } else {
        current = myRoot;
        while (current){
            if (current->GetData() > input){
                if (current->GetLeft() == nullptr){
                    current->SetLeft(node);
                    node->SetPrev(current);
                    current = 0;
                } else {
                    current = current->GetLeft();
                    }
            } else {
                if (current->GetRight() == nullptr){
                    current->SetRight(node);
                    node->SetPrev(current);
                    current = 0;
                } else {
                    current = current->GetRight();
                }
            }
        }
    }

}

template <typename DataType>
void BST<DataType>::TraversePreorderHelper(Node* yes) {
    Node* check = yes;

    cout << check->GetData() << " \t\t\t ";
    if (check->GetLeft() && check->GetRight()){
        cout << check->GetLeft()->GetData() << " \t\t\t ";
        cout << check->GetRight()->GetData() << "";
    } else if (check->GetLeft()){
        cout << check->GetLeft()->GetData() << " \t\t\t NIL";
    } else if (check->GetRight()){
        cout << "NIL \t\t\t " << check->GetRight()->GetData();
    } else {
        cout << "NIL \t\t\t NIL";
    }
    cout << endl;

    if (check->GetLeft()){
        TraversePreorderHelper(check->GetLeft());
    }
    if (check->GetRight()){
        TraversePreorderHelper(check->GetRight());
    }

    return;
}

template <typename DataType>
bool BST<DataType>::Search(DataType itemChecking){
    Node* current = myRoot;

    while (current){
        if (current->GetData() == itemChecking){
            searched = current; //basically where the searched node was found..
            //cout << "\n\n " << searched->GetPrev() << "\n\n";
            return true;  //returns if found.. no need to keep going
        } else if (current->GetData() > itemChecking){
            current = current->GetLeft();
        } else
            current = current->GetRight();
    }
    //if reached down here, that means it did not find it.
    return false;
}

template <typename DataType>
void BST<DataType>::LeafCountHelper(Node* yes){
    Node* check = yes;

    if (!check->GetLeft() && !check->GetRight()){
        leafCount++;
    }

    if (myRoot->GetData()){
        if (check->GetLeft()){
            LeafCountHelper(check->GetLeft());
        }
        if (check->GetRight()){
            LeafCountHelper(check->GetRight());
        }
    }
    return;
}

template <typename DataType>
void BST<DataType>::GetSibling(DataType itemChecking){
    Node* parent = nullptr;

    if((myRoot->GetData()) == itemChecking){
        cout << itemChecking << " does not have a sibling.\n";
        return;
    }

    if (myRoot){
        if (Search(itemChecking)){
            parent = searched->GetPrev(); //parent of the sibling. has a parent unless root
            if((parent->GetLeft()) && parent->GetLeft()->GetData() != itemChecking){
                cout << "The sibling of " << itemChecking << "is " << parent->GetLeft()->GetData() << "\n";
                return;
                //ran if function because i dont want the itemchecking to be called back..
                // and to make sure left node actually exists.
            } else if (parent->GetRight()){
                cout << "The sibling of " << itemChecking << " is " << parent->GetRight()->GetData() << "\n";
                    return;
                }
        } else {
            cout << "Item " << itemChecking << " is not found in the BST.\n";
            return;
        }
    }  else {
            cout << "No tree found. Please insert items first (Input 1). \n";
            return;
        }
    //if reached down here that means it didn't find the sibling. doesn't exist
    cout << itemChecking << " does not have a sibling.\n";
}

template <typename DataType>
int BST<DataType>::Delete(DataType itemDeleting){
    Node* parent = nullptr;
    Node* current = nullptr;
    Node* successor = nullptr;
    DataType succData = 0;

    if (Search(itemDeleting)){
        current = searched;
        parent = searched->GetPrev();
    } else
        return 0; //returns if item is not found

    if (current->GetLeft() && current->GetRight()){// means has 2 children
        successor = current->GetRight();
        while (successor->GetLeft())
            successor = successor->GetLeft();
        succData = successor->GetData();
        Delete(successor->GetData());
        current->SetData(succData);
    } else if (current->GetLeft() || current->GetRight()){ //if it only has one child
        if(parent == nullptr) { // means it is root node
            if (myRoot->GetLeft()){
                myRoot = current->GetLeft();
                myRoot->SetPrev(nullptr);
            } else if (myRoot->GetRight()){
                myRoot = current->GetRight();
                myRoot->SetPrev(nullptr);       //no previous
            } else {
                myRoot = nullptr;
                myRoot->SetPrev(nullptr);
            }
        } else if (current->GetLeft()) { //left child only
            if (parent->GetLeft() == current){ //means its left child of parent
                parent->SetLeft(current->GetLeft());
                current->SetPrev(parent);
            } else {
                parent->SetRight(current->GetLeft());
                current->SetPrev(parent);
            }
        } else {                                    //right child only
            if (parent->GetLeft() == current){ //means its left child of parent
                parent->SetLeft(current->GetRight());
                current->SetPrev(parent);
            } else {
                parent->SetRight(current->GetRight());
                current->SetPrev(parent);
            }
        }
    } else { //means leaf node
        if (parent == nullptr) {//means its root
            cout << "Last Item in BST, BST now empty.\n";
            delete current; // deletes the node so no memory leak..
        } else if (parent->GetLeft() == current){
            parent->SetLeft(nullptr);
            delete current; // deletes the node so no memory leak..
        }
        else {
            parent->SetRight(nullptr);
            delete current; // deletes the node so no memory leak..
        }
    }
    return 1; //means found
}
#endif // BST_CPP
