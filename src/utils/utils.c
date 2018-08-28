/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils
*/

# include "project.h"

static int calc_size(char *str, char const sp)
{
	char *tmp = str;
	int i = 0;

	while (*tmp) {
		if (*tmp == sp)
			++i;
		++tmp;
	}
	return i;
}

char **split(char *str, char const sp)
{
	char *s = str;
	char **results = NULL;
	int count;

	count = calc_size(s, sp);
	results = malloc((count + 2) * sizeof(char *));
	results[0] = s;
	count = 1;
	while (*s) {
		if (*s == sp) {
			*s = 0;
			++s;
			results[count++] = s;
		}
		else
			++s;
	}
	results[count] = NULL;
	return results;
}

char *get_client_addr(void)
{
	char hostname[MAX_LENGTH];
	struct hostent *host;
	struct in_addr addr;

	gethostname(hostname, MAX_LENGTH);
	host = gethostbyname(hostname);
	memcpy(&addr, host->h_addr_list[0], sizeof(struct in_addr));
	return inet_ntoa(addr);
}
