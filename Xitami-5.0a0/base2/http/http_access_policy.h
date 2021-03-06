/*---------------------------------------------------------------------------
    http_access_policy.h - http_access_policy component

    Applies access control policies to the HTTP request.
    Generated from http_access_policy.icl by smt_object_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_HTTP_ACCESS_POLICY_SAFE
#   define INCLUDE_HTTP_ACCESS_POLICY_SAFE
#   define INCLUDE_HTTP_ACCESS_POLICY_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_HTTP_ACCESS_POLICY_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _http_access_policy_t http_access_policy_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
#    define HTTP_ACCESS_POLICY_HISTORY_LENGTH 32
#endif

#define HTTP_ACCESS_POLICY_ALIVE        0xFABB
#define HTTP_ACCESS_POLICY_DEAD         0xDEAD

#define HTTP_ACCESS_POLICY_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL http_access_policy\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != HTTP_ACCESS_POLICY_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "http_access_policy at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, HTTP_ACCESS_POLICY_ALIVE, self->object_tag);\
        http_access_policy_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "http.h"
#   include "http_access_module.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_access_policy_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_ACCESS_POLICY_ACTIVE
#   if defined (ICL_IMPORT_HTTP_ACCESS_POLICY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_HTTP_ACCESS_POLICY_UNSAFE
#   define INCLUDE_HTTP_ACCESS_POLICY_UNSAFE
#   define INCLUDE_HTTP_ACCESS_POLICY_ACTIVE

#   include "http.h"
#   include "http_access_module.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_access_policy_agent.h"
//  Global variables

extern Bool
    http_access_policy_animating;

//  Structure of the http_access_policy object

struct _http_access_policy_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [HTTP_ACCESS_POLICY_HISTORY_LENGTH];
    int
        history_line  [HTTP_ACCESS_POLICY_HISTORY_LENGTH];
    char
        *history_type [HTTP_ACCESS_POLICY_HISTORY_LENGTH];
    int
        history_links [HTTP_ACCESS_POLICY_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *http_access_module_list;       //  List of portals
Bool
    http_access_module_stopped;     //  Is this portal stopped?
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    http_access_policy_announce (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal,          //  Portal back to client
smt_log_t * log                         //  Not documented
);

int
    http_access_policy_before (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

void
    http_access_policy_selftest (
void);

#define http_access_policy_new()        http_access_policy_new_ (__FILE__, __LINE__)
http_access_policy_t *
    http_access_policy_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_access_policy_terminate (
void);

http_access_module_t *
    http_access_policy__http_access_module_new (
void * self_v                           //  Untyped server reference
);

http_access_module_t *
    http_access_policy__http_access_module_factory (
void);

int
    http_access_policy__http_access_module_unbind (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal           //  Portal reference
);

int
    http_access_policy_open (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

int
    http_access_policy_after (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

int
    http_access_policy_close (
http_access_policy_t * self,            //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

#define http_access_policy_destroy(self)  http_access_policy_destroy_ (self, __FILE__, __LINE__)
int
    http_access_policy_destroy_ (
http_access_policy_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_access_policy_unlink(self)  http_access_policy_unlink_ (self, __FILE__, __LINE__)
void
    http_access_policy_unlink_ (
http_access_policy_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_access_policy_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define http_access_policy_free(self)   http_access_policy_free_ (self, __FILE__, __LINE__)
void
    http_access_policy_free_ (
http_access_policy_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_access_policy_show(item,opcode,trace_file)  http_access_policy_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    http_access_policy_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_access_policy_link(self)   http_access_policy_link_ (self, __FILE__, __LINE__)
http_access_policy_t *
    http_access_policy_link_ (
http_access_policy_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_access_policy_new_in_scope(self_p,_scope)  http_access_policy_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    http_access_policy_new_in_scope_ (
http_access_policy_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_ACCESS_POLICY_ACTIVE
#   if defined (ICL_IMPORT_HTTP_ACCESS_POLICY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_HTTP_ACCESS_POLICY_INLINE)
#   define INCLUDE_HTTP_ACCESS_POLICY_INLINE
#   define INCLUDE_HTTP_ACCESS_POLICY_ACTIVE

#   include "http.h"
#   include "http_access_module.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SELFTEST)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_FREE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ALLOC)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE) )
void
    http_access_policy_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_access_policy_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_ACCESS_POLICY_ACTIVE
#   if defined (ICL_IMPORT_HTTP_ACCESS_POLICY_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_HTTP_ACCESS_POLICY_ROOT
#   endif
# endif
#endif
