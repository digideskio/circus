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

#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#define HT_SIZE 256
#define ht_eq(a, b) (strcmp(a.key, b.key) == 0)     // Data equallity macro

/*************************/
/* Hash table definition */
/*************************/

// The data being stored in the hashtable
typedef struct {
    char* key;
    void* value;
} HTData;

// Hash table entry
typedef struct entry {
    struct entry *next;
    HTData data;
} HTEntry;

// Hash table data structure
typedef struct {
    HTEntry** entries;	    // The hash table
    size_t size;            // The size of the hash table
    int num_entries;        // The number of current entries
} HTable;

// Hash table index
typedef unsigned char HTIndex;

/************************/
/* Hash table functions */
/************************/

HTable*     ht_create();			    // Create a new hash table
void        ht_destroy(HTable* ht);                 // Destroy the given hash table
HTEntry*    ht_add(HTable* ht, HTData data);        // Add an entry to the hash table
HTData 	    ht_del(HTable* ht, HTData data);	    // Remove an entry from the hash table
HTEntry*    ht_find(HTable* ht, HTData data);	    // Find an entry in the hash table
void        ht_print_keys(HTable* ht);              // Print all keys in the table
HTIndex     ht_hash(HTData data);                   // Compute the hash for the given data

#endif

