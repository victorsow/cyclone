/*
Copyright(C) thecodeway.com
*/
#ifndef _CYCLONE_NETWORK_ADDRESS_H_
#define _CYCLONE_NETWORK_ADDRESS_H_

#include <cyclone_config.h>

namespace cyclone
{

class Address
{
public:
	//// get native address 
	const struct sockaddr_in& get_sockaddr_in() const { return m_address; }

	//// get ip address like "123.123.123.123"
	const char*	get_ip(void) const;
	uint16_t	get_port(void) const;

public:
	/// Constructs an endpoint with given port number.
	/// Mostly used in TcpServer listening.
	/// loopbackOnly bind to "127.0.0.1" as local port or "0.0.0.0" as internet port
	explicit Address(uint16_t port, bool loopbackOnly);

	/// Constructs an endpoint with given ip and port.
	/// @c ip should be "123.123.123.123"
	Address(const char* ip, uint16_t port);

	/// Constructs an endpoint with given struct @c sockaddr_in
	/// Mostly used when accepting new connections
	Address(const struct sockaddr_in& addr);

	/// Constructs current address to which the socket sfd is bound 
	/// @param peer constructs the peer address of active socket
	Address(bool peer, socket_t sfd);

	Address(const Address& other);
	Address();

private:
	struct sockaddr_in m_address;

	enum { IP_ADDRESS_LEN=32 };
	char m_ip_string[IP_ADDRESS_LEN];
};

}

#endif

