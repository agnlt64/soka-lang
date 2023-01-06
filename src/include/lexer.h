#pragma once
#include "token.h"
#include <stddef.h>

typedef struct LEXER_STRUCT
{
  char* src;
  size_t src_size;
  char c;
  unsigned int i;
} Lexer_T;

Lexer_T* init_lexer(char* src);

char lexer_peek(Lexer_T* lexer, int offset);

void lexer_advance(Lexer_T* lexer);
void lexer_skip_whitespace(Lexer_T* lexer);

Token_T* lexer_parse_number(Lexer_T* lexer);
Token_T* lexer_advance_current(Lexer_T* lexer, int type);
Token_T* lexer_advance_with(Lexer_T* lexer, Token_T* token);
Token_T* lexer_parse_id(Lexer_T* lexer);
Token_T* lexer_next_token(Lexer_T* lexer);
