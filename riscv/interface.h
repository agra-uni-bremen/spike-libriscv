#ifndef LIBRISCV_INTERFACE
#define LIBRISCV_INTERFACE

#include <stdint.h>

#include "decode.h"
#include "processor.h"

/* Spike-specific API */
void init_core(processor_t *);
void set_npc(reg_t *);

extern "C" {

/* Register file */
uint32_t read_register(unsigned idx);
void write_register(unsigned idx, uint32_t value);

/* Program counter */
uint32_t read_next_pc(void);
void write_pc(uint32_t newPC);

/* Byte-addressable memory */
uint8_t load_byte(uint32_t addr);
uint16_t load_half(uint32_t addr);
uint32_t load_word(uint32_t addr);
void store_byte(uint32_t addr, uint8_t value);
void store_half(uint32_t addr, uint16_t value);
void store_word(uint32_t addr, uint32_t value);

/* Decoder interface */
uint32_t instr_rs1(void *instr);
uint32_t instr_rs2(void *instr);
uint32_t instr_rd(void *instr);
uint32_t instr_immI(void *instr);
uint32_t instr_immS(void *instr);
uint32_t instr_immB(void *instr);
uint32_t instr_immU(void *instr);
uint32_t instr_immJ(void *instr);
uint32_t instr_shamt(void *instr);

}

#endif
