#include "instruction/AbstractInstruction.h"
#include "Instruction.h"

AbstractInstruction::AbstractInstruction (const std::string& key, Operand value, int numberOfOperands) {
    _key = key;
    _value = value;
    _numberOfOperands = numberOfOperands;
}

std::string AbstractInstruction::getKey () const {
    return _key;
}

Operand AbstractInstruction::getValue () const {
    return _value;
}

AbstractInstruction* AbstractInstruction::toInstruction (const std::string& instruction) {
    std::stringstream sInstruction(instruction);
    
    std::string key = "";
    sInstruction >> key;
    
    if (utils::toUppercase(key) == "LOAD") {
        std::string operand;
        sInstruction >> operand;
        return new LoadInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "STORE") {
        std::string operand;
        sInstruction >> operand;
        return new StoreInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "ADD") {
        std::string operand;
        sInstruction >> operand;
        return new AddInstruction(Operand::from(operand));
    }  else if (utils::toUppercase(key) == "SUB") {
        std::string operand;
        sInstruction >> operand;
        return new SubInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "DIV") {
        std::string operand;
        sInstruction >> operand;
        return new DivInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "MUL") {
        std::string operand;
        sInstruction >> operand;
        return new MulInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "READ") {
        std::string operand;
        sInstruction >> operand;
        return new ReadInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "WRITE") {
        std::string operand;
        sInstruction >> operand;
        return new WriteInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "JUMP") {
        std::string operand;
        sInstruction >> operand;
        return new JumpInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "JZERO") {
        std::string operand;
        sInstruction >> operand;
        return new JumpIfZeroInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "JGTZ") {
        std::string operand;
        sInstruction >> operand;
        return new JumpIfGreaterThanZeroInstruction(Operand::from(operand));
    } else if (utils::toUppercase(key) == "HALT") {
        return new HaltInstruction();
    } else {
        throw std::runtime_error("ERROR: Instrucción " + utils::toUppercase(key) + " no reconocida.");
    }
}

unsigned AbstractInstruction::numberOfOperands () const {
    return _numberOfOperands;
}

std::string AbstractInstruction::toString () const {
    return _key + " " + _value.toString();
}
