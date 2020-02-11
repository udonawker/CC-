#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//↓ テンポラリファイル名
#define TMPFILE "/tmp/my_tmp_file"         
#define MSGTEXT "IPA is a Japanese quasi-government\n" \
                "organization established in accor-\n" \
                "dance with The Law for Information\n" \
                "Processing Technology Promotion,\n" \
                "(Law No.90, May 22, 1979).\n"

int main(void)
{
   char readbuf[1024];
   int fd;

   fd = open(TMPFILE, O_RDWR|O_CREAT|O_EXCL, S_IRUSR|S_IWUSR);
   if(fd==-1) exit(1);                     //↑ テンポラリファイル作成

   unlink(TMPFILE);                        //← オープンしたまま削除

   if(write(fd, MSGTEXT, sizeof(MSGTEXT))==-1) exit(1);
                                           //↑ 削除しても書き込み可能
   if(lseek(fd, 0, SEEK_SET)==-1) exit(1); //← 削除してもシーク可能

   memset(readbuf, 0, sizeof(readbuf));
   if(read(fd, readbuf, sizeof(readbuf)-1)==-1) exit(1); 
                                           //↑ 削除しても読み込み可能
   printf("%s", readbuf);                  //← 読み込み結果を表示

   close(fd);                              //← クローズ
   return 0;
}
