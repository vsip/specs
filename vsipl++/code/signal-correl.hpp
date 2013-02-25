<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{

  enum matrix_type { biased, unbiased};

  template &lt;template &lt;typename, typename&gt; class const_View,
            support_region_type R,
            typename            T = VSIP_DEFAULT_VALUE_TYPE,
            unsigned            N = 0,
            alg_hint_type       H = alg_time&gt;
  class Correlation 
  {
  public:
    // compile-time constants and declarations
    static support_region_type const supprt = R;

    // constructors, copies, assignments, and destructor
    Correlation(Domain&lt;const_View::dim&gt; const &amp;,
                Domain&lt;const_View::dim&gt; const &amp;)
      VSIP_THROW((std::bad_alloc));
    Correlation(Correlation const &amp;) VSIP_NOTHROW;
    Correlation &amp;operator=(Correlation const &amp;) VSIP_NOTHROW;
    ~Correlation() VSIP_NOTHROW;

    // accessors
    Domain&lt;const_View::dim&gt; const &amp;reference_size() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;input_size() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;output_size() const VSIP_NOTHROW;
    support_region_type support() const VSIP_NOTHROW;

    // Correlation
    template &lt;typename Block0, typename Block1, typename Block2&gt;
    typename ViewConversion&lt;const_View, T, Block2&gt;::view_type
    operator()(matrix_type output_bias,
               const_View&lt;T, Block0&gt;, const_View&lt;T, Block1&gt;,
               typename ViewConversion&lt;const_View, T, Block2&gt;::view_type)
      VSIP_NOTHROW;
  };
}
</synopsis>
