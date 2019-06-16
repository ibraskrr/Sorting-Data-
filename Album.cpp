#include "Album.h"

Album::Album(std::string artist, std::string title) {
	tracks = new std::vector<Track*>();
	duration = new Duration();
	this->artist = artist;
	this->title = title;
}

Album::~Album() {
	for (std::vector<Track*>::iterator it = tracks->begin(); it != tracks->end(); it++)
	{
		delete *it;
	}
	delete this->tracks;
}

void Album::addTrack(std::string title, int seconds, int minutes, int hours) {
	// add track then update total album duration
	Track* t = new Track(title, seconds, minutes, hours);
	tracks->push_back(t);
	*(this->duration) = *(this->duration) + *(t->getDuration());
}

std::string Album::getArtist() {
	return this->artist;
}

std::string Album::getTitle() {
	return this->title;
}

std::vector<Track*>* Album::getTracks() {
	return this->tracks;
}

int Album::getNumberOfTracks() {
	return this->tracks->size();
}

Duration* Album::getDuration() {
	return duration;
}

Track* Album::getLongestTrack() {
	Track* t = nullptr;
	for (std::vector<Track*>::iterator it = tracks->begin(); it != tracks->end(); it++) {
		if (t == nullptr || *((*it)->getDuration()) > *(t->getDuration())) {
			t = *it;
		}
	}
	return t;
}


std::ostream& operator << (std::ostream& out, Album& obj)
{
	out << obj.getArtist() << " - " << obj.getTitle() << std::endl;
	return out;
}
