#include <stdio.h>
#include "vsip.h"

#define L 5
#define denom (vsip_scalar_d)10

int main()
{
  int i;
  /* define some data space */
  vsip_cvview_d* dataComplex;
  vsip_cvview_d* dataComplexQuotient;

  vsip_init((void *)0);
  dataComplex = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataComplexQuotient = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* put some complex data in dataComplex */
  for(i = 0; i < L; i++)
    vsip_cvput_d(dataComplex,i,
                 vsip_cmplx_d((double)(i * i),(double)(i+1)));
  /*divide dataComplex by some denom and print the input and output */
  vsip_cvrsdiv_d(dataComplex,denom,dataComplexQuotient);
  for(i=0; i<L; i++)
    printf("(%7.4f + %7.4fi) / %7.4f) = (%7.4f + %7.4fi)\n",
           vsip_real_d(vsip_cvget_d(dataComplex,i)),
           vsip_imag_d(vsip_cvget_d(dataComplex,i)),
           denom,
           vsip_real_d(vsip_cvget_d(dataComplexQuotient,i)),
           vsip_imag_d(vsip_cvget_d(dataComplexQuotient,i)));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplex));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplexQuotient));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 0.0000 + 1.0000i) / 10.0000 = ( 0.0000 + 0.1000i)
   ( 1.0000 + 2.0000i) / 10.0000 = ( 0.1000 + 0.2000i)
   ( 4.0000 + 3.0000i) / 10.0000 = ( 0.4000 + 0.3000i)
   ( 9.0000 + 4.0000i) / 10.0000 = ( 0.9000 + 0.4000i)
   (16.0000 + 5.0000i) / 10.0000 = ( 1.6000 + 0.5000i) */
