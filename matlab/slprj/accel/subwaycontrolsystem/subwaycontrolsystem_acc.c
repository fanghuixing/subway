#include "__cf_subwaycontrolsystem.h"
#include <math.h>
#include "subwaycontrolsystem_acc.h"
#include "subwaycontrolsystem_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) {
BlockIO_subwaycontrolsystem * _rtB ; Parameters_subwaycontrolsystem * _rtP ;
D_Work_subwaycontrolsystem * _rtDW ; _rtDW = ( ( D_Work_subwaycontrolsystem *
) ssGetRootDWork ( S ) ) ; _rtP = ( ( Parameters_subwaycontrolsystem * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( BlockIO_subwaycontrolsystem * )
_ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_2_34_0
= _rtP -> P_0 ; _rtB -> B_2_33_0 = _rtP -> P_1 ; ssCallAccelRunBlock ( S , 2
, 2 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_2 ; _rtB ->
B_2_34_0 = _rtP -> P_3 ; ssCallAccelRunBlock ( S , 2 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_4 ; _rtB -> B_2_34_0 =
_rtP -> P_5 ; ssCallAccelRunBlock ( S , 2 , 8 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_2_33_0 = _rtP -> P_6 ; _rtB -> B_2_34_0 = _rtP -> P_7 ;
ssCallAccelRunBlock ( S , 2 , 11 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 =
_rtP -> P_8 ; _rtB -> B_2_34_0 = _rtP -> P_9 ; ssCallAccelRunBlock ( S , 2 ,
14 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_10 ; _rtB ->
B_2_34_0 = _rtP -> P_11 ; ssCallAccelRunBlock ( S , 2 , 17 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_12 ; _rtB -> B_2_34_0 =
_rtP -> P_13 ; ssCallAccelRunBlock ( S , 2 , 20 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_2_33_0 = _rtP -> P_14 ; _rtB -> B_2_34_0 = _rtP -> P_15 ;
ssCallAccelRunBlock ( S , 2 , 23 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 =
_rtP -> P_16 ; _rtB -> B_2_34_0 = _rtP -> P_17 ; ssCallAccelRunBlock ( S , 2
, 26 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_18 ; _rtB ->
B_2_34_0 = _rtP -> P_19 ; ssCallAccelRunBlock ( S , 2 , 29 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_2_33_0 = _rtP -> P_20 ; _rtB -> B_2_34_0 =
_rtP -> P_21 ; ssCallAccelRunBlock ( S , 2 , 32 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_2_33_0 = _rtP -> P_22 ; _rtB -> B_2_34_0 = _rtP -> P_23 ;
ssCallAccelRunBlock ( S , 2 , 35 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_0_0_0 [
0 ] = _rtB -> B_2_14_0 ; _rtB -> B_0_0_0 [ 1 ] = _rtB -> B_2_17_0 ; _rtB ->
B_0_0_0 [ 2 ] = _rtB -> B_2_20_0 ; _rtB -> B_0_0_0 [ 3 ] = _rtB -> B_2_23_0 ;
_rtB -> B_0_0_0 [ 4 ] = _rtB -> B_2_26_0 ; _rtB -> B_0_0_0 [ 5 ] = _rtB ->
B_2_29_0 ; _rtB -> B_0_0_0 [ 6 ] = _rtB -> B_2_32_0 ; _rtB -> B_0_0_0 [ 7 ] =
_rtB -> B_2_35_0 ; ssCallAccelRunBlock ( S , 0 , 1 , SS_CALL_MDL_OUTPUTS ) ;
} _rtB -> B_1_0_0 [ 0 ] = _rtB -> B_2_2_0 ; _rtB -> B_1_0_0 [ 1 ] = _rtB ->
B_2_5_0 ; _rtB -> B_1_0_0 [ 2 ] = _rtB -> B_2_8_0 ; _rtB -> B_1_0_0 [ 3 ] =
_rtB -> B_2_11_0 ; ssCallAccelRunBlock ( S , 1 , 1 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 38 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 39 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 2 , 40 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { BlockIO_subwaycontrolsystem *
_rtB ; _rtB = ( ( BlockIO_subwaycontrolsystem * ) _ssGetBlockIO ( S ) ) ;
ssCallAccelRunBlock ( S , 1 , 1 , SS_CALL_MDL_DERIVATIVES ) ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 1845896972U
) ; ssSetChecksumVal ( S , 1 , 4047283419U ) ; ssSetChecksumVal ( S , 2 ,
1518977201U ) ; ssSetChecksumVal ( S , 3 , 280220012U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.0" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( D_Work_subwaycontrolsystem ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( BlockIO_subwaycontrolsystem ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
Parameters_subwaycontrolsystem ) ) { static char msg [ 256 ] ; sprintf ( msg
, "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & subwaycontrolsystem_rtDefaultParameters ) ; rt_InitInfAndNaN (
sizeof ( real_T ) ) ; } static void mdlInitializeSampleTimes ( SimStruct * S
) { { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS =
ssGetSFunction ( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; } } static
void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
