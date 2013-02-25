<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  enum user_storage_type 
  {
    no_user_format = any_storage_format,
    array_format = array,
    interleaved_format = interleaved_complex,
    split_format = split_complex
  };

  template &lt;dimension_type D = 1,
            typename       T = VSIP_DEFAULT_VALUE_TYPE,
            typename       O = <emphasis>row-major-for-D</emphasis>,
            typename       M = Local_map&lt;&gt; &gt;
  class Dense 
  {
  public:
    static dimension_type const dim = D;
    static storage_format_type const storage_format = <emphasis>implementation-defined</emphasis>;
    typedef T        value_type;
    typedef T&amp;       reference_type;
    typedef T const&amp; const_reference_type;
    typedef O        order_type;
    typedef M map_type;

    // constructors and destructor
    Dense(Domain&lt;D&gt; const&amp;, T const&amp;, map_type const&amp; = map_type())
      VSIP_THROW((std::bad_alloc));
    Dense(Domain&lt;D&gt; const&amp;, map_type const&amp; = map_type())
      VSIP_THROW((std::bad_alloc));
    Dense(Domain&lt;D&gt; const&amp;, T*const pointer, map_type const&amp; = map_type())
      VSIP_THROW((std::bad_alloc));
    // present only for complex type T = complex&lt;uT&gt;:
    Dense(Domain&lt;D&gt; const&amp;, uT*const pointer, map_type const&amp; = map_type())
      VSIP_THROW((std::bad_alloc));
    // present only for complex T = complex&lt;uT&gt;:
    Dense(Domain&lt;D&gt; const&amp;,
          uT*const real_pointer,
          uT*const imag_pointer,
          map_type const&amp; = map_type())
      VSIP_THROW((std::bad_alloc));
    Dense(std::pair&lt;uT*,uT*&gt; pointer, map_type const &amp; = map_type());
    ~Dense() VSIP_NOTHROW;

    // user data manipulation functions
    void admit(bool update = true) VSIP_NOTHROW;
    void release(bool update = true) VSIP_NOTHROW;
    void release(bool update, T*&amp; pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void release(bool update, uT*&amp; pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void release(bool update, uT*&amp; real_pointer, uT*&amp; imag_pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void release(std::pair&lt;uT*,uT*&gt; &amp;pointer) VSIP_NOTHROW;
    void find(T*&amp; pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void find(uT*&amp; pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void find(uT*&amp; real_pointer, uT*&amp; imag_pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void find(std::pair&lt;uT*,uT*&gt; &amp;pointer) VSIP_NOTHROW;
    void rebind(T*const pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void rebind(uT*const pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void rebind(uT*const real_pointer, uT*const image_pointer) VSIP_NOTHROW;
    // present only for complex T = complex&lt;uT&gt;:
    void rebind(std::pair&lt;uT*,uT*&gt; pointer) VSIP_NOTHROW;
    // These variants also resize the block
    void rebind(T*const pointer, Domain&lt;D&gt; const &amp;) VSIP_NOTHROW;
    void rebind(uT*const pointer, Domain&lt;D&gt; const &amp;) VSIP_NOTHROW;
    void rebind(uT*const real_pointer, uT*const image_pointer, Domain&lt;D&gt; const &amp;)
      VSIP_NOTHROW;
    void rebind(std::pair&lt;uT*,uT*&gt; pointer, Domain&lt;D&gt; const &amp;) VSIP_NOTHROW;

    // value accessors
    value_type get(index_type) const VSIP_NOTHROW;
    // exactly D index_type parameters; present only if D != 1
    value_type get(index_type, ..., index_type) const VSIP_NOTHROW;
    <emphasis>unspecified</emphasis> put(index_type, T const&amp;) VSIP_NOTHROW;
    // exactly D index_type parameters; present only if D != 1
    <emphasis>unspecified</emphasis> put(index_type, ..., index_type, T const&amp;) VSIP_NOTHROW;

    // accessors
    length_type size() VSIP_NOTHROW;
    length_type size(dimension_type Dim, dimension_type d) VSIP_NOTHROW;
    void increment_count() VSIP_NOTHROW;
    void decrement_count() VSIP_NOTHROW;
    map_type const&amp; map() const VSIP_NOTHROW;
    enum user_storage_type user_storage() const VSIP_NOTHROW;
    bool admitted() const VSIP_NOTHROW;
  };
}</synopsis>
