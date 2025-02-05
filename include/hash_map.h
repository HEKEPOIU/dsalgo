#ifndef DSAL_HASH_MAP
#define DSAL_HASH_MAP

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 4

typedef struct {
  int key;
  char val[256];
} Pair;

typedef struct Node {
  Pair *pair;
  struct Node *next;
} Node;

typedef struct HashMap HashMap;
typedef int (*hash_function)(const HashMap *const, int key);
typedef struct HashMap {
  size_t size;
  size_t capacity;
  double load_thres;
  int extend_ratio;
  Node **buckets;
  hash_function hash;
} HashMap;

HashMap *new_hash_map(hash_function ptr);
HashMap *new_hash_map_default(void);
void del_hash_map(HashMap **map);
int hash_func_defalut(const HashMap *const map, int key);
double load_factor(const HashMap *const map);
char *const get(const HashMap *const map, int key);
void put(HashMap *const map, int key, const char *val);
void extend(HashMap *const map);
void remove_item(HashMap *const map, int key);

HashMap *new_hash_map_default(void) { return new_hash_map(hash_func_defalut); }

HashMap *new_hash_map(hash_function ptr) {
  HashMap *map = malloc(sizeof(HashMap));
  map->size = 0;
  map->capacity = INIT_CAP;
  map->buckets = malloc(sizeof(Node *) * INIT_CAP);
  map->load_thres = 2.0 / 3.0;
  map->extend_ratio = 2;
  map->hash = ptr;
  for (size_t i = 0; i < map->capacity; i++) {
    map->buckets[i] = NULL;
  }
  return map;
}

void del_hash_map(HashMap **map) {
  for (size_t i = 0; i < (*map)->capacity; i++) {
    Node *cur = (*map)->buckets[i];
    while (cur) {
      Node *tmp = cur;
      cur = cur->next;
      free(tmp->pair);
      free(tmp);
    }
  }
  free((*map)->buckets);
  free(*map);
  (*map) = NULL;
}

int hash_func_defalut(const HashMap *const map, int key) {
  return key % (int)map->capacity;
}

double load_factor(const HashMap *const map) {
  return (double)map->size / (double)map->capacity;
}

char *const get(const HashMap *const map, int key) {
  int index = map->hash(map, key);

  Node *cur = map->buckets[index];
  while (cur) {
    if (cur->pair->key == key) {
      return cur->pair->val;
    }
    cur = cur->next;
  }
  return NULL;
}

void put(HashMap *const map, int key, const char *val) {
  if (load_factor(map) > map->load_thres) {
    extend(map);
  }
  int index = map->hash(map, key);
  Node *cur = map->buckets[index];
  while (cur) {
    if (cur->pair->key == key) {
      strcpy(cur->pair->val, val);
      return;
    }
    cur = cur->next;
  }
  Pair *p = malloc(sizeof(Pair));
  p->key = key;
  strcpy(p->val, val);
  Node *n = malloc(sizeof(Node));
  n->pair = p;
  n->next = map->buckets[index];
  map->buckets[index] = n;
  map->size++;
};

void extend(HashMap *const map) {
  size_t old_cap = map->capacity;
  Node **old_buckets = map->buckets;
  map->capacity *= (size_t)map->extend_ratio;
  map->size = 0;
  map->buckets = malloc(sizeof(Node *) * map->capacity);

  for (size_t i = 0; i < map->capacity; i++) {
    map->buckets[i] = NULL;
  }
  for (size_t i = 0; i < old_cap; i++) {
    Node *cur = old_buckets[i];
    while (cur) {
      put(map, cur->pair->key, cur->pair->val);
      Node *temp = cur;
      cur = cur->next;
      free(temp->pair);
      free(temp);
    }
  }
  free(old_buckets);
}

void remove_item(HashMap *const map, int key) {
  int index = map->hash(map, key);
  Node *cur = map->buckets[index];
  Node *pre = NULL;
  while (cur) {
    if (cur->pair->key == key) {
      if (pre) {
        pre->next = cur->next;
      } else {
        map->buckets[index] = cur->next;
      }
      free(cur->pair);
      free(cur);
      map->size--;
      return;
    }
    pre = cur;
    cur = cur->next;
  }
}

#endif // !DSAL_HASH_MAP
