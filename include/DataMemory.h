#pragma once

#include <map>
#include <iostream>

class DataMemory {
private:

    std::map<int, int> _registers;

public:
    DataMemory () = default;

    int get (unsigned i) const;
    void set (unsigned i, int value);

    friend std::ostream& operator<< (std::ostream& os, const DataMemory& memory);
};

std::ostream& operator<< (std::ostream& os, const DataMemory& memory);
