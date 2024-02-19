#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

class Tape {
private:
    unsigned _header;
    std::vector<int> _data;

public:
    Tape ();
    Tape (const std::vector<int>& data);
    Tape (const std::string& filename);

    void next ();
    void reset ();

    int read () const;
    void write (int data);

    void load (const std::string& filename);
    void save (const std::string& filename) const;

    friend std::ostream& operator<< (std::ostream& os, const Tape& tape);
};

std::ostream& operator<< (std::ostream& os, const Tape& tape);
