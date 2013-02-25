#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  vsip_vview_d* data;
  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the sum of squares of */
  vsip_vramp_d(0.0, 1.0, data);
  printf("%f \n", vsip_vsumsqval_d(data));
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_finalize((void *)0);
  return 0;
} /* output */
/* 91.000000 */
