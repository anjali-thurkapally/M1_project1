#include "unity.h"
#include "main.h"


int tLength = 0;
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_add(void) {
  TEST_ASSERT_EQUAL(0, addTodo("testing add todo"));
}

void test_delete(void) {
  TEST_ASSERT_EQUAL(0, addTodo("test delete todo"));
  TEST_ASSERT_EQUAL(0, deleteTodo(1));
}

void test_mark(void) {
  TEST_ASSERT_EQUAL(0, addTodo("test mark in todo"));
  TEST_ASSERT_EQUAL(0, markAsComplete(1));
}
void test_display(void) 
{ 
  TEST_ASSERT_EQUAL(1, printAllTodo()>0);
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_add);
  RUN_TEST(test_delete);
  RUN_TEST(test_mark);
  RUN_TEST(test_display);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
