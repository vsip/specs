#include <stdio.h>
#include "vsip.h"

#define L 7    /* length */

int main()
{
  double data[L]; /* a user-created data space */
  int i;
  vsip_vview_d* ramp;
  vsip_vview_d* output;
  
  vsip_init((void *)0);
  ramp = vsip_vcreate_d(L, VSIP_MEM_NONE);
  output = vsip_vbind_d(vsip_blockbind_d(data,L, VSIP_MEM_NONE),0,1,L);
  /*compute a ramp from zero to L-1*/
  vsip_vramp_d(0.0, 1.0, ramp);
  /* admit the user block with no update */
  vsip_blockadmit_d(vsip_vgetblock_d(output),VSIP_FALSE);
  /*compute the hyperbolic sine value */
  vsip_vsinh_d(ramp, output);
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
/* 0.000000 1.175201 3.626860 10.017875 27.289917 74.203211 201.713157 */
