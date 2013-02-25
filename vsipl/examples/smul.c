#include <stdio.h>
#include "vsip.h"

#define L 5

int main()
{
  int i;
  vsip_cvview_d* dataComplex;
  vsip_cscalar_d scalarComplex;
  vsip_cvview_d* dataComplexProduct;

  vsip_init((void *)0);
  dataComplex = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataComplexProduct = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* put some complex data in dataComplex */
  for(i = 0; i < L; i++)
    vsip_cvput_d(dataComplex,i,vsip_cmplx_d((double)(i * i),
                 (double)(i+1)));
  /* define a complex scalar */
  scalarComplex = vsip_cmplx_d(3,4);
  /* Multiply scalarComplex by dataComplex
     and print the input and output */
  vsip_csvmul_d(scalarComplex,dataComplex,dataComplexProduct);
  for(i=0; i < L; i++)
    printf("(%7.4f + %7.4fi) * (%7.4f + %7.4fi) = (%7.4f + %7.4fi)\n",
           vsip_real_d(scalarComplex),
           vsip_imag_d(scalarComplex),
           vsip_real_d(vsip_cvget_d(dataComplex,i)),
           vsip_imag_d(vsip_cvget_d(dataComplex,i)),
           vsip_real_d(vsip_cvget_d(dataComplexProduct,i)),
           vsip_imag_d(vsip_cvget_d(dataComplexProduct,i)));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplex));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplexProduct));
  vsip_finalize((void *)0);
  return 0;
} 
/* output */
/* ( 3.0000 + 4.0000i) * ( 0.0000 + 1.0000i) = (-4.0000 +  3.0000i)
   ( 3.0000 + 4.0000i) * ( 1.0000 + 2.0000i) = (-5.0000 + 10.0000i)
   ( 3.0000 + 4.0000i) * ( 4.0000 + 3.0000i) = ( 0.0000 + 25.0000i)
   ( 3.0000 + 4.0000i) * ( 9.0000 + 4.0000i) = (11.0000 + 48.0000i)
   ( 3.0000 + 4.0000i) * (16.0000 + 5.0000i) = (28.0000 + 79.0000i) */
