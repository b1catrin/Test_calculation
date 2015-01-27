/*
 ============================================================================
 Name        : Test_calculation.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include <Basic.h>
#include <CUError.h>
#include <stdio.h>
#include <TestDB.h>
#include "Automated.h"
#include "calculation.h"


void test_addition(void)
{

	int value_total, get_value;
	int a = 5, b = 4;
	value_total = 9;
	get_value = addition(a, b);
	CU_ASSERT_EQUAL(value_total, get_value);
}

void test_subtraction(void)
{
	int value_total, get_value;
	int a = 5, b = 4;
	value_total = 1;
	get_value = subtraction(a, b);
	CU_ASSERT_EQUAL(value_total, get_value);
}

void test_multiplication(void)
{
	int value_total, get_value;
	int a = 5, b = 4;
	value_total = 20;
	get_value = multiplication(a, b);
	CU_ASSERT_EQUAL(value_total, get_value);
}

void test_division(void)
{
	int value_total, get_value;
	int a = 10, b = 5;
	value_total = 2;
	get_value = division(a, b);
	CU_ASSERT_EQUAL(value_total, get_value);
}

void test_modulus(void)
{
	int value_total, get_value;
	int a = 10, b = 5;
	value_total = 0;
	get_value = modulus(a, b);
	CU_ASSERT_EQUAL(value_total, get_value);
}

int main(void) {
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
	  return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("Suite_success", NULL, NULL);
	if (NULL == pSuite) {
	  CU_cleanup_registry();
	  return CU_get_error();
	}

	/* add the tests to the suite */
	if ((NULL == CU_add_test(pSuite, "addition", test_addition)) ||
	   (NULL == CU_add_test(pSuite, "subtraction", test_subtraction)) ||
	   (NULL == CU_add_test(pSuite, "multiplication", test_multiplication)) ||
	   (NULL == CU_add_test(pSuite, "division", test_division)) ||
	   (NULL == CU_add_test(pSuite, "modulus", test_modulus)))
	{
	  CU_cleanup_registry();
	  return CU_get_error();
	}


	/* Run all tests using the automated interface */
	CU_automated_run_tests();
	CU_list_tests_to_file();


	/* Clean up registry and return */
	CU_cleanup_registry();
	return CU_get_error();


}
