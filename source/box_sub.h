/* Header for module box_sub, generated by p2c */
#ifndef BOX_SUB_H
#define BOX_SUB_H

#include "pastrix.h"
#include "boxglobl.h"
#include "yapp.h"
#include "boxlocal.h"

extern void send_final_unproto();
extern void send_new_unproto_header(boxlogstruct header);
extern void send_requested_unproto(unprotoportstype *hp);
extern void unproto_request1(char *call, char *port, char *path, char *s);
extern void clear_msgnumarr(void);
extern void fill_msgnumarr(void);
extern short msgnum2board(long msgnum, char *board);
extern long msgnum2centry(long msgnum, boxlogstruct *log, boolean fuzzy);
extern short actual_connects(void);
extern boolean wildcardcompare(short fangraster, char *w, char *t, char *wr);
extern long cpu_usage(short unr);
extern void expand_macro(short unr, char *hs);
extern boolean in_rsysops_boards(char *call, char *board);
extern void trace_cmd(short unr, char *w, char *w1);
extern short in_tracecalls(char *call);
extern void delete_trace_from(short unr);
extern void delete_all_tracecalls(void);
extern boolean in_protocalls(char *call);
extern void delete_all_protocalls(void);
extern void reload_proto(void);
extern void proto_cmd(short unr, char *w, char *w1);
extern void get_boxruntime_s(short what, char *hs);
extern time_t get_boxruntime_l(void);
extern void reset_boxruntime(void);
extern void flush_bidseek(void);
extern void flush_bidseek_immediately(void);
extern void update_bidseek(void);
extern boolean load_bidseek(void);
extern void create_hcs(indexstruct *h);
extern boolean check_hcs(indexstruct h);
extern cutboxtyp boxheader(char *zeile);
extern boolean boxrange(short unr);
extern void upd_statistik(short unr, long txbytes, long rxbytes, long start,
			  long stop);
extern void get_btext(short unr, short nr, char *s);
extern void x_w_btext(short unr, short nr, boolean lf);
extern void no_files(short unr, char *name);
extern short find_buser(short tnr, short pchan);
extern short actual_user(char *calls);
extern void show_rfile(short unr, char *base, long size, boolean mit_r,
		       boolean sf, boolean only_headers);
extern void show_textfile(short unr, char *name);
extern void show_help(short unr, char *w);
extern boolean defined_board(char *rubr);
extern void switch_to_default_board(char *rubr);
extern void switch_to_default_fserv_board(char *rubr);
extern void check_verteiler(char *rubr);
extern void check_transfers(char *rubr);
extern void extend_6_to_8(char *rubr);
extern boolean valid_boardname(char *rubrik);
extern boolean strip_invalid_boardname_chars(char *rubrik);
extern void chk_maxlt(unsigned short *lt1, unsigned short ltd);
extern void check_lt_acc(char *rubr, unsigned short *lt, unsigned short *acc);
extern boolean may_sysaccess(short unr, char *board);
extern void check_msgtype(char *msgtype, char *ziel, char *betreff);
extern long truesize(indexstruct rec);
extern char separate_status(char *status, char *ziel, char *absender,
			    char *mbx, char *datum, char *zeit, char *laenge,
			    char *lifetime);
extern void create_status(long additional, boolean hierarchicals, char *name,
			  indexstruct header, char *status);
extern void create_status2(boolean hierarchicals, char *dest, char *absender,
			   long rxdate, long expire_time, long size,
			   char msgtype, char *status);
extern void create_userid(char *call, char *absender, char *datum, char *zeit,
			  char *betreff, char *userid);
extern void new_bid(char *bid);
extern long new_msgnum(void);
extern long messagerxtime(void);
extern void split_sline(char *eingabe, char *call1, char *call2, char *mbx,
			char *bid, char *lt, char *betreff);
extern boolean check_for_dirty(char *hs);
extern boolean check_for_dirty2(char *bs, char *hs);
extern void check_reject(char *frombox, char msgchar, char *ziel, char *mbx,
  char *absender, char *lifetime, char *betreff, char *bid, long laenge,
  boolean is_local, boolean is_privlocal, boolean *reject_it, boolean *no_sf,
  char *rejectreason);
extern void do_convtit(char *frombox, char msgchar, char *ziel, char *mbx,
  char *absender1, char *lifetime1, char *betreff1, char *bid, long laenge,
  boolean is_local, boolean is_privlocal, boolean *reject_it, boolean *no_sf);
extern void create_ack(char *absender, char *ackcall, char *dest,
		       char *umleitung, char *betreff);
extern void show_prompt(short unr);
extern void check_replytitle(char *reply);
extern void get_numbers(short unr, boolean plong, char *eingabe, long *start,
			long *ende, short *threshold, char *option, char *search);
extern short find_command(short unr, char *kommando, boolean *onlysys);
extern void expand_command(short unr, char *kommando);
extern short str2disturb_chan(char *w);
extern short str2disturb_chan2(char *w);
extern void fill_logline(boolean full, short unr, char *hs);
extern void box_logbuch(short unr);
extern void send_conv(short unr, char *s);
extern void box_convers(short unr, char *cmd);
extern boolean use_gzip(long size);
extern void sane_shutdown(short magic);
extern boolean was_sane_shutdown(void);
extern void set_lastgarbagetime(time_t garbagetime);
extern time_t get_lastgarbagetime(void);
extern time_t get_totalruntime_l(void);

#define w_btext(unr, nr) x_w_btext(unr, nr, false)
#define wln_btext(unr, nr) x_w_btext(unr, nr, true)

#endif /*BOX_SUB_H*/

