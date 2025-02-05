#include <hash_map.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_new_map(void) {
  HashMap* map = new_hash_map_default();
  TEST_ASSERT_EQUAL_size_t(0, map->size);
  TEST_ASSERT_EQUAL_size_t(INIT_CAP, map->capacity);
  TEST_ASSERT_EQUAL_DOUBLE(2.0 / 3.0, map->load_thres);
  TEST_ASSERT_EQUAL_INT(2, map->extend_ratio);
  TEST_ASSERT_EQUAL_PTR(hash_func_defalut, map->hash);
}

void test_del_hash_map(void) {
  HashMap* map = new_hash_map_default();
  del_hash_map(&map);
  TEST_ASSERT_EQUAL_PTR(NULL, map);
}

void test_get_load_factor(void) {
  HashMap* map = new_hash_map_default();
  TEST_ASSERT_EQUAL_DOUBLE(0, load_factor(map));
}

void test_put_item(void) {
  HashMap* map = new_hash_map_default();
  put(map, 1, "123");
  int index1 = map->hash(map, 1);
  TEST_ASSERT_EQUAL_INT(1, map->buckets[index1]->pair->key);
  TEST_ASSERT_EQUAL_STRING("123", map->buckets[index1]->pair->val);
  TEST_ASSERT_EQUAL_size_t(1, map->size);
  TEST_ASSERT_EQUAL_DOUBLE(1.0 / INIT_CAP, load_factor(map));

  put(map, 2, "234");
  int index2 = map->hash(map, 2);
  TEST_ASSERT_EQUAL_INT(2, map->buckets[index2]->pair->key);
  TEST_ASSERT_EQUAL_STRING("234", map->buckets[index2]->pair->val);
  TEST_ASSERT_EQUAL_size_t(2, map->size);
  TEST_ASSERT_EQUAL_DOUBLE(2.0 / INIT_CAP, load_factor(map));

  put(map, 1, "345");
  TEST_ASSERT_EQUAL_INT(1, map->buckets[index1]->pair->key);
  TEST_ASSERT_EQUAL_STRING("345", map->buckets[index1]->pair->val);
  TEST_ASSERT_EQUAL_size_t(2, map->size);
  TEST_ASSERT_EQUAL_DOUBLE(2.0 / INIT_CAP, load_factor(map));

  put(map, 3, "456");
  int index3 = map->hash(map, 3);
  TEST_ASSERT_EQUAL_INT(3, map->buckets[index3]->pair->key);
  TEST_ASSERT_EQUAL_STRING("456", map->buckets[index3]->pair->val);
  TEST_ASSERT_EQUAL_size_t(3, map->size);
  TEST_ASSERT_EQUAL_DOUBLE(3.0 / INIT_CAP, load_factor(map));

  put(map, 4, "567");
  int index4 = map->hash(map, 4);
  TEST_ASSERT_EQUAL_INT(4, map->buckets[index4]->pair->key);
  TEST_ASSERT_EQUAL_STRING("567", map->buckets[index4]->pair->val);
  TEST_ASSERT_EQUAL_size_t(4, map->size);
  TEST_ASSERT_EQUAL_DOUBLE(4.0 / (INIT_CAP * 2), load_factor(map));
}

void test_get_item(void) {
  HashMap* map = new_hash_map_default();
  put(map, 1, "123");
  put(map, 2, "456");
  TEST_ASSERT_EQUAL_STRING("123", get(map, 1));
  TEST_ASSERT_EQUAL_STRING("456", get(map, 2));
  put(map, 3, "789");

  TEST_ASSERT_EQUAL_STRING("123", get(map, 1));
  TEST_ASSERT_EQUAL_STRING("456", get(map, 2));
  TEST_ASSERT_EQUAL_STRING("789", get(map, 3));
  TEST_ASSERT_EQUAL_STRING(NULL, get(map, 4));
}

void test_remove_item(void) {
  HashMap* map = new_hash_map_default();
  put(map, 1, "123");
  put(map, 2, "456");
  put(map, 3, "789");
  remove_item(map, 1);
  TEST_ASSERT_EQUAL_STRING(NULL, get(map, 1));
}

int main(int argc, char* argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_new_map);
  RUN_TEST(test_del_hash_map);
  RUN_TEST(test_get_load_factor);
  RUN_TEST(test_put_item);
  RUN_TEST(test_get_item);
  RUN_TEST(test_remove_item);
  return UNITY_END();
}
