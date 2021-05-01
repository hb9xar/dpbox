/* BOXSTART: Starter and audit for TNT/DPBOX
   Copyright (C) 1995 by Mark Wahl
   created: Mark Wahl DL4YBG 95/08/06
   updated: Mark Wahl DL4YBG 95/08/08
   changed: Nils, DF6LN, Joachim Schurig, DL8HBS 99/09/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <termios.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <pwd.h>
#include <unistd.h>

#define MAX_LINESIZE 256

static int wrong_usage;
static int scanned;
static char boxstart_initfile[MAX_LINESIZE];
static int warning;
static FILE *init_file_fp;
static char *str_ptr;
static char tmp_str[MAX_LINESIZE];
static int file_end;
static int file_corrupt;
static char line[MAX_LINESIZE];
static int state;
static FILE *fp;
static struct stat stat_buf;
static int start_it;
static char proc_str[MAX_LINESIZE];
static char proc_dir[MAX_LINESIZE+10];
static char *nl_ptr;

#define S_PROCFILE 0
#define S_PROGRAM 1

#define LOCKFILE "/tmp/boxstart.lck"

int main(int argc,char *argv[])
{
  int fd;
  int ignore_lock;
  
  ignore_lock = 0;
  strcpy(boxstart_initfile,"boxstart.ini");
  wrong_usage = 0;
  scanned = 1;
  while ((scanned < argc) && (!wrong_usage)) {
    if (strcmp(argv[scanned],"-i") == 0) {
      scanned++;
      if (scanned < argc) {
        strcpy(boxstart_initfile,argv[scanned]);
      }
      else wrong_usage = 1;
    }
    else if (strcmp(argv[scanned],"-u") == 0) {
      ignore_lock = 1;
    }
    else {
      wrong_usage = 1;
    }
    scanned++;
  }
  if (wrong_usage) {
    printf("Usage : boxstart [-u] [-i <init-file>]\n");
    exit(1);
  }

  if (ignore_lock)
    fd = open(LOCKFILE,O_RDWR|O_CREAT|O_TRUNC,0600);
  else
    fd = open(LOCKFILE,O_RDWR|O_CREAT|O_EXCL,0600);
  if (fd == -1) {
    printf("ERROR: Can't create lockfile\n");
    exit(1);
  }
  close(fd);

  warning = 0;
  if (!(init_file_fp = fopen(boxstart_initfile,"r"))) {
    str_ptr = getenv("HOME");
    if (str_ptr != NULL) {
      strcpy(tmp_str,str_ptr);
      strcat(tmp_str,"/");
      strcat(tmp_str,boxstart_initfile);
      if (!(init_file_fp = fopen(tmp_str,"r"))) {
        warning = 1;
      }
    }
    else warning = 1;
  }
  if (warning) {
    printf("ERROR: %s not found\n\n",boxstart_initfile);
    unlink(LOCKFILE);
    exit(1);
  }
  state = S_PROCFILE;
  file_end = 0;
  file_corrupt = 0;
  while (!file_end) {
    if (fgets(line,MAX_LINESIZE,init_file_fp) == NULL) {
      file_end = 1;
      if (state == S_PROGRAM) file_corrupt = 1;
    }
    else {
      if (strlen(line) == MAX_LINESIZE) {
        file_end = 1;
        file_corrupt = 1;
      }
      else {
        if (line[0] != '#') {
          switch (state) {
          case S_PROCFILE:
            start_it = 0;
            nl_ptr = strchr(line,'\n');
            if (nl_ptr != NULL) *nl_ptr = '\0';
            fp = fopen(line,"r");
            if (fp == NULL) {
              start_it = 1;
            }
            else {
              if (fgets(proc_str,MAX_LINESIZE,fp) == NULL) {
                fclose(fp);
                start_it = 1;
              }
              else {
                strcpy(proc_dir,"/proc/");
                strcat(proc_dir,proc_str);
                nl_ptr = strchr(proc_dir,'\n');
                if (nl_ptr != NULL) *nl_ptr = '\0';
                if (stat(proc_dir,&stat_buf) == -1) {
                  start_it = 1;
                }
                else {
                  start_it = 0;
                }
              }
            }
            state = S_PROGRAM;
            break;
          case S_PROGRAM:
            if (start_it) {
              nl_ptr = strchr(line,'\n');
              if (nl_ptr != NULL) *nl_ptr = '\0';
              printf("Starting %s\n",line);
              system(line);
            }
            state = S_PROCFILE;
            break;
          }
        }
      }
    }
  }
  fclose(init_file_fp);
  if (file_corrupt) {
    if (line == NULL) line[0] = '\0';
    printf("ERROR: %s is in wrong format, wrong line:\n%s\n\n",
           boxstart_initfile,line);
    unlink(LOCKFILE);
    exit(1);
  }
  unlink(LOCKFILE);
  exit(0);
}
