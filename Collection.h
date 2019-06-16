#pragma once
#include <string>
#include <Map>
#include <Vector>
#include "Album.h"

class Collection {
private:
	std::map<std::string, std::vector<Album*>> * collection;
public:
	Collection();
	~Collection();

	std::map<std::string, std::vector<Album*>>* getCollection();
	void addAlbum(std::string artist, std::string title);
	void addTrack(std::string artist, std::string albumTitle, std::string title, int seconds, int minutes, int hours);
	Album* getAlbum(std::string artist, std::string title);
	Duration getDuration(std::string artist);
	Album* getLargestAlbum();
	Track* getLongestTrack();
	friend std::ostream& operator << (std::ostream& out, const Collection& obj);
};