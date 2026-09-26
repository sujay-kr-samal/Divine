#include <stdio.h>
#include <stdlib.h>

#include "AST.h"
#include "Lexer.h"
#include "Parser.h"

char *read_file(const char *filename);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <file.divine>\n", argv[0]);
    return 1;
  }

  char *source = read_file(argv[1]);

  if (source == NULL) {
    return 1;
  }

  lexer_init(source);

  parser_init();

  ASTNode *tree = parse();

  ast_print(tree, 0);

  ast_free(tree);

  free(source);

  return 0;
}
