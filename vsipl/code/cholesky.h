<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Attribute structure for a Cholesky matrix object. */
typedef struct 
{
  vsip_length n; /* Matrix size is N by N */
} vsip_chol_attr_f;
/* Attribute structure for a complex Cholesky matrix object. */
typedef struct 
{
  vsip_length n; /* Matrix size is N by N */
} vsip_cchol_attr_f;
/* Object type for a Cholesky matrix system. */
struct vsip_choldobject_f;
typedef struct vsip_choldobject_f vsip_chol_f;
/* Object type for a complex Cholesky matrix system. */
struct vsip_ccholdobject_f;
typedef struct vsip_ccholdobject_f vsip_cchol_f;
</synopsis>
