#pragma once

typedef struct TOKEN_STRUCT
{
  char* value;

  enum 
  {
    TOKEN_ID,
    TOKEN_FUNC,
    TOKEN_EQUALS,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_LT,
    TOKEN_GT,
    TOKEN_MINUS,
    TOKEN_PLUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_RIGHT_ARROW,
    TOKEN_INT,
    TOKEN_SEMI,
    TOKEN_EOF,
  } type;
} Token_T;

Token_T* init_token(char* value, int type);

const char* token_type_to_str(int type);
char* token_to_str(Token_T* token);
