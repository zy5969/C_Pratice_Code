/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Dec 2023 09:47:32 AM CST
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>

//自定义
//调整宏
#ifdef _D
#define DBG(fmt, args...) printf(fmt, ##args)//##连接多个参数时去掉","，#不去
#else
#define DBG(fmt, args...)
#endif
//日志系统

#define LOG_LEVEL_INFO 0
#define LOG_LEVEL_WARNING 1
#define LOG_LEVEL_ERROR 2

//#define ToDo 

#endif
