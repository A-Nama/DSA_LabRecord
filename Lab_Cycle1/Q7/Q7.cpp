#include "Q7.h"

Song::Song(const string& t, const string& a, int d, const string& g) {
    title = t;
    artist = a;
    duration = d;
    genre = g;
    next = nullptr;
}

Song* merge(Song* left, Song* right, const string& sortBy) {
    if (!left) return right;
    if (!right) return left;

    Song* result = nullptr;

    if (sortBy == "title" || sortBy == "artist" || sortBy == "genre") {
        if (sortBy == "title" ? left->title <= right->title : sortBy == "artist" ? left->artist <= right->artist : left->genre <= right->genre) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    } 
    else { 
        if (left->duration <= right->duration) {
            result = left;
            result->next = merge(left->next, right, sortBy);
        } else {
            result = right;
            result->next = merge(left, right->next, sortBy);
        }
    }

    return result;
}

void splitList(Song* head, Song** left, Song** right) {
    Song* fast = head->next;
    Song* slow = head;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

void mergeSort(Song** headRef, const string& sortBy) {
    Song* head = *headRef;
    if (!head || !head->next) {
        return;
    }

    Song* left;
    Song* right;
    splitList(head, &left, &right);

    mergeSort(&left, sortBy);
    mergeSort(&right, sortBy);

    *headRef = merge(left, right, sortBy);
}

void printPlaylist(const Song* head) {
    while (head) {
        cout << "Title: " << head->title << "\t Artist: " << head->artist 
             << "\t Duration: " << head->duration << " seconds \t Genre: " 
             << head->genre << endl;
        head = head->next;
    }
}
