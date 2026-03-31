#include <iostream>
using namespace std;

struct Song{
    string title;
    string artist;
    int rating[3];
    Song* next;
    Song* prev;
};

Song* appendSong(Song** head, Song** tail, string a, string b, int ratings[3])
{
    Song* temporal = new Song();
    temporal->title = a;
    temporal->artist = b;
    temporal->next = temporal->prev = NULL;

    for(int i = 0; i < 3; i++)
    {
        temporal->rating[i] = ratings[i];
    }

    if(*head == NULL)
    {
        *head = *tail = temporal;
    }

    else{
        (*tail)->next = temporal;
        temporal->prev = *tail;
        *tail = temporal;
    }
    return *tail;
}

void display(Song* head, Song* current)
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Song* music = head;
    while(music != NULL)
    {
        if(current == music)
        {
            cout<< "[ ";
        }
        cout << music->title << " ";
        for(int i = 0; i < 3; i++)
        {
            cout << music->rating[i] << " ";
        }
        if(current == music)
        {
            cout <<" ]" << " ";
        }

        if(music->next == NULL)
        {
            cout << endl << endl;
            return;
        }

        cout << " <-> ";
        music = music->next;
    }
}

Song* removeSong(Song** head, Song** tail, Song* current) {
    if (current == nullptr) return nullptr;

    Song* prevNode = current->prev;
    Song* nextNode = current->next;


    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    } else {
        *head = nextNode;
    }

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    } else {
        *tail = prevNode;
    }

    Song* newCurrent = (nextNode != nullptr) ? nextNode : prevNode;

    delete current;

    return newCurrent;
}

void nextprev(int a, Song** current)
{
    if(*current == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    if(a == 1)
    {
        if((*current)->next == nullptr)
        {
            cout << "This is the last song." << endl;
            return;
        }
        else *current = (*current)->next;
    }

    else if(a == 0)
    {
        if((*current)->prev == nullptr)
        {
            cout << "This is the first song." << endl;
            return;
        }
        else *current = (*current)->prev;
    }
}

void removeMemory(Song* head)
{
    while (head != nullptr) {
        Song* silinecek = head;
        head = head->next;
        delete silinecek;
    }
}

int main()
{
    Song *head = NULL, *tail = NULL, *current = NULL;

    string artistSong;
    string titleSong;
    while(titleSong != "EXIT"){
        cout << "Name of the song: ";
        getline(cin >> ws, titleSong);
        cout << endl;

        if(titleSong == "EXIT" || titleSong == "exit")
        {
            removeMemory(head);
            return 0;
        }

        else if(titleSong == "remove")
        {
            current = removeSong(&head, &tail, current);
            continue;
        }

        else if(titleSong == "next")
        {
            nextprev(1, &current);
            continue;
        }

        else if(titleSong == "prev")
        {
            nextprev(0, &current);
            continue;
        }

        else if(titleSong == "display")
        {
            display(head, current);
            continue;
        }

        cout << endl << "Name of the artist: ";
        getline(cin >> ws, artistSong);
        cout << endl;

        int a;
        int ratings[3];
        for(int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". critic: ";
            cin >> a;
            ratings[i] = a;
            cout << endl;
        }
        tail = appendSong(&head, &tail, titleSong, artistSong, ratings);
        if(current == NULL)
        {
            current = head;
        }
    }
}
