#include <iostream>
#include <fstream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


//predefined function for checksum
uint32_t MyChkSum(const char* buff, size_t len, uint32_t prevchk) {

}

//implement the following function:
bool Compare(const std::string& p_A_filename, const std::string& p_B_filename) {
    std::ifstream p_A_file(p_A_filename, std::ios::binary);
    std::ifstream p_B_file(p_B_filename, std::ios::binary);
    return false;
}