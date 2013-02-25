<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // dot products
  // [math.matvec.dot]
  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  typename Promotion&lt;complex&lt;T0&gt;, complex&lt;T1&gt; &gt;::type
  cvjdot(const_Vector&lt;complex&lt;T0&gt;, Block0&gt;, 
         const_Vector&lt;complex&lt;T1&gt;, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  typename Promotion&lt;T0, T1&gt;::type
  dot(const_Vector&lt;T0, Block0&gt;,
      const_Vector&lt;T1, Block1&gt;) VSIP_NOTHROW;

  // Transpositions
  // [math.matvec.transpose]
  template &lt;typename T, typename Block&gt;
  const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
  trans(const_Matrix&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T, typename Block&gt;
  const_Matrix&lt;complex&lt;T&gt;, <emphasis>unspecified</emphasis>&gt;
  herm(const_Matrix&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  // Kronecker tensor product
  // [math.matvec.kron]
  template &lt;typename T0, typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_Matrix&lt;typename Promotion&lt;T0, typename Promotion&lt;T1, T2&gt;::type&gt;::type, <emphasis>unspecified</emphasis>&gt;
  kron(T0,
       const_View&lt;T1, Block1&gt;,
       const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  // Outer product
  // [math.matvec.outer]
  template &lt;typename T0, typename T1, typename T2,
            typename Block1, typename Block2&gt;
  const_Matrix&lt;typename Promotion&lt;T0, typename Promotion&lt;T1, T2&gt;::type&gt;::type, <emphasis>unspecified</emphasis>&gt;
  outer(T0,
        const_Vector&lt;T1, Block1&gt;,
        const_Vector&lt;T2, Block2&gt;) VSIP_NOTHROW;

  // Matrix products
  // [math.matvec.product]
  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod(const_Matrix&lt;T0, Block0&gt;,
       const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  const_Vector&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod(const_Matrix&lt;T0, Block0&gt;,
       const_Vector&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Vector&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod(const_Vector&lt;T0, Block0&gt;,
       const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod3(const_Matrix&lt;T0, Block0&gt;,
        const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Vector&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod3(const_Matrix&lt;T0, Block0&gt;,
        const_Vector&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod4(const_Matrix&lt;T0, Block0&gt;,
        const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Vector&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prod4(const_Matrix&lt;T0, Block0&gt;,
        const_Vector&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;complex&lt;T0&gt;, complex&lt;T1&gt; &gt;::type, <emphasis>unspecified</emphasis>&gt;
  prodh(const_Matrix&lt;complex&lt;T0&gt;, Block0&gt;,
        const_Matrix&lt;complex&lt;T1&gt;, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;complex&lt;T0&gt;, complex&lt;T1&gt; &gt;::type, <emphasis>unspecified</emphasis>&gt;
  prodj(const_Matrix&lt;complex&lt;T0&gt;, Block0&gt;,
        const_Matrix&lt;complex&lt;T1&gt;, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1,
            typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  prodt(const_Matrix&lt;T0, Block0&gt;,
        const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  // Generalized Matrix operations
  // [math.matvec.gem]
  template &lt;mat_op_type OpA, mat_op_type OpB,
            typename T0, typename T1, typename T2,
            typename T3, typename T4,
            typename Block1, typename Block2,
            typename Block4&gt;
  void gemp(T0, const_Matrix&lt;T1, Block1&gt;,
            const_Matrix&lt;T2, Block2&gt;, T3,
            Matrix&lt;T4, Block4&gt;) VSIP_NOTHROW;

  template &lt;mat_op_type OpA, mat_op_type OpB,
            typename T0, typename T1,
            typename T3, typename T4,
            typename Block1, typename Block4&gt;
  void gems(T0, const_Matrix&lt;T1, Block1&gt;,
            T3, Matrix&lt;T4, Block4&gt;) VSIP_NOTHROW;

  // Vector-Matrix products
  // [math.matvec.vmmul]
  template &lt;dimension_type d,
            typename T0, typename T1,
            typename Block0, typename Block1&gt;
  const_Matrix&lt;typename Promotion&lt;T0, T1&gt;::type, <emphasis>unspecified</emphasis>&gt;
  vmmul(const_Vector&lt;T0, Block0&gt;,
        const_Matrix&lt;T1, Block1&gt;) VSIP_NOTHROW;

  // Miscellaneous functions
  // [math.matvec.misc]
  template &lt;dimension_type d,
            typename T0, typename T1,
            template &lt;typename, typename&gt; class const_View,
            template &lt;typename, typename&gt; class View,
            typename Block0, typename Block1&gt;
  void
  cumsum(const_View&lt;T0, Block0&gt;, View&lt;T1, Block1&gt;) VSIP_NOTHROW;

  template &lt;typename T0, typename T1, typename T2,
            typename T3, typename Block0, typename Block1&gt;
  T1
  modulate(const_Vector&lt;T0, Block0&gt;, T1, T2,
           Vector&lt;complex&lt;T3&gt;, Block1&gt;) VSIP_NOTHROW;
}</synopsis>
