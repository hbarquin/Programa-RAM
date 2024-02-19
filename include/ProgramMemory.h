#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

#include "instruction/AbstractInstruction.h"

class AbstractInstruction;

class ProgramMemory {
private:
    unsigned _current_instruction;
    std::vector<AbstractInstruction*> _instructions;
    std::map<std::string, int> _tags;

public:
    ProgramMemory (const std::string& filename);
    ~ProgramMemory ();
    
    AbstractInstruction* read () const;

    void setCurrentInstruction (const std::string& tag);
    unsigned getIndex () const;

    bool hasTag (const std::string& tag) const;
    unsigned getIndexFromTag (const std::string& tag) const;

    void reset();
    void next ();
    bool end() const;

    void load (const std::string& filename);
};
