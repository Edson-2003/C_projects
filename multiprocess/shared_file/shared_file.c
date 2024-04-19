#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fnctl.h>
#include <stdbool.h>
#include <stdint.h>



#include "shared_file.h"

struct sf
{
  const char *fn;
  int fd;
  int timeout;
  struct flock lock;
};
  

static bool
sf_create(struct sf *sf)
{
  bool state = false;
  if(sf != NULL)
  {

    sf->fd = open(sf->fn, O_RDWR | O_CREAT, 0666);
    if(fd >0)
    {
      write(sf->fd, "0", 1);
      close(sf->fd);
      state = true;
      return state;
    }
  }

  return state;
}


static bool
sf_wopen(struct sf *sf)
{
  sf->fd = open(sf->fn, O_RDWR, 0666);
  return sf->fd >= 0 ? 1 : 0;
}

static void
sf_swlock(struct sf *sf)
{
  sf->lock.l_type = F_WRLCK;
  sf->lock.l_whence =  SEEK_SET;
  sf->lock.l_start = 0;
  sf->lock.l_len = 0;
  sf->lock.l_pid = getpid();
}

static void
sf_wlock(struct sf *sf)
{
  while(fcntl(sf->fd, F_SETLK, &sf->lock))
  {
    usleep(sf->timeout);
  }
}

static bool
sf_wunlock(struct sf *sf)
{
  bool state = false;
  sf->lock.l_type = F_UNLCK;

  if(fcntl(sf->fd, F_SETLK, &sf->lock))
  {
    close(sf->fd);
    state = true;
  }
  return state;
}

static bool
sf_ropen(struct sf *sf)
{
  sf->fd = open(sf->fn, O_RDONLY);
  return sf->fd >= 0 ? 1 : 0;
}

static void
sf_srlock(struct sf *sf)
{
  sf->lock.l_type = F_RDLCK;
}

static bool
sf_runlock(struct sf *sf)
{
  bool state = false;
  
  while(fcntl(sf->fd, F_GETLK, &sf->lock) < 0) usleep(sf->timeout);
  
  if(sf->lock.l_type == F_UNLCK)
  {
    state = true;
    return state;
  }
  close(sf->fd);
  return state;
}

bool 
sf_init(struct sf *sf)
{
  bool state = false;
  if(sf != NULL)
  {

    state = sf_create(sf);
  }

  return state;
}

bool
sf_write(struct sf *sf, const char *data, int *size)
{
  bool state = false;
  if(((sf != NULL) && (data != NULL)) && (size > 0))
  {
    if(sf_wopen(sf))
    {
      sf_swlock(sf);
      sf_lock(sf);

      write(sf->fd, data, size);

      state = sf_wunlock(sf);
    }
  }

  return state;

}

bool
sf_read(struct sf *sf, const char *data, int *size)
{
   bool state = false;
  if(((sf != NULL) && (data != NULL)) && (size > 0))  
  {
    if(sf_ropen(sf))
    {
      sf_unlock
    }

    state = sf_unlock(sf);
  }

  return state;
}

