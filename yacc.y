%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "C/util.h"
#include "C/Compiler/targets.h"
#include "C/Compiler/static_data.h"
#include "C/Compiler/instruction_memory.h"
#include "C/Compiler/instruction_factory.h"

#define BUF_SIZE 128

int yyerror(char* s);
int yylex();

FILE* input;
%}

%debug 

%union 
{
    char   trans[BUF_SIZE+1];
    short  val;
}

%start mips_option

%token IMMEDIATE TARGET
%token SYSCALL NOOP
%token L_PAREN R_PAREN

%type <trans> TARGET
%type <val> IMMEDIATE SYSCALL NOOP 
%type <val> command_rrr command_rr command_r command_rri command_ri command_ror command_brr command_br command_jr command_j

%%

mips_option     : instruction
                | TARGET COLON
                ;

instruction     : SYSCALL 
                {
                    new_instruction($1, 0, 0, 0, NULL);
                }
                | NOOP
                {
                    new_instruction($1, 0, 0, 0, NULL);
                }
                | command_rrr reg reg reg
                {
                    new_instruction($1, $2, $3, $4, NULL);
                }
                | command_rr reg reg
                {
                    new_instruction($1, $2, $3, 0, NULL);
                }
                | command_r reg
                {
                    new_instruction($1, $2, 0, 0, NULL);
                }
                | command_rri reg reg IMMEDIATE
                {
                    new_instruction($1, $2, $3, $4, NULL);
                }
                | command_ri reg IMMEDIATE
                {
                    new_instruction($1, $2, $3, 0, NULL);
                }
                | command_ror reg IMMEDIATE L_PAREN reg R_PAREN
                {
                    new_instruction($1, $2, $3, $5, NULL);
                }
                | command_brr reg reg TARGET
                {
                    new_instruction($1, $2, $3, 0, $4);
                }
                | command_br reg TARGET
                {
                    new_instruction($1, $2, 0, 0, $4);
                }
                | command_jr reg TARGET
                {
                    new_instruction($1, $2, 0, 0, $3);
                }
                | command_j TARGET
                {
                    new_instruction($1, 0, 0, 0, $2);
                }
                ;


%%

int main() {
    struct rlimit64 lim = {4000000000, 4294967296};
    if(setrlimit(RLIMIT_DATA, &lim) == -1)
        exit(1);
    yyparse();
    replace_targets();
    print();
    return 0;
}

int yyerror(char* s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}