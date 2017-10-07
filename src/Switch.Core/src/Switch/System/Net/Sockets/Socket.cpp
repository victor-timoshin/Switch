#include "../../../../../include/Switch/System/NotImplementedException.hpp"
#include "../../../../../include/Switch/System/ObjectClosedException.hpp"
#include "../../../../../include/Switch/System/Net/Dns.hpp"
#include "../../../../../include/Switch/System/Net/Sockets/Socket.hpp"
#include "../../../../../include/Switch/System/Net/Sockets/MulticastOption.hpp"
#include "../../../../../include/Switch/System/Net/Sockets/SocketException.hpp"
#include "../../../../__OS/CoreApi.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;

_property<bool, _readonly> Socket::OSSupportsIPv4 {
  [] {return __OS::CoreApi::Socket::GetOSSupportsIPv4();}
};

_property<bool, _readonly> Socket::OSSupportsIPv6 {
  [] {return __OS::CoreApi::Socket::GetOSSupportsIPv6();}
};

Socket::Socket(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType) {
  this->data->addressFamily = addressFamily;
  this->data->protocolType = protocolType;
  this->data->socketType = socketType;
  
  if (__OS::CoreApi::Socket::Open(this->data->addressFamily, this->data->socketType, this->data->protocolType, &this->data->socket) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
}

Socket::Socket(intptr socket) {
  this->data->socket = socket;
}

Socket::~Socket() {
  if (this->data.IsUnique())
    Close();
}

Socket Socket::Accept() {
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);
  if (this->data->bound == false || this->data->listening == false)
    throw InvalidOperationException(_caller);
 
  SocketAddress socketAddress(this->data->addressFamily);
  intptr socketHandle = 0;
  if (__OS::CoreApi::Socket::Accept(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size, &socketHandle) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  
  Socket socketNewlyCreated(socketHandle);
  socketNewlyCreated.data->addressFamily = this->data->addressFamily;
  socketNewlyCreated.data->socketType = this->data->socketType;
  socketNewlyCreated.data->protocolType = this->data->protocolType;
  socketNewlyCreated.data->localEndPoint = IPEndPoint(0, 0).Create(socketAddress);
	socketNewlyCreated.data->connected = true;
  this->data->connected = true;
  return socketNewlyCreated;
}

void Socket::InnerBind() {
  SocketAddress socketAddress = this->data->localEndPoint->Serialize();
  if (__OS::CoreApi::Socket::Bind(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size()) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);

  this->data->bound = true;
}

void Socket::Close() {
  this->data->connected = false;
  this->data->bound = false;
  this->data->listening = false;
  if (this->data->socket != IntPtr::Zero()) {
    __OS::CoreApi::Socket::Close(this->data->socket);
    this->data->socket = IntPtr::Zero();
  }
}

void Socket::InnerConnect() {
  SocketAddress socketAddress = this->data->remoteEndPoint->Serialize();
  if (__OS::CoreApi::Socket::Connect(this->data->socket, (byte*)socketAddress.bytes.Data(), socketAddress.Size) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);

  this->data->connected = true;
}

void Socket::Connect(const IPAddress& address, int32 port) {
  Connect(IPEndPoint(address, port));
}

void Socket::Connect(const Array<IPAddress>& addresses, int32 port) {
  for (IPAddress ipAddress : addresses) {
    if (Connected == false)
      Connect(ipAddress, port);
  }
}

void Socket::Connect(const string &host, int32 port) {
  Connect(Dns::GetHostAddresses(host), port);
}

void Socket::Disconnect(bool reuseSocket) {
  if (this->data->connected == false)
    throw ObjectClosedException(_caller);

  if (__OS::CoreApi::Socket::Connect(this->data->socket, null, 0) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);

  this->data->connected = false;
  this->data->bound = false;

  if (reuseSocket == false)
    Close();
}

SocketInformation Socket::DuplicateAndClose(int32 targetProcessId) {
  throw NotImplementedException(_caller);
}

int32 Socket::GetAvailable() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  int32 nbrBytesAvailable = 0;
  __OS::CoreApi::Socket::GetAvailable(this->data->socket, &nbrBytesAvailable);
  return nbrBytesAvailable;
}

bool Socket::GetBlocking() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  return !this->data->nonBlocking;
}

const EndPoint& Socket::GetLocalEndPoint() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  return *this->data->localEndPoint;
}

const EndPoint& Socket::GetRemoteEndPoint() const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  return *this->data->remoteEndPoint;
}

refptr<object> Socket::GetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName) const {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);

  if (socketOptionName == SocketOptionName::MaxConnections)
    throw SocketException((int32)SocketError::ProtocolOption, _caller);
  
  if (socketOptionName == SocketOptionName::Linger) {
    /// @todo
    //return ref_new<LingerOption>(false, 0);
    throw NotImplementedException(_caller);
  }
  
  if (socketOptionName == SocketOptionName::AddMembership || socketOptionName == SocketOptionName::DropMembership) {
    /// @todo
    //return ref_new<MulticastOption>(IPAddress());
    throw NotImplementedException(_caller);
  }

  int32 socketOption = 0;
  int32 size = sizeof(int32);
  if (__OS::CoreApi::Socket::GetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, &socketOption, &size) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  return ref_new<Int32>(socketOption);
}

