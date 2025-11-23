// Utils/CleanupStrings.h

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

/**
 * @brief Removes all characters from the 'text' string that are present in the 'black_list'.
 *
 * @param text The input string to be cleaned (modified in place).
 * @param black_list A list of characters to be removed from the text.
 * @return The cleaned string.
 */
std::string cleanString(std::string& text, const std::vector<char>& black_list) {
    // 1. Create a set for O(1) average time complexity lookup.
    // This is much faster than searching a vector repeatedly.
    const std::set<char> blacklist_set(black_list.begin(), black_list.end());

    // 2. Use the erase-remove idiom.
    // 'std::remove_if' moves all characters that satisfy the predicate (being in the blacklist)
    // to the end of the range and returns an iterator to the new logical end of the string.
    auto new_end = std::remove_if(text.begin(), text.end(), 
                                  [&](char c) {
                                      // Predicate: check if the character 'c' is in the blacklist_set
                                      return blacklist_set.count(c) > 0;
                                  });

    // 3. 'std::string::erase' removes the characters in the range 
    // from the new logical end ('new_end') to the physical end ('text.end()').
    text.erase(new_end, text.end());

    // 4. Return the cleaned string.
    if (text.empty()) {
        return "null";
    }
    return text;
}

