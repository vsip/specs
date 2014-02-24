#include "stdlib.h"
#include "vsip.h"
#define N 1024
int main(int argc, char **argv)
{
    vsip_vview_f *vw;
    vsip_dda_sync_policy pol = VSIP_DDA_SYNC_POLICY_OUT;
    vsip_dda_vdata_f *data;
    vsip_scalar_f *ptr;
    vsip_init((void*)0);
    vw = vsip_vcreate_f(N, VSIP_MEM_NONE); /* TODO: Handle error */
    data = vsip_dda_vdatacreate_f(vw, 0, pol, 0); /* TODO: Handle error */
    ptr = vsip_dda_vptr_f(data); /* TODO: Handle error */
    vsip_vput_f(vw, 0, 0.0F); ptr[0] = 1.0F;
    /* vsip_vget_f(vw, 0) == 0.0 */
    vsip_dda_vsync_out_f(data); /* TODO: Handle error */
    /* vsip_vget_f(vw, 0) == 1.0 */
    vsip_dda_vdatadestroy_f(data); /* TODO: Handle error */
    vsip_valldestroy_f(vw);
    vsip_finalize((void*)0);
    return 0;
}
