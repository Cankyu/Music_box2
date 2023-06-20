#include "Music_library.hpp"
#include <iostream>

#define MAX_SONGS 100
#define MAX_STR_LEN 100

int main(int argc, char* argv[]) {
    MusicLibrary library;
    library.loadFromJson(argv[1]);

    char choice;
    char title[MAX_STR_LEN];
    char artist[MAX_STR_LEN];
    char album[MAX_STR_LEN];
    int year;
    char genre[MAX_STR_LEN];

    while (1) {
        std::cout <<"***Welcome to Music library Manager***"<< std::endl;


        std::cout << "If you want to Add a song: Enter 1" << std::endl;

        std::cout << "If you want to Delete a song: Enter 2" << std::endl;

        std::cout << "If you want to Edit a song: Enter 3" << std::endl;

        std::cout << "If you want to Search a song: Enter 4" << std::endl;

        std::cout << "If you want to  Print the music library: Enter 5" << std::endl;

        std::cout << "If you want to Exit the programm: Enter 6" << std::endl;

        std::cin >> choice;

        if (choice == '1') {
            std::cout << "Enter title: ";
            std::cin >> title;
            std::cout << "Enter artist: ";
            std::cin >> artist;
            std::cout << "Enter album: ";
            std::cin >> album;
            std::cout << "Enter year: ";
            std::cin >> year;
            std::cout << "Enter genre: ";
            std::cin >> genre;
            library.addSong({title, artist, album, year, genre});
        } else if (choice == '2') {
            std::cout << "Enter title: ";
            std::cin >> title;
            library.removeSong(title);
        } else if (choice == '3') {
            char new_title[MAX_STR_LEN];
            char new_artist[MAX_STR_LEN];
            char new_album[MAX_STR_LEN];
            int new_year;
            char new_genre[MAX_STR_LEN];

            std::cout << "Enter title: ";
            std::cin >> title;

            std::cout << "Enter new title (or 'none'): ";
            std::cin >> new_title;
            if (strcmp(new_title, "none") == 0) {
                strcpy(new_title, "");
            }

            std::cout << "Enter new artist (or 'none'): ";
            std::cin >> new_artist;
            if (strcmp(new_artist, "none") == 0) {
                strcpy(new_artist, "");
            }

            std::cout << "Enter new album (or 'none'): ";
            std::cin >> new_album;
            if (strcmp(new_album, "none") == 0) {
                strcpy(new_album, "");
            }

            std::cout << "Enter new year (or -1): ";
            std::cin >> new_year;

            std::cout << "Enter new genre (or 'none'): ";
            std::cin >> new_genre;
            if (strcmp(new_genre, "none") == 0) {
                strcpy(new_genre, "");
            }

          library.updateSong(title,{new_title, new_artist, new_album, new_year, new_genre});
        } else if (choice == '4') {
            MusicLibrary results;

            std::cout << "Enter title (or 'none'): ";
            std::cin >> title;
            if (strcmp(title, "none") == 0) {
                strcpy(title, "");
            }

            std::cout << "Enter artist (or 'none'): ";
            std::cin >> artist;
            if (strcmp(artist, "none") == 0) {
                strcpy(artist, "");
            }

            std::cout << "Enter album (or 'none'): ";
            std::cin >> album;
            if (strcmp(album, "none") == 0) {
                strcpy(album, "");
            }

            std::cout << "Enter year (or -1): ";
            std::cin >> year;

            std::cout << "Enter genre (or 'none'): ";
            std::cin >> genre;
            if (strcmp(genre, "none") == 0) {
                strcpy(genre, "");
            }

          library.searchByTitle(title);     //

            //print_library(&results);

        } else if (choice == '5') {
           library.saveToJson(argv[1]);
        } else if (choice == '6') {
            break;
        }
    }

    return 0;
}

   
