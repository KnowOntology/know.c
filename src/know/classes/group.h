/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_person know_person_t;
inline void know_person_free(know_person_t*);
inline void know_people_free(know_person_t**);
inline know_person_t* know_person_clone(const know_person_t*);
inline know_person_t** know_people_clone(const know_person_t**);

typedef struct know_thing know_thing_t;
inline void know_thing_free(know_thing_t*);
inline void know_things_free(know_thing_t**);
inline know_thing_t* know_thing_clone(const know_thing_t*);
inline know_thing_t** know_things_clone(const know_thing_t**);

typedef struct know_group {
  char** logos;
  struct know_person** members;
} know_group_t;

inline know_group_t* know_group_alloc() {
  return calloc(1, sizeof(know_group_t));
}

inline know_group_t** know_groups_alloc(const size_t count) {
  return calloc(count, sizeof(know_group_t*));
}

inline know_group_t* know_group_clone(const know_group_t* thing) {
  know_group_t* clone = know_group_alloc();
  clone->logos = NULL; // TODO
  clone->members = NULL; // TODO
  return clone;
}

inline know_group_t** know_groups_clone(const know_group_t** things) {
  return NULL; // TODO
}

inline void know_group_free(know_group_t* thing) {
  if (!thing) return;
  if (thing->logos) {
    // TODO: free any array elements with know_strings_free()
    free(thing->logos);
    thing->logos = NULL;
  }
  if (thing->members) {
    // TODO: free any array elements with know_person_free()
    free(thing->members);
    thing->members = NULL;
  }
  free(thing);
}

inline void know_groups_free(know_group_t** things) {
  // TODO
}

inline char** know_group_logos_clone(const know_group_t* thing) {
  return know_strings_clone((const char**)thing->logos);
}

inline struct know_person** know_group_members_clone(const know_group_t* thing) {
  return know_people_clone((const struct know_person**)thing->members);
}
