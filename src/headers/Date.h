//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_DATE_H
#define SOUNDAPP_DATE_H


class Date {
private:
    static int totalDates; // Static member to keep track of total Date instances created
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool isBefore(const Date& other) const;


};


#endif //SOUNDAPP_DATE_H