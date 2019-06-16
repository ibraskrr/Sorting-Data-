#include "Duration.h"
Duration::Duration() {
	this->seconds = 0;
	this->minutes = 0;
	this->hours = 0;
}

Duration::Duration(int seconds, int minutes, int hours) {
	this->seconds = seconds;
	this->minutes = minutes;
	this->hours = hours;
}

int Duration::getSeconds() const {
	return this->seconds;
}
int Duration::getMinutes() const {
	return this->minutes;
}
int Duration::getHours() const {
	return this->hours;
}

Duration Duration::operator+(const Duration& b) {
	Duration duration();
	int s = this->seconds + b.seconds;
	int m = this->minutes + b.minutes;
	int h = this->hours + b.hours;

	// carry over
	if (s > 59) {
		s -= 60;
		m += 1;
	}
	if (m > 59) {
		m -= 60;
		h += 1;
	}
	return Duration(s, m, h);
}

bool Duration::operator>(const Duration& b) {
	if (this->hours > b.getHours()) {
		return true;
	}
	else if (this->hours == b.getHours()){
		if (this->minutes > b.getMinutes()) {
			return true;
		}
		else if (this->minutes == b.getMinutes()) {
			if (this->seconds > b.getSeconds()) {
				return true;
			}
		}
	}
	return false;
}

bool Duration::operator<(const Duration& b) {
	return !(*this > b);
}

bool Duration::operator==(const Duration& b) {
	return (this->hours == b.getHours() && this->minutes == b.getMinutes() && this->seconds == b.getSeconds());
}

std::ostream& operator << (std::ostream& out, const Duration& obj)
{
	out << obj.getHours() << ":" << obj.getMinutes() << ":" << obj.getSeconds();
	return out;
}