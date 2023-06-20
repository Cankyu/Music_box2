#include "Music_library.hpp"

int main(int argc, char* argv[]) {
    MusicLibrary library;
    library.loadFromJson(argv[1]);

    // Example usage
    library.searchByTitle("Call out my name");

    Song newSong;
    newSong.title = "Hallo";
    newSong.artist = "New Artist";
    newSong.album = "New Album";
    newSong.year = 2023;
    newSong.genre = "New Genre";
    library.addSong(newSong);

    library.removeSong("Kill Bill");

    Song updatedSong;
    updatedSong.title = "Call out my name";
    updatedSong.artist = "The Weeknd";
    updatedSong.album = "My Dear Melancholy";
    updatedSong.year = 2000;
    updatedSong.genre = "RnB";
    library.updateSong("Call out my name", updatedSong);

    library.saveToJson("updated_music_data.json");

    return 0;
}
