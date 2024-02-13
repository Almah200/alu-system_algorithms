#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>
#include "huffman.h"

/**
 * struct symbol - Represents a symbol with associated frequency.
 * @data: The data or character represented by the symbol.
 * @freq: The frequency associated with the symbol.
 */
typedef struct symbol
{
    char data;
    size_t freq;
} symbol_t;

/**
 * symbol_create - Creates a symbol data structure.
 * @data: The data to be stored in the structure.
 * @freq: Its associated frequency.
 *
 * Return: A pointer to the created symbol structure, or NULL if it fails.
 */
symbol_t *symbol_create(char data, size_t freq)
{
    symbol_t *newSymbol = malloc(sizeof(symbol_t));

    if (newSymbol)
    {
        newSymbol->data = data;
        newSymbol->freq = freq;
        }
        return (newSymbol);
}

#endif /* SYMBOL_H */
