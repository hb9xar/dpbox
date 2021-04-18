/* Header for module box_file, generated by p2c */
#ifndef BOX_FILE_H
#define BOX_FILE_H

#include "pastrix.h"
#include "boxglobl.h"
#include "yapp.h"
#include "boxlocal.h"

extern void check_disk_full(void);
extern short open_index(char *brett, short mode, boolean cache, boolean vorwaerts);
extern void close_index(short *handle);
extern void read_index(short handle, short nr, indexstruct *ibuf);
extern short write_index(short handle, short nr, indexstruct *ibuf);
extern void read_log(short handle, long nr, boxlogstruct *ibuf);
extern void write_log(short handle, long nr, boxlogstruct *ibuf);
extern void write_log_and_bid(char *brett1, short nummer, indexstruct header);
extern void show_all_user_at(short unr, char *call, boolean del, boolean del2,
			     boolean only_count, char *all_count);
extern void dispose_mptr(void);
extern void load_mptr(void);
extern boolean update_mybbsfile(boolean by_usercommand, char *call, time_t *updatetime,
				char *mybbs, char *mybbsmode);
extern void init_ufcache(void);
extern void clear_uf_cache(char *call);
extern void convert_ufil(boolean with_ext_strings, indexstruct header,
			 userstruct *rec);
extern void code_ufil(userstruct *rec, indexstruct *header);
extern void load_userfile(boolean only_m, boolean with_ext_strings,
			  char *calls, userstruct *rec);
extern void save_userfile(userstruct *rec);
extern void user_mybbs(char *call, char *mbx);
extern short last_valid(short unr, char *brett);
extern void alter_fwd(char what, char *bid, long new_msgnum, char *new_board, char *sfcall);
extern boolean recompile_fwd(void);
extern void alter_log(boolean onram, long msgnumber, unsigned short msgflags, char what, char *info);
extern void recompile_log(short unr);
extern short boxcheck(boolean all, char *callx);
extern short check_held_messages(short unr, short display_if_less_than);
extern void show_hold(short unr, short disp_if_less);
extern void send_tcpip_protocol_frame(short unr);
extern void load_userinfo_for_change(boolean only_m, char *callx, userstruct *ufil);
extern void sort_new_mail4(void);
extern void sort_new_mail2(short unr, char *pattern, char *rcall1);



#endif /*BOX_FILE_H*/
