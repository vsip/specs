<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;2, T&gt; &gt;
  class const_Matrix;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;2, T&gt; &gt;
  class Matrix;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;2, T&gt; &gt;
  class const_Matrix 
  {
  public:
    // compile-time values
    static dimension_type const dim = 2;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.matrix.subview_types]
    typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef subview_type const_subview_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; col_type;
    typedef col_type const_col_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; diag_type;
    typedef diag_type const_diag_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; row_type;
    typedef row_type const_row_type;
    typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; transpose_type;
    typedef transpose_type const_transpose_type;
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef const_Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef realview_type const_realview_type;
    typedef const_Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef imagview_type const_imagview_type;

    // constructors, copy, and destructor
    // [view.matrix.constructors]
    const_Matrix(length_type num_of_rows, length_type num_of_columns, T const&amp; value);
    const_Matrix(length_type num_of_rows, length_type num_of_columns);
    const_Matrix(Block&amp;) VSIP_NOTHROW;
    const_Matrix(const_Matrix const&amp;) VSIP_NOTHROW;
    const_Matrix(Matrix const&amp;) VSIP_NOTHROW;
    ~const_Matrix() VSIP_NOTHROW;

    // value accessors
    // [view.matrix.valaccess]
    value_type get(index_type, index_type) const VSIP_NOTHROW;
    const_reference_type operator()(index_type, index_type) const VSIP_NOTHROW;

    // subview accessors
    // [view.matrix.subviews]
    const_subview_type get(Domain&lt;2&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    const_subview_type operator()(Domain&lt;2&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    const_col_type col(index_type column_index) const VSIP_THROW((std::bad_alloc));
    const_col_type operator()(whole_domain_type, vsip::index_type i) const 
      VSIP_THROW((std::bad_alloc));
    const_row_type operator()(vsip::index_type i, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    const_diag_type diag(index_difference_type) const VSIP_THROW((std::bad_alloc));
    const_row_type row(index_type row_index) const VSIP_THROW((std::bad_alloc));
    const_transpose_type transpose() const VSIP_THROW((std::bad_alloc));
    // present only for complex type T:
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.matrix.accessors]
    block_type const&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
  };

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            class Block = Dense&lt;2, T&gt; &gt;
  class Matrix 
  {
  public:
    // compile-time values
    static dimension_type const dim = 2;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.matrix.subview_types]
    typedef Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; const_subview_type;
    typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; col_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_col_type;
    typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; diag_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_diag_type;
    typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; row_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_row_type;
    typedef Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; transpose_type;
    typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; const_transpose_type;
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef const_Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_realview_type;
    typedef Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef const_Matrix&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_imagview_type;

    // constructors, copy, assignment, and destructor
    // [view.matrix.constructors]
    Matrix(length_type num_of_rows, length_type num_of_columns, T const&amp; value);
    Matrix(length_type num_of_rows, length_type num_of_columns);
    Matrix(Block&amp;) VSIP_NOTHROW;
    Matrix(Matrix const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix(Matrix&lt;T0, Block0&gt; const&amp;);
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    Matrix&amp; operator=(const_reference_type) VSIP_NOTHROW;
    template &lt;typename T0&gt;
    Matrix&amp; operator=(T0 const&amp;) VSIP_NOTHROW;
    ~Matrix() VSIP_NOTHROW;

    // assignment operators
    // [view.matrix.assign]
    template &lt;typename T0&gt;
    Matrix&amp; operator+=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator+=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator+=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator-=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator-=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator-=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator*=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator*=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator*=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator/=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator/=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator/=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator&amp;=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator&amp;=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator&amp;=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator|=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator|=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator|=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Matrix&amp; operator^=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator^=(const_Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Matrix&amp; operator^=(Matrix&lt;T0, Block0&gt;) VSIP_NOTHROW;

    // value accessors
    // [view.matrix.valaccess]
    value_type get(index_type, index_type) const VSIP_NOTHROW;
    <emphasis>unspecified</emphasis> put(index_type, index_type, T const&amp;) VSIP_NOTHROW;
    reference_type operator()(index_type, index_type) VSIP_NOTHROW;
    const_reference_type operator()(index_type, index_type) const VSIP_NOTHROW;

    // subview accessors
    // [view.matrix.subviews]
    const_subview_type get(Domain&lt;2&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    subview_type operator()(Domain&lt;2&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    const_subview_type operator()(Domain&lt;2&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    col_type col(index_type column_index) VSIP_THROW((std::bad_alloc));
    const_col_type col(index_type column_index) const VSIP_THROW((std::bad_alloc));
    col_type operator()(whole_domain_type, vsip::index_type i) VSIP_THROW((std::bad_alloc));
    const_col_type operator()(whole_domain_type, vsip::index_type i) const 
      VSIP_THROW((std::bad_alloc));
    row_type operator()(vsip::index_type i, whole_domain_type) VSIP_THROW((std::bad_alloc));
    const_row_type operator()(vsip::index_type i, whole_domain_type) const 
      VSIP_THROW((std::bad_alloc));
    diag_type diag(index_difference_type = 0) VSIP_THROW((std::bad_alloc));
    const_diag_type diag(index_difference_type) const VSIP_THROW((std::bad_alloc));
    row_type row(index_type row_index) VSIP_THROW((std::bad_alloc));
    const_row_type row(index_type row_index) const VSIP_THROW((std::bad_alloc));
    transpose_type transpose() VSIP_THROW((std::bad_alloc));
    const_transpose_type transpose() const VSIP_THROW((std::bad_alloc));
    // present only for complex type T:
    realview_type real() VSIP_THROW((std::bad_alloc));
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    imagview_type imag() VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.matrix.accessors]
    block_type&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
  };

// a specialization
  template &lt;typename Dim0 = Block, ...,
            typename Dimn = Block&gt;
    // exactly VSIP_MAX_DIMENSION template parameters
  class Matrix&lt;T, Dense&lt;2, T, Map&lt;Dim0, ..., Dimn&gt; &gt; &gt; 
  {
  public:

  // ... All members are the same as for Matrix&lt;T,
  // Block&gt; except Matrix's first two constructors are
  // replaced by:

  Matrix(length_type, length_type, T const&amp; value,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Matrix(length_type, length_type,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Matrix(length_type, length_type, T const&amp; value,
         const_Vector&lt;processor_type&gt;,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Matrix(length_type, length_type,
         const_Vector&lt;processor_type&gt;,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Matrix(length_type, length_type, T const&amp; value, processor_type const*,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  Matrix(length_type, length_type, processor_type const*,
         Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
    VSIP_THROW((std::bad_alloc));
  };

  // view conversion
  template &lt;template &lt;typename, typename&gt; class View,
    typename T, typename Block&gt;
  class ViewConversion;
}
</synopsis>
