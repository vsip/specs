#include <stdio.h>
#include "vsip.h"

#define L 7    /* length */

int main()
{
  int i;
  vsip_scalar_d dataScalar = 5.5;
  vsip_vview_d* dataVector;
  vsip_vview_d* dataSub;

  vsip_init((void *)0);
  dataVector = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataSub = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataVector);
  /* Subtract the vectors from the scalar*/
  vsip_svsub_d(dataScalar, dataVector, dataSub);
  /*now print out the data and the result*/
  for(i=0; i < L; i++)
    printf("%7.4f = (%7.4f) - (%7.4f) \n", vsip_vget_d(dataSub,i),
           dataScalar, vsip_vget_d(dataVector,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVector));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataSub));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 4.5000 = ( 5.5000) - ( 1.0000)
   4.8333 = ( 5.5000) - ( 0.6667)
   5.1667 = ( 5.5000) - ( 0.3333)
   5.5000 = ( 5.5000) - ( 0.0000)
   5.8333 = ( 5.5000) - (-0.3333)
   6.1667 = ( 5.5000) - (-0.6667)
   6.5000 = ( 5.5000) - (-1.0000) */
