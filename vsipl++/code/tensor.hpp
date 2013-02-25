<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;3, T&gt; &gt;
  class const_Tensor;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;3, T&gt; &gt;
  class Tensor;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;3, T&gt; &gt;
  class const_Tensor 
  {
  public:
    // compile-time values
    static dimension_type const dim = 3;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.tensor.subview_types]
    typedef const_Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef subview_type const_subview_type;
    template &lt;dimension_type D1, dimension_type D2&gt;
    struct subvector
    {
      typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef type const_type;
      typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; subset_type;
      typedef subset_type const_subset_type;
    };
    template &lt;dimension_type D&gt;
    struct submatrix
    {
      typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef type const_type;
      typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; subset_type;
      typedef subset_type const_subset_type;
    };
    template &lt;dimension_type D0, dimension_type D1, dimension_type D2&gt;
    struct transpose_view
    {
      typedef const_Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef type const_type;
    };
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef const_Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef realview_type const_realview_type;
    typedef const_Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef imagview_type const_imagview_type;

    // constructors, copy, assignment, and destructor
    // [view.tensor.constructors]
    const_Tensor(length_type z_length, length_type y_length,
                 length_type x_length, T const&amp; value);
    const_Tensor(length_type z_length, length_type y_length,
                 length_type x_length);
    const_Tensor(Block&amp;) VSIP_NOTHROW;
    const_Tensor(const_Tensor const&amp;) VSIP_NOTHROW;
    const_Tensor(Tensor const&amp;) VSIP_NOTHROW;
    ~const_Tensor() VSIP_NOTHROW;

    // transposition
    // [view.tensor.transpose]
    template &lt;dimension_type D0, dimension_type D1, dimension_type D2&gt;
    typename transpose_view&lt;D0, D1, D2&gt;::const_type
    transpose() const VSIP_NOTHROW;

    // value accessors
    // [view.tensor.valaccess]
    value_type get(index_type, index_type, index_type) const VSIP_NOTHROW;
    const_reference_type operator()(index_type, index_type, index_type) const
      VSIP_NOTHROW;

    // subview accessors
    // [view.tensor.subviews]
    const_subview_type
    get(Domain&lt;3&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    const_subview_type
    operator()(Domain&lt;3&gt; const&amp;) const VSIP_THROW((std::bad_alloc));

    typename subvector&lt;0, 1&gt;::const_type
    operator()(index_type, index_type, whole_domain_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::const_type
    operator()(index_type, whole_domain_type, index_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::const_type
    operator()(whole_domain_type, index_type, index_type) const VSIP_THROW((std::bad_alloc));

    typename subvector&lt;0, 1&gt;::const_subset_type
    operator()(index_type, index_type, Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::const_subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, index_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, index_type) const VSIP_THROW((std::bad_alloc));

    typename submatrix&lt;0&gt;::const_type
    operator()(index_type, whole_domain_type, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::const_type
    operator()(whole_domain_type, index_type, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::const_type
    operator()(whole_domain_type, whole_domain_type, index_type) const 
      VSIP_THROW((std::bad_alloc));

    typename submatrix&lt;0&gt;::const_subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, Domain&lt;1&gt; const&amp;) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;, index_type) const 
      VSIP_THROW((std::bad_alloc));

    // present only for complex type T:
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.tensor.accessors]
    block_type&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
  };

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;3, T&gt; &gt;
  class Tensor 
  {
  public:
    // compile-time values
    static dimension_type const dim = 3;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.tensor.subview_types]
    typedef Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef const_Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; const_subview_type;
    template &lt;dimension_type D1, dimension_type D2&gt;
    struct subvector
    {
      typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_type;
      typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; subset_type;
      typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_subset_type;
    };
    template &lt;dimension_type D&gt;
    struct submatrix
    {
      typedef Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; const_type;
      typedef Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; subset_type;
      typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; const_subset_type;
    };
    template &lt;dimension_type D0, dimension_type D1, dimension_type D2&gt;
    struct transpose_view
    {
      typedef Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; type;
      typedef const_Tensor&lt;T, <emphasis>unspecified</emphasis>&gt; const_type;
    };
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef const_Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_realview_type;
    typedef Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef const_Tensor&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_imagview_type;

    // constructors, copy, assignment, and destructor
    // [view.tensor.constructors]
    Tensor(length_type z_length, length_type y_length,
           length_type x_length, T const&amp; value);
    Tensor(length_type z_length, length_type y_length,
           length_type x_length);
    Tensor(Block&amp;) VSIP_NOTHROW;
    Tensor(Tensor const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor(Tensor&lt;T0, Block0&gt; const&amp;);
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator=(const_Tensor&lt;T0,Block0&gt;) VSIP_NOTHROW;
    Tensor &amp;operator=(const_reference_type) VSIP_NOTHROW;
    template &lt;typename T0&gt;
    Tensor &amp;operator=(T0 const&amp;) VSIP_NOTHROW;
    ~Tensor() VSIP_NOTHROW;

    // assignment operators
    // [view.tensor.assign]
    template &lt;typename T0&gt;
    Tensor &amp;operator+=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator+=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor&amp; operator+=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator-=(T0 const &amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator-=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator-=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator*=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator*=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator*=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator/=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator/=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor&amp; operator/=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator&amp;=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator&amp;=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator&amp;=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator|=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator|=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator|=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Tensor &amp;operator^=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator^=(const_Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Tensor &amp;operator^=(Tensor&lt;T0, Block0&gt;) VSIP_NOTHROW;

    // transposition
    // [view.tensor.transpose]
    template &lt;dimension_type D0, dimension_type D1, dimension_type D2&gt;
    typename transpose_view&lt;D0, D1, D2&gt;::const_type
    transpose() const VSIP_NOTHROW;
    template &lt;dimension_type D0, dimension_type D1, dimension_type D2&gt;
    typename transpose_view&lt;D0, D1, D2&gt;::type
    transpose() VSIP_NOTHROW;

    // value accessors
    // [view.tensor.valaccess]
    value_type get(index_type, index_type, index_type) const VSIP_NOTHROW;
    <emphasis>unspecified</emphasis> put(index_type, index_type, index_type, T const&amp;) VSIP_NOTHROW;
    reference_type operator()(index_type, index_type, index_type) VSIP_NOTHROW;
    const_reference_type operator()(index_type, index_type, index_type) const VSIP_NOTHROW;

    // subview accessors
    // [view.tensor.subviews]
    const_subview_type
    get(Domain&lt;3&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    subview_type
    operator()(Domain&lt;3&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    const_subview_type
    operator()(Domain&lt;3&gt; const&amp;) const VSIP_THROW((std::bad_alloc));

    typename subvector&lt;0, 1&gt;::type
    operator()(index_type, index_type, whole_domain_type) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 1&gt;::const_type
    operator()(index_type, index_type, whole_domain_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::type
    operator()(index_type, whole_domain_type, index_type) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::const_type
    operator()(index_type, whole_domain_type, index_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::type
    operator()(whole_domain_type, index_type, index_type) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::const_type
    operator()(whole_domain_type, index_type, index_type) const VSIP_THROW((std::bad_alloc));

    typename subvector&lt;0, 1&gt;::subset_type
    operator()(index_type, index_type, Domain&lt;1&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 1&gt;::const_subset_type
    operator()(index_type, index_type, Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, index_type) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;0, 2&gt;::const_subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, index_type) const VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, index_type) VSIP_THROW((std::bad_alloc));
    typename subvector&lt;1, 2&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, index_type) const VSIP_THROW((std::bad_alloc));

    typename submatrix&lt;0&gt;::type
    operator()(index_type, whole_domain_type, whole_domain_type) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;0&gt;::const_type
    operator()(index_type, whole_domain_type, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::type
    operator()(whole_domain_type, index_type, whole_domain_type) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::const_type
    operator()(whole_domain_type, index_type, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::type
    operator()(whole_domain_type, whole_domain_type, index_type) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::const_type
    operator()(whole_domain_type, whole_domain_type, index_type) const 
      VSIP_THROW((std::bad_alloc));

    typename submatrix&lt;0&gt;::subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;0&gt;::const_subset_type
    operator()(index_type, Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, Domain&lt;1&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;1&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, index_type, Domain&lt;1&gt; const&amp;) const 
      VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::subset_type
    operator()(Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;, index_type) VSIP_THROW((std::bad_alloc));
    typename submatrix&lt;2&gt;::const_subset_type
    operator()(Domain&lt;1&gt; const&amp;, Domain&lt;1&gt; const&amp;, index_type) const 
      VSIP_THROW((std::bad_alloc));

    // present only for complex type T:
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    realview_type real() VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));
    imagview_type imag() VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.tensor.accessors]
    block_type&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
  };

  // a specialization
  template &lt;typename Dim0 = Block, ...,
            typename Dimn = Block&gt;
    // exactly VSIP_MAX_DIMENSION template parameters
  class Tensor&lt;T, Dense&lt;3, T, Map&lt;Dim0, ..., Dimn&gt; &gt; &gt; 
  {
  public:

  // ... All members are the same as for Tensor&lt;T,
  // Block&gt; except Tensor's first two constructors are
  // replaced by:

  Tensor(length_type, length_type, length_type, T const&amp; value,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Tensor(length_type, length_type, length_type,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Tensor(length_type, length_type, length_type,
         T const&amp; value, const_Vector&lt;processor_type&gt;,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Tensor(length_type, length_type, length_type, 
         const_Vector&lt;processor_type&gt;,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Tensor(length_type, length_type, length_type, 
         T const&amp; value, processor_type const*,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Tensor(length_type, length_type, length_type, 
         processor_type const*,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  };

  // view conversion
  template &lt;template &lt;typename, typename&gt; class View,
    typename T, typename Block&gt;
  class ViewConversion;
}
</synopsis>
