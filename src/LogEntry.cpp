#include "LogEntry.h"
/*
 * LogEntry Constructor
 * --------------------
 * Initializes a LogEntry object with the given timestamp, log level,
 * and message. The initializer list constructs each member variable
 * directly, which is more efficient than assigning inside the body.
 */

LogEntry::LogEntry(const std::string& ts,
    const std::string& lvl,
    const std::string& msg)
    : timestamp(ts), level(lvl), message(msg) {
}

/*
 * getTimestamp
 * ------------
 * Returns the timestamp string stored in this LogEntry.
 * This method does not modify the object.
 */
std::string LogEntry::getTimestamp() const {
    return timestamp;
}
/*
 * getLevel
 * --------
 * Returns the log level (INFO, WARNING, ERROR, DEBUG, etc.)
 * associated with this entry.
 */
std::string LogEntry::getLevel() const {
    return level;
}
/*
 * getMessage
 * ----------
 * Returns the message text from the log entry.
 * This is the descriptive part of the log line.
 */
std::string LogEntry::getMessage() const {
    return message;
}
