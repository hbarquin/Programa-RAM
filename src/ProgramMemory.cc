#include "ProgramMemory.h"

ProgramMemory::ProgramMemory (const std::string& filename) {
    load(filename);
}

ProgramMemory::~ProgramMemory () {
    for (AbstractInstruction* instruction: _instructions) {
        delete instruction;
    }
    _instructions.clear();
}

AbstractInstruction* ProgramMemory::read () const {
    return _instructions[_current_instruction];
}

void ProgramMemory::setCurrentInstruction (const std::string& tag) {
    assert(hasTag(tag));
    _current_instruction = _tags[tag];
}

unsigned ProgramMemory::getIndex () const {
    return _current_instruction;
}

bool ProgramMemory::hasTag (const std::string& tag) const {
    return _tags.find(tag) != _tags.end();
}

unsigned ProgramMemory::getIndexFromTag (const std::string& tag) const {
    assert(hasTag(tag));
    return _tags.at(tag);
}

void ProgramMemory::reset () {
    _current_instruction = 0;
}

void ProgramMemory::next () {
    _current_instruction++;
}

bool ProgramMemory::end () const {
    return _current_instruction >= _instructions.size();
}

void ProgramMemory::load (const std::string& filename) {
    if (filename.substr(filename.find_last_of('.')+1) != "ram") {
        std::cout << "WARNING: La extensión del programa RAM '" << filename << "' no tiene extensión '.ram'\n";
    }

    std::ifstream ifile(filename);

    if (!ifile.is_open()) {
        throw std::runtime_error("ERROR: No se pudo abrir el programa RAM.");
    }

    std::string line;
    int inx = 0;
    while (std::getline(ifile, line)) {
        if (line[0] == '#' || line.empty()) {
            continue;
        }

        std::cout << "[D] Leyendo línea '" << line << "'\n";
        std::stringstream sline(line);
        std::string word;
        sline >> word;
        if (word.empty()) {
            continue;
        }
        std::cout << "[D] Encontrada palabra '" << word << "'\n";

        if (word.back() == ':') {
            word.pop_back();
            std::cout << "[D] Categorizada palabra '" << word << "' como una etiqueta.\n";
            _tags[word] = inx;
        } else {
            sline = std::stringstream(line);
        }

        std::getline(sline, word);
        std::cout << "[D] Encontrada palabra '" << word << "'\n";
        _instructions.push_back(AbstractInstruction::toInstruction(word));
        inx++;
    }

    ifile.close();
}
