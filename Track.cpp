#include "Track.h"

Track::Track(std::string title, int seconds, int minutes, int hours) {
	this->title = title;
	this->duration = new Duration(seconds, minutes, hours);
}

Track::~Track() {
	delete this->duration;
}

std::string Track::getTitle() {
	return this->title;
}

Duration * Track::getDuration() {
	return this->duration;
}

std::ostream& operator << (std::ostream& out, Track& obj)
{
	out << obj.getTitle() << " - " << *obj.getDuration() << std::endl;
	return out;
}