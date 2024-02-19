#pragma once

#include <string>

#include "Utils.h"
#include "RAM.h"
#include "Operand.h"
#include "ProgramMemory.h"
#include "instruction/AbstractInstruction.h"

class RAM;
class ProgramMemory;

class HaltInstruction : public AbstractInstruction {
public:
    HaltInstruction ();
    virtual ~HaltInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class LoadInstruction : public AbstractInstruction {
public:
    LoadInstruction (Operand value);
    virtual ~LoadInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class StoreInstruction : public AbstractInstruction {
public:
    StoreInstruction (Operand value);
    virtual ~StoreInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class AddInstruction : public AbstractInstruction {
public:
    AddInstruction (Operand value);
    virtual ~AddInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class SubInstruction : public AbstractInstruction {
public:
    SubInstruction (Operand value);
    virtual ~SubInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class MulInstruction : public AbstractInstruction {
public:
    MulInstruction (Operand value);
    virtual ~MulInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class DivInstruction : public AbstractInstruction {
public:
    DivInstruction (Operand value);
    virtual ~DivInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class ReadInstruction : public AbstractInstruction {
public:
    ReadInstruction (Operand value);
    virtual ~ReadInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class WriteInstruction : public AbstractInstruction {
public:
    WriteInstruction (Operand value);
    virtual ~WriteInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class JumpInstruction : public AbstractInstruction {
public:
    JumpInstruction (Operand value);
    virtual ~JumpInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class JumpIfZeroInstruction : public AbstractInstruction {
public:
    JumpIfZeroInstruction (Operand value);
    virtual ~JumpIfZeroInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};

class JumpIfGreaterThanZeroInstruction : public AbstractInstruction {
public:
    JumpIfGreaterThanZeroInstruction (Operand value);
    virtual ~JumpIfGreaterThanZeroInstruction () = default;

    virtual bool isValid () const;
    virtual void execute (RAM& ram) const;
};
