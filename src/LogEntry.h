
#pragma once
#include <string>

/*
 * LogEntry
 * --------
 * Represents a single parsed line from the log file.
 * Each LogEntry stores three pieces of information:
 *   - timestamp: the date/time extracted from the log line
 *   - level: the log severity (INFO, WARNING, ERROR, DEBUG, etc.)
 *   - message: the descriptive text of the log event
 *
 * This class is a simple, immutable data container.
 * It does not perform parsing or analysis — those responsibilities
 * belong to LogParser and LogAnalyzer.
 */
    class LogEntry {
    private:
        std::string timestamp;   // Full timestamp string from the log line
        std::string level;       // Log level (INFO, ERROR, etc.)
        std::string message;     // Message text after the colon

    public:
        /*
         * Constructor
         * -----------
         * Initializes a LogEntry with the given timestamp, level, and message.
         * All fields are stored exactly as provided.
         */
        LogEntry(const std::string& ts,
            const std::string& lvl,
            const std::string& msg);

        /*
         * Accessor methods
         * ----------------
         * Return the stored timestamp, log level, and message.
         * These methods do not modify the object.
         */
        std::string getTimestamp() const;
        std::string getLevel() const;
        std::string getMessage() const;
};