#include <iostream>
#include <string>
using namespace std;

typedef struct Node{
    Node* data;
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


int main()
{
    Node* word_list = nullptr;

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
            //erase_data();
        }

        addWord(&word_list, x);



    }

    return 0;
}
