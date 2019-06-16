#include <iostream>
#include <fstream>
#include <string>
#include "Collection.h"
using namespace std;

int main() {
	ifstream infile("albums.txt");

	Collection myCollection;
	string line;
	string albumTitle = "", artist = "";

	// 1. populate myCollection from the provided file
	while (std::getline(infile, line))
	{
		// Album title
		if (!isdigit(line[0])) {
			size_t found = line.find(':');
			if (found != string::npos) {
				albumTitle = line.substr(found + 2, line.length() - found - 2);
				artist = line.substr(0, found - 1);
				myCollection.addAlbum(artist, albumTitle);
			}
		}
		else {
			string title;
			int s, m, h;
			size_t found = line.find('-');
			h = stoi(line.substr(0,1));
			m = stoi(line.substr(2, 2));
			s = stoi(line.substr(5, 2));
			title = line.substr(found + 2, line.length() - found - 2);
			myCollection.addTrack(artist, albumTitle, title, s, m, h);
		}
	}

	cout << "2. The entire collection sorted in alphabetical order: " << endl;
	cout << myCollection << endl;

	cout << "3. The total playtime of all Pink Floyd albums: " << endl;
	cout << myCollection.getDuration("Pink Floyd") << endl << endl;

	cout << "4. The album with the largest number of tracks: " << endl;
	cout << *myCollection.getLargestAlbum() << endl;

	cout << "5. The longest track of the collection: " << endl;
	cout << *myCollection.getLongestTrack() << endl;
	return 0;
}