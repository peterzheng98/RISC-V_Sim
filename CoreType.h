//
// Created by 郑文鑫 on 2019-07-03.
//

#ifndef RISC_V_SIM_CORETYPE_H
#define RISC_V_SIM_CORETYPE_H
union Byte {
  unsigned char u1;
  Byte(unsigned char u1) : u1(u1) {}
  Byte() {}
};
union Word {
  int s;
  unsigned int us;
  struct {
    unsigned char u1, u2, u3, u4;
  } core;
  Word(int s) : s(s) {}
  Word(unsigned int us) : us(us) {}
  Word() {}
  Word(unsigned char u1, unsigned char u2, unsigned char u3, unsigned char u4) {
    core.u1 = u1;
    core.u2 = u2;
    core.u3 = u3;
    core.u4 = u4;
  }
  Word(Byte u1, Byte u2, Byte u3, Byte u4) {
    core.u1 = u1.u1;
    core.u2 = u2.u1;
    core.u3 = u3.u1;
    core.u4 = u4.u1;
  }
};

union Half {
  short s;
  unsigned short us;
  struct {
    unsigned char u1, u2;
  } core;
  Half(short s) : s(s) {}
  Half(unsigned short us) : us(us) {}
  Half() {}
  Half(unsigned char u1, unsigned char u2) {
    core.u1 = u1;
    core.u2 = u2;
  }
  Half(Byte u1, Byte u2) {
    core.u1 = u1.u1;
    core.u2 = u2.u1;
  }
};

#endif // RISC_V_SIM_CORETYPE_H
