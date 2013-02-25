#include <stdio.h>
#include "vsip.h"

#define L 7         /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_scalar_d dataB;
  vsip_vview_d* dataC;
  vsip_vview_d* dataVsam;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataC = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVsam = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data*/
  /* First compute some ramps */
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, .25 , dataC);
  /* and make up a scalar */
  dataB = 4.5;
  /* Add A and B and Multiply C */
  vsip_vsam_d(dataA, dataB, dataC, dataVsam);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f + %7.4f) * %7.4f => %7.4f \n",
           vsip_vget_d(dataA,i),
           dataB,
           vsip_vget_d(dataC,i),
           vsip_vget_d(dataVsam,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataC));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVsam));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 + 4.5000) * 1.0000 =>  5.5000
   ( 2.0000 + 4.5000) * 1.2500 =>  8.1250
   ( 3.0000 + 4.5000) * 1.5000 => 11.2500
   ( 4.0000 + 4.5000) * 1.7500 => 14.8750
   ( 5.0000 + 4.5000) * 2.0000 => 19.0000
   ( 6.0000 + 4.5000) * 2.2500 => 23.6250
   ( 7.0000 + 4.5000) * 2.5000 => 28.7500 */
