#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argcount, char *argv[])
{
char source[100000],destination[1000],dest[1000],copy[1000],copyto[1000];
int sofd, destfd,sd,dd;
char readbuffer[10000];
struct dirent *dir;
struct stat stat;
for(int i = 1; i<argcount-1; i++)
{ 
	strcpy(source,argv[i]);
	DIR* directory = opendir(source);
	
	if(directory != NULL)
{
	while((dir = readdir(directory)) != NULL)
{
	
 	if(strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0)
	{
		continue;
	}

	strcpy(source,argv[i]);
	strcat(source,"/");
	strcat(source,dir->d_name);
	strcpy(dest,argv[argcount-1]);
	strcat(dest,"/");
	strcat(dest,dir->d_name);
	sofd = open(source, O_RDONLY);
	destfd = open(dest, O_CREAT | O_WRONLY);
	while((sd = read(sofd,&readbuffer,sizeof(readbuffer))) > 0)
	{
	dd = write(destfd,&readbuffer,sd);
	}	
} 
	close(sofd);
	close(destfd);	
}
	else
{
	strcpy(source,argv[i]);
	int k =0;
	for(int i = strlen(source)-1; i<=0; i++)
	{
	if(source[i] == '\\')
		break;
	else
	{
		copy[k] = source[i];
	}
	k++;
	}
	int j =0;
	for(int i = strlen(copy)-1; i<=0; i++)
	{
	copyto[j] = copy[i];
	j++;
	}
	strcpy(dest,argv[argcount-1]);
	strcat(dest,"/");
	strcat(dest,copyto);
	sofd = open(copyto, O_RDONLY);
	destfd = open(dest, O_CREAT | O_WRONLY);
	while((sd = read(sofd,&readbuffer,sizeof(readbuffer))) > 0)
	{
	dd = write(destfd,&readbuffer,sd);
	}
	close(sofd);
	close(destfd);	
}
} 

return 0;
}
