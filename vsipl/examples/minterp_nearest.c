#include <stdio.h>
#include <vsip.h>

#define VPRINT(_x) { vsip_length L = vsip_vgetlength_f(_x); \
vsip_index i; printf("[\n");			            \
for(i=0; i< L; i++) printf("%5.4f;\n",vsip_vget_f(_x,i));   \
printf("];\n"); }
#define MPRINT(_x) {			  \
vsip_length N = vsip_mgetrowlength_f(_x); \
vsip_length M = vsip_mgetcollength_f(_x); \
vsip_index i,j; printf("[\n");		  \
for(i=0; i< M; i++) { for(j=0; j<N; j++){ \
printf("%5.4f ",vsip_mget_f(_x,i,j));}	  \
printf(";\n");}			          \
printf("];\n"); }

/* Below we implement example from "help interp1" in octave 2.9.9
 * xf=[0:0.05:10]; yf = sin(2*pi*xf/5);
 * xp=[0:10]; yp = sin(2*pi*xp/5);
 * lin=interp1(xp,yp,xf);
 */
int main (int argc, const char * argv[]) 
{
  int retval = vsip_init((void*)0);
  vsip_length N0 = 11;
  vsip_length N = 201;
  vsip_length M = 3;
  vsip_mview_f *yf = vsip_mcreate_f(M,N,VSIP_ROW,VSIP_MEM_NONE);
  vsip_vview_f *xf = vsip_vcreate_f(N,VSIP_MEM_NONE);
  vsip_vview_f *xp = vsip_vcreate_f(N0,VSIP_MEM_NONE);
  vsip_mview_f *yp = vsip_mcreate_f(M,N0,VSIP_COL,VSIP_MEM_NONE);
  vsip_vview_f *yp0 = vsip_mrowview_f(yp,0);
  vsip_vview_f *yp1 = vsip_mrowview_f(yp,1);
  vsip_vview_f *yp2 = vsip_mrowview_f(yp,2);
  vsip_vramp_f(0.0,1.0,xp);
  vsip_vramp_f(0.0,0.05,xf);
  vsip_svmul_f(2.0/5.0 * M_PI,xp,yp0);
  vsip_svadd_f(M_PI/8.0,yp0,yp1);
  vsip_svadd_f(M_PI/8.0,yp1,yp2);
  vsip_vsin_f(yp0,yp0);
  vsip_vsin_f(yp1,yp1);
  vsip_vsin_f(yp2,yp2);
  printf("xp = ");VPRINT(xp);
  printf("yp = ");MPRINT(yp);
  printf("xf = ");VPRINT(xf);
  vsip_minterp_nearest_f(xp,yp,VSIP_ROW,xf,yf);
  printf("nearest = "); MPRINT(yf);
  vsip_vdestroy_f(yp0);
  vsip_vdestroy_f(yp1);
  vsip_vdestroy_f(yp2);
  vsip_valldestroy_f(xf);
  vsip_valldestroy_f(xp);
  vsip_malldestroy_f(yp);
  vsip_malldestroy_f(yf);
  vsip_finalize((void*)0);
  return retval;
}
