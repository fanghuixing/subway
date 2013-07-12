#include "__cf_subwaycontrolsystem.h"
#include <math.h>
#include "subwaycontrolsystem.h"
#include "subwaycontrolsystem_private.h"
#include "subwaycontrolsystem_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 2 ;
const char_T * gbl_raccel_Version = "8.0 (R2012b) 20-Jul-2012" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\subwaycontrolsystem\\subwaycontrolsystem_Jpattern.mat" ;
const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const
int_T gblInportDims [ ] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1
} ; const int_T gblInportInterpoFlag [ ] = { - 1 } ; const int_T
gblInportContinuous [ ] = { - 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
#define hsx0pdate3 (-1)
#define ab4gsgwqfm ((uint8_T)4U)
#define abokkwsuss ((uint8_T)8U)
#define atiyvzgfnq ((uint8_T)1U)
#define bg2pxs4yrg ((uint8_T)12U)
#define bozn0j4h3r ((uint8_T)2U)
#define bpsmzkxnnb ((uint8_T)3U)
#define cx0bb5ahz2 ((uint8_T)2U)
#define czs3vnbrbl ((uint8_T)7U)
#define ey4wkwipnf ((uint8_T)10U)
#define fkpeazmlxh ((uint8_T)1U)
#define g5thp4xumb ((uint8_T)6U)
#define gk0if0h1yc ((uint8_T)6U)
#define gyxihahkca ((uint8_T)7U)
#define h05jpwy3hy ((uint8_T)5U)
#define hjcg5jty2z ((uint8_T)8U)
#define hy3r3w5grg ((uint8_T)5U)
#define jkd1vnqob2 ((uint8_T)4U)
#define kpgupuy2kp ((uint8_T)11U)
#define m1cczpmiyp ((uint8_T)3U)
#define mce1hmjau3 ((uint8_T)1U)
#define mollve35d0 ((uint8_T)4U)
#define nsgxdn54fe ((uint8_T)2U)
#define nwxu2zxhpj ((uint8_T)3U)
#define nwxu2zxhpjf ((uint8_T)9U)
#define pe5ts3cbxi ((uint8_T)0U)
#define poj1ujn0qm ((uint8_T)2U)
#define puirb1divs ((uint8_T)1U)
#define pvvniy1wrq ((uint8_T)3U)
BlockIO rtB ; ContinuousStates rtX ; D_Work rtDWork ; static SimStruct
model_S ; SimStruct * const rtS = & model_S ; static real_T cssdru3pr0 (
real_T x ) ; static real_T kwtjth4lfb ( real_T x ) ; static int32_T
mrrmodciow ( int32_T a , real_T b ) ; static void k0nn3it3fd ( void ) ;
static real_T cssdru3pr0 ( real_T x ) { return muDoubleScalarAbs ( x ) ; }
static real_T kwtjth4lfb ( real_T x ) { return cssdru3pr0 ( x ) ; } static
int32_T mrrmodciow ( int32_T a , real_T b ) { int32_T y ; real_T tmp ; tmp =
muDoubleScalarRound ( ( real_T ) a * b ) ; if ( tmp < 2.147483648E+9 ) { if (
tmp >= - 2.147483648E+9 ) { y = ( int32_T ) tmp ; } else { y = MIN_int32_T ;
} } else if ( tmp >= 2.147483648E+9 ) { y = MAX_int32_T ; } else { y = 0 ; }
return y ; } static void k0nn3it3fd ( void ) { switch ( rtDWork . mtzmj2oq0u
) { case fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 0 ] = rtX
. ix1fmrtgm0 [ 6 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; break ; default : rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; break ; } switch ( rtDWork . jnwppiorce ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; default : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; } switch ( rtDWork . oxqnny3i5s ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; default : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; } switch ( rtDWork . h4hy2vxqsc ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; default : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; } switch ( rtDWork . e10uflryt4 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; default : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; } switch ( rtDWork . bl2j5t1c00 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; default : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; } switch ( rtDWork . d4xbuzbhso ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; default : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; } switch ( rtDWork . iewjsudzza ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; default : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; } switch ( rtDWork . lwzxupxcsq ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; default : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; } switch ( rtDWork . omrooalxeh ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; default : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; } switch ( rtDWork . jmxtcefkhj ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; default : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; } switch ( rtDWork . a0x4w1qbx1 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; default : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; } switch ( rtDWork . dxol0tigqi ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX . ix1fmrtgm0 [ 19 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX . ix1fmrtgm0 [
19 ] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . jcm3cem4ee ] =
rtX . ix1fmrtgm0 [ 19 ] ; break ; case gk0if0h1yc : break ; case gyxihahkca :
rtB . l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX . ix1fmrtgm0 [ 19 ] ; break ;
case abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB .
l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX . ix1fmrtgm0 [ 19 ] ; break ; case
kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX . ix1fmrtgm0 [
19 ] ; break ; default : rtB . l3p1u43lj0 [ rtDWork . jcm3cem4ee ] = rtX .
ix1fmrtgm0 [ 19 ] ; break ; } switch ( rtDWork . khvi5cgv0x ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX . ix1fmrtgm0 [ 4 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX . ix1fmrtgm0 [ 4
] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX
. ix1fmrtgm0 [ 4 ] ; break ; case gk0if0h1yc : break ; case gyxihahkca : rtB
. l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX . ix1fmrtgm0 [ 4 ] ; break ; case
abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB .
l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX . ix1fmrtgm0 [ 4 ] ; break ; case
kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX . ix1fmrtgm0 [ 4
] ; break ; default : rtB . l3p1u43lj0 [ rtDWork . depxwofcb1 ] = rtX .
ix1fmrtgm0 [ 4 ] ; break ; } switch ( rtDWork . hovg3awtfp ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX . ix1fmrtgm0 [
10 ] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . fqbexa5vby ] =
rtX . ix1fmrtgm0 [ 10 ] ; break ; case gk0if0h1yc : break ; case gyxihahkca :
rtB . l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX . ix1fmrtgm0 [ 10 ] ; break ;
case abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB .
l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; case
kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX . ix1fmrtgm0 [
10 ] ; break ; default : rtB . l3p1u43lj0 [ rtDWork . fqbexa5vby ] = rtX .
ix1fmrtgm0 [ 10 ] ; break ; } switch ( rtDWork . myspnolkmq ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX . ix1fmrtgm0 [ 15 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX . ix1fmrtgm0 [
15 ] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] =
rtX . ix1fmrtgm0 [ 15 ] ; break ; case gk0if0h1yc : break ; case gyxihahkca :
rtB . l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX . ix1fmrtgm0 [ 15 ] ; break ;
case abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB .
l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX . ix1fmrtgm0 [ 15 ] ; break ; case
kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX . ix1fmrtgm0 [
15 ] ; break ; default : rtB . l3p1u43lj0 [ rtDWork . ogmhlc5iu0 ] = rtX .
ix1fmrtgm0 [ 15 ] ; break ; } } void MdlInitialize ( void ) { int32_T i ;
rtDWork . gt42aq5wqz = hsx0pdate3 ; rtDWork . lfluclczgd = 0U ; rtDWork .
jxt0tifn1m = hsx0pdate3 ; rtDWork . lpvn5skrbx = 0U ; rtDWork . gbpi15raxo =
pe5ts3cbxi ; rtDWork . milvjxyyuk = 0U ; rtDWork . gorxzp2tc5 = pe5ts3cbxi ;
rtDWork . i43zhu5moy = 0U ; rtDWork . eke5mcashi = pe5ts3cbxi ; rtDWork .
ilmiwrbush = 0U ; rtDWork . dtvanlzaoj = pe5ts3cbxi ; rtDWork . cc1hr1gknw =
0U ; rtDWork . jnwppiorce = pe5ts3cbxi ; rtDWork . il0adu1aro = 0U ; rtDWork
. oxqnny3i5s = pe5ts3cbxi ; rtDWork . pjhjohvvwy = 0U ; rtDWork . h4hy2vxqsc
= pe5ts3cbxi ; rtDWork . k1omhwzsff = 0U ; rtDWork . e10uflryt4 = pe5ts3cbxi
; rtDWork . jatsecz0ba = 0U ; rtDWork . bl2j5t1c00 = pe5ts3cbxi ; rtDWork .
hzteyzmsp1 = 0U ; rtDWork . d4xbuzbhso = pe5ts3cbxi ; rtDWork . jcsk5s3kfb =
0U ; rtDWork . iewjsudzza = pe5ts3cbxi ; rtDWork . h0hof5daif = 0U ; rtDWork
. lwzxupxcsq = pe5ts3cbxi ; rtDWork . cshnk4nxt0 = 0U ; rtDWork . khvi5cgv0x
= pe5ts3cbxi ; rtDWork . cnr2qzd2co = 0U ; rtDWork . mtzmj2oq0u = pe5ts3cbxi
; rtDWork . odfyj0p414 = 0U ; rtDWork . hovg3awtfp = pe5ts3cbxi ; rtDWork .
ips0kg0xqe = 0U ; rtDWork . omrooalxeh = pe5ts3cbxi ; rtDWork . avzsnt2vfb =
0U ; rtDWork . myspnolkmq = pe5ts3cbxi ; rtDWork . bheu3h35yv = 0U ; rtDWork
. jmxtcefkhj = pe5ts3cbxi ; rtDWork . atydz2bu0a = 0U ; rtDWork . dxol0tigqi
= pe5ts3cbxi ; rtDWork . me5dxqkdhs = 0U ; rtDWork . a0x4w1qbx1 = pe5ts3cbxi
; rtDWork . ek5x23uca5 = 0U ; rtDWork . argt12xgun = pe5ts3cbxi ; rtDWork .
cj4jryemsn = 0U ; rtDWork . bzilocoerc [ 0 ] = 0.0 ; rtDWork . bzilocoerc [ 1
] = 0.0 ; rtDWork . bzilocoerc [ 2 ] = 0.0 ; rtDWork . bzilocoerc [ 3 ] = 0.0
; rtDWork . e5i3qovgis [ 0 ] = 0.0 ; rtDWork . e5i3qovgis [ 1 ] = 0.0 ;
rtDWork . e5i3qovgis [ 2 ] = 0.0 ; rtDWork . e5i3qovgis [ 3 ] = 0.0 ; rtDWork
. isgvs5svtv [ 0 ] = 0.0 ; rtDWork . isgvs5svtv [ 1 ] = 50.0 ; rtDWork .
isgvs5svtv [ 2 ] = 100.0 ; rtDWork . isgvs5svtv [ 3 ] = 150.0 ; rtDWork .
omfdvdtquy [ 0 ] = 0.0 ; rtDWork . omfdvdtquy [ 1 ] = 0.0 ; rtDWork .
omfdvdtquy [ 2 ] = 0.0 ; rtDWork . omfdvdtquy [ 3 ] = 0.0 ; rtDWork .
j04e3heoks [ 0 ] = 0.0 ; rtDWork . j04e3heoks [ 1 ] = 0.0 ; rtDWork .
j04e3heoks [ 2 ] = 0.0 ; rtDWork . j04e3heoks [ 3 ] = 0.0 ; rtDWork .
duzuwa454g [ 0 ] = 0.0 ; rtDWork . duzuwa454g [ 1 ] = 2284.0 ; rtDWork .
duzuwa454g [ 2 ] = 3292.0 ; rtDWork . duzuwa454g [ 3 ] = 9097.0 ; rtDWork .
kd0unb3ts3 [ 0 ] = 0.0 ; rtDWork . kd0unb3ts3 [ 1 ] = 0.0 ; rtDWork .
kd0unb3ts3 [ 2 ] = 0.0 ; rtDWork . kd0unb3ts3 [ 3 ] = 0.0 ; rtDWork .
ms2wqypsep [ 0 ] = 0.0 ; rtDWork . ms2wqypsep [ 1 ] = 0.0 ; rtDWork .
ms2wqypsep [ 2 ] = 0.0 ; rtDWork . ms2wqypsep [ 3 ] = 0.0 ; rtDWork .
mgytiqynw0 = 4 ; rtDWork . bdoe3sih52 [ 0 ] = 0.0 ; rtDWork . bdoe3sih52 [ 1
] = 0.0 ; rtDWork . bdoe3sih52 [ 2 ] = 0.0 ; rtDWork . bdoe3sih52 [ 3 ] = 0.0
; rtDWork . op2f2jmd1g [ 0 ] = 0 ; rtDWork . op2f2jmd1g [ 1 ] = 0 ; rtDWork .
op2f2jmd1g [ 2 ] = 0 ; rtDWork . op2f2jmd1g [ 3 ] = 0 ; rtDWork . guc4ezu4vd
[ 0 ] = 0.0 ; rtDWork . guc4ezu4vd [ 1 ] = 0.0 ; rtDWork . guc4ezu4vd [ 2 ] =
0.0 ; rtDWork . guc4ezu4vd [ 3 ] = 0.0 ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ;
rtDWork . l2jamqzsvo = 0 ; rtDWork . icojgqosr1 [ 0 ] = - 1 ; rtDWork .
icojgqosr1 [ 1 ] = - 1 ; rtDWork . icojgqosr1 [ 2 ] = - 1 ; rtDWork .
icojgqosr1 [ 3 ] = - 1 ; rtDWork . iu4glifpoq = 0 ; rtDWork . ofotg1tha3 = 0
; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; rtDWork . nvaeng4gwq = 0.0 ; rtDWork .
n0eg025vjq = 0.0 ; rtDWork . f2e0swgpo5 = 1 ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ;
rtDWork . myinbg3jep = 0.0 ; rtDWork . ckdvmn4dp4 = 0.0 ; rtX . ix1fmrtgm0 [
3 ] = 0.0 ; rtDWork . depxwofcb1 = 0 ; rtX . ix1fmrtgm0 [ 4 ] = 0.0 ; rtDWork
. oqkftxqo0p = 0.0 ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; rtDWork . ayboz2qrcw =
0.0 ; rtDWork . bhchhnlfkm = 0.0 ; rtDWork . n2m0va4pve = 0 ; rtX .
ix1fmrtgm0 [ 6 ] = 0.0 ; rtX . ix1fmrtgm0 [ 7 ] = 0.0 ; rtX . ix1fmrtgm0 [ 8
] = 0.0 ; rtDWork . gtkvhlkzsc = 0.0 ; rtDWork . fhaqcxx030 = 0.0 ; rtX .
ix1fmrtgm0 [ 9 ] = 0.0 ; rtDWork . fqbexa5vby = 0 ; rtX . ix1fmrtgm0 [ 10 ] =
0.0 ; rtDWork . hzbs4lmhew = 0.0 ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; rtDWork .
prfb015v23 = 0.0 ; rtDWork . e11zy0frlw = 0.0 ; rtDWork . a3ymfl4ch4 = 3 ;
rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork . lltfkpbor1 = 0.0 ; rtDWork .
fubcl3argx = 0.0 ; rtDWork . ijkudaz05s = 2 ; rtX . ix1fmrtgm0 [ 13 ] = 0.0 ;
rtDWork . jnkyxamnrc = 0.0 ; rtDWork . jmy4ojj1wm = 0.0 ; rtX . ix1fmrtgm0 [
14 ] = 0.0 ; rtDWork . ogmhlc5iu0 = 0 ; rtX . ix1fmrtgm0 [ 15 ] = 0.0 ;
rtDWork . opegpgmqkc = 0.0 ; rtX . ix1fmrtgm0 [ 16 ] = 0.0 ; rtX . ix1fmrtgm0
[ 17 ] = 0.0 ; rtDWork . driwqxy21l = 0.0 ; rtDWork . m2jewdvak1 = 0.0 ; rtX
. ix1fmrtgm0 [ 18 ] = 0.0 ; rtDWork . jcm3cem4ee = 0 ; rtX . ix1fmrtgm0 [ 19
] = 0.0 ; rtDWork . cs4bbjasbf = 0.0 ; rtX . ix1fmrtgm0 [ 20 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 21 ] = 0.0 ; rtX . ix1fmrtgm0 [ 22 ] = 0.0 ; rtX . ix1fmrtgm0 [
23 ] = 0.0 ; rtX . ix1fmrtgm0 [ 24 ] = 0.0 ; rtX . ix1fmrtgm0 [ 25 ] = 0.0 ;
rtX . ix1fmrtgm0 [ 26 ] = 0.0 ; rtX . ix1fmrtgm0 [ 27 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 28 ] = 0.0 ; rtB . l3p1u43lj0 [ 0 ] = 0.0 ; rtB . l3p1u43lj0 [ 1
] = 0.0 ; rtB . l3p1u43lj0 [ 2 ] = 0.0 ; rtB . l3p1u43lj0 [ 3 ] = 0.0 ; rtB .
bdv4orwwct [ 0 ] = 0.0 ; rtB . bdv4orwwct [ 1 ] = 0.0 ; rtB . bdv4orwwct [ 2
] = 0.0 ; rtB . bdv4orwwct [ 3 ] = 0.0 ; for ( i = 0 ; i < 8 ; i ++ ) {
rtDWork . ov5pkqlglu [ i ] = 0.0 ; rtDWork . jknd2rgprd [ i ] = 0.0 ; rtDWork
. a2j0p0cym5 [ i ] = 0.0 ; rtB . gotfm0hfnu [ i ] = 0.0 ; } } void MdlStart (
void ) { { static int_T rt_ToWksWidths [ ] = { 4 } ; static int_T
rt_ToWksNumDimensions [ ] = { 2 } ; static int_T rt_ToWksDimensions [ ] = { 4
, 1 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) , ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static const
char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) , ( NULL ) , ( NULL ) , { (
NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static const char_T
rt_ToWksBlockName [ ] = "subwaycontrolsystem/To Workspace1" ; rtDWork .
fcdtvsyw4o . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "traindoors" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDWork . fcdtvsyw4o . LoggedData == ( NULL ) )
return ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T j ;
int32_T k ; int32_T i ; int32_T c_index ; real_T fhzmmvyb0z [ 8 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtP . TDV_CurrentSetting == 1 ) { rtB
. mgreqddwbk = rtP . a_Value ; } else { rtB . mgreqddwbk = rtP . b_Value ; }
if ( rtP . TDV1_CurrentSetting == 1 ) { rtB . nojiyg1svu = rtP . a1_Value ; }
else { rtB . nojiyg1svu = rtP . b1_Value ; } if ( rtP . TDV2_CurrentSetting
== 1 ) { rtB . h32onzoiii = rtP . a2_Value ; } else { rtB . h32onzoiii = rtP
. b2_Value ; } if ( rtP . TDV3_CurrentSetting == 1 ) { rtB . cytqvalje5 = rtP
. a3_Value ; } else { rtB . cytqvalje5 = rtP . b3_Value ; } if ( rtP .
PSDV_CurrentSetting == 1 ) { fhzmmvyb0z [ 0 ] = rtP . c_Value ; } else {
fhzmmvyb0z [ 0 ] = rtP . d_Value ; } if ( rtP . PSDV1_CurrentSetting == 1 ) {
fhzmmvyb0z [ 1 ] = rtP . c1_Value ; } else { fhzmmvyb0z [ 1 ] = rtP .
d1_Value ; } if ( rtP . PSDV2_CurrentSetting == 1 ) { fhzmmvyb0z [ 2 ] = rtP
. c2_Value ; } else { fhzmmvyb0z [ 2 ] = rtP . d2_Value ; } if ( rtP .
PSDV3_CurrentSetting == 1 ) { fhzmmvyb0z [ 3 ] = rtP . c3_Value ; } else {
fhzmmvyb0z [ 3 ] = rtP . d3_Value ; } if ( rtP . PSDV4_CurrentSetting == 1 )
{ fhzmmvyb0z [ 4 ] = rtP . c4_Value ; } else { fhzmmvyb0z [ 4 ] = rtP .
d4_Value ; } if ( rtP . PSDV5_CurrentSetting == 1 ) { fhzmmvyb0z [ 5 ] = rtP
. c5_Value ; } else { fhzmmvyb0z [ 5 ] = rtP . d5_Value ; } if ( rtP .
PSDV6_CurrentSetting == 1 ) { fhzmmvyb0z [ 6 ] = rtP . c6_Value ; } else {
fhzmmvyb0z [ 6 ] = rtP . d6_Value ; } if ( rtP . PSDV7_CurrentSetting == 1 )
{ fhzmmvyb0z [ 7 ] = rtP . c7_Value ; } else { fhzmmvyb0z [ 7 ] = rtP .
d7_Value ; } rtDWork . gt42aq5wqz = hsx0pdate3 ; memset ( & rtB . e2bcofptlp
[ 0 ] , 0 , sizeof ( real_T ) << 3U ) ; j = 1.0 ; k = 1 ; for ( i = 0 ; i < 8
; i ++ ) { rtB . e2bcofptlp [ ( ( int32_T ) j + ( ( k - 1 ) << 2 ) ) - 1 ] =
fhzmmvyb0z [ i ] ; if ( k == 2 ) { k = 1 ; j ++ ; } else { k = 2 ; } } } rtB
. mewmcyb4gt [ 0 ] = rtB . mgreqddwbk ; rtB . mewmcyb4gt [ 1 ] = rtB .
nojiyg1svu ; rtB . mewmcyb4gt [ 2 ] = rtB . h32onzoiii ; rtB . mewmcyb4gt [ 3
] = rtB . cytqvalje5 ; if ( ssIsMajorTimeStep ( rtS ) != 0 ) { rtDWork .
csmhj2mobz = ssGetTaskTime ( rtS , 0 ) ; rtDWork . jviamtmzv0 = FALSE ;
rtDWork . jxt0tifn1m = hsx0pdate3 ; if ( rtDWork . cj4jryemsn == 0U ) {
rtDWork . cj4jryemsn = 1U ; rtDWork . cnr2qzd2co = 1U ; rtDWork . mtzmj2oq0u
= fkpeazmlxh ; rtX . ix1fmrtgm0 [ 6 ] = 0.0 ; rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; rtDWork . j04e3heoks [ 0 ] = 0.0 ; rtDWork . cc1hr1gknw =
1U ; rtDWork . a2j0p0cym5 [ 0 ] = 1.0 ; rtDWork . jnwppiorce = fkpeazmlxh ;
rtX . ix1fmrtgm0 [ 24 ] = 0.0 ; rtDWork . jknd2rgprd [ 0 ] = 0.0 ; rtDWork .
lpvn5skrbx = 1U ; rtDWork . ayboz2qrcw = 0.0 ; rtDWork . bhchhnlfkm = 0.0 ;
rtDWork . n2m0va4pve = 0 ; rtDWork . gbpi15raxo = h05jpwy3hy ; rtX .
ix1fmrtgm0 [ 5 ] = 0.0 ; rtDWork . il0adu1aro = 1U ; rtDWork . a2j0p0cym5 [ 4
] = 1.0 ; rtDWork . oxqnny3i5s = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 23 ] = 0.0 ;
rtDWork . jknd2rgprd [ 4 ] = 0.0 ; rtDWork . pjhjohvvwy = 1U ; rtDWork .
a2j0p0cym5 [ 1 ] = 1.0 ; rtDWork . h4hy2vxqsc = fkpeazmlxh ; rtX . ix1fmrtgm0
[ 21 ] = 0.0 ; rtDWork . jknd2rgprd [ 1 ] = 0.0 ; rtDWork . k1omhwzsff = 1U ;
rtDWork . a2j0p0cym5 [ 5 ] = 1.0 ; rtDWork . e10uflryt4 = fkpeazmlxh ; rtX .
ix1fmrtgm0 [ 22 ] = 0.0 ; rtDWork . jknd2rgprd [ 5 ] = 0.0 ; rtDWork .
jatsecz0ba = 1U ; rtDWork . a2j0p0cym5 [ 2 ] = 1.0 ; rtDWork . bl2j5t1c00 =
fkpeazmlxh ; rtX . ix1fmrtgm0 [ 28 ] = 0.0 ; rtDWork . jknd2rgprd [ 2 ] = 0.0
; rtDWork . hzteyzmsp1 = 1U ; rtDWork . a2j0p0cym5 [ 6 ] = 1.0 ; rtDWork .
d4xbuzbhso = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 27 ] = 0.0 ; rtDWork .
jknd2rgprd [ 6 ] = 0.0 ; rtDWork . jcsk5s3kfb = 1U ; rtDWork . a2j0p0cym5 [ 3
] = 1.0 ; rtDWork . iewjsudzza = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 25 ] = 0.0 ;
for ( i = 0 ; i < 8 ; i ++ ) { rtB . gotfm0hfnu [ i ] = rtX . ix1fmrtgm0 [ 25
] ; } rtDWork . jknd2rgprd [ 3 ] = 0.0 ; rtDWork . h0hof5daif = 1U ; rtDWork
. a2j0p0cym5 [ 7 ] = 1.0 ; rtDWork . lwzxupxcsq = fkpeazmlxh ; rtX .
ix1fmrtgm0 [ 26 ] = 0.0 ; rtB . gotfm0hfnu [ 7 ] = rtX . ix1fmrtgm0 [ 26 ] ;
rtDWork . jknd2rgprd [ 7 ] = 0.0 ; rtDWork . ips0kg0xqe = 1U ; rtDWork .
omrooalxeh = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 7 ] = 0.0 ; rtB . bdv4orwwct [ 1
] = rtX . ix1fmrtgm0 [ 7 ] ; rtDWork . j04e3heoks [ 1 ] = 0.0 ; rtDWork .
bheu3h35yv = 1U ; rtDWork . jmxtcefkhj = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 16 ]
= 0.0 ; rtB . bdv4orwwct [ 2 ] = rtX . ix1fmrtgm0 [ 16 ] ; rtDWork .
j04e3heoks [ 2 ] = 0.0 ; rtDWork . me5dxqkdhs = 1U ; rtDWork . a0x4w1qbx1 =
fkpeazmlxh ; rtX . ix1fmrtgm0 [ 20 ] = 0.0 ; rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; rtDWork . j04e3heoks [ 3 ] = 0.0 ; rtDWork . ek5x23uca5 =
1U ; rtDWork . l2jamqzsvo = 0 ; rtDWork . icojgqosr1 [ 0 ] = - 1 ; rtDWork .
icojgqosr1 [ 1 ] = - 1 ; rtDWork . icojgqosr1 [ 2 ] = - 1 ; rtDWork .
icojgqosr1 [ 3 ] = - 1 ; rtDWork . iu4glifpoq = 0 ; rtDWork . ofotg1tha3 = 0
; rtDWork . argt12xgun = cx0bb5ahz2 ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; rtDWork
. atydz2bu0a = 1U ; rtDWork . driwqxy21l = 0.0 ; rtDWork . m2jewdvak1 = 0.0 ;
rtDWork . cs4bbjasbf = 0.0 ; rtDWork . jcm3cem4ee = 3 ; rtDWork . bzilocoerc
[ rtDWork . jcm3cem4ee ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork . jcm3cem4ee
] = 0.0 ; rtX . ix1fmrtgm0 [ 18 ] = 0.0 ; rtX . ix1fmrtgm0 [ 19 ] = 0.0 ; rtX
. ix1fmrtgm0 [ 17 ] = 0.0 ; rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] = 1
; rtDWork . dxol0tigqi = poj1ujn0qm ; rtDWork . milvjxyyuk = 1U ; rtDWork .
nvaeng4gwq = 0.0 ; rtDWork . n0eg025vjq = 0.0 ; rtDWork . f2e0swgpo5 = 1 ;
rtDWork . gorxzp2tc5 = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; rtDWork .
i43zhu5moy = 1U ; rtDWork . lltfkpbor1 = 0.0 ; rtDWork . fubcl3argx = 0.0 ;
rtDWork . ijkudaz05s = 2 ; rtDWork . eke5mcashi = h05jpwy3hy ; rtX .
ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork . ilmiwrbush = 1U ; rtDWork . prfb015v23 =
0.0 ; rtDWork . e11zy0frlw = 0.0 ; rtDWork . a3ymfl4ch4 = 3 ; rtDWork .
dtvanlzaoj = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; rtDWork .
cshnk4nxt0 = 1U ; rtDWork . myinbg3jep = 0.0 ; rtDWork . ckdvmn4dp4 = 0.0 ;
rtDWork . oqkftxqo0p = 0.0 ; rtDWork . depxwofcb1 = 0 ; rtDWork . bzilocoerc
[ rtDWork . depxwofcb1 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork . depxwofcb1
] = 0.0 ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; rtX . ix1fmrtgm0 [ 4 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 2 ] = 0.0 ; rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] = 1 ;
rtDWork . khvi5cgv0x = poj1ujn0qm ; rtDWork . odfyj0p414 = 1U ; rtDWork .
gtkvhlkzsc = 0.0 ; rtDWork . fhaqcxx030 = 0.0 ; rtDWork . hzbs4lmhew = 0.0 ;
rtDWork . fqbexa5vby = 1 ; rtDWork . bzilocoerc [ rtDWork . fqbexa5vby ] =
0.0 ; rtDWork . e5i3qovgis [ rtDWork . fqbexa5vby ] = 0.0 ; rtX . ix1fmrtgm0
[ 9 ] = 0.0 ; rtX . ix1fmrtgm0 [ 10 ] = 0.0 ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ;
rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] = 1 ; rtDWork . hovg3awtfp =
poj1ujn0qm ; rtDWork . avzsnt2vfb = 1U ; rtDWork . jnkyxamnrc = 0.0 ; rtDWork
. jmy4ojj1wm = 0.0 ; rtDWork . opegpgmqkc = 0.0 ; rtDWork . ogmhlc5iu0 = 2 ;
rtDWork . bzilocoerc [ rtDWork . ogmhlc5iu0 ] = 0.0 ; rtDWork . e5i3qovgis [
rtDWork . ogmhlc5iu0 ] = 0.0 ; rtX . ix1fmrtgm0 [ 14 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 15 ] = 0.0 ; rtX . ix1fmrtgm0 [ 13 ] = 0.0 ; rtDWork .
op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] = 1 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . myspnolkmq = poj1ujn0qm ; } else { switch ( rtDWork . mtzmj2oq0u )
{ case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 0 ] == 1.0 ) { rtDWork .
omfdvdtquy [ 0 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . mtzmj2oq0u =
pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork . j04e3heoks [ 0 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . mtzmj2oq0u = ab4gsgwqfm ; }
break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 6 ] >= 2.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . mtzmj2oq0u = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 6
] = 2.0 ; rtB . bdv4orwwct [ 0 ] = rtX . ix1fmrtgm0 [ 6 ] ; } break ; default
: if ( ( rtX . ix1fmrtgm0 [ 6 ] > 0.0 ) && ( rtB . mewmcyb4gt [ 0 ] == 0.0 )
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . mtzmj2oq0u = pvvniy1wrq ; } else
{ if ( rtX . ix1fmrtgm0 [ 6 ] <= 0.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . mtzmj2oq0u = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 6 ] = 0.0 ; rtB .
bdv4orwwct [ 0 ] = rtX . ix1fmrtgm0 [ 6 ] ; rtDWork . j04e3heoks [ 0 ] = 0.0
; } } break ; } switch ( rtDWork . jnwppiorce ) { case fkpeazmlxh : if (
rtDWork . ov5pkqlglu [ 0 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 0 ] = 0.0 ;
rtDWork . ov5pkqlglu [ 0 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
jnwppiorce = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
jknd2rgprd [ 0 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
jnwppiorce = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
24 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . jnwppiorce =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 24 ] = 2.0 ; rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [ 24 ] <= 0.0 )
{ rtDWork . a2j0p0cym5 [ 0 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
jnwppiorce = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 24 ] = 0.0 ; rtB . gotfm0hfnu [
0 ] = rtX . ix1fmrtgm0 [ 24 ] ; rtDWork . jknd2rgprd [ 0 ] = 0.0 ; } else {
if ( ( rtX . ix1fmrtgm0 [ 24 ] > 0.0 ) && ( rtB . e2bcofptlp [ 0 ] == 0.0 ) )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . jnwppiorce = pvvniy1wrq ; } } break
; } switch ( rtDWork . gbpi15raxo ) { case mce1hmjau3 : if ( rtX . ix1fmrtgm0
[ 5 ] >= 5.0 ) { rtDWork . j04e3heoks [ rtDWork . n2m0va4pve ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 5 ] = 0.0 ; } break ; case bozn0j4h3r : if ( ( rtDWork .
mtzmj2oq0u == fkpeazmlxh ) == 0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; } else { if ( rtX .
ix1fmrtgm0 [ 5 ] >= 5.0 ) { rtDWork . jknd2rgprd [ ( int32_T ) rtDWork .
ayboz2qrcw + ( ( int32_T ) rtDWork . bhchhnlfkm << 2 ) ] = 1.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 5
] = 0.0 ; } } break ; case bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 5 ] >= 1.0 )
{ rtDWork . omfdvdtquy [ rtDWork . n2m0va4pve ] = 1.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . gbpi15raxo = g5thp4xumb ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; }
break ; case jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 5 ] >= 5.0 ) { rtDWork .
ov5pkqlglu [ ( int32_T ) rtDWork . ayboz2qrcw + ( ( int32_T ) rtDWork .
bhchhnlfkm << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = bpsmzkxnnb ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; } break ; case
h05jpwy3hy : if ( rtDWork . e5i3qovgis [ rtDWork . n2m0va4pve ] == 1.0 ) {
rtDWork . n2m0va4pve = 0 ; rtDWork . ayboz2qrcw = rtDWork . myinbg3jep ; i =
rtDWork . op2f2jmd1g [ rtDWork . n2m0va4pve ] + 1 ; rtDWork . bhchhnlfkm = (
real_T ) ( ( ( i < 0 ) + i ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; rtDWork . e5i3qovgis
[ rtDWork . n2m0va4pve ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 5 ] >=
1.0 ) && ( rtDWork . e5i3qovgis [ rtDWork . n2m0va4pve ] != 1.0 ) ) { rtDWork
. guc4ezu4vd [ rtDWork . n2m0va4pve ] = rtX . ix1fmrtgm0 [ 4 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 5
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 5 ] >= 10.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = czs3vnbrbl ; } break ;
case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 5 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 5 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 5 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
n2m0va4pve ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . bhchhnlfkm << 2 ) + ( int32_T ) rtDWork
. ayboz2qrcw ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; } } break ; } switch ( rtDWork
. oxqnny3i5s ) { case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 4 ] == 1.0 ) {
rtDWork . a2j0p0cym5 [ 4 ] = 0.0 ; rtDWork . ov5pkqlglu [ 4 ] = 0.0 ; rtDWork
. jviamtmzv0 = TRUE ; rtDWork . oxqnny3i5s = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 4 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . oxqnny3i5s = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 23 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
oxqnny3i5s = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 23 ] = 2.0 ; rtB . gotfm0hfnu [
4 ] = rtX . ix1fmrtgm0 [ 23 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
23 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 4 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . oxqnny3i5s = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 23 ] = 0.0 ;
rtB . gotfm0hfnu [ 4 ] = rtX . ix1fmrtgm0 [ 23 ] ; rtDWork . jknd2rgprd [ 4 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 23 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 4 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . oxqnny3i5s =
pvvniy1wrq ; } } break ; } switch ( rtDWork . h4hy2vxqsc ) { case fkpeazmlxh
: if ( rtDWork . ov5pkqlglu [ 1 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 1 ] = 0.0
; rtDWork . ov5pkqlglu [ 1 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h4hy2vxqsc = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
jknd2rgprd [ 1 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h4hy2vxqsc = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
21 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . h4hy2vxqsc =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 21 ] = 2.0 ; rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [ 21 ] <= 0.0 )
{ rtDWork . a2j0p0cym5 [ 1 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h4hy2vxqsc = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 21 ] = 0.0 ; rtB . gotfm0hfnu [
1 ] = rtX . ix1fmrtgm0 [ 21 ] ; rtDWork . jknd2rgprd [ 1 ] = 0.0 ; } else {
if ( ( rtX . ix1fmrtgm0 [ 21 ] > 0.0 ) && ( rtB . e2bcofptlp [ 1 ] == 0.0 ) )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . h4hy2vxqsc = pvvniy1wrq ; } } break
; } switch ( rtDWork . e10uflryt4 ) { case fkpeazmlxh : if ( rtDWork .
ov5pkqlglu [ 5 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 5 ] = 0.0 ; rtDWork .
ov5pkqlglu [ 5 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . e10uflryt4 =
pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 5 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . e10uflryt4 = ab4gsgwqfm ; }
break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 22 ] >= 2.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . e10uflryt4 = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 22
] = 2.0 ; rtB . gotfm0hfnu [ 5 ] = rtX . ix1fmrtgm0 [ 22 ] ; } break ;
default : if ( rtX . ix1fmrtgm0 [ 22 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 5 ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . e10uflryt4 = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 22 ] = 0.0 ; rtB . gotfm0hfnu [ 5 ] = rtX . ix1fmrtgm0 [ 22 ]
; rtDWork . jknd2rgprd [ 5 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 22 ]
> 0.0 ) && ( rtB . e2bcofptlp [ 5 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . e10uflryt4 = pvvniy1wrq ; } } break ; } switch ( rtDWork .
bl2j5t1c00 ) { case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 2 ] == 1.0 ) {
rtDWork . a2j0p0cym5 [ 2 ] = 0.0 ; rtDWork . ov5pkqlglu [ 2 ] = 0.0 ; rtDWork
. jviamtmzv0 = TRUE ; rtDWork . bl2j5t1c00 = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 2 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . bl2j5t1c00 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 28 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
bl2j5t1c00 = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 28 ] = 2.0 ; rtB . gotfm0hfnu [
2 ] = rtX . ix1fmrtgm0 [ 28 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
28 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 2 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . bl2j5t1c00 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 28 ] = 0.0 ;
rtB . gotfm0hfnu [ 2 ] = rtX . ix1fmrtgm0 [ 28 ] ; rtDWork . jknd2rgprd [ 2 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 28 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 2 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . bl2j5t1c00 =
pvvniy1wrq ; } } break ; } switch ( rtDWork . d4xbuzbhso ) { case fkpeazmlxh
: if ( rtDWork . ov5pkqlglu [ 6 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 6 ] = 0.0
; rtDWork . ov5pkqlglu [ 6 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
d4xbuzbhso = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
jknd2rgprd [ 6 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
d4xbuzbhso = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
27 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . d4xbuzbhso =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 27 ] = 2.0 ; rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [ 27 ] <= 0.0 )
{ rtDWork . a2j0p0cym5 [ 6 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
d4xbuzbhso = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 27 ] = 0.0 ; rtB . gotfm0hfnu [
6 ] = rtX . ix1fmrtgm0 [ 27 ] ; rtDWork . jknd2rgprd [ 6 ] = 0.0 ; } else {
if ( ( rtX . ix1fmrtgm0 [ 27 ] > 0.0 ) && ( rtB . e2bcofptlp [ 6 ] == 0.0 ) )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . d4xbuzbhso = pvvniy1wrq ; } } break
; } switch ( rtDWork . iewjsudzza ) { case fkpeazmlxh : if ( rtDWork .
ov5pkqlglu [ 3 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 3 ] = 0.0 ; rtDWork .
ov5pkqlglu [ 3 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . iewjsudzza =
pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 3 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . iewjsudzza = ab4gsgwqfm ; }
break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 25 ] >= 2.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . iewjsudzza = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 25
] = 2.0 ; rtB . gotfm0hfnu [ 3 ] = rtX . ix1fmrtgm0 [ 25 ] ; } break ;
default : if ( rtX . ix1fmrtgm0 [ 25 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 3 ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . iewjsudzza = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 25 ] = 0.0 ; for ( i = 0 ; i < 8 ; i ++ ) { rtB . gotfm0hfnu [
i ] = rtX . ix1fmrtgm0 [ 25 ] ; } rtDWork . jknd2rgprd [ 3 ] = 0.0 ; } else {
if ( ( rtX . ix1fmrtgm0 [ 25 ] > 0.0 ) && ( rtB . e2bcofptlp [ 3 ] == 0.0 ) )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . iewjsudzza = pvvniy1wrq ; } } break
; } switch ( rtDWork . lwzxupxcsq ) { case fkpeazmlxh : if ( rtDWork .
ov5pkqlglu [ 7 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 7 ] = 0.0 ; rtDWork .
ov5pkqlglu [ 7 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . lwzxupxcsq =
pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 7 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lwzxupxcsq = ab4gsgwqfm ; }
break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 26 ] >= 2.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . lwzxupxcsq = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 26
] = 2.0 ; rtB . gotfm0hfnu [ 7 ] = rtX . ix1fmrtgm0 [ 26 ] ; } break ;
default : if ( rtX . ix1fmrtgm0 [ 26 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 7 ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . lwzxupxcsq = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 26 ] = 0.0 ; rtB . gotfm0hfnu [ 7 ] = rtX . ix1fmrtgm0 [ 26 ]
; rtDWork . jknd2rgprd [ 7 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 26 ]
> 0.0 ) && ( rtB . e2bcofptlp [ 7 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . lwzxupxcsq = pvvniy1wrq ; } } break ; } switch ( rtDWork .
omrooalxeh ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 1 ] == 1.0 ) {
rtDWork . omfdvdtquy [ 1 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
omrooalxeh = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
j04e3heoks [ 1 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
omrooalxeh = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
7 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . omrooalxeh =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 7 ] = 2.0 ; rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 7 ] > 0.0 )
&& ( rtB . mewmcyb4gt [ 1 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . omrooalxeh = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 7 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . omrooalxeh = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 7 ] = 0.0 ; rtB . bdv4orwwct [ 1 ] = rtX . ix1fmrtgm0 [ 7 ] ;
rtDWork . j04e3heoks [ 1 ] = 0.0 ; } } break ; } switch ( rtDWork .
jmxtcefkhj ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 2 ] == 1.0 ) {
rtDWork . omfdvdtquy [ 2 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
jmxtcefkhj = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
j04e3heoks [ 2 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
jmxtcefkhj = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
16 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . jmxtcefkhj =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 16 ] = 2.0 ; rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 16 ] > 0.0
) && ( rtB . mewmcyb4gt [ 2 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . jmxtcefkhj = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 16 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . jmxtcefkhj = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 16 ] = 0.0 ; rtB . bdv4orwwct [ 2 ] = rtX . ix1fmrtgm0 [ 16 ]
; rtDWork . j04e3heoks [ 2 ] = 0.0 ; } } break ; } switch ( rtDWork .
a0x4w1qbx1 ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 3 ] == 1.0 ) {
rtDWork . omfdvdtquy [ 3 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
a0x4w1qbx1 = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
j04e3heoks [ 3 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
a0x4w1qbx1 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
20 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . a0x4w1qbx1 =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 20 ] = 2.0 ; rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 20 ] > 0.0
) && ( rtB . mewmcyb4gt [ 3 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . a0x4w1qbx1 = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 20 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . a0x4w1qbx1 = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 20 ] = 0.0 ; rtB . bdv4orwwct [ 3 ] = rtX . ix1fmrtgm0 [ 20 ]
; rtDWork . j04e3heoks [ 3 ] = 0.0 ; } } break ; } switch ( rtDWork .
argt12xgun ) { case atiyvzgfnq : if ( ( rtDWork . l2jamqzsvo != rtDWork .
mgytiqynw0 ) && ( rtX . ix1fmrtgm0 [ 0 ] >= 0.0 ) ) { rtDWork . ofotg1tha3 =
10000 ; k = 0 ; i = rtDWork . mgytiqynw0 - 1 ; if ( ( rtDWork . mgytiqynw0 <
0 ) && ( i >= 0 ) ) { i = MIN_int32_T ; } for ( c_index = 0 ; c_index <= i ;
c_index ++ ) { if ( ( rtDWork . l2jamqzsvo != c_index ) && ( rtDWork .
op2f2jmd1g [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] ==
rtDWork . op2f2jmd1g [ c_index ] ) ) { rtDWork . iu4glifpoq = mrrmodciow (
rtDWork . op2f2jmd1g [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 )
- 1 ] , rtDWork . guc4ezu4vd [ c_index ] - rtDWork . guc4ezu4vd [ ( int32_T )
( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] ) ; if ( ( rtDWork .
iu4glifpoq <= 300 ) && ( rtDWork . iu4glifpoq > 0 ) && ( rtDWork . iu4glifpoq
< rtDWork . ofotg1tha3 ) ) { rtDWork . ofotg1tha3 = rtDWork . iu4glifpoq ;
rtDWork . icojgqosr1 [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 )
- 1 ] = c_index + 1 ; k = 1 ; } } } if ( k == 1 ) { rtDWork . ms2wqypsep [ (
int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] = 1.0 ; } rtDWork .
jviamtmzv0 = TRUE ; rtDWork . argt12xgun = nwxu2zxhpj ; rtX . ix1fmrtgm0 [ 0
] = 0.0 ; } else { if ( ( rtDWork . l2jamqzsvo == rtDWork . mgytiqynw0 ) && (
rtX . ix1fmrtgm0 [ 0 ] >= 1.0 ) ) { rtDWork . l2jamqzsvo = 0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . argt12xgun = atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0
] = 0.0 ; } } break ; case cx0bb5ahz2 : if ( rtX . ix1fmrtgm0 [ 0 ] >= 150.0
) { rtDWork . l2jamqzsvo = 0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
argt12xgun = atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 0 ] >= 0.0 ) { if ( ( rtDWork . icojgqosr1 [ 0 ] != -
1 ) && ( rtDWork . bdoe3sih52 [ 0 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 0 ] =
0.0 ; if ( ( kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . icojgqosr1 [ 0 ] -
1 ] - rtDWork . guc4ezu4vd [ 0 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [
rtDWork . icojgqosr1 [ 0 ] - 1 ] != rtDWork . op2f2jmd1g [ 0 ] ) ) { rtDWork
. kd0unb3ts3 [ 0 ] = 1.0 ; rtDWork . bdoe3sih52 [ 0 ] = 0.0 ; } } if ( (
rtDWork . icojgqosr1 [ 1 ] != - 1 ) && ( rtDWork . bdoe3sih52 [ 1 ] == 1.0 )
) { rtDWork . ms2wqypsep [ 1 ] = 0.0 ; if ( ( kwtjth4lfb ( rtDWork .
guc4ezu4vd [ rtDWork . icojgqosr1 [ 1 ] - 1 ] - rtDWork . guc4ezu4vd [ 1 ] )
> 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork . icojgqosr1 [ 1 ] - 1 ] !=
rtDWork . op2f2jmd1g [ 1 ] ) ) { rtDWork . kd0unb3ts3 [ 1 ] = 1.0 ; rtDWork .
bdoe3sih52 [ 1 ] = 0.0 ; } } if ( ( rtDWork . icojgqosr1 [ 2 ] != - 1 ) && (
rtDWork . bdoe3sih52 [ 2 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 2 ] = 0.0 ; if
( ( kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . icojgqosr1 [ 2 ] - 1 ] -
rtDWork . guc4ezu4vd [ 2 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork .
icojgqosr1 [ 2 ] - 1 ] != rtDWork . op2f2jmd1g [ 2 ] ) ) { rtDWork .
kd0unb3ts3 [ 2 ] = 1.0 ; rtDWork . bdoe3sih52 [ 2 ] = 0.0 ; } } if ( (
rtDWork . icojgqosr1 [ 3 ] != - 1 ) && ( rtDWork . bdoe3sih52 [ 3 ] == 1.0 )
) { rtDWork . ms2wqypsep [ 3 ] = 0.0 ; if ( ( kwtjth4lfb ( rtDWork .
guc4ezu4vd [ rtDWork . icojgqosr1 [ 3 ] - 1 ] - rtDWork . guc4ezu4vd [ 3 ] )
> 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork . icojgqosr1 [ 3 ] - 1 ] !=
rtDWork . op2f2jmd1g [ 3 ] ) ) { rtDWork . kd0unb3ts3 [ 3 ] = 1.0 ; rtDWork .
bdoe3sih52 [ 3 ] = 0.0 ; } } rtDWork . l2jamqzsvo ++ ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . argt12xgun = atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; }
break ; } switch ( rtDWork . dxol0tigqi ) { case puirb1divs : if ( rtX .
ix1fmrtgm0 [ 18 ] >= 30.0 ) { rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] =
- rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] ; rtDWork . e5i3qovgis [
rtDWork . jcm3cem4ee ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . jcm3cem4ee ]
= 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = abokkwsuss ; rtX
. ix1fmrtgm0 [ 17 ] = 0.0 ; } break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0
[ 18 ] >= rtDWork . isgvs5svtv [ rtDWork . jcm3cem4ee ] ) { rtDWork .
e5i3qovgis [ rtDWork . jcm3cem4ee ] = 1.0 ; rtDWork . driwqxy21l = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = abokkwsuss ; rtX .
ix1fmrtgm0 [ 17 ] = 0.0 ; } break ; case m1cczpmiyp : if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
driwqxy21l ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . jcm3cem4ee ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . jcm3cem4ee ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . dxol0tigqi = abokkwsuss ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ;
} else { if ( rtDWork . ms2wqypsep [ rtDWork . jcm3cem4ee ] == 1.0 ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = ey4wkwipnf ; } } break ;
case mollve35d0 : if ( rtDWork . ms2wqypsep [ rtDWork . jcm3cem4ee ] == 1.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = ey4wkwipnf ; } else {
if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . driwqxy21l ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork
. jcm3cem4ee ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . jcm3cem4ee ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = abokkwsuss ; rtX .
ix1fmrtgm0 [ 17 ] = 0.0 ; } } break ; case hy3r3w5grg : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . driwqxy21l ] ) <= 500.0 ) { rtDWork . cs4bbjasbf = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 17 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = m1cczpmiyp ; } else if ( rtX .
ix1fmrtgm0 [ 17 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dxol0tigqi = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
jcm3cem4ee ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi =
ey4wkwipnf ; } } break ; case gk0if0h1yc : if ( rtDWork . m2jewdvak1 > 20.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = hy3r3w5grg ; } else {
if ( rtDWork . m2jewdvak1 <= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dxol0tigqi = kpgupuy2kp ; rtDWork . kd0unb3ts3 [ rtDWork . jcm3cem4ee ] = 0.0
; } } break ; case gyxihahkca : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [
19 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork . driwqxy21l ] ) <= 500.0 )
{ rtDWork . cs4bbjasbf = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 17 ] ,
2.0 ) * 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi =
m1cczpmiyp ; } else { if ( rtDWork . ms2wqypsep [ rtDWork . jcm3cem4ee ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = ey4wkwipnf ; } }
break ; case abokkwsuss : if ( rtDWork . bzilocoerc [ rtDWork . jcm3cem4ee ]
== 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . jcm3cem4ee ] = 0.0 ; rtX .
ix1fmrtgm0 [ 18 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi
= nwxu2zxhpjf ; } break ; case nwxu2zxhpjf : if ( ( rtDWork . driwqxy21l ==
0.0 ) && ( rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] == - 1 ) ) { rtDWork
. jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = puirb1divs ; } else if ( ( (
real_T ) ( rtDWork . mgytiqynw0 - 1 ) == rtDWork . driwqxy21l ) && ( rtDWork
. op2f2jmd1g [ rtDWork . jcm3cem4ee ] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . dxol0tigqi = puirb1divs ; } else { if ( ( ( rtDWork . op2f2jmd1g
[ rtDWork . jcm3cem4ee ] == 1 ) && ( rtDWork . driwqxy21l < ( real_T ) (
rtDWork . mgytiqynw0 - 1 ) ) ) || ( ( rtDWork . op2f2jmd1g [ rtDWork .
jcm3cem4ee ] == - 1 ) && ( rtDWork . driwqxy21l > 0.0 ) ) ) { rtDWork .
driwqxy21l += ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . dxol0tigqi = hy3r3w5grg ; } } break ;
case ey4wkwipnf : if ( rtX . ix1fmrtgm0 [ 17 ] <= 0.1 ) { rtDWork .
bdoe3sih52 [ rtDWork . jcm3cem4ee ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . dxol0tigqi = bg2pxs4yrg ; } break ; case kpgupuy2kp : if ( rtX .
ix1fmrtgm0 [ 17 ] >= rtDWork . m2jewdvak1 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . dxol0tigqi = mollve35d0 ; } else { if ( rtDWork . ms2wqypsep [
rtDWork . jcm3cem4ee ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dxol0tigqi = ey4wkwipnf ; } } break ; default : if ( rtDWork . kd0unb3ts3 [
rtDWork . jcm3cem4ee ] == 1.0 ) { rtDWork . m2jewdvak1 = muDoubleScalarSqrt (
muDoubleScalarAbs ( rtDWork . duzuwa454g [ ( int32_T ) rtDWork . driwqxy21l ]
- rtX . ix1fmrtgm0 [ 19 ] ) * 0.5 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dxol0tigqi = gk0if0h1yc ; } break ; } switch ( rtDWork . gorxzp2tc5 ) { case
mce1hmjau3 : if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . j04e3heoks [
rtDWork . f2e0swgpo5 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; case
bozn0j4h3r : if ( ( rtDWork . omrooalxeh == fkpeazmlxh ) == 0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 1
] = 0.0 ; } else { if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork .
jknd2rgprd [ ( int32_T ) rtDWork . nvaeng4gwq + ( ( int32_T ) rtDWork .
n0eg025vjq << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } } break ; case
bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 1 ] >= 1.0 ) { rtDWork . omfdvdtquy [
rtDWork . f2e0swgpo5 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = g5thp4xumb ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; case
jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ (
int32_T ) rtDWork . nvaeng4gwq + ( ( int32_T ) rtDWork . n0eg025vjq << 2 ) ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = bpsmzkxnnb ; rtX
. ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; case h05jpwy3hy : if ( rtDWork .
e5i3qovgis [ rtDWork . f2e0swgpo5 ] == 1.0 ) { rtDWork . f2e0swgpo5 = 1 ;
rtDWork . nvaeng4gwq = rtDWork . gtkvhlkzsc ; i = rtDWork . op2f2jmd1g [
rtDWork . f2e0swgpo5 ] + 1 ; rtDWork . n0eg025vjq = ( real_T ) ( ( ( i < 0 )
+ i ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 =
jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
f2e0swgpo5 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 1 ] >= 1.0 ) && (
rtDWork . e5i3qovgis [ rtDWork . f2e0swgpo5 ] != 1.0 ) ) { rtDWork .
guc4ezu4vd [ rtDWork . f2e0swgpo5 ] = rtX . ix1fmrtgm0 [ 10 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 1 ] >= 10.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = czs3vnbrbl ; } break ;
case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 1 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 1 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
f2e0swgpo5 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . n0eg025vjq << 2 ) + ( int32_T ) rtDWork
. nvaeng4gwq ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } } break ; } switch ( rtDWork
. eke5mcashi ) { case mce1hmjau3 : if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) {
rtDWork . j04e3heoks [ rtDWork . ijkudaz05s ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . eke5mcashi = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; }
break ; case bozn0j4h3r : if ( ( rtDWork . jmxtcefkhj == fkpeazmlxh ) == 0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 12 ] = 0.0 ; } else { if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) {
rtDWork . jknd2rgprd [ ( int32_T ) rtDWork . lltfkpbor1 + ( ( int32_T )
rtDWork . fubcl3argx << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
eke5mcashi = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } } break ; case
bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 12 ] >= 1.0 ) { rtDWork . omfdvdtquy [
rtDWork . ijkudaz05s ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
eke5mcashi = g5thp4xumb ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; case
jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ (
int32_T ) rtDWork . lltfkpbor1 + ( ( int32_T ) rtDWork . fubcl3argx << 2 ) ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi = bpsmzkxnnb ; rtX
. ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; case h05jpwy3hy : if ( rtDWork .
e5i3qovgis [ rtDWork . ijkudaz05s ] == 1.0 ) { rtDWork . ijkudaz05s = 2 ;
rtDWork . lltfkpbor1 = rtDWork . jnkyxamnrc ; i = rtDWork . op2f2jmd1g [
rtDWork . ijkudaz05s ] + 1 ; rtDWork . fubcl3argx = ( real_T ) ( ( ( i < 0 )
+ i ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi =
jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
ijkudaz05s ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 12 ] >= 1.0 ) && (
rtDWork . e5i3qovgis [ rtDWork . ijkudaz05s ] != 1.0 ) ) { rtDWork .
guc4ezu4vd [ rtDWork . ijkudaz05s ] = rtX . ix1fmrtgm0 [ 15 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . eke5mcashi = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 12
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 12 ] >= 10.0
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi = czs3vnbrbl ; } break
; case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 12 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 12 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
eke5mcashi = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
ijkudaz05s ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . fubcl3argx << 2 ) + ( int32_T ) rtDWork
. lltfkpbor1 ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . eke5mcashi
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } } break ; } switch ( rtDWork
. dtvanlzaoj ) { case mce1hmjau3 : if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) {
rtDWork . j04e3heoks [ rtDWork . a3ymfl4ch4 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . dtvanlzaoj = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; }
break ; case bozn0j4h3r : if ( ( rtDWork . a0x4w1qbx1 == fkpeazmlxh ) == 0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 11 ] = 0.0 ; } else { if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) {
rtDWork . jknd2rgprd [ ( int32_T ) rtDWork . prfb015v23 + ( ( int32_T )
rtDWork . e11zy0frlw << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dtvanlzaoj = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } } break ; case
bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 11 ] >= 1.0 ) { rtDWork . omfdvdtquy [
rtDWork . a3ymfl4ch4 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dtvanlzaoj = g5thp4xumb ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; case
jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ (
int32_T ) rtDWork . prfb015v23 + ( ( int32_T ) rtDWork . e11zy0frlw << 2 ) ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj = bpsmzkxnnb ; rtX
. ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; case h05jpwy3hy : if ( rtDWork .
e5i3qovgis [ rtDWork . a3ymfl4ch4 ] == 1.0 ) { rtDWork . a3ymfl4ch4 = 3 ;
rtDWork . prfb015v23 = rtDWork . driwqxy21l ; i = rtDWork . op2f2jmd1g [
rtDWork . a3ymfl4ch4 ] + 1 ; rtDWork . e11zy0frlw = ( real_T ) ( ( ( i < 0 )
+ i ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj =
jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
a3ymfl4ch4 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 11 ] >= 1.0 ) && (
rtDWork . e5i3qovgis [ rtDWork . a3ymfl4ch4 ] != 1.0 ) ) { rtDWork .
guc4ezu4vd [ rtDWork . a3ymfl4ch4 ] = rtX . ix1fmrtgm0 [ 19 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 11 ] >= 10.0
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj = czs3vnbrbl ; } break
; case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 11 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 11 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
dtvanlzaoj = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
a3ymfl4ch4 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . e11zy0frlw << 2 ) + ( int32_T ) rtDWork
. prfb015v23 ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . dtvanlzaoj
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } } break ; } switch ( rtDWork
. khvi5cgv0x ) { case puirb1divs : if ( rtX . ix1fmrtgm0 [ 3 ] >= 30.0 ) {
rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] = - rtDWork . op2f2jmd1g [
rtDWork . depxwofcb1 ] ; rtDWork . e5i3qovgis [ rtDWork . depxwofcb1 ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . depxwofcb1 ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . khvi5cgv0x = abokkwsuss ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; }
break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [ 3 ] >= rtDWork . isgvs5svtv
[ rtDWork . depxwofcb1 ] ) { rtDWork . e5i3qovgis [ rtDWork . depxwofcb1 ] =
1.0 ; rtDWork . myinbg3jep = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
khvi5cgv0x = abokkwsuss ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } break ; case
m1cczpmiyp : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 4 ] - rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . myinbg3jep ] ) <= 1.0 ) { rtDWork .
e5i3qovgis [ rtDWork . depxwofcb1 ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork .
depxwofcb1 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x =
abokkwsuss ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } else { if ( rtDWork .
ms2wqypsep [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . khvi5cgv0x = ey4wkwipnf ; } } break ; case mollve35d0 : if (
rtDWork . ms2wqypsep [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . khvi5cgv0x = ey4wkwipnf ; } else { if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 4 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
myinbg3jep ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . depxwofcb1 ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . depxwofcb1 ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . khvi5cgv0x = abokkwsuss ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; }
} break ; case hy3r3w5grg : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 4 ] -
rtDWork . duzuwa454g [ ( int32_T ) rtDWork . myinbg3jep ] ) <= 500.0 ) {
rtDWork . oqkftxqo0p = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 2 ] , 2.0 )
* 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = m1cczpmiyp ; }
else if ( rtX . ix1fmrtgm0 [ 2 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . khvi5cgv0x = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [
rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
khvi5cgv0x = ey4wkwipnf ; } } break ; case gk0if0h1yc : if ( rtDWork .
ckdvmn4dp4 > 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x =
hy3r3w5grg ; } else { if ( rtDWork . ckdvmn4dp4 <= 20.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = kpgupuy2kp ; rtDWork . kd0unb3ts3
[ rtDWork . depxwofcb1 ] = 0.0 ; } } break ; case gyxihahkca : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 4 ] - rtDWork . duzuwa454g [ ( int32_T
) rtDWork . myinbg3jep ] ) <= 500.0 ) { rtDWork . oqkftxqo0p = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 2 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = m1cczpmiyp ; } else { if ( rtDWork
. ms2wqypsep [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . khvi5cgv0x = ey4wkwipnf ; } } break ; case abokkwsuss : if (
rtDWork . bzilocoerc [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork . e5i3qovgis
[ rtDWork . depxwofcb1 ] = 0.0 ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = nwxu2zxhpjf ; } break ; case
nwxu2zxhpjf : if ( ( rtDWork . myinbg3jep == 0.0 ) && ( rtDWork . op2f2jmd1g
[ rtDWork . depxwofcb1 ] == - 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
khvi5cgv0x = puirb1divs ; } else if ( ( ( real_T ) ( rtDWork . mgytiqynw0 - 1
) == rtDWork . myinbg3jep ) && ( rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1
] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = puirb1divs
; } else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] == 1 ) && (
rtDWork . myinbg3jep < ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ) ) || ( (
rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] == - 1 ) && ( rtDWork .
myinbg3jep > 0.0 ) ) ) { rtDWork . myinbg3jep += ( real_T ) rtDWork .
op2f2jmd1g [ rtDWork . depxwofcb1 ] ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
khvi5cgv0x = hy3r3w5grg ; } } break ; case ey4wkwipnf : if ( rtX . ix1fmrtgm0
[ 2 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ rtDWork . depxwofcb1 ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = bg2pxs4yrg ; } break ;
case kpgupuy2kp : if ( rtX . ix1fmrtgm0 [ 2 ] >= rtDWork . ckdvmn4dp4 ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = mollve35d0 ; } else { if
( rtDWork . ms2wqypsep [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = ey4wkwipnf ; } } break ; default :
if ( rtDWork . kd0unb3ts3 [ rtDWork . depxwofcb1 ] == 1.0 ) { rtDWork .
ckdvmn4dp4 = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtDWork . duzuwa454g [
( int32_T ) rtDWork . myinbg3jep ] - rtX . ix1fmrtgm0 [ 4 ] ) * 0.5 ) ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . khvi5cgv0x = gk0if0h1yc ; } break ; }
switch ( rtDWork . hovg3awtfp ) { case puirb1divs : if ( rtX . ix1fmrtgm0 [ 9
] >= 30.0 ) { rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] = - rtDWork .
op2f2jmd1g [ rtDWork . fqbexa5vby ] ; rtDWork . e5i3qovgis [ rtDWork .
fqbexa5vby ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . fqbexa5vby ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = abokkwsuss ; rtX .
ix1fmrtgm0 [ 8 ] = 0.0 ; } break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [
9 ] >= rtDWork . isgvs5svtv [ rtDWork . fqbexa5vby ] ) { rtDWork . e5i3qovgis
[ rtDWork . fqbexa5vby ] = 1.0 ; rtDWork . gtkvhlkzsc = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = abokkwsuss ; rtX . ix1fmrtgm0 [ 8
] = 0.0 ; } break ; case m1cczpmiyp : if ( muDoubleScalarAbs ( rtX .
ix1fmrtgm0 [ 10 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork . gtkvhlkzsc ]
) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . fqbexa5vby ] = 1.0 ; rtDWork .
bzilocoerc [ rtDWork . fqbexa5vby ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . hovg3awtfp = abokkwsuss ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; } else {
if ( rtDWork . ms2wqypsep [ rtDWork . fqbexa5vby ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = ey4wkwipnf ; } } break ; case
mollve35d0 : if ( rtDWork . ms2wqypsep [ rtDWork . fqbexa5vby ] == 1.0 ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = ey4wkwipnf ; } else { if
( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 10 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . gtkvhlkzsc ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork
. fqbexa5vby ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . fqbexa5vby ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = abokkwsuss ; rtX .
ix1fmrtgm0 [ 8 ] = 0.0 ; } } break ; case hy3r3w5grg : if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 10 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
gtkvhlkzsc ] ) <= 500.0 ) { rtDWork . hzbs4lmhew = - muDoubleScalarPower (
rtX . ix1fmrtgm0 [ 8 ] , 2.0 ) * 0.001 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . hovg3awtfp = m1cczpmiyp ; } else if ( rtX . ix1fmrtgm0 [ 8 ] >=
20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = gyxihahkca ; }
else { if ( rtDWork . ms2wqypsep [ rtDWork . fqbexa5vby ] == 1.0 ) { rtDWork
. jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = ey4wkwipnf ; } } break ; case
gk0if0h1yc : if ( rtDWork . fhaqcxx030 > 20.0 ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . hovg3awtfp = hy3r3w5grg ; } else { if ( rtDWork . fhaqcxx030 <=
20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = kpgupuy2kp ;
rtDWork . kd0unb3ts3 [ rtDWork . fqbexa5vby ] = 0.0 ; } } break ; case
gyxihahkca : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 10 ] - rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . gtkvhlkzsc ] ) <= 500.0 ) { rtDWork .
hzbs4lmhew = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 8 ] , 2.0 ) * 0.001 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = m1cczpmiyp ; } else { if
( rtDWork . ms2wqypsep [ rtDWork . fqbexa5vby ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = ey4wkwipnf ; } } break ; case
abokkwsuss : if ( rtDWork . bzilocoerc [ rtDWork . fqbexa5vby ] == 1.0 ) {
rtDWork . e5i3qovgis [ rtDWork . fqbexa5vby ] = 0.0 ; rtX . ix1fmrtgm0 [ 9 ]
= 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = nwxu2zxhpjf ; }
break ; case nwxu2zxhpjf : if ( ( rtDWork . gtkvhlkzsc == 0.0 ) && ( rtDWork
. op2f2jmd1g [ rtDWork . fqbexa5vby ] == - 1 ) ) { rtDWork . jviamtmzv0 =
TRUE ; rtDWork . hovg3awtfp = puirb1divs ; } else if ( ( ( real_T ) ( rtDWork
. mgytiqynw0 - 1 ) == rtDWork . gtkvhlkzsc ) && ( rtDWork . op2f2jmd1g [
rtDWork . fqbexa5vby ] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
hovg3awtfp = puirb1divs ; } else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork .
fqbexa5vby ] == 1 ) && ( rtDWork . gtkvhlkzsc < ( real_T ) ( rtDWork .
mgytiqynw0 - 1 ) ) ) || ( ( rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] ==
- 1 ) && ( rtDWork . gtkvhlkzsc > 0.0 ) ) ) { rtDWork . gtkvhlkzsc += (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . hovg3awtfp = hy3r3w5grg ; } } break ; case ey4wkwipnf : if
( rtX . ix1fmrtgm0 [ 8 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ rtDWork .
fqbexa5vby ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp =
bg2pxs4yrg ; } break ; case kpgupuy2kp : if ( rtX . ix1fmrtgm0 [ 8 ] >=
rtDWork . fhaqcxx030 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp =
mollve35d0 ; } else { if ( rtDWork . ms2wqypsep [ rtDWork . fqbexa5vby ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = ey4wkwipnf ; } }
break ; default : if ( rtDWork . kd0unb3ts3 [ rtDWork . fqbexa5vby ] == 1.0 )
{ rtDWork . fhaqcxx030 = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . gtkvhlkzsc ] - rtX . ix1fmrtgm0 [ 10 ] ) *
0.5 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . hovg3awtfp = gk0if0h1yc ; }
break ; } switch ( rtDWork . myspnolkmq ) { case puirb1divs : if ( rtX .
ix1fmrtgm0 [ 14 ] >= 30.0 ) { rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] =
- rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] ; rtDWork . e5i3qovgis [
rtDWork . ogmhlc5iu0 ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . ogmhlc5iu0 ]
= 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = abokkwsuss ; rtX
. ix1fmrtgm0 [ 13 ] = 0.0 ; } break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0
[ 14 ] >= rtDWork . isgvs5svtv [ rtDWork . ogmhlc5iu0 ] ) { rtDWork .
e5i3qovgis [ rtDWork . ogmhlc5iu0 ] = 1.0 ; rtDWork . jnkyxamnrc = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = abokkwsuss ; rtX .
ix1fmrtgm0 [ 13 ] = 0.0 ; } break ; case m1cczpmiyp : if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
jnkyxamnrc ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . ogmhlc5iu0 ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . ogmhlc5iu0 ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . myspnolkmq = abokkwsuss ; rtX . ix1fmrtgm0 [ 13 ] = 0.0 ;
} else { if ( rtDWork . ms2wqypsep [ rtDWork . ogmhlc5iu0 ] == 1.0 ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = ey4wkwipnf ; } } break ;
case mollve35d0 : if ( rtDWork . ms2wqypsep [ rtDWork . ogmhlc5iu0 ] == 1.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = ey4wkwipnf ; } else {
if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . jnkyxamnrc ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork
. ogmhlc5iu0 ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . ogmhlc5iu0 ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = abokkwsuss ; rtX .
ix1fmrtgm0 [ 13 ] = 0.0 ; } } break ; case hy3r3w5grg : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . jnkyxamnrc ] ) <= 500.0 ) { rtDWork . opegpgmqkc = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 13 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = m1cczpmiyp ; } else if ( rtX .
ix1fmrtgm0 [ 13 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
myspnolkmq = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
ogmhlc5iu0 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq =
ey4wkwipnf ; } } break ; case gk0if0h1yc : if ( rtDWork . jmy4ojj1wm > 20.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = hy3r3w5grg ; } else {
if ( rtDWork . jmy4ojj1wm <= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
myspnolkmq = kpgupuy2kp ; rtDWork . kd0unb3ts3 [ rtDWork . ogmhlc5iu0 ] = 0.0
; } } break ; case gyxihahkca : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [
15 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork . jnkyxamnrc ] ) <= 500.0 )
{ rtDWork . opegpgmqkc = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 13 ] ,
2.0 ) * 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq =
m1cczpmiyp ; } else { if ( rtDWork . ms2wqypsep [ rtDWork . ogmhlc5iu0 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = ey4wkwipnf ; } }
break ; case abokkwsuss : if ( rtDWork . bzilocoerc [ rtDWork . ogmhlc5iu0 ]
== 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . ogmhlc5iu0 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 14 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq
= nwxu2zxhpjf ; } break ; case nwxu2zxhpjf : if ( ( rtDWork . jnkyxamnrc ==
0.0 ) && ( rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] == - 1 ) ) { rtDWork
. jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = puirb1divs ; } else if ( ( (
real_T ) ( rtDWork . mgytiqynw0 - 1 ) == rtDWork . jnkyxamnrc ) && ( rtDWork
. op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . myspnolkmq = puirb1divs ; } else { if ( ( ( rtDWork . op2f2jmd1g
[ rtDWork . ogmhlc5iu0 ] == 1 ) && ( rtDWork . jnkyxamnrc < ( real_T ) (
rtDWork . mgytiqynw0 - 1 ) ) ) || ( ( rtDWork . op2f2jmd1g [ rtDWork .
ogmhlc5iu0 ] == - 1 ) && ( rtDWork . jnkyxamnrc > 0.0 ) ) ) { rtDWork .
jnkyxamnrc += ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . myspnolkmq = hy3r3w5grg ; } } break ;
case ey4wkwipnf : if ( rtX . ix1fmrtgm0 [ 13 ] <= 0.1 ) { rtDWork .
bdoe3sih52 [ rtDWork . ogmhlc5iu0 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . myspnolkmq = bg2pxs4yrg ; } break ; case kpgupuy2kp : if ( rtX .
ix1fmrtgm0 [ 13 ] >= rtDWork . jmy4ojj1wm ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . myspnolkmq = mollve35d0 ; } else { if ( rtDWork . ms2wqypsep [
rtDWork . ogmhlc5iu0 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
myspnolkmq = ey4wkwipnf ; } } break ; default : if ( rtDWork . kd0unb3ts3 [
rtDWork . ogmhlc5iu0 ] == 1.0 ) { rtDWork . jmy4ojj1wm = muDoubleScalarSqrt (
muDoubleScalarAbs ( rtDWork . duzuwa454g [ ( int32_T ) rtDWork . jnkyxamnrc ]
- rtX . ix1fmrtgm0 [ 15 ] ) * 0.5 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
myspnolkmq = gk0if0h1yc ; } break ; } } if ( rtDWork . jviamtmzv0 ) {
ssSetSolverNeedsReset ( rtS ) ; } } k0nn3it3fd ( ) ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; if ( ssGetLogOutput ( rtS ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDWork . fcdtvsyw4o . LoggedData
, & locTime , rtB . bdv4orwwct ) ; } } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives (
void ) { StateDerivatives * _rtXdot ; _rtXdot = ( ( StateDerivatives * )
ssGetdX ( rtS ) ) ; _rtXdot -> ix1fmrtgm0 [ 0 ] = 0.0 ; _rtXdot -> ix1fmrtgm0
[ 1 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 2 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 3 ]
= 0.0 ; _rtXdot -> ix1fmrtgm0 [ 4 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 5 ] = 0.0
; _rtXdot -> ix1fmrtgm0 [ 6 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 7 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 8 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 9 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 10 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 11 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 12 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 13 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 14 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 15 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 16 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 18 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 19 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 20 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 21 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 22 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 23 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 24 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 25 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 26 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 27 ] = 0.0 ;
_rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; switch ( rtDWork . mtzmj2oq0u ) { case
fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 6 ] = 0.0 ; break ; case nsgxdn54fe :
_rtXdot -> ix1fmrtgm0 [ 6 ] = 0.0 ; break ; case pvvniy1wrq : _rtXdot ->
ix1fmrtgm0 [ 6 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0 [ 6 ] = rtB
. mewmcyb4gt [ 0 ] ; break ; } switch ( rtDWork . jnwppiorce ) { case
fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 24 ] = 0.0 ; break ; case nsgxdn54fe :
_rtXdot -> ix1fmrtgm0 [ 24 ] = 0.0 ; break ; case pvvniy1wrq : _rtXdot ->
ix1fmrtgm0 [ 24 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0 [ 24 ] =
rtB . e2bcofptlp [ 0 ] ; break ; } _rtXdot -> ix1fmrtgm0 [ 5 ] = 1.0 ; switch
( rtDWork . oxqnny3i5s ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 23 ] =
0.0 ; break ; case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 23 ] = 0.0 ; break ;
case pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 23 ] = 1.0 ; break ; default :
_rtXdot -> ix1fmrtgm0 [ 23 ] = rtB . e2bcofptlp [ 4 ] ; break ; } switch (
rtDWork . h4hy2vxqsc ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 21 ] = 0.0
; break ; case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 21 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 21 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 21 ] = rtB . e2bcofptlp [ 1 ] ; break ; } switch ( rtDWork .
e10uflryt4 ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 22 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 22 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 22 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 22 ] = rtB . e2bcofptlp [ 5 ] ; break ; } switch ( rtDWork .
bl2j5t1c00 ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 28 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 28 ] = rtB . e2bcofptlp [ 2 ] ; break ; } switch ( rtDWork .
d4xbuzbhso ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 27 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 27 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 27 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 27 ] = rtB . e2bcofptlp [ 6 ] ; break ; } switch ( rtDWork .
iewjsudzza ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 25 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 25 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 25 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 25 ] = rtB . e2bcofptlp [ 3 ] ; break ; } switch ( rtDWork .
lwzxupxcsq ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 26 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 26 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 26 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 26 ] = rtB . e2bcofptlp [ 7 ] ; break ; } switch ( rtDWork .
omrooalxeh ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 7 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 7 ] = 0.0 ; break ; case pvvniy1wrq
: _rtXdot -> ix1fmrtgm0 [ 7 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 7 ] = rtB . mewmcyb4gt [ 1 ] ; break ; } switch ( rtDWork . jmxtcefkhj ) {
case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 16 ] = 0.0 ; break ; case
nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 16 ] = 0.0 ; break ; case pvvniy1wrq :
_rtXdot -> ix1fmrtgm0 [ 16 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 16 ] = rtB . mewmcyb4gt [ 2 ] ; break ; } switch ( rtDWork . a0x4w1qbx1 ) {
case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 20 ] = 0.0 ; break ; case
nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 20 ] = 0.0 ; break ; case pvvniy1wrq :
_rtXdot -> ix1fmrtgm0 [ 20 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 20 ] = rtB . mewmcyb4gt [ 3 ] ; break ; } switch ( rtDWork . argt12xgun ) {
case atiyvzgfnq : _rtXdot -> ix1fmrtgm0 [ 0 ] = 0.5 ; break ; case cx0bb5ahz2
: _rtXdot -> ix1fmrtgm0 [ 0 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 0 ] = 0.5 ; break ; } switch ( rtDWork . dxol0tigqi ) { case puirb1divs :
_rtXdot -> ix1fmrtgm0 [ 18 ] = 1.0 ; break ; case poj1ujn0qm : _rtXdot ->
ix1fmrtgm0 [ 18 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [
19 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] * rtX .
ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = rtDWork . cs4bbjasbf ;
break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T ) rtDWork .
op2f2jmd1g [ rtDWork . jcm3cem4ee ] * rtX . ix1fmrtgm0 [ 17 ] ; _rtXdot ->
ix1fmrtgm0 [ 17 ] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [
19 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] * rtX .
ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.5 ; break ; case
gk0if0h1yc : break ; case gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 19 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] * rtX . ix1fmrtgm0 [
17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.0 ; break ; case abokkwsuss : break ;
case nwxu2zxhpjf : break ; case ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 19 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . jcm3cem4ee ] * rtX . ix1fmrtgm0 [
17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = - 1.5 ; break ; case kpgupuy2kp :
_rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork .
jcm3cem4ee ] * rtX . ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.5 ;
break ; default : _rtXdot -> ix1fmrtgm0 [ 19 ] = 0.0 ; _rtXdot -> ix1fmrtgm0
[ 17 ] = 0.0 ; break ; } _rtXdot -> ix1fmrtgm0 [ 1 ] = 1.0 ; _rtXdot ->
ix1fmrtgm0 [ 12 ] = 1.0 ; _rtXdot -> ix1fmrtgm0 [ 11 ] = 1.0 ; switch (
rtDWork . khvi5cgv0x ) { case puirb1divs : _rtXdot -> ix1fmrtgm0 [ 3 ] = 1.0
; break ; case poj1ujn0qm : _rtXdot -> ix1fmrtgm0 [ 3 ] = 1.0 ; break ; case
m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [ 4 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . depxwofcb1 ] * rtX . ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ]
= rtDWork . oqkftxqo0p ; break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 4
] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] * rtX .
ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ] = - 0.5 ; break ; case
hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [ 4 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . depxwofcb1 ] * rtX . ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ]
= 0.5 ; break ; case gk0if0h1yc : break ; case gyxihahkca : _rtXdot ->
ix1fmrtgm0 [ 4 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] *
rtX . ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ] = 0.0 ; break ; case
abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : _rtXdot ->
ix1fmrtgm0 [ 4 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . depxwofcb1 ] *
rtX . ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ] = - 1.5 ; break ; case
kpgupuy2kp : _rtXdot -> ix1fmrtgm0 [ 4 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . depxwofcb1 ] * rtX . ix1fmrtgm0 [ 2 ] ; _rtXdot -> ix1fmrtgm0 [ 2 ]
= 0.5 ; break ; default : _rtXdot -> ix1fmrtgm0 [ 4 ] = 0.0 ; _rtXdot ->
ix1fmrtgm0 [ 2 ] = 0.0 ; break ; } switch ( rtDWork . hovg3awtfp ) { case
puirb1divs : _rtXdot -> ix1fmrtgm0 [ 9 ] = 1.0 ; break ; case poj1ujn0qm :
_rtXdot -> ix1fmrtgm0 [ 9 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot ->
ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ]
* rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = rtDWork . hzbs4lmhew
; break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork
. op2f2jmd1g [ rtDWork . fqbexa5vby ] * rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot ->
ix1fmrtgm0 [ 8 ] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [
10 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] * rtX .
ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = 0.5 ; break ; case
gk0if0h1yc : break ; case gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 10 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] * rtX . ix1fmrtgm0 [ 8
] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = 0.0 ; break ; case abokkwsuss : break ;
case nwxu2zxhpjf : break ; case ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 10 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby ] * rtX . ix1fmrtgm0 [ 8
] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = - 1.5 ; break ; case kpgupuy2kp : _rtXdot
-> ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . fqbexa5vby
] * rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = 0.5 ; break ;
default : _rtXdot -> ix1fmrtgm0 [ 10 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 8 ] =
0.0 ; break ; } switch ( rtDWork . myspnolkmq ) { case puirb1divs : _rtXdot
-> ix1fmrtgm0 [ 14 ] = 1.0 ; break ; case poj1ujn0qm : _rtXdot -> ix1fmrtgm0
[ 14 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [ 15 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [
13 ] ; _rtXdot -> ix1fmrtgm0 [ 13 ] = rtDWork . opegpgmqkc ; break ; case
mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13
] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T
) rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [ 13 ] ;
_rtXdot -> ix1fmrtgm0 [ 13 ] = 0.5 ; break ; case gk0if0h1yc : break ; case
gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13
] = 0.0 ; break ; case abokkwsuss : break ; case nwxu2zxhpjf : break ; case
ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13
] = - 1.5 ; break ; case kpgupuy2kp : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T
) rtDWork . op2f2jmd1g [ rtDWork . ogmhlc5iu0 ] * rtX . ix1fmrtgm0 [ 13 ] ;
_rtXdot -> ix1fmrtgm0 [ 13 ] = 0.5 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 15 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 13 ] = 0.0 ; break ; } } void
MdlProjection ( void ) { } void MdlTerminate ( void ) { } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 29 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 68 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 36 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 570973301U ) ; ssSetChecksumVal ( rtS ,
1 , 2641100052U ) ; ssSetChecksumVal ( rtS , 2 , 3662954902U ) ;
ssSetChecksumVal ( rtS , 3 , 1657690244U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( BlockIO ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = ( real_T * )
& rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 ,
sizeof ( ContinuousStates ) ) ; } { void * dwork = ( void * ) & rtDWork ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof (
D_Work ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T
* ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , &
dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . B = & rtBTransTable ; dtInfo . P = & rtPTransTable ; } ssSetRootSS (
rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ;
ssSetModelName ( rtS , "subwaycontrolsystem" ) ; ssSetPath ( rtS ,
"subwaycontrolsystem" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS ,
2000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 29 } ;
static int_T rt_LoggedStateNumDimensions [ ] = { 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 29 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "subwaycontrolsystem/PSDS stateflow chart" }
; static const char_T * rt_LoggedStateNames [ ] = { "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 1 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 1 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ix1fmrtgm0 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetSigLog ( ssGetRTWLogInfo ( rtS
) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 29
] ; static real_T absTol [ 29 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 29 ] = { 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 4 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cytqvalje5 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
h32onzoiii ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
nojiyg1svu ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
mgreqddwbk ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 1.0E-6 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.1 ) ; ssSetSolverMaxOrder ( rtS , 5 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
4 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode15s" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 570973301U ) ; ssSetChecksumVal ( rtS , 1 ,
2641100052U ) ; ssSetChecksumVal ( rtS , 2 , 3662954902U ) ; ssSetChecksumVal
( rtS , 3 , 1657690244U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 27 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ;
systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ;
systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ;
systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ;
systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ;
systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ;
systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ;
systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ;
systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ;
systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = & rtAlwaysEnabled ;
systemRan [ 26 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
