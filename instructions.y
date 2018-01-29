instruction		: ABS rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ADD rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| ADDU rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| ADDI rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| ADDIU rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| AND rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| ANDI rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| CLO rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CLZ rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| DIV rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| DIVU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MULT rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MULTU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MUL rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MADD rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MADDU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MSUB rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| MSUBU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| NEG rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| NOR rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| NOT rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| OR rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| ORI rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| SLL rd rt SH
				{
					new_instruction($1, 0, $3, $2, 0, $4, 0, NULL);
				}
				| SLLV rd rt rs
				{
					new_instruction($1, $4, $3, $2, 0, 0, 0, NULL);
				}
				| SRA rd rt SH
				{
					new_instruction($1, 0, $3, $2, 0, $4, 0, NULL);
				}
				| SRL rd rt rs
				{
					new_instruction($1, $4, $3, $2, 0, 0, 0, NULL);
				}
				| SRLV rd rt rs
				{
					new_instruction($1, $4, $3, $2, 0, 0, 0, NULL);
				}
				| SUB rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| SUBU rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| XOR rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| XORI rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| LUI rt IM
				{
					new_instruction($1, 0, $2, 0, $3, 0, 0, NULL);
				}
				| LI rt L_IM
				{
					new_instruction($1, 0, $2, 0, $3, 0, 0, NULL);
				}
				| SLT rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| SLTU rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| SLTI rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| SLTIU rt rs IM
				{
					new_instruction($1, $3, $2, 0, $4, 0, 0, NULL);
				}
				| SGE rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| SGT rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| B TG
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, $2);
				}
				| BCLF CC TG
				{
					new_instruction($1, 0, 0, 0, 0, 0, $2, $3);
				}
				| BCLT CC TG
				{
					new_instruction($1, 0, 0, 0, 0, 0, $2, $3);
				}
				| BEQ rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BGEZ rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BGEZAL rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BGTZ rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BLEZ rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BLTZAL rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BLTZ rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BNE rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BEQZ rs TG
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, $3);
				}
				| BGE rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BGEU rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BGT rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BGTU rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BLE rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BLEU rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BLT rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BLTU rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| BNEZ rs rt TG
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, $4);
				}
				| J TG
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, $2);
				}
				| JAL TG
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, $2);
				}
				| JALR rs rd
				{
					new_instruction($1, $2, 0, $3, 0, 0, 0, NULL);
				}
				| JR rs
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, NULL);
				}
				| TEQ rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TEQI rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| TNE rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TNEI rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| TGE rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TGEU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TGEI rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| TGEIU rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| TLT rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TLTU rs rt
				{
					new_instruction($1, $2, $3, 0, 0, 0, 0, NULL);
				}
				| TLTI rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| TLTIU rs IM
				{
					new_instruction($1, $2, 0, 0, $3, 0, 0, NULL);
				}
				| LA rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LA rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LB rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LB rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LBU rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LBU rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LH rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LH rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LHU rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LHU rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LW rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LW rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LWCL rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LWCL rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LWL rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LWL rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LWR rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LWR rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LD rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LD rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| LL rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| LL rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SB rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SB rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SH rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SH rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SW rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SW rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SWCL ft TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SWCL ft IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SDCL ft TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SDCL ft IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SWL rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SWL rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SWR rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SWR rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SD rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SD rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| SC rt TG
				{
					new_instruction($1, 0, $2, 0, 0, 0, 0, $3);
				}
				| SC rt IM L_PAREN rs R_PAREN
				{
					new_instruction($1, $5, $2, 0, $3, 0, 0, NULL);
				}
				| MOVE rd rs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| MFHI rd
				{
					new_instruction($1, 0, 0, $2, 0, 0, 0, NULL);
				}
				| MFLO rd
				{
					new_instruction($1, 0, 0, $2, 0, 0, 0, NULL);
				}
				| MTHI rs
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, NULL);
				}
				| MTLO rs
				{
					new_instruction($1, $2, 0, 0, 0, 0, 0, NULL);
				}
				| MFC0 rt rd
				{
					new_instruction($1, 0, $2, $3, 0, 0, 0, NULL);
				}
				| MFC1 rt fs
				{
					new_instruction($1, $3, $2, 0, 0, 0, 0, NULL);
				}
				| MFCL_D rt fs
				{
					new_instruction($1, $3, $2, 0, 0, 0, 0, NULL);
				}
				| MTC0 rd rt
				{
					new_instruction($1, 0, $3, $2, 0, 0, 0, NULL);
				}
				| MTC1 rt fs
				{
					new_instruction($1, $3, $2, 0, 0, 0, 0, NULL);
				}
				| MOVN rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MOVZ rd rs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MOVF rd rs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| MOVT rd rs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| ABS_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ABS_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ADD_D fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| ADD_S fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| CEIL_W_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CEIL_W_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| C_EQ_D CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| C_EQ_S CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| C_LE_D CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| C_LE_S CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| C_LT_D CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| C_LT_S CC fs ft
				{
					new_instruction($1, $3, $4, 0, 0, 0, $2, NULL);
				}
				| CVT_D_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CVT_D_W fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CVT_S_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CVT_S_W fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CVT_W_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| CVT_W_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| DIV_D fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| DIV_S fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| FLOOR_W_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| FLOOR_W_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| MOV_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| MOV_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| MOVF_D fd fs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| MOVF_S fd fs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| MOVT_D fd fs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| MOVT_S fd fs CC
				{
					new_instruction($1, $3, 0, $2, 0, 0, $4, NULL);
				}
				| MOVN_D fd fs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MOVN_S fd fs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MOVZ_D fd fs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MOVZ_S fd fs rt
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MUL_D fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| MUL_S fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| NEG_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| NEG_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ROUND_W_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ROUDN_W_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| SQRT_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| SQRT_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| SUB_D fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| SUB_S fd fs ft
				{
					new_instruction($1, $3, $4, $2, 0, 0, 0, NULL);
				}
				| TRUNC_W_D fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| TRUNC_W_S fd fs
				{
					new_instruction($1, $3, 0, $2, 0, 0, 0, NULL);
				}
				| ERET 
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, NULL);
				}
				| SYSCALL 
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, NULL);
				}
				| NOP 
				{
					new_instruction($1, 0, 0, 0, 0, 0, 0, NULL);
				}
