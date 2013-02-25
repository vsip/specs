<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // type promotion traits
  template &lt;typename, typename&gt;
  class Promotion;

  // scalar functions and element-wise extensions
  // [math.fns.scalar] and [math.fns.elementwise]

  //acos
  template &lt;typename T&gt;
  T acos(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  acos(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //add, +
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  add(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  add(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  operator+(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator+(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //am
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2, typename Block3&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  am(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;,
     const_View&lt;T3, Block3&gt;) VSIP_NOTHROW;

  //land, band, &amp;&amp;, &amp;
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  land(const_View&lt;bool, Block1&gt;,
       const_View&lt;bool, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  band(const_View&lt;T1, Block1&gt;,
       const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator&amp;&amp;(const_View&lt;bool, Block1&gt;, const_View&lt;bool, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator&amp;(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //arg
  template &lt;typename T&gt;
  T arg(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  arg(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  //asin
  template &lt;typename T&gt;
  T asin(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  asin(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //atan, atan2
  template &lt;typename T&gt;
  T atan(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  atan(const_View&lt;T, Block&gt;) VSIP_NOTHROW;
  
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  atan2(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  atan2(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //ceil
  template &lt;typename T&gt;
  T ceil(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  ceil(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //cmplx
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;complex&lt;typename Promotion&lt;T1, T2&gt;::type&gt;,
             <emphasis>unspecified</emphasis>&gt;
  cmplx(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //conj
  template &lt;typename T&gt;
  complex&lt;T&gt;
  conj(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;complex&lt;T&gt;, <emphasis>unspecified</emphasis>&gt;
  conj(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  //cos
  template &lt;typename T&gt;
  T cos(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  cos(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //cosh
  template &lt;typename T&gt;
  T cosh(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  cosh(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //div, /
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  div(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  div(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  operator/(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator/(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //eq, ==
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  eq(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator==(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //euler
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;complex&lt;T&gt;, <emphasis>unspecified</emphasis>&gt;
  euler(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //exp, exp10
  template &lt;typename T&gt;
  T exp(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  exp(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  T exp10(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  exp10(const_View&lt;T, Block&gt;) VSIP_NOTHROW;
  
  //floor
  template &lt;typename T&gt;
  T floor(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  floor(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //fmod
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  fmod(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  fmod(const_View&lt;T1, Block1&gt;,
       const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //ge, &gt;=
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  ge(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator&gt;=(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //gt, &gt;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  gt(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator&gt;(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //hypot
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  hypot(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  hypot(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //imag
  template &lt;typename T&gt;
  T imag(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  imag(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  //jmul
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  jmul(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  jmul(const_View&lt;T1, Block1&gt;,
       const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //le, &lt;=
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  le(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator&lt;=(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //log, log10
  template &lt;typename T&gt;
  T log(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  log(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  T log10(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  log10(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //lt, &lt;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  lt(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator&lt;(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //ma
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2, typename Block3&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  ma(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;,
     const_View&lt;T3, Block3&gt;) VSIP_NOTHROW;

  //mag, magsq
  template &lt;typename T&gt;
  T mag(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  mag(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  T mag(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  mag(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  T magsq(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  magsq(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  //max, maxmg, maxmgsq
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  max(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  max(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  maxmg(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  maxmgsq(const_View&lt;complex&lt;T1&gt;, Block1&gt;, const_View&lt;complex&lt;T2&gt;, Block2&gt;) VSIP_NOTHROW;

  //min, minmg, minmgsq
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  min(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  min(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  minmg(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  minmgsq(const_View&lt;complex&lt;T1&gt;, Block1&gt;, const_View&lt;complex&lt;T2&gt;, Block2&gt;) VSIP_NOTHROW;

  //msb
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2, typename Block3&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  msb(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;,
      const_View&lt;T3, Block3&gt;) VSIP_NOTHROW;

  //mul, *
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  mul(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  mul(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  operator*(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator*(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //ne, !=
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  ne(const_View&lt;T1, Block1&gt;,
     const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator!=(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //neg, -
  template &lt;typename T&gt;
  T neg(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  neg(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  T operator-(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  operator-(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //lnot, bnot, !, ~
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  lnot(const_View&lt;bool, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  bnot(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator!(const_View&lt;bool, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator~(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //lor, bor, ||, |
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  lor(const_View&lt;bool, Block1&gt;,
      const_View&lt;bool, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  bor(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  operator||(const_View&lt;bool, Block1&gt;,
             const_View&lt;bool, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator|(const_View&lt;T1, Block1&gt;,
            const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //pow
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  pow(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  pow(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //real
  template &lt;typename T&gt;
  T real(complex&lt;T&gt; const&amp;) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  real(const_View&lt;complex&lt;T&gt;, Block&gt;) VSIP_NOTHROW;

  //recip
  template &lt;typename T&gt;
  T recip(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  recip(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //rsqrt
  template &lt;typename T&gt;
  T rsqrt(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  rsqrt(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sbm
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2, typename Block3&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  sbm(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;,
      const_View&lt;T3, Block3&gt;) VSIP_NOTHROW;

  //sin
  template &lt;typename T&gt;
  T sin(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  sin(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sinh
  template &lt;typename T&gt;
  T sinh(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  sinh(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sq
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  sq(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sqrt
  template &lt;typename T&gt;
  T sqrt(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  sqrt(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sub, -
  template &lt;typename T1, typename T2&gt;
  typename Promotion&lt;T1, T2&gt;::type
  sub(T1, T2) VSIP_NOTHROW;
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  sub(const_View&lt;T1, Block1&gt;,
      const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator-(const_View&lt;T1, Block1&gt;,
            const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  //tan
  template &lt;typename T&gt;
  T tan(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  tan(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //tanh
  template &lt;typename T&gt;
  T tanh(T) VSIP_NOTHROW;
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>&gt;
  tanh(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //lxor, bxor, ^
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;bool, <emphasis>unspecified</emphasis>&gt;
  lxor(const_View&lt;bool, Block1&gt;,
       const_View&lt;bool, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  bxor(const_View&lt;T1, Block1&gt;,
       const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator^(const_View&lt;T1, Block1&gt;,
            const_View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  // element-wise extensions with scalars
  // [math.fns.scalarview]
  //add, +
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  add(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator+(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  //am
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1, typename
             Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  am(const_View&lt;T1, Block1&gt;,
     T2,
     const_View&lt;T3, Block2&gt;) VSIP_NOTHROW;

  //div, /
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  div(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  div(const_View&lt;T1, Block&gt;, T2) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator/(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator/(const_View&lt;T1, Block&gt;, T2) VSIP_NOTHROW;

  //expoavg
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  expoavg(T1, const_View&lt;T2, Block1&gt;, const_View&lt;T3, Block2&gt;) VSIP_NOTHROW;

  //ma
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  ma(const_View&lt;T1, Block&gt;, T2, T3) VSIP_NOTHROW;
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  ma(const_View&lt;T1, Block1&gt;, T2, const_View&lt;T3, Block2&gt;) VSIP_NOTHROW;
  template &lt;typename T1, typename T2, typename T3,
            template &lt;typename, typename&gt; class const_View, 
            typename Block1, typename Block2&gt;
  const_View&lt;typename Promotion&lt;T1,
             typename Promotion&lt;T2, T3&gt;::type&gt;::type,
             <emphasis>unspecified</emphasis>&gt;
  ma(const_View&lt;T1, Block1&gt;, const_View&lt;T2, Block2&gt;, T3) VSIP_NOTHROW;

  //mul, *
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  mul(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator*(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  //sub, -
  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  sub(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T1, typename T2,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename Promotion&lt;T1, T2&gt;::type, <emphasis>unspecified</emphasis>&gt;
  operator-(T1, const_View&lt;T2, Block&gt;) VSIP_NOTHROW;

  // Element-wise extensions of user-specified functions
  // [math.fns.userelt]
  //unary
  template &lt;typename OutputType,
            typename UnaryFunction,
            template &lt;typename, typename&gt; class const_View,
            typename InputType,
            typename Block&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  unary(UnaryFunction f, const_View&lt;InputType, Block&gt;);

  template &lt;typename OutputType,
            template &lt;typename, typename&gt; class const_View,
            typename InputType,
            typename Block&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  unary(OutputType (*)(InputType), const_View&lt;InputType, Block&gt;);

  template &lt;typename UnaryFunction,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;typename UnaryFunction::result_type, <emphasis>unspecified</emphasis>&gt;
  unary(UnaryFunction, 
        const_View&lt;typename UnaryFunction::argument_type, Block&gt;);

  //binary
  template &lt;typename OutputType,
            typename BinaryFunction,
            template &lt;typename, typename&gt; class const_View,
            typename InputType0,
            typename Block0,
            typename InputType1,
            typename Block1&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  binary(BinaryFunction f,
         const_View&lt;InputType0, Block0&gt;,
         const_View&lt;InputType1, Block1&gt;);

  template &lt;typename OutputType,
            template &lt;typename, typename&gt; class const_View,
            typename InputType0,
            typename Block0,
            typename InputType1,
            typename Block1&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  binary(OutputType (*)(InputType0, InputType1),
         const_View&lt;InputType0, Block0&gt;,
         const_View&lt;InputType1, Block1&gt;);

  template &lt;typename BinaryFunction,
            template &lt;typename, typename&gt; class const_View,
            typename Block0,
            typename Block1&gt;
  const_View&lt;typename BinaryFunction::result_type, <emphasis>unspecified</emphasis>&gt;
  binary(BinaryFunction,
         const_View&lt;typename BinaryFunction::first_argument_type, Block0&gt;,
         const_View&lt;typename BinaryFunction::second_argument_type, Block1&gt;);

  //ternary
  template &lt;typename OutputType,
            typename TernaryFunction,
            template &lt;typename, typename&gt; class const_View,
            typename InputType0,
            typename Block0,
            typename InputType1,
            typename Block1,
            typename InputType2,
            typename Block2&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  ternary(TernaryFunction f,
          const_View&lt;InputType0, Block0&gt;,
          const_View&lt;InputType1, Block1&gt;,
          const_View&lt;InputType2, Block2&gt;);

  template &lt;typename OutputType,
            template &lt;typename, typename&gt; class const_View,
            typename InputType0,
            typename Block0,
            typename InputType1,
            typename Block1,
            typename InputType2,
            typename Block2&gt;
  const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
  ternary(OutputType (*)(InputType0, InputType1, InputType2),
          const_View&lt;InputType0, Block0&gt;,
          const_View&lt;InputType1, Block1&gt;,
          const_View&lt;InputType2, Block2&gt;);

  // Reduction functions
  // [math.fns.reductions]
  //alltrue
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T alltrue(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //anytrue
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T anytrue(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //meanval, meansqval
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T meanval(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T meansqval(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  //sumval, sumsqval
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T sumval(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  template &lt;template &lt;typename, typename&gt; class const_View, typename Block&gt;
  length_type
  sumval(const_View&lt;bool, Block&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T sumsqval(const_View&lt;T, Block&gt;) VSIP_NOTHROW;

  // Reduction functions also returning indices
  // [math.fns.reductidx]
  //maxmgsqval, maxmgval, maxval
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T maxmgsqval(const_View&lt;complex&lt;T&gt;, Block&gt;,
               Index&lt;View&lt;complex&lt;T&gt;, Block&gt;::dim&gt;&amp;)
    VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T maxmgval(const_View&lt;complex&lt;T&gt;, Block&gt;,
             Index&lt;View&lt;complex&lt;T&gt;, Block&gt;::dim&gt;&amp;)
    VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T maxval(const_View&lt;T, Block&gt;, Index&lt;View&lt;T, Block&gt;::dim&gt;&amp;) VSIP_NOTHROW;

  //minmgsqval, minmgval, minval
  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T minmgsqval(const_View&lt;complex&lt;T&gt;, Block&gt;,
               Index&lt;View&lt;complex&lt;T&gt;, Block&gt;::dim&gt;&amp;)
    VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T minmgval(const_View&lt;complex&lt;T&gt;, Block&gt;,
             Index&lt;View&lt;complex&lt;T&gt;, Block&gt;::dim&gt;&amp;)
    VSIP_NOTHROW;

  template &lt;typename T,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  T minval(const_View&lt;T, Block&gt;, Index&lt;View&lt;T, Block&gt;::dim&gt;&amp;) VSIP_NOTHROW;
}</synopsis>
