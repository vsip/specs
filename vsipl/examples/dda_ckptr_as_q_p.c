#include "stdlib.h"
#include "vsip.h"
#define N 1024
int main(int argc, char **argv)
{
    vsip_scalar_f userArray[2*N];
    vsip_cblock_f *blk;
    vsip_cvview_f *vw;
    vsip_dda_cvdata_f *data;
    vsip_dda_cvdataattr_f attrib;
    vsip_cscalar_f *arrayPtr;
    vsip_scalar_f *interPtr;
    vsip_scalar_f *splitRealPtr, *splitImagPtr;
    vsip_scalar_f *data1ptr, *data2ptr;    
    vsip_init((void *)0);   
    blk = vsip_cblockbind_f(&userArray[0], 0, N, VSIP_MEM_NONE);
        /* TODO: Handle error */
    /* NOTE
     * The block bind call above implies an INTERLEAVED storage format in the
     * user array, but once admitted, the implementation may use a different
     * storage format.
     */
    vsip_cblockadmit_f(blk, 0); /* TODO: Handle error */
    vw = vsip_cvbind_f(blk, 0, 1, N); /* TODO: Handle error */
    /* NOTE
     * No layout is provided when the data object is created, so the view's own
     * layout is used.
     */             
    data = vsip_dda_cvdatacreate_f(vw, 0, VSIP_DDA_SYNC_POLICY_OUT, 0);
    /* TODO: Handle error */
    vsip_dda_cvdatagetattrib_f(data, &attrib); /* TODO: Handle error */   
    /* NOTE
     * Since the layout of the data object is not specified, the data object
     * attributes must retrieved, and the storage format checked, to determine
     * which complex pointer accessor to use.
     */    
    if(VSIP_STORAGE_FORMAT_ARRAY == attrib.layout->storage_format)
    {        
        arrayPtr = vsip_dda_cvptr_as_array_f(data); /* TODO: Handle error */
        arrayPtr[0].r = 1.0F; arrayPtr[0].i = -1.0F;
    }
    else if(VSIP_STORAGE_FORMAT_INTERLEAVED_COMPLEX
        == attrib.layout->storage_format)
    {
        interPtr = vsip_dda_cvptr_as_inter_f(data); /* TODO: Handle error */
        interPtr[0] = 1.0F; interPtr[1] = -1.0F;       
    }
    else if(VSIP_STORAGE_FORMAT_SPLIT_COMPLEX == attrib.layout->storage_format)
    {
        vsip_dda_cvptr_as_split_f(data, &splitRealPtr, &splitImagPtr);
            /* TODO: Handle error */
        splitRealPtr[0] = 1.0F; splitImagPtr[0] = -1.0F;
    }
    vsip_dda_cvdatadestroy_f(data); /* TODO: Handle error */
    /* NOTE
     * Because of the OUT synchronization policy, the proxied view will have
     * been updated with the contents of any DDA buffers.
     */
    vsip_cvdestroy_f(vw); /* TODO: Handle error */
    vsip_cblockrelease_f(blk, 1, &data1ptr, &data2ptr); /* TODO: Handle error */
    vsip_cblockdestroy_f(blk);
    vsip_finalize((void *)0);
    return 0;
}
