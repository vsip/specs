<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE&gt;
  class Rand 
  {
  public:
    // view types
    typedef const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt; vector_type;
    typedef const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt; matrix_type;

    // constructors, copies, assignments, and destructors
    Rand(index_type, bool = true) VSIP_THROW((std::bad_alloc));
    Rand(index_type, index_type, index_type, bool = true)
      VSIP_THROW((std::bad_alloc));
  private:
    Rand(Rand const&amp;) VSIP_NOTHROW;
    Rand&amp; operator=(Rand const&amp;) VSIP_NOTHROW;
  public:
    ~Rand() VSIP_NOTHROW;

    // number generators
    T randu() VSIP_NOTHROW;
    T randn() VSIP_NOTHROW;
    vector_type&lt;T, <emphasis>unspecified</emphasis>&gt; randu(length_type) VSIP_NOTHROW;
    matrix_type&lt;T, <emphasis>unspecified</emphasis>&gt; randu(length_type, length_type)
      VSIP_NOTHROW;
    vector_type&lt;T, <emphasis>unspecified</emphasis>&gt; randn(length_type) VSIP_NOTHROW;
    matrix_type&lt;T, <emphasis>unspecified</emphasis>&gt; randn(length_type, length_type)
      VSIP_NOTHROW;
  };
}
</synopsis>
