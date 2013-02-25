<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;dimension_type D&gt;
  class Domain 
  {
  public:
    // compile-time values
    static dimension_type const dim = D;

    // constructors, copy, assignment, and destructor
    Domain() VSIP_NOTHROW;
    Domain(Domain&lt;1&gt; const &amp;, ..., Domain&lt;1&gt; const &amp;) VSIP_NOTHROW;
    // exactly D parameters
    Domain(Domain const &amp;) VSIP_NOTHROW;
    Domain&amp; operator=(Domain const &amp;) VSIP_NOTHROW;
    ~Domain() VSIP_NOTHROW;

    // comparison functions
    bool element_conformant(Domain const &amp;) const VSIP_NOTHROW;
    bool product_conformant(Domain&lt;2&gt; const &amp;) const VSIP_NOTHROW;
    
    // accessors
    Domain&lt;1&gt; const &amp;operator[](dimension_type) const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
  };
}
</synopsis>
