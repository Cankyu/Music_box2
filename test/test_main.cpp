#include catch.hpp
#include <catch2/catch.hpp>
#include <sstream>
#include <fstream>
#include "Music_library.hpp"

TEST_CASE("Adding a new song to the music library", "[addSong]") {
    // Setup
    MusicLibrary library;
    Song newSong;
    newSong.title = "Test Song";
    newSong.artist = "Test Artist";
    newSong.album = "Test Album";
    newSong.genre = "Test Genre";
    newSong.year = 2023;

    // Action
    library.addSong(newSong);

    // Assertion
    REQUIRE(library.getNumberOfSongs() == 1);
    REQUIRE(library.searchByTitle("Test Song") == true);
}

TEST_CASE("Searching for a song in the music library", "[searchByTitle]") {
    // Setup
    MusicLibrary library;
    Song song1;
    song1.title = "Test Song 1";
    Song song2;
    song2.title = "Test Song 2";
    library.addSong(song1);
    library.addSong(song2);

    // Action and Assertion
    REQUIRE(library.searchByTitle("Test Song 1") == true);
    REQUIRE(library.searchByTitle("Nonexistent Song") == false);
}

TEST_CASE("Removing a song from the music library", "[removeSong]") {
    // Setup
    MusicLibrary library;
    Song song1;
    song1.title = "Test Song 1";
    Song song2;
    song2.title = "Test Song 2";
    library.addSong(song1);
    library.addSong(song2);

    // Action
    library.removeSong("Test Song 1");

    // Assertion
    REQUIRE(library.getNumberOfSongs() == 1);
    REQUIRE(library.searchByTitle("Test Song 1") == false);
}

TEST_CASE("Updating a song in the music library", "[updateSong]") {
    // Setup
    MusicLibrary library;
    Song originalSong;
    originalSong.title = "Test Song";
    originalSong.artist = "Test Artist";
    originalSong.album = "Test Album";
    originalSong.genre = "Test Genre";
    originalSong.year = 2023;
    library.addSong(originalSong);

    // Action
    Song updatedSong;
    updatedSong.title = "Updated Song";
    updatedSong.artist = "Updated Artist";
    updatedSong.album = "Updated Album";
    updatedSong.genre = "Updated Genre";
    updatedSong.year = 2024;
    library.updateSong("Test Song", updatedSong);

    // Assertion
    REQUIRE(library.searchByTitle("Test Song") == false);
    REQUIRE(library.searchByTitle("Updated Song") == true);
}

TEST_CASE("Saving music library to JSON file", "[saveToJson]") {
    // Setup
    MusicLibrary library;
    Song song1;
    song1.title = "Test Song 1";
    Song song2;
    song2.title = "Test Song 2";
    library.addSong(song1);
    library.addSong(song2);

    // Action
    library.saveToJson("test_music_data.json");

    // Assertion
    std::ifstream file("test_music_data.json");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string jsonContent = buffer.str();
    file.close();
    REQUIRE(!jsonContent.empty());
}
