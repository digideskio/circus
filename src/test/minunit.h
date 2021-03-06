/*
 * Copyright (c) 2011 Ignasi Barrera
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * Inspired by MinUnit testing framework
 * http://www.jera.com/techinfo/jtns/jtn002.html
 */

#ifndef __MINUNIT_H__
#define __MINUNIT_H__

#include "../lib/debug.h"

/* Macro to string helpers */
#define STR_VALUE(x) #x
#define STR(x) STR_VALUE(x)

/* Test macros */
#define mu_assert(test, msg) do { if (!(test)) { mu_fail(msg); return; } } while (0)
#define mu_run(test) do { debug(("TEST: %s\n", STR(test))); test(); tests_run++; } while (0)
#define mu_suite(suite) do { debug(("SUITE: %s\n", STR(suite))); suite(); } while (0)

extern int tests_run;       /* Number of executed tests */
extern int test_fails;      /* Number of failed tests */

void mu_fail(char* msg);    /* Mark a test as failed */
void mu_results();          /* Print test results */
void mu_free();             /* Free memory used in testing */

#endif

