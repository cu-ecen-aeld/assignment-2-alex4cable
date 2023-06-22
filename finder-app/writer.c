#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#include <sys/stat.h>
#include <sys/types.h>

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <string.h>

#define APPNAME      0U
#define WRITEFILEIDX 1U
#define WRITESTR     2U 

int main(int argc, char *argv[]) 
{
	
	const int iExpcetedNbOfArgs = 3;

    openlog(0,0,LOG_USER);

    if (argc != iExpcetedNbOfArgs) 
	{
        syslog(LOG_ERR, "Usage: %s <writefile> <writestr>\n", argv[APPNAME]);
        return 1;
    }

    char* writefile = argv[WRITEFILEIDX];
    char* writestr = argv[WRITESTR];

    // Create parent directories if they don't exist
    char* parent_dir = strdup(writefile);
	
	if (parent_dir == 0)
	{
        syslog(LOG_ERR, "Memory allocation failed!");
        return 1;		
	}
	else
	{
			
		char* last_slash = strrchr(parent_dir, '/');
		
		// Remove filename from directory name
		// success?	
		if (last_slash != 0) 
		{
			*last_slash = '\0';
			
			// read write execute for user, group, everbody
			mkdir(parent_dir, 0777);
		}
		
		free(parent_dir);

		FILE *fp = fopen(writefile, "w");
		
		// success?
		if (fp == 0) 
		{
			syslog(LOG_ERR, "Error opening file %s\n", writefile);
			return 1;
		}

		syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);
		fprintf(fp, "%s", writestr);
		
		fclose(fp);
	}
    return 0;
}