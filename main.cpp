#include <iomanip>
#include <iostream>
#include <string>
#include "Memory.h"
#include "Register.h"

int main() {
  unsigned int addr = 0;
  std::string token;
  auto *load = new Byte[MemoryMaxSize];
  memset(load, 0, sizeof(load));
  while(std::cin >> token){
    if(token[0] == '@') {
      addr = std::stoi(std::string(token.begin() + 1, token.end()), nullptr, 16);
      continue;
    }
    unsigned char byte = std::stoi(token, nullptr, 16);
    load[addr] = Byte(byte);
    addr++;
  }
  memoryCore.init(load);
  registerCore.setPc(0);
}