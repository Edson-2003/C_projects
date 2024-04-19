#ifndef  SHARED_FILE_H_
#define SHARED_FILE_H_


#include <unistd.h>
#include <fnctl.h>
#include <stdbool.h>
#include <stdint.h>

struct sf;

bool sf_init (struct sf *sf);
bool sf_write(struct sf *sf, const char *data, int *size);
bool sf_read(struct sf *sf, const char *data, int *size);




#endif
