#include <iostream>
#include "BST.h"

using namespace std;

//BST<int> intBST;

int main()
{
    int validInput;

    cout << "\t1. Insert node(s)\n\t2. Traverse Preorder\n\t3. Search BST\n\t4. Delete node\n\t5. Leaf Count\n\t6. Sibling of a node\n\t7. Quit\n" << endl;
    cout << "Enter Your Choice <1 - 7>: ";
    cin >> validInput;

    while (!(validInput > 0 && validInput < 8)){
        cout << "Invalid Input, Please input a valid number <1 - 7>: ";
        cin >> validInput;
    }

    BST<int> intBST;
    int itemInput, numOfItems, i, badInput = 0;

    while (validInput != 7) {
        switch (validInput) {
        case 1: //input
            cout << "How many items are you inputting into the BST? ";
            cin >> numOfItems;
            while (i != numOfItems){
                i++;
                cout << "Enter item #" << i << ": ";
                cin >> itemInput;
                intBST.InsertNode(itemInput);
            }
            i = 0;
            break;
        case 2: // traversepreorder // not done yet.. works.. just fix how data is outputted
            if (intBST.Empty()){
                cout << "BST is empty.\n"; //empty
                break;
            }
            intBST.TraversePreorder();
            cout << "\n";
            break;
        case 3: //search function //done with this
            if (intBST.Empty()){
                cout << "BST is empty.\n"; //empty
                break;
            }
            cout << "Please enter the item you want to search for: ";
            cin >> itemInput;
            if (intBST.Search(itemInput)){
                cout << itemInput << " is found in the BST.\n";
            } else
                cout << itemInput << " is not found in the BST.\n";
            break;
        case 4: // delete function.. //done
            if (intBST.Empty()){
                cout << "BST is empty.\n"; //empty
                break;
            }
            cout << "Please enter the item you want to delete: ";
            cin >> itemInput;
            if (intBST.Delete(itemInput))
                cout << itemInput << " is deleted.\n";
            else
                cout << itemInput << " not found in the BST.\n";
            break;
        case 5: //leaf count // done with this
            if (intBST.Empty()){
                cout << "BST is empty.\n"; //empty
                break;
            }
            cout << "There are " << intBST.LeafCount() << " item of leaves in the BST.\n";
            break;
        case 6: //siblings //done with this
            if (intBST.Empty()){
                cout << "BST is empty.\n"; //empty
                break;
            }
            cout << "Please enter the item you want to find the sibling for: ";
            cin >> itemInput;
            intBST.GetSibling(itemInput);
            break;
        default: // done with this
            cout << "Invalid Input, Please input a valid number <1 - 7>: ";
            badInput = 1; // to pass "enter another valid input"
            break;
        }
        if (badInput == 0){
        cout << "Enter another valid input <1 - 7>: ";
        }
        cin >> validInput;
        badInput = 0;
    }


    cout << "End";
    return 0;
}
