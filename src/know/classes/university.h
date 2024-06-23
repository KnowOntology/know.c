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

typedef struct know_university {
} know_university_t;

inline know_university_t* know_university_alloc() {
  return calloc(1, sizeof(know_university_t));
}

inline know_university_t** know_universities_alloc(const size_t count) {
  return calloc(count, sizeof(know_university_t*));
}

inline know_university_t* know_university_clone(const know_university_t* thing) {
  know_university_t* clone = know_university_alloc();
  return clone;
}

inline know_university_t** know_universities_clone(const know_university_t** things) {
  return NULL; // TODO
}

inline void know_university_free(know_university_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_universities_free(know_university_t** things) {
  // TODO
}
