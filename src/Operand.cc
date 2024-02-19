#include "Operand.h"

Operand::Operand () {
    _type = OperandType::NONE;
}

Operand::Operand (OperandType type, int value) {
    _type = type;
    _value = value;
}

Operand::Operand (const std::string& tag) {
    _type = OperandType::TAG;
    _tag = tag;
}

Operand Operand::from (const std::string& instruction) {
    assert(!instruction.empty());

    char firstLetter = instruction[0];

    try {
        if (firstLetter == '=') {
            int value = std::stoi(instruction.substr(1));
            return Operand(OperandType::CONSTANT, value);
        } else if (firstLetter == '*') {
            int value = std::stoi(instruction.substr(1));
            return Operand(OperandType::INDIRECT, value);
        } else if (std::isdigit(firstLetter)) {
            int value = std::stoi(instruction);
            return Operand(OperandType::DIRECT, value);
        } else {
            return Operand(instruction);
        }
    } catch (std::invalid_argument e) {
        throw std::runtime_error("Operand: No se pudo convertir " + instruction + " a un operando válido.");
    }
}

OperandType Operand::type () const {
    return _type;
}

int Operand::value () const {
    assert(_type != OperandType::NONE && _type != OperandType::TAG);
    return _value;
}

std::string Operand::tag () const {
    assert(_type == OperandType::TAG);
    return _tag;
}

std::string Operand::toString () const {
    std::string str = "";

    switch (_type) {
        case OperandType::CONSTANT:
            str += "=";
            break;
        case OperandType::INDIRECT:
            str += "*";
            break;
    }

    switch (_type) {
        case OperandType::CONSTANT:
        case OperandType::INDIRECT:
        case OperandType::DIRECT:
            str += std::to_string(_value);
            break;
        case OperandType::TAG:
            str += _tag;
            break;
    }

    return str;
}
