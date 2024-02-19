#pragma once

#include <string>

enum OperandType { CONSTANT, DIRECT, INDIRECT, TAG, NONE };

class Operand {
private:
    OperandType _type;
    int _value;
    std::string _tag;

public:
    Operand ();
    Operand (OperandType type, int value);
    Operand (const std::string& tag);

    static Operand from (const std::string& instruction);

    OperandType type () const;
    int value () const;
    std::string tag () const;

    std::string toString () const;
};