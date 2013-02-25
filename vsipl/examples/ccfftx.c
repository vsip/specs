#include <stdio.h>
#include <vsip.h>

#define N 8
#define ACMPLX(x) vsip_real_d(x),\
    (vsip_imag_d(x) < 0.0 ? "-i" : "+i"), fabs(vsip_imag_d(x))
#define SCMPLX "%g%s%g"

int main()
{
  int i;
  vsip_cscalar_d z;
  vsip_randstate *state;
  vsip_scalar_d data[2*N]; /* a public data space for I/O */
  vsip_scalar_d *ptr1, *ptr2; /* for use in release */
  vsip_fft_d *ccfftNip;
  vsip_cblock_d *block;
  vsip_cvview_d *inout;

  /* Initialize Random Number Generator */
  int seed =0, num_procs=1, id=1;

  vsip_init((void *)0);
  state = vsip_randcreate(seed, num_procs, id, VSIP_PRNG);
  ccfftNip = /* Create an in-place Cmplx->Cmplx N-pt FFT */
    vsip_ccfftip_create_d(N, 1.0, VSIP_FFT_FWD, 1, VSIP_ALG_TIME);
  /* Create a block object and bind it to the array data */
  block = vsip_cblockbind_d(data, NULL, N, VSIP_MEM_NONE);
  inout = vsip_cvbind_d(block, 0, 1, N);
  /* Admit block to VSIPL for processing and initialize with
     complex Gaussian noise N(0,1) */
  vsip_cblockadmit_d(block, VSIP_FALSE);
  vsip_cvrandn_d(state, inout);
  printf("\nComplex Input Vector\n");
  for(i=0; i<N; i++) 
  {
    z = vsip_cvget_d(inout, i);
    printf(SCMPLX "\n", ACMPLX(z));
  }
  /* Compute an in-place Cmplx->Cmplx N-pt FFT using the ccfftNip object */
  vsip_ccfftip_d(ccfftNip, inout);
  /* Print it */
  /* Release the block from VSIPL so that data can be directly accessed */
  vsip_cblockrelease_d(block,VSIP_TRUE,&ptr1,&ptr2);
  printf("\nComplex Output Vector (Real, Imag)\n");
  for(i=0; i<N; i++)
    printf("(%g, %g)\n", data[2*i], data[2*i+1]);
  /* Destroy the ccfftNip and block objects */
  vsip_fft_destroy_d(ccfftNip);
  vsip_cvalldestroy_d(inout);
  vsip_randdestroy(state);
  vsip_finalize((void *)0);
  return(0);
}
/* Output */
/* Complex Input Vector
   -0.615549+i0.217406
    0.810217+i1.18112
    1.46004+i0.540183
   -1.27425+i0.688241
   -0.956159-i0.135591
    0.434556-i0.432679
   -0.209061+i0.719197
   -0.0821027-i1.4201
   Complex Output Vector (Real, Imag)
   (-0.432307, 1.35778)
   (3.90216, -1.08846)
   (-1.34239, -3.77869)
   (2.04297, 2.94914)
   (-0.209147, 1.32461)
   (-3.57896, -1.54376)
   (-4.30299, 1.42356)
   (-1.00372, 1.09507) */
