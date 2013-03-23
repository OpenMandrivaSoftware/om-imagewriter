#ifndef COMMON_H
#define COMMON_H

////////////////////////////////////////////////////////////////////////////////
// This file contains some commonly-used constants and function declarations


#include <QObject>
#include <QString>

#include <type_traits>

#include "platform.h"

// Default unit to be used when displaying file/device sizes (MB)
const quint64 DEFAULT_UNIT = 1048576;

// Application name used for titles in messageboxes
const QString ApplicationTitle = "ROSA Image Writer";

// Returns the number of blocks required to contain some number of bytes
// Input:
//  T      - any integer type
//  val    - number of bytes
//  factor - size of the block
// Returns:
//  the number of blocks of size <factor> required for <val> to fit in
template <typename T> T alignNumberDiv(T val, T factor)
{
    static_assert(std::is_integral<T>::value, "Only integer types are supported!");
    return ((val + factor - 1) / factor);
}

// Returns the total size of blocks required to contain some number of bytes
// Input:
//  T      - any integer type
//  val    - number of bytes
//  factor - size of the block
// Returns:
//  the total size of blocks of size <factor> required for <val> to fit in
template <typename T> T alignNumber(T val, T factor)
{
    static_assert(std::is_integral<T>::value, "Only integer types are supported!");
    return alignNumberDiv(val, factor) * factor;
}

#ifdef Q_OS_WIN32
// Converts the WinAPI and COM error code into text message
// Input:
//  prefixMessage - error description
//  errorCode     - error code (GetLastError() is used by default)
// Returns:
//  prefixMessage followed by a newline and the system error message for the errorCode
QString errorMessageFromCode(QString prefixMessage, DWORD errorCode = GetLastError());
#endif

// Gets the contents of the specified file
// Input:
//  fileName - path to the file to read
// Returns:
//  the file contents or empty string if an error occurred
QString readFileContents(const QString& fileName);

#endif // COMMON_H
