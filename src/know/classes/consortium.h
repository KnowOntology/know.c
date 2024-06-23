/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_organization know_organization_t;
inline void know_organization_free(know_organization_t*);
inline void know_organizations_free(know_organization_t**);
inline know_organization_t* know_organization_clone(const know_organization_t*);
inline know_organization_t** know_organizations_clone(const know_organization_t**);

typedef struct know_consortium {
} know_consortium_t;

inline know_consortium_t* know_consortium_alloc() {
  return calloc(1, sizeof(know_consortium_t));
}

inline know_consortium_t** know_consortia_alloc(const size_t count) {
  return calloc(count, sizeof(know_consortium_t*));
}

inline know_consortium_t* know_consortium_clone(const know_consortium_t* thing) {
  know_consortium_t* clone = know_consortium_alloc();
  return clone;
}

inline know_consortium_t** know_consortia_clone(const know_consortium_t** things) {
  return NULL; // TODO
}

inline void know_consortium_free(know_consortium_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_consortia_free(know_consortium_t** things) {
  // TODO
}
