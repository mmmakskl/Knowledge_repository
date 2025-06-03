/*==============================================================================
FMOD Example Framework
Copyright (c), Firelight Technologies Pty, Ltd 2014-2025.
==============================================================================*/
#include <pthread.h>
#include <assert.h>
#include <stdio.h>

#define COMMON_PLATFORM_SUPPORTS_FOPEN

#define FMOD_Main() main(int, char**)
#define Common_TTY(format, ...) fprintf(stderr, format, __VA_ARGS__)
