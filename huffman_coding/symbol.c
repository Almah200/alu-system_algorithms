#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include "heap/heap.h"

/**
 * struct symbol - Data structure.
 * @data: The data to be stored in the structure.
 * @freq: The frequency associated with the data.
 */

/**
 *symbol_t - Creates a symbol_t data structure.
 * @data: The data to be stored in the structure.
 * @freq: Its associated frequency.
 *
 * Return: A pointer to the created symbol_t structure, or NULL if it fails.
 */
symbol_t *symbol_create(char data, size_t freq)
{
symbol_t newSymbol = malloc(sizeof(symbol_t));
if (newSymbol)
{
newSymbol->data = data;
newSymbol->freq = freq;
}
return (*newSymbol);
}
#endif /* SYMBOL_H */
