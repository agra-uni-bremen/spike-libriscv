#ifndef RISCV_VP_ISS_INTERFACE
#define RISCV_VP_ISS_INTERFACE

#include <stdint.h>

#include "mmu.h"
#include "processor.h"
#include "decode.h"

////
// Register File
////

static inline uint32_t
read_register(void *core, unsigned idx)
{
	processor_t *p = (processor_t*)core;
	return READ_REG(idx);
}

static inline void
write_register(void *core, unsigned idx, uint32_t value)
{
	processor_t *p = (processor_t*)core;
	WRITE_REG(idx, value);
}

////
// Program Counter
////

static inline uint32_t
read_next_pc(void *core)
{
	processor_t *p = (processor_t*)core;
	return p->get_state()->pc;
}

static inline void
write_pc(void *core, uint32_t newPC)
{
	processor_t *p = (processor_t*)core;
	p->get_state()->pc = newPC;
}

////
// Data Memory
////

static inline uint8_t
load_byte(void *core, uint32_t addr)
{
	processor_t *p = (processor_t*)core;
	return MMU.load_uint8(addr);
}

static inline uint16_t
load_half(void *core, uint32_t addr)
{
	processor_t *p = (processor_t*)core;
	return MMU.load_uint16(addr);
}

static inline uint32_t
load_word(void *core, uint32_t addr)
{
	processor_t *p = (processor_t*)core;
	return MMU.load_uint32(addr);
}

static inline void
store_byte(void *core, uint32_t addr, uint8_t value)
{
	processor_t *p = (processor_t*)core;
	MMU.store_uint8(addr, value);
}

static inline void
store_half(void *core, uint32_t addr, uint16_t value)
{
	processor_t *p = (processor_t*)core;
	MMU.store_uint16(addr, value);
}

static inline void
store_word(void *core, uint32_t addr, uint32_t value)
{
	processor_t *p = (processor_t*)core;
	MMU.store_uint32(addr, value);
}

////
// Instruction Decoder
////

static inline uint32_t
instr_rs1(void *instr)
{
	return ((insn_t*)instr)->rs1();
}

static inline uint32_t
instr_rs2(void *instr)
{
	return ((insn_t*)instr)->rs2();
}

static inline uint32_t
instr_rd(void *instr)
{
	return ((insn_t*)instr)->rd();
}

static inline uint32_t
instr_immI(void *instr)
{
	return ((insn_t*)instr)->i_imm();
}

static inline uint32_t
instr_immS(void *instr)
{
	return ((insn_t*)instr)->s_imm();
}

static inline uint32_t
instr_immB(void *instr)
{
	return ((insn_t*)instr)->sb_imm();
}

static inline uint32_t
instr_immU(void *instr)
{
	return ((insn_t*)instr)->u_imm();
}

static inline uint32_t
instr_immJ(void *instr)
{
	return ((insn_t*)instr)->uj_imm();
}

static inline uint32_t
instr_shamt(void *instr)
{
	return ((insn_t*)instr)->shamt();
}

#endif
