#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <fstream>
#include "Music_library.hpp"


TEST_CASE("Adding a new song to the music library", "[addSong]") {
    
    MusicLibrary library;
    Song newSong;
    newSong.title = "Test Song";
    newSong.artist = "Test Artist";
    newSong.album = "Test Album";
    newSong.genre = "Test Genre";
    newSong.year = 2023;

   
    library.addSong(newSong);

    
    REQUIRE(library.searchByTitle("Test Song") == true);
}

TEST_CASE("Load music_data from Json", "[loadFromJson]") {
    
    MusicLibrary library;
   library.loadFromJson("test/test_music_data.json");
   
  
    REQUIRE(library.searchByTitle("Test Song Chopper") == true);
   
}

TEST_CASE("Removing a song from the music library", "[removeSong]") {
    
    MusicLibrary library;
    Song song1;
    song1.title = "Test Song 1";
    Song song2;
    song2.title = "Test Song 2";
    library.addSong(song1);
    library.addSong(song2);

 
    library.removeSong("Test Song 1");

   
   
    REQUIRE(library.searchByTitle("Test Song 1") == false);
    REQUIRE(library.searchByTitle("Test Song 2") == true);
}

TEST_CASE("Updating a song in the music library", "[updateSong]") {
  
    MusicLibrary library;
    Song originalSong;
    originalSong.title = "Test Song";
    originalSong.artist = "Test Artist";
    originalSong.album = "Test Album";
    originalSong.genre = "Test Genre";
    originalSong.year = 2023;
    library.addSong(originalSong);

 
    Song updatedSong;
    updatedSong.title = "Updated Song";
    updatedSong.artist = "Updated Artist";
    updatedSong.album = "Updated Album";
    updatedSong.genre = "Updated Genre";
    updatedSong.year = 2024;
    library.updateSong("Test Song", updatedSong);

 
    REQUIRE(library.searchByTitle("Test Song") == false);
    REQUIRE(library.searchByTitle("Updated Song") == true);
}

TEST_CASE("Saving music library to JSON file", "[saveToJson]") {
  
    MusicLibrary library;
    Song song1;
    song1.title = "Test Song 1";
    Song song2;
    song2.title = "Test Song 2";
    library.addSong(song1);
    library.addSong(song2);

   
    library.saveToJson("test_music_data2.json");

   MusicLibrary JsonLibrary;
   JsonLibrary.loadFromJson("test_music_data2.json");

    REQUIRE(library.searchByTitle("Test Song 1") == true);
    REQUIRE(library.searchByTitle("Test Song 2") == true);
    
}
