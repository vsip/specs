#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define N 4       /* length */

int main()
{
  double data[N]; /* a user-created data space */
  int i;
  vsip_vview_d* a;
  vsip_vview_d* x;

  vsip_init((void *)0);
  a = vsip_vbind_d(vsip_blockbind_d(data,N, VSIP_MEM_NONE),0,1,N);
  x = vsip_vcreate_d(N, VSIP_MEM_NONE);
  vsip_vramp_d(PI/4.0,2.0 * PI/N,x);
  /* admit the user block with no update */
  vsip_blockadmit_d(vsip_vgetblock_d(a),VSIP_FALSE);
  /*compute the tan value */
  vsip_vtan_d(x,a);
  /* release the user block with update */
  vsip_blockrelease_d(vsip_vgetblock_d(a),VSIP_TRUE);
  /*print it */
  for(i=0; i < N; i++)
    printf("%f ",data[i]);
  printf("\n");
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(x));
  vsip_blockdestroy_d(vsip_vdestroy_d(a));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 1.000000 -1.000000 1.000000 -1.000000 */
