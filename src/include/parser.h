#pragma once

#include "lexer.h"
#include "ast.h"
#include "token.h"

typedef struct PARSER_STRUCT
{
  Lexer_T* lexer;
  Token_T* token;
} Parser_T;

Parser_T* init_parser(Lexer_T* lexer);

Token_T* parser_eat(Parser_T* parser, int type);

AST_T* parser_parse_expr(Parser_T* parser);
AST_T* parser_parse(Parser_T* parser);
AST_T* parser_parse_compound(Parser_T* parser);
