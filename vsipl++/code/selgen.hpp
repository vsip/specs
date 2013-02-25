<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // selection functions

  // first
  template &lt;typename FnObject,
    typename T1, typename T2,
    typename Block1, typename Block2&gt;
  index_type 
  first(index_type, FnObject,
        const_Vector&lt;T1, Block1&gt;,
        const_Vector&lt;T2, Block2&gt;);

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename T,
            typename Block0, typename Block1&gt;
  length_type 
  indexbool(const_View&lt;T, Block0&gt; source,
            Vector&lt;Index&lt;const_View&lt;T, Block1&gt;::dim&gt;, Block1&gt; indices)
    VSIP_NOTHROW;

  // gather
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename T,
            typename Block0, typename Block1&gt;
  const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt;
  gather(const_View&lt;T, Block0&gt;,
         const_Vector&lt;Index&lt;const_View&lt;T, Block1 &gt;::dim&gt;, Block1&gt;)
    VSIP_NOTHROW;

  // scatter
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename T, typename Block0, typename Block1,
            typename Block2&gt;
  void
  scatter(const_Vector&lt;T, Block0&gt;,
          const_Vector&lt;Index&lt;const_View&lt;T,Block2&gt;::dim&gt;, Block1&gt;,
          typename ViewConversion&lt;const_View, T, Block2&gt;::view_type)
    VSIP_NOTHROW;

  // ramp
  template &lt;typename T&gt;
  const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; 
  ramp(T a, T b, length_type len) VSIP_NOTHROW;

  // clipping and inverse clipping
  template &lt;typename Tout, typename Tin0, typename Tin1,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;Tout, <emphasis>unspecified</emphasis>&gt;
  clip(const_View&lt;Tin0, Block&gt;,
       Tin1 lower_threshold,
       Tin1 upper_threshold,
       Tout lower_clip_value,
       Tout upper_clip_value)
    VSIP_NOTHROW;

  template &lt;typename Tout, typename Tin0, typename Tin1,
            template &lt;typename, typename&gt; class const_View,
            typename Block&gt;
  const_View&lt;Tout, <emphasis>unspecified</emphasis>&gt;
  invclip(const_View&lt;Tin0, Block&gt;,
          Tin1 lower_threshold,
          Tin1 middle_threshold,
          Tin1 upper_threshold,
          Tout lower_clip_value,
          Tout upper_clip_value)
    VSIP_NOTHROW;

  // manipulation functions
  template &lt;typename T0, typename T1,
            template &lt;typename, typename&gt; class View,
            typename Block0, typename Block1&gt;
  void  
  swap(View&lt;T0, Block0&gt;, View&lt;T1, Block1&gt;) VSIP_NOTHROW;
}
</synopsis>
