#ifndef __c1_subwaycontrolsystem_h__
#define __c1_subwaycontrolsystem_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c1_ResolvedFunctionInfo
#define typedef_c1_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c1_ResolvedFunctionInfo;

#endif                                 /*typedef_c1_ResolvedFunctionInfo*/

#ifndef typedef_SFc1_subwaycontrolsystemInstanceStruct
#define typedef_SFc1_subwaycontrolsystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_UrgentController;
  uint8_T c1_tp_tmp;
  uint8_T c1_tp_Delay;
  uint8_T c1_tp_idle;
  uint8_T c1_tp_Controller1;
  uint8_T c1_tp_about_to_close2;
  uint8_T c1_tp_start;
  uint8_T c1_tp_about_to_open2;
  uint8_T c1_b_tp_idle;
  uint8_T c1_tp_about_to_open1;
  uint8_T c1_tp_about_to_close1;
  uint8_T c1_tp_open1;
  uint8_T c1_tp_ring;
  uint8_T c1_tp_Train0;
  uint8_T c1_tp_urgent_inc;
  uint8_T c1_tp_recover;
  uint8_T c1_tp_select;
  uint8_T c1_tp_urgent_stop;
  uint8_T c1_tp_init;
  uint8_T c1_tp_near;
  uint8_T c1_tp_urgent_dec;
  uint8_T c1_tp_stop;
  uint8_T c1_b_tp_tmp;
  uint8_T c1_tp_stablerun;
  uint8_T c1_tp_run;
  uint8_T c1_tp_ChangeDirection;
  uint8_T c1_tp_Controller0;
  uint8_T c1_b_tp_about_to_close2;
  uint8_T c1_b_tp_start;
  uint8_T c1_b_tp_about_to_open2;
  uint8_T c1_c_tp_idle;
  uint8_T c1_b_tp_about_to_open1;
  uint8_T c1_b_tp_about_to_close1;
  uint8_T c1_b_tp_open1;
  uint8_T c1_b_tp_ring;
  uint8_T c1_tp_Train0_door;
  uint8_T c1_tp_open;
  uint8_T c1_tp_part;
  uint8_T c1_tp_closed;
  uint8_T c1_tp_shut;
  uint8_T c1_tp_Train1_door;
  uint8_T c1_b_tp_open;
  uint8_T c1_b_tp_part;
  uint8_T c1_b_tp_closed;
  uint8_T c1_b_tp_shut;
  uint8_T c1_tp_Train1;
  uint8_T c1_b_tp_urgent_inc;
  uint8_T c1_b_tp_recover;
  uint8_T c1_b_tp_select;
  uint8_T c1_b_tp_urgent_stop;
  uint8_T c1_b_tp_init;
  uint8_T c1_b_tp_near;
  uint8_T c1_b_tp_urgent_dec;
  uint8_T c1_b_tp_stop;
  uint8_T c1_c_tp_tmp;
  uint8_T c1_b_tp_stablerun;
  uint8_T c1_b_tp_run;
  uint8_T c1_b_tp_ChangeDirection;
  uint8_T c1_tp_Controller3;
  uint8_T c1_c_tp_about_to_close2;
  uint8_T c1_c_tp_start;
  uint8_T c1_c_tp_about_to_open2;
  uint8_T c1_d_tp_idle;
  uint8_T c1_c_tp_about_to_open1;
  uint8_T c1_c_tp_about_to_close1;
  uint8_T c1_c_tp_open1;
  uint8_T c1_c_tp_ring;
  uint8_T c1_tp_Controller2;
  uint8_T c1_d_tp_about_to_close2;
  uint8_T c1_d_tp_start;
  uint8_T c1_d_tp_about_to_open2;
  uint8_T c1_e_tp_idle;
  uint8_T c1_d_tp_about_to_open1;
  uint8_T c1_d_tp_about_to_close1;
  uint8_T c1_d_tp_open1;
  uint8_T c1_d_tp_ring;
  uint8_T c1_tp_Train2;
  uint8_T c1_c_tp_urgent_inc;
  uint8_T c1_c_tp_recover;
  uint8_T c1_c_tp_select;
  uint8_T c1_c_tp_urgent_stop;
  uint8_T c1_c_tp_init;
  uint8_T c1_c_tp_near;
  uint8_T c1_c_tp_urgent_dec;
  uint8_T c1_c_tp_stop;
  uint8_T c1_d_tp_tmp;
  uint8_T c1_c_tp_stablerun;
  uint8_T c1_c_tp_run;
  uint8_T c1_c_tp_ChangeDirection;
  uint8_T c1_tp_Train2_door;
  uint8_T c1_c_tp_open;
  uint8_T c1_c_tp_part;
  uint8_T c1_c_tp_closed;
  uint8_T c1_c_tp_shut;
  uint8_T c1_tp_Train3;
  uint8_T c1_d_tp_urgent_inc;
  uint8_T c1_d_tp_recover;
  uint8_T c1_d_tp_select;
  uint8_T c1_d_tp_urgent_stop;
  uint8_T c1_d_tp_init;
  uint8_T c1_d_tp_near;
  uint8_T c1_d_tp_urgent_dec;
  uint8_T c1_d_tp_stop;
  uint8_T c1_e_tp_tmp;
  uint8_T c1_d_tp_stablerun;
  uint8_T c1_d_tp_run;
  uint8_T c1_d_tp_ChangeDirection;
  uint8_T c1_tp_Train3_door;
  uint8_T c1_d_tp_open;
  uint8_T c1_d_tp_part;
  uint8_T c1_d_tp_closed;
  uint8_T c1_d_tp_shut;
  uint8_T c1_tp_Screen_door10;
  uint8_T c1_e_tp_part;
  uint8_T c1_e_tp_open;
  uint8_T c1_e_tp_shut;
  uint8_T c1_e_tp_closed;
  uint8_T c1_tp_Screen_door11;
  uint8_T c1_f_tp_part;
  uint8_T c1_f_tp_open;
  uint8_T c1_f_tp_shut;
  uint8_T c1_f_tp_closed;
  uint8_T c1_tp_Screen_door01;
  uint8_T c1_g_tp_part;
  uint8_T c1_g_tp_open;
  uint8_T c1_g_tp_shut;
  uint8_T c1_g_tp_closed;
  uint8_T c1_tp_Screen_door00;
  uint8_T c1_h_tp_part;
  uint8_T c1_h_tp_open;
  uint8_T c1_h_tp_shut;
  uint8_T c1_h_tp_closed;
  uint8_T c1_tp_Screen_door30;
  uint8_T c1_i_tp_part;
  uint8_T c1_i_tp_open;
  uint8_T c1_i_tp_shut;
  uint8_T c1_i_tp_closed;
  uint8_T c1_tp_Screen_door31;
  uint8_T c1_j_tp_part;
  uint8_T c1_j_tp_open;
  uint8_T c1_j_tp_shut;
  uint8_T c1_j_tp_closed;
  uint8_T c1_tp_Screen_door21;
  uint8_T c1_k_tp_part;
  uint8_T c1_k_tp_open;
  uint8_T c1_k_tp_shut;
  uint8_T c1_k_tp_closed;
  uint8_T c1_tp_Screen_door20;
  uint8_T c1_l_tp_part;
  uint8_T c1_l_tp_open;
  uint8_T c1_l_tp_shut;
  uint8_T c1_l_tp_closed;
  boolean_T c1_isStable;
  boolean_T c1_stateChanged;
  real_T c1_lastMajorTime;
  uint8_T c1_is_active_c1_subwaycontrolsystem;
  uint8_T c1_is_UrgentController;
  uint8_T c1_is_active_UrgentController;
  uint8_T c1_is_Controller1;
  uint8_T c1_is_active_Controller1;
  uint8_T c1_is_Train0;
  uint8_T c1_is_active_Train0;
  uint8_T c1_is_Controller0;
  uint8_T c1_is_active_Controller0;
  uint8_T c1_is_Train0_door;
  uint8_T c1_is_active_Train0_door;
  uint8_T c1_is_Train1_door;
  uint8_T c1_is_active_Train1_door;
  uint8_T c1_is_Train1;
  uint8_T c1_is_active_Train1;
  uint8_T c1_is_Controller3;
  uint8_T c1_is_active_Controller3;
  uint8_T c1_is_Controller2;
  uint8_T c1_is_active_Controller2;
  uint8_T c1_is_Train2;
  uint8_T c1_is_active_Train2;
  uint8_T c1_is_Train2_door;
  uint8_T c1_is_active_Train2_door;
  uint8_T c1_is_Train3;
  uint8_T c1_is_active_Train3;
  uint8_T c1_is_Train3_door;
  uint8_T c1_is_active_Train3_door;
  uint8_T c1_is_Screen_door10;
  uint8_T c1_is_active_Screen_door10;
  uint8_T c1_is_Screen_door11;
  uint8_T c1_is_active_Screen_door11;
  uint8_T c1_is_Screen_door01;
  uint8_T c1_is_active_Screen_door01;
  uint8_T c1_is_Screen_door00;
  uint8_T c1_is_active_Screen_door00;
  uint8_T c1_is_Screen_door30;
  uint8_T c1_is_active_Screen_door30;
  uint8_T c1_is_Screen_door31;
  uint8_T c1_is_active_Screen_door31;
  uint8_T c1_is_Screen_door21;
  uint8_T c1_is_active_Screen_door21;
  uint8_T c1_is_Screen_door20;
  uint8_T c1_is_active_Screen_door20;
  real_T c1_start[4];
  real_T c1_stop[4];
  real_T c1_openPSD[8];
  real_T c1_closePSD[8];
  real_T c1_Delay[4];
  real_T c1_openTD[4];
  real_T c1_closeTD[4];
  real_T c1_S[4];
  real_T c1_urstart[4];
  real_T c1_urstop[4];
  int32_T c1_N;
  real_T c1_urstopped[4];
  int32_T c1_dir[4];
  real_T c1_position[4];
  real_T c1_PSDClosed[8];
  int32_T c1_i;
  int32_T c1_RelevantIndex[4];
  int32_T c1_tdis;
  int32_T c1_dis;
  real_T c1_stationid;
  real_T c1_side;
  int32_T c1_b_i;
  real_T c1_j;
  real_T c1_maxv;
  int32_T c1_c_i;
  real_T c1_acc;
  real_T c1_b_stationid;
  real_T c1_b_side;
  int32_T c1_d_i;
  real_T c1_b_j;
  real_T c1_b_maxv;
  int32_T c1_e_i;
  real_T c1_b_acc;
  real_T c1_c_stationid;
  real_T c1_c_side;
  int32_T c1_f_i;
  real_T c1_d_stationid;
  real_T c1_d_side;
  int32_T c1_g_i;
  real_T c1_c_j;
  real_T c1_c_maxv;
  int32_T c1_h_i;
  real_T c1_c_acc;
  real_T c1_d_j;
  real_T c1_d_maxv;
  int32_T c1_i_i;
  real_T c1_d_acc;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_subwaycontrolsystemInstanceStruct;

#endif                                 /*typedef_SFc1_subwaycontrolsystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_subwaycontrolsystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_subwaycontrolsystem_get_check_sum(mxArray *plhs[]);
extern void c1_subwaycontrolsystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
