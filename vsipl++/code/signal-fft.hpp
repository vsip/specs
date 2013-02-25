<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  int const fft_fwd = <emphasis>unspecified</emphasis>;
  int const fft_inv = <emphasis>unspecified</emphasis>;

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename I,                         // input type 
            typename O,                         // output type
            int S = 0,                          // special dimension
            return_mechanism_type R = by_value, // return mechanism type
            unsigned N = 0,                     // number of times
            alg_hint_type H = alg_time&gt;         // algorithm hint
  class Fft 
  {
  public:
    // constructor, copies, assignments, and destructor
    Fft(Domain&lt;const_View::dim&gt; const &amp;, scalar_f)
      VSIP_THROW((std::bad_alloc));
    Fft(Fft const&amp;) VSIP_NOTHROW;
    Fft &amp;operator=(Fft const &amp;) VSIP_NOTHROW;
    ~Fft() VSIP_NOTHROW;

    // accessors
    Domain&lt;const_View::dim&gt; const &amp;input_size() const VSIP_NOTHROW;
    Domain&lt;const_View::dim&gt; const &amp;output_size() const VSIP_NOTHROW;
    scalar_f scale() const VSIP_NOTHROW;
    bool forward() const VSIP_NOTHROW;

    // operators
    // if R is by_value:
    template &lt;typename Block&gt;
    const_View&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
    operator()(const_View&lt;InputType, Block&gt;) VSIP_THROW((std::bad_alloc));

    // if R is by_reference:
    template &lt;typename Block0, typename Block1&gt;
    const_View&lt;OutputType, Block1&gt;
    operator()(const_View&lt;InputType, Block0&gt;,
               ViewConversion&lt;View, OutputType, Block1&gt;::view_type)
      VSIP_NOTHROW;
    // if R is by_reference and I == O:
    template &lt;typename Block&gt;
    typename ViewConversion&lt;View, OutputType, Block&gt;::view_type
    operator()(ViewConversion&lt;View, OutputType, Block&gt;::view_type)
      VSIP_NOTHROW;
  };
}
</synopsis>
