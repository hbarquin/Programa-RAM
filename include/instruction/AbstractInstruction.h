#pragma once

#include <sstream>

#include "Utils.h"
#include "Operand.h"

class RAM;

class AbstractInstruction {
protected:
    std::string _key;
    Operand _value;
    int _numberOfOperands;

public:
    AbstractInstruction (const std::string& key, Operand value, int numberOfOperands);
    virtual ~AbstractInstruction () = default;

    virtual std::string getKey () const;
    virtual Operand getValue () const;

    static AbstractInstruction* toInstruction (const std::string& instruction);

    virtual unsigned numberOfOperands () const;
    virtual bool isValid () const = 0;
    virtual void execute (RAM& ram) const = 0;

    std::string toString () const;
};
