# 1 "hello.c"
# 1 "/usr/local/include/stdio.h" 1 3
 


















 







# 1 "/usr/local/include/features.h" 1 3
 




















 






























































 




















 





 



 







 
# 142 "/usr/local/include/features.h" 3


 









 








 



























# 208 "/usr/local/include/features.h" 3


































 



 


 








 




 
















 


# 1 "/usr/local/include/sys/cdefs.h" 1 3
 




















 




 






 





 








 



# 65 "/usr/local/include/sys/cdefs.h" 3


 





 




 









 







 

















 















 







 






 








 








 








 











 










 







 




 


















# 283 "/usr/local/include/features.h" 2 3



 








 





 

 








# 1 "/usr/local/include/gnu/stubs.h" 1 3
 





















# 312 "/usr/local/include/features.h" 2 3




# 28 "/usr/local/include/stdio.h" 2 3


 



# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 


































typedef unsigned int size_t;






















 




 

# 271 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


# 283 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 34 "/usr/local/include/stdio.h" 2 3


# 1 "/usr/local/include/bits/types.h" 1 3
 

















 









# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 


# 188 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3





 




 

# 271 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


# 283 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 29 "/usr/local/include/bits/types.h" 2 3


 
typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;

__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef long long int __quad_t;
# 48 "/usr/local/include/bits/types.h" 3

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;

typedef __quad_t *__qaddr_t;

typedef __u_quad_t __dev_t;		 
typedef __u_int __uid_t;		 
typedef __u_int __gid_t;		 
typedef __u_long __ino_t;		 
typedef __u_int __mode_t;		 
typedef __u_int __nlink_t; 		 
typedef long int __off_t;		 
typedef __quad_t __loff_t;		 
typedef int __pid_t;			 
typedef int __ssize_t;			 
typedef __u_long __rlim_t;		 
typedef __u_quad_t __rlim64_t;		 
typedef __u_int __id_t;			 

typedef struct
  {
    int __val[2];
  } __fsid_t;				 

 
typedef int __daddr_t;			 
typedef char *__caddr_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __swblk_t;		 

typedef long int __clock_t;

 
typedef int __clockid_t;

 
typedef int __timer_t;


 



typedef int __key_t;

 
typedef unsigned short int __ipc_pid_t;


 
typedef long int __blksize_t;

 

 
typedef long int __blkcnt_t;
typedef __quad_t __blkcnt64_t;

 
typedef __u_long __fsblkcnt_t;
typedef __u_quad_t __fsblkcnt64_t;

 
typedef __u_long __fsfilcnt_t;
typedef __u_quad_t __fsfilcnt64_t;

 
typedef __u_quad_t __ino64_t;

 
typedef __loff_t __off64_t;

 
typedef long int __t_scalar_t;
typedef unsigned long int __t_uscalar_t;

 
typedef int __intptr_t;

 
typedef unsigned int __socklen_t;


 

# 1 "/usr/local/include/bits/pthreadtypes.h" 1 3
 
 
 
 
 
 
 
 
 
 
 
 
 









# 1 "/usr/local/include/bits/sched.h" 1 3
 



















# 62 "/usr/local/include/bits/sched.h" 3





 
struct __sched_param
  {
    int __sched_priority;
  };


# 23 "/usr/local/include/bits/pthreadtypes.h" 2 3


 
struct _pthread_fastlock
{
  long int __status;    
  int __spinlock;       

};


 
typedef struct _pthread_descr_struct *_pthread_descr;




 
typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;


 
typedef struct
{
  struct _pthread_fastlock __c_lock;  
  _pthread_descr __c_waiting;         
} pthread_cond_t;


 
typedef struct
{
  int __dummy;
} pthread_condattr_t;

 
typedef unsigned int pthread_key_t;


 
 

typedef struct
{
  int __m_reserved;                
  int __m_count;                   
  _pthread_descr __m_owner;        
  int __m_kind;                    
  struct _pthread_fastlock __m_lock;  
} pthread_mutex_t;


 
typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;


 
typedef int pthread_once_t;


