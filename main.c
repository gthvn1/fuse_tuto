#define FUSE_USE_VERSION 31

#include <errno.h>
#include <fuse3/fuse.h>
#include <stdio.h>
#include <string.h>

// Similar to stat. We need to fill [st] structure.
// [fi] is NULL if file not opened.
static int fs_gettatr(const char *path, struct stat *st,
                      struct fuse_file_info *fi) {
  int res = 0;

  memset(st, 0, sizeof(struct stat));
  if (strcmp(path, "/") == 0) {
    st->st_mode = S_IFDIR | 0755;
    st->st_nlink = 2;
  } else {
    printf("not implemented for %s\n", path);
    res = -ENOSYS;
  }

  return res;
}

int main(int argc, char *argv[]) {

  const struct fuse_operations fuse_op = {
      .getattr = fs_gettatr,
  };

  fuse_main(argc, argv, &fuse_op, NULL);

  return 0;
}
