// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: Canonical Ltd.

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc <= 1) {
    // We don't want to pretend to work but do nothing.
    fprintf(stderr, "nothing to open - empty glob?\n");
    return EXIT_FAILURE;
  }

  void **handles = calloc(argc, sizeof(void *));
  if (handles == NULL) {
    perror("calloc");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; ++i) {
    printf("dlopen %s\n", argv[i]);
    void *h = dlopen(argv[i], RTLD_NOW | RTLD_LOCAL);
    if (h == NULL) {
      perror(dlerror());
      return EXIT_FAILURE;
    }

    handles[i - 1] = h;
  }

  for (int i = argc - 1; i > 0; --i) {
    printf("dlclose %s\n", argv[i]);
    if (dlclose(handles[i - 1]) != 0) {
      perror(dlerror());
      return EXIT_FAILURE;
    }
  }

  free(handles);

  return EXIT_SUCCESS;
}
