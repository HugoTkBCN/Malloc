/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
    }
    return (i);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void test_calloc(void)
{
    const char *error = NULL;
    void *module = NULL;
    void *(*ptr)(size_t, size_t) = NULL;

    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "calloc");
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find calloc: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */

    int *test = (int *) (*ptr)(10, sizeof(int));

    for (int i = 0; i < 10; i++ )
        test[i] = i;
    for (int i = 0; i<10; i++ )
        my_put_nbr(test[i]);
    my_putstr("\n");
    free(test);

    /* All done, close things cleanly */
    dlclose(module);
}

void test_realloc(void)
{
    const char *error = NULL;
    void *module = NULL;
    void *(*ptr)(void*, size_t) = NULL;

    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "realloc");
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find realloc: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */
    int *test = (int *)malloc(sizeof(int)*2);
    int i;
    int *test_new = NULL;

    *test = 10;
    *(test + 1) = 20;

    test_new = (int *)(*ptr)(test, sizeof(int)*3);
    *(test_new + 2) = 30;
    for (i = 0; i < 3; i++)
        my_put_nbr(*(test_new + i));
    //free(test_new);
    my_putstr("\n");

    /* All done, close things cleanly */
    dlclose(module);
}

void test_reallocarray(void)
{
        const char *error = NULL;
    void *module = NULL;
    void *(*ptr)(void *, size_t, size_t) = NULL;

    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "reallocarray");
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find reallocarray: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */
    int *arr = NULL;

    arr = (*ptr)(NULL, 10, sizeof(int));
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    for (int i = 0; i < 10; i++)
        my_put_nbr(arr[i]);
    my_putstr("\n");
    free(arr);

    /* All done, close things cleanly */
    dlclose(module);
}

void test_malloc()
{
    const char *error = NULL;
    void *module = NULL;
    void *(*ptr)(size_t) = NULL;

    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "malloc");
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find malloc: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */
    int i = 0;
    char *str = "hola";
    char *test = (*ptr)(sizeof(char) * my_strlen(str) + 1);
    for (i = 0; str[i]; i++)
        test[i] = str[i];
    test[i] = '\0';
    my_putstr(test);
    my_putstr("\n");
    free(test);

    /* All done, close things cleanly */
    dlclose(module);
}

void test_free()
{
    const char *error = NULL;
    void *module = NULL;
    void *(*ptr)(void*) = NULL;

    /* Load dynamically loaded library */
    module = dlopen("libmy_malloc.so", RTLD_LAZY);
    if (!module) {
        dprintf(2, "Couldn't open libmy_malloc.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    ptr = dlsym(module, "free");
    if ((error = dlerror())) {
        dprintf(2, "Couldn't find free: %s\n", error);
        exit(1);
    }

    /* Now call the function in the DL library */
    int i = 0;
    char *str = "free!";
    char *test = malloc(sizeof(char) * my_strlen(str) + 1);
    for (i = 0; str[i]; i++)
        test[i] = str[i];
    test[i] = '\0';
    my_putstr(test);
    my_putstr("\n");
    (*ptr)(test);

    /* All done, close things cleanly */
    dlclose(module);
}

int main(void)
{
    test_malloc();
    test_realloc();
    test_calloc();
    test_reallocarray();
    test_free();
    return (0);
}
