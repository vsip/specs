#include "stdlib.h"
#include "vsip.h"
#define N 1024
int main(int argc, char **argv)
{
    vsip_vview_f *vw;
    vsip_scalar_f *buf = 0;
    vsip_dda_sync_policy pol = VSIP_DDA_SYNC_POLICY_IN;
    vsip_length reqsz;
    vsip_dda_vdata_f *data;
    vsip_init((void*)0);
    vw = vsip_vcreate_f(N, VSIP_MEM_NONE); /* TODO: Handle error */
    if(0 != (reqsz = vsip_dda_vrequired_buffer_size_f(vw, 0, pol)))
        buf = malloc(reqsz * sizeof(vsip_scalar_f));
    data = vsip_dda_vdatacreate_f(vw, 0, pol, buf); /* TODO: Handle error */
    /* TODO : Operate on the data object */
    vsip_dda_vdatadestroy_f(data); /* TODO: Handle error */
    vsip_valldestroy_f(vw);
    vsip_finalize((void*)0);
    return 0;
}
