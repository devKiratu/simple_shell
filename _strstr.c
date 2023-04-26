#include "main.h"

/**
 * _strstr - locates a substring @needle in string @haystack
 *
 * @needle: substring to search for
 * @haystack: containing string
 *
 * Return: pointer to located substring or NULL if not found
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j, found = 0;

	if (*needle == 0)
		return (haystack);

	while (haystack[i] != '\0')
	{
		j = 0;

		if (haystack[i] == needle[j])
		{
			while (needle[j] != '\0')
			{
				if (needle[j] == haystack[i + j])
				{
					j++;
					found = 1;
				}
				else
				{
					found = 0;
					break;
				}
			}

			if (found)
				return (&haystack[i]);
		}
		i++;
	}

	return (0);
}
