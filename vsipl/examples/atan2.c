#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define N 8             /* length */

int main()
{
  double data[N]; /* a user-created data space */
  int i;
  vsip_vview_d* arg;
  vsip_vview_d* x;
  vsip_vview_d* y;

  vsip_init((void *)0);
  arg = vsip_vbind_d(vsip_blockbind_d(data, N, VSIP_MEM_NONE),0,1,N);
  x = vsip_vcreate_d(N, VSIP_MEM_NONE);
  y = vsip_vcreate_d(N, VSIP_MEM_NONE);

  vsip_vramp_d(0.0, 2 * PI/N, y);
  vsip_vcos_d(y, x);
  vsip_vsin_d(y, y);

  /* admit the user block with no update */
  vsip_blockadmit_d(vsip_vgetblock_d(arg),VSIP_FALSE);
  /*compute the arctan2 value */
  vsip_vatan2_d(y, x, arg);
  /* release the user block with update */
  vsip_blockrelease_d(vsip_vgetblock_d(arg),VSIP_TRUE);
  /*print it */
  for(i=0; i<N; i++)
    printf("%f ",data[i]);
  printf("\n");
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(y));
  vsip_blockdestroy_d(vsip_vdestroy_d(x));
  vsip_blockdestroy_d(vsip_vdestroy_d(arg));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 0.000000 0.785398 1.570796 2.356194 3.141593 -2.356194 -1.570796 -0.785398 */