int32 Socket::IOControl(System::Net::Sockets::IOControlCode /*ioControlCode*/, const Array<byte>& /*optionInValue*/, Array<byte>& /*optionOutValue*/) {
  throw NotImplementedException(_caller);
}

void Socket::Listen(int32 backlog) {
  if (this->data->bound == false)
    throw SocketException((int32)SocketError::NotConnected, _caller);
  
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  if (backlog > (int32)SocketOptionName::MaxConnections || backlog < 0)
    throw ArgumentOutOfRangeException(_caller);

  __OS::CoreApi::Socket::Listen(this->data->socket, backlog);

  this->data->listening = true;
}

bool Socket::Poll(int32 microseconds, SelectMode mode) {
  int32 status = __OS::CoreApi::Socket::Poll(this->data->socket, microseconds, (int32)mode);

  if (status < 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  
  return (status > 0);
}

int32 Socket::Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  SocketError errorCode = SocketError::Success;
  int32 numberOfBytesReceived = this->Receive(buffer, offset, size, socketFlags, errorCode);
  if (errorCode != SocketError::Success)
    throw SocketException((int32)errorCode, _caller);
  return numberOfBytesReceived;
}

int32 Socket::Receive(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& errorCode) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(_caller);
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);
  
  int32 numberOfBytesReceived = __OS::CoreApi::Socket::Receive(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags);
  errorCode = numberOfBytesReceived == -1 ? (SocketError)__OS::CoreApi::Socket::GetLastError() : SocketError::Success;
  return numberOfBytesReceived;
}

int32 Socket::ReceiveFrom(Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, IPEndPoint& endPoint) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(_caller);
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);

  SocketAddress socketAddress(this->data->addressFamily);
  int32 numberOfBytesReceived = __OS::CoreApi::Socket::ReceiveFrom(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags, (byte*)socketAddress.bytes.Data(), socketAddress.Size);
  if (numberOfBytesReceived == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  endPoint = endPoint.Create(socketAddress).ChangeType<IPEndPoint>().ToObject();

  return numberOfBytesReceived;
}

int32 Socket::Select(IList<Socket>& checkRead, IList<Socket>& checkWrite, IList<Socket>& checkError, int32 microseconds) {
  if (checkRead.Count == 0 && checkWrite.Count == 0 && checkError.Count == 0)
    throw ArgumentNullException(_caller);
  
  int32 nbCheckRead = checkRead.Count;
  Array<intptr> checkReadHandles(nbCheckRead);
  for (int32 i = 0; i < nbCheckRead; i++)
    checkReadHandles[i] = checkRead[i].data->socket;
  
  int32 nbCheckWrite = checkWrite.Count;
  Array<intptr> checkWriteHandles(nbCheckWrite);
  for (int32 i = 0; i < nbCheckWrite; i++)
    checkWriteHandles[i] = checkWrite[i].data->socket;
  
  int32 nbCheckError = checkError.Count;
  Array<intptr> checkErrorHandles(nbCheckError);
  for (int32 i = 0; i < nbCheckError; i++)
    checkErrorHandles[i] = checkError[i].data->socket;
  
  int32 status = __OS::CoreApi::Socket::Select((intptr*)checkReadHandles.Data(), nbCheckRead, (intptr*)checkWriteHandles.Data(), nbCheckWrite, (intptr*)checkErrorHandles.Data(), nbCheckError, microseconds);
  
  if (status < 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  
  // List the null sockets
  List<Socket> readToRemove;
  for (int32 i = 0; i < nbCheckRead; i++)
    if (checkReadHandles[i] == 0)
      readToRemove.Add(checkRead[i]);
  
  // Remove the null sockets
  for (Socket item : readToRemove)
    if (checkRead.Contains(item))
      checkRead.Remove(item);
  
  // List the null sockets
  List<Socket> writeToRemove;
  for (int32 i = 0; i < nbCheckWrite; i++)
    if (checkWriteHandles[i] == 0)
      writeToRemove.Add(checkWrite[i]);
  
  // Remove the null sockets
  for (Socket item : writeToRemove)
    if (checkWrite.Contains(item))
      checkWrite.Remove(item);
  
  // List the null sockets
  List<Socket> errorToRemove;
  for (int32 i = 0; i < nbCheckError; i++)
    if (checkErrorHandles[i] == 0)
      errorToRemove.Add(checkError[i]);
  
  // Remove the null sockets
  for (Socket item : errorToRemove)
    if (checkError.Contains(item))
      checkError.Remove(item);
  
  return status;
}

int32 Socket::Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags) {
  SocketError errorCode = SocketError::Success;
  int32 numberOfBytesSended = this->Send(buffer, offset, size, socketFlags, errorCode);
  if (errorCode != SocketError::Success)
    throw SocketException((int32)errorCode, _caller);
  return numberOfBytesSended;
}

