#include <iostream>
#include <string>
using namespace std;

const int MAX_SONGS = 5;

void displayPlaylist(string playlist[], int count) {
    cout << "\n--- Current Playlist ---\n";
    if (count == 0) {
        cout << "Your playlist is empty.\n";
    } else {
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << playlist[i] << "\n";
        }
    }
    cout << "------------------------\n";
}

int main() {
    string playlist[MAX_SONGS];
    int songCount = 0;
    int choice;

    do {
        cout << "\nMusic Playlist Manager\n";
        cout << "1. Add Song\n";
        cout << "2. View Playlist\n";
        cout << "3. Play Next Song (Remove First)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        switch (choice) {
            case 1:
                if (songCount < MAX_SONGS) {
                    cout << "Enter song title: ";
                    getline(cin, playlist[songCount]);
                    songCount++;
                    cout << "Song added successfully!\n";
                } else {
                    cout << "Playlist is full! Max limit is " << MAX_SONGS << ".\n";
                }
                break;
            case 2:
                displayPlaylist(playlist, songCount);
                break;
            case 3:
                if (songCount > 0) {
                    cout << "Now playing: " << playlist[0] << "\n";
                    // Shift songs up
                    for (int i = 0; i < songCount - 1; i++) {
                        playlist[i] = playlist[i + 1];
                    }
                    songCount--;
                } else {
                    cout << "No songs in the playlist to play.\n";
                }
                break;
            case 4:
                cout << "Exiting application. Enjoy your music!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
