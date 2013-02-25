<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  enum support_region_type { support_full, support_same, support_min};
  enum symmetry_type { nonsym, sym_even_len_odd, sym_even_len_even};

  template &lt;template &lt;typename, typename&gt; class const_View,
            symmetry_type       S,
            support_region_type R,
            typename            T = VSIP_DEFAULT_VALUE_TYPE,
            unsigned            N = 0,
            alg_hint_type       H = alg_time&gt;
  class Convolution 
  {
  public:
    // compile-time constants
    static symmetry_type const symmtry = S;
    static support_region_type const supprt = R;

    // constructors, copies, assignments, and destructors
    template &lt;typename Block&gt;
    Convolution(const_View&lt;T, Block&gt;,
                Domain&lt;const_View&lt;T, Block&gt;::dim&gt; const &amp;,
                length_type decimation = 1)
      VSIP_THROW((std::bad_alloc));
    Convolution(Convolution const &amp;) VSIP_NOTHROW;
    Convolution &amp;operator=(Convolution const &amp;) VSIP_NOTHROW;
    ~Convolution() VSIP_NOTHROW;

    // accessors
    Domain&lt;const_View::dim&gt; const &amp;kernel_size() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;filter_order() const VSIP_NOTHROW;
    symmetry_type symmetry() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;input_size() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;output_size() const VSIP_NOTHROW;
    support_region_type support() const VSIP_NOTHROW;
    length_type decimation() const VSIP_NOTHROW;

    // Convolution
    template &lt;typename Block0, typename Block1&gt;
    typename ViewConversion&lt;const_View, T, Block1&gt;::view_type
    operator()(const_View&lt;T, Block0&gt;,
               typename ViewConversion&lt;const_View, T, Block1&gt;::view_type)
      VSIP_NOTHROW;
  };
}
</synopsis>