# 117 "/usr/local/include/bits/pthreadtypes.h" 3


# 136 "/usr/local/include/bits/pthreadtypes.h" 3



 
typedef unsigned long int pthread_t;


# 143 "/usr/local/include/bits/types.h" 2 3




# 36 "/usr/local/include/stdio.h" 2 3








 
typedef struct _IO_FILE FILE;








 
typedef struct _IO_FILE __FILE;









# 1 "/usr/local/include/libio.h" 1 3
 






























# 1 "/usr/local/include/_G_config.h" 1 3
 





 






# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 


# 188 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3





 




 





























 


























typedef long int wchar_t;
























typedef unsigned int  wint_t;




 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 14 "/usr/local/include/_G_config.h" 2 3










# 1 "/usr/local/include/wchar.h" 1 3
 

















 











# 46 "/usr/local/include/wchar.h" 3


# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 

# 190 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 




 

# 271 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3














 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 48 "/usr/local/include/wchar.h" 2 3


# 1 "/usr/local/include/bits/wchar.h" 1 3
 

























# 50 "/usr/local/include/wchar.h" 2 3


 













 
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;		 
} __mbstate_t;




 

# 682 "/usr/local/include/wchar.h" 3



# 24 "/usr/local/include/_G_config.h" 2 3


typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;








# 1 "/usr/local/include/gconv.h" 1 3
 

















 








# 1 "/usr/local/include/wchar.h" 1 3
 

















 











# 46 "/usr/local/include/wchar.h" 3


# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 

# 190 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 




 

# 271 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3














 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 48 "/usr/local/include/wchar.h" 2 3




 











# 76 "/usr/local/include/wchar.h" 3




 

# 682 "/usr/local/include/wchar.h" 3



# 28 "/usr/local/include/gconv.h" 2 3



# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 


# 188 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3





 




 


# 269 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




# 283 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3


 

 

# 317 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stddef.h" 3




 





















# 31 "/usr/local/include/gconv.h" 2 3


 


 
enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};


 
enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};


 
struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;


 
typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
			    __const unsigned char **, __const unsigned char *,
			    unsigned char **, size_t *, int, int);

 
typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);


 
typedef int (*__gconv_trans_fct) (struct __gconv_step *,
				  struct __gconv_step_data *, void *,
				  __const unsigned char *,
				  __const unsigned char **,
				  __const unsigned char *, unsigned char **,
				  size_t *);

 
typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
					  __const unsigned char *,
					  unsigned char *, unsigned char *);

 
typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
					size_t *);

 
typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{
   
  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};


 
struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;

   

  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;

   
  int __stateful;

  void *__data;		 
};

 

struct __gconv_step_data
{
  unsigned char *__outbuf;     
  unsigned char *__outbufend;  


   
  int __flags;

   

  int __invocation_counter;

   

  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;	 


   
  struct __gconv_trans_data *__trans;
};


 
typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [0] ;
} *__gconv_t;


# 44 "/usr/local/include/_G_config.h" 2 3

typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));




 


















 




 














# 32 "/usr/local/include/libio.h" 2 3

 

















 

# 1 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stdarg.h" 1 3
 
































































 






typedef void *__gnuc_va_list;



 

# 122 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stdarg.h" 3




















# 209 "/usr/lib/gcc-lib/i686-linux/2.95.3/include/stdarg.h" 3




# 53 "/usr/local/include/libio.h" 2 3







# 72 "/usr/local/include/libio.h" 3


 

















# 103 "/usr/local/include/libio.h" 3











 

























 



















struct _IO_jump_t;  struct _IO_FILE;

 







typedef void _IO_lock_t;



 

struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
   

   
  int _pos;
# 192 "/usr/local/include/libio.h" 3

};

 
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};

# 259 "/usr/local/include/libio.h" 3


struct _IO_FILE {
  int _flags;		 


   
   
