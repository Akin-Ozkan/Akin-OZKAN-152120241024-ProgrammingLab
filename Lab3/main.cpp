#include <iostream>
using namespace std;

struct Song{
    string title;
    string artist;
    int rating[3];
    Song* next;
    Song* prev;
    };


void addSong(Song** head, string songTitle, string nameArtist, int songRating[3])
{
    Song* temporal = new Song();

    temporal->title = songTitle;
    temporal->artist = nameArtist;

    for(int i = 0; i < 3; i++)
    {
        temporal->rating[i] = songRating[i];
    }


    temporal->next = nullptr;


    if(*head == nullptr)
    {
        *head = temporal;
        return;
    }


    while(temporal->next != nullptr)
    {
        temporal = temporal->next;
    }
}

void displaySongs(Song* head)
{
    Song* temporal = head;
    while(temporal != nullptr){
        cout << temporal->title << " " << temporal->artist << endl;
        for(int i = 0; i < 3; i++)
        {
            cout << temporal->rating[i] << endl;
        }
        temporal = temporal->next;
    }
    return;
}

void removeMemory(Song* head) {
    while (head != nullptr) {
        Song* silinecek = head;
        head = head->next;
        delete silinecek;
    }
}

int listen(Song* current, int status) //Next Prev fonksiyonu
{

}

void removeSong()
{

}


int main()
{
    Song* head = new Song();
    head = nullptr;


    string title = "START";
    string artist;

    while(title != "EXIT"){
        cout << "Name of the song: ";
        cin >> title;

        if(title == "EXIT" || title == "exit")
        {
            removeMemory(head);
            return 0;
        }

        if(title == "listen")
        {
            break;
        }

        else if(title == "display")
        {
            displaySongs(head);
            continue;
        }

        cout << endl << "Name of the artist: ";
        cin >> artist;

        int a;
        int rating[3];
        for(int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". critic: ";
            cin >> a;
            rating[i] = a;
            cout << endl;
        }

        addSong(&head,title,artist,rating);
    }

    Song* current = new Song();

    int status = 0;
    while(status != 4)
    {
        cout << "1)Back, 2)Forward, 3)Delete, 4)Exit";
        cin >> status;

        switch()
        {
            case 1:
                listen(current, status);
            case 2:
                listen(current, status);
            case 3:
                removeSong(current);
            case 4:
                removeMemory(head);
                return 0;
        }
    }


}
