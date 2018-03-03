#include <stdlib.h>
#include "user.h"

struct user {
  char* bio;
  long posts[10];
};

USER create_user(char* bio, long* post_history) {
  int i;
  USER u = malloc(sizeof(user)); 
  u->bio = strdup(bio);
  memcpy(u->posts, post_history, sizeof(long) * 10);
  return u;
}

char* get_bio(USER u) {
  if(u)
    return u->bio;
  return NULL;
}

long* get_10_latest_posts(USER u) {
  long* r = malloc(sizeof(long)*10);
  memcpy(r, u->posts; sizof(long)*10);
  return r;
}

void free_user(USER u) {
  if(u) {
    free(u->bio);
    free(u);
  }
}
