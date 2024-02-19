#pragma once

#include <string>

class RAM;

class ProcessUnit {
public:
    ProcessUnit () = default;

    void addToR0 (RAM& ram, int value) const;
    void subToR0 (RAM& ram, int value) const;
    void divR0 (RAM& ram, int value) const;
    void mulWithR0 (RAM& ram, int value) const;

    void jumpToTag (RAM& ram, const std::string& tag) const;
    void jumpIfZero (RAM& ram, int value, const std::string& tag) const;
    void jumpIfGreaterThanZero (RAM& ram, int value, const std::string& tag) const;
};
