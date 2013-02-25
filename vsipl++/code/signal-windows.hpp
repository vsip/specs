<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  blackman(length_type) VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  cheby(length_type, scalar_f) VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  hanning(length_type) VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  kaiser(length_type, scalar_f) VSIP_NOTHROW;
}
</synopsis>
