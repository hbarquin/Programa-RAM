#include "DataMemory.h"

int DataMemory::get (unsigned i) const {
    if (_registers.find(i) == _registers.end()) {
        return 0;
    }
    return _registers.at(i);
}

void DataMemory::set (unsigned i, int value) {
    _registers[i] = value;
}

std::ostream& operator<< (std::ostream& os, const DataMemory& memory) {
    int cont = 0;
    for (auto reg: memory._registers) {
        os << "[" << reg.first << "] " << reg.second;
        os << (cont == 3 ? '\n' : '\t');
        cont = ++cont % 3;
    }
    return os;
}
