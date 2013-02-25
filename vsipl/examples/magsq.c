#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7    /* length */

int main()
{
  int i;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;
  vsip_vview_d* dataMagsq;
  vsip_cvview_d* dataCmplx;
  vsip_cscalar_d cscalar;

  vsip_init((void *)0);
  dataRe = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataIm = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataMagsq = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the magnitude of */
  /* First compute a ramp from zero to 2pi and apply sin */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), dataRe);
  vsip_vsin_d(dataRe,dataRe);
  /* Then compute a ramp from zero to 3pi and apply cos */
  vsip_vramp_d(0.0, (3.0 * PI / (double) (L - 1)), dataIm);
  vsip_vcos_d(dataIm,dataIm);
  /* Finally make a complex vector. */
  vsip_vcmplx_d(dataRe, dataIm, dataCmplx);
  /* Find the Magnitude */
  vsip_vcmagsq_d(dataCmplx,dataMagsq);
  /*now print out dataCmplex and its arguments*/
  for(i=0; i < L; i++)
  {
    cscalar = vsip_cvget_d(dataCmplx, (vsip_scalar_vi) i);
    printf("(%7.4f, %7.4f) => %7.4f\n",cscalar.r, cscalar.i,
           vsip_vget_d(dataMagsq, (vsip_scalar_vi) i));
  }
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRe));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataIm));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMagsq));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 0.0000,  1.0000) => 1.0000
   ( 0.8660,  0.0000) => 0.7500
   ( 0.8660, -1.0000) => 1.7500
   ( 0.0000, -0.0000) => 0.0000
   (-0.8660,  1.0000) => 1.7500
   (-0.8660,  0.0000) => 0.7500
   (-0.0000, -1.0000) => 1.0000 */
