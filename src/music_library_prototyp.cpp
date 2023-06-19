#include <iostream>
#include <cstring>

#define MAX_SONGS 100
#define MAX_STR_LEN 100

struct Song {
    char title[MAX_STR_LEN];
    char artist[MAX_STR_LEN];
    char album[MAX_STR_LEN];
    int year;
    char genre[MAX_STR_LEN];
};

struct MusicLibrary {
    Song songs[MAX_SONGS];
    int num_songs;
};

void init_library(MusicLibrary *library) {
    library->num_songs = 0;
}

void add_song(MusicLibrary *library, const char *title, const char *artist, const char *album, int year, const char *genre) {
    if (library->num_songs >= MAX_SONGS) {
        std::cout << "Error: Library is full" << std::endl;
        return;
    }
    Song *song = &library->songs[library->num_songs++];
    strncpy(song->title, title, MAX_STR_LEN);
    strncpy(song->artist, artist, MAX_STR_LEN);
    strncpy(song->album, album, MAX_STR_LEN);
    song->year = year;
    strncpy(song->genre, genre, MAX_STR_LEN);
}

void delete_song(MusicLibrary *library, const char *title) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            for (int j = i; j < library->num_songs - 1; j++) {
                library->songs[j] = library->songs[j + 1];
            }
            library->num_songs--;
            return;
        }
    }
}

void edit_song(MusicLibrary *library, const char *title, const char *new_title, const char *new_artist, const char *new_album,
               int new_year, const char *new_genre) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            Song *song = &library->songs[i];
            if (new_title) {
                strncpy(song->title, new_title, MAX_STR_LEN);
            }
            if (new_artist) {
                strncpy(song->artist, new_artist, MAX_STR_LEN);
            }
            if (new_album) {
                strncpy(song->album, new_album, MAX_STR_LEN);
            }
            if (new_year != -1) {
                song->year = new_year;
            }
            if (new_genre) {
                strncpy(song->genre, new_genre, MAX_STR_LEN);
            }
            return;
        }
    }
}

void search(MusicLibrary *library,
            const char *title,
            const char *artist,
            const char *album,
            int year,
            const char *genre,
            MusicLibrary *results) {
    init_library(results);
    for (int i = 0; i < library->num_songs; i++) {
        Song song = library->songs[i];
        if (title && strcmp(song.title, title) != 0) {
            continue;
        }
        if (artist && strcmp(song.artist, title) != 0) {
            continue;
        }
        if (album && strcmp(song.album, title) != 0) {
            continue;
        }
        if (year != -1 && song.year != year) {
            continue;
        }
        if (genre && strcmp(song.genre, title) != 0) {
            continue;
        }

        add_song(results, song.title, song.artist, song.album, song.year, song.genre);
    }
}

void print_library(MusicLibrary *library) {
    for (int i = 0; i < library->num_songs; i++) {
        std::cout << "Title: " << library->songs[i].title << std::endl;
        std::cout << "Artist: " << library->songs[i].artist << std::endl;
        std::cout << "Album: " << library->songs[i].album << std::endl;
        std::cout << "Year: " << library->songs[i].year << std::endl;
        std::cout << "Genre: " << library->songs[i].genre << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    MusicLibrary library;

    init_library(&library);

    add_song(&library, "Call out my name", "The Weekend", "My dear melancholy", 2018, "RnB");
    add_song(&library, "Kill Bill", "SZA", "SOS", 2022, "RnB");
    add_song(&library, "Streets", "Doja Cat", "Hot pink", 2019, "RnB");
    add_song(&library, "Heartbreak Anniversary", "Giveon", "When its all said and clone", 2021, "RnB");
    add_song(&library, "Boyshit", "Madison Beer", "Life Support", 2021, "Pop");
    add_song(&library, "Boyfriend", "Dove Cameron", "Single", 2022, "Pop");
    add_song(&library, "bury a friend", "Billie Eilish", "When we all fall asleep where do we go?", 2019, "Pop");
    add_song(&library, "Pink Venom", "Blackpink", "Born Pink", 2022, "Pop");
    add_song(&library, "In the end", "Linking Park", "Hybrid Theory", 2000, "Rock");
    add_song(&library, "The Beginning", "One ok Rock", "Jinsei kakete Boku Wa", 2013, "Rock");
    add_song(&library, "Shoot For Your Heart", "Scorpions", "Rock Believer", 2022, "Rock");
    add_song(&library, "Zitti e buoni", "Maneskin", "Teatro dira", 2021, "Rock");

    int choice;
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

        if (choice == 1) {
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
            add_song(&library, title, artist, album, year, genre);
        } else if (choice == 2) {
            std::cout << "Enter title: ";
            std::cin >> title;
            delete_song(&library, title);
        } else if (choice == 3) {
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

            edit_song(&library, title, new_title, new_artist, new_album, new_year, new_genre);
        } else if (choice == 4) {
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

            search(&library, title, artist, album, year, genre, &results);

            print_library(&results);

        } else if (choice == 5) {
            print_library(&library);
        } else if (choice == 6) {
            break;
        }
    }

    return 0;
}
