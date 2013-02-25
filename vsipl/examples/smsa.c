#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_scalar_d dataB;
  vsip_scalar_d dataC;
  vsip_vview_d* dataVsmsa;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVsmsa = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data*/
  vsip_vramp_d(1.0, 1.0 , dataA);
  dataB = 4.5;
  dataC = -1.8;
  /* Multiply A and B and add C */
  vsip_vsmsa_d(dataA, dataB, dataC, dataVsmsa);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f * %7.4f) + %7.4f => %7.4f \n",
           vsip_vget_d(dataA,i),
           dataB,
           dataC,
           vsip_vget_d(dataVsmsa,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVsmsa));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 * 4.5000) + -1.8000 =>  2.7000
   ( 2.0000 * 4.5000) + -1.8000 =>  7.2000
   ( 3.0000 * 4.5000) + -1.8000 => 11.7000
   ( 4.0000 * 4.5000) + -1.8000 => 16.2000
   ( 5.0000 * 4.5000) + -1.8000 => 20.7000
   ( 6.0000 * 4.5000) + -1.8000 => 25.2000
   ( 7.0000 * 4.5000) + -1.8000 => 29.7000 */
