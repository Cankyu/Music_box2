#include <iostream>
#include "Music_library.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Please provide the filename of the music library as an argument." << std::endl;
        return 1;
    }

    MusicLibrary library;
    library.loadFromJson(argv[1]);

    while (true) {
        std::cout << "Please select your choice:" << std::endl;
        std::cout << "1. Add a new song" << std::endl;
        std::cout << "2. Search for a song" << std::endl;
        std::cout << "3. Remove a song" << std::endl;
        std::cout << "4. Update a song" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string title, artist, album, genre;
            int year;

            std::cout << "Titel: ";
            std::cin.ignore();
            std::getline(std::cin, title);

            std::cout << "Artist: ";
            std::getline(std::cin, artist);

            std::cout << "Album: ";
            std::getline(std::cin, album);

            std::cout << "Genre: ";
            std::getline(std::cin, genre);

            std::cout << "Year: ";
            std::cin >> year;

            Song newSong;
            newSong.title = title;
            newSong.artist = artist;
            newSong.album = album;
            newSong.genre = genre;
            newSong.year = year;

            library.addSong(newSong);

            std::cout << "New song has been added to the library." << std::endl;
        }
        else if (choice == 2) {
            std::string searchTitle;
            std::cout << "Bitte geben Sie den Titel des Songs ein, nach dem Sie suchen möchten: ";
            std::cin.ignore();
            std::getline(std::cin, searchTitle);

            library.searchByTitle(searchTitle);
        }
        else if (choice == 3) {
            std::string removeTitle;
            std::cout << "Bitte geben Sie den Titel des Songs ein, den Sie entfernen möchten: ";
            std::cin.ignore();
            std::getline(std::cin, removeTitle);

            library.removeSong(removeTitle);

            std::cout << "Song wurde aus der Bibliothek entfernt." << std::endl;
        }
        else if (choice == 4) {
            std::string updateTitle;
            std::cout << "Bitte geben Sie den Titel des Songs ein, den Sie aktualisieren möchten: ";
            std::cin.ignore();
            std::getline(std::cin, updateTitle);

            std::string newTitle, newArtist, newAlbum, newGenre;
            int newYear;

            std::cout << "Neuer Titel: ";
            std::getline(std::cin, newTitle);

            std::cout << "Neuer Künstler: ";
            std::getline(std::cin, newArtist);

            std::cout << "Neues Album: ";
            std::getline(std::cin, newAlbum);

            std::cout << "Neues Genre: ";
            std::getline(std::cin, newGenre);

            std::cout << "Neues Jahr: ";
            std::cin >> newYear;

            Song updatedSong;
            updatedSong.title = newTitle;
            updatedSong.artist = newArtist;
            updatedSong.album = newAlbum;
            updatedSong.genre = newGenre;
            updatedSong.year = newYear;

            library.updateSong(updateTitle, updatedSong);

            std::cout << "Song wurde aktualisiert." << std::endl;
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Ungültige Auswahl. Bitte wählen Sie erneut." << std::endl;
        }
    }

    library.saveToJson("updated_music_data.json");

    return 0;
}
