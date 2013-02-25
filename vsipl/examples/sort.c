#include<stdio.h>
#include<vsip.h>
#define NSIZE 10
#define SEED 4
#define PROCS 1
#define ID 1
#define CPRINT(_v) { /* complex vector print macro */\
int i; \
printf("\n[");\
for(i=0; i<vsip_cvgetlength_d(_v); i++){ \
vsip_cscalar_d a = vsip_cvget_d(_v,i); \
printf("(%f, %f) \n", vsip_real_d(a),vsip_imag_d(a)); \
} printf("]\n");}
#define PRINT(_v) { /* real vector print macro */\
int i; \
printf("\n[");\
for(i=0; i<vsip_vgetlength_d(_v); i++){ \
vsip_scalar_d a = vsip_vget_d(_v,i); \
printf("%f\n", a);\
} printf("]\n");}
int main(){
int retval = vsip_init((void*)0);
vsip_length N = NSIZE;
/* create objects */
vsip_cvview_d *cdata_in = vsip_cvcreate_d(N,VSIP_MEM_NONE);
vsip_cvview_d *cdata_sorted =\
vsip_cvcreate_d(N,VSIP_MEM_NONE);
vsip_vview_d *re = vsip_vrealview_d(cdata_in);
vsip_vview_d *im = vsip_vimagview_d(cdata_in);
vsip_vview_d *rdata = vsip_vcreate_d(N,VSIP_MEM_NONE);
vsip_vview_vi *ind = vsip_vcreate_vi(N,VSIP_MEM_NONE);
vsip_randstate *state = \
vsip_randcreate(SEED,PROCS,ID, VSIP_PRNG);
/* make some complex data for cdata_in*/
vsip_vrandn_d(state,re);
vsip_vrandn_d(state,im);
printf("\ninput vector");CPRINT(cdata_in);
/* sort the complex data by magnitude */
vsip_cvmag_d(cdata_in,rdata);
vsip_vsortip_d(rdata,VSIP_SORT_BYVALUE, \
VSIP_SORT_ASCENDING,VSIP_TRUE,ind);
vsip_cvgather_d(cdata_in,ind,cdata_sorted);
printf("\noutput vector"); CPRINT(cdata_sorted);
vsip_cvmag_d(cdata_sorted,rdata);
printf("\nmagnitude of output data");PRINT(rdata);
/* destroy objects */
vsip_randdestroy(state);
vsip_vdestroy_d(re);
vsip_vdestroy_d(im);
vsip_cvalldestroy_d(cdata_in);
vsip_cvalldestroy_d(cdata_sorted);
vsip_valldestroy_d(rdata);
vsip_valldestroy_vi(ind);
vsip_finalize((void*)0);
return retval;
}
/* output */
/* input vector
   [(-1.213093, -0.207605)
   (1.507828, -0.331832)
   (1.683972, -0.671796)
   (0.243529, 0.384777)
   (0.451852, -0.150182)
   (0.973947, -0.927580)
   (0.124482, -0.136170)
   (0.305283, -1.190044)
   (-0.369669, 0.771362)
   (-1.261732, -0.429227)
   ]
   output vector
   [(0.124482, -0.136170)
   (0.243529, 0.384777)
   (0.451852, -0.150182)
   (-0.369669, 0.771362)
   (0.305283, -1.190044)
   (-1.213093, -0.207605)
   (-1.261732, -0.429227)
   (0.973947, -0.927580)
   (1.507828, -0.331832)
   (1.683972, -0.671796)
   ]
   magnitude of output data
   [0.184494
   0.455367
   0.476156
   0.855369
   1.228577
   1.230729
   1.332743
   1.344982
   1.543910
   1.813028
   ] */
