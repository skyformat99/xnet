#pragma once
#include <map>
#include <memory>
#include <functional>
#include <vector>
#include <mutex>
#include <cassert>
#include <exception>
#include <iostream>
#include "common/guard.hpp"
#include "common/no_copy_able.hpp"
#ifdef _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define FD_SETSIZE      1024
#include <winsock2.h>
#include <mswsock.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#include "detail/iocp.hpp"
#endif
#include "detail/detail.hpp"
#include "xnet.hpp"
#include "detail/select.hpp"
#ifdef _WIN32
#define WIN_SELECT 1
#define IOCP 1
namespace xnet
{
	namespace detail
	{
#if WIN_SELECT
		typedef select::connection_impl connection_impl;
		typedef select::acceptor_impl acceptor_impl;
		typedef select::proactor_impl proactor_impl;
		typedef select::connector_impl connector_impl;
		typedef select::socket_exception socket_exception;
#elif IOCP
		typedef iocp::connection_impl connection_impl;
		typedef iocp::acceptor_impl acceptor_impl;
		typedef iocp::proactor_impl proactor_impl;
		typedef iocp::connector_impl connector_impl;
		typedef iocp::socket_exception socket_exception;
#endif
		
	}
}
#endif