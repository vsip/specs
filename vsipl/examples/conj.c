#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7 /* length */

int main()
{
  int i;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;
  vsip_cvview_d* dataCmplx;
  vsip_cvview_d* dataCmplxConj;
  vsip_cscalar_d cscalar;
  vsip_cscalar_d cconjscalar;

  vsip_init((void *)0);
  dataRe = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataIm = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataCmplxConj = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the complex conjugate of */
  /* First compute a ramp from zero to 2pi */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), dataRe);
  /*and transform it to a sin.*/
  vsip_vsin_d(dataRe,dataRe);
  /* Then compute a ramp from zero to 3pi */
  vsip_vramp_d(0.0, (3.0 * PI / (double) (L - 1)), dataIm);
  /* and transform it to a cos. */
  vsip_vcos_d(dataIm,dataIm);
  /* Finally make a complex vector. */
  vsip_vcmplx_d(dataRe, dataIm, dataCmplx);
  /* Find the Complex Conjugate */
  vsip_cvconj_d(dataCmplx,dataCmplxConj);
  /* now print out dataCmplex and its Conjugate */
  for(i=0; i < L; i++)
  {
    cscalar = vsip_cvget_d(dataCmplx, (vsip_scalar_vi) i);
    cconjscalar = vsip_cvget_d(dataCmplxConj, (vsip_scalar_vi) i);
    printf("(%7.4f, %7.4f) => (%7.4f, %7.4f)\n",cscalar.r, cscalar.i,
           cconjscalar.r, cconjscalar.i);
  }
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRe));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataIm));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplxConj));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 0.0000,  1.0000) => ( 0.0000, -1.0000)
   ( 0.8660,  0.0000) => ( 0.8660, -0.0000)
   ( 0.8660, -1.0000) => ( 0.8660,  1.0000)
   ( 0.0000, -0.0000) => ( 0.0000,  0.0000)
   (-0.8660,  1.0000) => (-0.8660, -1.0000)
   (-0.8660,  0.0000) => (-0.8660, -0.0000)
   (-0.0000, -1.0000) => (-0.0000,  1.0000) */
