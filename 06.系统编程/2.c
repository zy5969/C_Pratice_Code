//测试文件2
/*读文件read()

<unistd.h>

read(int fd文件描述符，void *buf（内存首地址，写入fd数据），字节数);

返回写入字节数，-1表示读错。

写文件write()

write(int fd文件描述符，void *buf（内存首地址，写入fd数据），字节数);

返回读取到的字节数，0表示文件结束。
*/

//<sys/types.h> <sys/stat.h><fcntl.h>

//open(文件名（路径）， bit源码组合)；（rxw/www等）

//open(文件名， bit源码组合， 文件权限)；

