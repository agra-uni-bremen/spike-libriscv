#include <stdint.h>

#include "mmu.h"
#include "processor.h"
#include "decode.h"
#include "interface.h"

static processor_t *p;
static reg_t *npc;

void init_core(processor_t *_core) {
	p = _core;
}

void set_npc(reg_t *npc) {
	npc = npc;
}

////
// Register File
////

uint32_t
read_register(unsigned idx)
{
	return READ_REG(idx);
}

void
write_register(unsigned idx, uint32_t value)
{
	WRITE_REG(idx, value);
}

////
// Program Counter
////

uint32_t
read_next_pc(void)
{
	return (uint32_t)*npc;
}

void
write_pc(uint32_t newPC)
{
	*npc = newPC;
}

////
// Data Memory
////

uint8_t
load_byte(uint32_t addr)
{
	return MMU.load_uint8(addr);
}

uint16_t
load_half(uint32_t addr)
{
	return MMU.load_uint16(addr);
}

uint32_t
load_word(uint32_t addr)
{
	return MMU.load_uint32(addr);
}

void
store_byte(uint32_t addr, uint8_t value)
{
	MMU.store_uint8(addr, value);
}

void
store_half(uint32_t addr, uint16_t value)
{
	MMU.store_uint16(addr, value);
}

void
store_word(uint32_t addr, uint32_t value)
{
	MMU.store_uint32(addr, value);
}

////
// Instruction Decoder
////

uint32_t
instr_rs1(void *instr)
{
	return ((insn_t*)instr)->rs1();
}

uint32_t
instr_rs2(void *instr)
{
	return ((insn_t*)instr)->rs2();
}

uint32_t
instr_rd(void *instr)
{
	return ((insn_t*)instr)->rd();
}

uint32_t
instr_immI(void *instr)
{
	return ((insn_t*)instr)->i_imm();
}

uint32_t
instr_immS(void *instr)
{
	return ((insn_t*)instr)->s_imm();
}

uint32_t
instr_immB(void *instr)
{
	return ((insn_t*)instr)->sb_imm();
}

uint32_t
instr_immU(void *instr)
{
	return ((insn_t*)instr)->u_imm();
}

uint32_t
instr_immJ(void *instr)
{
	return ((insn_t*)instr)->uj_imm();
}

uint32_t
instr_shamt(void *instr)
{
	return ((insn_t*)instr)->shamt();
}
