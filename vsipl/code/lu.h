<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Attribute structure for an LU matrix decomposition object. */
typedef struct 
{
  vsip_length n; /* Matrix size is N by N */
} vsip_lu_attr_f;
/* Attribute structure for a complex LU matrix decomposition object. */
typedef struct 
{
  vsip_length n; /* Matrix size is N by N */
} vsip_clu_attr_f;
/* Object type for an LU matrix decomposition. */
struct vsip_luobject_f;
typedef struct vsip_luobject_f vsip_lu_f;
/* Object type for a complex LU matrix decomposition. */
struct vsip_cluobject_f;
typedef struct vsip_cluobject_f vsip_clu_f;</synopsis>
