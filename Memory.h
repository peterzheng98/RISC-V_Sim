//
// Created by 郑文鑫 on 2019-07-03.
//

#ifndef RISC_V_SIM_MEMORY_H
#define RISC_V_SIM_MEMORY_H
#include "CoreType.h"
#include <cassert>
#include <memory>
#define MemoryMaxSize 0x400000
class Memory {
private:
  Byte memory_core[MemoryMaxSize];

public:
  Memory() = default;
  void init(Byte *data) {
    assert(sizeof(memory_core) == sizeof(data));
    memcpy(memory_core, data, sizeof(memory_core));
  }

  Byte LoadByte(const unsigned int &addr) { return Byte(memory_core[addr]); }

  Half LoadHalf(const unsigned int &addr) {
    return Half(memory_core[addr], memory_core[addr + 1]);
  }

  Word LoadWord(const unsigned int &addr) {
    return Word(memory_core[addr], memory_core[addr + 1], memory_core[addr + 2],
                memory_core[addr + 3]);
  }

  bool SaveByte(const unsigned int &addr, const Byte &dat) {
    if (addr > MemoryMaxSize)
      return false;
    this->memory_core[addr] = dat;
    return true;
  }

  bool SaveHalf(const unsigned int &addr, const Half &half) {
    if (addr + 1 > MemoryMaxSize)
      return false;
    this->memory_core[addr] = half.core.u1;
    this->memory_core[addr + 1] = half.core.u2;
    return true;
  }

  bool SaveWord(const unsigned int &addr, const Word &word) {
    if (addr + 3 > MemoryMaxSize)
      return false;
    this->memory_core[addr] = word.core.u1;
    this->memory_core[addr + 1] = word.core.u2;
    this->memory_core[addr + 2] = word.core.u3;
    this->memory_core[addr + 3] = word.core.u4;
    return true;
  }
};
Memory memoryCore;

#endif // RISC_V_SIM_MEMORY_H
