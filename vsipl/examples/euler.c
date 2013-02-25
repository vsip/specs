#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7         /* length */

int main()
{
  int i;
  vsip_cvview_d* dataEuler;
  vsip_vview_d* data;

  vsip_init((void *)0);
  dataEuler = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  /* Compute a ramp from zero to 2pi */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), data);
  /* Compute Euler */
  vsip_veuler_d(data,dataEuler);
  /* Now print out data and dataEuler */
  for(i=0; i < L; i++)
  {
    printf(" %7.4f => (%7.4f, %7.4f)\n",vsip_vget_d(data,i),
    vsip_real_d(vsip_cvget_d(dataEuler,i)),
    vsip_imag_d(vsip_cvget_d(dataEuler,i)));
  }
  /* Destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataEuler));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 0.0000 => ( 1.0000,  0.0000)
   1.0472 => ( 0.5000,  0.8660)
   2.0944 => (-0.5000,  0.8660)
   3.1416 => (-1.0000,  0.0000)
   4.1888 => (-0.5000, -0.8660)
   5.2360 => ( 0.5000, -0.8660)
   6.2832 => ( 1.0000, -0.0000) */
