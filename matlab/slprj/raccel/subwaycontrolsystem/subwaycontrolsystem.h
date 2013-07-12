#include "__cf_subwaycontrolsystem.h"
#ifndef RTW_HEADER_subwaycontrolsystem_h_
#define RTW_HEADER_subwaycontrolsystem_h_
#ifndef subwaycontrolsystem_COMMON_INCLUDES_
#define subwaycontrolsystem_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "subwaycontrolsystem_types.h"
#define MODEL_NAME subwaycontrolsystem
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (29)   
#elif NCSTATES != 29
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { real_T mgreqddwbk ; real_T nojiyg1svu ; real_T h32onzoiii ;
real_T cytqvalje5 ; real_T mewmcyb4gt [ 4 ] ; real_T l3p1u43lj0 [ 4 ] ;
real_T bdv4orwwct [ 4 ] ; real_T gotfm0hfnu [ 8 ] ; real_T e2bcofptlp [ 8 ] ;
} BlockIO ; typedef struct { real_T csmhj2mobz ; real_T bzilocoerc [ 4 ] ;
real_T e5i3qovgis [ 4 ] ; real_T ov5pkqlglu [ 8 ] ; real_T jknd2rgprd [ 8 ] ;
real_T isgvs5svtv [ 4 ] ; real_T omfdvdtquy [ 4 ] ; real_T j04e3heoks [ 4 ] ;
real_T duzuwa454g [ 4 ] ; real_T kd0unb3ts3 [ 4 ] ; real_T ms2wqypsep [ 4 ] ;
real_T bdoe3sih52 [ 4 ] ; real_T guc4ezu4vd [ 4 ] ; real_T a2j0p0cym5 [ 8 ] ;
real_T nvaeng4gwq ; real_T n0eg025vjq ; real_T myinbg3jep ; real_T ckdvmn4dp4
; real_T oqkftxqo0p ; real_T ayboz2qrcw ; real_T bhchhnlfkm ; real_T
gtkvhlkzsc ; real_T fhaqcxx030 ; real_T hzbs4lmhew ; real_T prfb015v23 ;
real_T e11zy0frlw ; real_T lltfkpbor1 ; real_T fubcl3argx ; real_T jnkyxamnrc
; real_T jmy4ojj1wm ; real_T opegpgmqkc ; real_T driwqxy21l ; real_T
m2jewdvak1 ; real_T cs4bbjasbf ; struct { void * LoggedData ; } bllphsg2bd ;
struct { void * LoggedData ; } fcdtvsyw4o ; int32_T jxt0tifn1m ; int32_T
mgytiqynw0 ; int32_T op2f2jmd1g [ 4 ] ; int32_T l2jamqzsvo ; int32_T
icojgqosr1 [ 4 ] ; int32_T iu4glifpoq ; int32_T ofotg1tha3 ; int32_T
f2e0swgpo5 ; int32_T depxwofcb1 ; int32_T n2m0va4pve ; int32_T fqbexa5vby ;
int32_T a3ymfl4ch4 ; int32_T ijkudaz05s ; int32_T ogmhlc5iu0 ; int32_T
jcm3cem4ee ; int32_T gt42aq5wqz ; uint8_T cj4jryemsn ; uint8_T argt12xgun ;
uint8_T ek5x23uca5 ; uint8_T gorxzp2tc5 ; uint8_T milvjxyyuk ; uint8_T
gbpi15raxo ; uint8_T lpvn5skrbx ; uint8_T bl2j5t1c00 ; uint8_T jatsecz0ba ;
uint8_T d4xbuzbhso ; uint8_T hzteyzmsp1 ; uint8_T mtzmj2oq0u ; uint8_T
cnr2qzd2co ; uint8_T omrooalxeh ; uint8_T ips0kg0xqe ; uint8_T lwzxupxcsq ;
uint8_T h0hof5daif ; uint8_T iewjsudzza ; uint8_T jcsk5s3kfb ; uint8_T
dtvanlzaoj ; uint8_T ilmiwrbush ; uint8_T eke5mcashi ; uint8_T i43zhu5moy ;
uint8_T jnwppiorce ; uint8_T cc1hr1gknw ; uint8_T oxqnny3i5s ; uint8_T
il0adu1aro ; uint8_T e10uflryt4 ; uint8_T k1omhwzsff ; uint8_T jmxtcefkhj ;
uint8_T bheu3h35yv ; uint8_T dxol0tigqi ; uint8_T atydz2bu0a ; uint8_T
a0x4w1qbx1 ; uint8_T me5dxqkdhs ; uint8_T h4hy2vxqsc ; uint8_T pjhjohvvwy ;
uint8_T khvi5cgv0x ; uint8_T cshnk4nxt0 ; uint8_T hovg3awtfp ; uint8_T
odfyj0p414 ; uint8_T myspnolkmq ; uint8_T avzsnt2vfb ; uint8_T lfluclczgd ;
boolean_T fwktsfwhv4 ; boolean_T jviamtmzv0 ; boolean_T ag3dlvdnni ;
boolean_T p4v1pjyxuj ; } D_Work ; typedef struct { real_T ix1fmrtgm0 [ 29 ] ;
} ContinuousStates ; typedef struct { real_T ix1fmrtgm0 [ 29 ] ; }
StateDerivatives ; typedef struct { boolean_T ix1fmrtgm0 [ 29 ] ; }
StateDisabled ; typedef struct { real_T ix1fmrtgm0 [ 29 ] ; } CStateAbsTol ;
struct Parameters_ { real_T b3_Value ; real_T a3_Value ; real_T b2_Value ;
real_T a2_Value ; real_T b1_Value ; real_T a1_Value ; real_T b_Value ; real_T
a_Value ; real_T d7_Value ; real_T c7_Value ; real_T d6_Value ; real_T
c6_Value ; real_T d5_Value ; real_T c5_Value ; real_T d4_Value ; real_T
c4_Value ; real_T d3_Value ; real_T c3_Value ; real_T d2_Value ; real_T
c2_Value ; real_T d1_Value ; real_T c1_Value ; real_T d_Value ; real_T
c_Value ; uint8_T TDV_CurrentSetting ; uint8_T TDV1_CurrentSetting ; uint8_T
TDV2_CurrentSetting ; uint8_T TDV3_CurrentSetting ; uint8_T
PSDV_CurrentSetting ; uint8_T PSDV1_CurrentSetting ; uint8_T
PSDV2_CurrentSetting ; uint8_T PSDV3_CurrentSetting ; uint8_T
PSDV4_CurrentSetting ; uint8_T PSDV5_CurrentSetting ; uint8_T
PSDV6_CurrentSetting ; uint8_T PSDV7_CurrentSetting ; } ; extern Parameters
rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern BlockIO rtB ;
extern ContinuousStates rtX ; extern D_Work rtDWork ; extern SimStruct *
const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
#endif
