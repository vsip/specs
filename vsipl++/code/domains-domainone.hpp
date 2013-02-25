<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;&gt;
  class Domain&lt;1&gt;
  {
  public:
    // compile-time values
    static dimension_type const dim = 1;

    // constructors, copy, assignment, and destructor
    Domain(index_type, stride_type, length_type) VSIP_NOTHROW;
    Domain(length_type = 0) VSIP_NOTHROW;
    Domain(Domain const &amp;) VSIP_NOTHROW;
    Domain&amp; operator=(Domain const &amp;) VSIP_NOTHROW;
    ~Domain() VSIP_NOTHROW;

    // comparison function
    bool element_conformant(Domain const &amp;) const VSIP_NOTHROW;
    bool product_conformant(Domain&lt;2&gt; const &amp;) const VSIP_NOTHROW;
    
    // accessors
    Domain&lt;1&gt; const &amp;operator[](dimension_type) const
      VSIP_NOTHROW;
    index_type first() const VSIP_NOTHROW;
    stride_type stride() const VSIP_NOTHROW;
    length_type length() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
  };
}
</synopsis>