int32 Socket::Send(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, SocketError& errorCode) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(_caller);
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);
  
  int32 numberOfBytesSended = __OS::CoreApi::Socket::Send(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags);
  errorCode = numberOfBytesSended == -1 ? (SocketError)__OS::CoreApi::Socket::GetLastError() : SocketError::Success;
  return numberOfBytesSended;
}

int32 Socket::SendTo(const Array<byte>& buffer, int32 offset, int32 size, SocketFlags socketFlags, const IPEndPoint& endPoint) {
  if (offset < 0 || size < 0 || offset + size > buffer.Length)
    throw IndexOutOfRangeException(_caller);
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);

  SocketAddress socketAddress = endPoint.Serialize();
  int32 numberOfBytesSended = __OS::CoreApi::Socket::SendTo(this->data->socket, (byte*)&buffer.Data()[offset], size, (int32)socketFlags, (byte*)socketAddress.bytes.Data(), socketAddress.Size);
  if (numberOfBytesSended == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
  return numberOfBytesSended;
}

void Socket::SetBlocking(bool blocking) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  if (__OS::CoreApi::Socket::SetBlocking(this->data->socket, blocking) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);

  this->data->nonBlocking = !blocking;
}

void Socket::SetDontFragment(bool dontFragment) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::DontFragment, dontFragment);
}

void Socket::SetDualMode(bool dualMode) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::IPv6Only, !dualMode);
}

void Socket::SetEnableBroadcast(bool enableBroadcast) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::Broadcast, enableBroadcast);
}

void Socket::SetExclusiveAddressUse(bool exclusiveAddressUse) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse, exclusiveAddressUse);
}

void Socket::SetLingerState(const LingerOption &lingerOption) {
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ExclusiveAddressUse, lingerOption);
}

void Socket::SetMulticastLoopback(bool multicastLoopback) {
  SetSocketOption(SocketOptionLevel::IP, SocketOptionName::MulticastLoopback, multicastLoopback);
}

void Socket::SetNoDelay(bool noDelay) {
  SetSocketOption(SocketOptionLevel::Tcp, SocketOptionName::NoDelay, noDelay);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, bool optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  int32 option = 0;
  if (optionValue)
    option = 0xFFFFFFFF;

  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (int32 *)&option, sizeof(option)) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const Array<byte>& optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (byte*)optionValue.Data(), optionValue.Length) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, int32 optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  if (__OS::CoreApi::Socket::SetSocketOption(this->data->socket, socketOptionLevel, socketOptionName, (byte *)&optionValue, sizeof(optionValue)) == -1)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
}

void Socket::SetSocketOption(SocketOptionLevel socketOptionLevel, SocketOptionName socketOptionName, const object& optionValue) {
  if (this->data->socket == IntPtr::Zero())
    throw ObjectClosedException(_caller);
  
  if (is<MulticastOption>(optionValue)) {
    /// @todo
    // Array<byte> optionValue;
    // SetSocketOption(socketOptionLevel, socketOptionName, optionValue);
    throw NotImplementedException(_caller);
  } else if (is<LingerOption>(optionValue)) {
    /// @todo
    // Array<byte> optionValue;
    // SetSocketOption(socketOptionLevel, socketOptionName, optionValue);
    throw NotImplementedException(_caller);
  } else
    throw NotImplementedException(_caller);
}

void Socket::SetReceiveBufferSize(int32 bufferSize) {
  if (bufferSize < 0)
    throw IndexOutOfRangeException(_caller);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveBuffer, bufferSize);
}

void Socket::SetReceiveTimeout(int32 timeout) {
  if (timeout < -1)
    throw IndexOutOfRangeException(_caller);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::ReceiveTimeout, timeout);
}

void Socket::SetSendBufferSize(int32 bufferSize) {
  if (bufferSize < 0)
    throw IndexOutOfRangeException(_caller);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendBuffer, bufferSize);
}

void Socket::SetSendTimeout(int32 timeout) {
  if (timeout < -1)
    throw IndexOutOfRangeException(_caller);
  SetSocketOption(SocketOptionLevel::Socket, SocketOptionName::SendTimeout, timeout);
}

void Socket::SetTtl(int32 ttl) {
  if (this->data->addressFamily != System::Net::Sockets::AddressFamily::InterNetwork && this->data->addressFamily != System::Net::Sockets::AddressFamily::InterNetworkV6)
    throw NotSupportedException(_caller);
  if (ttl < 0)
    throw IndexOutOfRangeException(_caller);
  SetSocketOption(SocketOptionLevel::IP, SocketOptionName::IpTimeToLive, ttl);
}

void Socket::Shutdown(SocketShutdown how) {
  if (this->data->socket == 0)
    throw ObjectClosedException(_caller);
  if (__OS::CoreApi::Socket::Shutdown(this->data->socket, Enum<SocketShutdown>::ToInt32(how)) != 0)
    throw SocketException(__OS::CoreApi::Socket::GetLastError(), _caller);
}
