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

class constant{
public:
  int add_f3 = 0x0, add_f7 = 0x0;
  int sub_f3 = 0x0, sub_f7 = 0x20;
  int and_f3 = 0x7, and_f7 = 0x0;
  int or_f3 = 0x6, or_f7 = 0x0;
  int xor_f3 = 0x4, xor_f7 = 0x0;
  int slt_f3 = 0x2, slt_f7 = 0x0;
  int sltu_f3 = 0x3, sltu_f7 = 0x0;
  int sra_f3 = 0x5, sra_f7 = 0x20;
  int srl_f3 = 0x5, srl_f7 = 0x0;
  int sll_f3 = 0x1, sll_f7 = 0x0;
  int mul_f3 = 0x0, mul_f7 = 0x1;
  int addi_f3 = 0x0;
  int andi_f3 = 0x7;
  int ori_f3 = 0x6;
  int xori_f3 = 0x4;
  int slti_f3 = 0x2;
  int sltiu_f3 = 0x3;
  int srai_f3 = 0x5, srai_f7 = 0x20;
  int srli_f3 = 0x5, srli_f7 = 0x0;
  int slli_f3 = 0x1, slli_f7 =0x0;
  int lw_f3 = 0x2;
  int lb_f3 = 0x0;
  int lh_f3 = 0x1;
  int lbu_f3 = 0x4;
  int lhu_f3 = 0x5;
  int sw_f3 = 0x2;
  int sb_f3 = 0x0;
  int sh_f3 = 0x1;
  int jalr_f3 = 0x0;
  int beq_f3 = 0x0;
  int bne_f3 = 0x1;
  int blt_f3 = 0x4;
  int bge_f3 = 0x5;
  int bltu_f3 = 0x6;
  int bgeu_f3 = 0x7;
  int r_type_opcode = 0x33;
  int i_type_opcode = 0x13;
  int lui_opcode = 0x37;
  int auipc_opcode = 0x17;
};
static constant constantLabel;
#endif // RISC_V_SIM_CORETYPE_H
