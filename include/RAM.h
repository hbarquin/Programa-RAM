#pragma once

#include <string>

#include "DataMemory.h"
#include "Tape.h"
#include "ProcessUnit.h"
#include "Instruction.h"
#include "ProgramMemory.h"

class ProgramMemory;
class ProcessUnit;

class RAM {
private:
    ProgramMemory _programMemory;
    ProcessUnit _processUnit;
    DataMemory _dataMemory;
    Tape _outputTape;
    Tape _inputTape;

    std::string _outputTapeFilename;
    std::string _inputTapeFilename;
    std::string _programFilename;

    bool _stop;

public:
    RAM (
        const std::string& programFilename,
        const std::string& inputFilename,
        const std::string& outputFilename
    );

    void start ();
    void stop ();

    const ProcessUnit& getProcessUnit () const;
    ProcessUnit& getProcessUnit ();

    const DataMemory& getDataMemory () const;
    DataMemory& getDataMemory ();

    const ProgramMemory& getProgramMemory () const;
    ProgramMemory& getProgramMemory ();

    const Tape& getInputTape () const;
    Tape& getInputTape ();

    const Tape& getOutputTape () const;
    Tape& getOutputTape ();
};
