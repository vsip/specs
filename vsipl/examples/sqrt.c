#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define N 8   /* length */
int main()
{
  vsip_scalar_d R = 2.0;
  vsip_scalar_d dataR[N]; /* a user created data space for real */
  vsip_scalar_d dataI[N]; /* a user created data space for imaginary */
  int i;
  vsip_vview_d* radius;
  vsip_vview_d* arg;
  vsip_cvview_d* cVsipVector;
  vsip_cblock_d* UsrBlock;
  vsip_cvview_d* cUsrVector;

  vsip_init((void *)0);
  radius = vsip_vcreate_d(N, VSIP_MEM_NONE);
  arg = vsip_vcreate_d(N, VSIP_MEM_NONE);
  cVsipVector = vsip_cvcreate_d(N, VSIP_MEM_NONE);
  UsrBlock = vsip_cblockbind_d(dataR,dataI, N, VSIP_MEM_NONE);
  cUsrVector = vsip_cvbind_d(UsrBlock, 0,1,N);
  /* Admit the user block as Complex data */
  vsip_cblockadmit_d(UsrBlock,VSIP_FALSE);
  /* compute arg */
  vsip_vramp_d(0.0, (2.0 * PI / (double) N ), arg);
  /* compute radius */
  vsip_vfill_d(R, radius);
  /* make the input vector */
  vsip_veuler_d(arg,cVsipVector);
  vsip_rcvmul_d(radius, cVsipVector, cVsipVector);
  /* compute the sqrt value */
  vsip_cvsqrt_d(cVsipVector,cUsrVector);
  /* release the usr block */
  { 
    vsip_scalar_d *a,*b;
    vsip_cblockrelease_d(UsrBlock, VSIP_TRUE, &a, &b);
  }
  /* print it */
  for(i=0; i < N; i++)
    printf("%7.4f + %7.4fi = sqrt(%7.4f + %7.4fi) \n",
           dataR[i],dataI[i],
           vsip_real_d(vsip_cvget_d(cVsipVector,i)),
           vsip_imag_d(vsip_cvget_d(cVsipVector,i)));
  /* destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(radius));
  vsip_blockdestroy_d(vsip_vdestroy_d(arg));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cUsrVector));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cVsipVector));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/*
1.4142 + 0.0000i = sqrt( 2.0000 + 0.0000i)
1.3066 + 0.5412i = sqrt( 1.4142 + 1.4142i)
1.0000 + 1.0000i = sqrt( 0.0000 + 2.0000i)
0.5412 + 1.3066i = sqrt(-1.4142 + 1.4142i)
0.0000 + 1.4142i = sqrt(-2.0000 + 0.0000i)
0.5412 + -1.3066i = sqrt(-1.4142 + -1.4142i)
1.0000 + -1.0000i = sqrt(-0.0000 + -2.0000i)
1.3066 + -0.5412i = sqrt( 1.4142 + -1.4142i) */
