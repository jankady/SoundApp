//
// Created by Jan Kaduch on 21.04.2026.
//

#include "../headers/Date.h"

int Date::totalDates = 0;

// Cheap input clamping via modulo — keeps day in 0..31 and month in 0..12.
// Not a real validator; just guards obviously bogus values.
Date::Date(int day, int month, int year) {
    this->day = day % 32;
    this->month = month % 13;
    this->year = year;
    Date::totalDates += 1;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

// Lexicographic compare on (year, month, day).
bool Date::isBefore(const Date& other) const {
    if (this->year > other.getYear()) {
        return false;
    }
    if (this->month > other.getMonth()) {
        return false;
    }
    if (this->day > other.getDay()) {
        return false;
    }

    return true;
}
