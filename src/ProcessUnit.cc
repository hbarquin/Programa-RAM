#include "ProcessUnit.h"
#include "RAM.h"

void ProcessUnit::addToR0 (RAM& ram, int value) const {
    int zeroValue = ram.getDataMemory().get(0);
    ram.getDataMemory().set(0, zeroValue + value);
}

void ProcessUnit::subToR0 (RAM& ram, int value) const {
    int zeroValue = ram.getDataMemory().get(0);
    ram.getDataMemory().set(0, zeroValue - value);
}

void ProcessUnit::divR0 (RAM& ram, int value) const {
    assert(value != 0);

    int zeroValue = ram.getDataMemory().get(0);
    ram.getDataMemory().set(0, zeroValue / value);
}

void ProcessUnit::mulWithR0 (RAM& ram, int value) const {
    int zeroValue = ram.getDataMemory().get(0);
    ram.getDataMemory().set(0, zeroValue * value);
}

void ProcessUnit::jumpToTag (RAM& ram, const std::string& tag) const {
    ram.getProgramMemory().setCurrentInstruction(tag);
}

void ProcessUnit::jumpIfZero (RAM& ram, int value, const std::string& tag) const {
    if (value == 0) {
        jumpToTag(ram, tag);
    }
}

void ProcessUnit::jumpIfGreaterThanZero (RAM& ram, int value, const std::string& tag) const {
    if (value > 0) {
        jumpToTag(ram, tag);
    }
}
