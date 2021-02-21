#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void printStruct(const struct stat *p);
void printMode(mode_t mode);
void printTime(time_t time);

int main()
{
    struct stat test;
    stat("Makefile", &test);

    printStruct(&test);
    return 0;
}

void printStruct(const struct stat *p)
{
    if(p == NULL)
        return;

    printf("Device ID: %ld\n", p->st_dev);
    printf("Inode: %ld\n", p->st_ino);
    
    //print file permissions
    printMode(p->st_mode);

    printf("Uid: %d, Gid: %d\n", p->st_uid, p->st_gid);
    printf("Size: %ld\n", p->st_size);
    printf("Blocksize: %ld, Blockcount: %ld\n", p->st_blksize, p->st_blocks);

    printTime(p->st_atime);
}
void printMode(mode_t mode)
{
    printf("Mode: %o\n", mode);
}
void printTime(time_t time)
{
    struct tm *timeinfo = localtime(&time);
    char buf[50];

    strftime(buf, sizeof(buf), "%F %T", timeinfo);
    printf("%s\n", buf);
}
