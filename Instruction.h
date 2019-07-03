//
// Created by 郑文鑫 on 2019-07-03.
//

#ifndef RISC_V_SIM_INSTRUCTION_H
#define RISC_V_SIM_INSTRUCTION_H

#include "Memory.h"
#include "Register.h"
class AbstractInst {
public:

  virtual void Execute() = 0;
  virtual void MemoryOper() = 0;
  virtual void WriteBack() = 0;
};

class RTypeInst : public AbstractInst {
private:
  int funct3, funct7;
  Word src1, src2;
  Word res;
  int destIdx;
  int opcode = 0;
public:
  RTypeInst(int funct3, int funct7, const Word &src1, const Word &src2,
            int destIdx, int opcode)
      : funct3(funct3), funct7(funct7), src1(src1), src2(src2),
        destIdx(destIdx), opcode(opcode) {}
  void Execute() override {
    assert(opcode == constantLabel.r_type_opcode);
    if (opcode == constantLabel.r_type_opcode) {
      if (funct3 == constantLabel.add_f3 && funct7 == constantLabel.add_f7)
        res = src1.s + src2.s;
      if (funct3 == constantLabel.sub_f3 && funct7 == constantLabel.sub_f7)
        res = src1.s - src2.s;
      if (funct3 == constantLabel.and_f3 && funct7 == constantLabel.and_f7)
        res = src1.s & src2.s;
      if (funct3 == constantLabel.or_f3 && funct7 == constantLabel.or_f7)
        res = src1.s | src2.s;
      if (funct3 == constantLabel.xor_f3 && funct7 == constantLabel.xor_f7)
        res = src1.s ^ src2.s;
      if (funct3 == constantLabel.slt_f3 && funct7 == constantLabel.slt_f7)
        res = (src1.s < src2.s ? 1 : 0);
      if (funct3 == constantLabel.sltu_f3 && funct7 == constantLabel.sltu_f7)
        res = (src1.us < src2.us ? 1 : 0);
      if (funct3 == constantLabel.sra_f3 && funct7 == constantLabel.sra_f7)
        res = src1.s >> (src2.s & 63);
      if (funct3 == constantLabel.srl_f3 && funct7 == constantLabel.srl_f7)
        res = src1.s >> (src2.s & 63);
      if (funct3 == constantLabel.sll_f3 && funct7 == constantLabel.sll_f7)
        res = src1.s << (src2.s & 63);
      if (funct3 == constantLabel.mul_f3 && funct7 == constantLabel.mul_f7)
        res = src1.s * src2.s;
    }
  }
  void MemoryOper() override {}
  void WriteBack() override {
    registerCore.setReg(res, destIdx);
  }
};

class ITypeInst : public AbstractInst {
private:
  int funct3, funct7;
  Word src1, imm;
  Word res;
  int destIdx;
  int opcode = 0;
public:
  ITypeInst(int funct3, int funct7, const Word &src1, const Word &imm, int destIdx,
            int opcode)
      : funct3(funct3), funct7(funct7), src1(src1), imm(imm), destIdx(destIdx), opcode(opcode) {
  }

  void Execute() override {
    if(opcode == constantLabel.i_type_opcode) {
      if (funct3 == constantLabel.addi_f3)
        res.s = src1.s + imm.s;
      if (funct3 == constantLabel.andi_f3)
        res.s = src1.s & imm.s;
      if (funct3 == constantLabel.ori_f3)
        res.s = src1.s | imm.s;
      if (funct3 == constantLabel.xori_f3)
        res.s = src1.s ^ imm.s;
      if (funct3 == constantLabel.slti_f3)
        res.s = (src1.s < imm.s ? 1 : 0);
      if (funct3 == constantLabel.sltiu_f3)
        res.s = (src1.us < imm.us ? 1 : 0);
      if (funct3 == constantLabel.srai_f3 && funct7 == constantLabel.srai_f7)
        res.s = src1.s >> imm.s;
      if (funct3 == constantLabel.srli_f3 && funct7 == constantLabel.srli_f7)
        res.us = src1.us >> imm.us;
      if (funct3 == constantLabel.slli_f3 && funct7 == constantLabel.slli_f7)
        res.us = src1.us << imm.us;
    }
    if(opcode == constantLabel.lui_opcode) res.s = imm.s << 12;
    if(opcode == constantLabel.auipc_opcode) res.s = registerCore.getPc() + imm.s << 12;
  }
  void MemoryOper() override {}
  void WriteBack() override {}
};

class STypeInst : public AbstractInst {
private:
  int funct3;
  Word src1, src2, imm;
  int opcode = 0;
public:
  STypeInst(int funct3, const Word &src1, const Word &src2, const Word &imm,
            int opcode)
      : funct3(funct3), src1(src1), src2(src2), imm(imm), opcode(opcode) {}
};

class BTypeInst : public AbstractInst {
private:
  int funct3;
  Word src1, src2, imm;
  int opcode = 0;
public:
  BTypeInst(int funct3, const Word &src1, const Word &src2, const Word &imm,
            int opcode)
      : funct3(funct3), src1(src1), src2(src2), imm(imm), opcode(opcode) {}
};

class UTypeInst : public AbstractInst {
private:
  int destIdx;
  Word imm;
  int opcode = 0;
public:
  UTypeInst(int destIdx, const Word &imm, int opcode)
      : destIdx(destIdx), imm(imm), opcode(opcode) {}
};

class JTypeInst : public AbstractInst {
private:
  Word imm;
  int destIdx;
  int opcode = 0;
public:
  JTypeInst(const Word &imm, int destIdx, int opcode)
      : imm(imm), destIdx(destIdx), opcode(opcode) {}
};

#endif // RISC_V_SIM_INSTRUCTION_H
