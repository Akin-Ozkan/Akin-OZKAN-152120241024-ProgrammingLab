#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
    string data;
    Node* next;
}Node;

void addWord(Node** head_ref, string word){
    Node* word_add = new Node();

    word_add->data = word;
    word_add->next = (*head_ref);
    (*head_ref) = word_add;

    return;
}

void displayChain(Node* n){
    while(n != nullptr)
    {
        cout << n->data << " -> ";
        n = n->next;
    }
    return;
}

void eraseData(Node** head_ref) {
    if (*head_ref == nullptr){
        cout << "Liste boş!\n";
        return;

    }


    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    delete temp;
}



int main()
{
    Node* head = nullptr;

    string x = "START";
    while(x != "EXIT"){
        cout << "Bir kelime giriniz: ";
        cin >> x;

        if(x == "EXIT")
        {
            break;
        }

        if(x == "UNDO")
        {
            eraseData(&head);
            displayChain(head);
            cout << endl;
            continue;
        }

        addWord(&head, x);
        displayChain(head);
        cout << endl;
    }

    return 0;
}
