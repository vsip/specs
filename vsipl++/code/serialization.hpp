<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip
{
namespace serialization
{

typedef <emphasis>unspecified</emphasis> uint8_type;
typedef <emphasis>unspecified</emphasis> int8_type;
typedef <emphasis>unspecified</emphasis> uint16_type;
typedef <emphasis>unspecified</emphasis> int16_type;
typedef <emphasis>unspecified</emphasis> uint32_type;
typedef <emphasis>unspecified</emphasis> int32_type;
typedef <emphasis>unspecified</emphasis> uint64_type;
typedef <emphasis>unspecified</emphasis> int64_type;

struct Descriptor
{
  uint64_type value_type;
  uint8_type dimensions;
  uint8_type storage_format;
  uint64_type size[3];
  int64_type stride[3];
  uint64_type storage_size;
};

template &lt;typename T&gt; struct type_info
{
  static uint64_type const value = <emphasis>unspecified</emphasis>;
};

template &lt;typename B, unsigned S, typename L&gt;
void describe_data(vsip::dda::Data&lt;B, S, L&gt; const &amp;data, Descriptor &amp;info);

template &lt;typename B&gt;
void describe_user_storage(B const &amp;block, Descriptor &amp;info);

template &lt;typename B&gt;
bool is_compatible(Descriptor const &amp;info);

}
}</synopsis>
