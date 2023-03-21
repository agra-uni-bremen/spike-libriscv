// See LICENSE for license details.

#include "interface.h"
#include "libriscv.h"
#include "insn_template.h"

reg_t rv32_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  int xlen = 32;
  write_pc(sext_xlen(pc + insn_length(OPCODE)));
  exec_NAME((uint32_t)pc, (void*)&insn);
  trace_opcode(p, OPCODE, insn);
  return read_next_pc();
}

reg_t rv64_NAME(processor_t* p, insn_t insn, reg_t pc)
{
  int xlen = 64;
  reg_t npc = sext_xlen(pc + insn_length(OPCODE));
  #include "insns/NAME.h"
  trace_opcode(p, OPCODE, insn);
  return npc;
}
