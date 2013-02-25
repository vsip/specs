<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            typename Block = Dense&lt;1, T&gt; &gt;
            class const_Vector;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            typename Block = Dense&lt;1, T&gt; &gt;
            class Vector;

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            typename Block = Dense&lt;1, T&gt; &gt;
  class const_Vector 
  {
  public:
    // compile-time values
    static dimension_type const dim = 1;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.vector.subview_types]
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef subview_type const_subview_type;
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef const_Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef realview_type const_realview_type;
    typedef const_Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef imagview_type const_imagview_type;

    // constructors, copy, and destructor
    // [view.vector.constructors]
    const_Vector(length_type, T const&amp; value);
    explicit const_Vector(length_type);
    const_Vector(Block&amp;) VSIP_NOTHROW;
    const_Vector(const_Vector const&amp;) VSIP_NOTHROW;
    const_Vector(Vector const&amp;) VSIP_NOTHROW;
    ~const_Vector() VSIP_NOTHROW;

    // value accessors
    // [view.vector.valaccess]
    value_type get(index_type) const VSIP_NOTHROW;
    const_reference_type operator()(index_type) const VSIP_NOTHROW;

    // subview accessors
    // [view.vector.subviews]
    const_subview_type get(Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    const_subview_type operator()(Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    const_Vector const &amp;operator()(whole_domain_type) const { return *this;}
    // present only for complex type T:
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.vector.accessors]
    block_type const&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
    length_type length() const VSIP_NOTHROW;
  };

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            typename Block = Dense&lt;1, T&gt; &gt;
  class Vector 
  {
  public:
    // compile-time values
    static dimension_type const dim = 1;
    typedef Block block_type;
    typedef typename block_type::value_type value_type;
    typedef typename block_type::reference_type reference_type;
    typedef typename block_type::const_reference_type
            const_reference_type;

    // subview types
    // [view.vector.subview_types]
    typedef Vector&lt;T, <emphasis>unspecified</emphasis>&gt; subview_type;
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; const_subview_type;
    // present only for complex type T = complex&lt;Tp&gt;:
    typedef Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; realview_type;
    typedef const_Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_realview_type;
    typedef Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; imagview_type;
    typedef const_Vector&lt;Tp, <emphasis>unspecified</emphasis>&gt; const_imagview_type;
  
    // constructors, copy, assignment, and destructor
    // [view.vector.constructors]
    Vector(length_type, T const&amp; value);
    explicit Vector(length_type);
    Vector(Block&amp;) VSIP_NOTHROW;
    Vector(Vector const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector(Vector&lt;T0, Block0&gt; const&amp;);
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    Vector&amp; operator=(const_reference_type) VSIP_NOTHROW;
    template &lt;typename T0&gt;
    Vector&amp; operator=(T0 const&amp;) VSIP_NOTHROW;
    ~Vector() VSIP_NOTHROW;

    // assignment operators
    // [view.vector.assign]
    template &lt;typename T0&gt;
    Vector&amp; operator+=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator+=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator+=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator-=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator-=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator-=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator*=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator*=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator*=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator/=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator/=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator/=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator&amp;=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator&amp;=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator&amp;=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator|=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator|=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator|=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    template &lt;typename T0&gt;
    Vector&amp; operator^=(T0 const&amp;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator^=(const_Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;
    template &lt;typename T0, typename Block0&gt;
    Vector&amp; operator^=(Vector&lt;T0, Block0&gt;) VSIP_NOTHROW;

    // value accessors
    // [view.vector.valaccess]
    value_type get(index_type) const VSIP_NOTHROW;
    <emphasis>unspecified</emphasis> put(index_type, T const&amp;) VSIP_NOTHROW;
    reference_type operator()(index_type) VSIP_NOTHROW;
    const_reference_type operator()(index_type) const VSIP_NOTHROW;

    // subview accessors
    // [view.vector.subviews]
    const_subview_type get(Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));
    subview_type operator()(Domain&lt;1&gt; const&amp;) VSIP_THROW((std::bad_alloc));
    const_subview_type operator()(Domain&lt;1&gt; const&amp;) const VSIP_THROW((std::bad_alloc));

    Vector const &amp;operator()(whole_domain_type) const { return *this;}
    Vector &amp;operator()(whole_domain_type) { return *this;}
    // present only for complex type T:
    realview_type real() VSIP_THROW((std::bad_alloc));
    const_realview_type real() const VSIP_THROW((std::bad_alloc));
    imagview_type imag() VSIP_THROW((std::bad_alloc));
    const_imagview_type imag() const VSIP_THROW((std::bad_alloc));

    // accessors
    // [view.vector.accessors]
    block_type&amp; block() const VSIP_NOTHROW;
    length_type size() const VSIP_NOTHROW;
    length_type size(dimension_type) const VSIP_NOTHROW;
    length_type length() const VSIP_NOTHROW;
  };

  // a specialization
  template &lt;typename Dim0 = Block, ...,
            typename Dimn = Block&gt;
  // exactly VSIP_MAX_DIMENSION template parameters
  class Vector&lt;T, Dense&lt;1, T, Map&lt;Dim0, ..., Dimn&gt; &gt; &gt; 
  {
  public:

    // ... All members are the same as for Vector&lt;T,
    // Block&gt; except Vector's first two constructors are
    // replaced by:

    Vector(length_type, T const&amp; value,
           Dim0 const&amp; = Dim0(), ...,
           Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
    explicit Vector(length_type, Dim0 const&amp; = Dim0(), ...,
                    Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
    Vector(length_type, T const&amp; value, const_Vector&lt;processor_type&gt;,
           Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
    Vector(length_type, const_Vector&lt;processor_type&gt;,
           Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
    Vector(length_type, T const&amp; value, processor_type const*,
           Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
    Vector(length_type, processor_type const*,
           Dim0 const&amp; = Dim0(), ..., Dimn const&amp; = Dimn())
      VSIP_THROW((std::bad_alloc));
  };

  // view conversion
  template &lt;template &lt;typename, typename&gt; class View,
            typename T, typename Block&gt;
  class ViewConversion;
</synopsis>
