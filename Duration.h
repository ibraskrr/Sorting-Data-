#pragma once
#include <ostream>

class Duration {
private:
	int seconds;
	int minutes;
	int hours;
public:
	Duration();
	Duration(int seconds, int minutes, int hours);

	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;

	Duration operator+(const Duration& b);
	bool operator>(const Duration& b);
	bool operator<(const Duration& b);
	bool operator==(const Duration& b);

	friend std::ostream& operator << (std::ostream& out, const Duration& obj);
};