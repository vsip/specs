<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Indicates the major memory direction for a tensor; C style with trailing dimension, 
   or FORTRAN style with the leading dimension. */
typedef enum 
{
  VSIP_TRAILING = 0, /* Trailing dimension, C style */
  VSIP_LEADING = 1   /* Leading Dimension, FORTRAN style */
} vsip_tmajor;

/* Specifies a 2-D slice of a tensor. */
typedef enum 
{
  VSIP_TMYX = 0,  /* Y– X Submatrix */
  VSIP_TMZX = 1,  /* Z– X Submatrix */
  VSIP_TMZY = 2   /* Z– Y Submatrix */
} vsip_tmslice;

/* Specifies a 1-D slice of a tensor.*/
typedef enum 
{
  VSIP_TVX = 0, /* X Subvector */
  VSIP_TVY = 1, /* Y Subvector */
  VSIP_TVZ = 2  /* Z Subvector */
} vsip_tvslice;

typedef enum 
{
  VSIP_TTRANS_NOP = 0,  /* No transpose */
  VSIP_TTRANS_YX = 1,   /* Y – X transpose */
  VSIP_TTRANS_ZY = 2,   /* Z – Y transpose */
  VSIP_TTRANS_ZX = 3,   /* Z – X transpose */
  VSIP_TTRANS_YXZY = 4, /* Y – X &amp; Z – Y transpose */
  VSIP_TTRANS_YXZX = 5  /* Y – X &amp; Z – X transpose */
} vsip_ttrans;</synopsis>
