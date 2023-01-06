#include "include/parser.h"
#include "include/ast.h"
#include "include/lexer.h"
#include "include/token.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Parser_T* init_parser(Lexer_T *lexer)
{
  Parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
  parser->lexer = lexer;
  parser->token = lexer_next_token(lexer);

  return parser;
}

Token_T* parser_eat(Parser_T* parser, int type)
{
  if (parser->token->type != type)
  {
    printf("[PARSER]: Unexpected token `%s`, was expecting `%s`\n", token_to_str(parser->token), token_type_to_str(type));
    exit(-1);
  }
  parser->token = lexer_next_token(parser->lexer);
  return parser->token;
}

AST_T* parser_parse(Parser_T* parser)
{
  return parser_parse_compound(parser);
}

AST_T* parser_parse_id(Parser_T* parser)
{
  char* value = calloc(strlen(parser->token->value) + 1, sizeof(char));
  strcpy(value, parser->token->value);
  parser_eat(parser, TOKEN_ID);
  printf("-->%s\n", value);

  if (parser->token->type == TOKEN_EQUALS)
  {
    parser_eat(parser, TOKEN_EQUALS);
    AST_T* ast = init_ast(AST_ASSIGNMENT);
    ast->name = value;
    printf("-->%s\n", ast->name);
    ast->value = parser_parse_expr(parser);

    return ast;
  }
    
  AST_T* ast = init_ast(AST_VARIABLE);
  ast->name = value;
  return ast;
}

AST_T* parser_parse_expr(Parser_T* parser)
{
  switch (parser->token->type)
  {
    case TOKEN_ID: return parser_parse_id(parser);
    default: printf("[PARSER]: Unexpected token `%s`\n", token_to_str(parser->token)); exit(1);
  }
}

AST_T* parser_parse_compound(Parser_T* parser)
{
  AST_T* compound = init_ast(AST_COMPOUND);

  while (parser->token->type != TOKEN_EOF)
  {
    list_push(compound->children, parser_parse_expr(parser));
  }
  return compound;
}
