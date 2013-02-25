#include <stdio.h>
#include "vsip.h"
#define L 7       /* length */
int main()
{
  double data[L]; /* a user-defined data space */
  int i;
  vsip_vview_d* ramp;
  vsip_vview_d* output;
  vsip_init((void *)0);
  ramp = vsip_vcreate_d(L,VSIP_MEM_NONE);
  output = vsip_vbind_d(vsip_blockbind_d(data, L, VSIP_MEM_NONE),0,1,L);
  /* admit the user block with no update */
  vsip_blockadmit_d(vsip_vgetblock_d(output),VSIP_FALSE);
  /*compute a ramp from -1 to 1 */
  vsip_vramp_d(-1.0, 2.0/(L-1) , ramp);
  /*compute the Arccosine value */
  vsip_vasin_d(ramp, output);
  /* release the user block with update */
  vsip_blockrelease_d(vsip_vgetblock_d(output),VSIP_TRUE);
  /*print it */
  for(i=0; i<L; i++)
    printf("%f ",data[i]);
  printf("\n");
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(ramp));
  vsip_blockdestroy_d(vsip_vdestroy_d(output));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* -1.570796 -0.729728 -0.339837 0.000000 0.339837 0.729728 1.570796 */
