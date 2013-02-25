<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip
{
template &lt;typename Block&gt;
struct supports_dda { static bool const value = <emphasis>unspecified</emphasis>;};

namespace dda
{
  typedef unsigned sync_policy;

  sync_policy const in = 0x01;
  sync_policy const out = 0x02;
  sync_policy const inout = in | out;
  sync_policy const copy = 0x04;

  template &lt;typename Layout, typename Block&gt;
  length_type 
  required_buffer_size(Block const &amp;b, bool forced_copy = false);

  template &lt;typename Block&gt;
  length_type 
  required_buffer_size(Block const &amp;b, bool forced_copy = false);

  template &lt;typename Block,
            sync_policy S,
            typename Layout = <emphasis>unspecified</emphasis>&gt;
  class Data
  {
  public:
    typedef <emphasis>unspecified</emphasis> const_ptr_type;
    typedef <emphasis>unspecified</emphasis> ptr_type;

    static int const ct_cost = unspecified;

    Data(Block &amp;block, ptr_type buffer = ptr_type());
    Data(Block const &amp;block, ptr_type buffer = ptr_type());
    ~Data();
    void sync_in();
    void sync_out();

    ptr_type ptr();
    const_ptr_type ptr() const;
    stride_type stride(dimension_type) const;
    length_type size(dimension_type) const;
    length_type size() const;
    length_type storage_size() const;
    int cost() const;
  };

}
}</synopsis>
