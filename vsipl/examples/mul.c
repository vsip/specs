#include <stdio.h>
#include"vsip.h"

#define L 7 /* length */

int main()
{
  int i;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;
  vsip_cvview_d* cvectorMul;
  vsip_cvview_d* cvectorLeft;
  vsip_cvview_d* cvectorRight;
  vsip_cscalar_d cscalar,cLeft,cRight;

  vsip_init((void *)0);
  dataRe = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataIm = vsip_vcreate_d(L, VSIP_MEM_NONE);
  cvectorMul = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  cvectorLeft = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  cvectorRight = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to use for a vector multiply */
  vsip_vramp_d(1.0, 1.0 , dataRe);
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataIm);
  vsip_vcmplx_d(dataRe, dataIm, cvectorLeft);
  /* We will just use a simple constant vector for the right */
  cscalar = vsip_cmplx_d(2,1);
  vsip_cvfill_d(cscalar, cvectorRight);
  /* Now multiply the two vectors */
  vsip_cvmul_d(cvectorLeft,cvectorRight,cvectorMul);
  /* and print out the data and the Result */
  for(i=0; i < L; i++)
  {
    cLeft = vsip_cvget_d(cvectorLeft, i);
    cRight = vsip_cvget_d(cvectorRight, i);
    cscalar = vsip_cvget_d(cvectorMul, i);
    printf("(%7.4f + %7.4fi) * (%7.4f + %7.4fi) = (%7.4f + %7.4fi)\n",
           vsip_real_d(cLeft),vsip_imag_d(cLeft),
           vsip_real_d(cRight),vsip_imag_d(cRight),
           vsip_real_d(cscalar),vsip_imag_d(cscalar));
  }
  /* and don't forget to recover memory */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRe));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataIm));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cvectorLeft));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cvectorRight));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cvectorMul));
  vsip_finalize((void *)0);
  return 0;
}
