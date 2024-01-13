#define FUSE_USE_VERSION 31

#include <fuse3/fuse.h>
#include <fuse3/fuse_opt.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

  /* Parse options */
  void *data = NULL;
  struct fuse_opt *opts = NULL;
  fuse_opt_proc_t proc = NULL;

  if (fuse_opt_parse(&args, data, opts, proc) == -1) {
    printf("failed to parse fuse args");
    return 1;
  };

  printf("Hello");
  return 0;
}
