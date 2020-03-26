#pragma once
#ifndef _ERRORS_H_
#define _ERRORS_H_
#include <string>
#include <sstream>
using namespace std;

#define SUCCESS 0
#define FAIL(code) ERRORS::processing(code)

using RETCODE = unsigned int;

enum ERR
{
	CSMTP_NO_ERROR = 0,
	//Unable to initialise winsock2
	WSA_STARTUP,
	//Wrong version of the winsock2
	WSA_VER,
	//Function send() failed
	WSA_SEND,
	//Function recv() failed
	WSA_RECV,
	//Function connect failed
	WSA_CONNECT,
	//Unable to determine remote server
	WSA_GETHOSTBY_NAME_ADDR,
	//Invalid winsock2 socket
	WSA_INVALID_SOCKET,
	//Function hostname() failed
	WSA_HOSTNAME,
	//Function ioctlsocket() failed
	WSA_IOCTLSOCKET,
	//Improper IPv4 address
	BAD_IPV4_ADDR,
	// 
	SELECT_TIMEOUT,
	// 
	WSA_SELECT,
	//Undefined message header
	UNDEF_MSG_HEADER,
	//Undefined mail sender
	UNDEF_MAIL_FROM,
	//Undefined message subject
	UNDEF_SUBJECT,
	//Undefined at least one reciepent
	UNDEF_RECIPIENTS,
	//Undefined recipent mail
	UNDEF_RECIPIENT_MAIL,
	//Undefined user login
	UNDEF_LOGIN,
	//Undefined user password
	UNDEF_PASSWORD,
	//Invalid user login or password
	BAD_LOGIN_PASSWORD,
	//Server returned a bad digest MD5 response
	BAD_DIGEST_RESPONSE,
	//Unable to determine server name for digest MD5 response
	BAD_SERVER_NAME,
	//Server returned error after sending MAIL FROM
	COMMAND_MAIL_FROM,
	//Server returned error after sending EHLO
	COMMAND_EHLO,
	//Server returned error after sending AUTH PLAIN
	COMMAND_AUTH_PLAIN,
	//Server returned error after sending AUTH LOGIN
	COMMAND_AUTH_LOGIN,
	//Server returned error after sending AUTH CRAM-MD5
	COMMAND_AUTH_CRAMMD5,
	//Server returned error after sending AUTH DIGEST-MD5
	COMMAND_AUTH_DIGESTMD5,
	//Server returned error after sending MD5 DIGEST
	COMMAND_DIGESTMD5,
	//Server returned error after sending DATA
	COMMAND_DATA,
	//Server returned error after sending QUIT
	COMMAND_QUIT,
	//Server returned error after sending RCPT TO
	COMMAND_RCPT_TO,
	//Error in message body
	MSG_BODY_ERROR,
	//Server has closed the connection
	CONNECTION_CLOSED,
	//Server is not ready
	SERVER_NOT_READY,
	//Server not responding
	SERVER_NOT_RESPONDING,
	//Attachment file does not exist
	FILE_NOT_EXIST,
	//Message is too big
	MSG_TOO_BIG,
	//Bad login or password
	BAD_LOGIN_PASS,
	//Undefined xyz SMTP response
	UNDEF_XYZ_RESPONSE,
	//Lack of memory
	LACK_OF_MEMORY,
	//time() error
	TIME_ERROR,
	//SendBuf is empty
	SENDBUF_IS_EMPTY,
	// Specified element index is out of vector size
	OUT_OF_VECTOR_RANGE,
	//Server returned error after sending STARTTLS
	COMMAND_EHLO_STARTTLS,
	//SSL problem
	SSL_PROBLEM,
	//Failed to send data block
	COMMAND_DATABLOCK,
	//The STARTTLS command is not supported by the server
	STARTTLS_NOT_SUPPORTED,
	//AUTH LOGIN is not supported by the server
	LOGIN_NOT_SUPPORTED
};

class ERRORS
{
public:
	static int processing(ERR err_);
	static string GetErrorText(void);
	static void addtrace();
private:
	static ERR ErrorCode;
};

#endif