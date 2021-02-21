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
    printf("User: ");
    mode_t user_perm = mode & S_IRWXU;
    if( user_perm == 0)
        printf("No permissions\n");
    else
    {
        if(user_perm & S_IRUSR)
            printf("(read) ");
        if(user_perm & S_IWUSR)
            printf("(write) ");
        if(user_perm & S_IXUSR)
            printf("(execute)");

        puts("");
    }

    printf("Group: ");
    mode_t grp_perm = mode & S_IRWXG;
    if( grp_perm == 0)
        printf("No permissions\n");
    else
    {
        if(grp_perm & S_IRGRP)
            printf("(read) ");
        if(grp_perm & S_IWGRP)
            printf("(write) ");
        if(grp_perm & S_IXGRP)
            printf("(execute)");

        puts("");
    }
    
    printf("Others: ");
    mode_t other_perm = mode & S_IRWXO;
    if( other_perm == 0)
        printf("No permissions\n");
    else
    {
        if(other_perm & S_IROTH)
            printf("(read) ");
        if(other_perm & S_IWOTH)
            printf("(write) ");
        if(other_perm & S_IXOTH)
            printf("(execute)");

        puts("");
    }
}
void printTime(time_t time)
{
    struct tm *timeinfo = localtime(&time);
    char buf[50];

    strftime(buf, sizeof(buf), "%F %T", timeinfo);
    printf("%s\n", buf);
}
