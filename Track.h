#pragma once
#include <string>
#include "Duration.h"

class Track {
private:
	std::string title;
	Duration * duration;
public:
	Track(std::string title, int seconds, int minutes, int hours);
	~Track();

	std::string getTitle();
	Duration* getDuration();

	friend std::ostream& operator << (std::ostream& out, Track& obj);
};