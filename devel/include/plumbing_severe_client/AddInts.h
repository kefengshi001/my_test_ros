// Generated by gencpp from file plumbing_severe_client/AddInts.msg
// DO NOT EDIT!


#ifndef PLUMBING_SEVERE_CLIENT_MESSAGE_ADDINTS_H
#define PLUMBING_SEVERE_CLIENT_MESSAGE_ADDINTS_H

#include <ros/service_traits.h>


#include <plumbing_severe_client/AddIntsRequest.h>
#include <plumbing_severe_client/AddIntsResponse.h>


namespace plumbing_severe_client
{

struct AddInts
{

typedef AddIntsRequest Request;
typedef AddIntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AddInts
} // namespace plumbing_severe_client


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::plumbing_severe_client::AddInts > {
  static const char* value()
  {
    return "4781436a0c2affec8025955a6041e481";
  }

  static const char* value(const ::plumbing_severe_client::AddInts&) { return value(); }
};

template<>
struct DataType< ::plumbing_severe_client::AddInts > {
  static const char* value()
  {
    return "plumbing_severe_client/AddInts";
  }

  static const char* value(const ::plumbing_severe_client::AddInts&) { return value(); }
};


// service_traits::MD5Sum< ::plumbing_severe_client::AddIntsRequest> should match
// service_traits::MD5Sum< ::plumbing_severe_client::AddInts >
template<>
struct MD5Sum< ::plumbing_severe_client::AddIntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::plumbing_severe_client::AddInts >::value();
  }
  static const char* value(const ::plumbing_severe_client::AddIntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::plumbing_severe_client::AddIntsRequest> should match
// service_traits::DataType< ::plumbing_severe_client::AddInts >
template<>
struct DataType< ::plumbing_severe_client::AddIntsRequest>
{
  static const char* value()
  {
    return DataType< ::plumbing_severe_client::AddInts >::value();
  }
  static const char* value(const ::plumbing_severe_client::AddIntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::plumbing_severe_client::AddIntsResponse> should match
// service_traits::MD5Sum< ::plumbing_severe_client::AddInts >
template<>
struct MD5Sum< ::plumbing_severe_client::AddIntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::plumbing_severe_client::AddInts >::value();
  }
  static const char* value(const ::plumbing_severe_client::AddIntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::plumbing_severe_client::AddIntsResponse> should match
// service_traits::DataType< ::plumbing_severe_client::AddInts >
template<>
struct DataType< ::plumbing_severe_client::AddIntsResponse>
{
  static const char* value()
  {
    return DataType< ::plumbing_severe_client::AddInts >::value();
  }
  static const char* value(const ::plumbing_severe_client::AddIntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PLUMBING_SEVERE_CLIENT_MESSAGE_ADDINTS_H