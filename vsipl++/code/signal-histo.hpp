<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;template &lt;typename, typename&gt; class const_View = const_Vector,
            typename T = VSIP_DEFAULT_VALUE_TYPE&gt;
  class Histogram 
  {
  public:
    // constructor and destructor
    Histogram(T, T, length_type) VSIP_THROW((std::bad_alloc));
    ~Histogram() VSIP_NOTHROW;

    // operator()
    template &lt;typename Block&gt;
    const_Vector&lt;scalar_i, <emphasis>unspecified</emphasis>&gt; operator() (const_View&lt;T, Block&gt;, bool = false) 
      VSIP_NOTHROW;
  };
}
</synopsis>
