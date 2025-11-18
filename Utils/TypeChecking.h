// Utils/TypeChecking.h

#include <iostream>
#include <string>


int classifyAndGetValue(const std::string& s) {
    if (s.empty()) {
        return -1; 
    }

    // --- 1. Check for Positive Integer ---
    // Must contain only digits (0-9).
    bool is_positive_integer = true;
    for (char c : s) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            is_positive_integer = false;
            break;
        }
    }

    if (is_positive_integer) {
        // Since we confirmed it's only digits, we can safely convert it.
        // If the number is too large, std::stoi will throw an exception, 
        // which you might want to catch in a production environment.
        try {
            return std::stoi(s);
        } catch (const std::out_of_range& e) {
            // Handle case where the number is too large for an int
            std::cerr << "Warning: Integer conversion failed (too large) for: " << s << std::endl;
            return -1; 
        }
    }

    return 0;

    // --- 2. Check for Name (allowing spaces and letters) ---
    // Must contain only alphabetic characters and spaces, and must contain at least one letter.
    bool is_name = true;
    bool has_alpha = false; 
    
    for (char c : s) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            has_alpha = true;
        } else if (c != ' ') {
            // If the character is neither a letter nor a space, it fails the Name test
            is_name = false;
            break;
        }
    }

    // A valid name must pass the character check AND must contain at least one letter.
    if (is_name && has_alpha) {
        return 0; // Return 0 for a valid name
    }

    // --- 3. Invalid
    return -1;
}