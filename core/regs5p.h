#ifndef REGS5P_H
#define REGS5P_H

/* TODO: make compile switch for simulation and FPGA 
		to remove redunduncy for implementing on FPGA 
*/
struct idreg_t {
	pc[32];
	pc4[32];
	inst[32];
	predict_as_taken;
	predict_as_not_taken;
};
struct dereg_t {
	pc[32];
	pc4[32];
	inst[32];
	alu_sel;
	alu_fn[4];
	alu_a[32];
	alu_b[32];
	alu_a_forward_en;
	alu_b_forward_en;
	funct3[3];
	funct12[12];
	rd[5];
	rs1[5];
	rs2[5];
	rs1_data[32];
	rs2_data[32];
	load;
	store;
	jump;
	branch;
	beq;
	bne;
	blt;
	bltu;
	bge;
	bgeu;
	nextpc[32];
	csrrw;
	csrrs;
	csrrc;
	uimm;
	fencei;
	fence;
	sfence_vma;
	ecall;
	ebreak;
	mret;
	sret;
	uret;
	wfi;
	wb;
	illegal_instruction;
	predict_as_taken;
	predict_as_not_taken;
};
struct emreg_t {
	pc[32];
	pc4[32];
	inst[32];
	funct3[3];
	funct12[12];
	rd[5];
	rs1[5];
	rs2[5];
	rs1_data[32];
	rs2_data[32];
	load;
	store;
	alu_q[32];
	fencei;
	fence;
	sfence_vma;
	wb;
};
struct mwreg_t {
	pc[32];
	pc4[32];
	inst[32];
	funct12[12];
	rd[5];
	rs1[5];
	rs2[5];
	rs1_data[32];
	rs2_data[32];
	load;
	store;
	alu_q[32];
	wb_value[32];
	wb;
#ifdef DEBUG
	debug_mem_write;
	debug_mem_adrs[32];
	debug_mem_byteen[3];
	debug_mem_data[32];
	debug_wb;
#endif
};
#endif
