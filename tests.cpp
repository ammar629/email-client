#include "test.h"

const string TEST::AUTH::email = "";
const string TEST::AUTH::password = "";
const string TEST::recipient_email = "";

void TEST::text(EMAIL mail)
{
	mail.SetSenderName("User");
	mail.SetSenderMail(AUTH::email);
	mail.SetReplyTo(AUTH::email);
	mail.SetSubject("Test");
	mail.AddRecipient(recipient_email);
	mail.SetXPriority(XPRIORITY_NORMAL);
	mail.SetXMailer("My email client");

	mail.AddMsgLine("Hello,");
	mail.AddMsgLine("");
	mail.AddMsgLine("...");
	mail.AddMsgLine("How are you today?");
	mail.AddMsgLine("");
	mail.AddMsgLine("Regards");
	mail.ModMsgLine(5, "regards");
	mail.DelMsgLine(2);
	mail.AddMsgLine("User");
}

void TEST::attachments(EMAIL mail)
{
	mail.SetSenderName("User");
	mail.SetSenderMail(AUTH::email);
	mail.SetReplyTo(AUTH::email);
	mail.SetSubject("Test");
	mail.AddRecipient(recipient_email);
	mail.SetXPriority(XPRIORITY_NORMAL);
	mail.SetXMailer("My email client");

	mail.AddMsgLine("��� ������ ���� � ������");

	mail.AddAttachment("test-files/1.jpg");
	mail.AddAttachment("test-files/2.jpg");
	mail.AddAttachment("test-files/3.jpg");
	mail.AddAttachment("test-files/4.jpg");
	mail.AddAttachment("test-files/5.jpg");
	mail.AddAttachment("test-files/6.jpg");
	mail.AddAttachment("test-files/7.jpg");
	mail.AddAttachment("test-files/8.jpg");
	mail.AddAttachment("./test-files/9.jpg");
	mail.AddAttachment("./test-files/10.jpg");
	mail.AddAttachment("./test-files/11jpg");
	mail.AddAttachment("./test-files/12.jpg");
	mail.AddAttachment("./test-files/13.jpg");
	mail.AddAttachment("./test-files/14.jpg");
	mail.AddAttachment("./test-files/15.jpg");
	mail.AddAttachment("./test-files/16.jpg");
	mail.AddAttachment("./test-files/17.jpg");
	mail.AddAttachment("./test-files/18.jpg");
	mail.AddAttachment("test-files/19_23.rar");
	mail.AddAttachment("test-files/19_23.zip");
	mail.AddAttachment("test-files/24.txt");
}

bool TEST::GMAIL::tls_test_attachments()
{
	EMAIL mail;

	mail.useGmail();
	mail.SetAuth(TEST::AUTH::email, TEST::AUTH::password);
	mail.SetSecurity(USE_TLS);

	text(mail);

	mail.send();

	std::cout << "Mail was send successfully.\n";
	return 0;
}

bool TEST::GMAIL::tls_test_text()
{
	EMAIL mail;

	mail.useGmail();
	mail.SetAuth(TEST::AUTH::email, TEST::AUTH::password);
	mail.SetSecurity(USE_TLS);

	attachments(mail);

	mail.send();

	std::cout << "Mail was send successfully.\n";
	return 0;
}

bool TEST::GMAIL::ssl_test_text()
{
	EMAIL mail;

	mail.useGmail();
	mail.SetAuth(TEST::AUTH::email, TEST::AUTH::password);
	mail.SetSecurity(USE_SSL);

	text(mail);

	mail.send();

	std::cout << "Mail was send successfully.\n";
	return 0;
}

bool TEST::GMAIL::ssl_test_attachments()
{
	EMAIL mail;

	mail.useGmail();
	mail.SetAuth(TEST::AUTH::email, TEST::AUTH::password);
	mail.SetSecurity(USE_SSL);

	attachments(mail);

	mail.send();

	std::cout << "Mail was send successfully.\n";
	return 0;
}