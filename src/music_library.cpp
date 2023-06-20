#include "json.hpp"
using json = nlohmann::json;
#include "Music_library.hpp"
#include <fstream>
#include <iostream>

MusicLibrary::MusicLibrary() {}

void MusicLibrary::loadFromJson(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open JSON file." << std::endl;
        return;
    }

    json jsonData;
    file >> jsonData;

    for (const auto& songData : jsonData["Music_library"]) {
        Song song;
        song.title = songData["Title"];
        song.artist = songData["Artist"];
        song.album = songData["Album"];
        song.year = songData["Year"];
        song.genre = songData["Genre"];
        songs.push_back(song);
    }

    file.close();
}

void MusicLibrary::saveToJson(const std::string& filename) {
    json jsonData;

    for (const auto& song : songs) {
        json songData;
        songData["Title"] = song.title;
        songData["Artist"] = song.artist;
        songData["Album"] = song.album;
        songData["Year"] = song.year;
        songData["Genre"] = song.genre;
        jsonData["Music_library"].push_back(songData);
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open JSON file." << std::endl;
        return;
    }

    file << std::setw(4) << jsonData << std::endl;
    file.close();
}

void MusicLibrary::addSong(const Song& song) {
    songs.push_back(song);
}

void MusicLibrary::removeSong(const std::string& title) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->title == title) {
            songs.erase(it);
            break;
        }
    }
}

void MusicLibrary::searchByTitle(const std::string& title) {
    for (const auto& song : songs) {
        if (song.title == title) {
            // Do something with the found song
            // e.g., print its details
            std::cout << "Title: " << song.title << std::endl;
            std::cout << "Artist: " << song.artist << std::endl;
            std::cout << "Album: " << song.album << std::endl;
            std::cout << "Year: " << song.year << std::endl;
            std::cout << "Genre: " << song.genre << std::endl;
        }
    }
}

void MusicLibrary::searchByArtist(const std::string& artist) {
    for (const auto& song : songs) {
        if (song.artist == artist) {
            // Do something with the found song
        }
    }
}

void MusicLibrary::searchByAlbum(const std::string& album) {
    for (const auto& song : songs) {
        if (song.album == album) {
            // Do something with the found song
        }
    }
}

void MusicLibrary::searchByYear(int year) {
    for (const auto& song : songs) {
        if (song.year == year) {
            // Do something with the found song
        }
    }
}

void MusicLibrary::searchByGenre(const std::string& genre) {
    for (const auto& song : songs) {
        if (song.genre == genre) {
            // Do something with the found song
        }
    }
}

void MusicLibrary::updateSong(const std::string& title, const Song& updatedSong) {
    for (auto& song : songs) {
        if (song.title == title) {
            song = updatedSong;
            break;
        }
    }
}
