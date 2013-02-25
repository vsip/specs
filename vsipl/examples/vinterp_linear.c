#include <stdio.h>
#include <vsip.h>

#define VPRINT(_x) { vsip_length L = vsip_vgetlength_f(_x); \
vsip_index i; printf("[\n");			            \
for(i=0; i< L; i++) printf("%5.4f;\n",vsip_vget_f(_x,i));   \
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
  vsip_vview_f *yf = vsip_vcreate_f(N,VSIP_MEM_NONE);
  vsip_vview_f *xf = vsip_vcreate_f(N,VSIP_MEM_NONE);
  vsip_vview_f *xp = vsip_vcreate_f(N0,VSIP_MEM_NONE);
  vsip_vview_f *yp = vsip_vcreate_f(N0,VSIP_MEM_NONE);
  vsip_vramp_f(0.0,1.0,xp);
  vsip_vramp_f(0.0,0.05,xf);
  vsip_svmul_f(2.0/5.0 * M_PI,xp,yp);
  vsip_vsin_f(yp,yp);
  printf("xp = ");VPRINT(xp);
  printf("yp = ");VPRINT(yp);
  printf("xf = ");VPRINT(xf);
  vsip_vinterp_linear_f(xp,yp,xf,yf);
  printf("linear = "); VPRINT(yf);

  vsip_valldestroy_f(xf);
  vsip_valldestroy_f(xp);
  vsip_valldestroy_f(yp);
  vsip_valldestroy_f(yf);
  vsip_finalize((void*)0);
  return retval;
}
