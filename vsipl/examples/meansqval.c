#include <stdio.h>
#include "vsip.h"

#define L 7    /* length */

int main()
{
  vsip_vview_d* data;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the mean square value of */
  /* Compute a ramp from zero to L-1 */
  vsip_vramp_d(0.0, 1.0, data);
  /* And find and print its mean square value */
  printf("%f \n",vsip_vmeansqval_d(data));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 13.000000 */
