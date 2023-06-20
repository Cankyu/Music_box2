#include "Music_library.hpp"

int main() {
    MusicLibrary library;
    library.loadFromJson("music_data.json");

    // Example usage
    library.searchByTitle("Call out my name");

    Song newSong;
    newSong.title = "New Song";
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
    updatedSong.year = 2018;
    updatedSong.genre = "RnB";
    library.updateSong("Call out my name", updatedSong);

    library.saveToJson("updated_music_data.json");

    return 0;
}
