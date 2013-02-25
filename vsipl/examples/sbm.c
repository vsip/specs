#include <stdio.h>
#include "vsip.h"

#define L 7 /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_vview_d* dataC;
  vsip_vview_d* dataVsbm;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataC = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVsbm = vsip_vcreate_d(L, VSIP_MEM_NONE);

  /* Make up some data*/
  /* First compute a ramp from One to L */
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, .25 , dataB);
  vsip_vramp_d(1.0, -1.5 , dataC);
  /* Subtract A and B and multiply times C */
  vsip_vsbm_d(dataA, dataB, dataC, dataVsbm);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f - %7.4f) * %7.4f => %7.4f \n",
           vsip_vget_d(dataA,i),
           vsip_vget_d(dataB,i),
           vsip_vget_d(dataC,i),
           vsip_vget_d(dataVsbm,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataC));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVsbm));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 - 1.0000) *  1.0000 =>   0.0000
   ( 2.0000 - 1.2500) * -0.5000 =>  -0.3750
   ( 3.0000 - 1.5000) * -2.0000 =>  -3.0000
   ( 4.0000 - 1.7500) * -3.5000 =>  -7.8750
   ( 5.0000 - 2.0000) * -5.0000 => -15.0000
   ( 6.0000 - 2.2500) * -6.5000 => -24.3750
   ( 7.0000 - 2.5000) * -8.0000 => -36.0000 */
