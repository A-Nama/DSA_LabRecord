#include <string>
#include<iostream>
using namespace std;

struct Song {
    string title;
    string artist;
    int duration;
    string genre;
    Song* next;

    Song(const string& t, const string& a, int d, const string& g);
};

Song* merge(Song* left, Song* right, const string& sortBy);
void splitList(Song* head, Song** left, Song** right);
void mergeSort(Song** headRef, const string& sortBy);
void printPlaylist(const Song* head);
