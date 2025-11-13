// Model/Dates.h

#pragma once

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
};

inline bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.day == rhs.day) && 
           (lhs.month == rhs.month) && 
           (lhs.year == rhs.year);
}