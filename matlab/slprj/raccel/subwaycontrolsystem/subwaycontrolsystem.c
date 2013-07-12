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
#define abokkwsuss ((uint8_T)7U)
#define atiyvzgfnq ((uint8_T)1U)
#define bg2pxs4yrg ((uint8_T)11U)
#define bozn0j4h3r ((uint8_T)2U)
#define bpsmzkxnnb ((uint8_T)3U)
#define cx0bb5ahz2 ((uint8_T)2U)
#define czs3vnbrbl ((uint8_T)7U)
#define ey4wkwipnf ((uint8_T)9U)
#define fkpeazmlxh ((uint8_T)1U)
#define g5thp4xumb ((uint8_T)6U)
#define gyxihahkca ((uint8_T)6U)
#define h05jpwy3hy ((uint8_T)5U)
#define hjcg5jty2z ((uint8_T)8U)
#define hy3r3w5grg ((uint8_T)5U)
#define jkd1vnqob2 ((uint8_T)4U)
#define kpgupuy2kp ((uint8_T)10U)
#define m1cczpmiyp ((uint8_T)3U)
#define mce1hmjau3 ((uint8_T)1U)
#define mollve35d0 ((uint8_T)4U)
#define nsgxdn54fe ((uint8_T)2U)
#define nwxu2zxhpj ((uint8_T)3U)
#define nwxu2zxhpjf ((uint8_T)8U)
#define pe5ts3cbxi ((uint8_T)0U)
#define poj1ujn0qm ((uint8_T)2U)
#define puirb1divs ((uint8_T)1U)
#define pvvniy1wrq ((uint8_T)3U)
BlockIO rtB ; ContinuousStates rtX ; D_Work rtDWork ; static SimStruct
model_S ; SimStruct * const rtS = & model_S ; static real_T cssdru3pr0 (
real_T x ) ; static real_T kwtjth4lfb ( real_T x ) ; static void k0nn3it3fd (
void ) ; static real_T cssdru3pr0 ( real_T x ) { return muDoubleScalarAbs ( x
) ; } static real_T kwtjth4lfb ( real_T x ) { return cssdru3pr0 ( x ) ; }
static void k0nn3it3fd ( void ) { switch ( rtDWork . e0siqbw4px ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; break ; default : rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; break ; } switch ( rtDWork . piy1mfyq04 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; default : rtB . gotfm0hfnu [ 0 ] = rtX .
ix1fmrtgm0 [ 24 ] ; break ; } switch ( rtDWork . m1coawef1z ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; default : rtB . gotfm0hfnu [ 4 ] = rtX .
ix1fmrtgm0 [ 23 ] ; break ; } switch ( rtDWork . kxzqsowcq4 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; default : rtB . gotfm0hfnu [ 1 ] = rtX .
ix1fmrtgm0 [ 21 ] ; break ; } switch ( rtDWork . puu0onps1o ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; default : rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; break ; } switch ( rtDWork . d5gd34izwy ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; default : rtB . gotfm0hfnu [ 2 ] = rtX .
ix1fmrtgm0 [ 28 ] ; break ; } switch ( rtDWork . m4axwklc2n ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; default : rtB . gotfm0hfnu [ 6 ] = rtX .
ix1fmrtgm0 [ 27 ] ; break ; } switch ( rtDWork . cor0ek34i1 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; default : rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; break ; } switch ( rtDWork . bieuzbl5sa ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; case pvvniy1wrq : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; default : rtB . gotfm0hfnu [ 7 ] = rtX .
ix1fmrtgm0 [ 26 ] ; break ; } switch ( rtDWork . e2s0vhz32j ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; default : rtB . bdv4orwwct [ 1 ] = rtX .
ix1fmrtgm0 [ 7 ] ; break ; } switch ( rtDWork . psc01ml3a2 ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; default : rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; break ; } switch ( rtDWork . fgm4uvex5n ) { case
fkpeazmlxh : break ; case nsgxdn54fe : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; case pvvniy1wrq : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; default : rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; break ; } switch ( rtDWork . l5nch0wfe0 ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5
] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . eli0bu1nqi ] = rtX
. ix1fmrtgm0 [ 5 ] ; break ; case gyxihahkca : rtB . l3p1u43lj0 [ rtDWork .
eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5 ] ; break ; case abokkwsuss : break ;
case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB . l3p1u43lj0 [ rtDWork .
eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5 ] ; break ; case kpgupuy2kp : rtB .
l3p1u43lj0 [ rtDWork . eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5 ] ; break ;
default : rtB . l3p1u43lj0 [ rtDWork . eli0bu1nqi ] = rtX . ix1fmrtgm0 [ 5 ]
; break ; } switch ( rtDWork . af0eeezn4z ) { case puirb1divs : break ; case
poj1ujn0qm : break ; case m1cczpmiyp : rtB . l3p1u43lj0 [ rtDWork .
p5wmqc33qy ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; case mollve35d0 : rtB .
l3p1u43lj0 [ rtDWork . p5wmqc33qy ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; case
hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . p5wmqc33qy ] = rtX . ix1fmrtgm0 [
10 ] ; break ; case gyxihahkca : rtB . l3p1u43lj0 [ rtDWork . p5wmqc33qy ] =
rtX . ix1fmrtgm0 [ 10 ] ; break ; case abokkwsuss : break ; case nwxu2zxhpjf
: break ; case ey4wkwipnf : rtB . l3p1u43lj0 [ rtDWork . p5wmqc33qy ] = rtX .
ix1fmrtgm0 [ 10 ] ; break ; case kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork .
p5wmqc33qy ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; default : rtB . l3p1u43lj0 [
rtDWork . p5wmqc33qy ] = rtX . ix1fmrtgm0 [ 10 ] ; break ; } switch ( rtDWork
. lfw2ucpenn ) { case puirb1divs : break ; case poj1ujn0qm : break ; case
m1cczpmiyp : rtB . l3p1u43lj0 [ rtDWork . o4qhycsmoh ] = rtX . ix1fmrtgm0 [
15 ] ; break ; case mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . o4qhycsmoh ] =
rtX . ix1fmrtgm0 [ 15 ] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [
rtDWork . o4qhycsmoh ] = rtX . ix1fmrtgm0 [ 15 ] ; break ; case gyxihahkca :
rtB . l3p1u43lj0 [ rtDWork . o4qhycsmoh ] = rtX . ix1fmrtgm0 [ 15 ] ; break ;
case abokkwsuss : break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB .
l3p1u43lj0 [ rtDWork . o4qhycsmoh ] = rtX . ix1fmrtgm0 [ 15 ] ; break ; case
kpgupuy2kp : rtB . l3p1u43lj0 [ rtDWork . o4qhycsmoh ] = rtX . ix1fmrtgm0 [
15 ] ; break ; default : rtB . l3p1u43lj0 [ rtDWork . o4qhycsmoh ] = rtX .
ix1fmrtgm0 [ 15 ] ; break ; } switch ( rtDWork . ho4yv0pef5 ) { case
puirb1divs : break ; case poj1ujn0qm : break ; case m1cczpmiyp : rtB .
l3p1u43lj0 [ rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [ 19 ] ; break ; case
mollve35d0 : rtB . l3p1u43lj0 [ rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [
19 ] ; break ; case hy3r3w5grg : rtB . l3p1u43lj0 [ rtDWork . mf54iquk4a ] =
rtX . ix1fmrtgm0 [ 19 ] ; break ; case gyxihahkca : rtB . l3p1u43lj0 [
rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [ 19 ] ; break ; case abokkwsuss :
break ; case nwxu2zxhpjf : break ; case ey4wkwipnf : rtB . l3p1u43lj0 [
rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [ 19 ] ; break ; case kpgupuy2kp :
rtB . l3p1u43lj0 [ rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [ 19 ] ; break ;
default : rtB . l3p1u43lj0 [ rtDWork . mf54iquk4a ] = rtX . ix1fmrtgm0 [ 19 ]
; break ; } } void MdlInitialize ( void ) { int32_T i ; rtDWork . gt42aq5wqz
= hsx0pdate3 ; rtDWork . lfluclczgd = 0U ; rtDWork . jxt0tifn1m = hsx0pdate3
; rtDWork . lpvn5skrbx = 0U ; rtDWork . gbpi15raxo = pe5ts3cbxi ; rtDWork .
milvjxyyuk = 0U ; rtDWork . gorxzp2tc5 = pe5ts3cbxi ; rtDWork . h1eicbufky =
0U ; rtDWork . pwv1ttrztn = pe5ts3cbxi ; rtDWork . dq53dldqu5 = 0U ; rtDWork
. h0gr1gfnip = pe5ts3cbxi ; rtDWork . aaa3dwwbpb = 0U ; rtDWork . piy1mfyq04
= pe5ts3cbxi ; rtDWork . c20f0hecbl = 0U ; rtDWork . m1coawef1z = pe5ts3cbxi
; rtDWork . j2iwqhng5v = 0U ; rtDWork . kxzqsowcq4 = pe5ts3cbxi ; rtDWork .
ityqbqwxs3 = 0U ; rtDWork . puu0onps1o = pe5ts3cbxi ; rtDWork . hjfnzxphh4 =
0U ; rtDWork . d5gd34izwy = pe5ts3cbxi ; rtDWork . kkmwpgcwey = 0U ; rtDWork
. m4axwklc2n = pe5ts3cbxi ; rtDWork . p1swflzbuh = 0U ; rtDWork . cor0ek34i1
= pe5ts3cbxi ; rtDWork . pqex5itzoo = 0U ; rtDWork . bieuzbl5sa = pe5ts3cbxi
; rtDWork . mk3y1ej5sc = 0U ; rtDWork . l5nch0wfe0 = pe5ts3cbxi ; rtDWork .
f4ecgcwjef = 0U ; rtDWork . e0siqbw4px = pe5ts3cbxi ; rtDWork . gwkbtmpoqm =
0U ; rtDWork . af0eeezn4z = pe5ts3cbxi ; rtDWork . dv1e4s4igc = 0U ; rtDWork
. e2s0vhz32j = pe5ts3cbxi ; rtDWork . a3d24qkbyc = 0U ; rtDWork . lfw2ucpenn
= pe5ts3cbxi ; rtDWork . idrkgh24mh = 0U ; rtDWork . psc01ml3a2 = pe5ts3cbxi
; rtDWork . ee02mqd4oz = 0U ; rtDWork . ho4yv0pef5 = pe5ts3cbxi ; rtDWork .
hwylozrfgv = 0U ; rtDWork . fgm4uvex5n = pe5ts3cbxi ; rtDWork . ek5x23uca5 =
0U ; rtDWork . argt12xgun = pe5ts3cbxi ; rtDWork . cj4jryemsn = 0U ; rtDWork
. bzilocoerc [ 0 ] = 0.0 ; rtDWork . bzilocoerc [ 1 ] = 0.0 ; rtDWork .
bzilocoerc [ 2 ] = 0.0 ; rtDWork . bzilocoerc [ 3 ] = 0.0 ; rtDWork .
e5i3qovgis [ 0 ] = 0.0 ; rtDWork . e5i3qovgis [ 1 ] = 0.0 ; rtDWork .
e5i3qovgis [ 2 ] = 0.0 ; rtDWork . e5i3qovgis [ 3 ] = 0.0 ; rtDWork .
isgvs5svtv [ 0 ] = 0.0 ; rtDWork . isgvs5svtv [ 1 ] = 60.0 ; rtDWork .
isgvs5svtv [ 2 ] = 120.0 ; rtDWork . isgvs5svtv [ 3 ] = 180.0 ; rtDWork .
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
rtDWork . l2jamqzsvo = 0 ; rtDWork . gophpoqjs0 = 0 ; rtDWork . bso50stzuv [
0 ] = - 1 ; rtDWork . bso50stzuv [ 1 ] = - 1 ; rtDWork . bso50stzuv [ 2 ] = -
1 ; rtDWork . bso50stzuv [ 3 ] = - 1 ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; rtDWork
. mhps55ndar = 0.0 ; rtDWork . ppgpg2d5gp = 0.0 ; rtDWork . kiu22l5yga = 1 ;
rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; rtDWork . avfoep3api = 0.0 ; rtDWork .
k3zetjkg2t = 0.0 ; rtDWork . pvpbflzhwc = 0 ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ;
rtDWork . pd5fkmhg4c = 0.0 ; rtDWork . igjejaivpx = 0.0 ; rtX . ix1fmrtgm0 [
4 ] = 0.0 ; rtDWork . eli0bu1nqi = 0 ; rtDWork . ne5tcs23kl = 0.0 ; rtX .
ix1fmrtgm0 [ 5 ] = 0.0 ; rtX . ix1fmrtgm0 [ 6 ] = 0.0 ; rtX . ix1fmrtgm0 [ 7
] = 0.0 ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; rtDWork . bkhrmaqhhj = 0.0 ; rtDWork
. fsek2utpw2 = 0.0 ; rtX . ix1fmrtgm0 [ 9 ] = 0.0 ; rtDWork . p5wmqc33qy = 0
; rtX . ix1fmrtgm0 [ 10 ] = 0.0 ; rtDWork . nuqllrp43p = 0.0 ; rtX .
ix1fmrtgm0 [ 11 ] = 0.0 ; rtDWork . n5wof223jc = 0.0 ; rtDWork . lmgwt2ihoi =
0.0 ; rtDWork . ov1u3dz22b = 3 ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork .
eyeyekatwb = 0.0 ; rtDWork . esraav3jfu = 0.0 ; rtDWork . hodq0clkgt = 2 ;
rtX . ix1fmrtgm0 [ 13 ] = 0.0 ; rtDWork . edvs5rk3fa = 0.0 ; rtDWork .
c1gduapxde = 0.0 ; rtX . ix1fmrtgm0 [ 14 ] = 0.0 ; rtDWork . o4qhycsmoh = 0 ;
rtX . ix1fmrtgm0 [ 15 ] = 0.0 ; rtDWork . bffxdmyjnr = 0.0 ; rtX . ix1fmrtgm0
[ 16 ] = 0.0 ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ; rtDWork . drbwe4rydf = 0.0 ;
rtDWork . fao3lacynd = 0.0 ; rtX . ix1fmrtgm0 [ 18 ] = 0.0 ; rtDWork .
mf54iquk4a = 0 ; rtX . ix1fmrtgm0 [ 19 ] = 0.0 ; rtDWork . acxds11k1q = 0.0 ;
rtX . ix1fmrtgm0 [ 20 ] = 0.0 ; rtX . ix1fmrtgm0 [ 21 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 22 ] = 0.0 ; rtX . ix1fmrtgm0 [ 23 ] = 0.0 ; rtX . ix1fmrtgm0 [
24 ] = 0.0 ; rtX . ix1fmrtgm0 [ 25 ] = 0.0 ; rtX . ix1fmrtgm0 [ 26 ] = 0.0 ;
rtX . ix1fmrtgm0 [ 27 ] = 0.0 ; rtX . ix1fmrtgm0 [ 28 ] = 0.0 ; rtB .
l3p1u43lj0 [ 0 ] = 0.0 ; rtB . l3p1u43lj0 [ 1 ] = 0.0 ; rtB . l3p1u43lj0 [ 2
] = 0.0 ; rtB . l3p1u43lj0 [ 3 ] = 0.0 ; rtB . bdv4orwwct [ 0 ] = 0.0 ; rtB .
bdv4orwwct [ 1 ] = 0.0 ; rtB . bdv4orwwct [ 2 ] = 0.0 ; rtB . bdv4orwwct [ 3
] = 0.0 ; for ( i = 0 ; i < 8 ; i ++ ) { rtDWork . ov5pkqlglu [ i ] = 0.0 ;
rtDWork . jknd2rgprd [ i ] = 0.0 ; rtDWork . a2j0p0cym5 [ i ] = 0.0 ; rtB .
gotfm0hfnu [ i ] = 0.0 ; } } void MdlStart ( void ) { { static int_T
rt_ToWksWidths [ ] = { 4 } ; static int_T rt_ToWksNumDimensions [ ] = { 2 } ;
static int_T rt_ToWksDimensions [ ] = { 4 , 1 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) , ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 , 4 } ;
static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static const char_T * rt_ToWksLabels [ ] = { "" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData , { rt_ToWksLabels } , ( NULL ) ,
( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ;
static const char_T rt_ToWksBlockName [ ] =
"subwaycontrolsystem/To Workspace1" ; rtDWork . fcdtvsyw4o . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "traindoors" , 1
, 0 , 1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDWork .
fcdtvsyw4o . LoggedData == ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T j ; int32_T k ; int32_T i ; boolean_T guard
= FALSE ; real_T fhzmmvyb0z [ 8 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( rtP . TDV_CurrentSetting == 1 ) { rtB . mgreqddwbk = rtP . a_Value ; } else
{ rtB . mgreqddwbk = rtP . b_Value ; } if ( rtP . TDV1_CurrentSetting == 1 )
{ rtB . nojiyg1svu = rtP . a1_Value ; } else { rtB . nojiyg1svu = rtP .
b1_Value ; } if ( rtP . TDV2_CurrentSetting == 1 ) { rtB . h32onzoiii = rtP .
a2_Value ; } else { rtB . h32onzoiii = rtP . b2_Value ; } if ( rtP .
TDV3_CurrentSetting == 1 ) { rtB . cytqvalje5 = rtP . a3_Value ; } else { rtB
. cytqvalje5 = rtP . b3_Value ; } if ( rtP . PSDV_CurrentSetting == 1 ) {
fhzmmvyb0z [ 0 ] = rtP . c_Value ; } else { fhzmmvyb0z [ 0 ] = rtP . d_Value
; } if ( rtP . PSDV1_CurrentSetting == 1 ) { fhzmmvyb0z [ 1 ] = rtP .
c1_Value ; } else { fhzmmvyb0z [ 1 ] = rtP . d1_Value ; } if ( rtP .
PSDV2_CurrentSetting == 1 ) { fhzmmvyb0z [ 2 ] = rtP . c2_Value ; } else {
fhzmmvyb0z [ 2 ] = rtP . d2_Value ; } if ( rtP . PSDV3_CurrentSetting == 1 )
{ fhzmmvyb0z [ 3 ] = rtP . c3_Value ; } else { fhzmmvyb0z [ 3 ] = rtP .
d3_Value ; } if ( rtP . PSDV4_CurrentSetting == 1 ) { fhzmmvyb0z [ 4 ] = rtP
. c4_Value ; } else { fhzmmvyb0z [ 4 ] = rtP . d4_Value ; } if ( rtP .
PSDV5_CurrentSetting == 1 ) { fhzmmvyb0z [ 5 ] = rtP . c5_Value ; } else {
fhzmmvyb0z [ 5 ] = rtP . d5_Value ; } if ( rtP . PSDV6_CurrentSetting == 1 )
{ fhzmmvyb0z [ 6 ] = rtP . c6_Value ; } else { fhzmmvyb0z [ 6 ] = rtP .
d6_Value ; } if ( rtP . PSDV7_CurrentSetting == 1 ) { fhzmmvyb0z [ 7 ] = rtP
. c7_Value ; } else { fhzmmvyb0z [ 7 ] = rtP . d7_Value ; } rtDWork .
gt42aq5wqz = hsx0pdate3 ; memset ( & rtB . e2bcofptlp [ 0 ] , 0 , sizeof (
real_T ) << 3U ) ; j = 1.0 ; k = 1 ; for ( i = 0 ; i < 8 ; i ++ ) { rtB .
e2bcofptlp [ ( ( int32_T ) j + ( ( k - 1 ) << 2 ) ) - 1 ] = fhzmmvyb0z [ i ]
; if ( k == 2 ) { k = 1 ; j ++ ; } else { k = 2 ; } } } rtB . mewmcyb4gt [ 0
] = rtB . mgreqddwbk ; rtB . mewmcyb4gt [ 1 ] = rtB . nojiyg1svu ; rtB .
mewmcyb4gt [ 2 ] = rtB . h32onzoiii ; rtB . mewmcyb4gt [ 3 ] = rtB .
cytqvalje5 ; if ( ssIsMajorTimeStep ( rtS ) != 0 ) { rtDWork . csmhj2mobz =
ssGetTaskTime ( rtS , 0 ) ; rtDWork . jviamtmzv0 = FALSE ; rtDWork .
jxt0tifn1m = hsx0pdate3 ; if ( rtDWork . cj4jryemsn == 0U ) { rtDWork .
cj4jryemsn = 1U ; rtDWork . f4ecgcwjef = 1U ; rtDWork . e0siqbw4px =
fkpeazmlxh ; rtX . ix1fmrtgm0 [ 6 ] = 0.0 ; rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; rtDWork . j04e3heoks [ 0 ] = 0.0 ; rtDWork . aaa3dwwbpb =
1U ; rtDWork . a2j0p0cym5 [ 0 ] = 1.0 ; rtDWork . piy1mfyq04 = fkpeazmlxh ;
rtX . ix1fmrtgm0 [ 24 ] = 0.0 ; rtDWork . jknd2rgprd [ 0 ] = 0.0 ; rtDWork .
lpvn5skrbx = 1U ; rtDWork . avfoep3api = 0.0 ; rtDWork . k3zetjkg2t = 0.0 ;
rtDWork . pvpbflzhwc = 0 ; rtDWork . gbpi15raxo = h05jpwy3hy ; rtX .
ix1fmrtgm0 [ 2 ] = 0.0 ; rtDWork . c20f0hecbl = 1U ; rtDWork . a2j0p0cym5 [ 4
] = 1.0 ; rtDWork . m1coawef1z = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 23 ] = 0.0 ;
rtDWork . jknd2rgprd [ 4 ] = 0.0 ; rtDWork . j2iwqhng5v = 1U ; rtDWork .
a2j0p0cym5 [ 1 ] = 1.0 ; rtDWork . kxzqsowcq4 = fkpeazmlxh ; rtX . ix1fmrtgm0
[ 21 ] = 0.0 ; rtDWork . jknd2rgprd [ 1 ] = 0.0 ; rtDWork . ityqbqwxs3 = 1U ;
rtDWork . a2j0p0cym5 [ 5 ] = 1.0 ; rtDWork . puu0onps1o = fkpeazmlxh ; rtX .
ix1fmrtgm0 [ 22 ] = 0.0 ; rtDWork . jknd2rgprd [ 5 ] = 0.0 ; rtDWork .
hjfnzxphh4 = 1U ; rtDWork . a2j0p0cym5 [ 2 ] = 1.0 ; rtDWork . d5gd34izwy =
fkpeazmlxh ; rtX . ix1fmrtgm0 [ 28 ] = 0.0 ; rtDWork . jknd2rgprd [ 2 ] = 0.0
; rtDWork . kkmwpgcwey = 1U ; rtDWork . a2j0p0cym5 [ 6 ] = 1.0 ; rtDWork .
m4axwklc2n = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 27 ] = 0.0 ; rtDWork .
jknd2rgprd [ 6 ] = 0.0 ; rtDWork . p1swflzbuh = 1U ; rtDWork . a2j0p0cym5 [ 3
] = 1.0 ; rtDWork . cor0ek34i1 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 25 ] = 0.0 ;
for ( i = 0 ; i < 8 ; i ++ ) { rtB . gotfm0hfnu [ i ] = rtX . ix1fmrtgm0 [ 25
] ; } rtDWork . jknd2rgprd [ 3 ] = 0.0 ; rtDWork . pqex5itzoo = 1U ; rtDWork
. a2j0p0cym5 [ 7 ] = 1.0 ; rtDWork . bieuzbl5sa = fkpeazmlxh ; rtX .
ix1fmrtgm0 [ 26 ] = 0.0 ; rtB . gotfm0hfnu [ 7 ] = rtX . ix1fmrtgm0 [ 26 ] ;
rtDWork . jknd2rgprd [ 7 ] = 0.0 ; rtDWork . dv1e4s4igc = 1U ; rtDWork .
e2s0vhz32j = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 7 ] = 0.0 ; rtB . bdv4orwwct [ 1
] = rtX . ix1fmrtgm0 [ 7 ] ; rtDWork . j04e3heoks [ 1 ] = 0.0 ; rtDWork .
idrkgh24mh = 1U ; rtDWork . psc01ml3a2 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 16 ]
= 0.0 ; rtB . bdv4orwwct [ 2 ] = rtX . ix1fmrtgm0 [ 16 ] ; rtDWork .
j04e3heoks [ 2 ] = 0.0 ; rtDWork . hwylozrfgv = 1U ; rtDWork . fgm4uvex5n =
fkpeazmlxh ; rtX . ix1fmrtgm0 [ 20 ] = 0.0 ; rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; rtDWork . j04e3heoks [ 3 ] = 0.0 ; rtDWork . mk3y1ej5sc =
1U ; rtDWork . pd5fkmhg4c = 0.0 ; rtDWork . igjejaivpx = 0.0 ; rtDWork .
ne5tcs23kl = 0.0 ; rtDWork . eli0bu1nqi = 0 ; rtDWork . bzilocoerc [ rtDWork
. eli0bu1nqi ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork . eli0bu1nqi ] = 0.0 ;
rtX . ix1fmrtgm0 [ 4 ] = 0.0 ; rtX . ix1fmrtgm0 [ 5 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 3 ] = 0.0 ; rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] = 1 ;
rtDWork . l5nch0wfe0 = poj1ujn0qm ; rtDWork . ek5x23uca5 = 1U ; rtDWork .
l2jamqzsvo = 0 ; rtDWork . gophpoqjs0 = 0 ; rtDWork . bso50stzuv [ 0 ] = - 1
; rtDWork . bso50stzuv [ 1 ] = - 1 ; rtDWork . bso50stzuv [ 2 ] = - 1 ;
rtDWork . bso50stzuv [ 3 ] = - 1 ; rtDWork . argt12xgun = cx0bb5ahz2 ; rtX .
ix1fmrtgm0 [ 0 ] = 0.0 ; rtDWork . gwkbtmpoqm = 1U ; rtDWork . bkhrmaqhhj =
0.0 ; rtDWork . fsek2utpw2 = 0.0 ; rtDWork . nuqllrp43p = 0.0 ; rtDWork .
p5wmqc33qy = 1 ; rtDWork . bzilocoerc [ rtDWork . p5wmqc33qy ] = 0.0 ;
rtDWork . e5i3qovgis [ rtDWork . p5wmqc33qy ] = 0.0 ; rtX . ix1fmrtgm0 [ 9 ]
= 0.0 ; rtX . ix1fmrtgm0 [ 10 ] = 0.0 ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ;
rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] = 1 ; rtDWork . af0eeezn4z =
poj1ujn0qm ; rtDWork . a3d24qkbyc = 1U ; rtDWork . edvs5rk3fa = 0.0 ; rtDWork
. c1gduapxde = 0.0 ; rtDWork . bffxdmyjnr = 0.0 ; rtDWork . o4qhycsmoh = 2 ;
rtDWork . bzilocoerc [ rtDWork . o4qhycsmoh ] = 0.0 ; rtDWork . e5i3qovgis [
rtDWork . o4qhycsmoh ] = 0.0 ; rtX . ix1fmrtgm0 [ 14 ] = 0.0 ; rtX .
ix1fmrtgm0 [ 15 ] = 0.0 ; rtX . ix1fmrtgm0 [ 13 ] = 0.0 ; rtDWork .
op2f2jmd1g [ rtDWork . o4qhycsmoh ] = 1 ; rtDWork . lfw2ucpenn = poj1ujn0qm ;
rtDWork . ee02mqd4oz = 1U ; rtDWork . drbwe4rydf = 0.0 ; rtDWork . fao3lacynd
= 0.0 ; rtDWork . acxds11k1q = 0.0 ; rtDWork . mf54iquk4a = 3 ; rtDWork .
bzilocoerc [ rtDWork . mf54iquk4a ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
mf54iquk4a ] = 0.0 ; rtX . ix1fmrtgm0 [ 18 ] = 0.0 ; rtX . ix1fmrtgm0 [ 19 ]
= 0.0 ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ; rtDWork . op2f2jmd1g [ rtDWork .
mf54iquk4a ] = 1 ; rtDWork . ho4yv0pef5 = poj1ujn0qm ; rtDWork . milvjxyyuk =
1U ; rtDWork . mhps55ndar = 0.0 ; rtDWork . ppgpg2d5gp = 0.0 ; rtDWork .
kiu22l5yga = 1 ; rtDWork . gorxzp2tc5 = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1 ] =
0.0 ; rtDWork . h1eicbufky = 1U ; rtDWork . eyeyekatwb = 0.0 ; rtDWork .
esraav3jfu = 0.0 ; rtDWork . hodq0clkgt = 2 ; rtDWork . pwv1ttrztn =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork . dq53dldqu5 = 1U ;
rtDWork . n5wof223jc = 0.0 ; rtDWork . lmgwt2ihoi = 0.0 ; rtDWork .
ov1u3dz22b = 3 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } else { switch ( rtDWork .
e0siqbw4px ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 0 ] == 1.0 ) {
rtDWork . omfdvdtquy [ 0 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
e0siqbw4px = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
j04e3heoks [ 0 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
e0siqbw4px = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
6 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . e0siqbw4px =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 6 ] = 2.0 ; rtB . bdv4orwwct [ 0 ] = rtX .
ix1fmrtgm0 [ 6 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 6 ] > 0.0 )
&& ( rtB . mewmcyb4gt [ 0 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . e0siqbw4px = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 6 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . e0siqbw4px = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 6 ] = 0.0 ; rtB . bdv4orwwct [ 0 ] = rtX . ix1fmrtgm0 [ 6 ] ;
rtDWork . j04e3heoks [ 0 ] = 0.0 ; } } break ; } switch ( rtDWork .
piy1mfyq04 ) { case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 0 ] == 1.0 ) {
rtDWork . a2j0p0cym5 [ 0 ] = 0.0 ; rtDWork . ov5pkqlglu [ 0 ] = 0.0 ; rtDWork
. jviamtmzv0 = TRUE ; rtDWork . piy1mfyq04 = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 0 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . piy1mfyq04 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 24 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
piy1mfyq04 = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 24 ] = 2.0 ; rtB . gotfm0hfnu [
0 ] = rtX . ix1fmrtgm0 [ 24 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
24 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 0 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . piy1mfyq04 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 24 ] = 0.0 ;
rtB . gotfm0hfnu [ 0 ] = rtX . ix1fmrtgm0 [ 24 ] ; rtDWork . jknd2rgprd [ 0 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 24 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 0 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . piy1mfyq04 =
pvvniy1wrq ; } } break ; } switch ( rtDWork . gbpi15raxo ) { case mce1hmjau3
: if ( rtX . ix1fmrtgm0 [ 2 ] >= 5.0 ) { rtDWork . j04e3heoks [ rtDWork .
pvpbflzhwc ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo =
bozn0j4h3r ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } break ; case bozn0j4h3r : if (
( rtDWork . e0siqbw4px == fkpeazmlxh ) == 0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . gbpi15raxo = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } else {
if ( rtX . ix1fmrtgm0 [ 2 ] >= 5.0 ) { rtDWork . jknd2rgprd [ ( int32_T )
rtDWork . avfoep3api + ( ( int32_T ) rtDWork . k3zetjkg2t << 2 ) ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = hjcg5jty2z ; rtX .
ix1fmrtgm0 [ 2 ] = 0.0 ; } } break ; case bpsmzkxnnb : if ( rtX . ix1fmrtgm0
[ 2 ] >= 1.0 ) { rtDWork . omfdvdtquy [ rtDWork . pvpbflzhwc ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = g5thp4xumb ; rtX .
ix1fmrtgm0 [ 2 ] = 0.0 ; } break ; case jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [
2 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ ( int32_T ) rtDWork . avfoep3api + ( (
int32_T ) rtDWork . k3zetjkg2t << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . gbpi15raxo = bpsmzkxnnb ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } break ;
case h05jpwy3hy : if ( rtDWork . e5i3qovgis [ rtDWork . pvpbflzhwc ] == 1.0 )
{ rtDWork . pvpbflzhwc = 0 ; rtDWork . avfoep3api = rtDWork . pd5fkmhg4c ; k
= rtDWork . op2f2jmd1g [ rtDWork . pvpbflzhwc ] + 1 ; rtDWork . k3zetjkg2t =
( real_T ) ( ( ( k < 0 ) + k ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork
. gbpi15raxo = jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; rtDWork .
e5i3qovgis [ rtDWork . pvpbflzhwc ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0
[ 2 ] >= 1.0 ) && ( rtDWork . e5i3qovgis [ rtDWork . pvpbflzhwc ] != 1.0 ) )
{ rtDWork . guc4ezu4vd [ rtDWork . pvpbflzhwc ] = rtX . ix1fmrtgm0 [ 5 ] ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo = h05jpwy3hy ; rtX .
ix1fmrtgm0 [ 2 ] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0
[ 2 ] >= 10.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . gbpi15raxo =
czs3vnbrbl ; } break ; case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 2 ] >=
20.0 ) && ( rtX . ix1fmrtgm0 [ 2 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . gbpi15raxo = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } break
; default : if ( rtX . ix1fmrtgm0 [ 2 ] >= 5.0 ) { rtDWork . bzilocoerc [
rtDWork . pvpbflzhwc ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } else { if (
rtDWork . a2j0p0cym5 [ ( ( int32_T ) rtDWork . k3zetjkg2t << 2 ) + ( int32_T
) rtDWork . avfoep3api ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gbpi15raxo = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 2 ] = 0.0 ; } } break ; } switch
( rtDWork . m1coawef1z ) { case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 4 ]
== 1.0 ) { rtDWork . a2j0p0cym5 [ 4 ] = 0.0 ; rtDWork . ov5pkqlglu [ 4 ] =
0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . m1coawef1z = pvvniy1wrq ; }
break ; case nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 4 ] == 1.0 ) { rtDWork
. jviamtmzv0 = TRUE ; rtDWork . m1coawef1z = ab4gsgwqfm ; } break ; case
pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 23 ] >= 2.0 ) { rtDWork . jviamtmzv0 =
TRUE ; rtDWork . m1coawef1z = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 23 ] = 2.0 ;
rtB . gotfm0hfnu [ 4 ] = rtX . ix1fmrtgm0 [ 23 ] ; } break ; default : if (
rtX . ix1fmrtgm0 [ 23 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 4 ] = 1.0 ; rtDWork
. jviamtmzv0 = TRUE ; rtDWork . m1coawef1z = fkpeazmlxh ; rtX . ix1fmrtgm0 [
23 ] = 0.0 ; rtB . gotfm0hfnu [ 4 ] = rtX . ix1fmrtgm0 [ 23 ] ; rtDWork .
jknd2rgprd [ 4 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 23 ] > 0.0 ) && (
rtB . e2bcofptlp [ 4 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
m1coawef1z = pvvniy1wrq ; } } break ; } switch ( rtDWork . kxzqsowcq4 ) {
case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 1 ] == 1.0 ) { rtDWork .
a2j0p0cym5 [ 1 ] = 0.0 ; rtDWork . ov5pkqlglu [ 1 ] = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . kxzqsowcq4 = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 1 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . kxzqsowcq4 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 21 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
kxzqsowcq4 = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 21 ] = 2.0 ; rtB . gotfm0hfnu [
1 ] = rtX . ix1fmrtgm0 [ 21 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
21 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 1 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . kxzqsowcq4 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 21 ] = 0.0 ;
rtB . gotfm0hfnu [ 1 ] = rtX . ix1fmrtgm0 [ 21 ] ; rtDWork . jknd2rgprd [ 1 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 21 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 1 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . kxzqsowcq4 =
pvvniy1wrq ; } } break ; } switch ( rtDWork . puu0onps1o ) { case fkpeazmlxh
: if ( rtDWork . ov5pkqlglu [ 5 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 5 ] = 0.0
; rtDWork . ov5pkqlglu [ 5 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
puu0onps1o = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
jknd2rgprd [ 5 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
puu0onps1o = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
22 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . puu0onps1o =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 22 ] = 2.0 ; rtB . gotfm0hfnu [ 5 ] = rtX .
ix1fmrtgm0 [ 22 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [ 22 ] <= 0.0 )
{ rtDWork . a2j0p0cym5 [ 5 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
puu0onps1o = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 22 ] = 0.0 ; rtB . gotfm0hfnu [
5 ] = rtX . ix1fmrtgm0 [ 22 ] ; rtDWork . jknd2rgprd [ 5 ] = 0.0 ; } else {
if ( ( rtX . ix1fmrtgm0 [ 22 ] > 0.0 ) && ( rtB . e2bcofptlp [ 5 ] == 0.0 ) )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . puu0onps1o = pvvniy1wrq ; } } break
; } switch ( rtDWork . d5gd34izwy ) { case fkpeazmlxh : if ( rtDWork .
ov5pkqlglu [ 2 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 2 ] = 0.0 ; rtDWork .
ov5pkqlglu [ 2 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . d5gd34izwy =
pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 2 ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . d5gd34izwy = ab4gsgwqfm ; }
break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 28 ] >= 2.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . d5gd34izwy = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 28
] = 2.0 ; rtB . gotfm0hfnu [ 2 ] = rtX . ix1fmrtgm0 [ 28 ] ; } break ;
default : if ( rtX . ix1fmrtgm0 [ 28 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 2 ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . d5gd34izwy = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 28 ] = 0.0 ; rtB . gotfm0hfnu [ 2 ] = rtX . ix1fmrtgm0 [ 28 ]
; rtDWork . jknd2rgprd [ 2 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 28 ]
> 0.0 ) && ( rtB . e2bcofptlp [ 2 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . d5gd34izwy = pvvniy1wrq ; } } break ; } switch ( rtDWork .
m4axwklc2n ) { case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 6 ] == 1.0 ) {
rtDWork . a2j0p0cym5 [ 6 ] = 0.0 ; rtDWork . ov5pkqlglu [ 6 ] = 0.0 ; rtDWork
. jviamtmzv0 = TRUE ; rtDWork . m4axwklc2n = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 6 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . m4axwklc2n = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 27 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
m4axwklc2n = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 27 ] = 2.0 ; rtB . gotfm0hfnu [
6 ] = rtX . ix1fmrtgm0 [ 27 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
27 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 6 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . m4axwklc2n = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 27 ] = 0.0 ;
rtB . gotfm0hfnu [ 6 ] = rtX . ix1fmrtgm0 [ 27 ] ; rtDWork . jknd2rgprd [ 6 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 27 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 6 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . m4axwklc2n =
pvvniy1wrq ; } } break ; } switch ( rtDWork . cor0ek34i1 ) { case fkpeazmlxh
: if ( rtDWork . ov5pkqlglu [ 3 ] == 1.0 ) { rtDWork . a2j0p0cym5 [ 3 ] = 0.0
; rtDWork . ov5pkqlglu [ 3 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
cor0ek34i1 = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
jknd2rgprd [ 3 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
cor0ek34i1 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
25 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . cor0ek34i1 =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 25 ] = 2.0 ; rtB . gotfm0hfnu [ 3 ] = rtX .
ix1fmrtgm0 [ 25 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [ 25 ] <= 0.0 )
{ rtDWork . a2j0p0cym5 [ 3 ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
cor0ek34i1 = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 25 ] = 0.0 ; for ( i = 0 ; i < 8
; i ++ ) { rtB . gotfm0hfnu [ i ] = rtX . ix1fmrtgm0 [ 25 ] ; } rtDWork .
jknd2rgprd [ 3 ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 25 ] > 0.0 ) && (
rtB . e2bcofptlp [ 3 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
cor0ek34i1 = pvvniy1wrq ; } } break ; } switch ( rtDWork . bieuzbl5sa ) {
case fkpeazmlxh : if ( rtDWork . ov5pkqlglu [ 7 ] == 1.0 ) { rtDWork .
a2j0p0cym5 [ 7 ] = 0.0 ; rtDWork . ov5pkqlglu [ 7 ] = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . bieuzbl5sa = pvvniy1wrq ; } break ; case
nsgxdn54fe : if ( rtDWork . jknd2rgprd [ 7 ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . bieuzbl5sa = ab4gsgwqfm ; } break ; case pvvniy1wrq : if (
rtX . ix1fmrtgm0 [ 26 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
bieuzbl5sa = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 26 ] = 2.0 ; rtB . gotfm0hfnu [
7 ] = rtX . ix1fmrtgm0 [ 26 ] ; } break ; default : if ( rtX . ix1fmrtgm0 [
26 ] <= 0.0 ) { rtDWork . a2j0p0cym5 [ 7 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . bieuzbl5sa = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 26 ] = 0.0 ;
rtB . gotfm0hfnu [ 7 ] = rtX . ix1fmrtgm0 [ 26 ] ; rtDWork . jknd2rgprd [ 7 ]
= 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 26 ] > 0.0 ) && ( rtB . e2bcofptlp
[ 7 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . bieuzbl5sa =
pvvniy1wrq ; } } break ; } switch ( rtDWork . e2s0vhz32j ) { case fkpeazmlxh
: if ( rtDWork . omfdvdtquy [ 1 ] == 1.0 ) { rtDWork . omfdvdtquy [ 1 ] = 0.0
; rtDWork . jviamtmzv0 = TRUE ; rtDWork . e2s0vhz32j = pvvniy1wrq ; } break ;
case nsgxdn54fe : if ( rtDWork . j04e3heoks [ 1 ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . e2s0vhz32j = ab4gsgwqfm ; } break ; case
pvvniy1wrq : if ( rtX . ix1fmrtgm0 [ 7 ] >= 2.0 ) { rtDWork . jviamtmzv0 =
TRUE ; rtDWork . e2s0vhz32j = nsgxdn54fe ; rtX . ix1fmrtgm0 [ 7 ] = 2.0 ; rtB
. bdv4orwwct [ 1 ] = rtX . ix1fmrtgm0 [ 7 ] ; } break ; default : if ( ( rtX
. ix1fmrtgm0 [ 7 ] > 0.0 ) && ( rtB . mewmcyb4gt [ 1 ] == 0.0 ) ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . e2s0vhz32j = pvvniy1wrq ; } else { if ( rtX .
ix1fmrtgm0 [ 7 ] <= 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
e2s0vhz32j = fkpeazmlxh ; rtX . ix1fmrtgm0 [ 7 ] = 0.0 ; rtB . bdv4orwwct [ 1
] = rtX . ix1fmrtgm0 [ 7 ] ; rtDWork . j04e3heoks [ 1 ] = 0.0 ; } } break ; }
switch ( rtDWork . psc01ml3a2 ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy
[ 2 ] == 1.0 ) { rtDWork . omfdvdtquy [ 2 ] = 0.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . psc01ml3a2 = pvvniy1wrq ; } break ; case nsgxdn54fe : if (
rtDWork . j04e3heoks [ 2 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
psc01ml3a2 = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
16 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . psc01ml3a2 =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 16 ] = 2.0 ; rtB . bdv4orwwct [ 2 ] = rtX .
ix1fmrtgm0 [ 16 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 16 ] > 0.0
) && ( rtB . mewmcyb4gt [ 2 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . psc01ml3a2 = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 16 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . psc01ml3a2 = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 16 ] = 0.0 ; rtB . bdv4orwwct [ 2 ] = rtX . ix1fmrtgm0 [ 16 ]
; rtDWork . j04e3heoks [ 2 ] = 0.0 ; } } break ; } switch ( rtDWork .
fgm4uvex5n ) { case fkpeazmlxh : if ( rtDWork . omfdvdtquy [ 3 ] == 1.0 ) {
rtDWork . omfdvdtquy [ 3 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
fgm4uvex5n = pvvniy1wrq ; } break ; case nsgxdn54fe : if ( rtDWork .
j04e3heoks [ 3 ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
fgm4uvex5n = ab4gsgwqfm ; } break ; case pvvniy1wrq : if ( rtX . ix1fmrtgm0 [
20 ] >= 2.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . fgm4uvex5n =
nsgxdn54fe ; rtX . ix1fmrtgm0 [ 20 ] = 2.0 ; rtB . bdv4orwwct [ 3 ] = rtX .
ix1fmrtgm0 [ 20 ] ; } break ; default : if ( ( rtX . ix1fmrtgm0 [ 20 ] > 0.0
) && ( rtB . mewmcyb4gt [ 3 ] == 0.0 ) ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . fgm4uvex5n = pvvniy1wrq ; } else { if ( rtX . ix1fmrtgm0 [ 20 ] <=
0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . fgm4uvex5n = fkpeazmlxh ; rtX
. ix1fmrtgm0 [ 20 ] = 0.0 ; rtB . bdv4orwwct [ 3 ] = rtX . ix1fmrtgm0 [ 20 ]
; rtDWork . j04e3heoks [ 3 ] = 0.0 ; } } break ; } switch ( rtDWork .
l5nch0wfe0 ) { case puirb1divs : if ( rtX . ix1fmrtgm0 [ 4 ] >= 30.0 ) {
rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] = - rtDWork . op2f2jmd1g [
rtDWork . eli0bu1nqi ] ; rtDWork . e5i3qovgis [ rtDWork . eli0bu1nqi ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . eli0bu1nqi ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . l5nch0wfe0 = abokkwsuss ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; }
break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [ 4 ] >= rtDWork . isgvs5svtv
[ rtDWork . eli0bu1nqi ] ) { rtDWork . e5i3qovgis [ rtDWork . eli0bu1nqi ] =
1.0 ; rtDWork . pd5fkmhg4c = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
l5nch0wfe0 = abokkwsuss ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; } break ; case
m1cczpmiyp : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 5 ] - rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . pd5fkmhg4c ] ) <= 1.0 ) { rtDWork .
e5i3qovgis [ rtDWork . eli0bu1nqi ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork .
eli0bu1nqi ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 =
abokkwsuss ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; } else { if ( rtDWork .
ms2wqypsep [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . l5nch0wfe0 = ey4wkwipnf ; } } break ; case mollve35d0 : if (
rtDWork . ms2wqypsep [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . l5nch0wfe0 = ey4wkwipnf ; } else { if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 5 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
pd5fkmhg4c ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . eli0bu1nqi ] = 1.0
; rtDWork . e5i3qovgis [ rtDWork . eli0bu1nqi ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . l5nch0wfe0 = abokkwsuss ; rtX . ix1fmrtgm0 [ 3 ] = 0.0 ; }
} break ; case hy3r3w5grg : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 5 ] -
rtDWork . duzuwa454g [ ( int32_T ) rtDWork . pd5fkmhg4c ] ) <= 500.0 ) {
rtDWork . ne5tcs23kl = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 3 ] , 2.0 )
* 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = m1cczpmiyp ; }
else if ( rtX . ix1fmrtgm0 [ 3 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . l5nch0wfe0 = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [
rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
l5nch0wfe0 = ey4wkwipnf ; } } break ; case gyxihahkca : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 5 ] - rtDWork . duzuwa454g [ ( int32_T
) rtDWork . pd5fkmhg4c ] ) <= 500.0 ) { rtDWork . ne5tcs23kl = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 3 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = m1cczpmiyp ; } else { if ( rtDWork
. ms2wqypsep [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . l5nch0wfe0 = ey4wkwipnf ; } } break ; case abokkwsuss : if (
rtDWork . bzilocoerc [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork . e5i3qovgis
[ rtDWork . eli0bu1nqi ] = 0.0 ; rtX . ix1fmrtgm0 [ 4 ] = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = nwxu2zxhpjf ; } break ; case
nwxu2zxhpjf : if ( ( rtDWork . pd5fkmhg4c == 0.0 ) && ( rtDWork . op2f2jmd1g
[ rtDWork . eli0bu1nqi ] == - 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
l5nch0wfe0 = puirb1divs ; } else if ( ( ( real_T ) ( rtDWork . mgytiqynw0 - 1
) == rtDWork . pd5fkmhg4c ) && ( rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi
] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = puirb1divs
; } else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] == 1 ) && (
rtDWork . pd5fkmhg4c < ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ) ) || ( (
rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] == - 1 ) && ( rtDWork .
pd5fkmhg4c > 0.0 ) ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 =
hy3r3w5grg ; rtDWork . pd5fkmhg4c += ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . eli0bu1nqi ] ; } } break ; case ey4wkwipnf : if ( rtX . ix1fmrtgm0
[ 3 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ rtDWork . eli0bu1nqi ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = bg2pxs4yrg ; } break ;
case kpgupuy2kp : if ( rtX . ix1fmrtgm0 [ 3 ] >= rtDWork . igjejaivpx ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = mollve35d0 ; } else { if
( rtDWork . ms2wqypsep [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = ey4wkwipnf ; } } break ; default :
if ( rtDWork . kd0unb3ts3 [ rtDWork . eli0bu1nqi ] == 1.0 ) { rtDWork .
igjejaivpx = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtDWork . duzuwa454g [
( int32_T ) rtDWork . pd5fkmhg4c ] - rtX . ix1fmrtgm0 [ 5 ] ) * 0.5 ) ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . l5nch0wfe0 = kpgupuy2kp ; rtDWork .
kd0unb3ts3 [ rtDWork . eli0bu1nqi ] = 0.0 ; } break ; } switch ( rtDWork .
argt12xgun ) { case atiyvzgfnq : if ( ( rtDWork . gophpoqjs0 != rtDWork .
mgytiqynw0 ) && ( rtDWork . l2jamqzsvo == rtDWork . gophpoqjs0 ) && ( rtX .
ix1fmrtgm0 [ 0 ] >= 1.0 ) ) { rtDWork . gophpoqjs0 ++ ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . argt12xgun = atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; }
else if ( ( rtDWork . gophpoqjs0 == rtDWork . mgytiqynw0 ) && ( rtX .
ix1fmrtgm0 [ 0 ] >= 1.0 ) ) { rtDWork . gophpoqjs0 = 0 ; rtDWork . l2jamqzsvo
++ ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . argt12xgun = atiyvzgfnq ; rtX .
ix1fmrtgm0 [ 0 ] = 0.0 ; } else if ( ( rtDWork . l2jamqzsvo != rtDWork .
mgytiqynw0 ) && ( rtDWork . gophpoqjs0 != rtDWork . mgytiqynw0 ) && ( rtDWork
. l2jamqzsvo != rtDWork . gophpoqjs0 ) && ( rtX . ix1fmrtgm0 [ 0 ] >= 1.0 ) )
{ if ( rtDWork . op2f2jmd1g [ rtDWork . l2jamqzsvo ] != rtDWork . op2f2jmd1g
[ rtDWork . gophpoqjs0 ] ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
argt12xgun = nwxu2zxhpj ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; } else if ( rtDWork
. op2f2jmd1g [ rtDWork . l2jamqzsvo ] == rtDWork . op2f2jmd1g [ rtDWork .
gophpoqjs0 ] ) { if ( muDoubleScalarAbs ( rtDWork . guc4ezu4vd [ rtDWork .
gophpoqjs0 ] - rtDWork . guc4ezu4vd [ rtDWork . l2jamqzsvo ] ) > 300.0 ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . argt12xgun = nwxu2zxhpj ; rtX .
ix1fmrtgm0 [ 0 ] = 0.0 ; } else if ( muDoubleScalarAbs ( rtDWork . guc4ezu4vd
[ rtDWork . gophpoqjs0 ] - rtDWork . guc4ezu4vd [ rtDWork . l2jamqzsvo ] ) <=
300.0 ) { if ( rtDWork . op2f2jmd1g [ ( int32_T ) ( ( real_T ) rtDWork .
l2jamqzsvo + 1.0 ) - 1 ] == 1 ) { if ( rtDWork . guc4ezu4vd [ ( int32_T ) ( (
real_T ) rtDWork . gophpoqjs0 + 1.0 ) - 1 ] > rtDWork . guc4ezu4vd [ (
int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] ) { k = rtDWork .
l2jamqzsvo ; j = muDoubleScalarRound ( ( real_T ) rtDWork . gophpoqjs0 + 1.0
) ; if ( j < 2.147483648E+9 ) { rtDWork . bso50stzuv [ ( int32_T ) ( ( real_T
) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] = ( int32_T ) j ; } else { rtDWork .
bso50stzuv [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] =
MAX_int32_T ; } } else { k = rtDWork . gophpoqjs0 ; j = muDoubleScalarRound (
( real_T ) rtDWork . l2jamqzsvo + 1.0 ) ; if ( j < 2.147483648E+9 ) { rtDWork
. bso50stzuv [ ( int32_T ) ( ( real_T ) rtDWork . gophpoqjs0 + 1.0 ) - 1 ] =
( int32_T ) j ; } else { rtDWork . bso50stzuv [ ( int32_T ) ( ( real_T )
rtDWork . gophpoqjs0 + 1.0 ) - 1 ] = MAX_int32_T ; } } } else if ( rtDWork .
guc4ezu4vd [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] >
rtDWork . guc4ezu4vd [ ( int32_T ) ( ( real_T ) rtDWork . gophpoqjs0 + 1.0 )
- 1 ] ) { k = rtDWork . l2jamqzsvo ; j = muDoubleScalarRound ( ( real_T )
rtDWork . gophpoqjs0 + 1.0 ) ; if ( j < 2.147483648E+9 ) { rtDWork .
bso50stzuv [ ( int32_T ) ( ( real_T ) rtDWork . l2jamqzsvo + 1.0 ) - 1 ] = (
int32_T ) j ; } else { rtDWork . bso50stzuv [ ( int32_T ) ( ( real_T )
rtDWork . l2jamqzsvo + 1.0 ) - 1 ] = MAX_int32_T ; } } else { k = rtDWork .
gophpoqjs0 ; j = muDoubleScalarRound ( ( real_T ) rtDWork . l2jamqzsvo + 1.0
) ; if ( j < 2.147483648E+9 ) { rtDWork . bso50stzuv [ ( int32_T ) ( ( real_T
) rtDWork . gophpoqjs0 + 1.0 ) - 1 ] = ( int32_T ) j ; } else { rtDWork .
bso50stzuv [ ( int32_T ) ( ( real_T ) rtDWork . gophpoqjs0 + 1.0 ) - 1 ] =
MAX_int32_T ; } } rtDWork . ms2wqypsep [ ( int32_T ) ( ( real_T ) k + 1.0 ) -
1 ] = 1.0 ; rtDWork . ms2wqypsep [ ( int32_T ) ( ( real_T ) k + 1.0 ) - 1 ] =
0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . argt12xgun = nwxu2zxhpj ; rtX .
ix1fmrtgm0 [ 0 ] = 0.0 ; } else { guard = TRUE ; } } else { guard = TRUE ; }
} else { guard = TRUE ; } break ; case cx0bb5ahz2 : if ( rtX . ix1fmrtgm0 [ 0
] >= 3.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . argt12xgun = atiyvzgfnq
; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; } break ; default : if ( rtX . ix1fmrtgm0 [
0 ] >= 1.0 ) { if ( ( rtDWork . bso50stzuv [ 0 ] != - 1 ) && ( rtDWork .
bdoe3sih52 [ 0 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 0 ] = 0.0 ; if ( (
kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . bso50stzuv [ 0 ] - 1 ] -
rtDWork . guc4ezu4vd [ 0 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork .
bso50stzuv [ 0 ] - 1 ] != rtDWork . op2f2jmd1g [ 0 ] ) ) { rtDWork .
kd0unb3ts3 [ 0 ] = 1.0 ; } } if ( ( rtDWork . bso50stzuv [ 1 ] != - 1 ) && (
rtDWork . bdoe3sih52 [ 1 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 1 ] = 0.0 ; if
( ( kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . bso50stzuv [ 1 ] - 1 ] -
rtDWork . guc4ezu4vd [ 1 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork .
bso50stzuv [ 1 ] - 1 ] != rtDWork . op2f2jmd1g [ 1 ] ) ) { rtDWork .
kd0unb3ts3 [ 1 ] = 1.0 ; } } if ( ( rtDWork . bso50stzuv [ 2 ] != - 1 ) && (
rtDWork . bdoe3sih52 [ 2 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 2 ] = 0.0 ; if
( ( kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . bso50stzuv [ 2 ] - 1 ] -
rtDWork . guc4ezu4vd [ 2 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork .
bso50stzuv [ 2 ] - 1 ] != rtDWork . op2f2jmd1g [ 2 ] ) ) { rtDWork .
kd0unb3ts3 [ 2 ] = 1.0 ; } } if ( ( rtDWork . bso50stzuv [ 3 ] != - 1 ) && (
rtDWork . bdoe3sih52 [ 3 ] == 1.0 ) ) { rtDWork . ms2wqypsep [ 3 ] = 0.0 ; if
( ( kwtjth4lfb ( rtDWork . guc4ezu4vd [ rtDWork . bso50stzuv [ 3 ] - 1 ] -
rtDWork . guc4ezu4vd [ 3 ] ) > 300.0 ) || ( rtDWork . op2f2jmd1g [ rtDWork .
bso50stzuv [ 3 ] - 1 ] != rtDWork . op2f2jmd1g [ 3 ] ) ) { rtDWork .
kd0unb3ts3 [ 3 ] = 1.0 ; } } rtDWork . gophpoqjs0 ++ ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . argt12xgun = atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; }
break ; } if ( guard && ( ( rtDWork . l2jamqzsvo == rtDWork . mgytiqynw0 ) &&
( rtX . ix1fmrtgm0 [ 0 ] >= 1.0 ) ) ) { rtDWork . l2jamqzsvo = 0 ; rtDWork .
gophpoqjs0 = 0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . argt12xgun =
atiyvzgfnq ; rtX . ix1fmrtgm0 [ 0 ] = 0.0 ; } switch ( rtDWork . af0eeezn4z )
{ case puirb1divs : if ( rtX . ix1fmrtgm0 [ 9 ] >= 30.0 ) { rtDWork .
op2f2jmd1g [ rtDWork . p5wmqc33qy ] = - rtDWork . op2f2jmd1g [ rtDWork .
p5wmqc33qy ] ; rtDWork . e5i3qovgis [ rtDWork . p5wmqc33qy ] = 1.0 ; rtDWork
. bzilocoerc [ rtDWork . p5wmqc33qy ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . af0eeezn4z = abokkwsuss ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; } break ;
case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [ 9 ] >= rtDWork . isgvs5svtv [
rtDWork . p5wmqc33qy ] ) { rtDWork . e5i3qovgis [ rtDWork . p5wmqc33qy ] =
1.0 ; rtDWork . bkhrmaqhhj = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
af0eeezn4z = abokkwsuss ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; } break ; case
m1cczpmiyp : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 10 ] - rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . bkhrmaqhhj ] ) <= 1.0 ) { rtDWork .
e5i3qovgis [ rtDWork . p5wmqc33qy ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork .
p5wmqc33qy ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z =
abokkwsuss ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; } else { if ( rtDWork .
ms2wqypsep [ rtDWork . p5wmqc33qy ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . af0eeezn4z = ey4wkwipnf ; } } break ; case mollve35d0 : if (
rtDWork . ms2wqypsep [ rtDWork . p5wmqc33qy ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . af0eeezn4z = ey4wkwipnf ; } else { if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 10 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
bkhrmaqhhj ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . p5wmqc33qy ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . p5wmqc33qy ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . af0eeezn4z = abokkwsuss ; rtX . ix1fmrtgm0 [ 8 ] = 0.0 ; }
} break ; case hy3r3w5grg : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 10 ]
- rtDWork . duzuwa454g [ ( int32_T ) rtDWork . bkhrmaqhhj ] ) <= 500.0 ) {
rtDWork . nuqllrp43p = - muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 8 ] , 2.0 )
* 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = m1cczpmiyp ; }
else if ( rtX . ix1fmrtgm0 [ 8 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ;
rtDWork . af0eeezn4z = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [
rtDWork . p5wmqc33qy ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
af0eeezn4z = ey4wkwipnf ; } } break ; case gyxihahkca : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 10 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . bkhrmaqhhj ] ) <= 500.0 ) { rtDWork . nuqllrp43p = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 8 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = m1cczpmiyp ; } else { if ( rtDWork
. ms2wqypsep [ rtDWork . p5wmqc33qy ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE
; rtDWork . af0eeezn4z = ey4wkwipnf ; } } break ; case abokkwsuss : if (
rtDWork . bzilocoerc [ rtDWork . p5wmqc33qy ] == 1.0 ) { rtDWork . e5i3qovgis
[ rtDWork . p5wmqc33qy ] = 0.0 ; rtX . ix1fmrtgm0 [ 9 ] = 0.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = nwxu2zxhpjf ; } break ; case
nwxu2zxhpjf : if ( ( rtDWork . bkhrmaqhhj == 0.0 ) && ( rtDWork . op2f2jmd1g
[ rtDWork . p5wmqc33qy ] == - 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
af0eeezn4z = puirb1divs ; } else if ( ( ( real_T ) ( rtDWork . mgytiqynw0 - 1
) == rtDWork . bkhrmaqhhj ) && ( rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy
] == 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = puirb1divs
; } else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] == 1 ) && (
rtDWork . bkhrmaqhhj < ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ) ) || ( (
rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] == - 1 ) && ( rtDWork .
bkhrmaqhhj > 0.0 ) ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z =
hy3r3w5grg ; rtDWork . bkhrmaqhhj += ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . p5wmqc33qy ] ; } } break ; case ey4wkwipnf : if ( rtX . ix1fmrtgm0
[ 8 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ rtDWork . p5wmqc33qy ] = 1.0 ; rtX .
ix1fmrtgm0 [ 8 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z =
bg2pxs4yrg ; } break ; case kpgupuy2kp : if ( rtX . ix1fmrtgm0 [ 8 ] >=
rtDWork . fsek2utpw2 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z =
mollve35d0 ; } else { if ( rtDWork . ms2wqypsep [ rtDWork . p5wmqc33qy ] ==
1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = ey4wkwipnf ; } }
break ; default : if ( rtDWork . kd0unb3ts3 [ rtDWork . p5wmqc33qy ] == 1.0 )
{ rtDWork . fsek2utpw2 = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . bkhrmaqhhj ] - rtX . ix1fmrtgm0 [ 10 ] ) *
0.5 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . af0eeezn4z = kpgupuy2kp ;
rtDWork . kd0unb3ts3 [ rtDWork . p5wmqc33qy ] = 0.0 ; } break ; } switch (
rtDWork . lfw2ucpenn ) { case puirb1divs : if ( rtX . ix1fmrtgm0 [ 14 ] >=
30.0 ) { rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] = - rtDWork .
op2f2jmd1g [ rtDWork . o4qhycsmoh ] ; rtDWork . e5i3qovgis [ rtDWork .
o4qhycsmoh ] = 1.0 ; rtDWork . bzilocoerc [ rtDWork . o4qhycsmoh ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = abokkwsuss ; rtX .
ix1fmrtgm0 [ 13 ] = 0.0 ; } break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [
14 ] >= rtDWork . isgvs5svtv [ rtDWork . o4qhycsmoh ] ) { rtDWork .
e5i3qovgis [ rtDWork . o4qhycsmoh ] = 1.0 ; rtDWork . edvs5rk3fa = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = abokkwsuss ; rtX .
ix1fmrtgm0 [ 13 ] = 0.0 ; } break ; case m1cczpmiyp : if ( muDoubleScalarAbs
( rtX . ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork .
edvs5rk3fa ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . o4qhycsmoh ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . o4qhycsmoh ] = 0.0 ; rtX . ix1fmrtgm0 [ 15
] = rtDWork . duzuwa454g [ ( int32_T ) rtDWork . edvs5rk3fa ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = abokkwsuss ; rtX . ix1fmrtgm0 [ 13
] = 0.0 ; } else { if ( rtDWork . ms2wqypsep [ rtDWork . o4qhycsmoh ] == 1.0
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = ey4wkwipnf ; } }
break ; case mollve35d0 : if ( rtDWork . ms2wqypsep [ rtDWork . o4qhycsmoh ]
== 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = ey4wkwipnf ;
} else { if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 15 ] - rtDWork .
duzuwa454g [ ( int32_T ) rtDWork . edvs5rk3fa ] ) <= 1.0 ) { rtDWork .
e5i3qovgis [ rtDWork . o4qhycsmoh ] = 1.0 ; rtDWork . e5i3qovgis [ rtDWork .
o4qhycsmoh ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn =
abokkwsuss ; rtX . ix1fmrtgm0 [ 13 ] = 0.0 ; } } break ; case hy3r3w5grg : if
( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . edvs5rk3fa ] ) <= 500.0 ) { rtDWork . bffxdmyjnr = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 13 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = m1cczpmiyp ; } else if ( rtX .
ix1fmrtgm0 [ 13 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
lfw2ucpenn = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
o4qhycsmoh ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn =
ey4wkwipnf ; } } break ; case gyxihahkca : if ( muDoubleScalarAbs ( rtX .
ix1fmrtgm0 [ 15 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork . edvs5rk3fa ]
) <= 500.0 ) { rtDWork . bffxdmyjnr = - muDoubleScalarPower ( rtX .
ix1fmrtgm0 [ 13 ] , 2.0 ) * 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
lfw2ucpenn = m1cczpmiyp ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
o4qhycsmoh ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn =
ey4wkwipnf ; } } break ; case abokkwsuss : if ( rtDWork . bzilocoerc [
rtDWork . o4qhycsmoh ] == 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . o4qhycsmoh
] = 0.0 ; rtX . ix1fmrtgm0 [ 14 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . lfw2ucpenn = nwxu2zxhpjf ; } break ; case nwxu2zxhpjf : if ( (
rtDWork . edvs5rk3fa == 0.0 ) && ( rtDWork . op2f2jmd1g [ rtDWork .
o4qhycsmoh ] == - 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn
= puirb1divs ; } else if ( ( ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ==
rtDWork . edvs5rk3fa ) && ( rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] ==
1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = puirb1divs ; }
else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] == 1 ) && (
rtDWork . edvs5rk3fa < ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ) ) || ( (
rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] == - 1 ) && ( rtDWork .
edvs5rk3fa > 0.0 ) ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn =
hy3r3w5grg ; rtDWork . edvs5rk3fa += ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . o4qhycsmoh ] ; } } break ; case ey4wkwipnf : if ( rtX . ix1fmrtgm0
[ 13 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ rtDWork . o4qhycsmoh ] = 1.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = bg2pxs4yrg ; } break ;
case kpgupuy2kp : if ( rtX . ix1fmrtgm0 [ 13 ] >= rtDWork . c1gduapxde ) {
rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = mollve35d0 ; } else { if
( rtDWork . ms2wqypsep [ rtDWork . o4qhycsmoh ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = ey4wkwipnf ; } } break ; default :
if ( rtDWork . kd0unb3ts3 [ rtDWork . o4qhycsmoh ] == 1.0 ) { rtDWork .
c1gduapxde = muDoubleScalarSqrt ( muDoubleScalarAbs ( rtDWork . duzuwa454g [
( int32_T ) rtDWork . edvs5rk3fa ] - rtX . ix1fmrtgm0 [ 15 ] ) * 0.5 ) ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . lfw2ucpenn = kpgupuy2kp ; rtDWork .
kd0unb3ts3 [ rtDWork . o4qhycsmoh ] = 0.0 ; } break ; } switch ( rtDWork .
ho4yv0pef5 ) { case puirb1divs : if ( rtX . ix1fmrtgm0 [ 18 ] >= 30.0 ) {
rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] = - rtDWork . op2f2jmd1g [
rtDWork . mf54iquk4a ] ; rtDWork . e5i3qovgis [ rtDWork . mf54iquk4a ] = 1.0
; rtDWork . bzilocoerc [ rtDWork . mf54iquk4a ] = 0.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . ho4yv0pef5 = abokkwsuss ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ;
} break ; case poj1ujn0qm : if ( rtX . ix1fmrtgm0 [ 18 ] >= rtDWork .
isgvs5svtv [ rtDWork . mf54iquk4a ] ) { rtDWork . e5i3qovgis [ rtDWork .
mf54iquk4a ] = 1.0 ; rtDWork . drbwe4rydf = 0.0 ; rtDWork . jviamtmzv0 = TRUE
; rtDWork . ho4yv0pef5 = abokkwsuss ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ; } break
; case m1cczpmiyp : if ( muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 19 ] -
rtDWork . duzuwa454g [ ( int32_T ) rtDWork . drbwe4rydf ] ) <= 1.0 ) {
rtDWork . e5i3qovgis [ rtDWork . mf54iquk4a ] = 1.0 ; rtDWork . bzilocoerc [
rtDWork . mf54iquk4a ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
ho4yv0pef5 = abokkwsuss ; rtX . ix1fmrtgm0 [ 17 ] = 0.0 ; } else { if (
rtDWork . ms2wqypsep [ rtDWork . mf54iquk4a ] == 1.0 ) { rtDWork . jviamtmzv0
= TRUE ; rtDWork . ho4yv0pef5 = ey4wkwipnf ; } } break ; case mollve35d0 : if
( rtDWork . ms2wqypsep [ rtDWork . mf54iquk4a ] == 1.0 ) { rtDWork .
jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 = ey4wkwipnf ; } else { if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . drbwe4rydf ] ) <= 1.0 ) { rtDWork . e5i3qovgis [ rtDWork
. mf54iquk4a ] = 1.0 ; rtDWork . e5i3qovgis [ rtDWork . mf54iquk4a ] = 0.0 ;
rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 = abokkwsuss ; rtX .
ix1fmrtgm0 [ 17 ] = 0.0 ; } } break ; case hy3r3w5grg : if (
muDoubleScalarAbs ( rtX . ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ (
int32_T ) rtDWork . drbwe4rydf ] ) <= 500.0 ) { rtDWork . acxds11k1q = -
muDoubleScalarPower ( rtX . ix1fmrtgm0 [ 17 ] , 2.0 ) * 0.001 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 = m1cczpmiyp ; } else if ( rtX .
ix1fmrtgm0 [ 17 ] >= 20.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
ho4yv0pef5 = gyxihahkca ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
mf54iquk4a ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 =
ey4wkwipnf ; } } break ; case gyxihahkca : if ( muDoubleScalarAbs ( rtX .
ix1fmrtgm0 [ 19 ] - rtDWork . duzuwa454g [ ( int32_T ) rtDWork . drbwe4rydf ]
) <= 500.0 ) { rtDWork . acxds11k1q = - muDoubleScalarPower ( rtX .
ix1fmrtgm0 [ 17 ] , 2.0 ) * 0.001 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
ho4yv0pef5 = m1cczpmiyp ; } else { if ( rtDWork . ms2wqypsep [ rtDWork .
mf54iquk4a ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 =
ey4wkwipnf ; } } break ; case abokkwsuss : if ( rtDWork . bzilocoerc [
rtDWork . mf54iquk4a ] == 1.0 ) { rtDWork . e5i3qovgis [ rtDWork . mf54iquk4a
] = 0.0 ; rtX . ix1fmrtgm0 [ 18 ] = 0.0 ; rtDWork . jviamtmzv0 = TRUE ;
rtDWork . ho4yv0pef5 = nwxu2zxhpjf ; } break ; case nwxu2zxhpjf : if ( (
rtDWork . drbwe4rydf == 0.0 ) && ( rtDWork . op2f2jmd1g [ rtDWork .
mf54iquk4a ] == - 1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5
= puirb1divs ; } else if ( ( ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ==
rtDWork . drbwe4rydf ) && ( rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] ==
1 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 = puirb1divs ; }
else { if ( ( ( rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] == 1 ) && (
rtDWork . drbwe4rydf < ( real_T ) ( rtDWork . mgytiqynw0 - 1 ) ) ) || ( (
rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] == - 1 ) && ( rtDWork .
drbwe4rydf > 0.0 ) ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . ho4yv0pef5 =
hy3r3w5grg ; rtDWork . drbwe4rydf += ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . mf54iquk4a ] ; } } break ; case ey4wkwipnf : if ( rtX . ix1fmrtgm0
[ 17 ] <= 0.1 ) { rtDWork . bdoe3sih52 [ 0 ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . ho4yv0pef5 = bg2pxs4yrg ; } break ; case kpgupuy2kp : if (
rtX . ix1fmrtgm0 [ 17 ] >= rtDWork . fao3lacynd ) { rtDWork . jviamtmzv0 =
TRUE ; rtDWork . ho4yv0pef5 = mollve35d0 ; } else { if ( rtDWork . ms2wqypsep
[ rtDWork . mf54iquk4a ] == 1.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
ho4yv0pef5 = ey4wkwipnf ; } } break ; default : if ( rtDWork . kd0unb3ts3 [
rtDWork . mf54iquk4a ] == 1.0 ) { rtDWork . fao3lacynd = muDoubleScalarSqrt (
muDoubleScalarAbs ( rtDWork . duzuwa454g [ ( int32_T ) rtDWork . drbwe4rydf ]
- rtX . ix1fmrtgm0 [ 19 ] ) * 0.5 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
ho4yv0pef5 = kpgupuy2kp ; rtDWork . kd0unb3ts3 [ rtDWork . mf54iquk4a ] = 0.0
; } break ; } switch ( rtDWork . gorxzp2tc5 ) { case mce1hmjau3 : if ( rtX .
ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . j04e3heoks [ rtDWork . kiu22l5yga ] =
1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; case bozn0j4h3r : if ( ( rtDWork .
e2s0vhz32j == fkpeazmlxh ) == 0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } else { if ( rtX .
ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . jknd2rgprd [ ( int32_T ) rtDWork .
mhps55ndar + ( ( int32_T ) rtDWork . ppgpg2d5gp << 2 ) ] = 1.0 ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 1
] = 0.0 ; } } break ; case bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 1 ] >= 1.0 )
{ rtDWork . omfdvdtquy [ rtDWork . kiu22l5yga ] = 1.0 ; rtDWork . jviamtmzv0
= TRUE ; rtDWork . gorxzp2tc5 = g5thp4xumb ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; }
break ; case jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork .
ov5pkqlglu [ ( int32_T ) rtDWork . mhps55ndar + ( ( int32_T ) rtDWork .
ppgpg2d5gp << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = bpsmzkxnnb ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; case
h05jpwy3hy : if ( rtDWork . e5i3qovgis [ rtDWork . kiu22l5yga ] == 1.0 ) {
rtDWork . kiu22l5yga = 1 ; rtDWork . mhps55ndar = rtDWork . bkhrmaqhhj ; k =
rtDWork . op2f2jmd1g [ rtDWork . kiu22l5yga ] + 1 ; rtDWork . ppgpg2d5gp = (
real_T ) ( ( ( k < 0 ) + k ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; rtDWork . e5i3qovgis
[ rtDWork . kiu22l5yga ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 1 ] >=
1.0 ) && ( rtDWork . e5i3qovgis [ rtDWork . kiu22l5yga ] != 1.0 ) ) { rtDWork
. guc4ezu4vd [ rtDWork . kiu22l5yga ] = rtX . ix1fmrtgm0 [ 10 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 1 ] >= 10.0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 = czs3vnbrbl ; } break ;
case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 1 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 1 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
gorxzp2tc5 = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 1 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
kiu22l5yga ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5 =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . ppgpg2d5gp << 2 ) + ( int32_T ) rtDWork
. mhps55ndar ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . gorxzp2tc5
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 1 ] = 0.0 ; } } break ; } switch ( rtDWork
. pwv1ttrztn ) { case mce1hmjau3 : if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) {
rtDWork . j04e3heoks [ rtDWork . hodq0clkgt ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . pwv1ttrztn = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; }
break ; case bozn0j4h3r : if ( ( rtDWork . psc01ml3a2 == fkpeazmlxh ) == 0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 12 ] = 0.0 ; } else { if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) {
rtDWork . jknd2rgprd [ ( int32_T ) rtDWork . eyeyekatwb + ( ( int32_T )
rtDWork . esraav3jfu << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
pwv1ttrztn = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } } break ; case
bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 12 ] >= 1.0 ) { rtDWork . omfdvdtquy [
rtDWork . hodq0clkgt ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
pwv1ttrztn = g5thp4xumb ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; case
jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ (
int32_T ) rtDWork . eyeyekatwb + ( ( int32_T ) rtDWork . esraav3jfu << 2 ) ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn = bpsmzkxnnb ; rtX
. ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; case h05jpwy3hy : if ( rtDWork .
e5i3qovgis [ rtDWork . hodq0clkgt ] == 1.0 ) { rtDWork . hodq0clkgt = 2 ;
rtDWork . eyeyekatwb = rtDWork . edvs5rk3fa ; k = rtDWork . op2f2jmd1g [
rtDWork . hodq0clkgt ] + 1 ; rtDWork . esraav3jfu = ( real_T ) ( ( ( k < 0 )
+ k ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn =
jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
hodq0clkgt ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 12 ] >= 1.0 ) && (
rtDWork . e5i3qovgis [ rtDWork . hodq0clkgt ] != 1.0 ) ) { rtDWork .
guc4ezu4vd [ rtDWork . hodq0clkgt ] = rtX . ix1fmrtgm0 [ 15 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 12
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 12 ] >= 10.0
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn = czs3vnbrbl ; } break
; case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 12 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 12 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
pwv1ttrztn = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 12 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
hodq0clkgt ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . esraav3jfu << 2 ) + ( int32_T ) rtDWork
. eyeyekatwb ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . pwv1ttrztn
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 12 ] = 0.0 ; } } break ; } switch ( rtDWork
. h0gr1gfnip ) { case mce1hmjau3 : if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) {
rtDWork . j04e3heoks [ rtDWork . ov1u3dz22b ] = 1.0 ; rtDWork . jviamtmzv0 =
TRUE ; rtDWork . h0gr1gfnip = bozn0j4h3r ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; }
break ; case bozn0j4h3r : if ( ( rtDWork . fgm4uvex5n == fkpeazmlxh ) == 0 )
{ rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip = bozn0j4h3r ; rtX .
ix1fmrtgm0 [ 11 ] = 0.0 ; } else { if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) {
rtDWork . jknd2rgprd [ ( int32_T ) rtDWork . n5wof223jc + ( ( int32_T )
rtDWork . lmgwt2ihoi << 2 ) ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h0gr1gfnip = hjcg5jty2z ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } } break ; case
bpsmzkxnnb : if ( rtX . ix1fmrtgm0 [ 11 ] >= 1.0 ) { rtDWork . omfdvdtquy [
rtDWork . ov1u3dz22b ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h0gr1gfnip = g5thp4xumb ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; case
jkd1vnqob2 : if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) { rtDWork . ov5pkqlglu [ (
int32_T ) rtDWork . n5wof223jc + ( ( int32_T ) rtDWork . lmgwt2ihoi << 2 ) ]
= 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip = bpsmzkxnnb ; rtX
. ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; case h05jpwy3hy : if ( rtDWork .
e5i3qovgis [ rtDWork . ov1u3dz22b ] == 1.0 ) { rtDWork . ov1u3dz22b = 3 ;
rtDWork . n5wof223jc = rtDWork . drbwe4rydf ; k = rtDWork . op2f2jmd1g [
rtDWork . ov1u3dz22b ] + 1 ; rtDWork . lmgwt2ihoi = ( real_T ) ( ( ( k < 0 )
+ k ) >> 1 ) ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip =
jkd1vnqob2 ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; rtDWork . e5i3qovgis [ rtDWork .
ov1u3dz22b ] = 0.0 ; } else { if ( ( rtX . ix1fmrtgm0 [ 11 ] >= 1.0 ) && (
rtDWork . e5i3qovgis [ rtDWork . ov1u3dz22b ] != 1.0 ) ) { rtDWork .
guc4ezu4vd [ rtDWork . ov1u3dz22b ] = rtX . ix1fmrtgm0 [ 19 ] ; rtDWork .
jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip = h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11
] = 0.0 ; } } break ; case g5thp4xumb : if ( rtX . ix1fmrtgm0 [ 11 ] >= 10.0
) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip = czs3vnbrbl ; } break
; case czs3vnbrbl : if ( ( rtX . ix1fmrtgm0 [ 11 ] >= 20.0 ) && ( rtX .
ix1fmrtgm0 [ 11 ] <= 30.0 ) ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork .
h0gr1gfnip = mce1hmjau3 ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } break ; default :
if ( rtX . ix1fmrtgm0 [ 11 ] >= 5.0 ) { rtDWork . bzilocoerc [ rtDWork .
ov1u3dz22b ] = 1.0 ; rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip =
h05jpwy3hy ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } else { if ( rtDWork .
a2j0p0cym5 [ ( ( int32_T ) rtDWork . lmgwt2ihoi << 2 ) + ( int32_T ) rtDWork
. n5wof223jc ] == 0.0 ) { rtDWork . jviamtmzv0 = TRUE ; rtDWork . h0gr1gfnip
= hjcg5jty2z ; rtX . ix1fmrtgm0 [ 11 ] = 0.0 ; } } break ; } } if ( rtDWork .
jviamtmzv0 ) { ssSetSolverNeedsReset ( rtS ) ; } } k0nn3it3fd ( ) ; { double
locTime = ssGetTaskTime ( rtS , 0 ) ; if ( ssGetLogOutput ( rtS ) ) {
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
_rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; switch ( rtDWork . e0siqbw4px ) { case
fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 6 ] = 0.0 ; break ; case nsgxdn54fe :
_rtXdot -> ix1fmrtgm0 [ 6 ] = 0.0 ; break ; case pvvniy1wrq : _rtXdot ->
ix1fmrtgm0 [ 6 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0 [ 6 ] = rtB
. mewmcyb4gt [ 0 ] ; break ; } switch ( rtDWork . piy1mfyq04 ) { case
fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 24 ] = 0.0 ; break ; case nsgxdn54fe :
_rtXdot -> ix1fmrtgm0 [ 24 ] = 0.0 ; break ; case pvvniy1wrq : _rtXdot ->
ix1fmrtgm0 [ 24 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0 [ 24 ] =
rtB . e2bcofptlp [ 0 ] ; break ; } _rtXdot -> ix1fmrtgm0 [ 2 ] = 1.0 ; switch
( rtDWork . m1coawef1z ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 23 ] =
0.0 ; break ; case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 23 ] = 0.0 ; break ;
case pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 23 ] = 1.0 ; break ; default :
_rtXdot -> ix1fmrtgm0 [ 23 ] = rtB . e2bcofptlp [ 4 ] ; break ; } switch (
rtDWork . kxzqsowcq4 ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 21 ] = 0.0
; break ; case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 21 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 21 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 21 ] = rtB . e2bcofptlp [ 1 ] ; break ; } switch ( rtDWork .
puu0onps1o ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 22 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 22 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 22 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 22 ] = rtB . e2bcofptlp [ 5 ] ; break ; } switch ( rtDWork .
d5gd34izwy ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 28 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 28 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 28 ] = rtB . e2bcofptlp [ 2 ] ; break ; } switch ( rtDWork .
m4axwklc2n ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 27 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 27 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 27 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 27 ] = rtB . e2bcofptlp [ 6 ] ; break ; } switch ( rtDWork .
cor0ek34i1 ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 25 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 25 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 25 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 25 ] = rtB . e2bcofptlp [ 3 ] ; break ; } switch ( rtDWork .
bieuzbl5sa ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 26 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 26 ] = 0.0 ; break ; case
pvvniy1wrq : _rtXdot -> ix1fmrtgm0 [ 26 ] = 1.0 ; break ; default : _rtXdot
-> ix1fmrtgm0 [ 26 ] = rtB . e2bcofptlp [ 7 ] ; break ; } switch ( rtDWork .
e2s0vhz32j ) { case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 7 ] = 0.0 ; break ;
case nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 7 ] = 0.0 ; break ; case pvvniy1wrq
: _rtXdot -> ix1fmrtgm0 [ 7 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 7 ] = rtB . mewmcyb4gt [ 1 ] ; break ; } switch ( rtDWork . psc01ml3a2 ) {
case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 16 ] = 0.0 ; break ; case
nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 16 ] = 0.0 ; break ; case pvvniy1wrq :
_rtXdot -> ix1fmrtgm0 [ 16 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 16 ] = rtB . mewmcyb4gt [ 2 ] ; break ; } switch ( rtDWork . fgm4uvex5n ) {
case fkpeazmlxh : _rtXdot -> ix1fmrtgm0 [ 20 ] = 0.0 ; break ; case
nsgxdn54fe : _rtXdot -> ix1fmrtgm0 [ 20 ] = 0.0 ; break ; case pvvniy1wrq :
_rtXdot -> ix1fmrtgm0 [ 20 ] = 1.0 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 20 ] = rtB . mewmcyb4gt [ 3 ] ; break ; } switch ( rtDWork . l5nch0wfe0 ) {
case puirb1divs : _rtXdot -> ix1fmrtgm0 [ 4 ] = 1.0 ; break ; case poj1ujn0qm
: _rtXdot -> ix1fmrtgm0 [ 4 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot ->
ix1fmrtgm0 [ 5 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] *
rtX . ix1fmrtgm0 [ 3 ] ; _rtXdot -> ix1fmrtgm0 [ 3 ] = rtDWork . ne5tcs23kl ;
break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 5 ] = ( real_T ) rtDWork .
op2f2jmd1g [ rtDWork . eli0bu1nqi ] * rtX . ix1fmrtgm0 [ 3 ] ; _rtXdot ->
ix1fmrtgm0 [ 3 ] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [
5 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] * rtX .
ix1fmrtgm0 [ 3 ] ; _rtXdot -> ix1fmrtgm0 [ 3 ] = 0.5 ; break ; case
gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 5 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . eli0bu1nqi ] * rtX . ix1fmrtgm0 [ 3 ] ; _rtXdot -> ix1fmrtgm0 [ 3 ]
= 0.0 ; break ; case abokkwsuss : break ; case nwxu2zxhpjf : break ; case
ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 5 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . eli0bu1nqi ] * rtX . ix1fmrtgm0 [ 3 ] ; _rtXdot -> ix1fmrtgm0 [ 3 ]
= - 1.5 ; break ; case kpgupuy2kp : _rtXdot -> ix1fmrtgm0 [ 5 ] = ( real_T )
rtDWork . op2f2jmd1g [ rtDWork . eli0bu1nqi ] * rtX . ix1fmrtgm0 [ 3 ] ;
_rtXdot -> ix1fmrtgm0 [ 3 ] = 0.5 ; break ; default : _rtXdot -> ix1fmrtgm0 [
5 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 3 ] = 0.0 ; break ; } _rtXdot ->
ix1fmrtgm0 [ 0 ] = 1.0 ; switch ( rtDWork . af0eeezn4z ) { case puirb1divs :
_rtXdot -> ix1fmrtgm0 [ 9 ] = 1.0 ; break ; case poj1ujn0qm : _rtXdot ->
ix1fmrtgm0 [ 9 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [ 10
] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] * rtX .
ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = rtDWork . nuqllrp43p ; break
; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork .
op2f2jmd1g [ rtDWork . p5wmqc33qy ] * rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot ->
ix1fmrtgm0 [ 8 ] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [
10 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] * rtX .
ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ] = 0.5 ; break ; case
gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . p5wmqc33qy ] * rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ]
= 0.0 ; break ; case abokkwsuss : break ; case nwxu2zxhpjf : break ; case
ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 10 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . p5wmqc33qy ] * rtX . ix1fmrtgm0 [ 8 ] ; _rtXdot -> ix1fmrtgm0 [ 8 ]
= - 1.5 ; break ; case kpgupuy2kp : _rtXdot -> ix1fmrtgm0 [ 10 ] = ( real_T )
rtDWork . op2f2jmd1g [ rtDWork . p5wmqc33qy ] * rtX . ix1fmrtgm0 [ 8 ] ;
_rtXdot -> ix1fmrtgm0 [ 8 ] = 0.5 ; break ; default : _rtXdot -> ix1fmrtgm0 [
10 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 8 ] = 0.0 ; break ; } switch ( rtDWork .
lfw2ucpenn ) { case puirb1divs : _rtXdot -> ix1fmrtgm0 [ 14 ] = 1.0 ; break ;
case poj1ujn0qm : _rtXdot -> ix1fmrtgm0 [ 14 ] = 1.0 ; break ; case
m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . o4qhycsmoh ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13
] = rtDWork . bffxdmyjnr ; break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [
15 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] * rtX .
ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13 ] = - 0.5 ; break ; case
hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . o4qhycsmoh ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13
] = 0.5 ; break ; case gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T )
rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] * rtX . ix1fmrtgm0 [ 13 ] ;
_rtXdot -> ix1fmrtgm0 [ 13 ] = 0.0 ; break ; case abokkwsuss : break ; case
nwxu2zxhpjf : break ; case ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 15 ] = (
real_T ) rtDWork . op2f2jmd1g [ rtDWork . o4qhycsmoh ] * rtX . ix1fmrtgm0 [
13 ] ; _rtXdot -> ix1fmrtgm0 [ 13 ] = - 1.5 ; break ; case kpgupuy2kp :
_rtXdot -> ix1fmrtgm0 [ 15 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork .
o4qhycsmoh ] * rtX . ix1fmrtgm0 [ 13 ] ; _rtXdot -> ix1fmrtgm0 [ 13 ] = 0.5 ;
break ; default : _rtXdot -> ix1fmrtgm0 [ 15 ] = 0.0 ; _rtXdot -> ix1fmrtgm0
[ 13 ] = 0.0 ; break ; } switch ( rtDWork . ho4yv0pef5 ) { case puirb1divs :
_rtXdot -> ix1fmrtgm0 [ 18 ] = 1.0 ; break ; case poj1ujn0qm : _rtXdot ->
ix1fmrtgm0 [ 18 ] = 1.0 ; break ; case m1cczpmiyp : _rtXdot -> ix1fmrtgm0 [
19 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] * rtX .
ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = rtDWork . acxds11k1q ;
break ; case mollve35d0 : _rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T ) rtDWork .
op2f2jmd1g [ rtDWork . mf54iquk4a ] * rtX . ix1fmrtgm0 [ 17 ] ; _rtXdot ->
ix1fmrtgm0 [ 17 ] = - 0.5 ; break ; case hy3r3w5grg : _rtXdot -> ix1fmrtgm0 [
19 ] = ( real_T ) rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] * rtX .
ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.5 ; break ; case
gyxihahkca : _rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . mf54iquk4a ] * rtX . ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17
] = 0.0 ; break ; case abokkwsuss : break ; case nwxu2zxhpjf : break ; case
ey4wkwipnf : _rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T ) rtDWork . op2f2jmd1g [
rtDWork . mf54iquk4a ] * rtX . ix1fmrtgm0 [ 17 ] ; _rtXdot -> ix1fmrtgm0 [ 17
] = - 1.5 ; break ; case kpgupuy2kp : _rtXdot -> ix1fmrtgm0 [ 19 ] = ( real_T
) rtDWork . op2f2jmd1g [ rtDWork . mf54iquk4a ] * rtX . ix1fmrtgm0 [ 17 ] ;
_rtXdot -> ix1fmrtgm0 [ 17 ] = 0.5 ; break ; default : _rtXdot -> ix1fmrtgm0
[ 19 ] = 0.0 ; _rtXdot -> ix1fmrtgm0 [ 17 ] = 0.0 ; break ; } _rtXdot ->
ix1fmrtgm0 [ 1 ] = 1.0 ; _rtXdot -> ix1fmrtgm0 [ 12 ] = 1.0 ; _rtXdot ->
ix1fmrtgm0 [ 11 ] = 1.0 ; } void MdlProjection ( void ) { } void MdlTerminate
( void ) { } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 29
) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough (
rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 67 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 36 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 1570811217U ) ; ssSetChecksumVal ( rtS ,
1 , 3232968676U ) ; ssSetChecksumVal ( rtS , 2 , 3323065162U ) ;
ssSetChecksumVal ( rtS , 3 , 1679384083U ) ; } SimStruct *
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
ssSetChecksumVal ( rtS , 0 , 1570811217U ) ; ssSetChecksumVal ( rtS , 1 ,
3232968676U ) ; ssSetChecksumVal ( rtS , 2 , 3323065162U ) ; ssSetChecksumVal
( rtS , 3 , 1679384083U ) ; { static const sysRanDType rtAlwaysEnabled =
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
