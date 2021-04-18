/* Header for module box_sys, generated by p2c */
#ifndef BOX_SYS_H
#define BOX_SYS_H

#include "pastrix.h"
#include "boxglobl.h"

typedef void (*cbaproc)(const short unr, const char *s);

extern void box_rtitle(boolean set_it, short unr, char *rtitle);
extern void box_ttouch(short unr);
extern void show_ext_command_result(short unr);
extern void update_dp2(short unr);
extern void update_dp(short unr, char *eingabe);
extern void write_file2(short unr, char *eingabe);
extern void write_file(short unr, char *eingabe);
extern void yapp_responses(short unr, char *info, long infosize);
extern void yapp_input(short unr, char *info, long infosize);
extern boolean read_file(boolean delete_afterwards, short unr, char *eingabe);
extern boolean read_filepart(short unr);
extern void abort_fileread(short unr);
extern void read_file_immediately(boolean delete_afterwards, short unr, char *eingabe);
extern void show_file_dir(short unr, char *eingabe);
extern void calc_boxactivity(short unr, cbaproc outputproc);
extern void show_boxactivity(short unr);
extern void check_sysanswer(short unr, char *eingabe);
extern void answer_sysrequest(short unr, boolean MD2, boolean MD5);
extern void show_stat(short unr, short x);
extern void update_digimap(short unr, char *updatefile);
extern void calc_lonstr(double lon, char *str);
extern void calc_latstr(double lat, char *str);
extern void show_prefix_information(short unr, char *call, char *loc);
extern void calc_qthdist(short unr, char *loc1, char *loc2);
extern void show_user(short unr, char *call, char *option);
extern void set_password(short unr, boolean superv, char *eingabe);
extern void import_pw(short unr, char *eingabe);
extern void change_unprotomode(short unr, char *eingabe);
extern void change_md2sf(short unr, char *eingabe, boolean MD5);
extern void change_fbbmode(short unr, char *eingabe);
extern void change_prompt(short unr, char *eingabe);
extern void change_mailbeacon(short unr, char *eingabe);
extern void change_readlock(short unr, char *eingabe);
extern void change_ttl(short unr, char *eingabe);
extern void change_startup(short unr, char *eingabe);
extern void change_mybbs(short unr, char *callx, char *bbs, long updatetime,
			 char *level, char mybbsmode, boolean update, boolean fwd);
extern void change_levels(short unr, short cnr, char *callx, short lvl);
extern void change_name(short unr, char *callx, char *w);
extern boolean valid_language(char *lan);
extern void show_languages(short unr);
extern void change_language(short unr, char *callx, char *w);
extern void show_systemtime(short unr);
extern void new_login(short unr, char *times);
extern void show_version(short unr, boolean extended);
extern void disc_user(short unr, char *eingabe);
extern void write_ctext(short unr, char *eingabe);
extern void enter_ctext(short unr);
extern void search_bull(short unr, char *w, boolean kill, boolean add);
extern void set_talk_mode(short unr, char *w);
extern void end_talk_mode(short unr, boolean prompt);
extern void talk_line(short unr, char *eingabe);
extern void msgwuser(short unr, boolean immediate, char *s, boolean cr);
extern void send_msg(short unr, char *w, char *eingabe);
extern void reset_to_term(short unr, boolean to_sat, boolean to_node);
extern boolean open_shell(short unr, boolean transparent);
extern void call_runprg(boolean extern_, short unr, char *fname,
			char *rkommando, boolean full_gem, char *add_environment);
extern void set_comp_mode(short unr, char *w);
extern void stelle_uhr(char *eingabe, boolean datum);
extern void calc_pwdb(char *call, char *code, char *pw);
extern void gimme_five_pw_numbers(char *pw, char *numbers);
extern void calc_pwtn(char *call, char *code, char *pw);
extern void jitter_pwtn(char *pw);
extern void generate_dbpwfile(short unr, char *fname, char *options);
extern boolean is_german(char *w);
extern boolean for_german_readers(char *call1, char *call2, char *mbx);
extern void sig_german_authinfo(char *call, char *mbx, char *ret);
extern void create_sfstat(short unr, char *eingabe);
extern void generate_sfstat(short unr);
extern void readjust_dayly_sfcount(void);
extern void do_config(short unr, char *filename, char *eingabe);
extern void do_stripcr(short unr, char *filename);
extern void set_maxread(short unr, char *w, char *eingabe);

#endif /*BOX_SYS_H*/
