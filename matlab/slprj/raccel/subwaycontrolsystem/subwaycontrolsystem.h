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
real_T mhps55ndar ; real_T ppgpg2d5gp ; real_T avfoep3api ; real_T k3zetjkg2t
; real_T pd5fkmhg4c ; real_T igjejaivpx ; real_T ne5tcs23kl ; real_T
bkhrmaqhhj ; real_T fsek2utpw2 ; real_T nuqllrp43p ; real_T n5wof223jc ;
real_T lmgwt2ihoi ; real_T eyeyekatwb ; real_T esraav3jfu ; real_T edvs5rk3fa
; real_T c1gduapxde ; real_T bffxdmyjnr ; real_T drbwe4rydf ; real_T
fao3lacynd ; real_T acxds11k1q ; struct { void * LoggedData ; } fcdtvsyw4o ;
int32_T jxt0tifn1m ; int32_T mgytiqynw0 ; int32_T op2f2jmd1g [ 4 ] ; int32_T
l2jamqzsvo ; int32_T gophpoqjs0 ; int32_T bso50stzuv [ 4 ] ; int32_T
kiu22l5yga ; int32_T pvpbflzhwc ; int32_T eli0bu1nqi ; int32_T p5wmqc33qy ;
int32_T ov1u3dz22b ; int32_T hodq0clkgt ; int32_T o4qhycsmoh ; int32_T
mf54iquk4a ; int32_T gt42aq5wqz ; uint8_T cj4jryemsn ; uint8_T argt12xgun ;
uint8_T ek5x23uca5 ; uint8_T gorxzp2tc5 ; uint8_T milvjxyyuk ; uint8_T
gbpi15raxo ; uint8_T lpvn5skrbx ; uint8_T l5nch0wfe0 ; uint8_T mk3y1ej5sc ;
uint8_T e0siqbw4px ; uint8_T f4ecgcwjef ; uint8_T e2s0vhz32j ; uint8_T
dv1e4s4igc ; uint8_T af0eeezn4z ; uint8_T gwkbtmpoqm ; uint8_T h0gr1gfnip ;
uint8_T dq53dldqu5 ; uint8_T pwv1ttrztn ; uint8_T h1eicbufky ; uint8_T
lfw2ucpenn ; uint8_T a3d24qkbyc ; uint8_T psc01ml3a2 ; uint8_T idrkgh24mh ;
uint8_T ho4yv0pef5 ; uint8_T ee02mqd4oz ; uint8_T fgm4uvex5n ; uint8_T
hwylozrfgv ; uint8_T kxzqsowcq4 ; uint8_T j2iwqhng5v ; uint8_T puu0onps1o ;
uint8_T ityqbqwxs3 ; uint8_T m1coawef1z ; uint8_T c20f0hecbl ; uint8_T
piy1mfyq04 ; uint8_T aaa3dwwbpb ; uint8_T cor0ek34i1 ; uint8_T p1swflzbuh ;
uint8_T bieuzbl5sa ; uint8_T pqex5itzoo ; uint8_T m4axwklc2n ; uint8_T
kkmwpgcwey ; uint8_T d5gd34izwy ; uint8_T hjfnzxphh4 ; uint8_T lfluclczgd ;
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
