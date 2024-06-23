/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_group know_group_t;
inline void know_group_free(know_group_t*);
inline void know_groups_free(know_group_t**);
inline know_group_t* know_group_clone(const know_group_t*);
inline know_group_t** know_groups_clone(const know_group_t**);

typedef struct know_organization {
} know_organization_t;

inline know_organization_t* know_organization_alloc() {
  return calloc(1, sizeof(know_organization_t));
}

inline know_organization_t** know_organizations_alloc(const size_t count) {
  return calloc(count, sizeof(know_organization_t*));
}

inline know_organization_t* know_organization_clone(const know_organization_t* thing) {
  know_organization_t* clone = know_organization_alloc();
  return clone;
}

inline know_organization_t** know_organizations_clone(const know_organization_t** things) {
  return NULL; // TODO
}

inline void know_organization_free(know_organization_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_organizations_free(know_organization_t** things) {
  // TODO
}
