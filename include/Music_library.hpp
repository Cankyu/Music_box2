
#ifndef MUSIC_LIBRARY_HPP
#define MUSIC_LIBRARY_HPP

#include <string>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

struct Song {
    std::string title;
    std::string artist;
    std::string album;
    int year = 0;
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
    bool searchByTitle(const std::string& title);
    bool searchByArtist(const std::string& artist);
    bool searchByAlbum(const std::string& album);
    bool searchByYear(int year);
    bool searchByGenre(const std::string& genre);
    void updateSong(const std::string& title, const Song& updatedSong);
};

#endif  
