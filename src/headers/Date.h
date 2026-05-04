//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_DATE_H
#define SOUNDAPP_DATE_H


/**
 * Simple value-like calendar date (day/month/year). Used by composition inside
 * Subscription and Invoice. Provides a chronological comparison helper.
 */
class Date {
private:
    static int totalDates;     // running count of live Date instances
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Returns true if this date is chronologically before `other`.
    bool isBefore(const Date& other) const;


};


#endif //SOUNDAPP_DATE_H
