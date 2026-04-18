#pragma once
#include <string>
/*
 * LogParser
 * ---------
 * Stateless utility class responsible for converting raw log lines into
 * structured LogEntry objects. Provides static parsing functions that extract
 * the timestamp, log level, and message from a single line of text.
 *
 * Expected input format:
 *     [YYYY-MM-DD HH:MM:SS] LEVEL: message text
 *
 * This class throws an exception if the line is malformed or missing required
 * components. It does not store state, maintain collections of entries, or
 * perform any analysis — its sole responsibility is parsing.
 *
 * Used by higher-level components (e.g., LogAnalyzer) to transform raw log
 * data into structured objects for further processing.
 */

class LogParser
{
public:
/*
 * parseLine
 * ---------
 * Parses a single raw log line and returns a fully constructed LogEntry object.
 *
 * Expected format:
 *     [YYYY-MM-DD HH:MM:SS] LEVEL: message text
 *
 * The method extracts the timestamp, log level, and message from the input
 * string. If any required component is missing, malformed, or incorrectly
 * formatted, the function throws a std::runtime_error to signal that the line
 * cannot be parsed.
 *
 * This function is static and stateless; it performs no I/O and does not
 * modify or depend on any class-level data.
 */
	static std::string parseLine(const std::string& line);

private:
    /*
       * Helper methods
       * ----------------
	   * Used to validate and extract individual components from a log line.
	   * These methods are private and static, as they are only intended for internal
       */
    static std::string extractTimestamp(const std::string& line);
    static std::string extractLevel(const std::string& line);
    static std::string extractMessage(const std::string& line);
    static std::string trim(const std::string& s);
};
