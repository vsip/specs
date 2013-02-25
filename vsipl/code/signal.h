<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Hint for how to optimize an object. */
typedef enum 
{
  VSIP_ALG_TIME = 0,  /* Minimize execution time */
  VSIP_ALG_SPACE = 1, /* Minimize memory required */
  VSIP_ALG_NOISE = 2  /* Minimize computational noise, Maximize Accuracy */
} vsip_alg_hint;

/* For filter and convolution kernels, specifies the symmetry of the kernel. */
typedef enum 
{
  VSIP_NONSYM = 0,           /* Non-symmetric */
  VSIP_SYM_EVEN_LEN_ODD = 1, /* (Even) Symmetric, odd length */
  VSIP_SYM_EVEN_LEN_EVEN = 2 /* (Even) Symmetric, even length */
} vsip_symmetry;

/* For filters, convolutions, and correlations; specifies the region over which 
   the output result is computed. */
typedef enum 
{
  VSIP_SUPPORT_FULL = 0, /* Maximum region */
  VSIP_SUPPORT_SAME = 1, /* Input and output same size */
  VSIP_SUPPORT_MIN = 2   /* Region without zero extending the kernel, reference */
} vsip_support_region;</synopsis>
