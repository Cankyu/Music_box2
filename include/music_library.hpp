#ifndef MUSIC_LIBRARY_HPP
#define MUSIC_LIBRARY_HPP

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct Song {
    std::string title;
    std::string artist;
    std::string album;
    int year;
    std::string genre;
};

class MusicLibrary {
private:
    std::vector<Song> songs;
    
public:
    MusicLibrary();
    void loadFromJson(const std::string& filename);
    void saveToJson(const std::string& filename);
    void addSong(const Song& song);
    void removeSong(const std::string& title);
    void searchByTitle(const std::string& title);
    void searchByArtist(const std::string& artist);
    void searchByAlbum(const std::string& album);
    void searchByYear(int year);
    void searchByGenre(const std::string& genre);
    void updateSong(const std::string& title, const Song& updatedSong);
};

#endif  // MUSIC_LIBRARY_HPP
