<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;dimension_type D&gt;
  class Index 
  {
  public:
    static dimension_type const dim = D;

    Index() VSIP_NOTHROW;
    Index(index_type, ..., index_type) VSIP_NOTHROW; // exactly D parameters
    Index(Index const &amp;) VSIP_NOTHROW;
    Index &amp;operator=(Index const &amp;) VSIP_NOTHROW;
    ~Index() VSIP_NOTHROW;

    index_type operator[](dimension_type) const VSIP_NOTHROW;
  };
}
</synopsis>
