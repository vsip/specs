#include <stdio.h>
#include <vsip.h>

#define N 8
#define ACMPLX(x) vsip_real_d(x), \
   (vsip_imag_d(x) < 0.0 ? "-i" : "+i"), fabs(vsip_imag_d(x))
#define SCMPLX "%g%s%g"

int main()
{
  int i;
  vsip_cscalar_d z;
  vsip_scalar_d data[N]; /* a public data space for I/O */
  vsip_fft_d *rcfftNop;
  vsip_block_d *block;
  vsip_vview_d *xin;
  vsip_cvview_d *yout;

  vsip_init((void *)0);
  rcfftNop = /* Create an out-of-place Real->Cmplx N-pt FFT */
    vsip_rcfftop_create_d(N, 1.0, 1, VSIP_ALG_TIME);
  /* Create a block object and bind it to the array data */
  block = vsip_blockbind_d(data, N, VSIP_MEM_NONE);
  xin = vsip_vbind_d(block, 0, 1, N);
  /* Create another block and complex vector view for the
     symmetric output */
  yout = vsip_cvcreate_d((N/2)+1, VSIP_MEM_NONE);
  /* Admit block to VSIPL for processing and initialize with a
     linear ramp */
  vsip_blockadmit_d(block, VSIP_FALSE);
  vsip_vramp_d(0.0, 1.0, xin);
  /* Compute an out-of-place Real->Cmplx N-pt FFT using the
     rcfftNop object */
  vsip_rcfftop_d(rcfftNop, xin, yout);
  /* print it */
  printf("Real Input Vector\n");
  for(i=0; i<N; i++) 
  {
    printf("%g\n", vsip_vget_d(xin,i));
  }
  printf("\nComplex Output Vector\n");
  for(i=0; i<(N/2)+1; i++) 
  {
    z = vsip_cvget_d(yout,i);
    printf(SCMPLX "\n", ACMPLX(z));
  }
  /* Destroy the rcfftNop, blocks, and view objects */
  vsip_fft_destroy_d(rcfftNop);
  vsip_valldestroy_d(xin);
  vsip_cvalldestroy_d(yout);
  vsip_finalize((void *)0);
  return(0);
}
