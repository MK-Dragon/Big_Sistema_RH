// Model/Note.h

#pragma once
#include <string>
#include <vector>


struct Note {
    std::string text;
    std::string date;
};

inline bool operator==(const Note& lhs, const Note& rhs) {
    return (lhs.text == rhs.text) && 
           (lhs.date == rhs.date);
}