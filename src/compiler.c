#include "compiler.h"
int compile_file(const char *filename, const char *out_filename, int flags) {
  struct compile_process *process =
      compile_process_create(filename, out_filename, flags);

  // Lexical analysis

  // parsing

  // code generation

  if (!process)
    return COMPILER_FAILED_WITH_ERRORS;
  return COMPILER_FILE_COMPILED_OK;
}
