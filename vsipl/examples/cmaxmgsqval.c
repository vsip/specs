#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d *dataMagsq;
  vsip_cvview_d *dataCmplx;
  vsip_vview_d *dataRe;
  vsip_vview_d *dataIm;
  vsip_cscalar_d cscalar;
  vsip_scalar_d mgsqval;
  vsip_scalar_vi index = 0;
  
  vsip_init((void *)0);
  dataMagsq = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRe = vsip_vrealview_d(dataCmplx);
  dataIm = vsip_vimagview_d(dataCmplx);
  /* Make up some data to find the magnitude of */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), dataRe);
  vsip_vsin_d(dataRe,dataRe);
  vsip_vramp_d(0.0, (3.0 * PI / (double) (L - 1)), dataIm);
  vsip_vcos_d(dataIm,dataIm);
  vsip_vdestroy_d(dataRe); /*don't need these views any more*/
  vsip_vdestroy_d(dataIm);
  /* Find the Magnitude */
  vsip_vcmagsq_d(dataCmplx,dataMagsq);
  /*now print out dataCmplex an its magnitude squared*/
  printf(" complex vector => Mag Squared\n");
  for(i=0; i<L; i++)
  {
    cscalar = vsip_cvget_d(dataCmplx, (vsip_scalar_vi) i);
    printf("(%7.4f, %7.4f) => %7.4f\n",
           vsip_real_d(cscalar), vsip_imag_d(cscalar),
           vsip_vget_d(dataMagsq, i));
  }
  /* now find the maximum and minimum value and its index */
  mgsqval = vsip_vcmaxmgsqval_d(dataCmplx, &index);
  printf("Max Mag Squared of %7.4f at index %i\n", mgsqval,(int) index);
  mgsqval = vsip_vcminmgsqval_d(dataCmplx, &index);
  printf("Min Mag Squared of %7.4f at index %i\n", mgsqval,(int) index);
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMagsq));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_finalize((void *)0);
  return 0;
}
/*
 complex vector => Mag Squared
 ( 0.0000,  1.0000) => 1.0000
 ( 0.8660,  0.0000) => 0.7500
 ( 0.8660, -1.0000) => 1.7500
 ( 0.0000, -0.0000) => 0.0000
 (-0.8660,  1.0000) => 1.7500
 (-0.8660,  0.0000) => 0.7500
 (-0.0000, -1.0000) => 1.0000
 Max Mag Squared of 1.7500 at index 2
 Min Mag Squared of 0.0000 at index 3 */
