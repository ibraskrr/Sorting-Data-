#include "Collection.h"

Collection::Collection() {
	collection = new std::map<std::string, std::vector<Album*>>;
}

Collection::~Collection() {
	for (std::map<std::string, std::vector<Album*>>::iterator it = collection->begin(); it != collection->end(); it++)
	{
		for(std::vector<Album*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
			delete *it2;
	}
	delete collection;
}

std::map<std::string, std::vector<Album*>>* Collection::getCollection() {
	return collection;
}

void Collection::addAlbum(std::string artist, std::string title) {
	// add empty album
	Album* album = new Album(artist, title);
	(*collection)[artist].push_back(album);
}

void Collection::addTrack(std::string artist, std::string albumTitle, std::string title, int seconds, int minutes, int hours) {
	// add track to existing album
	std::map<std::string, std::vector<Album*>>::iterator it = collection->find(artist);
	if (it != collection->end()) {
		for (std::vector<Album*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if ((*it2)->getTitle() == albumTitle) {
				(*it2)->addTrack(title, seconds, minutes, hours);
				return;
			}
		}
		
	}
}

Album* Collection::getAlbum(std::string artist, std::string title) {
	std::map<std::string, std::vector<Album*>>::iterator it = collection->find(artist);
	if (it != collection->end()) {
		for (std::vector<Album*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			if ((*it2)->getTitle() == title) {
				return *it2;
			}
		}
	}
	return nullptr;
}

Duration Collection::getDuration(std::string artist) {
	// sum durations of all albums of the artist
	Duration d;
	std::map<std::string, std::vector<Album*>>::iterator it = collection->find(artist);
	if (it != collection->end()) {
		for (std::vector<Album*>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			d = d + *((*it2)->getDuration());
		}
	}
	return d;
}

Album* Collection::getLargestAlbum() {
	Album* largestAlbum = nullptr;
	for (std::map<std::string, std::vector<Album*>>::iterator it = collection->begin(); it != collection->end(); it++) {
		std::vector<Album*>* albums = &it->second;
		for (std::vector<Album*>::iterator it2 = albums->begin(); it2 != albums->end(); it2++) {
			if (largestAlbum == nullptr || (*it2)->getNumberOfTracks() > largestAlbum->getNumberOfTracks()) {
				largestAlbum = *it2;
			}
		}
	}
	return largestAlbum;
}

Track* Collection::getLongestTrack() {
	Track* t = nullptr, *max = nullptr;
	for (std::map<std::string, std::vector<Album*>>::iterator it = collection->begin(); it != collection->end(); it++) {
		std::vector<Album*>* albums = &it->second;
		for (std::vector<Album*>::iterator it2 = albums->begin(); it2 != albums->end(); it2++) {
			t = (*it2)->getLongestTrack();
			if (max == nullptr || *(t->getDuration()) > *(max->getDuration())) {
				max = t;
			}
		}
	}
	return max;
}

std::ostream& operator << (std::ostream& out, const Collection& obj)
{
	// since map iterator search the map in alphabetical order by default
	// we only need to sort the album vector of each artist
	for (std::map<std::string, std::vector<Album*>>::iterator it = obj.collection->begin(); it != obj.collection->end(); it++) {
		std::vector<Album*> * albums = &it->second;
		// sort arist albums using bubble sort
		for (int i = 0, n = albums->size(); i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if ((*albums)[j]->getTitle() > (*albums)[j + 1]->getTitle()) {
					Album* temp = (*albums)[j];
					(*albums)[j] = (*albums)[j + 1];
					(*albums)[j + 1] = temp;
				}
			}
		}
		for (std::vector<Album*>::iterator it2 = albums->begin(); it2 != albums->end(); it2++) {
			out << it->first << " - " << (*it2)->getTitle() << std::endl;
		}

	}
	return out;
}