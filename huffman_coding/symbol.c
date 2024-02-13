#ifndef SYMBOL_H
#define SYMBOL_H

#include <stdlib.h>

/**
 * struct symbol - Data structure.
 * @data: The data to be stored in the structure.
 * @freq: The frequency associated with the data.
 */
typedef struct symbol
{
char data;
size_t freq;
} symbol_t;

/**
 * symbol_create - Creates a symbol_t data structure.
 * @data: The data to be stored in the structure.
 * @freq: Its associated frequency.
 *
 * Return: A pointer to the created symbol_t structure, or NULL if it fails.
 */
symbol_t *symbol_create(char data, size_t freq)
{
symbol_t *new_symbol = (symbol_t *)malloc(sizeof(symbol_t));
if (new_symbol)
{
new_symbol->data = data;
new_symbol->freq = freq;
}
return (new_symbol);
}
#endif /* SYMBOL_H */
