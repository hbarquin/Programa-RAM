#include "RAM.h"

RAM::RAM (
    const std::string& programFilename,
    const std::string& inputFilename,
    const std::string& outputFilename
) : _programMemory(programFilename),
    _outputTape(outputFilename),
    _inputTape(inputFilename)
{
    _outputTapeFilename = outputFilename;
    _inputTapeFilename = inputFilename;
    _programFilename = programFilename;
}

void RAM::start () {
    _programMemory.reset();

    while (!_programMemory.end() && !_stop) {
        AbstractInstruction* instruction = _programMemory.read();
        _programMemory.next();
        if (instruction->isValid()) {
            std::cout << "[D] " << instruction->toString() << '\n';
            instruction->execute(*this);
            std::cout << "[D] Entrada: " << _inputTape << '\n';
            std::cout << "[D] Datos:\n\t" << _dataMemory << '\n';
            std::cout << "[D] Salida: " << _outputTape << '\n';
        } else {
            throw std::runtime_error(
                "ERROR: [" + std::to_string(_programMemory.getIndex()) + "] "
                + "La instrucción " + instruction->toString() + " no es válida."
            );
        }
    }
    _outputTape.save(_outputTapeFilename);
}

void RAM::stop () {
    _stop = true;
}

const ProcessUnit& RAM::getProcessUnit () const {
    return _processUnit;
}

ProcessUnit& RAM::getProcessUnit () {
    return _processUnit;
}

const DataMemory& RAM::getDataMemory () const {
    return _dataMemory;
}

DataMemory& RAM::getDataMemory () {
    return _dataMemory;
}

const ProgramMemory& RAM::getProgramMemory () const {
    return _programMemory;
}

ProgramMemory& RAM::getProgramMemory () {
    return _programMemory;
}

const Tape& RAM::getInputTape () const {
    return _inputTape;
}

Tape& RAM::getInputTape () {
    return _inputTape;
}

const Tape& RAM::getOutputTape () const {
    return _outputTape;
}

Tape& RAM::getOutputTape () {
    return _outputTape;
}
