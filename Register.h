//
// Created by 郑文鑫 on 2019-07-03.
//

#ifndef RISC_V_SIM_REGISTER_H
#define RISC_V_SIM_REGISTER_H

#include "CoreType.h"
#include <cassert>
#include <memory>
class Register {
private:
  Word reg[32];
  Word pc;
  bool locker[32];

public:
  Register(const Word &pc) : pc(pc) {}
  Register() { memset(locker, 0, sizeof(locker)); }
  Register(Word *reg, const Word &pc) : pc(pc) {
    assert(sizeof(reg) == sizeof(this->reg));
    memcpy(this->reg, reg, sizeof(reg));
  }
  const Word *getReg() const { return reg; }
  const Word &getPc() const { return pc; }
  void setPc(const Word &pc) { Register::pc = pc; }
  void setReg(const Word &dat, const int &idx) { Register::reg[idx] = dat; }
};
Register registerCore;

#endif // RISC_V_SIM_REGISTER_H
