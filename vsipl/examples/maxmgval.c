#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7 /* length */
int main()
{
  int i;
  vsip_vview_d* data;
  vsip_scalar_d mgval;
  vsip_scalar_vi index = 0;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the magnitude of */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), data);
  vsip_vsin_d(data,data);
  printf(" data \n");
  for(i=0; i<L; i++)
    printf("%7.4f\n", vsip_vget_d(data, i));
  /* now find the max and min magnitude value and their index */
  mgval = vsip_vmaxmgval_d(data, &index);
  printf("Max Mag of %7.4f at index %i\n", mgval,(int) index);
  mgval = vsip_vminmgval_d(data, &index);
  printf("Min Mag of %7.4f at index %i\n", mgval,(int) index);
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_finalize((void *)0);
  return 0;
}
/*  output */
/*  0.0000
    0.8660
    0.8660
    0.0000
   -0.8660
   -0.8660
   -0.0000
   Max Mag of 0.8660 at index 5
   Min Mag of 0.0000 at index 0 */
