#define FUSE_USE_VERSION 31

#include <errno.h>
#include <fuse3/fuse.h>
#include <stdio.h>

static int fs_gettatr(const char *path, struct stat *st,
                      struct fuse_file_info *fi) {
  printf("not implemented\n");
  return -ENOSYS;
}

int main(int argc, char *argv[]) {

  const struct fuse_operations fuse_op = {
      .getattr = fs_gettatr,
  };

  fuse_main(argc, argv, &fuse_op, NULL);

  return 0;
}