  char* _IO_read_ptr;	 
  char* _IO_read_end;	 
  char* _IO_read_base;	 
  char* _IO_write_base;	 
  char* _IO_write_ptr;	 
  char* _IO_write_end;	 
  char* _IO_buf_base;	 
  char* _IO_buf_end;	 
   
  char *_IO_save_base;  
  char *_IO_backup_base;   
  char *_IO_save_end;  

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _blksize;
  __off_t   _old_offset;  


   
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

   

  _IO_lock_t *_lock;








  __off64_t   _offset;





  void *__pad1;
  void *__pad2;

  int _mode;
   
  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;











 

 

typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);

 





typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
				 size_t __n);

 





typedef int __io_seek_fn (void *__cookie, __off64_t   *__pos, int __w);

 
typedef int __io_close_fn (void *__cookie);


# 389 "/usr/local/include/libio.h" 3







extern int __underflow (_IO_FILE *)  ;
extern int __uflow (_IO_FILE *)  ;
extern int __overflow (_IO_FILE *, int)  ;
extern wint_t   __wunderflow (_IO_FILE *)  ;
extern wint_t   __wuflow (_IO_FILE *)  ;
extern wint_t   __woverflow (_IO_FILE *, wint_t  )  ;
























extern int _IO_getc (_IO_FILE *__fp)  ;
extern int _IO_putc (int __c, _IO_FILE *__fp)  ;
extern int _IO_feof (_IO_FILE *__fp)  ;
extern int _IO_ferror (_IO_FILE *__fp)  ;

extern int _IO_peekc_locked (_IO_FILE *__fp)  ;

 



extern void _IO_flockfile (_IO_FILE *)  ;
extern void _IO_funlockfile (_IO_FILE *)  ;
extern int _IO_ftrylockfile (_IO_FILE *)  ;
















extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
			__gnuc_va_list , int *__restrict)  ;
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
			 __gnuc_va_list )  ;
extern __ssize_t   _IO_padn (_IO_FILE *, int, __ssize_t  )  ;
extern size_t   _IO_sgetn (_IO_FILE *, void *, size_t  )  ;

extern __off64_t   _IO_seekoff (_IO_FILE *, __off64_t  , int, int)  ;
extern __off64_t   _IO_seekpos (_IO_FILE *, __off64_t  , int)  ;

extern void _IO_free_backup_area (_IO_FILE *)  ;

# 511 "/usr/local/include/libio.h" 3







# 65 "/usr/local/include/stdio.h" 2 3


# 76 "/usr/local/include/stdio.h" 3


 

typedef _G_fpos_t fpos_t;







 





 





 






 







 




 








# 1 "/usr/local/include/bits/stdio_lim.h" 1 3
 








































# 129 "/usr/local/include/stdio.h" 2 3



 
extern FILE *stdin;		 
extern FILE *stdout;		 
extern FILE *stderr;		 
 




 
extern int remove (__const char *__filename)  ;
 
extern int rename (__const char *__old, __const char *__new)  ;


 

extern FILE *tmpfile (void)  ;










 
extern char *tmpnam (char *__s)  ;


 

extern char *tmpnam_r (char *__s)  ;




 






extern char *tempnam (__const char *__dir, __const char *__pfx)
        ;



 
extern int fclose (FILE *__stream)  ;
 
extern int fflush (FILE *__stream)  ;


 
extern int fflush_unlocked (FILE *__stream)  ;









 
extern FILE *fopen (__const char *__restrict __filename,
		    __const char *__restrict __modes)  ;
 
extern FILE *freopen (__const char *__restrict __filename,
		      __const char *__restrict __modes,
		      FILE *__restrict __stream)  ;
# 220 "/usr/local/include/stdio.h" 3










 
extern FILE *fdopen (int __fd, __const char *__modes)  ;


# 249 "/usr/local/include/stdio.h" 3



 

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf)  ;
 


extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
		    int __modes, size_t __n)  ;


 

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
		       size_t __size)  ;

 
extern void setlinebuf (FILE *__stream)  ;



 
extern int fprintf (FILE *__restrict __stream,
		    __const char *__restrict __format, ...)  ;
 
