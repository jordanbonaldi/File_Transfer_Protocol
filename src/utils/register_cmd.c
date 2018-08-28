/*
** EPITECH PROJECT, 2018
** registering
** File description:
** registering
*/

# include "project.h"

void loading_log(_)
{
	__create_command("USER", &command_user);
	__create_command("PASS", &command_pass);
	__create_command("QUIT", &command_quit);
	__create_command("NOOP", &command_noop);
	__create_command("HELP", &command_help);
	__create_command("PWD", &command_pwd);
	__create_command("CWD", &command_cwd);
	__create_command("CDUP", &command_cdup);
	__create_command("DELE", &command_del);
	__create_command("PORT", &command_port);
	__create_command("PASV", &command_pasv);
	__create_command("LIST", &command_list);
	__create_command("EXEC", &command_exec);
	__create_command("RETR", &command_retr);
	__create_command("STOR", &command_stor);
	__create_command("SYST", &command_syst);
}
