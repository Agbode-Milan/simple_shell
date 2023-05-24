#ifndef BUILTIN_H
#define BUILTIN_H

#include "shell.h"
#include "types.h"

int _myexit(struct info_t *info);
int _mycd(struct info_t *info);
int _myhelp(struct info_t *info);

#endif  /* BUILTIN_H */

