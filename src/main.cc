#include "RAM.h"

int main (int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "ERROR: Debe indicar el nombre del programa RAM y los ficheros de las cintas de entrada y salida.\n";
        std::cerr << "Modo de uso: ./ram_simulator program.ram input.tape output.tape\n";
        return 1;
    }

    std::string programFilename = argv[1];
    std::string inputFilename = argv[2];
    std::string outputFilename = argv[3];
    
    RAM ram(
        programFilename,
        inputFilename,
        outputFilename
    );
    ram.start();
    
    return 0;
}