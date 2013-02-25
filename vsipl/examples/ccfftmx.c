#include <stdio.h>
#include <vsip.h>

#define ROWS 64
#define N 16
#define ACMPLX(x) vsip_real_d(x),\
   (vsip_imag_d(x) < 0.0 ? "-i" : "+i"), fabs(vsip_imag_d(x))
#define SCMPLX "%g%s%g"

int main()
{
  int i;
  vsip_randstate *state;
  vsip_cmview_d *xy;
  vsip_cvview_d *xy_row;
  vsip_length stride;
  vsip_cvview_d *sum;
  vsip_fftm_d *ccfftmip;
  vsip_length seed =0, num_procs=1, id=1;

  vsip_init((void *)0);
  /* Initialize Random Number Generator */
  state = vsip_randcreate(seed, num_procs, id, VSIP_PRNG);
  /* Row major, 64 (ROWS) of 16 point data vectors */
  xy = vsip_cmcreate_d(ROWS, 16, VSIP_ROW, VSIP_MEM_NONE);
  /* Bind xy_row view initially to row 0 of xy */
  xy_row = vsip_cmrowview_d(xy, 0);
  /* Stride between column elements of xy */
  stride = vsip_cmgetcolstride_d(xy);
  sum = vsip_cvcreate_d(N, VSIP_MEM_NONE);
  /* Create an in-place Cmplx->Cmplx Multiple N-pt FFT */
  ccfftmip = vsip_ccfftmip_create_d(ROWS, N, 1.0, VSIP_FFT_FWD,
				    VSIP_ROW, 1, VSIP_ALG_TIME);
  /* Initialize xy by rows with complex Gaussian noise N(0,1) */
  for (i=0; i<ROWS; i++) 
  {
    vsip_cvputoffset_d(xy_row, i*stride); /* view of row i of xy */
    vsip_cvrand_d(state,xy_row); /* Initialize row i of xy */
  }
  /* Compute an in-place Cmplx->Cmplx Multiple N-pt FFT using the
     ccfftmip object*/
  vsip_ccfftmip_d(ccfftmip, xy);
  /* Coherently sum the rows together (in the Freq domain) */
  vsip_cvputoffset_d(xy_row, 0);
  vsip_cvcopy_d_d(xy_row, sum); /* sum = row 0 of xy */
  for (i=1; i<ROWS; i++)
  {
    vsip_cvputoffset_d(xy_row, i*stride); /* view of row i of xy */
    vsip_cvadd_d(xy_row, sum, sum); /* sum += row i of xy */
  }
  /* Print it */
  printf("\nComplex Output Vector (Real, Imag)\n");
  for(i=0; i<N; i++)
    printf("%d:\t" SCMPLX "\n", i, ACMPLX(vsip_cvget_d(sum,i)));
  printf("\n");
  /* Destroy all the objects */
  vsip_fftm_destroy_d(ccfftmip);
  vsip_cvdestroy(xy_row);
  vsip_cvdestroy(sum);
  vsip_cmalldestroy_d(xy);
  vsip_randdestroy(state);
  vsip_finalize((void *)0);
  return(0);
}
