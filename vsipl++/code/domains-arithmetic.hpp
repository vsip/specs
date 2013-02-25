<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // shift the initial index
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator+(Domain&lt;D&gt; const &amp;, index_difference_type) VSIP_NOTHROW;
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator+(index_difference_type, Domain&lt;D&gt; const &amp;) VSIP_NOTHROW;
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator-(Domain&lt;D&gt; const &amp;, index_difference_type) VSIP_NOTHROW;

  // modify the stride
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator*(Domain&lt;D&gt; const &amp;, stride_scalar_type) VSIP_NOTHROW;
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator*(stride_scalar_type, Domain&lt;D&gt; const &amp;) VSIP_NOTHROW;
  template &lt;dimension_type D&gt;
  Domain&lt;D&gt; operator/(Domain&lt;D&gt; const &amp;, stride_scalar_type) VSIP_NOTHROW;
}
</synopsis>
