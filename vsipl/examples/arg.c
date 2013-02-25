#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7    /* length */

int main()
{
  int i;
  vsip_vview_d* dataArg;
  vsip_cvview_d* dataCmplx;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;

  vsip_init((void *)0);
  dataArg = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRe = vsip_vrealview_d(dataCmplx);
  dataIm = vsip_vimagview_d(dataCmplx);
  /* Make up some data to find the arg of */
  /* First compute a ramp from zero to 2pi */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), dataArg);
  /*and transform it to a sin (real) and a cos (imaginary).*/
  vsip_vsin_d(dataArg,dataRe);
  vsip_vcos_d(dataArg,dataIm);
  /* Find the argument */
  vsip_varg_d(dataCmplx,dataArg);
  /*now print out dataCmplex and its argument*/
  for(i=0; i < L; i++)
    printf("(%7.4f, %7.4f) => %7.4f\n",
           vsip_vget_d(dataRe,i),
           vsip_vget_d(dataIm,i),
           vsip_vget_d(dataArg,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataArg));
  vsip_vdestroy_d(dataRe);
  vsip_vdestroy_d(dataIm);
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 0.0000,  1.0000) =>  1.5708
   ( 0.8660,  0.5000) =>  0.5236
   ( 0.8660, -0.5000) => -0.5236
   ( 0.0000, -1.0000) => -1.5708
   (-0.8660, -0.5000) => -2.6180
   (-0.8660,  0.5000) =>  2.6180
   (-0.0000,  1.0000) =>  1.5708 */
