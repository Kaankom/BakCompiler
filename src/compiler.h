#ifndef BAKCOMPILER_H
#define BAKCOMPILER_H

#include <stdio.h>
#include <stdbool.h>

struct position {
  int line;
  int col;
  const char* filename;
};

enum {
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYPE_OPERATOR,
  TOKEN_TYPE_SYMBOL,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE,
};

struct token {
  int type;
  int flags;

  union {
    char cval; // chars
    const char* sval; // strings
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void* any;
  };

  // true if there is whitespace between the token an the nextToken
  // i.e. "int number" would result in whitespace be set for token "number"
  bool whitespace;

  const char* between_brackets;
};

enum { COMPILER_FILE_COMPILED_OK, COMPILER_FAILED_WITH_ERRORS };

struct compile_process {
  // Compiling Options
  int flags;

  struct compile_process_input_file {
    FILE *fp;
    const char *abs_path;
  } cfile;

  FILE *ofile;
};

int compile_file(const char *filename, const char *out_filename, int flags);
struct compile_process *compile_process_create(const char *filename,
                                               const char *filename_out,
                                               int flags);

#endif
