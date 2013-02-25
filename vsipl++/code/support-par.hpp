<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // map and processor types
  typedef <emphasis>implementationdefined</emphasis> processor_type;
  typedef <emphasis>signed-version-of-processor_type</emphasis> processor_difference_type;
  enum distribution_type { block, cyclic, whole, other};

  // functions
  length_type num_processors() VSIP_NOTHROW;
  const_Vector&lt;processor_type, <emphasis>implementationdefined</emphasis> &gt; processor_set() 
    VSIP_THROW((std::bad_alloc));
  processor_type local_processor() VSIP_NOTHROW;
  index_type local_processor_index() VSIP_NOTHROW;

  // constants
  processor_type const no_processor;
  index_type const no_subblock;
}
</synopsis>
