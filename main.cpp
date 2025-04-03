#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

const size_t max_bytes = 1024;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


//predefined function for checksum
uint32_t MyChkSum(const char* buff, size_t len, uint32_t prevchk);

//implement the following function:
bool Compare(const std::string& p_A_filename, const std::string& p_B_filename) {
    std::ifstream p_A_file(p_A_filename, std::ios::binary);
    std::ifstream p_B_file(p_B_filename, std::ios::binary);

    //error handling in file opening
    try {
        if (!p_A_file.is_open() || !p_B_file.is_open()) {
            throw std::runtime_error("Failed to open the file for reading.");
        }
    } catch (const std::exception& e) {
        p_A_file.close();
        p_B_file.close();
        throw;
    }

    //variables
    char buffA[max_bytes];
    char buffB[max_bytes];
    uint32_t prevchkA = 0;
    uint32_t prevchkB = 0;

    while (p_A_file) {
        p_A_file.read(buffA, max_bytes); //to only read 1024 bytes max
        std::streamsize pA = p_A_file.gcount();
        if (pA == 0) break; //end of file

        p_B_file.read(buffB, max_bytes);
        std::streamsize pB = p_B_file.gcount();

        if (pB < pA) return false; //B is smaller than A

        prevchkA = MyChkSum(buffA, pA, prevchkA);
        prevchkB = MyChkSum(buffB, pB, prevchkB);

        if (prevchkA != prevchkB) return false;
    }

    return true;
}