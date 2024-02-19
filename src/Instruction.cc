#include "Instruction.h"

// HALT INSTRUCTION //////////////////////////////////

HaltInstruction::HaltInstruction ()
    : AbstractInstruction("HALT", Operand(), 0)
{}

bool HaltInstruction::isValid () const {
    return true;
}

void HaltInstruction::execute (RAM& ram) const {
    ram.stop();
}

// LOAD INSTRUCTION //////////////////////////////////

LoadInstruction::LoadInstruction (Operand value)
    : AbstractInstruction("LOAD", value, 1)
{}

bool LoadInstruction::isValid () const {
    return true;
}

void LoadInstruction::execute (RAM& ram) const {
    int data;
    switch (_value.type()) {
        case OperandType::CONSTANT:
            ram.getDataMemory().set(0, _value.value());
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(_value.value());
            ram.getDataMemory().set(0, data);
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(_value.value());
            data = ram.getDataMemory().get(data);
            ram.getDataMemory().set(0, data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
}

// STORE INSTRUCTION //////////////////////////////////

StoreInstruction::StoreInstruction (Operand value)
    : AbstractInstruction("STORE", value, 1)
{}

bool StoreInstruction::isValid () const {
    return _value.type() != OperandType::CONSTANT;
}

void StoreInstruction::execute (RAM& ram) const {
    int data;
    switch (_value.type()) {
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(0);
            ram.getDataMemory().set(_value.value(), data);
            break;
        case OperandType::INDIRECT: {
            data = ram.getDataMemory().get(0);
            int toStore = ram.getDataMemory().get(_value.value());
            ram.getDataMemory().set(toStore, data);
            break;
        }
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
}

// ADD INSTRUCTION //////////////////////////////////

AddInstruction::AddInstruction (Operand value)
    : AbstractInstruction("ADD", value, 1)
{}

bool AddInstruction::isValid () const {
    return true;
}

void AddInstruction::execute (RAM& ram) const {
    int data = 0;
    switch (_value.type()) {
        case OperandType::CONSTANT:
            data = _value.value();
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(_value.value());
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(_value.value());
            data = ram.getDataMemory().get(data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
    ram.getProcessUnit().addToR0(ram, data);
}

// SUB INSTRUCTION //////////////////////////////////

SubInstruction::SubInstruction (Operand value)
    : AbstractInstruction("SUB", value, 1)
{}

bool SubInstruction::isValid () const {
    return true;
}

void SubInstruction::execute (RAM& ram) const {
    int data = 0;
    switch (_value.type()) {
        case OperandType::CONSTANT:
            data = _value.value();
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(_value.value());
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(_value.value());
            data = ram.getDataMemory().get(data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
    ram.getProcessUnit().subToR0(ram, data);
}

// MUL INSTRUCTION //////////////////////////////////

MulInstruction::MulInstruction (Operand value)
    : AbstractInstruction("MUL", value, 1)
{}

bool MulInstruction::isValid () const {
    return true;
}

void MulInstruction::execute (RAM& ram) const {
    int data = 0;
    switch (_value.type()) {
        case OperandType::CONSTANT:
            data = _value.value();
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(_value.value());
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(_value.value());
            data = ram.getDataMemory().get(data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
    ram.getProcessUnit().mulWithR0(ram, data);
}

// DIV INSTRUCTION //////////////////////////////////

DivInstruction::DivInstruction (Operand value)
    : AbstractInstruction("DIV", value, 1)
{}

bool DivInstruction::isValid () const {
    return true;
}

void DivInstruction::execute (RAM& ram) const {
    int data = 0;
    switch (_value.type()) {
        case OperandType::CONSTANT:
            data = _value.value();
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(_value.value());
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(_value.value());
            data = ram.getDataMemory().get(data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
    ram.getProcessUnit().divR0(ram, data);
}

// READ INSTRUCTION //////////////////////////////////

ReadInstruction::ReadInstruction (Operand value)
    : AbstractInstruction("READ", value, 1)
{}

bool ReadInstruction::isValid () const {
    return (_value.type() == OperandType::DIRECT && _value.value() != 0)
        || _value.type() == OperandType::INDIRECT;
}

void ReadInstruction::execute (RAM& ram) const {
    switch (_value.type()) {
        case OperandType::DIRECT: {
            int data = ram.getInputTape().read();
            ram.getInputTape().next();
            ram.getDataMemory().set(_value.value(), data);
            break;
        }
        case OperandType::INDIRECT: {
            int value = ram.getInputTape().read();
            ram.getInputTape().next();
            int index = ram.getDataMemory().get(_value.value());
            ram.getDataMemory().set(index, value);
        }
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado.");
    }
}

// WRITE INSTRUCTION //////////////////////////////////

WriteInstruction::WriteInstruction (Operand value)
    : AbstractInstruction("WRITE", value, 1)
{}

bool WriteInstruction::isValid () const {
    return _value.type() == OperandType::CONSTANT
        || (_value.type() == OperandType::DIRECT && _value.value() != 0)
        || _value.type() == OperandType::INDIRECT;
}

void WriteInstruction::execute (RAM& ram) const {
    int data = _value.value();
    switch (_value.type()) {
        case OperandType::CONSTANT:
            break;
        case OperandType::DIRECT:
            data = ram.getDataMemory().get(data);
            break;
        case OperandType::INDIRECT:
            data = ram.getDataMemory().get(data);
            data = ram.getDataMemory().get(data);
            break;
        default:
            throw std::runtime_error(_key + ": No se reconoce, o no es válido, el tipo de operando indicado. (" + std::to_string(_value.type()) + ")");
    }
    ram.getOutputTape().write(data);
    ram.getOutputTape().next();
}

// JUMP INSTRUCTION //////////////////////////////////

JumpInstruction::JumpInstruction (Operand value)
    : AbstractInstruction("JUMP", value, 1)
{}

bool JumpInstruction::isValid () const {
    return _value.type() == OperandType::TAG;
}

void JumpInstruction::execute (RAM& ram) const {
    assert(_value.type() == OperandType::TAG);

    if (!ram.getProgramMemory().hasTag(_value.tag())) {
        throw std::runtime_error(_key + ": No se encuentra la etiqueta " + _value.tag() + ".");
    }

    ram.getProcessUnit().jumpToTag(ram, _value.tag());
}

// JZERO INSTRUCTION //////////////////////////////////

JumpIfZeroInstruction::JumpIfZeroInstruction (Operand value)
    : AbstractInstruction("JZERO", value, 1)
{}

bool JumpIfZeroInstruction::isValid () const {
    return _value.type() == OperandType::TAG;
}

void JumpIfZeroInstruction::execute (RAM& ram) const {
    assert(_value.type() == OperandType::TAG);

    if (!ram.getProgramMemory().hasTag(_value.tag())) {
        throw std::runtime_error(_key + ": No se encuentra la etiqueta " + _value.tag() + ".");
    }

    int zeroValue = ram.getDataMemory().get(0);
    ram.getProcessUnit().jumpIfZero(ram, zeroValue, _value.tag());
}

// JGTZ INSTRUCTION //////////////////////////////////

JumpIfGreaterThanZeroInstruction::JumpIfGreaterThanZeroInstruction (Operand value)
    : AbstractInstruction("JGTZ", value, 1)
{}

bool JumpIfGreaterThanZeroInstruction::isValid () const {
    return _value.type() == OperandType::TAG;
}

void JumpIfGreaterThanZeroInstruction::execute (RAM& ram) const {
    assert(_value.type() == OperandType::TAG);

    if (!ram.getProgramMemory().hasTag(_value.tag())) {
        throw std::runtime_error(_key + ": No se encuentra la etiqueta " + _value.tag() + ".");
    }

    int zeroValue = ram.getDataMemory().get(0);
    ram.getProcessUnit().jumpIfGreaterThanZero(ram, zeroValue, _value.tag());
}
