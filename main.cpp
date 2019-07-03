#include <iomanip>
#include <iostream>

int main() {
  std::string code;
  unsigned int inst;
  for(int i = 0; i < 4; ++i){
    std::cin >> code;
    int bit1 = (code[0] >= 'A' ? code[0] - 'A' + 10 : code[0] - '0');
    int bit2 = (code[1] >= 'A' ? code[1] - 'A' + 10 : code[1] - '0');
    inst = inst * 16 * 16 + bit1 * 16 + bit2;
  }
  std::cout << inst << " in Hex: " << std::setbase(16) << inst;
}