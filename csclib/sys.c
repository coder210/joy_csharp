//#include "../mono.h"
//#include "../sys.h"
//#include "csclib.h"
//
//
//static bool csys_bind(uint64_t sockfd, MonoString* ip, int port)
//{
//	char* cstr_ip;
//	bool result;
//	cstr_ip = livS_mono_string_to_utf8(ip);
//	result = sys_bind(sockfd, cstr_ip, port);
//	livS_mono_free(cstr_ip);
//	return result;
//}
//
//static int 
//csys_recvfrom(uint64_t sockfd, MonoArray** out_bytes, MonoString** ip, int* port)
//{
//	char cstr_buf[JOY_MAX_BUFFER], cstr_ip[JOY_MAX_IP];
//	int len;
//	SDL_memset(cstr_ip, 0, JOY_MAX_IP);
//	len = sys_recvfrom(sockfd, cstr_buf, cstr_ip, port);
//	*out_bytes = livS_mono_array_new(livS_mono_domain_get(), livS_mono_get_byte_class(), len);
//	char* data = livS_mono_array_addr(*out_bytes, sizeof(char), 0);
//	for (int i = 0; i < len; i++) {
//		data[i] = cstr_buf[i];
//	}
//	*ip = livS_mono_string_new(livS_mono_domain_get(), cstr_ip);
//	return len;
//}
//
//static int
//csys_sendto(uint64_t sockfd, MonoArray* bytes, MonoString* ip, int port)
//{
//	int result, c_buf_len;
//	char* c_buf, * cstr_ip;
//	c_buf_len = livS_mono_array_length(bytes);
//	c_buf = livS_mono_array_addr(bytes, sizeof(char), 0);
//	cstr_ip = livS_mono_string_to_utf8(ip);
//	result = sys_sendto(sockfd, c_buf, c_buf_len, cstr_ip, port);
//	livS_mono_free(cstr_ip);
//	return result;
//}
//
//void csopen_sys()
//{
//	livS_mono_add_internal_call("Joy.Sys::InitNetEnv", sys_init_netenv);
//	livS_mono_add_internal_call("Joy.Sys::ReleaseNetEnv", sys_release_netenv);
//	livS_mono_add_internal_call("Joy.Sys::Anyaddr", sys_anyaddr);
//	livS_mono_add_internal_call("Joy.Sys::CloseSocket", sys_closesocket);
//	livS_mono_add_internal_call("Joy.Sys::SetSockSndtimeo", sys_set_sock_sndtimeo);
//	livS_mono_add_internal_call("Joy.Sys::SetSockRcvtimeo", sys_set_sock_rcvtimeo);
//	livS_mono_add_internal_call("Joy.Sys::Tcp", sys_tcp);
//	livS_mono_add_internal_call("Joy.Sys::Udp", sys_udp);
//	livS_mono_add_internal_call("Joy.Sys::Bind", csys_bind);
//	livS_mono_add_internal_call("Joy.Sys::Connect", sys_connect);
//	livS_mono_add_internal_call("Joy.Sys::Listen", sys_listen);
//	livS_mono_add_internal_call("Joy.Sys::Accept", sys_accept);
//	livS_mono_add_internal_call("Joy.Sys::Send", sys_send);
//	livS_mono_add_internal_call("Joy.Sys::Recv", sys_recv);
//	livS_mono_add_internal_call("Joy.Sys::Recvfrom", csys_recvfrom);
//	livS_mono_add_internal_call("Joy.Sys::SendTo", csys_sendto);
//	livS_mono_add_internal_call("Joy.Sys::CurrentTime", sys_current_time);
//}
