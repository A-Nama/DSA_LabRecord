#include "Q7.cpp"

int main() {
    int length;
    cout << "Enter the number of songs in your playlist: ";
    cin >> length;

    cin.ignore(); 

    Song* head = nullptr;
    Song* tail = nullptr; 

    for (int i = 0; i < length; i++) {
        string songname, artist, genre;
        int duration;
        cout << "Song Name: ";
        getline(cin, songname);
        cout << "Artist: ";
        getline(cin, artist);
        cout << "Duration (seconds): ";
        cin >> duration;
        cin.ignore(); 
        cout << "Genre: ";
        getline(cin, genre);
        
        if (!head) {
            head = new Song(songname, artist, duration, genre);
            tail = head;
        } else {
            tail->next = new Song(songname, artist, duration, genre);
            tail = tail->next;
        }
    }

    cout << "\nOriginal Playlist:" << endl;
    printPlaylist(head);

    mergeSort(&head, "Title"); 
    cout << "\nSorted Playlist by Title:" << endl;
    printPlaylist(head);

    mergeSort(&head, "Artist"); 
    cout << "\nSorted Playlist by Artist:" << endl;
    printPlaylist(head);

    mergeSort(&head, "Duration"); 
    cout << "\nSorted Playlist by Duration:" << endl;
    printPlaylist(head);

    mergeSort(&head, "Genre"); 
    cout << "\nSorted Playlist by Genre:" << endl;
    printPlaylist(head);

    while (head) {
        Song* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