extern int printf (__const char *__restrict __format, ...)  ;
 
extern int sprintf (char *__restrict __s,
		    __const char *__restrict __format, ...)  ;

 
extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
		     __gnuc_va_list  __arg)  ;
 
extern int vprintf (__const char *__restrict __format, __gnuc_va_list  __arg)
      ;
 
extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
		     __gnuc_va_list  __arg)  ;


 
extern int snprintf (char *__restrict __s, size_t __maxlen,
		     __const char *__restrict __format, ...)
       __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
		      __const char *__restrict __format, __gnuc_va_list  __arg)
       __attribute__ ((__format__ (__printf__, 3, 0)));


# 321 "/usr/local/include/stdio.h" 3



 
extern int fscanf (FILE *__restrict __stream,
		   __const char *__restrict __format, ...)  ;
 
extern int scanf (__const char *__restrict __format, ...)  ;
 
extern int sscanf (__const char *__restrict __s,
		   __const char *__restrict __format, ...)  ;

# 347 "/usr/local/include/stdio.h" 3



 
extern int fgetc (FILE *__stream)  ;
extern int getc (FILE *__stream)  ;

 
extern int getchar (void)  ;

 




 
extern int getc_unlocked (FILE *__stream)  ;
extern int getchar_unlocked (void)  ;



 
extern int fgetc_unlocked (FILE *__stream)  ;



 
extern int fputc (int __c, FILE *__stream)  ;
extern int putc (int __c, FILE *__stream)  ;

 
extern int putchar (int __c)  ;

 




 
extern int fputc_unlocked (int __c, FILE *__stream)  ;



 
extern int putc_unlocked (int __c, FILE *__stream)  ;
extern int putchar_unlocked (int __c)  ;




 
extern int getw (FILE *__stream)  ;

 
extern int putw (int __w, FILE *__stream)  ;



 
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
      ;







 

extern char *gets (char *__s)  ;


# 437 "/usr/local/include/stdio.h" 3



 
extern int fputs (__const char *__restrict __s, FILE *__restrict __stream)
      ;







 
extern int puts (__const char *__s)  ;


 
extern int ungetc (int __c, FILE *__stream)  ;


 
extern size_t fread (void *__restrict __ptr, size_t __size,
		     size_t __n, FILE *__restrict __stream)  ;
 
extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
		      size_t __n, FILE *__restrict __s)  ;


 
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
			      size_t __n, FILE *__restrict __stream)  ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
			       size_t __n, FILE *__restrict __stream)  ;



 
extern int fseek (FILE *__stream, long int __off, int __whence)  ;
 
extern long int ftell (FILE *__stream)  ;
 
extern void rewind (FILE *__stream)  ;

 












 
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
      ;
 
extern int fsetpos (FILE *__stream, __const fpos_t *__pos)  ;
# 520 "/usr/local/include/stdio.h" 3










 
extern void clearerr (FILE *__stream)  ;
 
extern int feof (FILE *__stream)  ;
 
extern int ferror (FILE *__stream)  ;


 
extern void clearerr_unlocked (FILE *__stream)  ;
extern int feof_unlocked (FILE *__stream)  ;
extern int ferror_unlocked (FILE *__stream)  ;



 
extern void perror (__const char *__s)  ;

 


extern int sys_nerr;
extern __const char *__const sys_errlist[];








 
extern int fileno (FILE *__stream)  ;



 
extern int fileno_unlocked (FILE *__stream)  ;





 
extern FILE *popen (__const char *__command, __const char *__modes)  ;

 
extern int pclose (FILE *__stream)  ;




 
extern char *ctermid (char *__s)  ;









# 602 "/usr/local/include/stdio.h" 3




 

 
extern void flockfile (FILE *__stream)  ;

 

extern int ftrylockfile (FILE *__stream)  ;

 
extern void funlockfile (FILE *__stream)  ;










 





 




# 1 "hello.c" 2


int
main(int argc, char *argv[])
{
    puts("Hello, Linux!");
    return 0;
}
