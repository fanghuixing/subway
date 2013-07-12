#include "__cf_subwaycontrolsystem.h"
#ifndef RTW_HEADER_subwaycontrolsystem_acc_h_
#define RTW_HEADER_subwaycontrolsystem_acc_h_
#ifndef subwaycontrolsystem_acc_COMMON_INCLUDES_
#define subwaycontrolsystem_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "subwaycontrolsystem_acc_types.h"
typedef struct { real_T B_2_2_0 ; real_T B_2_5_0 ; real_T B_2_8_0 ; real_T
B_2_11_0 ; real_T B_2_14_0 ; real_T B_2_17_0 ; real_T B_2_20_0 ; real_T
B_2_23_0 ; real_T B_2_26_0 ; real_T B_2_29_0 ; real_T B_2_32_0 ; real_T
B_2_35_0 ; real_T B_1_0_0 [ 4 ] ; real_T B_1_1_1 [ 4 ] ; real_T B_1_1_2 [ 4 ]
; real_T B_1_1_3 [ 8 ] ; real_T B_0_0_0 [ 8 ] ; real_T B_0_1_1 [ 8 ] ; real_T
B_2_34_0 ; real_T B_2_33_0 ; } BlockIO_subwaycontrolsystem ; typedef struct {
void * ToWorkspace_PWORK ; void * ToWorkspace1_PWORK ; void *
ToWorkspace2_PWORK ; } D_Work_subwaycontrolsystem ; typedef struct { real_T
SFunction_CSTATE [ 29 ] ; } ContinuousStates_subwaycontrolsystem ; typedef
struct { real_T SFunction_CSTATE [ 29 ] ; }
StateDerivatives_subwaycontrolsystem ; typedef struct { boolean_T
SFunction_CSTATE [ 29 ] ; } StateDisabled_subwaycontrolsystem ; typedef
struct { real_T SFunction_CSTATE [ 29 ] ; } CStateAbsTol_subwaycontrolsystem
; struct Parameters_subwaycontrolsystem_ { real_T P_0 ; real_T P_1 ; real_T
P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T
P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ;
real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T
P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; uint8_T P_24 ;
uint8_T P_25 ; uint8_T P_26 ; uint8_T P_27 ; uint8_T P_28 ; uint8_T P_29 ;
uint8_T P_30 ; uint8_T P_31 ; uint8_T P_32 ; uint8_T P_33 ; uint8_T P_34 ;
uint8_T P_35 ; char pad_P_35 [ 4 ] ; } ; extern
Parameters_subwaycontrolsystem subwaycontrolsystem_rtDefaultParameters ;
#endif
