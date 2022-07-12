#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;

    len = _printf("Let's try to printf a simple sentence and %c with %c and %c\n", 'A', 'B', 'c');
    len2 = printf("Let's try to printf a simple sentence and another name is j.\n");
    ui = (unsigned int)INT_MAX + 1024;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -5343534);
    printf("Negative:[%d]\n", -5343534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = printf("Percent:[%%]\n");
    len2 = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len2);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%m] \n");
    printf("Unknown:[%m]\n");
    return (0);
}
