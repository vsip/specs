<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  using std::complex;
  using std::polar;
  template &lt;typename T1, typename T2&gt;
  void recttopolar(complex&lt;T1&gt; const, T2&amp;, T2&amp;) VSIP_NOTHROW;

  template &lt;typename T1,
            typename T2,
            template &lt;typename&gt; class const_View,
            typename Block0,
            typename Block1,
            typename Block2&gt;
  void recttopolar(const_View&lt;complex&lt;T1&gt;, Block0&gt;,
                   View&lt;T2, Block1&gt;, View&lt;T2, Block2&gt;) VSIP_NOTHROW;

  template &lt;typename T&gt;
  complex&lt;T&gt; polartorect(T const&amp; rho, T const&amp; theta = 0) VSIP_NOTHROW;

  template &lt;typename T,
            typename Block0,
            typename Block1&gt;
  const_View&lt;complex&lt;T&gt;, <emphasis>unspecified</emphasis>&gt; polartorect(const_View&lt;T, Block0&gt;) VSIP_NOTHROW;

  template &lt;typename T,
            typename Block0,
            typename Block1&gt;
  const_View&lt;complex&lt;T&gt;, <emphasis>unspecified</emphasis>&gt;
  polartorect(const_View&lt;T, Block0&gt;, const_View&lt;T, Block1&gt;) VSIP_NOTHROW;
}</synopsis>
