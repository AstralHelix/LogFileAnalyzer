#include "LogParser.h"
#include <string>
#include <stdexcept>

// ------------------------------------------------------------
// parseLine
// Parses a full log line and extracts its components
// (timestamp, level, and message) using helper functions.
//
// Expected input format:
//     [timestamp] LEVEL: message text
//
// Example:
//     "[2024-01-01 10:00] INFO: System started"
//
// Behavior:
// - Validates that the line contains a timestamp, level, and message
// - Calls extractTimestamp(), extractLevel(), and extractMessage()
// - Throws std::runtime_error if the line is malformed
//
// Returns:
// - A formatted string or structured representation of the parsed data,
//   depending on how the function is implemented in LogParser.cpp.
//
// Notes:
// - This is the main entry point for parsing a single log line.
// - Helper functions handle the detailed extraction logic.
// ------------------------------------------------------------
std::string LogParser::parseLine(const std::string& line)
{
	// Extract the timestamp, level, and message from the line
	std::string timestamp = extractTimestamp(line);
	std::string level = extractLevel(line);
	std::string message = extractMessage(line);

	// Format the output as "timestamp | level | message"
	return timestamp + " | " + level + " | " + message;
}


// ------------------------------------------------------------
// extractTimestamp
// Extracts the substring between '[' and ']'
// Example: "[2024-01-01 10:00] INFO: Message"
// Returns: "2024-01-01 10:00"
// ------------------------------------------------------------
std::string LogParser::extractTimestamp(const std::string& line)
{
    // Find the opening bracket
    int indexStart = line.find('[');
    if (indexStart == std::string::npos)
    {
        throw std::runtime_error("Missing opening bracket for timestamp");
    }

    // Find the closing bracket
    int indexEnd = line.find(']');
    if (indexEnd == std::string::npos)
    {
        throw std::runtime_error("Missing closing bracket for timestamp");
    }

    // Ensure the closing bracket comes after the opening bracket
    if (indexEnd < indexStart)
    {
        throw std::runtime_error("Closing bracket appears before opening bracket");
    }

    // Extract everything between the brackets
    return line.substr(indexStart + 1, indexEnd - indexStart - 1);
}

// ------------------------------------------------------------
// extractLevel
// Extracts the log level between "] " and ":"
// Example: "[timestamp] INFO: Message"
// Returns: "INFO"
// ------------------------------------------------------------
std::string LogParser::extractLevel(const std::string& line)
{
    // Find the closing bracket of the timestamp
    int indexStart = line.find(']');
    if (indexStart == std::string::npos)
    {
        throw std::runtime_error("Missing closing bracket for timestamp");
    }

    // Find the colon after the log level
    int indexEnd = line.find(':');
    if (indexEnd == std::string::npos)
    {
        throw std::runtime_error("Missing colon after level");
    }

    // Extract the level (skip "] ")
    return line.substr(indexStart + 2, indexEnd - (indexStart + 2));
}

// ------------------------------------------------------------
// extractMessage
// Extracts everything after the first colon and trims whitespace
// Example: "[timestamp] INFO: Something happened"
// Returns: "Something happened"
// ------------------------------------------------------------
std::string LogParser::extractMessage(const std::string& line)
{
    // Find the colon that separates level from message
    int index = line.find(':');
    if (index == std::string::npos)
    {
        throw std::runtime_error("Missing colon after level");
    }

    // Extract everything after the colon and trim it
    return trim(line.substr(index + 1));
}

// ------------------------------------------------------------
// trim
// Removes leading and trailing spaces/tabs
// Example: "   hello world   " → "hello world"
// ------------------------------------------------------------
std::string LogParser::trim(const std::string& s)
{
    // Find first non-whitespace character
    size_t start = s.find_first_not_of(" \t");

    // Find last non-whitespace character
    size_t end = s.find_last_not_of(" \t");

    // If the string is all whitespace, return empty string
    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }

    // Return the trimmed substring
    return s.substr(start, end - start + 1);
}