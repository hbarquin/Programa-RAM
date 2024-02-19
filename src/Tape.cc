#include "Tape.h"

Tape::Tape () {
    reset();
}

Tape::Tape (const std::vector<int>& data) {
    reset();
    _data = data;
}

Tape::Tape (const std::string& filename) {
    reset();
    load(filename);
}

void Tape::next () {
    _header++;
}

void Tape::reset () {
    _header = 0;
}

int Tape::read () const {
    assert(_header < _data.size());
    return _data[_header];
}

void Tape::write (int data) {
    assert(_header <= _data.size());
    if (_header == _data.size()) {
        _data.push_back(data);
    } else {
        _data[_header] = data;
    }
}

void Tape::load (const std::string& filename) {
    if (!std::filesystem::exists(filename)) {
        return;
    }

    std::ifstream ifile(filename);
    if (!ifile.is_open()) {
        throw std::runtime_error("ERROR: No se ha podido abrir el fichero " + filename + " para leer la cinta.");
    }

    while (!ifile.eof()) {
        int value;
        ifile >> value;
        _data.push_back(value);
    }
    
    ifile.close();
}

void Tape::save (const std::string& filename) const {
    std::ofstream ofile(filename);

    if (!ofile.is_open()) {
        throw std::runtime_error("ERROR: No se ha podido abrir el fichero " + filename + " para escribir la cinta.");
    }

    for (size_t i = 0; i < _data.size(); i++) {
        ofile << _data[i];
        if (i < _data.size() - 1) {
            ofile << " ";
        }
    }

    ofile.close();
}

std::ostream& operator<< (std::ostream& os, const Tape& tape) {
    for (unsigned i = 0; i < tape._data.size(); i++) {
        if (i == tape._header) {
            os << "> ";
        }
        os << tape._data.at(i);
        if (i < tape._data.size() - 1) {
            os << " ";
        }
    }
    
    return os;
}
