#pragma once
#include <string>
#include <Vector>
#include "Track.h"

class Album {
private:
	std::string artist;
	std::string title;
	std::vector<Track*> * tracks;
	Duration* duration;
public:
	Album(std::string artist, std::string title);
	~Album();

	void addTrack(std::string title, int seconds, int minutes, int hours);
	std::string getArtist();
	std::string getTitle();
	std::vector<Track*> * getTracks();
	int getNumberOfTracks();
	Duration* getDuration();
	Track* getLongestTrack();

	friend std::ostream& operator << (std::ostream& out, Album& obj);
};