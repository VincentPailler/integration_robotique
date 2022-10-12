// Generated by gencpp from file motoman_msgs/ReadMRegisterResponse.msg
// DO NOT EDIT!


#ifndef MOTOMAN_MSGS_MESSAGE_READMREGISTERRESPONSE_H
#define MOTOMAN_MSGS_MESSAGE_READMREGISTERRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace motoman_msgs
{
template <class ContainerAllocator>
struct ReadMRegisterResponse_
{
  typedef ReadMRegisterResponse_<ContainerAllocator> Type;

  ReadMRegisterResponse_()
    : message()
    , success(false)
    , value(0)  {
    }
  ReadMRegisterResponse_(const ContainerAllocator& _alloc)
    : message(_alloc)
    , success(false)
    , value(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;

   typedef uint8_t _success_type;
  _success_type success;

   typedef uint16_t _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ReadMRegisterResponse_

typedef ::motoman_msgs::ReadMRegisterResponse_<std::allocator<void> > ReadMRegisterResponse;

typedef boost::shared_ptr< ::motoman_msgs::ReadMRegisterResponse > ReadMRegisterResponsePtr;
typedef boost::shared_ptr< ::motoman_msgs::ReadMRegisterResponse const> ReadMRegisterResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator1> & lhs, const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator2> & rhs)
{
  return lhs.message == rhs.message &&
    lhs.success == rhs.success &&
    lhs.value == rhs.value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator1> & lhs, const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace motoman_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a0305ccc5f57b472aa935ba809c1b3ca";
  }

  static const char* value(const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa0305ccc5f57b472ULL;
  static const uint64_t static_value2 = 0xaa935ba809c1b3caULL;
};

template<class ContainerAllocator>
struct DataType< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "motoman_msgs/ReadMRegisterResponse";
  }

  static const char* value(const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string message\n"
"bool success\n"
"uint16 value\n"
"\n"
;
  }

  static const char* value(const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.message);
      stream.next(m.success);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReadMRegisterResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::motoman_msgs::ReadMRegisterResponse_<ContainerAllocator>& v)
  {
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "value: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOTOMAN_MSGS_MESSAGE_READMREGISTERRESPONSE_H