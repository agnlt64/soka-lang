#include "include/soka.h"
#include "include/ast.h"
#include "include/lexer.h"
#include "include/token.h"
#include "include/io.h"
#include "include/parser.h"

#include <stdio.h>
#include <stdlib.h>

void soka_compile(char* src)
{
  Lexer_T* lexer = init_lexer(src);
  Parser_T* parser = init_parser(lexer);
  AST_T* root = parser_parse(parser);

  printf("%d\n", root->children->size);

  Token_T* tok = 0;
  while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF)
  {
    printf("%s\n", token_to_str(tok));
  }
}

void soka_compile_file(const char* filename)
{
  char* src = tac_read_file(filename);
  soka_compile(src);
  free(src);
}
