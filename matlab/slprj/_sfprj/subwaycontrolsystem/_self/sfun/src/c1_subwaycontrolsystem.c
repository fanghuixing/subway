/* Include files */

#include "blascompat32.h"
#include "subwaycontrolsystem_sfun.h"
#include "c1_subwaycontrolsystem.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "subwaycontrolsystem_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_D1                       ((uint8_T)1U)
#define c1_IN_Delay                    ((uint8_T)2U)
#define c1_IN_tmp                      ((uint8_T)3U)
#define c1_IN_about_to_close1          ((uint8_T)1U)
#define c1_IN_about_to_close2          ((uint8_T)2U)
#define c1_IN_about_to_open1           ((uint8_T)3U)
#define c1_IN_about_to_open2           ((uint8_T)4U)
#define c1_IN_idle                     ((uint8_T)5U)
#define c1_IN_open1                    ((uint8_T)6U)
#define c1_IN_ring                     ((uint8_T)7U)
#define c1_IN_start                    ((uint8_T)8U)
#define c1_IN_closed                   ((uint8_T)1U)
#define c1_IN_open                     ((uint8_T)2U)
#define c1_IN_part                     ((uint8_T)3U)
#define c1_IN_shut                     ((uint8_T)4U)
#define c1_IN_ChangeDirection          ((uint8_T)1U)
#define c1_IN_init                     ((uint8_T)2U)
#define c1_IN_near                     ((uint8_T)3U)
#define c1_IN_recover                  ((uint8_T)4U)
#define c1_IN_run                      ((uint8_T)5U)
#define c1_IN_select                   ((uint8_T)6U)
#define c1_IN_stablerun                ((uint8_T)7U)
#define c1_IN_stop                     ((uint8_T)8U)
#define c1_b_IN_tmp                    ((uint8_T)9U)
#define c1_IN_urgent_dec               ((uint8_T)10U)
#define c1_IN_urgent_inc               ((uint8_T)11U)
#define c1_IN_urgent_stop              ((uint8_T)12U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[4] = { "si", "sj", "nargin", "nargout"
};

static const char * c1_b_debug_family_names[5] = { "needstop", "index", "nargin",
  "nargout", "a" };

/* Function Declarations */
static void initialize_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void initialize_params_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void enable_c1_subwaycontrolsystem(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance);
static void disable_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void ext_mode_exec_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void set_sim_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void finalize_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void sf_c1_subwaycontrolsystem(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance);
static void zeroCrossings_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void derivatives_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void outputs_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void initSimStructsc1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void c1_eml_ini_fcn_to_be_inlined_976
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void c1_eml_term_fcn_to_be_inlined_976
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_sj, const char_T *c1_identifier);
static int32_T c1_d_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static real_T c1_abs(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
                     real_T c1_x);
static real_T c1_eml_scalar_abs(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, real_T c1_x);
static boolean_T c1_eml_int_forloop_overflow_check_helper
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_b);
static int32_T c1_intmax(SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void c1_eml_int_forloop_overflow_check
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_b);
static void c1_check_forloop_overflow_error
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, boolean_T c1_overflow);
static int32_T c1_mtimes(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
  int32_T c1_a, real_T c1_b);
static void c1_common_checks(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance);
static void c1_integer_only_checks(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance);
static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u);
static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, char_T c1_u[34]);
static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, char_T c1_u[5]);
static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, uint8_T c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_is_UrgentController, const char_T
  *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[4]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[8]);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_start, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_h_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[4]);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_stop, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_j_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_k_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_openPSD, const char_T *c1_identifier, real_T
  c1_y[8]);
static void c1_l_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u[4]);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_dir, const char_T *c1_identifier, int32_T
  c1_y[4]);
static void c1_n_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[4]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u[4]);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_o_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_RelevantIndex, const char_T *c1_identifier,
  int32_T c1_y[4]);
static void c1_p_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[4]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance);
static void c1_q_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u);
static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_s_emlrt_marshallIn
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId);
static int32_T c1__s32_d_(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
  real_T c1_b);
static int32_T c1__s32_uminus__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b);
static int32_T c1__s32_minus__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c);
static int32_T c1__s32_add__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c);
static void init_dsm_address_info(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_Controller0;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_active_Controller1;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_active_Controller2;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_active_Controller3;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_active_Screen_door00;
  uint8_T *c1_is_Screen_door00;
  uint8_T *c1_is_active_Screen_door01;
  uint8_T *c1_is_Screen_door01;
  uint8_T *c1_is_active_Screen_door10;
  uint8_T *c1_is_Screen_door10;
  uint8_T *c1_is_active_Screen_door11;
  uint8_T *c1_is_Screen_door11;
  uint8_T *c1_is_active_Screen_door20;
  uint8_T *c1_is_Screen_door20;
  uint8_T *c1_is_active_Screen_door21;
  uint8_T *c1_is_Screen_door21;
  uint8_T *c1_is_active_Screen_door30;
  uint8_T *c1_is_Screen_door30;
  uint8_T *c1_is_active_Screen_door31;
  uint8_T *c1_is_Screen_door31;
  uint8_T *c1_is_active_Train0;
  uint8_T *c1_is_Train0;
  uint8_T *c1_is_active_Train0_door;
  uint8_T *c1_is_Train0_door;
  uint8_T *c1_is_active_Train1;
  uint8_T *c1_is_Train1;
  uint8_T *c1_is_active_Train1_door;
  uint8_T *c1_is_Train1_door;
  uint8_T *c1_is_active_Train2;
  uint8_T *c1_is_Train2;
  uint8_T *c1_is_active_Train2_door;
  uint8_T *c1_is_Train2_door;
  uint8_T *c1_is_active_Train3;
  uint8_T *c1_is_Train3;
  uint8_T *c1_is_active_Train3_door;
  uint8_T *c1_is_Train3_door;
  uint8_T *c1_is_active_UrgentController;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  int32_T *c1_N;
  real_T *c1_t;
  int32_T *c1_i;
  int32_T *c1_tdis;
  int32_T *c1_dis;
  real_T *c1_z;
  real_T *c1_stationid;
  real_T *c1_side;
  int32_T *c1_b_i;
  real_T *c1_v;
  real_T *c1_j;
  real_T *c1_maxv;
  real_T *c1_time;
  int32_T *c1_c_i;
  real_T *c1_distance;
  real_T *c1_acc;
  real_T *c1_b_z;
  real_T *c1_b_stationid;
  real_T *c1_b_side;
  int32_T *c1_d_i;
  real_T *c1_y1;
  real_T *c1_b_y1;
  real_T *c1_b_v;
  real_T *c1_b_j;
  real_T *c1_b_maxv;
  real_T *c1_b_time;
  int32_T *c1_e_i;
  real_T *c1_b_distance;
  real_T *c1_b_acc;
  real_T *c1_c_z;
  real_T *c1_c_stationid;
  real_T *c1_c_side;
  int32_T *c1_f_i;
  real_T *c1_d_z;
  real_T *c1_d_stationid;
  real_T *c1_d_side;
  int32_T *c1_g_i;
  real_T *c1_c_v;
  real_T *c1_c_j;
  real_T *c1_c_maxv;
  real_T *c1_c_time;
  int32_T *c1_h_i;
  real_T *c1_c_distance;
  real_T *c1_c_acc;
  real_T *c1_c_y1;
  real_T *c1_d_v;
  real_T *c1_d_j;
  real_T *c1_d_maxv;
  real_T *c1_d_time;
  int32_T *c1_i_i;
  real_T *c1_d_distance;
  real_T *c1_d_acc;
  real_T *c1_d_y1;
  real_T *c1_y2;
  real_T *c1_b_y2;
  real_T *c1_c_y2;
  real_T *c1_d_y2;
  real_T *c1_e_y2;
  real_T *c1_f_y2;
  real_T *c1_g_y2;
  real_T *c1_h_y2;
  real_T (*c1_openPSD)[8];
  real_T (*c1_closePSD)[8];
  real_T (*c1_PSDClosed)[8];
  real_T (*c1_y2_out)[8];
  real_T (*c1_stop)[4];
  real_T (*c1_Delay)[4];
  real_T (*c1_S)[4];
  int32_T (*c1_RelevantIndex)[4];
  real_T (*c1_y1_out)[4];
  real_T (*c1_distance_out)[4];
  real_T (*c1_position)[4];
  int32_T (*c1_dir)[4];
  real_T (*c1_urstopped)[4];
  real_T (*c1_urstop)[4];
  real_T (*c1_urstart)[4];
  real_T (*c1_closeTD)[4];
  real_T (*c1_openTD)[4];
  real_T (*c1_start)[4];
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
  c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
  c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 90);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
  c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
  c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 86);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
  c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 84);
  c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
  c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
  c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
  c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 81);
  c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
  c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
  c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
  c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
  c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 76);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
  c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 74);
  c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
  c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
  c1_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
  c1_j = (real_T *)ssGetDWork(chartInstance->S, 69);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
  c1_side = (real_T *)ssGetDWork(chartInstance->S, 67);
  c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
  c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_dis = (int32_T *)ssGetDWork(chartInstance->S, 65);
  c1_tdis = (int32_T *)ssGetDWork(chartInstance->S, 64);
  c1_RelevantIndex = (int32_T (*)[4])ssGetDWork(chartInstance->S, 63);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
  c1_position = (real_T (*)[4])ssGetDWork(chartInstance->S, 60);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_urstopped = (real_T (*)[4])ssGetDWork(chartInstance->S, 58);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
  c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
  c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
  c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
  c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
  c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
  c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
  c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
  c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
  c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
  c1_is_active_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 46);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_active_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 44);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_active_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 42);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_active_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 40);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_active_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 38);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_active_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 36);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_active_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 34);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_active_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 32);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_active_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 30);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_active_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 28);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_active_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 26);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_active_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 24);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_active_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 22);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_active_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 20);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_active_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 18);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_active_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 16);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_active_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 14);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_active_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 12);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_active_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 10);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_active_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 8);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_active_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 6);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  *c1_is_active_Controller0 = 0U;
  *c1_is_Controller0 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Controller1 = 0U;
  *c1_is_Controller1 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Controller2 = 0U;
  *c1_is_Controller2 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Controller3 = 0U;
  *c1_is_Controller3 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door00 = 0U;
  *c1_is_Screen_door00 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door01 = 0U;
  *c1_is_Screen_door01 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door10 = 0U;
  *c1_is_Screen_door10 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door11 = 0U;
  *c1_is_Screen_door11 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door20 = 0U;
  *c1_is_Screen_door20 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door21 = 0U;
  *c1_is_Screen_door21 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door30 = 0U;
  *c1_is_Screen_door30 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Screen_door31 = 0U;
  *c1_is_Screen_door31 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train0 = 0U;
  *c1_is_Train0 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train0_door = 0U;
  *c1_is_Train0_door = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train1 = 0U;
  *c1_is_Train1 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train1_door = 0U;
  *c1_is_Train1_door = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train2 = 0U;
  *c1_is_Train2 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train2_door = 0U;
  *c1_is_Train2_door = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train3 = 0U;
  *c1_is_Train3 = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_Train3_door = 0U;
  *c1_is_Train3_door = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_UrgentController = 0U;
  *c1_is_UrgentController = c1_IN_NO_ACTIVE_CHILD;
  *c1_is_active_c1_subwaycontrolsystem = 0U;
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    (*c1_start)[c1_i0] = 0.0;
  }

  (*c1_stop)[0] = 0.0;
  (*c1_stop)[1] = 0.0;
  (*c1_stop)[2] = 0.0;
  (*c1_stop)[3] = 0.0;
  for (c1_i1 = 0; c1_i1 < 8; c1_i1++) {
    (*c1_openPSD)[c1_i1] = 0.0;
  }

  for (c1_i2 = 0; c1_i2 < 8; c1_i2++) {
    (*c1_closePSD)[c1_i2] = 0.0;
  }

  (*c1_Delay)[0] = 0.0;
  (*c1_Delay)[1] = 50.0;
  (*c1_Delay)[2] = 100.0;
  (*c1_Delay)[3] = 150.0;
  for (c1_i3 = 0; c1_i3 < 4; c1_i3++) {
    (*c1_openTD)[c1_i3] = 0.0;
  }

  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    (*c1_closeTD)[c1_i4] = 0.0;
  }

  (*c1_S)[0] = 0.0;
  (*c1_S)[1] = 2284.0;
  (*c1_S)[2] = 3292.0;
  (*c1_S)[3] = 9097.0;
  for (c1_i5 = 0; c1_i5 < 4; c1_i5++) {
    (*c1_urstart)[c1_i5] = 0.0;
  }

  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    (*c1_urstop)[c1_i6] = 0.0;
  }

  *c1_N = 4;
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    (*c1_urstopped)[c1_i7] = 0.0;
  }

  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    (*c1_dir)[c1_i8] = 0;
  }

  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    (*c1_position)[c1_i9] = 0.0;
  }

  for (c1_i10 = 0; c1_i10 < 8; c1_i10++) {
    (*c1_PSDClosed)[c1_i10] = 0.0;
  }

  *c1_t = 0.0;
  *c1_i = 0;
  (*c1_RelevantIndex)[0] = -1;
  (*c1_RelevantIndex)[1] = -1;
  (*c1_RelevantIndex)[2] = -1;
  (*c1_RelevantIndex)[3] = -1;
  *c1_tdis = 0;
  *c1_dis = 0;
  *c1_z = 0.0;
  *c1_stationid = 0.0;
  *c1_side = 0.0;
  *c1_b_i = 1;
  *c1_v = 0.0;
  *c1_j = 0.0;
  *c1_maxv = 0.0;
  *c1_time = 0.0;
  *c1_c_i = 0;
  *c1_distance = 0.0;
  *c1_acc = 0.0;
  *c1_b_z = 0.0;
  *c1_b_stationid = 0.0;
  *c1_b_side = 0.0;
  *c1_d_i = 0;
  *c1_y1 = 0.0;
  *c1_b_y1 = 0.0;
  *c1_b_v = 0.0;
  *c1_b_j = 0.0;
  *c1_b_maxv = 0.0;
  *c1_b_time = 0.0;
  *c1_e_i = 0;
  *c1_b_distance = 0.0;
  *c1_b_acc = 0.0;
  *c1_c_z = 0.0;
  *c1_c_stationid = 0.0;
  *c1_c_side = 0.0;
  *c1_f_i = 3;
  *c1_d_z = 0.0;
  *c1_d_stationid = 0.0;
  *c1_d_side = 0.0;
  *c1_g_i = 2;
  *c1_c_v = 0.0;
  *c1_c_j = 0.0;
  *c1_c_maxv = 0.0;
  *c1_c_time = 0.0;
  *c1_h_i = 0;
  *c1_c_distance = 0.0;
  *c1_c_acc = 0.0;
  *c1_c_y1 = 0.0;
  *c1_d_v = 0.0;
  *c1_d_j = 0.0;
  *c1_d_maxv = 0.0;
  *c1_d_time = 0.0;
  *c1_i_i = 0;
  *c1_d_distance = 0.0;
  *c1_d_acc = 0.0;
  *c1_d_y1 = 0.0;
  *c1_y2 = 0.0;
  *c1_b_y2 = 0.0;
  *c1_c_y2 = 0.0;
  *c1_d_y2 = 0.0;
  *c1_e_y2 = 0.0;
  *c1_f_y2 = 0.0;
  *c1_g_y2 = 0.0;
  *c1_h_y2 = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
      (*c1_distance_out)[c1_i11] = 0.0;
    }
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
      (*c1_y1_out)[c1_i12] = 0.0;
    }
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 3) != 0)) {
    for (c1_i13 = 0; c1_i13 < 8; c1_i13++) {
      (*c1_y2_out)[c1_i13] = 0.0;
    }
  }
}

static void initialize_params_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void enable_c1_subwaycontrolsystem(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  uint8_T *c1_is_active_UrgentController;
  uint8_T *c1_is_active_Controller1;
  uint8_T *c1_is_active_Controller0;
  uint8_T *c1_is_active_Screen_door20;
  uint8_T *c1_is_active_Screen_door21;
  uint8_T *c1_is_active_Train0_door;
  uint8_T *c1_is_active_Train1_door;
  uint8_T *c1_is_active_Screen_door31;
  uint8_T *c1_is_active_Screen_door30;
  uint8_T *c1_is_active_Controller3;
  uint8_T *c1_is_active_Controller2;
  uint8_T *c1_is_active_Screen_door00;
  uint8_T *c1_is_active_Screen_door01;
  uint8_T *c1_is_active_Screen_door11;
  uint8_T *c1_is_active_Train2_door;
  uint8_T *c1_is_active_Train3;
  uint8_T *c1_is_active_Train3_door;
  uint8_T *c1_is_active_Screen_door10;
  uint8_T *c1_is_active_Train0;
  uint8_T *c1_is_active_Train1;
  uint8_T *c1_is_active_Train2;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_Train3;
  uint8_T *c1_is_Screen_door20;
  uint8_T *c1_is_Screen_door21;
  uint8_T *c1_is_Screen_door31;
  uint8_T *c1_is_Train0_door;
  uint8_T *c1_is_Train1_door;
  uint8_T *c1_is_Screen_door30;
  uint8_T *c1_is_Screen_door00;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_Screen_door01;
  uint8_T *c1_is_Screen_door11;
  uint8_T *c1_is_Train2_door;
  uint8_T *c1_is_Train3_door;
  uint8_T *c1_is_Screen_door10;
  uint8_T *c1_is_Train0;
  uint8_T *c1_is_Train1;
  uint8_T *c1_is_Train2;
  int32_T *c1_sfEvent;
  c1_is_active_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 46);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_active_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 44);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_active_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 42);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_active_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 40);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_active_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 38);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_active_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 36);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_active_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 34);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_active_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 32);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_active_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 30);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_active_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 28);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_active_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 26);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_active_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 24);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_active_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 22);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_active_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 20);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_active_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 18);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_active_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 16);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_active_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 14);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_active_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 12);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_active_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 10);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_active_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 8);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_active_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 6);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (*c1_is_active_c1_subwaycontrolsystem == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *c1_sfEvent);
  }

  if (*c1_is_active_UrgentController == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 148U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 148U, *c1_sfEvent);
  }

  if (*c1_is_UrgentController == c1_IN_tmp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 153U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 153U, *c1_sfEvent);
  }

  if (*c1_is_UrgentController == c1_IN_Delay) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 151U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 151U, *c1_sfEvent);
  }

  if (*c1_is_UrgentController == c1_IN_D1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 150U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 150U, *c1_sfEvent);
  }

  if (*c1_is_active_Controller1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_about_to_close2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_about_to_open2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_about_to_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_about_to_close1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *c1_sfEvent);
  }

  if (*c1_is_Controller1 == c1_IN_ring) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *c1_sfEvent);
  }

  if (*c1_is_active_Controller0 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_about_to_close2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_about_to_open2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_about_to_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_about_to_close1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *c1_sfEvent);
  }

  if (*c1_is_Controller0 == c1_IN_ring) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_select) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 136U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 136U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door20 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door20 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door20 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door20 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door21 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door20 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door21 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door21 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door21 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door21 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door31 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, *c1_sfEvent);
  }

  if (*c1_is_active_Train0_door == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 89U, *c1_sfEvent);
  }

  if (*c1_is_Train0_door == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 91U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 91U, *c1_sfEvent);
  }

  if (*c1_is_Train0_door == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 92U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 92U, *c1_sfEvent);
  }

  if (*c1_is_Train0_door == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 90U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *c1_sfEvent);
  }

  if (*c1_is_Train0_door == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 93U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 93U, *c1_sfEvent);
  }

  if (*c1_is_active_Train1_door == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 107U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 107U, *c1_sfEvent);
  }

  if (*c1_is_Train1_door == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 109U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 109U, *c1_sfEvent);
  }

  if (*c1_is_Train1_door == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 110U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 110U, *c1_sfEvent);
  }

  if (*c1_is_Train1_door == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 108U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 108U, *c1_sfEvent);
  }

  if (*c1_is_Train1_door == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 111U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 111U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door31 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 75U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 75U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door31 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 73U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door31 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door31 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 71U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door30 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door30 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door30 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door30 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 69U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 69U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door30 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door00 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door00 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door00 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *c1_sfEvent);
  }

  if (*c1_is_active_Controller3 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_about_to_close2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_about_to_open2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_about_to_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_about_to_close1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, *c1_sfEvent);
  }

  if (*c1_is_Controller3 == c1_IN_ring) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *c1_sfEvent);
  }

  if (*c1_is_active_Controller2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_about_to_close2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_about_to_open2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_about_to_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_about_to_close1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_open1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, *c1_sfEvent);
  }

  if (*c1_is_Controller2 == c1_IN_ring) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door00 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door00 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door01 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door01 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door01 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door01 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door01 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door11 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door11 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door11 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door11 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door11 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, *c1_sfEvent);
  }

  if (*c1_is_active_Train2_door == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 125U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 125U, *c1_sfEvent);
  }

  if (*c1_is_Train2_door == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 127U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 127U, *c1_sfEvent);
  }

  if (*c1_is_Train2_door == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 128U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 128U, *c1_sfEvent);
  }

  if (*c1_is_Train2_door == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 126U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 126U, *c1_sfEvent);
  }

  if (*c1_is_Train2_door == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 129U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 129U, *c1_sfEvent);
  }

  if (*c1_is_active_Train3 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 130U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 130U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_urgent_inc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 141U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 141U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_recover) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 134U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 134U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_urgent_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 142U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 142U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 132U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 132U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_urgent_dec) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 140U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_near) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 133U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 133U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 138U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 138U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_b_IN_tmp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 139U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 139U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_stablerun) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 137U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 137U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 135U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 135U, *c1_sfEvent);
  }

  if (*c1_is_Train3 == c1_IN_ChangeDirection) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 131U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 131U, *c1_sfEvent);
  }

  if (*c1_is_active_Train3_door == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 143U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 143U, *c1_sfEvent);
  }

  if (*c1_is_Train3_door == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 145U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 145U, *c1_sfEvent);
  }

  if (*c1_is_Train3_door == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 146U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 146U, *c1_sfEvent);
  }

  if (*c1_is_Train3_door == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 144U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 144U, *c1_sfEvent);
  }

  if (*c1_is_Train3_door == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 147U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 147U, *c1_sfEvent);
  }

  if (*c1_is_active_Screen_door10 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door10 == c1_IN_part) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door10 == c1_IN_open) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door10 == c1_IN_shut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *c1_sfEvent);
  }

  if (*c1_is_Screen_door10 == c1_IN_closed) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *c1_sfEvent);
  }

  if (*c1_is_active_Train0 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 76U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 76U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_urgent_inc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 87U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_recover) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 80U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 80U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_select) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 82U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_urgent_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 88U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 88U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 78U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 78U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_near) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 79U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_urgent_dec) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 86U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 84U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_b_IN_tmp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 85U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_stablerun) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 83U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 83U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 81U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 81U, *c1_sfEvent);
  }

  if (*c1_is_Train0 == c1_IN_ChangeDirection) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 77U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 77U, *c1_sfEvent);
  }

  if (*c1_is_active_Train1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 94U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 94U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_urgent_inc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 105U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_recover) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 98U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_select) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 100U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 100U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_urgent_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 106U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 106U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 96U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 96U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_near) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 97U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_urgent_dec) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 104U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 102U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_b_IN_tmp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 103U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_stablerun) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 101U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 99U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *c1_sfEvent);
  }

  if (*c1_is_Train1 == c1_IN_ChangeDirection) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 95U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 95U, *c1_sfEvent);
  }

  if (*c1_is_active_Train2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 112U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 112U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_urgent_inc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 123U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_recover) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 116U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_select) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 118U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 118U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_urgent_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 124U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 124U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 114U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 114U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_near) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 115U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 115U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_urgent_dec) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 122U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 120U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_b_IN_tmp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 121U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_stablerun) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 119U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 119U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *c1_sfEvent);
  }

  if (*c1_is_Train2 == c1_IN_ChangeDirection) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 113U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *c1_sfEvent);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_subwaycontrolsystem(chartInstance);
}

static const mxArray *get_sim_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  const mxArray *c1_st = NULL;
  c1_st = NULL;
  sf_mex_assign(&c1_st, c1_k_emlrt_marshallOut(chartInstance), FALSE);
  return c1_st;
}

static void set_sim_state_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c1_st)
{
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_st));
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_subwaycontrolsystem(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_subwaycontrolsystem(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_d0;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  real_T c1_d1;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_d2;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  real_T c1_d3;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  real_T c1_d4;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  real_T c1_d5;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  real_T c1_d6;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  real_T c1_d7;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  real_T c1_d8;
  int32_T c1_i72;
  real_T c1_d9;
  real_T c1_d10;
  real_T c1_d11;
  real_T c1_d12;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  real_T c1_d13;
  int32_T c1_i76;
  real_T c1_d14;
  real_T c1_d15;
  real_T c1_d16;
  real_T c1_d17;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  real_T c1_d18;
  int32_T c1_i80;
  real_T c1_d19;
  real_T c1_d20;
  real_T c1_d21;
  real_T c1_d22;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  real_T c1_d23;
  int32_T c1_i84;
  real_T c1_d24;
  real_T c1_d25;
  real_T c1_d26;
  real_T c1_d27;
  int32_T c1_i85;
  boolean_T c1_out;
  int32_T c1_i86;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  int32_T c1_i87;
  boolean_T c1_temp;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  int32_T c1_i88;
  int32_T c1_i89;
  boolean_T c1_g_out;
  int32_T c1_i90;
  real_T c1_d28;
  int32_T c1_i91;
  boolean_T c1_h_out;
  boolean_T c1_i_out;
  int32_T c1_i92;
  boolean_T c1_j_out;
  boolean_T c1_k_out;
  int32_T c1_i93;
  real_T c1_d29;
  int32_T c1_i94;
  int32_T c1_i95;
  boolean_T c1_b_temp;
  boolean_T c1_l_out;
  boolean_T c1_m_out;
  int32_T c1_i96;
  boolean_T c1_n_out;
  boolean_T c1_o_out;
  boolean_T c1_p_out;
  int32_T c1_i97;
  boolean_T c1_q_out;
  int32_T c1_i98;
  boolean_T c1_r_out;
  int32_T c1_i99;
  boolean_T c1_s_out;
  boolean_T c1_c_temp;
  boolean_T c1_t_out;
  int32_T c1_i100;
  real_T c1_d30;
  int32_T c1_i101;
  real_T c1_d31;
  int32_T c1_i102;
  boolean_T c1_d_temp;
  boolean_T c1_u_out;
  int32_T c1_i103;
  real_T c1_d32;
  boolean_T c1_v_out;
  boolean_T c1_e_temp;
  boolean_T c1_w_out;
  boolean_T c1_x_out;
  boolean_T c1_y_out;
  int32_T c1_i104;
  boolean_T c1_ab_out;
  boolean_T c1_bb_out;
  int32_T c1_i105;
  real_T c1_d33;
  int32_T c1_i106;
  boolean_T c1_cb_out;
  boolean_T c1_db_out;
  int32_T c1_i107;
  boolean_T c1_eb_out;
  boolean_T c1_fb_out;
  int32_T c1_i108;
  real_T c1_d34;
  int32_T c1_i109;
  int32_T c1_i110;
  boolean_T c1_f_temp;
  boolean_T c1_gb_out;
  boolean_T c1_hb_out;
  int32_T c1_i111;
  real_T c1_d35;
  int32_T c1_i112;
  boolean_T c1_ib_out;
  boolean_T c1_jb_out;
  int32_T c1_i113;
  boolean_T c1_kb_out;
  boolean_T c1_lb_out;
  int32_T c1_i114;
  real_T c1_d36;
  int32_T c1_i115;
  int32_T c1_i116;
  boolean_T c1_g_temp;
  boolean_T c1_mb_out;
  boolean_T c1_nb_out;
  int32_T c1_i117;
  real_T c1_d37;
  int32_T c1_i118;
  boolean_T c1_ob_out;
  boolean_T c1_pb_out;
  int32_T c1_i119;
  boolean_T c1_qb_out;
  boolean_T c1_rb_out;
  int32_T c1_i120;
  real_T c1_d38;
  int32_T c1_i121;
  int32_T c1_i122;
  boolean_T c1_h_temp;
  boolean_T c1_sb_out;
  boolean_T c1_tb_out;
  int32_T c1_i123;
  real_T c1_d39;
  int32_T c1_i124;
  boolean_T c1_ub_out;
  boolean_T c1_vb_out;
  int32_T c1_i125;
  boolean_T c1_wb_out;
  boolean_T c1_xb_out;
  int32_T c1_i126;
  real_T c1_d40;
  int32_T c1_i127;
  int32_T c1_i128;
  boolean_T c1_i_temp;
  boolean_T c1_yb_out;
  boolean_T c1_ac_out;
  int32_T c1_i129;
  real_T c1_d41;
  int32_T c1_i130;
  boolean_T c1_bc_out;
  boolean_T c1_cc_out;
  int32_T c1_i131;
  boolean_T c1_dc_out;
  boolean_T c1_ec_out;
  int32_T c1_i132;
  real_T c1_d42;
  int32_T c1_i133;
  int32_T c1_i134;
  boolean_T c1_j_temp;
  boolean_T c1_fc_out;
  boolean_T c1_gc_out;
  int32_T c1_i135;
  real_T c1_d43;
  int32_T c1_i136;
  boolean_T c1_hc_out;
  boolean_T c1_ic_out;
  int32_T c1_i137;
  boolean_T c1_jc_out;
  boolean_T c1_kc_out;
  int32_T c1_i138;
  real_T c1_d44;
  int32_T c1_i139;
  int32_T c1_i140;
  int32_T c1_i141;
  boolean_T c1_k_temp;
  boolean_T c1_lc_out;
  boolean_T c1_mc_out;
  int32_T c1_i142;
  real_T c1_d45;
  int32_T c1_i143;
  boolean_T c1_nc_out;
  boolean_T c1_oc_out;
  int32_T c1_i144;
  boolean_T c1_pc_out;
  boolean_T c1_qc_out;
  int32_T c1_i145;
  real_T c1_d46;
  int32_T c1_i146;
  int32_T c1_i147;
  boolean_T c1_l_temp;
  boolean_T c1_rc_out;
  boolean_T c1_sc_out;
  int32_T c1_i148;
  boolean_T c1_tc_out;
  boolean_T c1_uc_out;
  int32_T c1_i149;
  boolean_T c1_m_temp;
  boolean_T c1_vc_out;
  boolean_T c1_wc_out;
  boolean_T c1_xc_out;
  int32_T c1_i150;
  int32_T c1_i151;
  boolean_T c1_yc_out;
  int32_T c1_i152;
  boolean_T c1_ad_out;
  boolean_T c1_bd_out;
  int32_T c1_i153;
  boolean_T c1_n_temp;
  boolean_T c1_cd_out;
  boolean_T c1_dd_out;
  boolean_T c1_ed_out;
  int32_T c1_i154;
  int32_T c1_i155;
  boolean_T c1_fd_out;
  int32_T c1_i156;
  boolean_T c1_gd_out;
  boolean_T c1_hd_out;
  int32_T c1_i157;
  boolean_T c1_o_temp;
  boolean_T c1_id_out;
  boolean_T c1_jd_out;
  boolean_T c1_kd_out;
  int32_T c1_i158;
  int32_T c1_i159;
  boolean_T c1_p_temp;
  boolean_T c1_ld_out;
  boolean_T c1_md_out;
  int32_T c1_hoistedGlobal;
  real_T c1_a;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_needstop;
  int32_T c1_index;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 0.0;
  int32_T c1_q0;
  int32_T c1_q1;
  int32_T c1_qY;
  int32_T c1_i160;
  int32_T c1_b_index;
  int32_T c1_b_q0;
  int32_T c1_b_q1;
  int32_T c1_b_qY;
  int32_T c1_c_q0;
  int32_T c1_c_q1;
  int32_T c1_c_qY;
  int32_T c1_d_q0;
  int32_T c1_d_q1;
  int32_T c1_d_qY;
  boolean_T c1_q_temp;
  boolean_T c1_nd_out;
  int32_T c1_i161;
  boolean_T c1_od_out;
  boolean_T c1_pd_out;
  uint32_T c1_b_debug_family_var_map[4];
  real_T c1_si;
  int32_T c1_sj;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 0.0;
  int32_T c1_c_index;
  real_T c1_d_index;
  boolean_T c1_qd_out;
  int32_T c1_i162;
  int32_T c1_i163;
  int32_T c1_i164;
  real_T c1_d47;
  int32_T c1_i165;
  boolean_T c1_rd_out;
  int32_T c1_i166;
  real_T c1_d48;
  boolean_T c1_sd_out;
  boolean_T c1_td_out;
  int32_T c1_i167;
  real_T c1_d49;
  int32_T c1_i168;
  boolean_T c1_ud_out;
  boolean_T c1_vd_out;
  boolean_T c1_wd_out;
  int32_T c1_i169;
  real_T c1_d50;
  real_T c1_d51;
  int32_T c1_i170;
  boolean_T c1_xd_out;
  boolean_T c1_yd_out;
  boolean_T c1_ae_out;
  real_T c1_d52;
  boolean_T c1_be_out;
  boolean_T c1_ce_out;
  boolean_T c1_de_out;
  boolean_T c1_ee_out;
  boolean_T c1_fe_out;
  boolean_T c1_ge_out;
  int32_T c1_i171;
  boolean_T c1_he_out;
  boolean_T c1_ie_out;
  real_T c1_d53;
  boolean_T c1_je_out;
  boolean_T c1_ke_out;
  int32_T c1_i172;
  real_T c1_d54;
  boolean_T c1_r_temp;
  boolean_T c1_le_out;
  boolean_T c1_s_temp;
  boolean_T c1_me_out;
  boolean_T c1_t_temp;
  boolean_T c1_u_temp;
  boolean_T c1_v_temp;
  boolean_T c1_ne_out;
  boolean_T c1_w_temp;
  boolean_T c1_oe_out;
  boolean_T c1_x_temp;
  boolean_T c1_y_temp;
  boolean_T c1_ab_temp;
  boolean_T c1_pe_out;
  boolean_T c1_bb_temp;
  boolean_T c1_cb_temp;
  boolean_T c1_db_temp;
  boolean_T c1_qe_out;
  boolean_T c1_re_out;
  int32_T c1_i173;
  boolean_T c1_se_out;
  boolean_T c1_te_out;
  boolean_T c1_ue_out;
  boolean_T c1_ve_out;
  real_T c1_d55;
  boolean_T c1_we_out;
  int32_T c1_i174;
  boolean_T c1_xe_out;
  boolean_T c1_ye_out;
  boolean_T c1_af_out;
  int32_T c1_i175;
  boolean_T c1_bf_out;
  int32_T c1_i176;
  boolean_T c1_cf_out;
  int32_T c1_i177;
  boolean_T c1_df_out;
  boolean_T c1_eb_temp;
  boolean_T c1_ef_out;
  int32_T c1_i178;
  real_T c1_d56;
  int32_T c1_i179;
  real_T c1_d57;
  int32_T c1_i180;
  boolean_T c1_fb_temp;
  boolean_T c1_ff_out;
  int32_T c1_i181;
  real_T c1_d58;
  boolean_T c1_gf_out;
  boolean_T c1_gb_temp;
  boolean_T c1_hf_out;
  boolean_T c1_if_out;
  boolean_T c1_jf_out;
  int32_T c1_i182;
  boolean_T c1_kf_out;
  boolean_T c1_lf_out;
  int32_T c1_i183;
  boolean_T c1_mf_out;
  boolean_T c1_nf_out;
  boolean_T c1_of_out;
  int32_T c1_i184;
  boolean_T c1_pf_out;
  int32_T c1_i185;
  boolean_T c1_qf_out;
  int32_T c1_i186;
  boolean_T c1_rf_out;
  boolean_T c1_hb_temp;
  boolean_T c1_sf_out;
  int32_T c1_i187;
  real_T c1_d59;
  int32_T c1_i188;
  real_T c1_d60;
  int32_T c1_i189;
  boolean_T c1_ib_temp;
  boolean_T c1_tf_out;
  int32_T c1_i190;
  real_T c1_d61;
  boolean_T c1_uf_out;
  boolean_T c1_jb_temp;
  boolean_T c1_vf_out;
  boolean_T c1_wf_out;
  boolean_T c1_xf_out;
  int32_T c1_i191;
  boolean_T c1_yf_out;
  boolean_T c1_ag_out;
  int32_T c1_i192;
  boolean_T c1_bg_out;
  boolean_T c1_cg_out;
  boolean_T c1_dg_out;
  int32_T c1_i193;
  boolean_T c1_eg_out;
  int32_T c1_i194;
  boolean_T c1_fg_out;
  int32_T c1_i195;
  boolean_T c1_gg_out;
  boolean_T c1_kb_temp;
  boolean_T c1_hg_out;
  int32_T c1_i196;
  real_T c1_d62;
  int32_T c1_i197;
  real_T c1_d63;
  int32_T c1_i198;
  boolean_T c1_lb_temp;
  boolean_T c1_ig_out;
  int32_T c1_i199;
  real_T c1_d64;
  boolean_T c1_jg_out;
  boolean_T c1_mb_temp;
  boolean_T c1_kg_out;
  boolean_T c1_lg_out;
  boolean_T c1_mg_out;
  int32_T c1_i200;
  boolean_T c1_ng_out;
  boolean_T c1_og_out;
  int32_T c1_i201;
  int32_T c1_i202;
  int32_T c1_i203;
  real_T c1_d65;
  int32_T c1_i204;
  boolean_T c1_pg_out;
  int32_T c1_i205;
  real_T c1_d66;
  boolean_T c1_qg_out;
  boolean_T c1_rg_out;
  int32_T c1_i206;
  real_T c1_d67;
  int32_T c1_i207;
  boolean_T c1_sg_out;
  boolean_T c1_tg_out;
  boolean_T c1_ug_out;
  int32_T c1_i208;
  real_T c1_d68;
  real_T c1_d69;
  int32_T c1_i209;
  boolean_T c1_vg_out;
  boolean_T c1_wg_out;
  boolean_T c1_xg_out;
  real_T c1_d70;
  boolean_T c1_yg_out;
  boolean_T c1_ah_out;
  boolean_T c1_bh_out;
  boolean_T c1_ch_out;
  boolean_T c1_dh_out;
  boolean_T c1_eh_out;
  int32_T c1_i210;
  boolean_T c1_fh_out;
  boolean_T c1_gh_out;
  real_T c1_d71;
  boolean_T c1_hh_out;
  boolean_T c1_ih_out;
  int32_T c1_i211;
  real_T c1_d72;
  boolean_T c1_nb_temp;
  boolean_T c1_jh_out;
  boolean_T c1_ob_temp;
  boolean_T c1_kh_out;
  boolean_T c1_pb_temp;
  boolean_T c1_qb_temp;
  boolean_T c1_rb_temp;
  boolean_T c1_lh_out;
  boolean_T c1_sb_temp;
  boolean_T c1_mh_out;
  boolean_T c1_tb_temp;
  boolean_T c1_ub_temp;
  boolean_T c1_vb_temp;
  boolean_T c1_nh_out;
  boolean_T c1_wb_temp;
  boolean_T c1_xb_temp;
  boolean_T c1_yb_temp;
  boolean_T c1_oh_out;
  boolean_T c1_ph_out;
  int32_T c1_i212;
  boolean_T c1_qh_out;
  boolean_T c1_rh_out;
  boolean_T c1_sh_out;
  boolean_T c1_th_out;
  real_T c1_d73;
  boolean_T c1_uh_out;
  int32_T c1_i213;
  int32_T c1_i214;
  int32_T c1_i215;
  real_T c1_d74;
  int32_T c1_i216;
  boolean_T c1_vh_out;
  int32_T c1_i217;
  real_T c1_d75;
  boolean_T c1_wh_out;
  boolean_T c1_xh_out;
  int32_T c1_i218;
  real_T c1_d76;
  int32_T c1_i219;
  boolean_T c1_yh_out;
  boolean_T c1_ai_out;
  boolean_T c1_bi_out;
  int32_T c1_i220;
  real_T c1_d77;
  real_T c1_d78;
  int32_T c1_i221;
  boolean_T c1_ci_out;
  boolean_T c1_di_out;
  boolean_T c1_ei_out;
  real_T c1_d79;
  boolean_T c1_fi_out;
  boolean_T c1_gi_out;
  boolean_T c1_hi_out;
  boolean_T c1_ii_out;
  boolean_T c1_ji_out;
  boolean_T c1_ki_out;
  int32_T c1_i222;
  boolean_T c1_li_out;
  boolean_T c1_mi_out;
  real_T c1_d80;
  boolean_T c1_ni_out;
  boolean_T c1_oi_out;
  int32_T c1_i223;
  real_T c1_d81;
  boolean_T c1_ac_temp;
  boolean_T c1_pi_out;
  boolean_T c1_bc_temp;
  boolean_T c1_qi_out;
  boolean_T c1_cc_temp;
  boolean_T c1_dc_temp;
  boolean_T c1_ec_temp;
  boolean_T c1_ri_out;
  boolean_T c1_fc_temp;
  boolean_T c1_si_out;
  boolean_T c1_gc_temp;
  boolean_T c1_hc_temp;
  boolean_T c1_ic_temp;
  boolean_T c1_ti_out;
  boolean_T c1_jc_temp;
  boolean_T c1_kc_temp;
  boolean_T c1_lc_temp;
  boolean_T c1_ui_out;
  boolean_T c1_vi_out;
  int32_T c1_i224;
  boolean_T c1_wi_out;
  boolean_T c1_xi_out;
  boolean_T c1_yi_out;
  boolean_T c1_aj_out;
  real_T c1_d82;
  boolean_T c1_bj_out;
  int32_T c1_i225;
  int32_T c1_i226;
  int32_T c1_i227;
  real_T c1_d83;
  int32_T c1_i228;
  boolean_T c1_cj_out;
  int32_T c1_i229;
  real_T c1_d84;
  boolean_T c1_dj_out;
  boolean_T c1_ej_out;
  int32_T c1_i230;
  real_T c1_d85;
  int32_T c1_i231;
  boolean_T c1_fj_out;
  boolean_T c1_gj_out;
  boolean_T c1_hj_out;
  int32_T c1_i232;
  real_T c1_d86;
  real_T c1_d87;
  int32_T c1_i233;
  boolean_T c1_ij_out;
  boolean_T c1_jj_out;
  boolean_T c1_kj_out;
  real_T c1_d88;
  boolean_T c1_lj_out;
  boolean_T c1_mj_out;
  boolean_T c1_nj_out;
  boolean_T c1_oj_out;
  boolean_T c1_pj_out;
  boolean_T c1_qj_out;
  int32_T c1_i234;
  boolean_T c1_rj_out;
  boolean_T c1_sj_out;
  real_T c1_d89;
  boolean_T c1_tj_out;
  boolean_T c1_uj_out;
  int32_T c1_i235;
  real_T c1_d90;
  boolean_T c1_mc_temp;
  boolean_T c1_vj_out;
  boolean_T c1_nc_temp;
  boolean_T c1_wj_out;
  boolean_T c1_oc_temp;
  boolean_T c1_pc_temp;
  boolean_T c1_qc_temp;
  boolean_T c1_xj_out;
  boolean_T c1_rc_temp;
  boolean_T c1_yj_out;
  boolean_T c1_sc_temp;
  boolean_T c1_tc_temp;
  boolean_T c1_uc_temp;
  boolean_T c1_ak_out;
  boolean_T c1_vc_temp;
  boolean_T c1_wc_temp;
  boolean_T c1_xc_temp;
  boolean_T c1_bk_out;
  boolean_T c1_ck_out;
  int32_T c1_i236;
  boolean_T c1_dk_out;
  boolean_T c1_ek_out;
  boolean_T c1_fk_out;
  boolean_T c1_gk_out;
  real_T c1_d91;
  int32_T c1_i237;
  int32_T c1_i238;
  int32_T c1_i239;
  int32_T c1_i240;
  int32_T c1_i241;
  int32_T c1_i242;
  int32_T c1_i243;
  int32_T c1_i244;
  int32_T c1_i245;
  int32_T c1_i246;
  int32_T c1_i247;
  int32_T c1_i248;
  int32_T c1_i249;
  int32_T c1_i250;
  int32_T c1_i251;
  int32_T c1_i252;
  int32_T c1_i253;
  int32_T c1_i254;
  int32_T c1_i255;
  int32_T c1_i256;
  int32_T c1_i257;
  int32_T c1_i258;
  int32_T c1_i259;
  int32_T c1_i260;
  int32_T c1_i261;
  int32_T c1_i262;
  int32_T c1_i263;
  int32_T c1_i264;
  int32_T c1_i265;
  int32_T c1_i266;
  int32_T c1_i267;
  int32_T c1_i268;
  int32_T c1_i269;
  int32_T c1_i270;
  int32_T c1_i271;
  int32_T c1_i272;
  int32_T c1_i273;
  int32_T c1_i274;
  int32_T c1_i275;
  int32_T c1_i276;
  int32_T c1_i277;
  int32_T c1_i278;
  int32_T c1_i279;
  int32_T c1_i280;
  int32_T c1_i281;
  int32_T c1_i282;
  int32_T c1_i283;
  int32_T c1_i284;
  int32_T c1_i285;
  int32_T c1_i286;
  int32_T c1_i287;
  int32_T c1_i288;
  int32_T c1_i289;
  int32_T c1_i290;
  int32_T c1_i291;
  int32_T c1_i292;
  int32_T c1_i293;
  int32_T c1_i294;
  int32_T c1_i295;
  int32_T c1_i296;
  int32_T c1_i297;
  int32_T c1_i298;
  int32_T c1_i299;
  int32_T c1_i300;
  real_T *c1_lastMajorTime;
  boolean_T *c1_stateChanged;
  int32_T *c1_sfEvent;
  int32_T *c1_N;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  uint8_T *c1_is_Train0_door;
  real_T *c1_y1;
  uint8_T *c1_is_Screen_door00;
  real_T *c1_y2;
  uint8_T *c1_is_Controller0;
  real_T *c1_z;
  int32_T *c1_i;
  real_T *c1_stationid;
  real_T *c1_side;
  real_T *c1_j;
  real_T *c1_distance;
  uint8_T *c1_is_Screen_door01;
  real_T *c1_b_y2;
  uint8_T *c1_is_Screen_door10;
  real_T *c1_c_y2;
  uint8_T *c1_is_Screen_door11;
  real_T *c1_d_y2;
  uint8_T *c1_is_Screen_door20;
  real_T *c1_e_y2;
  uint8_T *c1_is_Screen_door21;
  real_T *c1_f_y2;
  uint8_T *c1_is_Screen_door30;
  real_T *c1_g_y2;
  uint8_T *c1_is_Screen_door31;
  real_T *c1_h_y2;
  uint8_T *c1_is_Train1_door;
  real_T *c1_b_y1;
  uint8_T *c1_is_Train2_door;
  real_T *c1_c_y1;
  uint8_T *c1_is_Train3_door;
  real_T *c1_d_y1;
  uint8_T *c1_is_UrgentController;
  int32_T *c1_b_i;
  real_T *c1_t;
  int32_T *c1_dis;
  int32_T *c1_tdis;
  uint8_T *c1_is_Train3;
  real_T *c1_time;
  int32_T *c1_c_i;
  real_T *c1_v;
  real_T *c1_b_j;
  real_T *c1_b_distance;
  real_T *c1_acc;
  real_T *c1_maxv;
  uint8_T *c1_is_Controller1;
  real_T *c1_b_z;
  int32_T *c1_d_i;
  real_T *c1_b_stationid;
  real_T *c1_b_side;
  real_T *c1_c_j;
  real_T *c1_c_distance;
  uint8_T *c1_is_Controller2;
  real_T *c1_c_z;
  int32_T *c1_e_i;
  real_T *c1_c_stationid;
  real_T *c1_c_side;
  real_T *c1_d_j;
  real_T *c1_d_distance;
  uint8_T *c1_is_Controller3;
  real_T *c1_d_z;
  int32_T *c1_f_i;
  real_T *c1_d_stationid;
  real_T *c1_d_side;
  uint8_T *c1_is_Train0;
  real_T *c1_b_time;
  int32_T *c1_g_i;
  real_T *c1_b_v;
  real_T *c1_b_acc;
  real_T *c1_b_maxv;
  uint8_T *c1_is_Train1;
  real_T *c1_c_time;
  int32_T *c1_h_i;
  real_T *c1_c_v;
  real_T *c1_c_acc;
  real_T *c1_c_maxv;
  uint8_T *c1_is_Train2;
  real_T *c1_d_time;
  int32_T *c1_i_i;
  real_T *c1_d_v;
  real_T *c1_d_acc;
  real_T *c1_d_maxv;
  uint8_T *c1_is_active_Train0_door;
  uint8_T *c1_is_active_Screen_door00;
  uint8_T *c1_is_active_Controller0;
  uint8_T *c1_is_active_Screen_door01;
  uint8_T *c1_is_active_Screen_door10;
  uint8_T *c1_is_active_Screen_door11;
  uint8_T *c1_is_active_Screen_door20;
  uint8_T *c1_is_active_Screen_door21;
  uint8_T *c1_is_active_Screen_door30;
  uint8_T *c1_is_active_Screen_door31;
  uint8_T *c1_is_active_Train1_door;
  uint8_T *c1_is_active_Train2_door;
  uint8_T *c1_is_active_Train3_door;
  uint8_T *c1_is_active_UrgentController;
  uint8_T *c1_is_active_Train3;
  uint8_T *c1_is_active_Controller1;
  uint8_T *c1_is_active_Controller2;
  uint8_T *c1_is_active_Controller3;
  uint8_T *c1_is_active_Train0;
  uint8_T *c1_is_active_Train1;
  uint8_T *c1_is_active_Train2;
  real_T (*c1_y2_out)[8];
  real_T (*c1_openTD)[4];
  real_T (*c1_y1_out)[4];
  real_T (*c1_closeTD)[4];
  real_T (*c1_PSDClosed)[8];
  real_T (*c1_openPSD)[8];
  real_T (*c1_closePSD)[8];
  real_T (*c1_position)[4];
  real_T (*c1_stop)[4];
  real_T (*c1_start)[4];
  real_T (*c1_urstop)[4];
  int32_T (*c1_RelevantIndex)[4];
  int32_T (*c1_dir)[4];
  real_T (*c1_urstart)[4];
  real_T (*c1_urstopped)[4];
  real_T (*c1_distance_out)[4];
  real_T (*c1_v_shutTD)[4];
  real_T (*c1_v_shutPSD)[8];
  real_T (*c1_Delay)[4];
  real_T (*c1_S)[4];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
  c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
  c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 90);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
  c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
  c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 86);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
  c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 84);
  c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
  c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
  c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
  c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 81);
  c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
  c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
  c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
  c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
  c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 76);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
  c1_side = (real_T *)ssGetDWork(chartInstance->S, 74);
  c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
  c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
  c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
  c1_j = (real_T *)ssGetDWork(chartInstance->S, 69);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
  c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 67);
  c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
  c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_dis = (int32_T *)ssGetDWork(chartInstance->S, 65);
  c1_tdis = (int32_T *)ssGetDWork(chartInstance->S, 64);
  c1_RelevantIndex = (int32_T (*)[4])ssGetDWork(chartInstance->S, 63);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
  c1_position = (real_T (*)[4])ssGetDWork(chartInstance->S, 60);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_urstopped = (real_T (*)[4])ssGetDWork(chartInstance->S, 58);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
  c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
  c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
  c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
  c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
  c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
  c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
  c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
  c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
  c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
  c1_v_shutPSD = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c1_v_shutTD = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_is_active_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 46);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_active_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 44);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_active_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 42);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_active_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 40);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_active_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 38);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_active_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 36);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_active_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 34);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_active_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 32);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_active_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 30);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_active_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 28);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_active_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 26);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_active_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 24);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_active_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 22);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_active_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 20);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_active_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 18);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_active_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 16);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_active_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 14);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_active_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 12);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_active_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 10);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_active_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 8);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_active_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 6);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_lastMajorTime = (real_T *)ssGetDWork(chartInstance->S, 3);
  c1_stateChanged = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_subwaycontrolsystem(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (ssIsMajorTimeStep(chartInstance->S) != 0) {
    *c1_lastMajorTime = _sfTime_;
    *c1_stateChanged = FALSE;
    _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
    for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
      _SFD_DATA_RANGE_CHECK((*c1_v_shutTD)[c1_i14], 0U);
    }

    for (c1_i15 = 0; c1_i15 < 8; c1_i15++) {
      _SFD_DATA_RANGE_CHECK((*c1_v_shutPSD)[c1_i15], 1U);
    }

    for (c1_i16 = 0; c1_i16 < 4; c1_i16++) {
      _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i16], 2U);
    }

    for (c1_i17 = 0; c1_i17 < 4; c1_i17++) {
      _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i17], 3U);
    }

    for (c1_i18 = 0; c1_i18 < 8; c1_i18++) {
      _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i18], 4U);
    }

    for (c1_i19 = 0; c1_i19 < 8; c1_i19++) {
      _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i19], 5U);
    }

    for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i20], 6U);
    }

    for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
      _SFD_DATA_RANGE_CHECK((*c1_Delay)[c1_i21], 7U);
    }

    for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
      _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i22], 8U);
    }

    for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
      _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i23], 9U);
    }

    for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
      _SFD_DATA_RANGE_CHECK((*c1_S)[c1_i24], 10U);
    }

    for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
      _SFD_DATA_RANGE_CHECK((*c1_urstart)[c1_i25], 11U);
    }

    for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
      _SFD_DATA_RANGE_CHECK((*c1_urstop)[c1_i26], 12U);
    }

    _SFD_DATA_RANGE_CHECK((real_T)*c1_N, 13U);
    for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i27], 14U);
    }

    for (c1_i28 = 0; c1_i28 < 8; c1_i28++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i28], 15U);
    }

    for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
      _SFD_DATA_RANGE_CHECK((*c1_urstopped)[c1_i29], 16U);
    }

    for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i30], 17U);
    }

    for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
      _SFD_DATA_RANGE_CHECK((*c1_position)[c1_i31], 18U);
    }

    for (c1_i32 = 0; c1_i32 < 8; c1_i32++) {
      _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i32], 19U);
    }

    *c1_sfEvent = CALL_EVENT;
    _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
    if (*c1_is_active_c1_subwaycontrolsystem == 0U) {
      _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_active_c1_subwaycontrolsystem = 1U;
      _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_active_Train0_door = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *c1_sfEvent);
      *c1_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_y1, 41U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Train0_door = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 90U, *c1_sfEvent);
      *c1_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_y1, 41U);
      (*c1_y1_out)[0] = *c1_y1;
      for (c1_i33 = 0; c1_i33 < 4; c1_i33++) {
        _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i33], 14U);
      }

      (*c1_closeTD)[0] = 0.0;
      for (c1_i34 = 0; c1_i34 < 4; c1_i34++) {
        _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i34], 9U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door00 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *c1_sfEvent);
      *c1_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_y2, 77U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *c1_sfEvent);
      (*c1_PSDClosed)[0] = 1.0;
      for (c1_i35 = 0; c1_i35 < 8; c1_i35++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i35], 19U);
      }

      c1_d0 = (*c1_PSDClosed)[0];
      sf_mex_printf("%s =\\n", "PSDClosed[0][0]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d0);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door00 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *c1_sfEvent);
      *c1_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_y2, 77U);
      (*c1_y2_out)[0] = *c1_y2;
      for (c1_i36 = 0; c1_i36 < 8; c1_i36++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i36], 15U);
      }

      (*c1_closePSD)[0] = 0.0;
      for (c1_i37 = 0; c1_i37 < 8; c1_i37++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i37], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Controller0 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
      *c1_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
      *c1_stationid = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_stationid, 38U);
      *c1_side = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_side, 39U);
      *c1_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_i, 40U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Controller0 = c1_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *c1_sfEvent);
      *c1_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door01 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *c1_sfEvent);
      *c1_b_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_y2, 76U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, *c1_sfEvent);
      (*c1_PSDClosed)[4] = 1.0;
      for (c1_i38 = 0; c1_i38 < 8; c1_i38++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i38], 19U);
      }

      c1_d1 = (*c1_PSDClosed)[4];
      sf_mex_printf("%s =\\n", "PSDClosed[0][1]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d1);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door01 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *c1_sfEvent);
      *c1_b_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_y2, 76U);
      (*c1_y2_out)[4] = *c1_b_y2;
      for (c1_i39 = 0; c1_i39 < 8; c1_i39++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i39], 15U);
      }

      (*c1_closePSD)[4] = 0.0;
      for (c1_i40 = 0; c1_i40 < 8; c1_i40++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i40], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door10 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *c1_sfEvent);
      *c1_c_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_y2, 74U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, *c1_sfEvent);
      (*c1_PSDClosed)[1] = 1.0;
      for (c1_i41 = 0; c1_i41 < 8; c1_i41++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i41], 19U);
      }

      c1_d2 = (*c1_PSDClosed)[1];
      sf_mex_printf("%s =\\n", "PSDClosed[1][0]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d2);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door10 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *c1_sfEvent);
      *c1_c_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_y2, 74U);
      (*c1_y2_out)[1] = *c1_c_y2;
      for (c1_i42 = 0; c1_i42 < 8; c1_i42++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i42], 15U);
      }

      (*c1_closePSD)[1] = 0.0;
      for (c1_i43 = 0; c1_i43 < 8; c1_i43++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i43], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door11 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *c1_sfEvent);
      *c1_d_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_y2, 75U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, *c1_sfEvent);
      (*c1_PSDClosed)[5] = 1.0;
      for (c1_i44 = 0; c1_i44 < 8; c1_i44++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i44], 19U);
      }

      c1_d3 = (*c1_PSDClosed)[5];
      sf_mex_printf("%s =\\n", "PSDClosed[1][1]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d3);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door11 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *c1_sfEvent);
      *c1_d_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_y2, 75U);
      (*c1_y2_out)[5] = *c1_d_y2;
      for (c1_i45 = 0; c1_i45 < 8; c1_i45++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i45], 15U);
      }

      (*c1_closePSD)[5] = 0.0;
      for (c1_i46 = 0; c1_i46 < 8; c1_i46++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i46], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door20 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *c1_sfEvent);
      *c1_e_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_e_y2, 81U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, *c1_sfEvent);
      (*c1_PSDClosed)[2] = 1.0;
      for (c1_i47 = 0; c1_i47 < 8; c1_i47++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i47], 19U);
      }

      c1_d4 = (*c1_PSDClosed)[2];
      sf_mex_printf("%s =\\n", "PSDClosed[2][0]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d4);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door20 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *c1_sfEvent);
      *c1_e_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_e_y2, 81U);
      (*c1_y2_out)[2] = *c1_e_y2;
      for (c1_i48 = 0; c1_i48 < 8; c1_i48++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i48], 15U);
      }

      (*c1_closePSD)[2] = 0.0;
      for (c1_i49 = 0; c1_i49 < 8; c1_i49++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i49], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door21 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *c1_sfEvent);
      *c1_f_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_f_y2, 80U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, *c1_sfEvent);
      (*c1_PSDClosed)[6] = 1.0;
      for (c1_i50 = 0; c1_i50 < 8; c1_i50++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i50], 19U);
      }

      c1_d5 = (*c1_PSDClosed)[6];
      sf_mex_printf("%s =\\n", "PSDClosed[2][1]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d5);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door21 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *c1_sfEvent);
      *c1_f_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_f_y2, 80U);
      (*c1_y2_out)[6] = *c1_f_y2;
      for (c1_i51 = 0; c1_i51 < 8; c1_i51++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i51], 15U);
      }

      (*c1_closePSD)[6] = 0.0;
      for (c1_i52 = 0; c1_i52 < 8; c1_i52++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i52], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door30 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, *c1_sfEvent);
      *c1_g_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_g_y2, 78U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, *c1_sfEvent);
      (*c1_PSDClosed)[3] = 1.0;
      for (c1_i53 = 0; c1_i53 < 8; c1_i53++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i53], 19U);
      }

      c1_d6 = (*c1_PSDClosed)[3];
      sf_mex_printf("%s =\\n", "PSDClosed[3][0]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d6);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door30 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, *c1_sfEvent);
      *c1_g_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_g_y2, 78U);
      for (c1_i54 = 0; c1_i54 < 8; c1_i54++) {
        (*c1_y2_out)[c1_i54] = *c1_g_y2;
      }

      for (c1_i55 = 0; c1_i55 < 8; c1_i55++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i55], 15U);
      }

      (*c1_closePSD)[3] = 0.0;
      for (c1_i56 = 0; c1_i56 < 8; c1_i56++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i56], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Screen_door31 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, *c1_sfEvent);
      *c1_h_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_h_y2, 79U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, *c1_sfEvent);
      (*c1_PSDClosed)[7] = 1.0;
      for (c1_i57 = 0; c1_i57 < 8; c1_i57++) {
        _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i57], 19U);
      }

      c1_d7 = (*c1_PSDClosed)[7];
      sf_mex_printf("%s =\\n", "PSDClosed[3][1]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d7);
      *c1_stateChanged = TRUE;
      *c1_is_Screen_door31 = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, *c1_sfEvent);
      *c1_h_y2 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_h_y2, 79U);
      (*c1_y2_out)[7] = *c1_h_y2;
      for (c1_i58 = 0; c1_i58 < 8; c1_i58++) {
        _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i58], 15U);
      }

      (*c1_closePSD)[7] = 0.0;
      for (c1_i59 = 0; c1_i59 < 8; c1_i59++) {
        _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i59], 5U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Train1_door = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 107U, *c1_sfEvent);
      *c1_b_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_y1, 42U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Train1_door = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 108U, *c1_sfEvent);
      *c1_b_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_y1, 42U);
      (*c1_y1_out)[1] = *c1_b_y1;
      for (c1_i60 = 0; c1_i60 < 4; c1_i60++) {
        _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i60], 14U);
      }

      (*c1_closeTD)[1] = 0.0;
      for (c1_i61 = 0; c1_i61 < 4; c1_i61++) {
        _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i61], 9U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Train2_door = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 125U, *c1_sfEvent);
      *c1_c_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_y1, 65U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Train2_door = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 126U, *c1_sfEvent);
      *c1_c_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_y1, 65U);
      (*c1_y1_out)[2] = *c1_c_y1;
      for (c1_i62 = 0; c1_i62 < 4; c1_i62++) {
        _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i62], 14U);
      }

      (*c1_closeTD)[2] = 0.0;
      for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
        _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i63], 9U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_Train3_door = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 143U, *c1_sfEvent);
      *c1_d_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_y1, 73U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Train3_door = c1_IN_closed;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 144U, *c1_sfEvent);
      *c1_d_y1 = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_y1, 73U);
      (*c1_y1_out)[3] = *c1_d_y1;
      for (c1_i64 = 0; c1_i64 < 4; c1_i64++) {
        _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i64], 14U);
      }

      (*c1_closeTD)[3] = 0.0;
      for (c1_i65 = 0; c1_i65 < 4; c1_i65++) {
        _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i65], 9U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_active_UrgentController = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 148U, *c1_sfEvent);
      *c1_t = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
      *c1_b_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_b_i, 21U);
      (*c1_RelevantIndex)[0] = -1;
      for (c1_i66 = 0; c1_i66 < 4; c1_i66++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_RelevantIndex)[c1_i66], 22U);
      }

      (*c1_RelevantIndex)[1] = -1;
      for (c1_i67 = 0; c1_i67 < 4; c1_i67++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_RelevantIndex)[c1_i67], 22U);
      }

      (*c1_RelevantIndex)[2] = -1;
      for (c1_i68 = 0; c1_i68 < 4; c1_i68++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_RelevantIndex)[c1_i68], 22U);
      }

      (*c1_RelevantIndex)[3] = -1;
      for (c1_i69 = 0; c1_i69 < 4; c1_i69++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_RelevantIndex)[c1_i69], 22U);
      }

      *c1_tdis = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_tdis, 23U);
      *c1_dis = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_dis, 24U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_UrgentController = c1_IN_Delay;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 151U, *c1_sfEvent);
      *c1_t = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
      *c1_stateChanged = TRUE;
      *c1_is_active_Train3 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 130U, *c1_sfEvent);
      *c1_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
      *c1_b_j = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_j, 67U);
      *c1_maxv = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_maxv, 68U);
      *c1_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_time, 69U);
      *c1_c_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_i, 70U);
      *c1_b_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_distance, 71U);
      *c1_acc = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_acc, 72U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 87U, *c1_sfEvent);
      *c1_c_i = 3;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_c_i, 70U);
      c1_i70 = *c1_c_i;
      sf_mex_printf("%s =\\n", "i");
      sf_mex_call_debug("disp", 0U, 1U, 12, c1_i70);
      (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] = 0.0;
      for (c1_i71 = 0; c1_i71 < 4; c1_i71++) {
        _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i71], 2U);
      }

      c1_d8 = (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)];
      sf_mex_printf("%s =\\n", "start[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d8);
      (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 0.0;
      for (c1_i72 = 0; c1_i72 < 4; c1_i72++) {
        _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i72], 3U);
      }

      c1_d9 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
      sf_mex_printf("%s =\\n", "stop[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d9);
      *c1_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_time, 69U);
      c1_d10 = *c1_time;
      sf_mex_printf("%s =\\n", "time");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d10);
      *c1_b_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_distance, 71U);
      c1_d11 = *c1_b_distance;
      sf_mex_printf("%s =\\n", "distance");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d11);
      *c1_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
      c1_d12 = *c1_v;
      sf_mex_printf("%s =\\n", "v");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d12);
      (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] = 1;
      for (c1_i73 = 0; c1_i73 < 4; c1_i73++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i73], 17U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_Train3 = c1_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 132U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_active_Controller1 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *c1_sfEvent);
      *c1_b_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
      *c1_b_stationid = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_stationid, 27U);
      *c1_b_side = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_side, 28U);
      *c1_d_i = 1;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_d_i, 29U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 111U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Controller1 = c1_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *c1_sfEvent);
      *c1_b_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
      *c1_stateChanged = TRUE;
      *c1_is_active_Controller2 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *c1_sfEvent);
      *c1_c_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
      *c1_c_stationid = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_stationid, 55U);
      *c1_c_side = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_side, 56U);
      *c1_e_i = 2;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_e_i, 57U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 122U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Controller2 = c1_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *c1_sfEvent);
      *c1_c_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
      *c1_stateChanged = TRUE;
      *c1_is_active_Controller3 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *c1_sfEvent);
      *c1_d_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
      *c1_d_stationid = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_stationid, 51U);
      *c1_d_side = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_side, 52U);
      *c1_f_i = 3;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_f_i, 53U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 133U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_Controller3 = c1_IN_idle;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *c1_sfEvent);
      *c1_d_z = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
      *c1_stateChanged = TRUE;
      *c1_is_active_Train0 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 76U, *c1_sfEvent);
      *c1_b_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
      *c1_j = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_j, 31U);
      *c1_b_maxv = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_maxv, 32U);
      *c1_b_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_time, 33U);
      *c1_g_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_g_i, 34U);
      *c1_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_distance, 35U);
      *c1_b_acc = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_acc, 36U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 150U, *c1_sfEvent);
      *c1_g_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_g_i, 34U);
      c1_i74 = *c1_g_i;
      sf_mex_printf("%s =\\n", "i");
      sf_mex_call_debug("disp", 0U, 1U, 12, c1_i74);
      (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)] = 0.0;
      for (c1_i75 = 0; c1_i75 < 4; c1_i75++) {
        _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i75], 2U);
      }

      c1_d13 = (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)];
      sf_mex_printf("%s =\\n", "start[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d13);
      (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 0.0;
      for (c1_i76 = 0; c1_i76 < 4; c1_i76++) {
        _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i76], 3U);
      }

      c1_d14 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
      sf_mex_printf("%s =\\n", "stop[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d14);
      *c1_b_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_time, 33U);
      c1_d15 = *c1_b_time;
      sf_mex_printf("%s =\\n", "time");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d15);
      *c1_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_distance, 35U);
      c1_d16 = *c1_distance;
      sf_mex_printf("%s =\\n", "distance");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d16);
      *c1_b_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
      c1_d17 = *c1_b_v;
      sf_mex_printf("%s =\\n", "v");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d17);
      (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] = 1;
      for (c1_i77 = 0; c1_i77 < 4; c1_i77++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i77], 17U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_Train0 = c1_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 78U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_active_Train1 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 94U, *c1_sfEvent);
      *c1_c_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
      *c1_c_j = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_j, 44U);
      *c1_c_maxv = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_maxv, 45U);
      *c1_c_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_time, 46U);
      *c1_h_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_h_i, 47U);
      *c1_c_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_distance, 48U);
      *c1_c_acc = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_acc, 49U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 174U, *c1_sfEvent);
      *c1_h_i = 1;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_h_i, 47U);
      c1_i78 = *c1_h_i;
      sf_mex_printf("%s =\\n", "i");
      sf_mex_call_debug("disp", 0U, 1U, 12, c1_i78);
      (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)] = 0.0;
      for (c1_i79 = 0; c1_i79 < 4; c1_i79++) {
        _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i79], 2U);
      }

      c1_d18 = (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)];
      sf_mex_printf("%s =\\n", "start[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d18);
      (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 0.0;
      for (c1_i80 = 0; c1_i80 < 4; c1_i80++) {
        _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i80], 3U);
      }

      c1_d19 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
      sf_mex_printf("%s =\\n", "stop[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d19);
      *c1_c_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_time, 46U);
      c1_d20 = *c1_c_time;
      sf_mex_printf("%s =\\n", "time");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d20);
      *c1_c_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_distance, 48U);
      c1_d21 = *c1_c_distance;
      sf_mex_printf("%s =\\n", "distance");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d21);
      *c1_c_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
      c1_d22 = *c1_c_v;
      sf_mex_printf("%s =\\n", "v");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d22);
      (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] = 1;
      for (c1_i81 = 0; c1_i81 < 4; c1_i81++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i81], 17U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_Train1 = c1_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 96U, *c1_sfEvent);
      *c1_stateChanged = TRUE;
      *c1_is_active_Train2 = 1U;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 112U, *c1_sfEvent);
      *c1_d_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
      *c1_d_j = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_j, 59U);
      *c1_d_maxv = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_maxv, 60U);
      *c1_d_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_time, 61U);
      *c1_i_i = 0;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_i_i, 62U);
      *c1_d_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_distance, 63U);
      *c1_d_acc = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_acc, 64U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 198U, *c1_sfEvent);
      *c1_i_i = 2;
      _SFD_DATA_RANGE_CHECK((real_T)*c1_i_i, 62U);
      c1_i82 = *c1_i_i;
      sf_mex_printf("%s =\\n", "i");
      sf_mex_call_debug("disp", 0U, 1U, 12, c1_i82);
      (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)] = 0.0;
      for (c1_i83 = 0; c1_i83 < 4; c1_i83++) {
        _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i83], 2U);
      }

      c1_d23 = (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)];
      sf_mex_printf("%s =\\n", "start[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d23);
      (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 0.0;
      for (c1_i84 = 0; c1_i84 < 4; c1_i84++) {
        _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i84], 3U);
      }

      c1_d24 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
      sf_mex_printf("%s =\\n", "stop[i]");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d24);
      *c1_d_time = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_time, 61U);
      c1_d25 = *c1_d_time;
      sf_mex_printf("%s =\\n", "time");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d25);
      *c1_d_distance = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_distance, 63U);
      c1_d26 = *c1_d_distance;
      sf_mex_printf("%s =\\n", "distance");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d26);
      *c1_d_v = 0.0;
      _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
      c1_d27 = *c1_d_v;
      sf_mex_printf("%s =\\n", "v");
      sf_mex_call_debug("disp", 0U, 1U, 6, c1_d27);
      (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] = 1;
      for (c1_i85 = 0; c1_i85 < 4; c1_i85++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i85], 17U);
      }

      *c1_stateChanged = TRUE;
      *c1_is_Train2 = c1_IN_init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 114U, *c1_sfEvent);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 89U, *c1_sfEvent);
      switch (*c1_is_Train0_door) {
       case c1_IN_closed:
        CV_STATE_EVAL(89, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 90U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, *c1_sfEvent);
        c1_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                    (*c1_openTD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *c1_sfEvent);
          *c1_is_Train0_door = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 3U, *c1_sfEvent);
          (*c1_openTD)[0] = 0.0;
          for (c1_i86 = 0; c1_i86 < 4; c1_i86++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i86], 8U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Train0_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 92U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 90U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(89, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 91U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *c1_sfEvent);
        c1_b_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
          (*c1_closeTD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 91U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0_door = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 93U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 91U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(89, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 92U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, *c1_sfEvent);
        c1_c_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0, *c1_y1 >=
          2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 92U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0_door = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 91U, *c1_sfEvent);
          *c1_y1 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_y1, 41U);
          (*c1_y1_out)[0] = *c1_y1;
          for (c1_i87 = 0; c1_i87 < 4; c1_i87++) {
            _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i87], 14U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 92U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(89, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 93U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *c1_sfEvent);
        c1_temp = (_SFD_CCP_CALL(2U, 0, *c1_y1 > 0.0 != 0U, *c1_sfEvent) != 0);
        if (c1_temp) {
          c1_temp = (_SFD_CCP_CALL(2U, 1, (*c1_v_shutTD)[0] == 0.0 != 0U,
                      *c1_sfEvent) != 0);
        }

        c1_d_out = (CV_TRANSITION_EVAL(2U, (int32_T)c1_temp) != 0);
        if (c1_d_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 2;
            sf_debug_transition_conflict_check_begin();
            c1_e_out = (*c1_y1 <= 0.0);
            if (c1_e_out) {
              transitionList[numTransitions] = 1;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 93U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 92U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *c1_sfEvent);
          c1_f_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
            *c1_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 93U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0_door = c1_IN_closed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 90U, *c1_sfEvent);
            *c1_y1 = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_y1, 41U);
            (*c1_y1_out)[0] = *c1_y1;
            for (c1_i88 = 0; c1_i88 < 4; c1_i88++) {
              _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i88], 14U);
            }

            (*c1_closeTD)[0] = 0.0;
            for (c1_i89 = 0; c1_i89 < 4; c1_i89++) {
              _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i89], 9U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 93U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(89, 0, 0);
        *c1_is_Train0_door = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 89U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U, *c1_sfEvent);
      switch (*c1_is_Screen_door00) {
       case c1_IN_closed:
        CV_STATE_EVAL(36, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, *c1_sfEvent);
        c1_g_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
          (*c1_openPSD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *c1_sfEvent);
          (*c1_PSDClosed)[0] = 0.0;
          for (c1_i90 = 0; c1_i90 < 8; c1_i90++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i90], 19U);
          }

          c1_d28 = (*c1_PSDClosed)[0];
          sf_mex_printf("%s =\\n", "PSDClosed[0][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d28);
          *c1_is_Screen_door00 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 7U, *c1_sfEvent);
          (*c1_openPSD)[0] = 0.0;
          for (c1_i91 = 0; c1_i91 < 8; c1_i91++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i91], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door00 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(36, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, *c1_sfEvent);
        c1_h_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
          (*c1_closePSD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door00 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(36, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, *c1_sfEvent);
        c1_i_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0, *c1_y2 >=
          2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_i_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door00 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *c1_sfEvent);
          *c1_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_y2, 77U);
          (*c1_y2_out)[0] = *c1_y2;
          for (c1_i92 = 0; c1_i92 < 8; c1_i92++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i92], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(36, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, *c1_sfEvent);
        c1_j_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
          *c1_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_j_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 11;
            sf_debug_transition_conflict_check_begin();
            c1_k_out = ((*c1_y2 > 0.0) && ((*c1_v_shutPSD)[0] == 0.0));
            if (c1_k_out) {
              transitionList[numTransitions] = 9;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *c1_sfEvent);
          (*c1_PSDClosed)[0] = 1.0;
          for (c1_i93 = 0; c1_i93 < 8; c1_i93++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i93], 19U);
          }

          c1_d29 = (*c1_PSDClosed)[0];
          sf_mex_printf("%s =\\n", "PSDClosed[0][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d29);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door00 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *c1_sfEvent);
          *c1_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_y2, 77U);
          (*c1_y2_out)[0] = *c1_y2;
          for (c1_i94 = 0; c1_i94 < 8; c1_i94++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i94], 15U);
          }

          (*c1_closePSD)[0] = 0.0;
          for (c1_i95 = 0; c1_i95 < 8; c1_i95++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i95], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, *c1_sfEvent);
          c1_b_temp = (_SFD_CCP_CALL(9U, 0, *c1_y2 > 0.0 != 0U, *c1_sfEvent) !=
                       0);
          if (c1_b_temp) {
            c1_b_temp = (_SFD_CCP_CALL(9U, 1, (*c1_v_shutPSD)[0] == 0.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_l_out = (CV_TRANSITION_EVAL(9U, (int32_T)c1_b_temp) != 0);
          if (c1_l_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door00 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(36, 0, 0);
        *c1_is_Screen_door00 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
      switch (*c1_is_Controller0) {
       case c1_IN_about_to_close1:
        CV_STATE_EVAL(0, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U, *c1_sfEvent);
        c1_m_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0, *c1_z
          >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_m_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, *c1_sfEvent);
          (*c1_closeTD)[_SFD_ARRAY_BOUNDS_CHECK(9U, *c1_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i96 = 0; c1_i96 < 4; c1_i96++) {
            _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i96], 9U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_close2:
        CV_STATE_EVAL(0, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U, *c1_sfEvent);
        c1_n_out = (CV_TRANSITION_EVAL(21U, (int32_T)_SFD_CCP_CALL(21U, 0,
          (int16_T)(*c1_is_Train0_door == c1_IN_closed) == 0 != 0U, *c1_sfEvent))
                    != 0);
        if (c1_n_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 21;
            sf_debug_transition_conflict_check_begin();
            c1_o_out = (*c1_z >= 5.0);
            if (c1_o_out) {
              transitionList[numTransitions] = 18;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, *c1_sfEvent);
          c1_p_out = (CV_TRANSITION_EVAL(18U, (int32_T)_SFD_CCP_CALL(18U, 0,
            *c1_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_p_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, *c1_sfEvent);
            (*c1_closePSD)[_SFD_ARRAY_BOUNDS_CHECK(5U, c1__s32_d_(chartInstance,
              *c1_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(5U,
              c1__s32_d_(chartInstance, *c1_side), 0, 1, 2, 0) << 2)] = 1.0;
            for (c1_i97 = 0; c1_i97 < 8; c1_i97++) {
              _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i97], 5U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller0 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *c1_sfEvent);
            *c1_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_about_to_open1:
        CV_STATE_EVAL(0, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U, *c1_sfEvent);
        c1_q_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(14U, 0, *c1_z
          >= 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_q_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *c1_sfEvent);
          (*c1_openTD)[_SFD_ARRAY_BOUNDS_CHECK(8U, *c1_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i98 = 0; c1_i98 < 4; c1_i98++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i98], 8U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_open2:
        CV_STATE_EVAL(0, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U, *c1_sfEvent);
        c1_r_out = (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0, *c1_z
          >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_r_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *c1_sfEvent);
          (*c1_openPSD)[_SFD_ARRAY_BOUNDS_CHECK(4U, c1__s32_d_(chartInstance,
            *c1_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(4U,
            c1__s32_d_(chartInstance, *c1_side), 0, 1, 2, 0) << 2)] = 1.0;
          for (c1_i99 = 0; c1_i99 < 8; c1_i99++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i99], 4U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_about_to_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c1_sfEvent);
        }
        break;

       case c1_IN_idle:
        CV_STATE_EVAL(0, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U, *c1_sfEvent);
        c1_s_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i, 0, 3, 2, 0)] == 1.0 !=
          0U, *c1_sfEvent)) != 0);
        if (c1_s_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 12;
            sf_debug_transition_conflict_check_begin();
            c1_c_temp = (*c1_z >= 1.0);
            if (c1_c_temp) {
              c1_c_temp = ((*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i, 0, 3, 2,
                0)] != 1.0);
            }

            c1_t_out = c1_c_temp;
            if (c1_t_out) {
              transitionList[numTransitions] = 109;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *c1_sfEvent);
          *c1_i = 0;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_i, 40U);
          c1_i100 = *c1_i;
          sf_mex_printf("%s =\\n", "i");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i100);
          *c1_stationid = *c1_j;
          _SFD_DATA_RANGE_CHECK(*c1_stationid, 38U);
          c1_d30 = *c1_stationid;
          sf_mex_printf("%s =\\n", "stationid");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d30);
          c1_i101 = c1__s32_add__(chartInstance, (*c1_dir)
            [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0, 3, 1, 0)], 1);
          *c1_side = (real_T)((c1_i101 + (c1_i101 < 0)) >> 1);
          _SFD_DATA_RANGE_CHECK(*c1_side, 39U);
          c1_d31 = *c1_side;
          sf_mex_printf("%s =\\n", "side");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d31);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_about_to_open2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i102 = 0; c1_i102 < 4; c1_i102++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i102], 3U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 109U, *c1_sfEvent);
          c1_d_temp = (_SFD_CCP_CALL(109U, 0, *c1_z >= 1.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_d_temp) {
            c1_d_temp = (_SFD_CCP_CALL(109U, 1, (*c1_stop)
              [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i, 0, 3, 2, 0)] != 1.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_u_out = (CV_TRANSITION_EVAL(109U, (int32_T)c1_d_temp) != 0);
          if (c1_u_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 109U, *c1_sfEvent);
            (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_i, 0, 3, 1, 0)] =
              *c1_distance;
            for (c1_i103 = 0; c1_i103 < 4; c1_i103++) {
              _SFD_DATA_RANGE_CHECK((*c1_position)[c1_i103], 18U);
            }

            c1_d32 = (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_i, 0, 3, 1,
              0)];
            sf_mex_printf("%s =\\n", "position[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d32);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller0 = c1_IN_idle;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *c1_sfEvent);
            *c1_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_open1:
        CV_STATE_EVAL(0, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U, *c1_sfEvent);
        c1_v_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0, *c1_z
          >= 10.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_v_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_ring;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c1_sfEvent);
        }
        break;

       case c1_IN_ring:
        CV_STATE_EVAL(0, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, *c1_sfEvent);
        c1_e_temp = (_SFD_CCP_CALL(16U, 0, *c1_z >= 20.0 != 0U, *c1_sfEvent) !=
                     0);
        if (c1_e_temp) {
          c1_e_temp = (_SFD_CCP_CALL(16U, 1, *c1_z <= 30.0 != 0U, *c1_sfEvent)
                       != 0);
        }

        c1_w_out = (CV_TRANSITION_EVAL(16U, (int32_T)c1_e_temp) != 0);
        if (c1_w_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_about_to_close1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c1_sfEvent);
        }
        break;

       case c1_IN_start:
        CV_STATE_EVAL(0, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, *c1_sfEvent);
        c1_x_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(19U, 0, *c1_z
          >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_x_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 19;
            sf_debug_transition_conflict_check_begin();
            c1_y_out = ((*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
              (chartInstance, *c1_stationid), 0, 3, 1, 0) +
                        (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *
              c1_side), 0, 1, 2, 0) << 2)] == 0.0);
            if (c1_y_out) {
              transitionList[numTransitions] = 143;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, *c1_sfEvent);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i104 = 0; c1_i104 < 4; c1_i104++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i104], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller0 = c1_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *c1_sfEvent);
          *c1_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 143U, *c1_sfEvent);
          c1_ab_out = (CV_TRANSITION_EVAL(143U, (int32_T)_SFD_CCP_CALL(143U, 0,
                         (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_stationid), 0, 3, 1, 0) +
            (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_side), 0,
            1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ab_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 143U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller0 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *c1_sfEvent);
            *c1_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_z, 37U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(0, 0, 0);
        *c1_is_Controller0 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, *c1_sfEvent);
      switch (*c1_is_Screen_door01) {
       case c1_IN_closed:
        CV_STATE_EVAL(41, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U, *c1_sfEvent);
        c1_bb_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0,
          (*c1_openPSD)[4] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_bb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, *c1_sfEvent);
          (*c1_PSDClosed)[4] = 0.0;
          for (c1_i105 = 0; c1_i105 < 8; c1_i105++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i105], 19U);
          }

          c1_d33 = (*c1_PSDClosed)[4];
          sf_mex_printf("%s =\\n", "PSDClosed[0][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d33);
          *c1_is_Screen_door01 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 23U, *c1_sfEvent);
          (*c1_openPSD)[4] = 0.0;
          for (c1_i106 = 0; c1_i106 < 8; c1_i106++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i106], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door01 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(41, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, *c1_sfEvent);
        c1_cb_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
          (*c1_closePSD)[4] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_cb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door01 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(41, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U, *c1_sfEvent);
        c1_db_out = (CV_TRANSITION_EVAL(22U, (int32_T)_SFD_CCP_CALL(22U, 0,
          *c1_b_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_db_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door01 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *c1_sfEvent);
          *c1_b_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_y2, 76U);
          (*c1_y2_out)[4] = *c1_b_y2;
          for (c1_i107 = 0; c1_i107 < 8; c1_i107++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i107], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(41, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U, *c1_sfEvent);
        c1_eb_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U, 0,
          *c1_b_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_eb_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 27;
            sf_debug_transition_conflict_check_begin();
            c1_fb_out = ((*c1_b_y2 > 0.0) && ((*c1_v_shutPSD)[4] == 0.0));
            if (c1_fb_out) {
              transitionList[numTransitions] = 24;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, *c1_sfEvent);
          (*c1_PSDClosed)[4] = 1.0;
          for (c1_i108 = 0; c1_i108 < 8; c1_i108++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i108], 19U);
          }

          c1_d34 = (*c1_PSDClosed)[4];
          sf_mex_printf("%s =\\n", "PSDClosed[0][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d34);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door01 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *c1_sfEvent);
          *c1_b_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_y2, 76U);
          (*c1_y2_out)[4] = *c1_b_y2;
          for (c1_i109 = 0; c1_i109 < 8; c1_i109++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i109], 15U);
          }

          (*c1_closePSD)[4] = 0.0;
          for (c1_i110 = 0; c1_i110 < 8; c1_i110++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i110], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, *c1_sfEvent);
          c1_f_temp = (_SFD_CCP_CALL(24U, 0, *c1_b_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_f_temp) {
            c1_f_temp = (_SFD_CCP_CALL(24U, 1, (*c1_v_shutPSD)[4] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_gb_out = (CV_TRANSITION_EVAL(24U, (int32_T)c1_f_temp) != 0);
          if (c1_gb_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door01 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(41, 0, 0);
        *c1_is_Screen_door01 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U, *c1_sfEvent);
      switch (*c1_is_Screen_door10) {
       case c1_IN_closed:
        CV_STATE_EVAL(46, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, *c1_sfEvent);
        c1_hb_out = (CV_TRANSITION_EVAL(29U, (int32_T)_SFD_CCP_CALL(29U, 0,
          (*c1_openPSD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_hb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, *c1_sfEvent);
          (*c1_PSDClosed)[1] = 0.0;
          for (c1_i111 = 0; c1_i111 < 8; c1_i111++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i111], 19U);
          }

          c1_d35 = (*c1_PSDClosed)[1];
          sf_mex_printf("%s =\\n", "PSDClosed[1][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d35);
          *c1_is_Screen_door10 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 29U, *c1_sfEvent);
          (*c1_openPSD)[1] = 0.0;
          for (c1_i112 = 0; c1_i112 < 8; c1_i112++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i112], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door10 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(46, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U, *c1_sfEvent);
        c1_ib_out = (CV_TRANSITION_EVAL(31U, (int32_T)_SFD_CCP_CALL(31U, 0,
          (*c1_closePSD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ib_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door10 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(46, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U, *c1_sfEvent);
        c1_jb_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
          *c1_c_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_jb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door10 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *c1_sfEvent);
          *c1_c_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_y2, 74U);
          (*c1_y2_out)[1] = *c1_c_y2;
          for (c1_i113 = 0; c1_i113 < 8; c1_i113++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i113], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(46, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U, *c1_sfEvent);
        c1_kb_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL(33U, 0,
          *c1_c_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_kb_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 33;
            sf_debug_transition_conflict_check_begin();
            c1_lb_out = ((*c1_c_y2 > 0.0) && ((*c1_v_shutPSD)[1] == 0.0));
            if (c1_lb_out) {
              transitionList[numTransitions] = 30;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, *c1_sfEvent);
          (*c1_PSDClosed)[1] = 1.0;
          for (c1_i114 = 0; c1_i114 < 8; c1_i114++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i114], 19U);
          }

          c1_d36 = (*c1_PSDClosed)[1];
          sf_mex_printf("%s =\\n", "PSDClosed[1][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d36);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door10 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *c1_sfEvent);
          *c1_c_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_y2, 74U);
          (*c1_y2_out)[1] = *c1_c_y2;
          for (c1_i115 = 0; c1_i115 < 8; c1_i115++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i115], 15U);
          }

          (*c1_closePSD)[1] = 0.0;
          for (c1_i116 = 0; c1_i116 < 8; c1_i116++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i116], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U, *c1_sfEvent);
          c1_g_temp = (_SFD_CCP_CALL(30U, 0, *c1_c_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_g_temp) {
            c1_g_temp = (_SFD_CCP_CALL(30U, 1, (*c1_v_shutPSD)[1] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_mb_out = (CV_TRANSITION_EVAL(30U, (int32_T)c1_g_temp) != 0);
          if (c1_mb_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door10 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(46, 0, 0);
        *c1_is_Screen_door10 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U, *c1_sfEvent);
      switch (*c1_is_Screen_door11) {
       case c1_IN_closed:
        CV_STATE_EVAL(51, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U, *c1_sfEvent);
        c1_nb_out = (CV_TRANSITION_EVAL(35U, (int32_T)_SFD_CCP_CALL(35U, 0,
          (*c1_openPSD)[5] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_nb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, *c1_sfEvent);
          (*c1_PSDClosed)[5] = 0.0;
          for (c1_i117 = 0; c1_i117 < 8; c1_i117++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i117], 19U);
          }

          c1_d37 = (*c1_PSDClosed)[5];
          sf_mex_printf("%s =\\n", "PSDClosed[1][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d37);
          *c1_is_Screen_door11 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 35U, *c1_sfEvent);
          (*c1_openPSD)[5] = 0.0;
          for (c1_i118 = 0; c1_i118 < 8; c1_i118++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i118], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door11 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(51, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U, *c1_sfEvent);
        c1_ob_out = (CV_TRANSITION_EVAL(37U, (int32_T)_SFD_CCP_CALL(37U, 0,
          (*c1_closePSD)[5] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ob_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door11 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(51, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U, *c1_sfEvent);
        c1_pb_out = (CV_TRANSITION_EVAL(34U, (int32_T)_SFD_CCP_CALL(34U, 0,
          *c1_d_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_pb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door11 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *c1_sfEvent);
          *c1_d_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_y2, 75U);
          (*c1_y2_out)[5] = *c1_d_y2;
          for (c1_i119 = 0; c1_i119 < 8; c1_i119++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i119], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(51, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 39U, *c1_sfEvent);
        c1_qb_out = (CV_TRANSITION_EVAL(39U, (int32_T)_SFD_CCP_CALL(39U, 0,
          *c1_d_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_qb_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 39;
            sf_debug_transition_conflict_check_begin();
            c1_rb_out = ((*c1_d_y2 > 0.0) && ((*c1_v_shutPSD)[5] == 0.0));
            if (c1_rb_out) {
              transitionList[numTransitions] = 36;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, *c1_sfEvent);
          (*c1_PSDClosed)[5] = 1.0;
          for (c1_i120 = 0; c1_i120 < 8; c1_i120++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i120], 19U);
          }

          c1_d38 = (*c1_PSDClosed)[5];
          sf_mex_printf("%s =\\n", "PSDClosed[1][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d38);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door11 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *c1_sfEvent);
          *c1_d_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_y2, 75U);
          (*c1_y2_out)[5] = *c1_d_y2;
          for (c1_i121 = 0; c1_i121 < 8; c1_i121++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i121], 15U);
          }

          (*c1_closePSD)[5] = 0.0;
          for (c1_i122 = 0; c1_i122 < 8; c1_i122++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i122], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, *c1_sfEvent);
          c1_h_temp = (_SFD_CCP_CALL(36U, 0, *c1_d_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_h_temp) {
            c1_h_temp = (_SFD_CCP_CALL(36U, 1, (*c1_v_shutPSD)[5] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_sb_out = (CV_TRANSITION_EVAL(36U, (int32_T)c1_h_temp) != 0);
          if (c1_sb_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door11 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(51, 0, 0);
        *c1_is_Screen_door11 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U, *c1_sfEvent);
      switch (*c1_is_Screen_door20) {
       case c1_IN_closed:
        CV_STATE_EVAL(56, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U, *c1_sfEvent);
        c1_tb_out = (CV_TRANSITION_EVAL(41U, (int32_T)_SFD_CCP_CALL(41U, 0,
          (*c1_openPSD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_tb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, *c1_sfEvent);
          (*c1_PSDClosed)[2] = 0.0;
          for (c1_i123 = 0; c1_i123 < 8; c1_i123++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i123], 19U);
          }

          c1_d39 = (*c1_PSDClosed)[2];
          sf_mex_printf("%s =\\n", "PSDClosed[2][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d39);
          *c1_is_Screen_door20 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 41U, *c1_sfEvent);
          (*c1_openPSD)[2] = 0.0;
          for (c1_i124 = 0; c1_i124 < 8; c1_i124++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i124], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door20 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(56, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U, *c1_sfEvent);
        c1_ub_out = (CV_TRANSITION_EVAL(43U, (int32_T)_SFD_CCP_CALL(43U, 0,
          (*c1_closePSD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ub_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door20 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(56, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, *c1_sfEvent);
        c1_vb_out = (CV_TRANSITION_EVAL(40U, (int32_T)_SFD_CCP_CALL(40U, 0,
          *c1_e_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_vb_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door20 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *c1_sfEvent);
          *c1_e_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_e_y2, 81U);
          (*c1_y2_out)[2] = *c1_e_y2;
          for (c1_i125 = 0; c1_i125 < 8; c1_i125++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i125], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(56, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U, *c1_sfEvent);
        c1_wb_out = (CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(45U, 0,
          *c1_e_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_wb_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 45;
            sf_debug_transition_conflict_check_begin();
            c1_xb_out = ((*c1_e_y2 > 0.0) && ((*c1_v_shutPSD)[2] == 0.0));
            if (c1_xb_out) {
              transitionList[numTransitions] = 42;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, *c1_sfEvent);
          (*c1_PSDClosed)[2] = 1.0;
          for (c1_i126 = 0; c1_i126 < 8; c1_i126++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i126], 19U);
          }

          c1_d40 = (*c1_PSDClosed)[2];
          sf_mex_printf("%s =\\n", "PSDClosed[2][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d40);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door20 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *c1_sfEvent);
          *c1_e_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_e_y2, 81U);
          (*c1_y2_out)[2] = *c1_e_y2;
          for (c1_i127 = 0; c1_i127 < 8; c1_i127++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i127], 15U);
          }

          (*c1_closePSD)[2] = 0.0;
          for (c1_i128 = 0; c1_i128 < 8; c1_i128++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i128], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U, *c1_sfEvent);
          c1_i_temp = (_SFD_CCP_CALL(42U, 0, *c1_e_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_i_temp) {
            c1_i_temp = (_SFD_CCP_CALL(42U, 1, (*c1_v_shutPSD)[2] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_yb_out = (CV_TRANSITION_EVAL(42U, (int32_T)c1_i_temp) != 0);
          if (c1_yb_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door20 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(56, 0, 0);
        *c1_is_Screen_door20 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, *c1_sfEvent);
      switch (*c1_is_Screen_door21) {
       case c1_IN_closed:
        CV_STATE_EVAL(61, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U, *c1_sfEvent);
        c1_ac_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(47U, 0,
          (*c1_openPSD)[6] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ac_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, *c1_sfEvent);
          (*c1_PSDClosed)[6] = 0.0;
          for (c1_i129 = 0; c1_i129 < 8; c1_i129++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i129], 19U);
          }

          c1_d41 = (*c1_PSDClosed)[6];
          sf_mex_printf("%s =\\n", "PSDClosed[2][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d41);
          *c1_is_Screen_door21 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 47U, *c1_sfEvent);
          (*c1_openPSD)[6] = 0.0;
          for (c1_i130 = 0; c1_i130 < 8; c1_i130++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i130], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door21 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(61, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 49U, *c1_sfEvent);
        c1_bc_out = (CV_TRANSITION_EVAL(49U, (int32_T)_SFD_CCP_CALL(49U, 0,
          (*c1_closePSD)[6] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_bc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door21 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(61, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U, *c1_sfEvent);
        c1_cc_out = (CV_TRANSITION_EVAL(46U, (int32_T)_SFD_CCP_CALL(46U, 0,
          *c1_f_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_cc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door21 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, *c1_sfEvent);
          *c1_f_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_f_y2, 80U);
          (*c1_y2_out)[6] = *c1_f_y2;
          for (c1_i131 = 0; c1_i131 < 8; c1_i131++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i131], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(61, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 51U, *c1_sfEvent);
        c1_dc_out = (CV_TRANSITION_EVAL(51U, (int32_T)_SFD_CCP_CALL(51U, 0,
          *c1_f_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_dc_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 51;
            sf_debug_transition_conflict_check_begin();
            c1_ec_out = ((*c1_f_y2 > 0.0) && ((*c1_v_shutPSD)[6] == 0.0));
            if (c1_ec_out) {
              transitionList[numTransitions] = 48;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, *c1_sfEvent);
          (*c1_PSDClosed)[6] = 1.0;
          for (c1_i132 = 0; c1_i132 < 8; c1_i132++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i132], 19U);
          }

          c1_d42 = (*c1_PSDClosed)[6];
          sf_mex_printf("%s =\\n", "PSDClosed[2][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d42);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door21 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *c1_sfEvent);
          *c1_f_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_f_y2, 80U);
          (*c1_y2_out)[6] = *c1_f_y2;
          for (c1_i133 = 0; c1_i133 < 8; c1_i133++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i133], 15U);
          }

          (*c1_closePSD)[6] = 0.0;
          for (c1_i134 = 0; c1_i134 < 8; c1_i134++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i134], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U, *c1_sfEvent);
          c1_j_temp = (_SFD_CCP_CALL(48U, 0, *c1_f_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_j_temp) {
            c1_j_temp = (_SFD_CCP_CALL(48U, 1, (*c1_v_shutPSD)[6] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_fc_out = (CV_TRANSITION_EVAL(48U, (int32_T)c1_j_temp) != 0);
          if (c1_fc_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door21 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(61, 0, 0);
        *c1_is_Screen_door21 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U, *c1_sfEvent);
      switch (*c1_is_Screen_door30) {
       case c1_IN_closed:
        CV_STATE_EVAL(66, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U, *c1_sfEvent);
        c1_gc_out = (CV_TRANSITION_EVAL(53U, (int32_T)_SFD_CCP_CALL(53U, 0,
          (*c1_openPSD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_gc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, *c1_sfEvent);
          (*c1_PSDClosed)[3] = 0.0;
          for (c1_i135 = 0; c1_i135 < 8; c1_i135++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i135], 19U);
          }

          c1_d43 = (*c1_PSDClosed)[3];
          sf_mex_printf("%s =\\n", "PSDClosed[3][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d43);
          *c1_is_Screen_door30 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 53U, *c1_sfEvent);
          (*c1_openPSD)[3] = 0.0;
          for (c1_i136 = 0; c1_i136 < 8; c1_i136++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i136], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door30 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 69U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(66, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U, *c1_sfEvent);
        c1_hc_out = (CV_TRANSITION_EVAL(55U, (int32_T)_SFD_CCP_CALL(55U, 0,
          (*c1_closePSD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_hc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door30 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(66, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 52U, *c1_sfEvent);
        c1_ic_out = (CV_TRANSITION_EVAL(52U, (int32_T)_SFD_CCP_CALL(52U, 0,
          *c1_g_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ic_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 69U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door30 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, *c1_sfEvent);
          *c1_g_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_g_y2, 78U);
          (*c1_y2_out)[3] = *c1_g_y2;
          for (c1_i137 = 0; c1_i137 < 8; c1_i137++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i137], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(66, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 70U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 57U, *c1_sfEvent);
        c1_jc_out = (CV_TRANSITION_EVAL(57U, (int32_T)_SFD_CCP_CALL(57U, 0,
          *c1_g_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_jc_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 57;
            sf_debug_transition_conflict_check_begin();
            c1_kc_out = ((*c1_g_y2 > 0.0) && ((*c1_v_shutPSD)[3] == 0.0));
            if (c1_kc_out) {
              transitionList[numTransitions] = 54;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, *c1_sfEvent);
          (*c1_PSDClosed)[3] = 1.0;
          for (c1_i138 = 0; c1_i138 < 8; c1_i138++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i138], 19U);
          }

          c1_d44 = (*c1_PSDClosed)[3];
          sf_mex_printf("%s =\\n", "PSDClosed[3][0]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d44);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door30 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, *c1_sfEvent);
          *c1_g_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_g_y2, 78U);
          for (c1_i139 = 0; c1_i139 < 8; c1_i139++) {
            (*c1_y2_out)[c1_i139] = *c1_g_y2;
          }

          for (c1_i140 = 0; c1_i140 < 8; c1_i140++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i140], 15U);
          }

          (*c1_closePSD)[3] = 0.0;
          for (c1_i141 = 0; c1_i141 < 8; c1_i141++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i141], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U, *c1_sfEvent);
          c1_k_temp = (_SFD_CCP_CALL(54U, 0, *c1_g_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_k_temp) {
            c1_k_temp = (_SFD_CCP_CALL(54U, 1, (*c1_v_shutPSD)[3] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_lc_out = (CV_TRANSITION_EVAL(54U, (int32_T)c1_k_temp) != 0);
          if (c1_lc_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door30 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 69U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(66, 0, 0);
        *c1_is_Screen_door30 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U, *c1_sfEvent);
      switch (*c1_is_Screen_door31) {
       case c1_IN_closed:
        CV_STATE_EVAL(71, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U, *c1_sfEvent);
        c1_mc_out = (CV_TRANSITION_EVAL(59U, (int32_T)_SFD_CCP_CALL(59U, 0,
          (*c1_openPSD)[7] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_mc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, *c1_sfEvent);
          (*c1_PSDClosed)[7] = 0.0;
          for (c1_i142 = 0; c1_i142 < 8; c1_i142++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i142], 19U);
          }

          c1_d45 = (*c1_PSDClosed)[7];
          sf_mex_printf("%s =\\n", "PSDClosed[3][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d45);
          *c1_is_Screen_door31 = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 59U, *c1_sfEvent);
          (*c1_openPSD)[7] = 0.0;
          for (c1_i143 = 0; c1_i143 < 8; c1_i143++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i143], 4U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Screen_door31 = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(71, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 61U, *c1_sfEvent);
        c1_nc_out = (CV_TRANSITION_EVAL(61U, (int32_T)_SFD_CCP_CALL(61U, 0,
          (*c1_closePSD)[7] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_nc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 73U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door31 = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 75U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(71, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 74U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 58U, *c1_sfEvent);
        c1_oc_out = (CV_TRANSITION_EVAL(58U, (int32_T)_SFD_CCP_CALL(58U, 0,
          *c1_h_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_oc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door31 = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, *c1_sfEvent);
          *c1_h_y2 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_h_y2, 79U);
          (*c1_y2_out)[7] = *c1_h_y2;
          for (c1_i144 = 0; c1_i144 < 8; c1_i144++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i144], 15U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(71, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 75U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U, *c1_sfEvent);
        c1_pc_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(63U, 0,
          *c1_h_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_pc_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 63;
            sf_debug_transition_conflict_check_begin();
            c1_qc_out = ((*c1_h_y2 > 0.0) && ((*c1_v_shutPSD)[7] == 0.0));
            if (c1_qc_out) {
              transitionList[numTransitions] = 60;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, *c1_sfEvent);
          (*c1_PSDClosed)[7] = 1.0;
          for (c1_i145 = 0; c1_i145 < 8; c1_i145++) {
            _SFD_DATA_RANGE_CHECK((*c1_PSDClosed)[c1_i145], 19U);
          }

          c1_d46 = (*c1_PSDClosed)[7];
          sf_mex_printf("%s =\\n", "PSDClosed[3][1]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d46);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 75U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Screen_door31 = c1_IN_closed;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, *c1_sfEvent);
          *c1_h_y2 = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_h_y2, 79U);
          (*c1_y2_out)[7] = *c1_h_y2;
          for (c1_i146 = 0; c1_i146 < 8; c1_i146++) {
            _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i146], 15U);
          }

          (*c1_closePSD)[7] = 0.0;
          for (c1_i147 = 0; c1_i147 < 8; c1_i147++) {
            _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i147], 5U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 60U, *c1_sfEvent);
          c1_l_temp = (_SFD_CCP_CALL(60U, 0, *c1_h_y2 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_l_temp) {
            c1_l_temp = (_SFD_CCP_CALL(60U, 1, (*c1_v_shutPSD)[7] == 0.0 != 0U, *
              c1_sfEvent) != 0);
          }

          c1_rc_out = (CV_TRANSITION_EVAL(60U, (int32_T)c1_l_temp) != 0);
          if (c1_rc_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 75U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Screen_door31 = c1_IN_part;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 75U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(71, 0, 0);
        *c1_is_Screen_door31 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 107U, *c1_sfEvent);
      switch (*c1_is_Train1_door) {
       case c1_IN_closed:
        CV_STATE_EVAL(107, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 108U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 65U, *c1_sfEvent);
        c1_sc_out = (CV_TRANSITION_EVAL(65U, (int32_T)_SFD_CCP_CALL(65U, 0,
          (*c1_openTD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_sc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, *c1_sfEvent);
          *c1_is_Train1_door = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 108U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 65U, *c1_sfEvent);
          (*c1_openTD)[1] = 0.0;
          for (c1_i148 = 0; c1_i148 < 4; c1_i148++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i148], 8U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Train1_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 110U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 108U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(107, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 109U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 66U, *c1_sfEvent);
        c1_tc_out = (CV_TRANSITION_EVAL(66U, (int32_T)_SFD_CCP_CALL(66U, 0,
          (*c1_closeTD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_tc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 109U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1_door = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 111U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 109U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(107, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 110U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U, *c1_sfEvent);
        c1_uc_out = (CV_TRANSITION_EVAL(64U, (int32_T)_SFD_CCP_CALL(64U, 0,
          *c1_b_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_uc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 110U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1_door = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 109U, *c1_sfEvent);
          *c1_b_y1 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_y1, 42U);
          (*c1_y1_out)[1] = *c1_b_y1;
          for (c1_i149 = 0; c1_i149 < 4; c1_i149++) {
            _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i149], 14U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 110U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(107, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 111U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U, *c1_sfEvent);
        c1_m_temp = (_SFD_CCP_CALL(67U, 0, *c1_b_y1 > 0.0 != 0U, *c1_sfEvent) !=
                     0);
        if (c1_m_temp) {
          c1_m_temp = (_SFD_CCP_CALL(67U, 1, (*c1_v_shutTD)[1] == 0.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_vc_out = (CV_TRANSITION_EVAL(67U, (int32_T)c1_m_temp) != 0);
        if (c1_vc_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 67;
            sf_debug_transition_conflict_check_begin();
            c1_wc_out = (*c1_b_y1 <= 0.0);
            if (c1_wc_out) {
              transitionList[numTransitions] = 69;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 111U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 110U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 69U, *c1_sfEvent);
          c1_xc_out = (CV_TRANSITION_EVAL(69U, (int32_T)_SFD_CCP_CALL(69U, 0,
            *c1_b_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_xc_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 111U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1_door = c1_IN_closed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 108U, *c1_sfEvent);
            *c1_b_y1 = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_y1, 42U);
            (*c1_y1_out)[1] = *c1_b_y1;
            for (c1_i150 = 0; c1_i150 < 4; c1_i150++) {
              _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i150], 14U);
            }

            (*c1_closeTD)[1] = 0.0;
            for (c1_i151 = 0; c1_i151 < 4; c1_i151++) {
              _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i151], 9U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 111U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(107, 0, 0);
        *c1_is_Train1_door = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 108U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 107U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 125U, *c1_sfEvent);
      switch (*c1_is_Train2_door) {
       case c1_IN_closed:
        CV_STATE_EVAL(125, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 126U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 71U, *c1_sfEvent);
        c1_yc_out = (CV_TRANSITION_EVAL(71U, (int32_T)_SFD_CCP_CALL(71U, 0,
          (*c1_openTD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_yc_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, *c1_sfEvent);
          *c1_is_Train2_door = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 126U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 71U, *c1_sfEvent);
          (*c1_openTD)[2] = 0.0;
          for (c1_i152 = 0; c1_i152 < 4; c1_i152++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i152], 8U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Train2_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 128U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 126U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(125, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 127U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U, *c1_sfEvent);
        c1_ad_out = (CV_TRANSITION_EVAL(72U, (int32_T)_SFD_CCP_CALL(72U, 0,
          (*c1_closeTD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ad_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 127U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2_door = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 129U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 127U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(125, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 128U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U, *c1_sfEvent);
        c1_bd_out = (CV_TRANSITION_EVAL(70U, (int32_T)_SFD_CCP_CALL(70U, 0,
          *c1_c_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_bd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 128U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2_door = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 127U, *c1_sfEvent);
          *c1_c_y1 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_y1, 65U);
          (*c1_y1_out)[2] = *c1_c_y1;
          for (c1_i153 = 0; c1_i153 < 4; c1_i153++) {
            _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i153], 14U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 128U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(125, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 129U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 73U, *c1_sfEvent);
        c1_n_temp = (_SFD_CCP_CALL(73U, 0, *c1_c_y1 > 0.0 != 0U, *c1_sfEvent) !=
                     0);
        if (c1_n_temp) {
          c1_n_temp = (_SFD_CCP_CALL(73U, 1, (*c1_v_shutTD)[2] == 0.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_cd_out = (CV_TRANSITION_EVAL(73U, (int32_T)c1_n_temp) != 0);
        if (c1_cd_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 73;
            sf_debug_transition_conflict_check_begin();
            c1_dd_out = (*c1_c_y1 <= 0.0);
            if (c1_dd_out) {
              transitionList[numTransitions] = 75;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 129U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 128U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 75U, *c1_sfEvent);
          c1_ed_out = (CV_TRANSITION_EVAL(75U, (int32_T)_SFD_CCP_CALL(75U, 0,
            *c1_c_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ed_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 129U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2_door = c1_IN_closed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 126U, *c1_sfEvent);
            *c1_c_y1 = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_y1, 65U);
            (*c1_y1_out)[2] = *c1_c_y1;
            for (c1_i154 = 0; c1_i154 < 4; c1_i154++) {
              _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i154], 14U);
            }

            (*c1_closeTD)[2] = 0.0;
            for (c1_i155 = 0; c1_i155 < 4; c1_i155++) {
              _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i155], 9U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 129U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(125, 0, 0);
        *c1_is_Train2_door = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 126U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 125U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 143U, *c1_sfEvent);
      switch (*c1_is_Train3_door) {
       case c1_IN_closed:
        CV_STATE_EVAL(143, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 144U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 77U, *c1_sfEvent);
        c1_fd_out = (CV_TRANSITION_EVAL(77U, (int32_T)_SFD_CCP_CALL(77U, 0,
          (*c1_openTD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_fd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *c1_sfEvent);
          *c1_is_Train3_door = c1_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 144U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_TRANS_ACTION_TAG, 77U, *c1_sfEvent);
          (*c1_openTD)[3] = 0.0;
          for (c1_i156 = 0; c1_i156 < 4; c1_i156++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i156], 8U);
          }

          *c1_stateChanged = TRUE;
          *c1_is_Train3_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 146U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 144U, *c1_sfEvent);
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(143, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 145U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 78U, *c1_sfEvent);
        c1_gd_out = (CV_TRANSITION_EVAL(78U, (int32_T)_SFD_CCP_CALL(78U, 0,
          (*c1_closeTD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_gd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 145U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3_door = c1_IN_shut;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 147U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 145U, *c1_sfEvent);
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(143, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 146U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 76U, *c1_sfEvent);
        c1_hd_out = (CV_TRANSITION_EVAL(76U, (int32_T)_SFD_CCP_CALL(76U, 0,
          *c1_d_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_hd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 146U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3_door = c1_IN_open;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 145U, *c1_sfEvent);
          *c1_d_y1 = 2.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_y1, 73U);
          (*c1_y1_out)[3] = *c1_d_y1;
          for (c1_i157 = 0; c1_i157 < 4; c1_i157++) {
            _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i157], 14U);
          }
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 146U, *c1_sfEvent);
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(143, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 147U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 79U, *c1_sfEvent);
        c1_o_temp = (_SFD_CCP_CALL(79U, 0, *c1_d_y1 > 0.0 != 0U, *c1_sfEvent) !=
                     0);
        if (c1_o_temp) {
          c1_o_temp = (_SFD_CCP_CALL(79U, 1, (*c1_v_shutTD)[3] == 0.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_id_out = (CV_TRANSITION_EVAL(79U, (int32_T)c1_o_temp) != 0);
        if (c1_id_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 79;
            sf_debug_transition_conflict_check_begin();
            c1_jd_out = (*c1_d_y1 <= 0.0);
            if (c1_jd_out) {
              transitionList[numTransitions] = 81;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 147U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3_door = c1_IN_part;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 146U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 81U, *c1_sfEvent);
          c1_kd_out = (CV_TRANSITION_EVAL(81U, (int32_T)_SFD_CCP_CALL(81U, 0,
            *c1_d_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_kd_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 147U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3_door = c1_IN_closed;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 144U, *c1_sfEvent);
            *c1_d_y1 = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_y1, 73U);
            (*c1_y1_out)[3] = *c1_d_y1;
            for (c1_i158 = 0; c1_i158 < 4; c1_i158++) {
              _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i158], 14U);
            }

            (*c1_closeTD)[3] = 0.0;
            for (c1_i159 = 0; c1_i159 < 4; c1_i159++) {
              _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i159], 9U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 147U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(143, 0, 0);
        *c1_is_Train3_door = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 144U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 143U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 148U, *c1_sfEvent);
      switch (*c1_is_UrgentController) {
       case c1_IN_D1:
        CV_STATE_EVAL(148, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 150U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 84U, *c1_sfEvent);
        c1_p_temp = (_SFD_CCP_CALL(84U, 0, *c1_b_i != *c1_N != 0U, *c1_sfEvent)
                     != 0);
        if (c1_p_temp) {
          c1_p_temp = (_SFD_CCP_CALL(84U, 1, *c1_t >= 0.0 != 0U, *c1_sfEvent) !=
                       0);
        }

        c1_ld_out = (CV_TRANSITION_EVAL(84U, (int32_T)c1_p_temp) != 0);
        if (c1_ld_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 84;
            sf_debug_transition_conflict_check_begin();
            c1_md_out = ((*c1_b_i == *c1_N) && (*c1_t >= 1.0));
            if (c1_md_out) {
              transitionList[numTransitions] = 147;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 84U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 85U, *c1_sfEvent);
          c1_hoistedGlobal = *c1_b_i;
          c1_a = (real_T)c1_hoistedGlobal;
          _SFD_SET_DATA_VALUE_PTR(25U, &c1_a);
          sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c1_b_debug_family_names,
            c1_debug_family_var_map);
          sf_debug_symbol_scope_add_eml_importable(&c1_needstop, 0U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_index, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 2U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 3U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_a, 4U, c1_sf_marshallOut,
            c1_sf_marshallIn);
          CV_EML_FCN(152U, 0);
          _SFD_EML_CALL(152U, *c1_sfEvent, 3);
          *c1_dis = 10000;
          _SFD_EML_CALL(152U, *c1_sfEvent, 4);
          c1_needstop = 0.0;
          _SFD_EML_CALL(152U, *c1_sfEvent, 6);
          c1_q0 = *c1_N;
          c1_q1 = 1;
          c1_qY = c1_q0 - c1_q1;
          if ((c1_q0 < 0) && ((c1_q1 >= 0) && (c1_qY >= 0))) {
            c1_qY = MIN_int32_T;
          } else {
            if ((c1_q0 >= 0) && ((c1_q1 < 0) && (c1_qY < 0))) {
              c1_qY = MAX_int32_T;
            }
          }

          c1_i160 = c1_qY;
          c1_eml_int_forloop_overflow_check(chartInstance, c1_i160);
          c1_index = 0;
          c1_b_index = 0;
          while (c1_b_index <= c1_i160) {
            c1_index = c1_b_index;
            CV_EML_FOR(152U, 1, 0, 1);
            _SFD_EML_CALL(152U, *c1_sfEvent, 7);
            guard3 = FALSE;
            if (CV_EML_COND(152U, 1, 0, c1_a != (real_T)c1_index)) {
              c1_b_q0 = c1_index;
              c1_b_q1 = 1;
              c1_b_qY = c1_b_q0 + c1_b_q1;
              if ((c1_b_q0 < 0) && ((c1_b_q1 < 0) && (c1_b_qY >= 0))) {
                c1_b_qY = MIN_int32_T;
              } else {
                if ((c1_b_q0 > 0) && ((c1_b_q1 > 0) && (c1_b_qY <= 0))) {
                  c1_b_qY = MAX_int32_T;
                }
              }

              if (CV_EML_COND(152U, 1, 1, (*c1_dir)[_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "dir", (int32_T)_SFD_INTEGER_CHECK("a+1", c1_a + 1.0), 1, 4,
                    1, 0) - 1] == (*c1_dir)[_SFD_EML_ARRAY_BOUNDS_CHECK("dir",
                    (int32_T)_SFD_INTEGER_CHECK("index+1", (real_T)c1_b_qY), 1,
                    4, 1, 0) - 1])) {
                CV_EML_MCDC(152U, 1, 0, TRUE);
                CV_EML_IF(152U, 1, 0, TRUE);
                _SFD_EML_CALL(152U, *c1_sfEvent, 8);
                c1_c_q0 = c1_index;
                c1_c_q1 = 1;
                c1_c_qY = c1_c_q0 + c1_c_q1;
                if ((c1_c_q0 < 0) && ((c1_c_q1 < 0) && (c1_c_qY >= 0))) {
                  c1_c_qY = MIN_int32_T;
                } else {
                  if ((c1_c_q0 > 0) && ((c1_c_q1 > 0) && (c1_c_qY <= 0))) {
                    c1_c_qY = MAX_int32_T;
                  }
                }

                *c1_tdis = c1_mtimes(chartInstance, (*c1_dir)
                                     [_SFD_EML_ARRAY_BOUNDS_CHECK("dir",
                  (int32_T)_SFD_INTEGER_CHECK("a+1", c1_a + 1.0), 1, 4, 1, 0) -
                                     1], (*c1_position)
                                     [_SFD_EML_ARRAY_BOUNDS_CHECK("position",
                  (int32_T)_SFD_INTEGER_CHECK("index+1", (real_T)c1_c_qY), 1, 4,
                  1, 0) - 1] - (*c1_position)[_SFD_EML_ARRAY_BOUNDS_CHECK(
                  "position", (int32_T)_SFD_INTEGER_CHECK("a+1", c1_a + 1.0), 1,
                  4, 1, 0) - 1]);
                _SFD_EML_CALL(152U, *c1_sfEvent, 9);
                guard4 = FALSE;
                if (CV_EML_COND(152U, 1, 2, (real_T)*c1_tdis <= 300.0)) {
                  if (CV_EML_COND(152U, 1, 3, (real_T)*c1_tdis > 0.0)) {
                    CV_EML_MCDC(152U, 1, 1, TRUE);
                    CV_EML_IF(152U, 1, 1, TRUE);
                    _SFD_EML_CALL(152U, *c1_sfEvent, 10);
                    if (CV_EML_IF(152U, 1, 2, *c1_tdis < *c1_dis)) {
                      _SFD_EML_CALL(152U, *c1_sfEvent, 11);
                      *c1_dis = *c1_tdis;
                      sf_mex_printf("%s =\\n", "dis");
                      sf_mex_call_debug("disp", 0U, 1U, 14,
                                        c1_b_emlrt_marshallOut(chartInstance,
                        *c1_dis));
                      _SFD_EML_CALL(152U, *c1_sfEvent, 12);
                      c1_d_q0 = c1_index;
                      c1_d_q1 = 1;
                      c1_d_qY = c1_d_q0 + c1_d_q1;
                      if ((c1_d_q0 < 0) && ((c1_d_q1 < 0) && (c1_d_qY >= 0))) {
                        c1_d_qY = MIN_int32_T;
                      } else {
                        if ((c1_d_q0 > 0) && ((c1_d_q1 > 0) && (c1_d_qY <= 0)))
                        {
                          c1_d_qY = MAX_int32_T;
                        }
                      }

                      (*c1_RelevantIndex)[_SFD_EML_ARRAY_BOUNDS_CHECK(
                        "RelevantIndex", (int32_T)_SFD_INTEGER_CHECK("a+1", c1_a
                        + 1.0), 1, 4, 1, 0) - 1] = c1_d_qY;
                      _SFD_EML_CALL(152U, *c1_sfEvent, 13);
                      c1_needstop = 1.0;
                    }
                  } else {
                    guard4 = TRUE;
                  }
                } else {
                  guard4 = TRUE;
                }

                if (guard4 == TRUE) {
                  CV_EML_MCDC(152U, 1, 1, FALSE);
                  CV_EML_IF(152U, 1, 1, FALSE);
                }
              } else {
                guard3 = TRUE;
              }
            } else {
              guard3 = TRUE;
            }

            if (guard3 == TRUE) {
              CV_EML_MCDC(152U, 1, 0, FALSE);
              CV_EML_IF(152U, 1, 0, FALSE);
            }

            c1_b_index++;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }

          CV_EML_FOR(152U, 1, 0, 0);
          _SFD_EML_CALL(152U, *c1_sfEvent, 19);
          if (CV_EML_IF(152U, 1, 3, c1_needstop == 1.0)) {
            _SFD_EML_CALL(152U, *c1_sfEvent, 20);
            (*c1_urstop)[_SFD_EML_ARRAY_BOUNDS_CHECK("urstop", (int32_T)
              _SFD_INTEGER_CHECK("a+1", c1_a + 1.0), 1, 4, 1, 0) - 1] = 1.0;
          }

          _SFD_EML_CALL(152U, *c1_sfEvent, -20);
          sf_debug_symbol_scope_pop();
          _SFD_UNSET_DATA_VALUE_PTR(25U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 150U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_UrgentController = c1_IN_tmp;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 153U, *c1_sfEvent);
          *c1_t = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 147U, *c1_sfEvent);
          c1_q_temp = (_SFD_CCP_CALL(147U, 0, *c1_b_i == *c1_N != 0U,
            *c1_sfEvent) != 0);
          if (c1_q_temp) {
            c1_q_temp = (_SFD_CCP_CALL(147U, 1, *c1_t >= 1.0 != 0U, *c1_sfEvent)
                         != 0);
          }

          c1_nd_out = (CV_TRANSITION_EVAL(147U, (int32_T)c1_q_temp) != 0);
          if (c1_nd_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 147U, *c1_sfEvent);
            *c1_b_i = 0;
            _SFD_DATA_RANGE_CHECK((real_T)*c1_b_i, 21U);
            c1_i161 = *c1_b_i;
            sf_mex_printf("%s =\\n", "i");
            sf_mex_call_debug("disp", 0U, 1U, 12, c1_i161);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 150U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_UrgentController = c1_IN_D1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 150U, *c1_sfEvent);
            *c1_t = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 150U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_Delay:
        CV_STATE_EVAL(148, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 151U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 83U, *c1_sfEvent);
        c1_od_out = (CV_TRANSITION_EVAL(83U, (int32_T)_SFD_CCP_CALL(83U, 0,
          *c1_t >= 150.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_od_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, *c1_sfEvent);
          *c1_b_i = 0;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_b_i, 21U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 151U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_UrgentController = c1_IN_D1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 150U, *c1_sfEvent);
          *c1_t = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 151U, *c1_sfEvent);
        }
        break;

       case c1_IN_tmp:
        CV_STATE_EVAL(148, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 153U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 86U, *c1_sfEvent);
        c1_pd_out = (CV_TRANSITION_EVAL(86U, (int32_T)_SFD_CCP_CALL(86U, 0,
          *c1_t >= 0.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_pd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 86U, *c1_sfEvent);
          sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_debug_family_names,
            c1_b_debug_family_var_map);
          sf_debug_symbol_scope_add_eml_importable(&c1_si, 0U, c1_sf_marshallOut,
            c1_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_sj, 1U,
            c1_b_sf_marshallOut, c1_b_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 2U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 3U,
            c1_sf_marshallOut, c1_sf_marshallIn);
          CV_EML_FCN(149U, 0);
          _SFD_EML_CALL(149U, *c1_sfEvent, 3);
          c1_c_index = 0;
          while (c1_c_index < 4) {
            c1_d_index = 1.0 + (real_T)c1_c_index;
            CV_EML_FOR(149U, 1, 0, 1);
            _SFD_EML_CALL(149U, *c1_sfEvent, 4);
            c1_si = c1_d_index;
            _SFD_EML_CALL(149U, *c1_sfEvent, 5);
            c1_sj = (*c1_RelevantIndex)[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "RelevantIndex", (int32_T)_SFD_INTEGER_CHECK("index", c1_d_index),
              1, 4, 1, 0) - 1];
            _SFD_EML_CALL(149U, *c1_sfEvent, 6);
            guard1 = FALSE;
            if (CV_EML_COND(149U, 1, 0, (real_T)c1_sj != -1.0)) {
              if (CV_EML_COND(149U, 1, 1, (*c1_urstopped)
                              [_SFD_EML_ARRAY_BOUNDS_CHECK("urstopped", (int32_T)
                    _SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1, 0) - 1] == 1.0)) {
                CV_EML_MCDC(149U, 1, 0, TRUE);
                CV_EML_IF(149U, 1, 0, TRUE);
                _SFD_EML_CALL(149U, *c1_sfEvent, 7);
                (*c1_urstop)[_SFD_EML_ARRAY_BOUNDS_CHECK("urstop", (int32_T)
                  _SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1, 0) - 1] = 0.0;
                _SFD_EML_CALL(149U, *c1_sfEvent, 8);
                guard2 = FALSE;
                if (CV_EML_COND(149U, 1, 2, c1_abs(chartInstance, (*c1_position)
                      [_SFD_EML_ARRAY_BOUNDS_CHECK("position", (int32_T)
                       _SFD_INTEGER_CHECK("sj", (real_T)c1_sj), 1, 4, 1, 0) - 1]
                      - (*c1_position)[_SFD_EML_ARRAY_BOUNDS_CHECK("position",
                       (int32_T)_SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1, 0) - 1])
                                > 300.0)) {
                  guard2 = TRUE;
                } else if (CV_EML_COND(149U, 1, 3, (*c1_dir)
                                       [_SFD_EML_ARRAY_BOUNDS_CHECK("dir",
                             (int32_T)_SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1,
                             0) - 1] != (*c1_dir)[_SFD_EML_ARRAY_BOUNDS_CHECK(
                             "dir", (int32_T)_SFD_INTEGER_CHECK("sj", (real_T)
                              c1_sj), 1, 4, 1, 0) - 1])) {
                  guard2 = TRUE;
                } else {
                  CV_EML_MCDC(149U, 1, 1, FALSE);
                  CV_EML_IF(149U, 1, 1, FALSE);
                }

                if (guard2 == TRUE) {
                  CV_EML_MCDC(149U, 1, 1, TRUE);
                  CV_EML_IF(149U, 1, 1, TRUE);
                  _SFD_EML_CALL(149U, *c1_sfEvent, 9);
                  (*c1_urstart)[_SFD_EML_ARRAY_BOUNDS_CHECK("urstart", (int32_T)
                    _SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1, 0) - 1] = 1.0;
                  _SFD_EML_CALL(149U, *c1_sfEvent, 10);
                  (*c1_urstopped)[_SFD_EML_ARRAY_BOUNDS_CHECK("urstopped",
                    (int32_T)_SFD_INTEGER_CHECK("si", c1_si), 1, 4, 1, 0) - 1] =
                    0.0;
                }
              } else {
                guard1 = TRUE;
              }
            } else {
              guard1 = TRUE;
            }

            if (guard1 == TRUE) {
              CV_EML_MCDC(149U, 1, 0, FALSE);
              CV_EML_IF(149U, 1, 0, FALSE);
            }

            c1_c_index++;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }

          CV_EML_FOR(149U, 1, 0, 0);
          _SFD_EML_CALL(149U, *c1_sfEvent, -10);
          sf_debug_symbol_scope_pop();
          *c1_b_i = c1__s32_add__(chartInstance, *c1_b_i, 1);
          _SFD_DATA_RANGE_CHECK((real_T)*c1_b_i, 21U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 153U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_UrgentController = c1_IN_D1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 150U, *c1_sfEvent);
          *c1_t = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_t, 20U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 153U, *c1_sfEvent);
        }
        break;

       default:
        CV_STATE_EVAL(148, 0, 0);
        *c1_is_UrgentController = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 150U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 148U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 130U, *c1_sfEvent);
      switch (*c1_is_Train3) {
       case c1_IN_ChangeDirection:
        CV_STATE_EVAL(130, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 131U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 99U, *c1_sfEvent);
        c1_qd_out = (CV_TRANSITION_EVAL(99U, (int32_T)_SFD_CCP_CALL(99U, 0,
          *c1_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_qd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 99U, *c1_sfEvent);
          (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] =
            c1__s32_uminus__(chartInstance, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                             (17U, *c1_c_i, 0, 3, 1, 0)]);
          for (c1_i162 = 0; c1_i162 < 4; c1_i162++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i162], 17U);
          }

          c1_i163 = (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)];
          sf_mex_printf("%s =\\n", "dir[i]");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i163);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i164 = 0; c1_i164 < 4; c1_i164++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i164], 3U);
          }

          c1_d47 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d47);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i165 = 0; c1_i165 < 4; c1_i165++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i165], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 131U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 138U, *c1_sfEvent);
          *c1_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 131U, *c1_sfEvent);
        }
        break;

       case c1_IN_init:
        CV_STATE_EVAL(130, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 132U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 95U, *c1_sfEvent);
        c1_rd_out = (CV_TRANSITION_EVAL(95U, (int32_T)_SFD_CCP_CALL(95U, 0,
          *c1_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_c_i, 0, 3, 2,
          0)] != 0U, *c1_sfEvent)) != 0);
        if (c1_rd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 95U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i166 = 0; c1_i166 < 4; c1_i166++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i166], 3U);
          }

          c1_d48 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d48);
          *c1_b_j = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_j, 67U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 132U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 138U, *c1_sfEvent);
          *c1_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 132U, *c1_sfEvent);
        }
        break;

       case c1_IN_near:
        CV_STATE_EVAL(130, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 133U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 96U, *c1_sfEvent);
        c1_sd_out = (CV_TRANSITION_EVAL(96U, (int32_T)_SFD_CCP_CALL(96U, 0,
          muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_sd_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 96;
            sf_debug_transition_conflict_check_begin();
            c1_td_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_td_out) {
              transitionList[numTransitions] = 97;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 96U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i167 = 0; c1_i167 < 4; c1_i167++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i167], 3U);
          }

          c1_d49 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d49);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i168 = 0; c1_i168 < 4; c1_i168++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i168], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 133U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 138U, *c1_sfEvent);
          *c1_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 97U, *c1_sfEvent);
          c1_ud_out = (CV_TRANSITION_EVAL(97U, (int32_T)_SFD_CCP_CALL(97U, 0,
            (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3, 1, 0)] ==
            1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ud_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 97U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 133U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 133U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_recover:
        CV_STATE_EVAL(130, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 134U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 90U, *c1_sfEvent);
        c1_vd_out = (CV_TRANSITION_EVAL(90U, (int32_T)_SFD_CCP_CALL(90U, 0,
          (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_vd_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 90U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 134U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_urgent_dec;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 91U, *c1_sfEvent);
          c1_wd_out = (CV_TRANSITION_EVAL(91U, (int32_T)_SFD_CCP_CALL(91U, 0,
            muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_wd_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 91U, *c1_sfEvent);
            (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 1.0;
            for (c1_i169 = 0; c1_i169 < 4; c1_i169++) {
              _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i169], 3U);
            }

            c1_d50 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
            sf_mex_printf("%s =\\n", "stop[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d50);
            *c1_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
            c1_d51 = *c1_v;
            sf_mex_printf("%s =\\n", "v");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d51);
            (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] = 0.0;
            for (c1_i170 = 0; c1_i170 < 4; c1_i170++) {
              _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i170], 2U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 134U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_stop;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 138U, *c1_sfEvent);
            *c1_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_v, 66U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 134U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_run:
        CV_STATE_EVAL(130, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 135U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 107U, *c1_sfEvent);
        c1_xd_out = (CV_TRANSITION_EVAL(107U, (int32_T)_SFD_CCP_CALL(107U, 0,
          muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_xd_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 107;
            sf_debug_transition_conflict_check_begin();
            c1_yd_out = (*c1_v >= 20.0);
            if (c1_yd_out) {
              transitionList[numTransitions] = 108;
              numTransitions++;
            }

            c1_ae_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_ae_out) {
              transitionList[numTransitions] = 100;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 107U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_acc = -muDoubleScalarPower(*c1_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_acc, 72U);
          c1_d52 = *c1_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d52);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 135U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 133U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 108U, *c1_sfEvent);
          c1_be_out = (CV_TRANSITION_EVAL(108U, (int32_T)_SFD_CCP_CALL(108U, 0, *
            c1_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_be_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 108;
              sf_debug_transition_conflict_check_begin();
              c1_ce_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0,
                3, 1, 0)] == 1.0);
              if (c1_ce_out) {
                transitionList[numTransitions] = 100;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 108U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 135U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_stablerun;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 137U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 100U, *c1_sfEvent);
            c1_de_out = (CV_TRANSITION_EVAL(100U, (int32_T)_SFD_CCP_CALL(100U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_de_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 100U, *c1_sfEvent);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 135U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train3 = c1_IN_urgent_dec;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 135U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_select:
        CV_STATE_EVAL(130, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 136U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 148U, *c1_sfEvent);
        c1_ee_out = (CV_TRANSITION_EVAL(148U, (int32_T)_SFD_CCP_CALL(148U, 0,
          *c1_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ee_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 148;
            sf_debug_transition_conflict_check_begin();
            c1_fe_out = (*c1_maxv <= 20.0);
            if (c1_fe_out) {
              transitionList[numTransitions] = 89;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 148U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 136U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_run;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 135U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 89U, *c1_sfEvent);
          c1_ge_out = (CV_TRANSITION_EVAL(89U, (int32_T)_SFD_CCP_CALL(89U, 0,
            *c1_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ge_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 89U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 136U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_urgent_inc;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 141U, *c1_sfEvent);
            (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_c_i, 0, 3, 1, 0)] =
              0.0;
            for (c1_i171 = 0; c1_i171 < 4; c1_i171++) {
              _SFD_DATA_RANGE_CHECK((*c1_urstart)[c1_i171], 11U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 136U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stablerun:
        CV_STATE_EVAL(130, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 137U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 106U, *c1_sfEvent);
        c1_he_out = (CV_TRANSITION_EVAL(106U, (int32_T)_SFD_CCP_CALL(106U, 0,
          muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_he_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 106;
            sf_debug_transition_conflict_check_begin();
            c1_ie_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_ie_out) {
              transitionList[numTransitions] = 101;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 106U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_acc = -muDoubleScalarPower(*c1_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_acc, 72U);
          c1_d53 = *c1_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d53);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 137U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 133U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 101U, *c1_sfEvent);
          c1_je_out = (CV_TRANSITION_EVAL(101U, (int32_T)_SFD_CCP_CALL(101U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_je_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 101U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 137U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 137U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stop:
        CV_STATE_EVAL(130, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 138U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 98U, *c1_sfEvent);
        c1_ke_out = (CV_TRANSITION_EVAL(98U, (int32_T)_SFD_CCP_CALL(98U, 0,
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_ke_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 98U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i172 = 0; c1_i172 < 4; c1_i172++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i172], 3U);
          }

          c1_d54 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_c_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d54);
          *c1_time = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_time, 69U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 138U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_b_IN_tmp;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 139U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 138U, *c1_sfEvent);
        }
        break;

       case c1_b_IN_tmp:
        CV_STATE_EVAL(130, 0, 9);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 139U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 104U, *c1_sfEvent);
        c1_r_temp = (_SFD_CCP_CALL(104U, 0, *c1_b_j == 0.0 != 0U, *c1_sfEvent)
                     != 0);
        if (c1_r_temp) {
          c1_r_temp = (_SFD_CCP_CALL(104U, 1, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
            (17U, *c1_c_i, 0, 3, 1, 0)] == -1 != 0U, *c1_sfEvent) != 0);
        }

        c1_le_out = (CV_TRANSITION_EVAL(104U, (int32_T)c1_r_temp) != 0);
        if (c1_le_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 104;
            sf_debug_transition_conflict_check_begin();
            c1_s_temp = (*c1_b_j == (real_T)c1__s32_minus__(chartInstance, *c1_N,
              1));
            if (c1_s_temp) {
              c1_s_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3,
                1, 0)] == 1);
            }

            c1_me_out = c1_s_temp;
            if (c1_me_out) {
              transitionList[numTransitions] = 105;
              numTransitions++;
            }

            c1_t_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1,
              0)] == 1);
            if (c1_t_temp) {
              c1_t_temp = (*c1_b_j < (real_T)c1__s32_minus__(chartInstance,
                *c1_N, 1));
            }

            c1_u_temp = c1_t_temp;
            if (!c1_u_temp) {
              c1_v_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3,
                1, 0)] == -1);
              if (c1_v_temp) {
                c1_v_temp = (*c1_b_j > 0.0);
              }

              c1_u_temp = c1_v_temp;
            }

            c1_ne_out = c1_u_temp;
            if (c1_ne_out) {
              transitionList[numTransitions] = 103;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 104U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 139U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_ChangeDirection;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 131U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 105U, *c1_sfEvent);
          c1_w_temp = (_SFD_CCP_CALL(105U, 0, *c1_b_j == (real_T)c1__s32_minus__
                        (chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
          if (c1_w_temp) {
            c1_w_temp = (_SFD_CCP_CALL(105U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_oe_out = (CV_TRANSITION_EVAL(105U, (int32_T)c1_w_temp) != 0);
          if (c1_oe_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 105;
              sf_debug_transition_conflict_check_begin();
              c1_x_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3,
                1, 0)] == 1);
              if (c1_x_temp) {
                c1_x_temp = (*c1_b_j < (real_T)c1__s32_minus__(chartInstance,
                  *c1_N, 1));
              }

              c1_y_temp = c1_x_temp;
              if (!c1_y_temp) {
                c1_ab_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0,
                  3, 1, 0)] == -1);
                if (c1_ab_temp) {
                  c1_ab_temp = (*c1_b_j > 0.0);
                }

                c1_y_temp = c1_ab_temp;
              }

              c1_pe_out = c1_y_temp;
              if (c1_pe_out) {
                transitionList[numTransitions] = 103;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 105U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 139U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_ChangeDirection;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 131U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 103U, *c1_sfEvent);
            c1_bb_temp = (_SFD_CCP_CALL(103U, 0, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
            if (c1_bb_temp) {
              c1_bb_temp = (_SFD_CCP_CALL(103U, 1, *c1_b_j < (real_T)
                c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) !=
                            0);
            }

            c1_cb_temp = c1_bb_temp;
            if (!c1_cb_temp) {
              c1_db_temp = (_SFD_CCP_CALL(103U, 2, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == -1 != 0U,
                *c1_sfEvent) != 0);
              if (c1_db_temp) {
                c1_db_temp = (_SFD_CCP_CALL(103U, 3, *c1_b_j > 0.0 != 0U,
                  *c1_sfEvent) != 0);
              }

              c1_cb_temp = c1_db_temp;
            }

            c1_qe_out = (CV_TRANSITION_EVAL(103U, (int32_T)c1_cb_temp) != 0);
            if (c1_qe_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 103U, *c1_sfEvent);
              *c1_b_j += (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
                0, 3, 1, 0)];
              _SFD_DATA_RANGE_CHECK(*c1_b_j, 67U);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 139U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train3 = c1_IN_run;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 135U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 139U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_urgent_dec:
        CV_STATE_EVAL(130, 0, 10);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 140U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U, *c1_sfEvent);
        c1_re_out = (CV_TRANSITION_EVAL(93U, (int32_T)_SFD_CCP_CALL(93U, 0,
          *c1_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
        if (c1_re_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, *c1_sfEvent);
          (*c1_urstopped)[_SFD_ARRAY_BOUNDS_CHECK(16U, *c1_c_i, 0, 3, 1, 0)] =
            1.0;
          for (c1_i173 = 0; c1_i173 < 4; c1_i173++) {
            _SFD_DATA_RANGE_CHECK((*c1_urstopped)[c1_i173], 16U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 140U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_urgent_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 142U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 140U, *c1_sfEvent);
        }
        break;

       case c1_IN_urgent_inc:
        CV_STATE_EVAL(130, 0, 11);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 141U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 88U, *c1_sfEvent);
        c1_se_out = (CV_TRANSITION_EVAL(88U, (int32_T)_SFD_CCP_CALL(88U, 0,
          *c1_v >= *c1_maxv != 0U, *c1_sfEvent)) != 0);
        if (c1_se_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 88;
            sf_debug_transition_conflict_check_begin();
            c1_te_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_te_out) {
              transitionList[numTransitions] = 92;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 88U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 141U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_recover;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 134U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 92U, *c1_sfEvent);
          c1_ue_out = (CV_TRANSITION_EVAL(92U, (int32_T)_SFD_CCP_CALL(92U, 0,
            (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3, 1, 0)] ==
            1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ue_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 92U, *c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 141U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train3 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 140U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 141U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_urgent_stop:
        CV_STATE_EVAL(130, 0, 12);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 142U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 149U, *c1_sfEvent);
        c1_ve_out = (CV_TRANSITION_EVAL(149U, (int32_T)_SFD_CCP_CALL(149U, 0,
          (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_c_i, 0, 3, 1, 0)] ==
          1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ve_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 149U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 142U, *c1_sfEvent);
          *c1_maxv = muDoubleScalarSqrt(0.5 * muDoubleScalarAbs((*c1_S)
            [_SFD_ARRAY_BOUNDS_CHECK(10U, c1__s32_d_(chartInstance, *c1_b_j), 0,
            3, 2, 0)] - *c1_b_distance));
          _SFD_DATA_RANGE_CHECK(*c1_maxv, 68U);
          c1_d55 = *c1_maxv;
          sf_mex_printf("%s =\\n", "maxv");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d55);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 142U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 142U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train3 = c1_IN_select;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 136U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 142U, *c1_sfEvent);
        }
        break;

       default:
        CV_STATE_EVAL(130, 0, 0);
        *c1_is_Train3 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 131U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 130U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, *c1_sfEvent);
      switch (*c1_is_Controller1) {
       case c1_IN_about_to_close1:
        CV_STATE_EVAL(9, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 112U, *c1_sfEvent);
        c1_we_out = (CV_TRANSITION_EVAL(112U, (int32_T)_SFD_CCP_CALL(112U, 0,
          *c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_we_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 112U, *c1_sfEvent);
          (*c1_closeTD)[_SFD_ARRAY_BOUNDS_CHECK(9U, *c1_d_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i174 = 0; c1_i174 < 4; c1_i174++) {
            _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i174], 9U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_close2:
        CV_STATE_EVAL(9, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 110U, *c1_sfEvent);
        c1_xe_out = (CV_TRANSITION_EVAL(110U, (int32_T)_SFD_CCP_CALL(110U, 0,
          (int16_T)(*c1_is_Train1_door == c1_IN_closed) == 0 != 0U, *c1_sfEvent))
                     != 0);
        if (c1_xe_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 110;
            sf_debug_transition_conflict_check_begin();
            c1_ye_out = (*c1_b_z >= 5.0);
            if (c1_ye_out) {
              transitionList[numTransitions] = 113;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 110U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 113U, *c1_sfEvent);
          c1_af_out = (CV_TRANSITION_EVAL(113U, (int32_T)_SFD_CCP_CALL(113U, 0, *
            c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_af_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 113U, *c1_sfEvent);
            (*c1_closePSD)[_SFD_ARRAY_BOUNDS_CHECK(5U, c1__s32_d_(chartInstance,
              *c1_b_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(5U,
              c1__s32_d_(chartInstance, *c1_b_side), 0, 1, 2, 0) << 2)] = 1.0;
            for (c1_i175 = 0; c1_i175 < 8; c1_i175++) {
              _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i175], 5U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller1 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *c1_sfEvent);
            *c1_b_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_about_to_open1:
        CV_STATE_EVAL(9, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 119U, *c1_sfEvent);
        c1_bf_out = (CV_TRANSITION_EVAL(119U, (int32_T)_SFD_CCP_CALL(119U, 0,
          *c1_b_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_bf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, *c1_sfEvent);
          (*c1_openTD)[_SFD_ARRAY_BOUNDS_CHECK(8U, *c1_d_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i176 = 0; c1_i176 < 4; c1_i176++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i176], 8U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_open2:
        CV_STATE_EVAL(9, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 117U, *c1_sfEvent);
        c1_cf_out = (CV_TRANSITION_EVAL(117U, (int32_T)_SFD_CCP_CALL(117U, 0,
          *c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_cf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 117U, *c1_sfEvent);
          (*c1_openPSD)[_SFD_ARRAY_BOUNDS_CHECK(4U, c1__s32_d_(chartInstance,
            *c1_b_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(4U,
            c1__s32_d_(chartInstance, *c1_b_side), 0, 1, 2, 0) << 2)] = 1.0;
          for (c1_i177 = 0; c1_i177 < 8; c1_i177++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i177], 4U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_about_to_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *c1_sfEvent);
        }
        break;

       case c1_IN_idle:
        CV_STATE_EVAL(9, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 114U, *c1_sfEvent);
        c1_df_out = (CV_TRANSITION_EVAL(114U, (int32_T)_SFD_CCP_CALL(114U, 0,
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3, 2, 0)] == 1.0 !=
          0U, *c1_sfEvent)) != 0);
        if (c1_df_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 114;
            sf_debug_transition_conflict_check_begin();
            c1_eb_temp = (*c1_b_z >= 1.0);
            if (c1_eb_temp) {
              c1_eb_temp = ((*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3,
                2, 0)] != 1.0);
            }

            c1_ef_out = c1_eb_temp;
            if (c1_ef_out) {
              transitionList[numTransitions] = 116;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 114U, *c1_sfEvent);
          *c1_d_i = 1;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_d_i, 29U);
          c1_i178 = *c1_d_i;
          sf_mex_printf("%s =\\n", "i");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i178);
          *c1_b_stationid = *c1_c_j;
          _SFD_DATA_RANGE_CHECK(*c1_b_stationid, 27U);
          c1_d56 = *c1_b_stationid;
          sf_mex_printf("%s =\\n", "stationid");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d56);
          c1_i179 = c1__s32_add__(chartInstance, (*c1_dir)
            [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i, 0, 3, 1, 0)], 1);
          *c1_b_side = (real_T)((c1_i179 + (c1_i179 < 0)) >> 1);
          _SFD_DATA_RANGE_CHECK(*c1_b_side, 28U);
          c1_d57 = *c1_b_side;
          sf_mex_printf("%s =\\n", "side");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d57);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_about_to_open2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i180 = 0; c1_i180 < 4; c1_i180++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i180], 3U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 116U, *c1_sfEvent);
          c1_fb_temp = (_SFD_CCP_CALL(116U, 0, *c1_b_z >= 1.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_fb_temp) {
            c1_fb_temp = (_SFD_CCP_CALL(116U, 1, (*c1_stop)
              [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3, 2, 0)] != 1.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_ff_out = (CV_TRANSITION_EVAL(116U, (int32_T)c1_fb_temp) != 0);
          if (c1_ff_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 116U, *c1_sfEvent);
            (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_d_i, 0, 3, 1, 0)] = *
              c1_c_distance;
            for (c1_i181 = 0; c1_i181 < 4; c1_i181++) {
              _SFD_DATA_RANGE_CHECK((*c1_position)[c1_i181], 18U);
            }

            c1_d58 = (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_d_i, 0, 3,
              1, 0)];
            sf_mex_printf("%s =\\n", "position[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d58);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller1 = c1_IN_idle;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *c1_sfEvent);
            *c1_b_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_open1:
        CV_STATE_EVAL(9, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 118U, *c1_sfEvent);
        c1_gf_out = (CV_TRANSITION_EVAL(118U, (int32_T)_SFD_CCP_CALL(118U, 0,
          *c1_b_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_gf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 118U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_ring;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *c1_sfEvent);
        }
        break;

       case c1_IN_ring:
        CV_STATE_EVAL(9, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 120U, *c1_sfEvent);
        c1_gb_temp = (_SFD_CCP_CALL(120U, 0, *c1_b_z >= 20.0 != 0U, *c1_sfEvent)
                      != 0);
        if (c1_gb_temp) {
          c1_gb_temp = (_SFD_CCP_CALL(120U, 1, *c1_b_z <= 30.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_hf_out = (CV_TRANSITION_EVAL(120U, (int32_T)c1_gb_temp) != 0);
        if (c1_hf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 120U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_about_to_close1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *c1_sfEvent);
        }
        break;

       case c1_IN_start:
        CV_STATE_EVAL(9, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 115U, *c1_sfEvent);
        c1_if_out = (CV_TRANSITION_EVAL(115U, (int32_T)_SFD_CCP_CALL(115U, 0,
          *c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_if_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 115;
            sf_debug_transition_conflict_check_begin();
            c1_jf_out = ((*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_b_stationid), 0, 3, 1, 0) +
                         (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance,
              *c1_b_side), 0, 1, 2, 0) << 2)] == 0.0);
            if (c1_jf_out) {
              transitionList[numTransitions] = 144;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 115U, *c1_sfEvent);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_d_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i182 = 0; c1_i182 < 4; c1_i182++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i182], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller1 = c1_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *c1_sfEvent);
          *c1_b_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 144U, *c1_sfEvent);
          c1_kf_out = (CV_TRANSITION_EVAL(144U, (int32_T)_SFD_CCP_CALL(144U, 0,
                         (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_b_stationid), 0, 3, 1, 0) +
            (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_b_side),
            0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_kf_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 144U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller1 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *c1_sfEvent);
            *c1_b_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_z, 26U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(9, 0, 0);
        *c1_is_Controller1 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, *c1_sfEvent);
      switch (*c1_is_Controller2) {
       case c1_IN_about_to_close1:
        CV_STATE_EVAL(18, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 123U, *c1_sfEvent);
        c1_lf_out = (CV_TRANSITION_EVAL(123U, (int32_T)_SFD_CCP_CALL(123U, 0,
          *c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_lf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 123U, *c1_sfEvent);
          (*c1_closeTD)[_SFD_ARRAY_BOUNDS_CHECK(9U, *c1_e_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i183 = 0; c1_i183 < 4; c1_i183++) {
            _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i183], 9U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_close2:
        CV_STATE_EVAL(18, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 121U, *c1_sfEvent);
        c1_mf_out = (CV_TRANSITION_EVAL(121U, (int32_T)_SFD_CCP_CALL(121U, 0,
          (int16_T)(*c1_is_Train2_door == c1_IN_closed) == 0 != 0U, *c1_sfEvent))
                     != 0);
        if (c1_mf_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 121;
            sf_debug_transition_conflict_check_begin();
            c1_nf_out = (*c1_c_z >= 5.0);
            if (c1_nf_out) {
              transitionList[numTransitions] = 124;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 121U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 124U, *c1_sfEvent);
          c1_of_out = (CV_TRANSITION_EVAL(124U, (int32_T)_SFD_CCP_CALL(124U, 0, *
            c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_of_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 124U, *c1_sfEvent);
            (*c1_closePSD)[_SFD_ARRAY_BOUNDS_CHECK(5U, c1__s32_d_(chartInstance,
              *c1_c_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(5U,
              c1__s32_d_(chartInstance, *c1_c_side), 0, 1, 2, 0) << 2)] = 1.0;
            for (c1_i184 = 0; c1_i184 < 8; c1_i184++) {
              _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i184], 5U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller2 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *c1_sfEvent);
            *c1_c_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_about_to_open1:
        CV_STATE_EVAL(18, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 130U, *c1_sfEvent);
        c1_pf_out = (CV_TRANSITION_EVAL(130U, (int32_T)_SFD_CCP_CALL(130U, 0,
          *c1_c_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_pf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 130U, *c1_sfEvent);
          (*c1_openTD)[_SFD_ARRAY_BOUNDS_CHECK(8U, *c1_e_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i185 = 0; c1_i185 < 4; c1_i185++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i185], 8U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_open2:
        CV_STATE_EVAL(18, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 128U, *c1_sfEvent);
        c1_qf_out = (CV_TRANSITION_EVAL(128U, (int32_T)_SFD_CCP_CALL(128U, 0,
          *c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_qf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 128U, *c1_sfEvent);
          (*c1_openPSD)[_SFD_ARRAY_BOUNDS_CHECK(4U, c1__s32_d_(chartInstance,
            *c1_c_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(4U,
            c1__s32_d_(chartInstance, *c1_c_side), 0, 1, 2, 0) << 2)] = 1.0;
          for (c1_i186 = 0; c1_i186 < 8; c1_i186++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i186], 4U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_about_to_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c1_sfEvent);
        }
        break;

       case c1_IN_idle:
        CV_STATE_EVAL(18, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 125U, *c1_sfEvent);
        c1_rf_out = (CV_TRANSITION_EVAL(125U, (int32_T)_SFD_CCP_CALL(125U, 0,
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3, 2, 0)] == 1.0 !=
          0U, *c1_sfEvent)) != 0);
        if (c1_rf_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 125;
            sf_debug_transition_conflict_check_begin();
            c1_hb_temp = (*c1_c_z >= 1.0);
            if (c1_hb_temp) {
              c1_hb_temp = ((*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3,
                2, 0)] != 1.0);
            }

            c1_sf_out = c1_hb_temp;
            if (c1_sf_out) {
              transitionList[numTransitions] = 127;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 125U, *c1_sfEvent);
          *c1_e_i = 2;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_e_i, 57U);
          c1_i187 = *c1_e_i;
          sf_mex_printf("%s =\\n", "i");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i187);
          *c1_c_stationid = *c1_d_j;
          _SFD_DATA_RANGE_CHECK(*c1_c_stationid, 55U);
          c1_d59 = *c1_c_stationid;
          sf_mex_printf("%s =\\n", "stationid");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d59);
          c1_i188 = c1__s32_add__(chartInstance, (*c1_dir)
            [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_e_i, 0, 3, 1, 0)], 1);
          *c1_c_side = (real_T)((c1_i188 + (c1_i188 < 0)) >> 1);
          _SFD_DATA_RANGE_CHECK(*c1_c_side, 56U);
          c1_d60 = *c1_c_side;
          sf_mex_printf("%s =\\n", "side");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d60);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_about_to_open2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i189 = 0; c1_i189 < 4; c1_i189++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i189], 3U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 127U, *c1_sfEvent);
          c1_ib_temp = (_SFD_CCP_CALL(127U, 0, *c1_c_z >= 1.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_ib_temp) {
            c1_ib_temp = (_SFD_CCP_CALL(127U, 1, (*c1_stop)
              [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3, 2, 0)] != 1.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_tf_out = (CV_TRANSITION_EVAL(127U, (int32_T)c1_ib_temp) != 0);
          if (c1_tf_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 127U, *c1_sfEvent);
            (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_e_i, 0, 3, 1, 0)] = *
              c1_d_distance;
            for (c1_i190 = 0; c1_i190 < 4; c1_i190++) {
              _SFD_DATA_RANGE_CHECK((*c1_position)[c1_i190], 18U);
            }

            c1_d61 = (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_e_i, 0, 3,
              1, 0)];
            sf_mex_printf("%s =\\n", "position[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d61);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller2 = c1_IN_idle;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *c1_sfEvent);
            *c1_c_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_open1:
        CV_STATE_EVAL(18, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 129U, *c1_sfEvent);
        c1_uf_out = (CV_TRANSITION_EVAL(129U, (int32_T)_SFD_CCP_CALL(129U, 0,
          *c1_c_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_uf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 129U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_ring;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *c1_sfEvent);
        }
        break;

       case c1_IN_ring:
        CV_STATE_EVAL(18, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 131U, *c1_sfEvent);
        c1_jb_temp = (_SFD_CCP_CALL(131U, 0, *c1_c_z >= 20.0 != 0U, *c1_sfEvent)
                      != 0);
        if (c1_jb_temp) {
          c1_jb_temp = (_SFD_CCP_CALL(131U, 1, *c1_c_z <= 30.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_vf_out = (CV_TRANSITION_EVAL(131U, (int32_T)c1_jb_temp) != 0);
        if (c1_vf_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 131U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_about_to_close1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *c1_sfEvent);
        }
        break;

       case c1_IN_start:
        CV_STATE_EVAL(18, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 126U, *c1_sfEvent);
        c1_wf_out = (CV_TRANSITION_EVAL(126U, (int32_T)_SFD_CCP_CALL(126U, 0,
          *c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_wf_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 126;
            sf_debug_transition_conflict_check_begin();
            c1_xf_out = ((*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_c_stationid), 0, 3, 1, 0) +
                         (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance,
              *c1_c_side), 0, 1, 2, 0) << 2)] == 0.0);
            if (c1_xf_out) {
              transitionList[numTransitions] = 145;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 126U, *c1_sfEvent);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_e_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i191 = 0; c1_i191 < 4; c1_i191++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i191], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller2 = c1_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *c1_sfEvent);
          *c1_c_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 145U, *c1_sfEvent);
          c1_yf_out = (CV_TRANSITION_EVAL(145U, (int32_T)_SFD_CCP_CALL(145U, 0,
                         (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_c_stationid), 0, 3, 1, 0) +
            (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_c_side),
            0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yf_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 145U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller2 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *c1_sfEvent);
            *c1_c_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_z, 54U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(18, 0, 0);
        *c1_is_Controller2 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, *c1_sfEvent);
      switch (*c1_is_Controller3) {
       case c1_IN_about_to_close1:
        CV_STATE_EVAL(27, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 134U, *c1_sfEvent);
        c1_ag_out = (CV_TRANSITION_EVAL(134U, (int32_T)_SFD_CCP_CALL(134U, 0,
          *c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ag_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 134U, *c1_sfEvent);
          (*c1_closeTD)[_SFD_ARRAY_BOUNDS_CHECK(9U, *c1_f_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i192 = 0; c1_i192 < 4; c1_i192++) {
            _SFD_DATA_RANGE_CHECK((*c1_closeTD)[c1_i192], 9U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_close2:
        CV_STATE_EVAL(27, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 132U, *c1_sfEvent);
        c1_bg_out = (CV_TRANSITION_EVAL(132U, (int32_T)_SFD_CCP_CALL(132U, 0,
          (int16_T)(*c1_is_Train3_door == c1_IN_closed) == 0 != 0U, *c1_sfEvent))
                     != 0);
        if (c1_bg_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 132;
            sf_debug_transition_conflict_check_begin();
            c1_cg_out = (*c1_d_z >= 5.0);
            if (c1_cg_out) {
              transitionList[numTransitions] = 135;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 132U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_about_to_close2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 135U, *c1_sfEvent);
          c1_dg_out = (CV_TRANSITION_EVAL(135U, (int32_T)_SFD_CCP_CALL(135U, 0, *
            c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_dg_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 135U, *c1_sfEvent);
            (*c1_closePSD)[_SFD_ARRAY_BOUNDS_CHECK(5U, c1__s32_d_(chartInstance,
              *c1_d_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(5U,
              c1__s32_d_(chartInstance, *c1_d_side), 0, 1, 2, 0) << 2)] = 1.0;
            for (c1_i193 = 0; c1_i193 < 8; c1_i193++) {
              _SFD_DATA_RANGE_CHECK((*c1_closePSD)[c1_i193], 5U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller3 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *c1_sfEvent);
            *c1_d_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_about_to_open1:
        CV_STATE_EVAL(27, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 141U, *c1_sfEvent);
        c1_eg_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(141U, 0,
          *c1_d_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_eg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 141U, *c1_sfEvent);
          (*c1_openTD)[_SFD_ARRAY_BOUNDS_CHECK(8U, *c1_f_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i194 = 0; c1_i194 < 4; c1_i194++) {
            _SFD_DATA_RANGE_CHECK((*c1_openTD)[c1_i194], 8U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *c1_sfEvent);
        }
        break;

       case c1_IN_about_to_open2:
        CV_STATE_EVAL(27, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 139U, *c1_sfEvent);
        c1_fg_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(139U, 0,
          *c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_fg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 139U, *c1_sfEvent);
          (*c1_openPSD)[_SFD_ARRAY_BOUNDS_CHECK(4U, c1__s32_d_(chartInstance,
            *c1_d_stationid), 0, 3, 1, 0) + (_SFD_ARRAY_BOUNDS_CHECK(4U,
            c1__s32_d_(chartInstance, *c1_d_side), 0, 1, 2, 0) << 2)] = 1.0;
          for (c1_i195 = 0; c1_i195 < 8; c1_i195++) {
            _SFD_DATA_RANGE_CHECK((*c1_openPSD)[c1_i195], 4U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_about_to_open1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, *c1_sfEvent);
        }
        break;

       case c1_IN_idle:
        CV_STATE_EVAL(27, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 136U, *c1_sfEvent);
        c1_gg_out = (CV_TRANSITION_EVAL(136U, (int32_T)_SFD_CCP_CALL(136U, 0,
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3, 2, 0)] == 1.0 !=
          0U, *c1_sfEvent)) != 0);
        if (c1_gg_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 136;
            sf_debug_transition_conflict_check_begin();
            c1_kb_temp = (*c1_d_z >= 1.0);
            if (c1_kb_temp) {
              c1_kb_temp = ((*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3,
                2, 0)] != 1.0);
            }

            c1_hg_out = c1_kb_temp;
            if (c1_hg_out) {
              transitionList[numTransitions] = 138;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 136U, *c1_sfEvent);
          *c1_f_i = 3;
          _SFD_DATA_RANGE_CHECK((real_T)*c1_f_i, 53U);
          c1_i196 = *c1_f_i;
          sf_mex_printf("%s =\\n", "i");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i196);
          *c1_d_stationid = *c1_b_j;
          _SFD_DATA_RANGE_CHECK(*c1_d_stationid, 51U);
          c1_d62 = *c1_d_stationid;
          sf_mex_printf("%s =\\n", "stationid");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d62);
          c1_i197 = c1__s32_add__(chartInstance, (*c1_dir)
            [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_f_i, 0, 3, 1, 0)], 1);
          *c1_d_side = (real_T)((c1_i197 + (c1_i197 < 0)) >> 1);
          _SFD_DATA_RANGE_CHECK(*c1_d_side, 52U);
          c1_d63 = *c1_d_side;
          sf_mex_printf("%s =\\n", "side");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d63);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_about_to_open2;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i198 = 0; c1_i198 < 4; c1_i198++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i198], 3U);
          }
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 138U, *c1_sfEvent);
          c1_lb_temp = (_SFD_CCP_CALL(138U, 0, *c1_d_z >= 1.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_lb_temp) {
            c1_lb_temp = (_SFD_CCP_CALL(138U, 1, (*c1_stop)
              [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3, 2, 0)] != 1.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_ig_out = (CV_TRANSITION_EVAL(138U, (int32_T)c1_lb_temp) != 0);
          if (c1_ig_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 138U, *c1_sfEvent);
            (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_f_i, 0, 3, 1, 0)] = *
              c1_b_distance;
            for (c1_i199 = 0; c1_i199 < 4; c1_i199++) {
              _SFD_DATA_RANGE_CHECK((*c1_position)[c1_i199], 18U);
            }

            c1_d64 = (*c1_position)[_SFD_ARRAY_BOUNDS_CHECK(18U, *c1_f_i, 0, 3,
              1, 0)];
            sf_mex_printf("%s =\\n", "position[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d64);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller3 = c1_IN_idle;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *c1_sfEvent);
            *c1_d_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_open1:
        CV_STATE_EVAL(27, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 140U, *c1_sfEvent);
        c1_jg_out = (CV_TRANSITION_EVAL(140U, (int32_T)_SFD_CCP_CALL(140U, 0,
          *c1_d_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_jg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 140U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_ring;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *c1_sfEvent);
        }
        break;

       case c1_IN_ring:
        CV_STATE_EVAL(27, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 142U, *c1_sfEvent);
        c1_mb_temp = (_SFD_CCP_CALL(142U, 0, *c1_d_z >= 20.0 != 0U, *c1_sfEvent)
                      != 0);
        if (c1_mb_temp) {
          c1_mb_temp = (_SFD_CCP_CALL(142U, 1, *c1_d_z <= 30.0 != 0U,
            *c1_sfEvent) != 0);
        }

        c1_kg_out = (CV_TRANSITION_EVAL(142U, (int32_T)c1_mb_temp) != 0);
        if (c1_kg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 142U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_about_to_close1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *c1_sfEvent);
        }
        break;

       case c1_IN_start:
        CV_STATE_EVAL(27, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 137U, *c1_sfEvent);
        c1_lg_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(137U, 0,
          *c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_lg_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 137;
            sf_debug_transition_conflict_check_begin();
            c1_mg_out = ((*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_d_stationid), 0, 3, 1, 0) +
                         (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance,
              *c1_d_side), 0, 1, 2, 0) << 2)] == 0.0);
            if (c1_mg_out) {
              transitionList[numTransitions] = 146;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 137U, *c1_sfEvent);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_f_i, 0, 3, 1, 0)] = 1.0;
          for (c1_i200 = 0; c1_i200 < 4; c1_i200++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i200], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Controller3 = c1_IN_idle;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *c1_sfEvent);
          *c1_d_z = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 146U, *c1_sfEvent);
          c1_ng_out = (CV_TRANSITION_EVAL(146U, (int32_T)_SFD_CCP_CALL(146U, 0,
                         (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_
                          (chartInstance, *c1_d_stationid), 0, 3, 1, 0) +
            (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_d_side),
            0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ng_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 146U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Controller3 = c1_IN_start;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *c1_sfEvent);
            *c1_d_z = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_z, 50U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *c1_sfEvent);
          }
        }
        break;

       default:
        CV_STATE_EVAL(27, 0, 0);
        *c1_is_Controller3 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 76U, *c1_sfEvent);
      switch (*c1_is_Train0) {
       case c1_IN_ChangeDirection:
        CV_STATE_EVAL(76, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 77U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 164U, *c1_sfEvent);
        c1_og_out = (CV_TRANSITION_EVAL(164U, (int32_T)_SFD_CCP_CALL(164U, 0,
          *c1_b_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_og_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 164U, *c1_sfEvent);
          (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] =
            c1__s32_uminus__(chartInstance, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                             (17U, *c1_g_i, 0, 3, 1, 0)]);
          for (c1_i201 = 0; c1_i201 < 4; c1_i201++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i201], 17U);
          }

          c1_i202 = (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)];
          sf_mex_printf("%s =\\n", "dir[i]");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i202);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i203 = 0; c1_i203 < 4; c1_i203++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i203], 3U);
          }

          c1_d65 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d65);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i204 = 0; c1_i204 < 4; c1_i204++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i204], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 77U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *c1_sfEvent);
          *c1_b_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 77U, *c1_sfEvent);
        }
        break;

       case c1_IN_init:
        CV_STATE_EVAL(76, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 78U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 160U, *c1_sfEvent);
        c1_pg_out = (CV_TRANSITION_EVAL(160U, (int32_T)_SFD_CCP_CALL(160U, 0,
          *c1_b_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_g_i, 0, 3, 2,
          0)] != 0U, *c1_sfEvent)) != 0);
        if (c1_pg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 160U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i205 = 0; c1_i205 < 4; c1_i205++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i205], 3U);
          }

          c1_d66 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d66);
          *c1_j = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_j, 31U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 78U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *c1_sfEvent);
          *c1_b_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 78U, *c1_sfEvent);
        }
        break;

       case c1_IN_near:
        CV_STATE_EVAL(76, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 79U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 161U, *c1_sfEvent);
        c1_qg_out = (CV_TRANSITION_EVAL(161U, (int32_T)_SFD_CCP_CALL(161U, 0,
          muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_qg_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 161;
            sf_debug_transition_conflict_check_begin();
            c1_rg_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_rg_out) {
              transitionList[numTransitions] = 162;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 161U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i206 = 0; c1_i206 < 4; c1_i206++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i206], 3U);
          }

          c1_d67 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d67);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i207 = 0; c1_i207 < 4; c1_i207++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i207], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 79U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *c1_sfEvent);
          *c1_b_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 162U, *c1_sfEvent);
          c1_sg_out = (CV_TRANSITION_EVAL(162U, (int32_T)_SFD_CCP_CALL(162U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_sg_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 162U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 79U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 79U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_recover:
        CV_STATE_EVAL(76, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 80U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 155U, *c1_sfEvent);
        c1_tg_out = (CV_TRANSITION_EVAL(155U, (int32_T)_SFD_CCP_CALL(155U, 0,
          (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_tg_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 155U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 158U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 80U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_urgent_dec;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 156U, *c1_sfEvent);
          c1_ug_out = (CV_TRANSITION_EVAL(156U, (int32_T)_SFD_CCP_CALL(156U, 0,
            muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
            c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
            *c1_sfEvent)) != 0);
          if (c1_ug_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 156U, *c1_sfEvent);
            (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 1.0;
            for (c1_i208 = 0; c1_i208 < 4; c1_i208++) {
              _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i208], 3U);
            }

            c1_d68 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
            sf_mex_printf("%s =\\n", "stop[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d68);
            *c1_b_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
            c1_d69 = *c1_b_v;
            sf_mex_printf("%s =\\n", "v");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d69);
            (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)] = 0.0;
            for (c1_i209 = 0; c1_i209 < 4; c1_i209++) {
              _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i209], 2U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 80U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_stop;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *c1_sfEvent);
            *c1_b_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_b_v, 30U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 80U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_run:
        CV_STATE_EVAL(76, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 81U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 172U, *c1_sfEvent);
        c1_vg_out = (CV_TRANSITION_EVAL(172U, (int32_T)_SFD_CCP_CALL(172U, 0,
          muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_vg_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 172;
            sf_debug_transition_conflict_check_begin();
            c1_wg_out = (*c1_b_v >= 20.0);
            if (c1_wg_out) {
              transitionList[numTransitions] = 173;
              numTransitions++;
            }

            c1_xg_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_xg_out) {
              transitionList[numTransitions] = 166;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 172U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 165U, *c1_sfEvent);
          *c1_b_acc = -muDoubleScalarPower(*c1_b_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_b_acc, 36U);
          c1_d70 = *c1_b_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d70);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 81U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 173U, *c1_sfEvent);
          c1_yg_out = (CV_TRANSITION_EVAL(173U, (int32_T)_SFD_CCP_CALL(173U, 0, *
            c1_b_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yg_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 173;
              sf_debug_transition_conflict_check_begin();
              c1_ah_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0,
                3, 1, 0)] == 1.0);
              if (c1_ah_out) {
                transitionList[numTransitions] = 166;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 173U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 81U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_stablerun;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 83U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 166U, *c1_sfEvent);
            c1_bh_out = (CV_TRANSITION_EVAL(166U, (int32_T)_SFD_CCP_CALL(166U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_bh_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 166U, *c1_sfEvent);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 81U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train0 = c1_IN_urgent_dec;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 81U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_select:
        CV_STATE_EVAL(76, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 82U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 152U, *c1_sfEvent);
        c1_ch_out = (CV_TRANSITION_EVAL(152U, (int32_T)_SFD_CCP_CALL(152U, 0,
          *c1_b_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ch_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 152;
            sf_debug_transition_conflict_check_begin();
            c1_dh_out = (*c1_b_maxv <= 20.0);
            if (c1_dh_out) {
              transitionList[numTransitions] = 153;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 152U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_run;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 81U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 153U, *c1_sfEvent);
          c1_eh_out = (CV_TRANSITION_EVAL(153U, (int32_T)_SFD_CCP_CALL(153U, 0, *
            c1_b_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_eh_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 153U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_urgent_inc;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 87U, *c1_sfEvent);
            (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_g_i, 0, 3, 1, 0)] =
              0.0;
            for (c1_i210 = 0; c1_i210 < 4; c1_i210++) {
              _SFD_DATA_RANGE_CHECK((*c1_urstart)[c1_i210], 11U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 82U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stablerun:
        CV_STATE_EVAL(76, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 83U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 171U, *c1_sfEvent);
        c1_fh_out = (CV_TRANSITION_EVAL(171U, (int32_T)_SFD_CCP_CALL(171U, 0,
          muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_fh_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 171;
            sf_debug_transition_conflict_check_begin();
            c1_gh_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_gh_out) {
              transitionList[numTransitions] = 167;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 171U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 165U, *c1_sfEvent);
          *c1_b_acc = -muDoubleScalarPower(*c1_b_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_b_acc, 36U);
          c1_d71 = *c1_b_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d71);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 83U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 167U, *c1_sfEvent);
          c1_hh_out = (CV_TRANSITION_EVAL(167U, (int32_T)_SFD_CCP_CALL(167U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_hh_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 167U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 83U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 83U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stop:
        CV_STATE_EVAL(76, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 84U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 163U, *c1_sfEvent);
        c1_ih_out = (CV_TRANSITION_EVAL(163U, (int32_T)_SFD_CCP_CALL(163U, 0,
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_ih_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 163U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i211 = 0; c1_i211 < 4; c1_i211++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i211], 3U);
          }

          c1_d72 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_g_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d72);
          *c1_b_time = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_b_time, 33U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 84U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_b_IN_tmp;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 85U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 84U, *c1_sfEvent);
        }
        break;

       case c1_b_IN_tmp:
        CV_STATE_EVAL(76, 0, 9);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 85U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 169U, *c1_sfEvent);
        c1_nb_temp = (_SFD_CCP_CALL(169U, 0, *c1_j == 0.0 != 0U, *c1_sfEvent) !=
                      0);
        if (c1_nb_temp) {
          c1_nb_temp = (_SFD_CCP_CALL(169U, 1, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                         (17U, *c1_g_i, 0, 3, 1, 0)] == -1 != 0U, *c1_sfEvent)
                        != 0);
        }

        c1_jh_out = (CV_TRANSITION_EVAL(169U, (int32_T)c1_nb_temp) != 0);
        if (c1_jh_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 169;
            sf_debug_transition_conflict_check_begin();
            c1_ob_temp = (*c1_j == (real_T)c1__s32_minus__(chartInstance, *c1_N,
              1));
            if (c1_ob_temp) {
              c1_ob_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3,
                1, 0)] == 1);
            }

            c1_kh_out = c1_ob_temp;
            if (c1_kh_out) {
              transitionList[numTransitions] = 170;
              numTransitions++;
            }

            c1_pb_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3,
              1, 0)] == 1);
            if (c1_pb_temp) {
              c1_pb_temp = (*c1_j < (real_T)c1__s32_minus__(chartInstance, *c1_N,
                1));
            }

            c1_qb_temp = c1_pb_temp;
            if (!c1_qb_temp) {
              c1_rb_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3,
                1, 0)] == -1);
              if (c1_rb_temp) {
                c1_rb_temp = (*c1_j > 0.0);
              }

              c1_qb_temp = c1_rb_temp;
            }

            c1_lh_out = c1_qb_temp;
            if (c1_lh_out) {
              transitionList[numTransitions] = 168;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 169U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_ChangeDirection;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 77U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 170U, *c1_sfEvent);
          c1_sb_temp = (_SFD_CCP_CALL(170U, 0, *c1_j == (real_T)c1__s32_minus__
            (chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
          if (c1_sb_temp) {
            c1_sb_temp = (_SFD_CCP_CALL(170U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_mh_out = (CV_TRANSITION_EVAL(170U, (int32_T)c1_sb_temp) != 0);
          if (c1_mh_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 170;
              sf_debug_transition_conflict_check_begin();
              c1_tb_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3,
                1, 0)] == 1);
              if (c1_tb_temp) {
                c1_tb_temp = (*c1_j < (real_T)c1__s32_minus__(chartInstance,
                  *c1_N, 1));
              }

              c1_ub_temp = c1_tb_temp;
              if (!c1_ub_temp) {
                c1_vb_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0,
                  3, 1, 0)] == -1);
                if (c1_vb_temp) {
                  c1_vb_temp = (*c1_j > 0.0);
                }

                c1_ub_temp = c1_vb_temp;
              }

              c1_nh_out = c1_ub_temp;
              if (c1_nh_out) {
                transitionList[numTransitions] = 168;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 170U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_ChangeDirection;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 77U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 168U, *c1_sfEvent);
            c1_wb_temp = (_SFD_CCP_CALL(168U, 0, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
            if (c1_wb_temp) {
              c1_wb_temp = (_SFD_CCP_CALL(168U, 1, *c1_j < (real_T)
                c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) !=
                            0);
            }

            c1_xb_temp = c1_wb_temp;
            if (!c1_xb_temp) {
              c1_yb_temp = (_SFD_CCP_CALL(168U, 2, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == -1 != 0U,
                *c1_sfEvent) != 0);
              if (c1_yb_temp) {
                c1_yb_temp = (_SFD_CCP_CALL(168U, 3, *c1_j > 0.0 != 0U,
                  *c1_sfEvent) != 0);
              }

              c1_xb_temp = c1_yb_temp;
            }

            c1_oh_out = (CV_TRANSITION_EVAL(168U, (int32_T)c1_xb_temp) != 0);
            if (c1_oh_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 168U, *c1_sfEvent);
              *c1_j += (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0,
                3, 1, 0)];
              _SFD_DATA_RANGE_CHECK(*c1_j, 31U);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train0 = c1_IN_run;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 81U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_urgent_dec:
        CV_STATE_EVAL(76, 0, 10);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 86U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 159U, *c1_sfEvent);
        c1_ph_out = (CV_TRANSITION_EVAL(159U, (int32_T)_SFD_CCP_CALL(159U, 0,
          *c1_b_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
        if (c1_ph_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 159U, *c1_sfEvent);
          (*c1_urstopped)[_SFD_ARRAY_BOUNDS_CHECK(16U, *c1_g_i, 0, 3, 1, 0)] =
            1.0;
          for (c1_i212 = 0; c1_i212 < 4; c1_i212++) {
            _SFD_DATA_RANGE_CHECK((*c1_urstopped)[c1_i212], 16U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 86U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_urgent_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 88U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 86U, *c1_sfEvent);
        }
        break;

       case c1_IN_urgent_inc:
        CV_STATE_EVAL(76, 0, 11);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 87U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 151U, *c1_sfEvent);
        c1_qh_out = (CV_TRANSITION_EVAL(151U, (int32_T)_SFD_CCP_CALL(151U, 0,
          *c1_b_v >= *c1_b_maxv != 0U, *c1_sfEvent)) != 0);
        if (c1_qh_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 151;
            sf_debug_transition_conflict_check_begin();
            c1_rh_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_rh_out) {
              transitionList[numTransitions] = 157;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 151U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_recover;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 80U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 157U, *c1_sfEvent);
          c1_sh_out = (CV_TRANSITION_EVAL(157U, (int32_T)_SFD_CCP_CALL(157U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_sh_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 157U, *c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 158U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train0 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 87U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_urgent_stop:
        CV_STATE_EVAL(76, 0, 12);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 88U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 154U, *c1_sfEvent);
        c1_th_out = (CV_TRANSITION_EVAL(154U, (int32_T)_SFD_CCP_CALL(154U, 0,
          (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_g_i, 0, 3, 1, 0)] ==
          1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_th_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 154U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 88U, *c1_sfEvent);
          *c1_b_maxv = muDoubleScalarSqrt(0.5 * muDoubleScalarAbs((*c1_S)
            [_SFD_ARRAY_BOUNDS_CHECK(10U, c1__s32_d_(chartInstance, *c1_j), 0, 3,
            2, 0)] - *c1_distance));
          _SFD_DATA_RANGE_CHECK(*c1_b_maxv, 32U);
          c1_d73 = *c1_b_maxv;
          sf_mex_printf("%s =\\n", "maxv");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d73);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 88U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train0 = c1_IN_select;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 82U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *c1_sfEvent);
        }
        break;

       default:
        CV_STATE_EVAL(76, 0, 0);
        *c1_is_Train0 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 77U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 76U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 94U, *c1_sfEvent);
      switch (*c1_is_Train1) {
       case c1_IN_ChangeDirection:
        CV_STATE_EVAL(94, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 95U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 188U, *c1_sfEvent);
        c1_uh_out = (CV_TRANSITION_EVAL(188U, (int32_T)_SFD_CCP_CALL(188U, 0,
          *c1_c_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_uh_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 188U, *c1_sfEvent);
          (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] =
            c1__s32_uminus__(chartInstance, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                             (17U, *c1_h_i, 0, 3, 1, 0)]);
          for (c1_i213 = 0; c1_i213 < 4; c1_i213++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i213], 17U);
          }

          c1_i214 = (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)];
          sf_mex_printf("%s =\\n", "dir[i]");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i214);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i215 = 0; c1_i215 < 4; c1_i215++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i215], 3U);
          }

          c1_d74 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d74);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i216 = 0; c1_i216 < 4; c1_i216++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i216], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 95U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_c_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 95U, *c1_sfEvent);
        }
        break;

       case c1_IN_init:
        CV_STATE_EVAL(94, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 96U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 184U, *c1_sfEvent);
        c1_vh_out = (CV_TRANSITION_EVAL(184U, (int32_T)_SFD_CCP_CALL(184U, 0,
          *c1_c_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_h_i, 0, 3, 2,
          0)] != 0U, *c1_sfEvent)) != 0);
        if (c1_vh_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 184U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i217 = 0; c1_i217 < 4; c1_i217++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i217], 3U);
          }

          c1_d75 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d75);
          *c1_c_j = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_j, 44U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 96U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_c_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 96U, *c1_sfEvent);
        }
        break;

       case c1_IN_near:
        CV_STATE_EVAL(94, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 97U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 185U, *c1_sfEvent);
        c1_wh_out = (CV_TRANSITION_EVAL(185U, (int32_T)_SFD_CCP_CALL(185U, 0,
          muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_wh_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 185;
            sf_debug_transition_conflict_check_begin();
            c1_xh_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_xh_out) {
              transitionList[numTransitions] = 186;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 185U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i218 = 0; c1_i218 < 4; c1_i218++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i218], 3U);
          }

          c1_d76 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d76);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i219 = 0; c1_i219 < 4; c1_i219++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i219], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 97U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_c_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 186U, *c1_sfEvent);
          c1_yh_out = (CV_TRANSITION_EVAL(186U, (int32_T)_SFD_CCP_CALL(186U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yh_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 186U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 97U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 97U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_recover:
        CV_STATE_EVAL(94, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 98U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 179U, *c1_sfEvent);
        c1_ai_out = (CV_TRANSITION_EVAL(179U, (int32_T)_SFD_CCP_CALL(179U, 0,
          (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_ai_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 179U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 182U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_urgent_dec;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 180U, *c1_sfEvent);
          c1_bi_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(180U, 0,
            muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_bi_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 180U, *c1_sfEvent);
            (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 1.0;
            for (c1_i220 = 0; c1_i220 < 4; c1_i220++) {
              _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i220], 3U);
            }

            c1_d77 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
            sf_mex_printf("%s =\\n", "stop[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d77);
            *c1_c_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
            c1_d78 = *c1_c_v;
            sf_mex_printf("%s =\\n", "v");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d78);
            (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)] = 0.0;
            for (c1_i221 = 0; c1_i221 < 4; c1_i221++) {
              _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i221], 2U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_stop;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *c1_sfEvent);
            *c1_c_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_c_v, 43U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 98U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_run:
        CV_STATE_EVAL(94, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 99U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 196U, *c1_sfEvent);
        c1_ci_out = (CV_TRANSITION_EVAL(196U, (int32_T)_SFD_CCP_CALL(196U, 0,
          muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_ci_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 196;
            sf_debug_transition_conflict_check_begin();
            c1_di_out = (*c1_c_v >= 20.0);
            if (c1_di_out) {
              transitionList[numTransitions] = 197;
              numTransitions++;
            }

            c1_ei_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_ei_out) {
              transitionList[numTransitions] = 190;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 196U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 189U, *c1_sfEvent);
          *c1_c_acc = -muDoubleScalarPower(*c1_c_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_c_acc, 49U);
          c1_d79 = *c1_c_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d79);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 197U, *c1_sfEvent);
          c1_fi_out = (CV_TRANSITION_EVAL(197U, (int32_T)_SFD_CCP_CALL(197U, 0, *
            c1_c_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_fi_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 197;
              sf_debug_transition_conflict_check_begin();
              c1_gi_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0,
                3, 1, 0)] == 1.0);
              if (c1_gi_out) {
                transitionList[numTransitions] = 190;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 197U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_stablerun;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 101U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 190U, *c1_sfEvent);
            c1_hi_out = (CV_TRANSITION_EVAL(190U, (int32_T)_SFD_CCP_CALL(190U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_hi_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 190U, *c1_sfEvent);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train1 = c1_IN_urgent_dec;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_select:
        CV_STATE_EVAL(94, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 100U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 176U, *c1_sfEvent);
        c1_ii_out = (CV_TRANSITION_EVAL(176U, (int32_T)_SFD_CCP_CALL(176U, 0,
          *c1_c_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_ii_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 176;
            sf_debug_transition_conflict_check_begin();
            c1_ji_out = (*c1_c_maxv <= 20.0);
            if (c1_ji_out) {
              transitionList[numTransitions] = 177;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 176U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 100U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_run;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 99U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 177U, *c1_sfEvent);
          c1_ki_out = (CV_TRANSITION_EVAL(177U, (int32_T)_SFD_CCP_CALL(177U, 0, *
            c1_c_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ki_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 177U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 100U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_urgent_inc;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 105U, *c1_sfEvent);
            (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_h_i, 0, 3, 1, 0)] =
              0.0;
            for (c1_i222 = 0; c1_i222 < 4; c1_i222++) {
              _SFD_DATA_RANGE_CHECK((*c1_urstart)[c1_i222], 11U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 100U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stablerun:
        CV_STATE_EVAL(94, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 101U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 195U, *c1_sfEvent);
        c1_li_out = (CV_TRANSITION_EVAL(195U, (int32_T)_SFD_CCP_CALL(195U, 0,
          muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_li_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 195;
            sf_debug_transition_conflict_check_begin();
            c1_mi_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_mi_out) {
              transitionList[numTransitions] = 191;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 195U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 189U, *c1_sfEvent);
          *c1_c_acc = -muDoubleScalarPower(*c1_c_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_c_acc, 49U);
          c1_d80 = *c1_c_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d80);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 191U, *c1_sfEvent);
          c1_ni_out = (CV_TRANSITION_EVAL(191U, (int32_T)_SFD_CCP_CALL(191U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ni_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 191U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 101U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stop:
        CV_STATE_EVAL(94, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 102U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 187U, *c1_sfEvent);
        c1_oi_out = (CV_TRANSITION_EVAL(187U, (int32_T)_SFD_CCP_CALL(187U, 0,
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_oi_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 187U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i223 = 0; c1_i223 < 4; c1_i223++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i223], 3U);
          }

          c1_d81 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_h_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d81);
          *c1_c_time = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_c_time, 46U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 102U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_b_IN_tmp;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 103U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 102U, *c1_sfEvent);
        }
        break;

       case c1_b_IN_tmp:
        CV_STATE_EVAL(94, 0, 9);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 103U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 193U, *c1_sfEvent);
        c1_ac_temp = (_SFD_CCP_CALL(193U, 0, *c1_c_j == 0.0 != 0U, *c1_sfEvent)
                      != 0);
        if (c1_ac_temp) {
          c1_ac_temp = (_SFD_CCP_CALL(193U, 1, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                         (17U, *c1_h_i, 0, 3, 1, 0)] == -1 != 0U, *c1_sfEvent)
                        != 0);
        }

        c1_pi_out = (CV_TRANSITION_EVAL(193U, (int32_T)c1_ac_temp) != 0);
        if (c1_pi_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 193;
            sf_debug_transition_conflict_check_begin();
            c1_bc_temp = (*c1_c_j == (real_T)c1__s32_minus__(chartInstance,
              *c1_N, 1));
            if (c1_bc_temp) {
              c1_bc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3,
                1, 0)] == 1);
            }

            c1_qi_out = c1_bc_temp;
            if (c1_qi_out) {
              transitionList[numTransitions] = 194;
              numTransitions++;
            }

            c1_cc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3,
              1, 0)] == 1);
            if (c1_cc_temp) {
              c1_cc_temp = (*c1_c_j < (real_T)c1__s32_minus__(chartInstance,
                *c1_N, 1));
            }

            c1_dc_temp = c1_cc_temp;
            if (!c1_dc_temp) {
              c1_ec_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3,
                1, 0)] == -1);
              if (c1_ec_temp) {
                c1_ec_temp = (*c1_c_j > 0.0);
              }

              c1_dc_temp = c1_ec_temp;
            }

            c1_ri_out = c1_dc_temp;
            if (c1_ri_out) {
              transitionList[numTransitions] = 192;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 193U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_ChangeDirection;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 95U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 194U, *c1_sfEvent);
          c1_fc_temp = (_SFD_CCP_CALL(194U, 0, *c1_c_j == (real_T)
            c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
          if (c1_fc_temp) {
            c1_fc_temp = (_SFD_CCP_CALL(194U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_si_out = (CV_TRANSITION_EVAL(194U, (int32_T)c1_fc_temp) != 0);
          if (c1_si_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 194;
              sf_debug_transition_conflict_check_begin();
              c1_gc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3,
                1, 0)] == 1);
              if (c1_gc_temp) {
                c1_gc_temp = (*c1_c_j < (real_T)c1__s32_minus__(chartInstance,
                  *c1_N, 1));
              }

              c1_hc_temp = c1_gc_temp;
              if (!c1_hc_temp) {
                c1_ic_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0,
                  3, 1, 0)] == -1);
                if (c1_ic_temp) {
                  c1_ic_temp = (*c1_c_j > 0.0);
                }

                c1_hc_temp = c1_ic_temp;
              }

              c1_ti_out = c1_hc_temp;
              if (c1_ti_out) {
                transitionList[numTransitions] = 192;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 194U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_ChangeDirection;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 95U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 192U, *c1_sfEvent);
            c1_jc_temp = (_SFD_CCP_CALL(192U, 0, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
            if (c1_jc_temp) {
              c1_jc_temp = (_SFD_CCP_CALL(192U, 1, *c1_c_j < (real_T)
                c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) !=
                            0);
            }

            c1_kc_temp = c1_jc_temp;
            if (!c1_kc_temp) {
              c1_lc_temp = (_SFD_CCP_CALL(192U, 2, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == -1 != 0U,
                *c1_sfEvent) != 0);
              if (c1_lc_temp) {
                c1_lc_temp = (_SFD_CCP_CALL(192U, 3, *c1_c_j > 0.0 != 0U,
                  *c1_sfEvent) != 0);
              }

              c1_kc_temp = c1_lc_temp;
            }

            c1_ui_out = (CV_TRANSITION_EVAL(192U, (int32_T)c1_kc_temp) != 0);
            if (c1_ui_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 192U, *c1_sfEvent);
              *c1_c_j += (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i,
                0, 3, 1, 0)];
              _SFD_DATA_RANGE_CHECK(*c1_c_j, 44U);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train1 = c1_IN_run;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 99U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 103U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_urgent_dec:
        CV_STATE_EVAL(94, 0, 10);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 104U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 183U, *c1_sfEvent);
        c1_vi_out = (CV_TRANSITION_EVAL(183U, (int32_T)_SFD_CCP_CALL(183U, 0,
          *c1_c_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
        if (c1_vi_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 183U, *c1_sfEvent);
          (*c1_urstopped)[_SFD_ARRAY_BOUNDS_CHECK(16U, *c1_h_i, 0, 3, 1, 0)] =
            1.0;
          for (c1_i224 = 0; c1_i224 < 4; c1_i224++) {
            _SFD_DATA_RANGE_CHECK((*c1_urstopped)[c1_i224], 16U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 104U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_urgent_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 106U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 104U, *c1_sfEvent);
        }
        break;

       case c1_IN_urgent_inc:
        CV_STATE_EVAL(94, 0, 11);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 105U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 175U, *c1_sfEvent);
        c1_wi_out = (CV_TRANSITION_EVAL(175U, (int32_T)_SFD_CCP_CALL(175U, 0,
          *c1_c_v >= *c1_c_maxv != 0U, *c1_sfEvent)) != 0);
        if (c1_wi_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 175;
            sf_debug_transition_conflict_check_begin();
            c1_xi_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_xi_out) {
              transitionList[numTransitions] = 181;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 175U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_recover;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 98U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 181U, *c1_sfEvent);
          c1_yi_out = (CV_TRANSITION_EVAL(181U, (int32_T)_SFD_CCP_CALL(181U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yi_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 181U, *c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 182U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train1 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 105U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_urgent_stop:
        CV_STATE_EVAL(94, 0, 12);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 106U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 178U, *c1_sfEvent);
        c1_aj_out = (CV_TRANSITION_EVAL(178U, (int32_T)_SFD_CCP_CALL(178U, 0,
          (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_h_i, 0, 3, 1, 0)] ==
          1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_aj_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 178U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 106U, *c1_sfEvent);
          *c1_c_maxv = muDoubleScalarSqrt(0.5 * muDoubleScalarAbs((*c1_S)
            [_SFD_ARRAY_BOUNDS_CHECK(10U, c1__s32_d_(chartInstance, *c1_c_j), 0,
            3, 2, 0)] - *c1_c_distance));
          _SFD_DATA_RANGE_CHECK(*c1_c_maxv, 45U);
          c1_d82 = *c1_c_maxv;
          sf_mex_printf("%s =\\n", "maxv");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d82);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 106U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train1 = c1_IN_select;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 100U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *c1_sfEvent);
        }
        break;

       default:
        CV_STATE_EVAL(94, 0, 0);
        *c1_is_Train1 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 95U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 94U, *c1_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 112U, *c1_sfEvent);
      switch (*c1_is_Train2) {
       case c1_IN_ChangeDirection:
        CV_STATE_EVAL(112, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 113U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 212U, *c1_sfEvent);
        c1_bj_out = (CV_TRANSITION_EVAL(212U, (int32_T)_SFD_CCP_CALL(212U, 0,
          *c1_d_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_bj_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 212U, *c1_sfEvent);
          (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] =
            c1__s32_uminus__(chartInstance, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                             (17U, *c1_i_i, 0, 3, 1, 0)]);
          for (c1_i225 = 0; c1_i225 < 4; c1_i225++) {
            _SFD_DATA_RANGE_CHECK((real_T)(*c1_dir)[c1_i225], 17U);
          }

          c1_i226 = (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)];
          sf_mex_printf("%s =\\n", "dir[i]");
          sf_mex_call_debug("disp", 0U, 1U, 12, c1_i226);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i227 = 0; c1_i227 < 4; c1_i227++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i227], 3U);
          }

          c1_d83 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d83);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i228 = 0; c1_i228 < 4; c1_i228++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i228], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *c1_sfEvent);
          *c1_d_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 113U, *c1_sfEvent);
        }
        break;

       case c1_IN_init:
        CV_STATE_EVAL(112, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 114U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 208U, *c1_sfEvent);
        c1_cj_out = (CV_TRANSITION_EVAL(208U, (int32_T)_SFD_CCP_CALL(208U, 0,
          *c1_d_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_i_i, 0, 3, 2,
          0)] != 0U, *c1_sfEvent)) != 0);
        if (c1_cj_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 208U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i229 = 0; c1_i229 < 4; c1_i229++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i229], 3U);
          }

          c1_d84 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d84);
          *c1_d_j = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_j, 59U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 114U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *c1_sfEvent);
          *c1_d_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 114U, *c1_sfEvent);
        }
        break;

       case c1_IN_near:
        CV_STATE_EVAL(112, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 115U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 209U, *c1_sfEvent);
        c1_dj_out = (CV_TRANSITION_EVAL(209U, (int32_T)_SFD_CCP_CALL(209U, 0,
          muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_dj_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 209;
            sf_debug_transition_conflict_check_begin();
            c1_ej_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_ej_out) {
              transitionList[numTransitions] = 210;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 209U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 1.0;
          for (c1_i230 = 0; c1_i230 < 4; c1_i230++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i230], 3U);
          }

          c1_d85 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d85);
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)] = 0.0;
          for (c1_i231 = 0; c1_i231 < 4; c1_i231++) {
            _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i231], 2U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 115U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *c1_sfEvent);
          *c1_d_v = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 210U, *c1_sfEvent);
          c1_fj_out = (CV_TRANSITION_EVAL(210U, (int32_T)_SFD_CCP_CALL(210U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_fj_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 210U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 115U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 115U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_recover:
        CV_STATE_EVAL(112, 0, 4);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 116U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 203U, *c1_sfEvent);
        c1_gj_out = (CV_TRANSITION_EVAL(203U, (int32_T)_SFD_CCP_CALL(203U, 0,
          (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_gj_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 203U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 206U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_urgent_dec;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 204U, *c1_sfEvent);
          c1_hj_out = (CV_TRANSITION_EVAL(204U, (int32_T)_SFD_CCP_CALL(204U, 0,
            muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_hj_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 204U, *c1_sfEvent);
            (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 1.0;
            for (c1_i232 = 0; c1_i232 < 4; c1_i232++) {
              _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i232], 3U);
            }

            c1_d86 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
            sf_mex_printf("%s =\\n", "stop[i]");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d86);
            *c1_d_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
            c1_d87 = *c1_d_v;
            sf_mex_printf("%s =\\n", "v");
            sf_mex_call_debug("disp", 0U, 1U, 6, c1_d87);
            (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)] = 0.0;
            for (c1_i233 = 0; c1_i233 < 4; c1_i233++) {
              _SFD_DATA_RANGE_CHECK((*c1_start)[c1_i233], 2U);
            }

            _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_stop;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *c1_sfEvent);
            *c1_d_v = 0.0;
            _SFD_DATA_RANGE_CHECK(*c1_d_v, 58U);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 116U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_run:
        CV_STATE_EVAL(112, 0, 5);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 117U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 220U, *c1_sfEvent);
        c1_ij_out = (CV_TRANSITION_EVAL(220U, (int32_T)_SFD_CCP_CALL(220U, 0,
          muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_ij_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 220;
            sf_debug_transition_conflict_check_begin();
            c1_jj_out = (*c1_d_v >= 20.0);
            if (c1_jj_out) {
              transitionList[numTransitions] = 221;
              numTransitions++;
            }

            c1_kj_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_kj_out) {
              transitionList[numTransitions] = 214;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 220U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 213U, *c1_sfEvent);
          *c1_d_acc = -muDoubleScalarPower(*c1_d_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_d_acc, 64U);
          c1_d88 = *c1_d_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d88);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 115U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 221U, *c1_sfEvent);
          c1_lj_out = (CV_TRANSITION_EVAL(221U, (int32_T)_SFD_CCP_CALL(221U, 0, *
            c1_d_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_lj_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 221;
              sf_debug_transition_conflict_check_begin();
              c1_mj_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0,
                3, 1, 0)] == 1.0);
              if (c1_mj_out) {
                transitionList[numTransitions] = 214;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 221U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_stablerun;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 119U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 214U, *c1_sfEvent);
            c1_nj_out = (CV_TRANSITION_EVAL(214U, (int32_T)_SFD_CCP_CALL(214U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_nj_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 214U, *c1_sfEvent);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train2 = c1_IN_urgent_dec;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 117U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_select:
        CV_STATE_EVAL(112, 0, 6);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 118U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 200U, *c1_sfEvent);
        c1_oj_out = (CV_TRANSITION_EVAL(200U, (int32_T)_SFD_CCP_CALL(200U, 0,
          *c1_d_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_oj_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 200;
            sf_debug_transition_conflict_check_begin();
            c1_pj_out = (*c1_d_maxv <= 20.0);
            if (c1_pj_out) {
              transitionList[numTransitions] = 201;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 200U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 118U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_run;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 201U, *c1_sfEvent);
          c1_qj_out = (CV_TRANSITION_EVAL(201U, (int32_T)_SFD_CCP_CALL(201U, 0, *
            c1_d_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_qj_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 201U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 118U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_urgent_inc;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 123U, *c1_sfEvent);
            (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_i_i, 0, 3, 1, 0)] =
              0.0;
            for (c1_i234 = 0; c1_i234 < 4; c1_i234++) {
              _SFD_DATA_RANGE_CHECK((*c1_urstart)[c1_i234], 11U);
            }
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 118U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stablerun:
        CV_STATE_EVAL(112, 0, 7);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 119U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 219U, *c1_sfEvent);
        c1_rj_out = (CV_TRANSITION_EVAL(219U, (int32_T)_SFD_CCP_CALL(219U, 0,
          muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
          c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
          *c1_sfEvent)) != 0);
        if (c1_rj_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 219;
            sf_debug_transition_conflict_check_begin();
            c1_sj_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_sj_out) {
              transitionList[numTransitions] = 215;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 219U, *c1_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 213U, *c1_sfEvent);
          *c1_d_acc = -muDoubleScalarPower(*c1_d_v, 2.0) * 0.001;
          _SFD_DATA_RANGE_CHECK(*c1_d_acc, 64U);
          c1_d89 = *c1_d_acc;
          sf_mex_printf("%s =\\n", "acc");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d89);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 119U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_near;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 115U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 215U, *c1_sfEvent);
          c1_tj_out = (CV_TRANSITION_EVAL(215U, (int32_T)_SFD_CCP_CALL(215U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_tj_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 215U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 119U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 119U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_stop:
        CV_STATE_EVAL(112, 0, 8);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 120U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 211U, *c1_sfEvent);
        c1_uj_out = (CV_TRANSITION_EVAL(211U, (int32_T)_SFD_CCP_CALL(211U, 0,
          (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3, 1, 0)] == 1.0
          != 0U, *c1_sfEvent)) != 0);
        if (c1_uj_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 211U, *c1_sfEvent);
          (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)] = 0.0;
          for (c1_i235 = 0; c1_i235 < 4; c1_i235++) {
            _SFD_DATA_RANGE_CHECK((*c1_stop)[c1_i235], 3U);
          }

          c1_d90 = (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_i_i, 0, 3, 2, 0)];
          sf_mex_printf("%s =\\n", "stop[i]");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d90);
          *c1_d_time = 0.0;
          _SFD_DATA_RANGE_CHECK(*c1_d_time, 61U);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 120U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_b_IN_tmp;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 121U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 120U, *c1_sfEvent);
        }
        break;

       case c1_b_IN_tmp:
        CV_STATE_EVAL(112, 0, 9);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 121U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 217U, *c1_sfEvent);
        c1_mc_temp = (_SFD_CCP_CALL(217U, 0, *c1_d_j == 0.0 != 0U, *c1_sfEvent)
                      != 0);
        if (c1_mc_temp) {
          c1_mc_temp = (_SFD_CCP_CALL(217U, 1, (*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK
                         (17U, *c1_i_i, 0, 3, 1, 0)] == -1 != 0U, *c1_sfEvent)
                        != 0);
        }

        c1_vj_out = (CV_TRANSITION_EVAL(217U, (int32_T)c1_mc_temp) != 0);
        if (c1_vj_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[3];
            unsigned int numTransitions = 1;
            transitionList[0] = 217;
            sf_debug_transition_conflict_check_begin();
            c1_nc_temp = (*c1_d_j == (real_T)c1__s32_minus__(chartInstance,
              *c1_N, 1));
            if (c1_nc_temp) {
              c1_nc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3,
                1, 0)] == 1);
            }

            c1_wj_out = c1_nc_temp;
            if (c1_wj_out) {
              transitionList[numTransitions] = 218;
              numTransitions++;
            }

            c1_oc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3,
              1, 0)] == 1);
            if (c1_oc_temp) {
              c1_oc_temp = (*c1_d_j < (real_T)c1__s32_minus__(chartInstance,
                *c1_N, 1));
            }

            c1_pc_temp = c1_oc_temp;
            if (!c1_pc_temp) {
              c1_qc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3,
                1, 0)] == -1);
              if (c1_qc_temp) {
                c1_qc_temp = (*c1_d_j > 0.0);
              }

              c1_pc_temp = c1_qc_temp;
            }

            c1_xj_out = c1_pc_temp;
            if (c1_xj_out) {
              transitionList[numTransitions] = 216;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 217U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_ChangeDirection;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 113U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 218U, *c1_sfEvent);
          c1_rc_temp = (_SFD_CCP_CALL(218U, 0, *c1_d_j == (real_T)
            c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
          if (c1_rc_temp) {
            c1_rc_temp = (_SFD_CCP_CALL(218U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_yj_out = (CV_TRANSITION_EVAL(218U, (int32_T)c1_rc_temp) != 0);
          if (c1_yj_out) {
            if (sf_debug_transition_conflict_check_enabled()) {
              unsigned int transitionList[2];
              unsigned int numTransitions = 1;
              transitionList[0] = 218;
              sf_debug_transition_conflict_check_begin();
              c1_sc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3,
                1, 0)] == 1);
              if (c1_sc_temp) {
                c1_sc_temp = (*c1_d_j < (real_T)c1__s32_minus__(chartInstance,
                  *c1_N, 1));
              }

              c1_tc_temp = c1_sc_temp;
              if (!c1_tc_temp) {
                c1_uc_temp = ((*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0,
                  3, 1, 0)] == -1);
                if (c1_uc_temp) {
                  c1_uc_temp = (*c1_d_j > 0.0);
                }

                c1_tc_temp = c1_uc_temp;
              }

              c1_ak_out = c1_tc_temp;
              if (c1_ak_out) {
                transitionList[numTransitions] = 216;
                numTransitions++;
              }

              sf_debug_transition_conflict_check_end();
              if (numTransitions > 1) {
                _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
              }
            }

            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 218U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_ChangeDirection;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 113U, *c1_sfEvent);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 216U, *c1_sfEvent);
            c1_vc_temp = (_SFD_CCP_CALL(216U, 0, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == 1 != 0U,
              *c1_sfEvent) != 0);
            if (c1_vc_temp) {
              c1_vc_temp = (_SFD_CCP_CALL(216U, 1, *c1_d_j < (real_T)
                c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) !=
                            0);
            }

            c1_wc_temp = c1_vc_temp;
            if (!c1_wc_temp) {
              c1_xc_temp = (_SFD_CCP_CALL(216U, 2, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == -1 != 0U,
                *c1_sfEvent) != 0);
              if (c1_xc_temp) {
                c1_xc_temp = (_SFD_CCP_CALL(216U, 3, *c1_d_j > 0.0 != 0U,
                  *c1_sfEvent) != 0);
              }

              c1_wc_temp = c1_xc_temp;
            }

            c1_bk_out = (CV_TRANSITION_EVAL(216U, (int32_T)c1_wc_temp) != 0);
            if (c1_bk_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 216U, *c1_sfEvent);
              *c1_d_j += (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i,
                0, 3, 1, 0)];
              _SFD_DATA_RANGE_CHECK(*c1_d_j, 59U);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *c1_sfEvent);
              *c1_stateChanged = TRUE;
              *c1_is_Train2 = c1_IN_run;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *c1_sfEvent);
            } else {
              _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 121U, *c1_sfEvent);
            }
          }
        }
        break;

       case c1_IN_urgent_dec:
        CV_STATE_EVAL(112, 0, 10);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 122U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 207U, *c1_sfEvent);
        c1_ck_out = (CV_TRANSITION_EVAL(207U, (int32_T)_SFD_CCP_CALL(207U, 0,
          *c1_d_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
        if (c1_ck_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 207U, *c1_sfEvent);
          (*c1_urstopped)[_SFD_ARRAY_BOUNDS_CHECK(16U, *c1_i_i, 0, 3, 1, 0)] =
            1.0;
          for (c1_i236 = 0; c1_i236 < 4; c1_i236++) {
            _SFD_DATA_RANGE_CHECK((*c1_urstopped)[c1_i236], 16U);
          }

          _SFD_CS_CALL(STATE_INACTIVE_TAG, 122U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_urgent_stop;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 124U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 122U, *c1_sfEvent);
        }
        break;

       case c1_IN_urgent_inc:
        CV_STATE_EVAL(112, 0, 11);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 123U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 199U, *c1_sfEvent);
        c1_dk_out = (CV_TRANSITION_EVAL(199U, (int32_T)_SFD_CCP_CALL(199U, 0,
          *c1_d_v >= *c1_d_maxv != 0U, *c1_sfEvent)) != 0);
        if (c1_dk_out) {
          if (sf_debug_transition_conflict_check_enabled()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 199;
            sf_debug_transition_conflict_check_begin();
            c1_ek_out = ((*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
              1, 0)] == 1.0);
            if (c1_ek_out) {
              transitionList[numTransitions] = 205;
              numTransitions++;
            }

            sf_debug_transition_conflict_check_end();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 199U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_recover;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 116U, *c1_sfEvent);
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 205U, *c1_sfEvent);
          c1_fk_out = (CV_TRANSITION_EVAL(205U, (int32_T)_SFD_CCP_CALL(205U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_fk_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 205U, *c1_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 206U, *c1_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *c1_sfEvent);
            *c1_stateChanged = TRUE;
            *c1_is_Train2 = c1_IN_urgent_dec;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *c1_sfEvent);
          } else {
            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 123U, *c1_sfEvent);
          }
        }
        break;

       case c1_IN_urgent_stop:
        CV_STATE_EVAL(112, 0, 12);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 124U, *c1_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 202U, *c1_sfEvent);
        c1_gk_out = (CV_TRANSITION_EVAL(202U, (int32_T)_SFD_CCP_CALL(202U, 0,
          (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_i_i, 0, 3, 1, 0)] ==
          1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_gk_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 202U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 124U, *c1_sfEvent);
          *c1_d_maxv = muDoubleScalarSqrt(0.5 * muDoubleScalarAbs((*c1_S)
            [_SFD_ARRAY_BOUNDS_CHECK(10U, c1__s32_d_(chartInstance, *c1_d_j), 0,
            3, 2, 0)] - *c1_d_distance));
          _SFD_DATA_RANGE_CHECK(*c1_d_maxv, 60U);
          c1_d91 = *c1_d_maxv;
          sf_mex_printf("%s =\\n", "maxv");
          sf_mex_call_debug("disp", 0U, 1U, 6, c1_d91);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *c1_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 124U, *c1_sfEvent);
          *c1_stateChanged = TRUE;
          *c1_is_Train2 = c1_IN_select;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 118U, *c1_sfEvent);
        } else {
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *c1_sfEvent);
        }
        break;

       default:
        CV_STATE_EVAL(112, 0, 0);
        *c1_is_Train2 = c1_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *c1_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 112U, *c1_sfEvent);
    }

    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
    if (*c1_stateChanged) {
      ssSetSolverNeedsReset(chartInstance->S);
    }
  }

  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 89U, *c1_sfEvent);
  switch (*c1_is_Train0_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(89, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 90U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 90U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(89, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 91U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i237 = 0; c1_i237 < 4; c1_i237++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i237], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 91U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(89, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 92U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i238 = 0; c1_i238 < 4; c1_i238++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i238], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 92U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(89, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 93U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i239 = 0; c1_i239 < 4; c1_i239++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i239], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 93U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(89, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 89U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U, *c1_sfEvent);
  switch (*c1_is_Screen_door00) {
   case c1_IN_closed:
    CV_STATE_EVAL(36, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(36, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i240 = 0; c1_i240 < 8; c1_i240++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i240], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(36, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i241 = 0; c1_i241 < 8; c1_i241++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i241], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(36, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i242 = 0; c1_i242 < 8; c1_i242++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i242], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(36, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  switch (*c1_is_Controller0) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(0, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, *c1_sfEvent);
  switch (*c1_is_Screen_door01) {
   case c1_IN_closed:
    CV_STATE_EVAL(41, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(41, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i243 = 0; c1_i243 < 8; c1_i243++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i243], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(41, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i244 = 0; c1_i244 < 8; c1_i244++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i244], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(41, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i245 = 0; c1_i245 < 8; c1_i245++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i245], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(41, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U, *c1_sfEvent);
  switch (*c1_is_Screen_door10) {
   case c1_IN_closed:
    CV_STATE_EVAL(46, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(46, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i246 = 0; c1_i246 < 8; c1_i246++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i246], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(46, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i247 = 0; c1_i247 < 8; c1_i247++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i247], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(46, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i248 = 0; c1_i248 < 8; c1_i248++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i248], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(46, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U, *c1_sfEvent);
  switch (*c1_is_Screen_door11) {
   case c1_IN_closed:
    CV_STATE_EVAL(51, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(51, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i249 = 0; c1_i249 < 8; c1_i249++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i249], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(51, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i250 = 0; c1_i250 < 8; c1_i250++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i250], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(51, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i251 = 0; c1_i251 < 8; c1_i251++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i251], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(51, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U, *c1_sfEvent);
  switch (*c1_is_Screen_door20) {
   case c1_IN_closed:
    CV_STATE_EVAL(56, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(56, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i252 = 0; c1_i252 < 8; c1_i252++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i252], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(56, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i253 = 0; c1_i253 < 8; c1_i253++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i253], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(56, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i254 = 0; c1_i254 < 8; c1_i254++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i254], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(56, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, *c1_sfEvent);
  switch (*c1_is_Screen_door21) {
   case c1_IN_closed:
    CV_STATE_EVAL(61, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(61, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i255 = 0; c1_i255 < 8; c1_i255++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i255], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(61, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i256 = 0; c1_i256 < 8; c1_i256++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i256], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(61, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i257 = 0; c1_i257 < 8; c1_i257++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i257], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(61, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U, *c1_sfEvent);
  switch (*c1_is_Screen_door30) {
   case c1_IN_closed:
    CV_STATE_EVAL(66, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(66, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i258 = 0; c1_i258 < 8; c1_i258++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i258], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(66, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i259 = 0; c1_i259 < 8; c1_i259++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i259], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(66, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 70U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i260 = 0; c1_i260 < 8; c1_i260++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i260], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(66, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U, *c1_sfEvent);
  switch (*c1_is_Screen_door31) {
   case c1_IN_closed:
    CV_STATE_EVAL(71, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(71, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i261 = 0; c1_i261 < 8; c1_i261++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i261], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(71, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 74U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i262 = 0; c1_i262 < 8; c1_i262++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i262], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(71, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 75U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i263 = 0; c1_i263 < 8; c1_i263++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i263], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 75U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(71, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 107U, *c1_sfEvent);
  switch (*c1_is_Train1_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(107, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 108U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 108U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(107, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 109U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i264 = 0; c1_i264 < 4; c1_i264++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i264], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 109U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(107, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 110U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i265 = 0; c1_i265 < 4; c1_i265++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i265], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 110U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(107, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 111U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i266 = 0; c1_i266 < 4; c1_i266++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i266], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 111U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(107, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 107U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 125U, *c1_sfEvent);
  switch (*c1_is_Train2_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(125, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 126U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 126U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(125, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 127U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i267 = 0; c1_i267 < 4; c1_i267++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i267], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 127U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(125, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 128U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i268 = 0; c1_i268 < 4; c1_i268++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i268], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 128U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(125, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 129U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i269 = 0; c1_i269 < 4; c1_i269++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i269], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 129U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(125, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 125U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 143U, *c1_sfEvent);
  switch (*c1_is_Train3_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(143, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 144U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 144U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(143, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 145U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i270 = 0; c1_i270 < 4; c1_i270++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i270], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 145U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(143, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 146U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i271 = 0; c1_i271 < 4; c1_i271++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i271], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 146U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(143, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 147U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i272 = 0; c1_i272 < 4; c1_i272++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i272], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 147U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(143, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 143U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 148U, *c1_sfEvent);
  switch (*c1_is_UrgentController) {
   case c1_IN_D1:
    CV_STATE_EVAL(148, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 150U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 150U, *c1_sfEvent);
    break;

   case c1_IN_Delay:
    CV_STATE_EVAL(148, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 151U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 151U, *c1_sfEvent);
    break;

   case c1_IN_tmp:
    CV_STATE_EVAL(148, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 153U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 153U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(148, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 148U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 130U, *c1_sfEvent);
  switch (*c1_is_Train3) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(130, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 131U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 131U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(130, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 132U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 132U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(130, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 133U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i273 = 0; c1_i273 < 4; c1_i273++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i273], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 133U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(130, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 134U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i274 = 0; c1_i274 < 4; c1_i274++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i274], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 134U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(130, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 135U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i275 = 0; c1_i275 < 4; c1_i275++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i275], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 135U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(130, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 136U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 136U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(130, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 137U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i276 = 0; c1_i276 < 4; c1_i276++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i276], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 137U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(130, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 138U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 138U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(130, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 139U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 139U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(130, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 140U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i277 = 0; c1_i277 < 4; c1_i277++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i277], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 140U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(130, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 141U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i278 = 0; c1_i278 < 4; c1_i278++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i278], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 141U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(130, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 142U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i279 = 0; c1_i279 < 4; c1_i279++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i279], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 142U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(130, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 130U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, *c1_sfEvent);
  switch (*c1_is_Controller1) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(9, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(9, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, *c1_sfEvent);
  switch (*c1_is_Controller2) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(18, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(18, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(18, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(18, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(18, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(18, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(18, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(18, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(18, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, *c1_sfEvent);
  switch (*c1_is_Controller3) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(27, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(27, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(27, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(27, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(27, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(27, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(27, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(27, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 76U, *c1_sfEvent);
  switch (*c1_is_Train0) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(76, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 77U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 77U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(76, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 78U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 78U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(76, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 79U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i280 = 0; c1_i280 < 4; c1_i280++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i280], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 79U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(76, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 80U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i281 = 0; c1_i281 < 4; c1_i281++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i281], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 80U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(76, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 81U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i282 = 0; c1_i282 < 4; c1_i282++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i282], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 81U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(76, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 82U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 82U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(76, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 83U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i283 = 0; c1_i283 < 4; c1_i283++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i283], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 83U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(76, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 84U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 84U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(76, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 85U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(76, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 86U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i284 = 0; c1_i284 < 4; c1_i284++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i284], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 86U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(76, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 87U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i285 = 0; c1_i285 < 4; c1_i285++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i285], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 87U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(76, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 88U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_g_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i286 = 0; c1_i286 < 4; c1_i286++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i286], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(76, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 76U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 94U, *c1_sfEvent);
  switch (*c1_is_Train1) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(94, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 95U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 95U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(94, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 96U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 96U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(94, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 97U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i287 = 0; c1_i287 < 4; c1_i287++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i287], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 97U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(94, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 98U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i288 = 0; c1_i288 < 4; c1_i288++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i288], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 98U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(94, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 99U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i289 = 0; c1_i289 < 4; c1_i289++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i289], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(94, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 100U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 100U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(94, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 101U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i290 = 0; c1_i290 < 4; c1_i290++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i290], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 101U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(94, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 102U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 102U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(94, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 103U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 103U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(94, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 104U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i291 = 0; c1_i291 < 4; c1_i291++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i291], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 104U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(94, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 105U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i292 = 0; c1_i292 < 4; c1_i292++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i292], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 105U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(94, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 106U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_h_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i293 = 0; c1_i293 < 4; c1_i293++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i293], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(94, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 94U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 112U, *c1_sfEvent);
  switch (*c1_is_Train2) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(112, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 113U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 113U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(112, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 114U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 114U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(112, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 115U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i294 = 0; c1_i294 < 4; c1_i294++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i294], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 115U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(112, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 116U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i295 = 0; c1_i295 < 4; c1_i295++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i295], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 116U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(112, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 117U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i296 = 0; c1_i296 < 4; c1_i296++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i296], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 117U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(112, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 118U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 118U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(112, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 119U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i297 = 0; c1_i297 < 4; c1_i297++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i297], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 119U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(112, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 120U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 120U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(112, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 121U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 121U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(112, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 122U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i298 = 0; c1_i298 < 4; c1_i298++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i298], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 122U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(112, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 123U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i299 = 0; c1_i299 < 4; c1_i299++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i299], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 123U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(112, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 124U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i300 = 0; c1_i300 < 4; c1_i300++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i300], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(112, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 112U, *c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_subwaycontrolsystemMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void zeroCrossings_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  boolean_T c1_c_out;
  boolean_T c1_temp;
  boolean_T c1_d_out;
  boolean_T c1_e_out;
  boolean_T c1_f_out;
  boolean_T c1_g_out;
  boolean_T c1_h_out;
  boolean_T c1_i_out;
  boolean_T c1_b_temp;
  boolean_T c1_j_out;
  boolean_T c1_k_out;
  boolean_T c1_l_out;
  boolean_T c1_m_out;
  boolean_T c1_n_out;
  boolean_T c1_o_out;
  boolean_T c1_p_out;
  boolean_T c1_c_temp;
  boolean_T c1_q_out;
  boolean_T c1_r_out;
  boolean_T c1_d_temp;
  boolean_T c1_s_out;
  boolean_T c1_t_out;
  boolean_T c1_u_out;
  boolean_T c1_v_out;
  boolean_T c1_w_out;
  boolean_T c1_x_out;
  boolean_T c1_y_out;
  boolean_T c1_e_temp;
  boolean_T c1_ab_out;
  boolean_T c1_bb_out;
  boolean_T c1_cb_out;
  boolean_T c1_db_out;
  boolean_T c1_eb_out;
  boolean_T c1_f_temp;
  boolean_T c1_fb_out;
  boolean_T c1_gb_out;
  boolean_T c1_hb_out;
  boolean_T c1_ib_out;
  boolean_T c1_jb_out;
  boolean_T c1_g_temp;
  boolean_T c1_kb_out;
  boolean_T c1_lb_out;
  boolean_T c1_mb_out;
  boolean_T c1_nb_out;
  boolean_T c1_ob_out;
  boolean_T c1_h_temp;
  boolean_T c1_pb_out;
  boolean_T c1_qb_out;
  boolean_T c1_rb_out;
  boolean_T c1_sb_out;
  boolean_T c1_tb_out;
  boolean_T c1_i_temp;
  boolean_T c1_ub_out;
  boolean_T c1_vb_out;
  boolean_T c1_wb_out;
  boolean_T c1_xb_out;
  boolean_T c1_yb_out;
  boolean_T c1_j_temp;
  boolean_T c1_ac_out;
  boolean_T c1_bc_out;
  boolean_T c1_cc_out;
  boolean_T c1_dc_out;
  boolean_T c1_ec_out;
  boolean_T c1_k_temp;
  boolean_T c1_fc_out;
  boolean_T c1_gc_out;
  boolean_T c1_hc_out;
  boolean_T c1_ic_out;
  boolean_T c1_l_temp;
  boolean_T c1_jc_out;
  boolean_T c1_kc_out;
  boolean_T c1_lc_out;
  boolean_T c1_mc_out;
  boolean_T c1_nc_out;
  boolean_T c1_m_temp;
  boolean_T c1_oc_out;
  boolean_T c1_pc_out;
  boolean_T c1_qc_out;
  boolean_T c1_rc_out;
  boolean_T c1_sc_out;
  boolean_T c1_n_temp;
  boolean_T c1_tc_out;
  boolean_T c1_uc_out;
  boolean_T c1_o_temp;
  boolean_T c1_vc_out;
  boolean_T c1_p_temp;
  boolean_T c1_wc_out;
  boolean_T c1_xc_out;
  boolean_T c1_yc_out;
  boolean_T c1_ad_out;
  boolean_T c1_bd_out;
  boolean_T c1_cd_out;
  boolean_T c1_dd_out;
  boolean_T c1_ed_out;
  boolean_T c1_fd_out;
  boolean_T c1_gd_out;
  boolean_T c1_hd_out;
  boolean_T c1_id_out;
  boolean_T c1_jd_out;
  boolean_T c1_kd_out;
  boolean_T c1_ld_out;
  boolean_T c1_md_out;
  boolean_T c1_nd_out;
  boolean_T c1_q_temp;
  boolean_T c1_od_out;
  boolean_T c1_r_temp;
  boolean_T c1_pd_out;
  boolean_T c1_s_temp;
  boolean_T c1_t_temp;
  boolean_T c1_u_temp;
  boolean_T c1_qd_out;
  boolean_T c1_rd_out;
  boolean_T c1_sd_out;
  boolean_T c1_td_out;
  boolean_T c1_ud_out;
  boolean_T c1_vd_out;
  boolean_T c1_wd_out;
  boolean_T c1_xd_out;
  boolean_T c1_yd_out;
  boolean_T c1_ae_out;
  boolean_T c1_be_out;
  boolean_T c1_v_temp;
  boolean_T c1_ce_out;
  boolean_T c1_de_out;
  boolean_T c1_w_temp;
  boolean_T c1_ee_out;
  boolean_T c1_fe_out;
  boolean_T c1_ge_out;
  boolean_T c1_he_out;
  boolean_T c1_ie_out;
  boolean_T c1_je_out;
  boolean_T c1_ke_out;
  boolean_T c1_le_out;
  boolean_T c1_me_out;
  boolean_T c1_x_temp;
  boolean_T c1_ne_out;
  boolean_T c1_oe_out;
  boolean_T c1_y_temp;
  boolean_T c1_pe_out;
  boolean_T c1_qe_out;
  boolean_T c1_re_out;
  boolean_T c1_se_out;
  boolean_T c1_te_out;
  boolean_T c1_ue_out;
  boolean_T c1_ve_out;
  boolean_T c1_we_out;
  boolean_T c1_xe_out;
  boolean_T c1_ab_temp;
  boolean_T c1_ye_out;
  boolean_T c1_af_out;
  boolean_T c1_bb_temp;
  boolean_T c1_bf_out;
  boolean_T c1_cf_out;
  boolean_T c1_df_out;
  boolean_T c1_ef_out;
  boolean_T c1_ff_out;
  boolean_T c1_gf_out;
  boolean_T c1_hf_out;
  boolean_T c1_if_out;
  boolean_T c1_jf_out;
  boolean_T c1_kf_out;
  boolean_T c1_lf_out;
  boolean_T c1_mf_out;
  boolean_T c1_nf_out;
  boolean_T c1_of_out;
  boolean_T c1_pf_out;
  boolean_T c1_qf_out;
  boolean_T c1_rf_out;
  boolean_T c1_cb_temp;
  boolean_T c1_sf_out;
  boolean_T c1_db_temp;
  boolean_T c1_tf_out;
  boolean_T c1_eb_temp;
  boolean_T c1_fb_temp;
  boolean_T c1_gb_temp;
  boolean_T c1_uf_out;
  boolean_T c1_vf_out;
  boolean_T c1_wf_out;
  boolean_T c1_xf_out;
  boolean_T c1_yf_out;
  boolean_T c1_ag_out;
  boolean_T c1_bg_out;
  boolean_T c1_cg_out;
  boolean_T c1_dg_out;
  boolean_T c1_eg_out;
  boolean_T c1_fg_out;
  boolean_T c1_gg_out;
  boolean_T c1_hg_out;
  boolean_T c1_ig_out;
  boolean_T c1_jg_out;
  boolean_T c1_kg_out;
  boolean_T c1_lg_out;
  boolean_T c1_mg_out;
  boolean_T c1_ng_out;
  boolean_T c1_hb_temp;
  boolean_T c1_og_out;
  boolean_T c1_ib_temp;
  boolean_T c1_pg_out;
  boolean_T c1_jb_temp;
  boolean_T c1_kb_temp;
  boolean_T c1_lb_temp;
  boolean_T c1_qg_out;
  boolean_T c1_rg_out;
  boolean_T c1_sg_out;
  boolean_T c1_tg_out;
  boolean_T c1_ug_out;
  boolean_T c1_vg_out;
  boolean_T c1_wg_out;
  boolean_T c1_xg_out;
  boolean_T c1_yg_out;
  boolean_T c1_ah_out;
  boolean_T c1_bh_out;
  boolean_T c1_ch_out;
  boolean_T c1_dh_out;
  boolean_T c1_eh_out;
  boolean_T c1_fh_out;
  boolean_T c1_gh_out;
  boolean_T c1_hh_out;
  boolean_T c1_ih_out;
  boolean_T c1_jh_out;
  boolean_T c1_mb_temp;
  boolean_T c1_kh_out;
  boolean_T c1_nb_temp;
  boolean_T c1_lh_out;
  boolean_T c1_ob_temp;
  boolean_T c1_pb_temp;
  boolean_T c1_qb_temp;
  boolean_T c1_mh_out;
  boolean_T c1_nh_out;
  boolean_T c1_oh_out;
  boolean_T c1_ph_out;
  boolean_T c1_qh_out;
  real_T *c1_lastMajorTime;
  real_T *c1_zcVar;
  boolean_T *c1_stateChanged;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  uint8_T *c1_is_Train0_door;
  real_T *c1_y1;
  uint8_T *c1_is_Screen_door00;
  real_T *c1_y2;
  uint8_T *c1_is_Controller0;
  real_T *c1_z;
  uint8_T *c1_is_Screen_door01;
  real_T *c1_b_y2;
  uint8_T *c1_is_Screen_door10;
  real_T *c1_c_y2;
  uint8_T *c1_is_Screen_door11;
  real_T *c1_d_y2;
  uint8_T *c1_is_Screen_door20;
  real_T *c1_e_y2;
  uint8_T *c1_is_Screen_door21;
  real_T *c1_f_y2;
  uint8_T *c1_is_Screen_door30;
  real_T *c1_g_y2;
  uint8_T *c1_is_Screen_door31;
  real_T *c1_h_y2;
  uint8_T *c1_is_Train1_door;
  real_T *c1_b_y1;
  uint8_T *c1_is_Train2_door;
  real_T *c1_c_y1;
  uint8_T *c1_is_Train3_door;
  real_T *c1_d_y1;
  uint8_T *c1_is_UrgentController;
  int32_T *c1_i;
  int32_T *c1_N;
  real_T *c1_t;
  uint8_T *c1_is_Train3;
  real_T *c1_time;
  real_T *c1_distance;
  real_T *c1_v;
  real_T *c1_maxv;
  real_T *c1_j;
  uint8_T *c1_is_Controller1;
  real_T *c1_b_z;
  uint8_T *c1_is_Controller2;
  real_T *c1_c_z;
  uint8_T *c1_is_Controller3;
  real_T *c1_d_z;
  uint8_T *c1_is_Train0;
  real_T *c1_b_time;
  real_T *c1_b_distance;
  real_T *c1_b_v;
  real_T *c1_b_maxv;
  real_T *c1_b_j;
  uint8_T *c1_is_Train1;
  real_T *c1_c_time;
  real_T *c1_c_distance;
  real_T *c1_c_v;
  real_T *c1_c_maxv;
  real_T *c1_c_j;
  uint8_T *c1_is_Train2;
  real_T *c1_d_time;
  real_T *c1_d_distance;
  real_T *c1_d_v;
  real_T *c1_d_maxv;
  real_T *c1_d_j;
  int32_T *c1_b_i;
  real_T *c1_stationid;
  real_T *c1_side;
  int32_T *c1_c_i;
  int32_T *c1_d_i;
  real_T *c1_b_stationid;
  real_T *c1_b_side;
  int32_T *c1_e_i;
  real_T *c1_c_stationid;
  real_T *c1_c_side;
  int32_T *c1_f_i;
  real_T *c1_d_stationid;
  real_T *c1_d_side;
  int32_T *c1_g_i;
  int32_T *c1_h_i;
  int32_T *c1_i_i;
  real_T (*c1_openTD)[4];
  real_T (*c1_closeTD)[4];
  real_T (*c1_v_shutTD)[4];
  real_T (*c1_openPSD)[8];
  real_T (*c1_closePSD)[8];
  real_T (*c1_v_shutPSD)[8];
  real_T (*c1_stop)[4];
  real_T (*c1_PSDClosed)[8];
  real_T (*c1_Delay)[4];
  real_T (*c1_S)[4];
  real_T (*c1_urstop)[4];
  real_T (*c1_start)[4];
  int32_T (*c1_dir)[4];
  real_T (*c1_urstart)[4];
  int32_T *c1_sfEvent;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  boolean_T guard7 = FALSE;
  boolean_T guard8 = FALSE;
  boolean_T guard9 = FALSE;
  boolean_T guard10 = FALSE;
  boolean_T guard11 = FALSE;
  boolean_T guard12 = FALSE;
  boolean_T guard13 = FALSE;
  boolean_T guard14 = FALSE;
  boolean_T guard15 = FALSE;
  boolean_T guard16 = FALSE;
  boolean_T guard17 = FALSE;
  boolean_T guard18 = FALSE;
  boolean_T guard19 = FALSE;
  boolean_T guard20 = FALSE;
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
  c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
  c1_j = (real_T *)ssGetDWork(chartInstance->S, 90);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
  c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
  c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 86);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
  c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 84);
  c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
  c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
  c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
  c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 81);
  c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
  c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
  c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
  c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 76);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
  c1_side = (real_T *)ssGetDWork(chartInstance->S, 74);
  c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
  c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
  c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 69);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
  c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 67);
  c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
  c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
  c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
  c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
  c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
  c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
  c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
  c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
  c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
  c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
  c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
  c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
  c1_v_shutPSD = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c1_v_shutTD = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_lastMajorTime = (real_T *)ssGetDWork(chartInstance->S, 3);
  c1_stateChanged = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  c1_zcVar = (real_T *)(ssGetNonsampledZCs(chartInstance->S) + 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  if (*c1_lastMajorTime == _sfTime_) {
    *c1_zcVar = -1.0;
  } else {
    *c1_stateChanged = FALSE;
    if (*c1_is_active_c1_subwaycontrolsystem == 0U) {
      *c1_stateChanged = TRUE;
    } else {
      guard1 = FALSE;
      guard2 = FALSE;
      guard3 = FALSE;
      guard4 = FALSE;
      guard5 = FALSE;
      guard6 = FALSE;
      guard7 = FALSE;
      guard8 = FALSE;
      guard9 = FALSE;
      guard10 = FALSE;
      guard11 = FALSE;
      guard12 = FALSE;
      guard13 = FALSE;
      guard14 = FALSE;
      guard15 = FALSE;
      guard16 = FALSE;
      guard17 = FALSE;
      guard18 = FALSE;
      guard19 = FALSE;
      guard20 = FALSE;
      switch (*c1_is_Train0_door) {
       case c1_IN_closed:
        CV_STATE_EVAL(89, 0, 1);
        c1_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                    (*c1_openTD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_out) {
          *c1_stateChanged = TRUE;
        } else {
          guard20 = TRUE;
        }
        break;

       case c1_IN_open:
        CV_STATE_EVAL(89, 0, 2);
        c1_b_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
          (*c1_closeTD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_b_out) {
          *c1_stateChanged = TRUE;
        } else {
          guard20 = TRUE;
        }
        break;

       case c1_IN_part:
        CV_STATE_EVAL(89, 0, 3);
        c1_c_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0, *c1_y1 >=
          2.0 != 0U, *c1_sfEvent)) != 0);
        if (c1_c_out) {
          *c1_stateChanged = TRUE;
        } else {
          guard20 = TRUE;
        }
        break;

       case c1_IN_shut:
        CV_STATE_EVAL(89, 0, 4);
        c1_temp = (_SFD_CCP_CALL(2U, 0, *c1_y1 > 0.0 != 0U, *c1_sfEvent) != 0);
        if (c1_temp) {
          c1_temp = (_SFD_CCP_CALL(2U, 1, (*c1_v_shutTD)[0] == 0.0 != 0U,
                      *c1_sfEvent) != 0);
        }

        c1_d_out = (CV_TRANSITION_EVAL(2U, (int32_T)c1_temp) != 0);
        if (c1_d_out) {
          *c1_stateChanged = TRUE;
        } else {
          c1_e_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
            *c1_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_e_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard20 = TRUE;
          }
        }
        break;

       default:
        CV_STATE_EVAL(89, 0, 0);
        *c1_is_Train0_door = c1_IN_NO_ACTIVE_CHILD;
        guard20 = TRUE;
        break;
      }

      if (guard20 == TRUE) {
        switch (*c1_is_Screen_door00) {
         case c1_IN_closed:
          CV_STATE_EVAL(36, 0, 1);
          c1_f_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
            (*c1_openPSD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_f_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard19 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(36, 0, 2);
          c1_g_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
            (*c1_closePSD)[0] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_g_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard19 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(36, 0, 3);
          c1_h_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
            *c1_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_h_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard19 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(36, 0, 4);
          c1_i_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
            *c1_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_i_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_b_temp = (_SFD_CCP_CALL(9U, 0, *c1_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_b_temp) {
              c1_b_temp = (_SFD_CCP_CALL(9U, 1, (*c1_v_shutPSD)[0] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_j_out = (CV_TRANSITION_EVAL(9U, (int32_T)c1_b_temp) != 0);
            if (c1_j_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard19 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(36, 0, 0);
          *c1_is_Screen_door00 = c1_IN_NO_ACTIVE_CHILD;
          guard19 = TRUE;
          break;
        }
      }

      if (guard19 == TRUE) {
        switch (*c1_is_Controller0) {
         case c1_IN_about_to_close1:
          CV_STATE_EVAL(0, 0, 1);
          c1_k_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
            *c1_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_k_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard18 = TRUE;
          }
          break;

         case c1_IN_about_to_close2:
          CV_STATE_EVAL(0, 0, 2);
          c1_l_out = (CV_TRANSITION_EVAL(21U, (int32_T)_SFD_CCP_CALL(21U, 0,
            (int16_T)(*c1_is_Train0_door == c1_IN_closed) == 0 != 0U,
            *c1_sfEvent)) != 0);
          if (c1_l_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_m_out = (CV_TRANSITION_EVAL(18U, (int32_T)_SFD_CCP_CALL(18U, 0,
              *c1_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_m_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard18 = TRUE;
            }
          }
          break;

         case c1_IN_about_to_open1:
          CV_STATE_EVAL(0, 0, 3);
          c1_n_out = (CV_TRANSITION_EVAL(14U, (int32_T)_SFD_CCP_CALL(14U, 0,
            *c1_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_n_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard18 = TRUE;
          }
          break;

         case c1_IN_about_to_open2:
          CV_STATE_EVAL(0, 0, 4);
          c1_o_out = (CV_TRANSITION_EVAL(13U, (int32_T)_SFD_CCP_CALL(13U, 0,
            *c1_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_o_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard18 = TRUE;
          }
          break;

         case c1_IN_idle:
          CV_STATE_EVAL(0, 0, 5);
          c1_p_out = (CV_TRANSITION_EVAL(12U, (int32_T)_SFD_CCP_CALL(12U, 0,
            (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_b_i, 0, 3, 2, 0)] == 1.0
            != 0U, *c1_sfEvent)) != 0);
          if (c1_p_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_c_temp = (_SFD_CCP_CALL(109U, 0, *c1_z >= 1.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_c_temp) {
              c1_c_temp = (_SFD_CCP_CALL(109U, 1, (*c1_stop)
                [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_b_i, 0, 3, 2, 0)] != 1.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_q_out = (CV_TRANSITION_EVAL(109U, (int32_T)c1_c_temp) != 0);
            if (c1_q_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard18 = TRUE;
            }
          }
          break;

         case c1_IN_open1:
          CV_STATE_EVAL(0, 0, 6);
          c1_r_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
            *c1_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_r_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard18 = TRUE;
          }
          break;

         case c1_IN_ring:
          CV_STATE_EVAL(0, 0, 7);
          c1_d_temp = (_SFD_CCP_CALL(16U, 0, *c1_z >= 20.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_d_temp) {
            c1_d_temp = (_SFD_CCP_CALL(16U, 1, *c1_z <= 30.0 != 0U, *c1_sfEvent)
                         != 0);
          }

          c1_s_out = (CV_TRANSITION_EVAL(16U, (int32_T)c1_d_temp) != 0);
          if (c1_s_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard18 = TRUE;
          }
          break;

         case c1_IN_start:
          CV_STATE_EVAL(0, 0, 8);
          c1_t_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(19U, 0,
            *c1_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_t_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_u_out = (CV_TRANSITION_EVAL(143U, (int32_T)_SFD_CCP_CALL(143U, 0,
                          (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U,
              c1__s32_d_(chartInstance, *c1_stationid), 0, 3, 1, 0) +
              (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_side),
              0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_u_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard18 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(0, 0, 0);
          *c1_is_Controller0 = c1_IN_NO_ACTIVE_CHILD;
          guard18 = TRUE;
          break;
        }
      }

      if (guard18 == TRUE) {
        switch (*c1_is_Screen_door01) {
         case c1_IN_closed:
          CV_STATE_EVAL(41, 0, 1);
          c1_v_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0,
            (*c1_openPSD)[4] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_v_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard17 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(41, 0, 2);
          c1_w_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
            (*c1_closePSD)[4] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_w_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard17 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(41, 0, 3);
          c1_x_out = (CV_TRANSITION_EVAL(22U, (int32_T)_SFD_CCP_CALL(22U, 0,
            *c1_b_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_x_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard17 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(41, 0, 4);
          c1_y_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U, 0,
            *c1_b_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_y_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_e_temp = (_SFD_CCP_CALL(24U, 0, *c1_b_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_e_temp) {
              c1_e_temp = (_SFD_CCP_CALL(24U, 1, (*c1_v_shutPSD)[4] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ab_out = (CV_TRANSITION_EVAL(24U, (int32_T)c1_e_temp) != 0);
            if (c1_ab_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard17 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(41, 0, 0);
          *c1_is_Screen_door01 = c1_IN_NO_ACTIVE_CHILD;
          guard17 = TRUE;
          break;
        }
      }

      if (guard17 == TRUE) {
        switch (*c1_is_Screen_door10) {
         case c1_IN_closed:
          CV_STATE_EVAL(46, 0, 1);
          c1_bb_out = (CV_TRANSITION_EVAL(29U, (int32_T)_SFD_CCP_CALL(29U, 0,
            (*c1_openPSD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_bb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard16 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(46, 0, 2);
          c1_cb_out = (CV_TRANSITION_EVAL(31U, (int32_T)_SFD_CCP_CALL(31U, 0,
            (*c1_closePSD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_cb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard16 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(46, 0, 3);
          c1_db_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
            *c1_c_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_db_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard16 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(46, 0, 4);
          c1_eb_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL(33U, 0,
            *c1_c_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_eb_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_f_temp = (_SFD_CCP_CALL(30U, 0, *c1_c_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_f_temp) {
              c1_f_temp = (_SFD_CCP_CALL(30U, 1, (*c1_v_shutPSD)[1] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_fb_out = (CV_TRANSITION_EVAL(30U, (int32_T)c1_f_temp) != 0);
            if (c1_fb_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard16 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(46, 0, 0);
          *c1_is_Screen_door10 = c1_IN_NO_ACTIVE_CHILD;
          guard16 = TRUE;
          break;
        }
      }

      if (guard16 == TRUE) {
        switch (*c1_is_Screen_door11) {
         case c1_IN_closed:
          CV_STATE_EVAL(51, 0, 1);
          c1_gb_out = (CV_TRANSITION_EVAL(35U, (int32_T)_SFD_CCP_CALL(35U, 0,
            (*c1_openPSD)[5] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_gb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard15 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(51, 0, 2);
          c1_hb_out = (CV_TRANSITION_EVAL(37U, (int32_T)_SFD_CCP_CALL(37U, 0,
            (*c1_closePSD)[5] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_hb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard15 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(51, 0, 3);
          c1_ib_out = (CV_TRANSITION_EVAL(34U, (int32_T)_SFD_CCP_CALL(34U, 0,
            *c1_d_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ib_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard15 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(51, 0, 4);
          c1_jb_out = (CV_TRANSITION_EVAL(39U, (int32_T)_SFD_CCP_CALL(39U, 0,
            *c1_d_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_jb_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_g_temp = (_SFD_CCP_CALL(36U, 0, *c1_d_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_g_temp) {
              c1_g_temp = (_SFD_CCP_CALL(36U, 1, (*c1_v_shutPSD)[5] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_kb_out = (CV_TRANSITION_EVAL(36U, (int32_T)c1_g_temp) != 0);
            if (c1_kb_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard15 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(51, 0, 0);
          *c1_is_Screen_door11 = c1_IN_NO_ACTIVE_CHILD;
          guard15 = TRUE;
          break;
        }
      }

      if (guard15 == TRUE) {
        switch (*c1_is_Screen_door20) {
         case c1_IN_closed:
          CV_STATE_EVAL(56, 0, 1);
          c1_lb_out = (CV_TRANSITION_EVAL(41U, (int32_T)_SFD_CCP_CALL(41U, 0,
            (*c1_openPSD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_lb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard14 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(56, 0, 2);
          c1_mb_out = (CV_TRANSITION_EVAL(43U, (int32_T)_SFD_CCP_CALL(43U, 0,
            (*c1_closePSD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_mb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard14 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(56, 0, 3);
          c1_nb_out = (CV_TRANSITION_EVAL(40U, (int32_T)_SFD_CCP_CALL(40U, 0,
            *c1_e_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_nb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard14 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(56, 0, 4);
          c1_ob_out = (CV_TRANSITION_EVAL(45U, (int32_T)_SFD_CCP_CALL(45U, 0,
            *c1_e_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ob_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_h_temp = (_SFD_CCP_CALL(42U, 0, *c1_e_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_h_temp) {
              c1_h_temp = (_SFD_CCP_CALL(42U, 1, (*c1_v_shutPSD)[2] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_pb_out = (CV_TRANSITION_EVAL(42U, (int32_T)c1_h_temp) != 0);
            if (c1_pb_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard14 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(56, 0, 0);
          *c1_is_Screen_door20 = c1_IN_NO_ACTIVE_CHILD;
          guard14 = TRUE;
          break;
        }
      }

      if (guard14 == TRUE) {
        switch (*c1_is_Screen_door21) {
         case c1_IN_closed:
          CV_STATE_EVAL(61, 0, 1);
          c1_qb_out = (CV_TRANSITION_EVAL(47U, (int32_T)_SFD_CCP_CALL(47U, 0,
            (*c1_openPSD)[6] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_qb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard13 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(61, 0, 2);
          c1_rb_out = (CV_TRANSITION_EVAL(49U, (int32_T)_SFD_CCP_CALL(49U, 0,
            (*c1_closePSD)[6] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_rb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard13 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(61, 0, 3);
          c1_sb_out = (CV_TRANSITION_EVAL(46U, (int32_T)_SFD_CCP_CALL(46U, 0,
            *c1_f_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_sb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard13 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(61, 0, 4);
          c1_tb_out = (CV_TRANSITION_EVAL(51U, (int32_T)_SFD_CCP_CALL(51U, 0,
            *c1_f_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_tb_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_i_temp = (_SFD_CCP_CALL(48U, 0, *c1_f_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_i_temp) {
              c1_i_temp = (_SFD_CCP_CALL(48U, 1, (*c1_v_shutPSD)[6] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ub_out = (CV_TRANSITION_EVAL(48U, (int32_T)c1_i_temp) != 0);
            if (c1_ub_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard13 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(61, 0, 0);
          *c1_is_Screen_door21 = c1_IN_NO_ACTIVE_CHILD;
          guard13 = TRUE;
          break;
        }
      }

      if (guard13 == TRUE) {
        switch (*c1_is_Screen_door30) {
         case c1_IN_closed:
          CV_STATE_EVAL(66, 0, 1);
          c1_vb_out = (CV_TRANSITION_EVAL(53U, (int32_T)_SFD_CCP_CALL(53U, 0,
            (*c1_openPSD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_vb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard12 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(66, 0, 2);
          c1_wb_out = (CV_TRANSITION_EVAL(55U, (int32_T)_SFD_CCP_CALL(55U, 0,
            (*c1_closePSD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_wb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard12 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(66, 0, 3);
          c1_xb_out = (CV_TRANSITION_EVAL(52U, (int32_T)_SFD_CCP_CALL(52U, 0,
            *c1_g_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_xb_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard12 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(66, 0, 4);
          c1_yb_out = (CV_TRANSITION_EVAL(57U, (int32_T)_SFD_CCP_CALL(57U, 0,
            *c1_g_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yb_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_j_temp = (_SFD_CCP_CALL(54U, 0, *c1_g_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_j_temp) {
              c1_j_temp = (_SFD_CCP_CALL(54U, 1, (*c1_v_shutPSD)[3] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ac_out = (CV_TRANSITION_EVAL(54U, (int32_T)c1_j_temp) != 0);
            if (c1_ac_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard12 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(66, 0, 0);
          *c1_is_Screen_door30 = c1_IN_NO_ACTIVE_CHILD;
          guard12 = TRUE;
          break;
        }
      }

      if (guard12 == TRUE) {
        switch (*c1_is_Screen_door31) {
         case c1_IN_closed:
          CV_STATE_EVAL(71, 0, 1);
          c1_bc_out = (CV_TRANSITION_EVAL(59U, (int32_T)_SFD_CCP_CALL(59U, 0,
            (*c1_openPSD)[7] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_bc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard11 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(71, 0, 2);
          c1_cc_out = (CV_TRANSITION_EVAL(61U, (int32_T)_SFD_CCP_CALL(61U, 0,
            (*c1_closePSD)[7] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_cc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard11 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(71, 0, 3);
          c1_dc_out = (CV_TRANSITION_EVAL(58U, (int32_T)_SFD_CCP_CALL(58U, 0,
            *c1_h_y2 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_dc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard11 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(71, 0, 4);
          c1_ec_out = (CV_TRANSITION_EVAL(63U, (int32_T)_SFD_CCP_CALL(63U, 0,
            *c1_h_y2 <= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ec_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_k_temp = (_SFD_CCP_CALL(60U, 0, *c1_h_y2 > 0.0 != 0U, *c1_sfEvent)
                         != 0);
            if (c1_k_temp) {
              c1_k_temp = (_SFD_CCP_CALL(60U, 1, (*c1_v_shutPSD)[7] == 0.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_fc_out = (CV_TRANSITION_EVAL(60U, (int32_T)c1_k_temp) != 0);
            if (c1_fc_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard11 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(71, 0, 0);
          *c1_is_Screen_door31 = c1_IN_NO_ACTIVE_CHILD;
          guard11 = TRUE;
          break;
        }
      }

      if (guard11 == TRUE) {
        switch (*c1_is_Train1_door) {
         case c1_IN_closed:
          CV_STATE_EVAL(107, 0, 1);
          c1_gc_out = (CV_TRANSITION_EVAL(65U, (int32_T)_SFD_CCP_CALL(65U, 0,
            (*c1_openTD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_gc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard10 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(107, 0, 2);
          c1_hc_out = (CV_TRANSITION_EVAL(66U, (int32_T)_SFD_CCP_CALL(66U, 0,
            (*c1_closeTD)[1] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_hc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard10 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(107, 0, 3);
          c1_ic_out = (CV_TRANSITION_EVAL(64U, (int32_T)_SFD_CCP_CALL(64U, 0,
            *c1_b_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ic_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard10 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(107, 0, 4);
          c1_l_temp = (_SFD_CCP_CALL(67U, 0, *c1_b_y1 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_l_temp) {
            c1_l_temp = (_SFD_CCP_CALL(67U, 1, (*c1_v_shutTD)[1] == 0.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_jc_out = (CV_TRANSITION_EVAL(67U, (int32_T)c1_l_temp) != 0);
          if (c1_jc_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_kc_out = (CV_TRANSITION_EVAL(69U, (int32_T)_SFD_CCP_CALL(69U, 0, *
              c1_b_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_kc_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard10 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(107, 0, 0);
          *c1_is_Train1_door = c1_IN_NO_ACTIVE_CHILD;
          guard10 = TRUE;
          break;
        }
      }

      if (guard10 == TRUE) {
        switch (*c1_is_Train2_door) {
         case c1_IN_closed:
          CV_STATE_EVAL(125, 0, 1);
          c1_lc_out = (CV_TRANSITION_EVAL(71U, (int32_T)_SFD_CCP_CALL(71U, 0,
            (*c1_openTD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_lc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard9 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(125, 0, 2);
          c1_mc_out = (CV_TRANSITION_EVAL(72U, (int32_T)_SFD_CCP_CALL(72U, 0,
            (*c1_closeTD)[2] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_mc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard9 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(125, 0, 3);
          c1_nc_out = (CV_TRANSITION_EVAL(70U, (int32_T)_SFD_CCP_CALL(70U, 0,
            *c1_c_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_nc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard9 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(125, 0, 4);
          c1_m_temp = (_SFD_CCP_CALL(73U, 0, *c1_c_y1 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_m_temp) {
            c1_m_temp = (_SFD_CCP_CALL(73U, 1, (*c1_v_shutTD)[2] == 0.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_oc_out = (CV_TRANSITION_EVAL(73U, (int32_T)c1_m_temp) != 0);
          if (c1_oc_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_pc_out = (CV_TRANSITION_EVAL(75U, (int32_T)_SFD_CCP_CALL(75U, 0, *
              c1_c_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_pc_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard9 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(125, 0, 0);
          *c1_is_Train2_door = c1_IN_NO_ACTIVE_CHILD;
          guard9 = TRUE;
          break;
        }
      }

      if (guard9 == TRUE) {
        switch (*c1_is_Train3_door) {
         case c1_IN_closed:
          CV_STATE_EVAL(143, 0, 1);
          c1_qc_out = (CV_TRANSITION_EVAL(77U, (int32_T)_SFD_CCP_CALL(77U, 0,
            (*c1_openTD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_qc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard8 = TRUE;
          }
          break;

         case c1_IN_open:
          CV_STATE_EVAL(143, 0, 2);
          c1_rc_out = (CV_TRANSITION_EVAL(78U, (int32_T)_SFD_CCP_CALL(78U, 0,
            (*c1_closeTD)[3] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_rc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard8 = TRUE;
          }
          break;

         case c1_IN_part:
          CV_STATE_EVAL(143, 0, 3);
          c1_sc_out = (CV_TRANSITION_EVAL(76U, (int32_T)_SFD_CCP_CALL(76U, 0,
            *c1_d_y1 >= 2.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_sc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard8 = TRUE;
          }
          break;

         case c1_IN_shut:
          CV_STATE_EVAL(143, 0, 4);
          c1_n_temp = (_SFD_CCP_CALL(79U, 0, *c1_d_y1 > 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_n_temp) {
            c1_n_temp = (_SFD_CCP_CALL(79U, 1, (*c1_v_shutTD)[3] == 0.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_tc_out = (CV_TRANSITION_EVAL(79U, (int32_T)c1_n_temp) != 0);
          if (c1_tc_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_uc_out = (CV_TRANSITION_EVAL(81U, (int32_T)_SFD_CCP_CALL(81U, 0, *
              c1_d_y1 <= 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_uc_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard8 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(143, 0, 0);
          *c1_is_Train3_door = c1_IN_NO_ACTIVE_CHILD;
          guard8 = TRUE;
          break;
        }
      }

      if (guard8 == TRUE) {
        switch (*c1_is_UrgentController) {
         case c1_IN_D1:
          CV_STATE_EVAL(148, 0, 1);
          c1_o_temp = (_SFD_CCP_CALL(84U, 0, *c1_i != *c1_N != 0U, *c1_sfEvent)
                       != 0);
          if (c1_o_temp) {
            c1_o_temp = (_SFD_CCP_CALL(84U, 1, *c1_t >= 0.0 != 0U, *c1_sfEvent)
                         != 0);
          }

          c1_vc_out = (CV_TRANSITION_EVAL(84U, (int32_T)c1_o_temp) != 0);
          if (c1_vc_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_p_temp = (_SFD_CCP_CALL(147U, 0, *c1_i == *c1_N != 0U,
              *c1_sfEvent) != 0);
            if (c1_p_temp) {
              c1_p_temp = (_SFD_CCP_CALL(147U, 1, *c1_t >= 1.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_wc_out = (CV_TRANSITION_EVAL(147U, (int32_T)c1_p_temp) != 0);
            if (c1_wc_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard7 = TRUE;
            }
          }
          break;

         case c1_IN_Delay:
          CV_STATE_EVAL(148, 0, 2);
          c1_xc_out = (CV_TRANSITION_EVAL(83U, (int32_T)_SFD_CCP_CALL(83U, 0,
            *c1_t >= 150.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_xc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard7 = TRUE;
          }
          break;

         case c1_IN_tmp:
          CV_STATE_EVAL(148, 0, 3);
          c1_yc_out = (CV_TRANSITION_EVAL(86U, (int32_T)_SFD_CCP_CALL(86U, 0,
            *c1_t >= 0.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yc_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard7 = TRUE;
          }
          break;

         default:
          CV_STATE_EVAL(148, 0, 0);
          *c1_is_UrgentController = c1_IN_NO_ACTIVE_CHILD;
          guard7 = TRUE;
          break;
        }
      }

      if (guard7 == TRUE) {
        switch (*c1_is_Train3) {
         case c1_IN_ChangeDirection:
          CV_STATE_EVAL(130, 0, 1);
          c1_ad_out = (CV_TRANSITION_EVAL(99U, (int32_T)_SFD_CCP_CALL(99U, 0,
            *c1_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ad_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard6 = TRUE;
          }
          break;

         case c1_IN_init:
          CV_STATE_EVAL(130, 0, 2);
          c1_bd_out = (CV_TRANSITION_EVAL(95U, (int32_T)_SFD_CCP_CALL(95U, 0,
            *c1_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_c_i, 0, 3, 2,
            0)] != 0U, *c1_sfEvent)) != 0);
          if (c1_bd_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard6 = TRUE;
          }
          break;

         case c1_IN_near:
          CV_STATE_EVAL(130, 0, 3);
          c1_cd_out = (CV_TRANSITION_EVAL(96U, (int32_T)_SFD_CCP_CALL(96U, 0,
            muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
            c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 1.0 != 0U,
            *c1_sfEvent)) != 0);
          if (c1_cd_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_dd_out = (CV_TRANSITION_EVAL(97U, (int32_T)_SFD_CCP_CALL(97U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_dd_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard6 = TRUE;
            }
          }
          break;

         case c1_IN_recover:
          CV_STATE_EVAL(130, 0, 4);
          c1_ed_out = (CV_TRANSITION_EVAL(90U, (int32_T)_SFD_CCP_CALL(90U, 0,
            (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3, 1, 0)] ==
            1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ed_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_fd_out = (CV_TRANSITION_EVAL(91U, (int32_T)_SFD_CCP_CALL(91U, 0,
              muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                                (10U, c1__s32_d_(chartInstance, *c1_j), 0, 3, 2,
                                 0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_fd_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard6 = TRUE;
            }
          }
          break;

         case c1_IN_run:
          CV_STATE_EVAL(130, 0, 5);
          c1_gd_out = (CV_TRANSITION_EVAL(107U, (int32_T)_SFD_CCP_CALL(107U, 0,
            muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
            c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
            *c1_sfEvent)) != 0);
          if (c1_gd_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_hd_out = (CV_TRANSITION_EVAL(108U, (int32_T)_SFD_CCP_CALL(108U, 0,
              *c1_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_hd_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_id_out = (CV_TRANSITION_EVAL(100U, (int32_T)_SFD_CCP_CALL(100U,
                0, (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0, 3, 1, 0)]
                == 1.0 != 0U, *c1_sfEvent)) != 0);
              if (c1_id_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard6 = TRUE;
              }
            }
          }
          break;

         case c1_IN_select:
          CV_STATE_EVAL(130, 0, 6);
          c1_jd_out = (CV_TRANSITION_EVAL(148U, (int32_T)_SFD_CCP_CALL(148U, 0, *
            c1_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_jd_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_kd_out = (CV_TRANSITION_EVAL(89U, (int32_T)_SFD_CCP_CALL(89U, 0, *
              c1_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_kd_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard6 = TRUE;
            }
          }
          break;

         case c1_IN_stablerun:
          CV_STATE_EVAL(130, 0, 7);
          c1_ld_out = (CV_TRANSITION_EVAL(106U, (int32_T)_SFD_CCP_CALL(106U, 0,
            muDoubleScalarAbs(*c1_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK(10U,
            c1__s32_d_(chartInstance, *c1_j), 0, 3, 2, 0)]) <= 500.0 != 0U,
            *c1_sfEvent)) != 0);
          if (c1_ld_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_md_out = (CV_TRANSITION_EVAL(101U, (int32_T)_SFD_CCP_CALL(101U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_md_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard6 = TRUE;
            }
          }
          break;

         case c1_IN_stop:
          CV_STATE_EVAL(130, 0, 8);
          c1_nd_out = (CV_TRANSITION_EVAL(98U, (int32_T)_SFD_CCP_CALL(98U, 0,
            (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_c_i, 0, 3, 1, 0)] == 1.0
            != 0U, *c1_sfEvent)) != 0);
          if (c1_nd_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard6 = TRUE;
          }
          break;

         case c1_b_IN_tmp:
          CV_STATE_EVAL(130, 0, 9);
          c1_q_temp = (_SFD_CCP_CALL(104U, 0, *c1_j == 0.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_q_temp) {
            c1_q_temp = (_SFD_CCP_CALL(104U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == -1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_od_out = (CV_TRANSITION_EVAL(104U, (int32_T)c1_q_temp) != 0);
          if (c1_od_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_r_temp = (_SFD_CCP_CALL(105U, 0, *c1_j == (real_T)c1__s32_minus__
                          (chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
            if (c1_r_temp) {
              c1_r_temp = (_SFD_CCP_CALL(105U, 1, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
            }

            c1_pd_out = (CV_TRANSITION_EVAL(105U, (int32_T)c1_r_temp) != 0);
            if (c1_pd_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_s_temp = (_SFD_CCP_CALL(103U, 0, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
              if (c1_s_temp) {
                c1_s_temp = (_SFD_CCP_CALL(103U, 1, *c1_j < (real_T)
                  c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent)
                             != 0);
              }

              c1_t_temp = c1_s_temp;
              if (!c1_t_temp) {
                c1_u_temp = (_SFD_CCP_CALL(103U, 2, (*c1_dir)
                  [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i, 0, 3, 1, 0)] == -1 !=
                  0U, *c1_sfEvent) != 0);
                if (c1_u_temp) {
                  c1_u_temp = (_SFD_CCP_CALL(103U, 3, *c1_j > 0.0 != 0U,
                    *c1_sfEvent) != 0);
                }

                c1_t_temp = c1_u_temp;
              }

              c1_qd_out = (CV_TRANSITION_EVAL(103U, (int32_T)c1_t_temp) != 0);
              if (c1_qd_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard6 = TRUE;
              }
            }
          }
          break;

         case c1_IN_urgent_dec:
          CV_STATE_EVAL(130, 0, 10);
          c1_rd_out = (CV_TRANSITION_EVAL(93U, (int32_T)_SFD_CCP_CALL(93U, 0,
            *c1_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
          if (c1_rd_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard6 = TRUE;
          }
          break;

         case c1_IN_urgent_inc:
          CV_STATE_EVAL(130, 0, 11);
          c1_sd_out = (CV_TRANSITION_EVAL(88U, (int32_T)_SFD_CCP_CALL(88U, 0,
            *c1_v >= *c1_maxv != 0U, *c1_sfEvent)) != 0);
          if (c1_sd_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_td_out = (CV_TRANSITION_EVAL(92U, (int32_T)_SFD_CCP_CALL(92U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_c_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_td_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard6 = TRUE;
            }
          }
          break;

         case c1_IN_urgent_stop:
          CV_STATE_EVAL(130, 0, 12);
          c1_ud_out = (CV_TRANSITION_EVAL(149U, (int32_T)_SFD_CCP_CALL(149U, 0,
                         (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_c_i, 0,
            3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ud_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard6 = TRUE;
          }
          break;

         default:
          CV_STATE_EVAL(130, 0, 0);
          *c1_is_Train3 = c1_IN_NO_ACTIVE_CHILD;
          guard6 = TRUE;
          break;
        }
      }

      if (guard6 == TRUE) {
        switch (*c1_is_Controller1) {
         case c1_IN_about_to_close1:
          CV_STATE_EVAL(9, 0, 1);
          c1_vd_out = (CV_TRANSITION_EVAL(112U, (int32_T)_SFD_CCP_CALL(112U, 0, *
            c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_vd_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard5 = TRUE;
          }
          break;

         case c1_IN_about_to_close2:
          CV_STATE_EVAL(9, 0, 2);
          c1_wd_out = (CV_TRANSITION_EVAL(110U, (int32_T)_SFD_CCP_CALL(110U, 0,
                         (int16_T)(*c1_is_Train1_door == c1_IN_closed) == 0 !=
            0U, *c1_sfEvent)) != 0);
          if (c1_wd_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_xd_out = (CV_TRANSITION_EVAL(113U, (int32_T)_SFD_CCP_CALL(113U, 0,
              *c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_xd_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard5 = TRUE;
            }
          }
          break;

         case c1_IN_about_to_open1:
          CV_STATE_EVAL(9, 0, 3);
          c1_yd_out = (CV_TRANSITION_EVAL(119U, (int32_T)_SFD_CCP_CALL(119U, 0, *
            c1_b_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yd_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard5 = TRUE;
          }
          break;

         case c1_IN_about_to_open2:
          CV_STATE_EVAL(9, 0, 4);
          c1_ae_out = (CV_TRANSITION_EVAL(117U, (int32_T)_SFD_CCP_CALL(117U, 0, *
            c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ae_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard5 = TRUE;
          }
          break;

         case c1_IN_idle:
          CV_STATE_EVAL(9, 0, 5);
          c1_be_out = (CV_TRANSITION_EVAL(114U, (int32_T)_SFD_CCP_CALL(114U, 0,
                         (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3, 2,
            0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_be_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_v_temp = (_SFD_CCP_CALL(116U, 0, *c1_b_z >= 1.0 != 0U,
              *c1_sfEvent) != 0);
            if (c1_v_temp) {
              c1_v_temp = (_SFD_CCP_CALL(116U, 1, (*c1_stop)
                [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_d_i, 0, 3, 2, 0)] != 1.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ce_out = (CV_TRANSITION_EVAL(116U, (int32_T)c1_v_temp) != 0);
            if (c1_ce_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard5 = TRUE;
            }
          }
          break;

         case c1_IN_open1:
          CV_STATE_EVAL(9, 0, 6);
          c1_de_out = (CV_TRANSITION_EVAL(118U, (int32_T)_SFD_CCP_CALL(118U, 0, *
            c1_b_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_de_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard5 = TRUE;
          }
          break;

         case c1_IN_ring:
          CV_STATE_EVAL(9, 0, 7);
          c1_w_temp = (_SFD_CCP_CALL(120U, 0, *c1_b_z >= 20.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_w_temp) {
            c1_w_temp = (_SFD_CCP_CALL(120U, 1, *c1_b_z <= 30.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_ee_out = (CV_TRANSITION_EVAL(120U, (int32_T)c1_w_temp) != 0);
          if (c1_ee_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard5 = TRUE;
          }
          break;

         case c1_IN_start:
          CV_STATE_EVAL(9, 0, 8);
          c1_fe_out = (CV_TRANSITION_EVAL(115U, (int32_T)_SFD_CCP_CALL(115U, 0, *
            c1_b_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_fe_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ge_out = (CV_TRANSITION_EVAL(144U, (int32_T)_SFD_CCP_CALL(144U, 0,
                           (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U,
              c1__s32_d_(chartInstance, *c1_b_stationid), 0, 3, 1, 0) +
              (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_b_side),
              0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_ge_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard5 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(9, 0, 0);
          *c1_is_Controller1 = c1_IN_NO_ACTIVE_CHILD;
          guard5 = TRUE;
          break;
        }
      }

      if (guard5 == TRUE) {
        switch (*c1_is_Controller2) {
         case c1_IN_about_to_close1:
          CV_STATE_EVAL(18, 0, 1);
          c1_he_out = (CV_TRANSITION_EVAL(123U, (int32_T)_SFD_CCP_CALL(123U, 0, *
            c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_he_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard4 = TRUE;
          }
          break;

         case c1_IN_about_to_close2:
          CV_STATE_EVAL(18, 0, 2);
          c1_ie_out = (CV_TRANSITION_EVAL(121U, (int32_T)_SFD_CCP_CALL(121U, 0,
                         (int16_T)(*c1_is_Train2_door == c1_IN_closed) == 0 !=
            0U, *c1_sfEvent)) != 0);
          if (c1_ie_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_je_out = (CV_TRANSITION_EVAL(124U, (int32_T)_SFD_CCP_CALL(124U, 0,
              *c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_je_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard4 = TRUE;
            }
          }
          break;

         case c1_IN_about_to_open1:
          CV_STATE_EVAL(18, 0, 3);
          c1_ke_out = (CV_TRANSITION_EVAL(130U, (int32_T)_SFD_CCP_CALL(130U, 0, *
            c1_c_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ke_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard4 = TRUE;
          }
          break;

         case c1_IN_about_to_open2:
          CV_STATE_EVAL(18, 0, 4);
          c1_le_out = (CV_TRANSITION_EVAL(128U, (int32_T)_SFD_CCP_CALL(128U, 0, *
            c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_le_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard4 = TRUE;
          }
          break;

         case c1_IN_idle:
          CV_STATE_EVAL(18, 0, 5);
          c1_me_out = (CV_TRANSITION_EVAL(125U, (int32_T)_SFD_CCP_CALL(125U, 0,
                         (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3, 2,
            0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_me_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_x_temp = (_SFD_CCP_CALL(127U, 0, *c1_c_z >= 1.0 != 0U,
              *c1_sfEvent) != 0);
            if (c1_x_temp) {
              c1_x_temp = (_SFD_CCP_CALL(127U, 1, (*c1_stop)
                [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_e_i, 0, 3, 2, 0)] != 1.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ne_out = (CV_TRANSITION_EVAL(127U, (int32_T)c1_x_temp) != 0);
            if (c1_ne_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard4 = TRUE;
            }
          }
          break;

         case c1_IN_open1:
          CV_STATE_EVAL(18, 0, 6);
          c1_oe_out = (CV_TRANSITION_EVAL(129U, (int32_T)_SFD_CCP_CALL(129U, 0, *
            c1_c_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_oe_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard4 = TRUE;
          }
          break;

         case c1_IN_ring:
          CV_STATE_EVAL(18, 0, 7);
          c1_y_temp = (_SFD_CCP_CALL(131U, 0, *c1_c_z >= 20.0 != 0U, *c1_sfEvent)
                       != 0);
          if (c1_y_temp) {
            c1_y_temp = (_SFD_CCP_CALL(131U, 1, *c1_c_z <= 30.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_pe_out = (CV_TRANSITION_EVAL(131U, (int32_T)c1_y_temp) != 0);
          if (c1_pe_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard4 = TRUE;
          }
          break;

         case c1_IN_start:
          CV_STATE_EVAL(18, 0, 8);
          c1_qe_out = (CV_TRANSITION_EVAL(126U, (int32_T)_SFD_CCP_CALL(126U, 0, *
            c1_c_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_qe_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_re_out = (CV_TRANSITION_EVAL(145U, (int32_T)_SFD_CCP_CALL(145U, 0,
                           (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U,
              c1__s32_d_(chartInstance, *c1_c_stationid), 0, 3, 1, 0) +
              (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_c_side),
              0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_re_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard4 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(18, 0, 0);
          *c1_is_Controller2 = c1_IN_NO_ACTIVE_CHILD;
          guard4 = TRUE;
          break;
        }
      }

      if (guard4 == TRUE) {
        switch (*c1_is_Controller3) {
         case c1_IN_about_to_close1:
          CV_STATE_EVAL(27, 0, 1);
          c1_se_out = (CV_TRANSITION_EVAL(134U, (int32_T)_SFD_CCP_CALL(134U, 0, *
            c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_se_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard3 = TRUE;
          }
          break;

         case c1_IN_about_to_close2:
          CV_STATE_EVAL(27, 0, 2);
          c1_te_out = (CV_TRANSITION_EVAL(132U, (int32_T)_SFD_CCP_CALL(132U, 0,
                         (int16_T)(*c1_is_Train3_door == c1_IN_closed) == 0 !=
            0U, *c1_sfEvent)) != 0);
          if (c1_te_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ue_out = (CV_TRANSITION_EVAL(135U, (int32_T)_SFD_CCP_CALL(135U, 0,
              *c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_ue_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard3 = TRUE;
            }
          }
          break;

         case c1_IN_about_to_open1:
          CV_STATE_EVAL(27, 0, 3);
          c1_ve_out = (CV_TRANSITION_EVAL(141U, (int32_T)_SFD_CCP_CALL(141U, 0, *
            c1_d_z >= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ve_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard3 = TRUE;
          }
          break;

         case c1_IN_about_to_open2:
          CV_STATE_EVAL(27, 0, 4);
          c1_we_out = (CV_TRANSITION_EVAL(139U, (int32_T)_SFD_CCP_CALL(139U, 0, *
            c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_we_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard3 = TRUE;
          }
          break;

         case c1_IN_idle:
          CV_STATE_EVAL(27, 0, 5);
          c1_xe_out = (CV_TRANSITION_EVAL(136U, (int32_T)_SFD_CCP_CALL(136U, 0,
                         (*c1_stop)[_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3, 2,
            0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_xe_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ab_temp = (_SFD_CCP_CALL(138U, 0, *c1_d_z >= 1.0 != 0U,
              *c1_sfEvent) != 0);
            if (c1_ab_temp) {
              c1_ab_temp = (_SFD_CCP_CALL(138U, 1, (*c1_stop)
                [_SFD_ARRAY_BOUNDS_CHECK(3U, *c1_f_i, 0, 3, 2, 0)] != 1.0 != 0U,
                *c1_sfEvent) != 0);
            }

            c1_ye_out = (CV_TRANSITION_EVAL(138U, (int32_T)c1_ab_temp) != 0);
            if (c1_ye_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard3 = TRUE;
            }
          }
          break;

         case c1_IN_open1:
          CV_STATE_EVAL(27, 0, 6);
          c1_af_out = (CV_TRANSITION_EVAL(140U, (int32_T)_SFD_CCP_CALL(140U, 0, *
            c1_d_z >= 10.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_af_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard3 = TRUE;
          }
          break;

         case c1_IN_ring:
          CV_STATE_EVAL(27, 0, 7);
          c1_bb_temp = (_SFD_CCP_CALL(142U, 0, *c1_d_z >= 20.0 != 0U,
            *c1_sfEvent) != 0);
          if (c1_bb_temp) {
            c1_bb_temp = (_SFD_CCP_CALL(142U, 1, *c1_d_z <= 30.0 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_bf_out = (CV_TRANSITION_EVAL(142U, (int32_T)c1_bb_temp) != 0);
          if (c1_bf_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard3 = TRUE;
          }
          break;

         case c1_IN_start:
          CV_STATE_EVAL(27, 0, 8);
          c1_cf_out = (CV_TRANSITION_EVAL(137U, (int32_T)_SFD_CCP_CALL(137U, 0, *
            c1_d_z >= 5.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_cf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_df_out = (CV_TRANSITION_EVAL(146U, (int32_T)_SFD_CCP_CALL(146U, 0,
                           (*c1_PSDClosed)[_SFD_ARRAY_BOUNDS_CHECK(19U,
              c1__s32_d_(chartInstance, *c1_d_stationid), 0, 3, 1, 0) +
              (_SFD_ARRAY_BOUNDS_CHECK(19U, c1__s32_d_(chartInstance, *c1_d_side),
              0, 1, 2, 0) << 2)] == 0.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_df_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard3 = TRUE;
            }
          }
          break;

         default:
          CV_STATE_EVAL(27, 0, 0);
          *c1_is_Controller3 = c1_IN_NO_ACTIVE_CHILD;
          guard3 = TRUE;
          break;
        }
      }

      if (guard3 == TRUE) {
        switch (*c1_is_Train0) {
         case c1_IN_ChangeDirection:
          CV_STATE_EVAL(76, 0, 1);
          c1_ef_out = (CV_TRANSITION_EVAL(164U, (int32_T)_SFD_CCP_CALL(164U, 0, *
            c1_b_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ef_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard2 = TRUE;
          }
          break;

         case c1_IN_init:
          CV_STATE_EVAL(76, 0, 2);
          c1_ff_out = (CV_TRANSITION_EVAL(160U, (int32_T)_SFD_CCP_CALL(160U, 0, *
            c1_b_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_g_i, 0, 3,
            2, 0)] != 0U, *c1_sfEvent)) != 0);
          if (c1_ff_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard2 = TRUE;
          }
          break;

         case c1_IN_near:
          CV_STATE_EVAL(76, 0, 3);
          c1_gf_out = (CV_TRANSITION_EVAL(161U, (int32_T)_SFD_CCP_CALL(161U, 0,
            muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_gf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_hf_out = (CV_TRANSITION_EVAL(162U, (int32_T)_SFD_CCP_CALL(162U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_hf_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard2 = TRUE;
            }
          }
          break;

         case c1_IN_recover:
          CV_STATE_EVAL(76, 0, 4);
          c1_if_out = (CV_TRANSITION_EVAL(155U, (int32_T)_SFD_CCP_CALL(155U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_if_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_jf_out = (CV_TRANSITION_EVAL(156U, (int32_T)_SFD_CCP_CALL(156U, 0,
              muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                                (10U, c1__s32_d_(chartInstance, *c1_b_j), 0, 3,
                                 2, 0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_jf_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard2 = TRUE;
            }
          }
          break;

         case c1_IN_run:
          CV_STATE_EVAL(76, 0, 5);
          c1_kf_out = (CV_TRANSITION_EVAL(172U, (int32_T)_SFD_CCP_CALL(172U, 0,
            muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_kf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_lf_out = (CV_TRANSITION_EVAL(173U, (int32_T)_SFD_CCP_CALL(173U, 0,
              *c1_b_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_lf_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_mf_out = (CV_TRANSITION_EVAL(166U, (int32_T)_SFD_CCP_CALL(166U,
                0, (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0, 3, 1, 0)]
                == 1.0 != 0U, *c1_sfEvent)) != 0);
              if (c1_mf_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard2 = TRUE;
              }
            }
          }
          break;

         case c1_IN_select:
          CV_STATE_EVAL(76, 0, 6);
          c1_nf_out = (CV_TRANSITION_EVAL(152U, (int32_T)_SFD_CCP_CALL(152U, 0, *
            c1_b_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_nf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_of_out = (CV_TRANSITION_EVAL(153U, (int32_T)_SFD_CCP_CALL(153U, 0,
              *c1_b_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_of_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard2 = TRUE;
            }
          }
          break;

         case c1_IN_stablerun:
          CV_STATE_EVAL(76, 0, 7);
          c1_pf_out = (CV_TRANSITION_EVAL(171U, (int32_T)_SFD_CCP_CALL(171U, 0,
            muDoubleScalarAbs(*c1_b_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_b_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_pf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_qf_out = (CV_TRANSITION_EVAL(167U, (int32_T)_SFD_CCP_CALL(167U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_qf_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard2 = TRUE;
            }
          }
          break;

         case c1_IN_stop:
          CV_STATE_EVAL(76, 0, 8);
          c1_rf_out = (CV_TRANSITION_EVAL(163U, (int32_T)_SFD_CCP_CALL(163U, 0,
                         (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_g_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_rf_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard2 = TRUE;
          }
          break;

         case c1_b_IN_tmp:
          CV_STATE_EVAL(76, 0, 9);
          c1_cb_temp = (_SFD_CCP_CALL(169U, 0, *c1_b_j == 0.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_cb_temp) {
            c1_cb_temp = (_SFD_CCP_CALL(169U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == -1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_sf_out = (CV_TRANSITION_EVAL(169U, (int32_T)c1_cb_temp) != 0);
          if (c1_sf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_db_temp = (_SFD_CCP_CALL(170U, 0, *c1_b_j == (real_T)
              c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
            if (c1_db_temp) {
              c1_db_temp = (_SFD_CCP_CALL(170U, 1, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
            }

            c1_tf_out = (CV_TRANSITION_EVAL(170U, (int32_T)c1_db_temp) != 0);
            if (c1_tf_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_eb_temp = (_SFD_CCP_CALL(168U, 0, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
              if (c1_eb_temp) {
                c1_eb_temp = (_SFD_CCP_CALL(168U, 1, *c1_b_j < (real_T)
                  c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent)
                              != 0);
              }

              c1_fb_temp = c1_eb_temp;
              if (!c1_fb_temp) {
                c1_gb_temp = (_SFD_CCP_CALL(168U, 2, (*c1_dir)
                  [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_g_i, 0, 3, 1, 0)] == -1 !=
                  0U, *c1_sfEvent) != 0);
                if (c1_gb_temp) {
                  c1_gb_temp = (_SFD_CCP_CALL(168U, 3, *c1_b_j > 0.0 != 0U,
                    *c1_sfEvent) != 0);
                }

                c1_fb_temp = c1_gb_temp;
              }

              c1_uf_out = (CV_TRANSITION_EVAL(168U, (int32_T)c1_fb_temp) != 0);
              if (c1_uf_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard2 = TRUE;
              }
            }
          }
          break;

         case c1_IN_urgent_dec:
          CV_STATE_EVAL(76, 0, 10);
          c1_vf_out = (CV_TRANSITION_EVAL(159U, (int32_T)_SFD_CCP_CALL(159U, 0, *
            c1_b_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
          if (c1_vf_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard2 = TRUE;
          }
          break;

         case c1_IN_urgent_inc:
          CV_STATE_EVAL(76, 0, 11);
          c1_wf_out = (CV_TRANSITION_EVAL(151U, (int32_T)_SFD_CCP_CALL(151U, 0, *
            c1_b_v >= *c1_b_maxv != 0U, *c1_sfEvent)) != 0);
          if (c1_wf_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_xf_out = (CV_TRANSITION_EVAL(157U, (int32_T)_SFD_CCP_CALL(157U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_g_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_xf_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard2 = TRUE;
            }
          }
          break;

         case c1_IN_urgent_stop:
          CV_STATE_EVAL(76, 0, 12);
          c1_yf_out = (CV_TRANSITION_EVAL(154U, (int32_T)_SFD_CCP_CALL(154U, 0,
                         (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_g_i, 0,
            3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_yf_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard2 = TRUE;
          }
          break;

         default:
          CV_STATE_EVAL(76, 0, 0);
          *c1_is_Train0 = c1_IN_NO_ACTIVE_CHILD;
          guard2 = TRUE;
          break;
        }
      }

      if (guard2 == TRUE) {
        switch (*c1_is_Train1) {
         case c1_IN_ChangeDirection:
          CV_STATE_EVAL(94, 0, 1);
          c1_ag_out = (CV_TRANSITION_EVAL(188U, (int32_T)_SFD_CCP_CALL(188U, 0, *
            c1_c_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ag_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard1 = TRUE;
          }
          break;

         case c1_IN_init:
          CV_STATE_EVAL(94, 0, 2);
          c1_bg_out = (CV_TRANSITION_EVAL(184U, (int32_T)_SFD_CCP_CALL(184U, 0, *
            c1_c_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_h_i, 0, 3,
            2, 0)] != 0U, *c1_sfEvent)) != 0);
          if (c1_bg_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard1 = TRUE;
          }
          break;

         case c1_IN_near:
          CV_STATE_EVAL(94, 0, 3);
          c1_cg_out = (CV_TRANSITION_EVAL(185U, (int32_T)_SFD_CCP_CALL(185U, 0,
            muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_cg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_dg_out = (CV_TRANSITION_EVAL(186U, (int32_T)_SFD_CCP_CALL(186U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_dg_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard1 = TRUE;
            }
          }
          break;

         case c1_IN_recover:
          CV_STATE_EVAL(94, 0, 4);
          c1_eg_out = (CV_TRANSITION_EVAL(179U, (int32_T)_SFD_CCP_CALL(179U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_eg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_fg_out = (CV_TRANSITION_EVAL(180U, (int32_T)_SFD_CCP_CALL(180U, 0,
              muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                                (10U, c1__s32_d_(chartInstance, *c1_c_j), 0, 3,
                                 2, 0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_fg_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard1 = TRUE;
            }
          }
          break;

         case c1_IN_run:
          CV_STATE_EVAL(94, 0, 5);
          c1_gg_out = (CV_TRANSITION_EVAL(196U, (int32_T)_SFD_CCP_CALL(196U, 0,
            muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_gg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_hg_out = (CV_TRANSITION_EVAL(197U, (int32_T)_SFD_CCP_CALL(197U, 0,
              *c1_c_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_hg_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_ig_out = (CV_TRANSITION_EVAL(190U, (int32_T)_SFD_CCP_CALL(190U,
                0, (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0, 3, 1, 0)]
                == 1.0 != 0U, *c1_sfEvent)) != 0);
              if (c1_ig_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard1 = TRUE;
              }
            }
          }
          break;

         case c1_IN_select:
          CV_STATE_EVAL(94, 0, 6);
          c1_jg_out = (CV_TRANSITION_EVAL(176U, (int32_T)_SFD_CCP_CALL(176U, 0, *
            c1_c_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_jg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_kg_out = (CV_TRANSITION_EVAL(177U, (int32_T)_SFD_CCP_CALL(177U, 0,
              *c1_c_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_kg_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard1 = TRUE;
            }
          }
          break;

         case c1_IN_stablerun:
          CV_STATE_EVAL(94, 0, 7);
          c1_lg_out = (CV_TRANSITION_EVAL(195U, (int32_T)_SFD_CCP_CALL(195U, 0,
            muDoubleScalarAbs(*c1_c_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_c_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_lg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_mg_out = (CV_TRANSITION_EVAL(191U, (int32_T)_SFD_CCP_CALL(191U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_mg_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard1 = TRUE;
            }
          }
          break;

         case c1_IN_stop:
          CV_STATE_EVAL(94, 0, 8);
          c1_ng_out = (CV_TRANSITION_EVAL(187U, (int32_T)_SFD_CCP_CALL(187U, 0,
                         (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_h_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ng_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard1 = TRUE;
          }
          break;

         case c1_b_IN_tmp:
          CV_STATE_EVAL(94, 0, 9);
          c1_hb_temp = (_SFD_CCP_CALL(193U, 0, *c1_c_j == 0.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_hb_temp) {
            c1_hb_temp = (_SFD_CCP_CALL(193U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == -1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_og_out = (CV_TRANSITION_EVAL(193U, (int32_T)c1_hb_temp) != 0);
          if (c1_og_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ib_temp = (_SFD_CCP_CALL(194U, 0, *c1_c_j == (real_T)
              c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
            if (c1_ib_temp) {
              c1_ib_temp = (_SFD_CCP_CALL(194U, 1, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
            }

            c1_pg_out = (CV_TRANSITION_EVAL(194U, (int32_T)c1_ib_temp) != 0);
            if (c1_pg_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_jb_temp = (_SFD_CCP_CALL(192U, 0, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
              if (c1_jb_temp) {
                c1_jb_temp = (_SFD_CCP_CALL(192U, 1, *c1_c_j < (real_T)
                  c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent)
                              != 0);
              }

              c1_kb_temp = c1_jb_temp;
              if (!c1_kb_temp) {
                c1_lb_temp = (_SFD_CCP_CALL(192U, 2, (*c1_dir)
                  [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_h_i, 0, 3, 1, 0)] == -1 !=
                  0U, *c1_sfEvent) != 0);
                if (c1_lb_temp) {
                  c1_lb_temp = (_SFD_CCP_CALL(192U, 3, *c1_c_j > 0.0 != 0U,
                    *c1_sfEvent) != 0);
                }

                c1_kb_temp = c1_lb_temp;
              }

              c1_qg_out = (CV_TRANSITION_EVAL(192U, (int32_T)c1_kb_temp) != 0);
              if (c1_qg_out) {
                *c1_stateChanged = TRUE;
              } else {
                guard1 = TRUE;
              }
            }
          }
          break;

         case c1_IN_urgent_dec:
          CV_STATE_EVAL(94, 0, 10);
          c1_rg_out = (CV_TRANSITION_EVAL(183U, (int32_T)_SFD_CCP_CALL(183U, 0, *
            c1_c_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
          if (c1_rg_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard1 = TRUE;
          }
          break;

         case c1_IN_urgent_inc:
          CV_STATE_EVAL(94, 0, 11);
          c1_sg_out = (CV_TRANSITION_EVAL(175U, (int32_T)_SFD_CCP_CALL(175U, 0, *
            c1_c_v >= *c1_c_maxv != 0U, *c1_sfEvent)) != 0);
          if (c1_sg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_tg_out = (CV_TRANSITION_EVAL(181U, (int32_T)_SFD_CCP_CALL(181U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_h_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_tg_out) {
              *c1_stateChanged = TRUE;
            } else {
              guard1 = TRUE;
            }
          }
          break;

         case c1_IN_urgent_stop:
          CV_STATE_EVAL(94, 0, 12);
          c1_ug_out = (CV_TRANSITION_EVAL(178U, (int32_T)_SFD_CCP_CALL(178U, 0,
                         (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_h_i, 0,
            3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ug_out) {
            *c1_stateChanged = TRUE;
          } else {
            guard1 = TRUE;
          }
          break;

         default:
          CV_STATE_EVAL(94, 0, 0);
          *c1_is_Train1 = c1_IN_NO_ACTIVE_CHILD;
          guard1 = TRUE;
          break;
        }
      }

      if (guard1 == TRUE) {
        switch (*c1_is_Train2) {
         case c1_IN_ChangeDirection:
          CV_STATE_EVAL(112, 0, 1);
          c1_vg_out = (CV_TRANSITION_EVAL(212U, (int32_T)_SFD_CCP_CALL(212U, 0, *
            c1_d_time >= 30.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_vg_out) {
            *c1_stateChanged = TRUE;
          }
          break;

         case c1_IN_init:
          CV_STATE_EVAL(112, 0, 2);
          c1_wg_out = (CV_TRANSITION_EVAL(208U, (int32_T)_SFD_CCP_CALL(208U, 0, *
            c1_d_time >= (*c1_Delay)[_SFD_ARRAY_BOUNDS_CHECK(7U, *c1_i_i, 0, 3,
            2, 0)] != 0U, *c1_sfEvent)) != 0);
          if (c1_wg_out) {
            *c1_stateChanged = TRUE;
          }
          break;

         case c1_IN_near:
          CV_STATE_EVAL(112, 0, 3);
          c1_xg_out = (CV_TRANSITION_EVAL(209U, (int32_T)_SFD_CCP_CALL(209U, 0,
            muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2,
                               0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_xg_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_yg_out = (CV_TRANSITION_EVAL(210U, (int32_T)_SFD_CCP_CALL(210U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_yg_out) {
              *c1_stateChanged = TRUE;
            }
          }
          break;

         case c1_IN_recover:
          CV_STATE_EVAL(112, 0, 4);
          c1_ah_out = (CV_TRANSITION_EVAL(203U, (int32_T)_SFD_CCP_CALL(203U, 0,
                         (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ah_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_bh_out = (CV_TRANSITION_EVAL(204U, (int32_T)_SFD_CCP_CALL(204U, 0,
              muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                                (10U, c1__s32_d_(chartInstance, *c1_d_j), 0, 3,
                                 2, 0)]) <= 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_bh_out) {
              *c1_stateChanged = TRUE;
            }
          }
          break;

         case c1_IN_run:
          CV_STATE_EVAL(112, 0, 5);
          c1_ch_out = (CV_TRANSITION_EVAL(220U, (int32_T)_SFD_CCP_CALL(220U, 0,
            muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_ch_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_dh_out = (CV_TRANSITION_EVAL(221U, (int32_T)_SFD_CCP_CALL(221U, 0,
              *c1_d_v >= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_dh_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_eh_out = (CV_TRANSITION_EVAL(214U, (int32_T)_SFD_CCP_CALL(214U,
                0, (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0, 3, 1, 0)]
                == 1.0 != 0U, *c1_sfEvent)) != 0);
              if (c1_eh_out) {
                *c1_stateChanged = TRUE;
              }
            }
          }
          break;

         case c1_IN_select:
          CV_STATE_EVAL(112, 0, 6);
          c1_fh_out = (CV_TRANSITION_EVAL(200U, (int32_T)_SFD_CCP_CALL(200U, 0, *
            c1_d_maxv > 20.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_fh_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_gh_out = (CV_TRANSITION_EVAL(201U, (int32_T)_SFD_CCP_CALL(201U, 0,
              *c1_d_maxv <= 20.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_gh_out) {
              *c1_stateChanged = TRUE;
            }
          }
          break;

         case c1_IN_stablerun:
          CV_STATE_EVAL(112, 0, 7);
          c1_hh_out = (CV_TRANSITION_EVAL(219U, (int32_T)_SFD_CCP_CALL(219U, 0,
            muDoubleScalarAbs(*c1_d_distance - (*c1_S)[_SFD_ARRAY_BOUNDS_CHECK
                              (10U, c1__s32_d_(chartInstance, *c1_d_j), 0, 3, 2,
                               0)]) <= 500.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_hh_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ih_out = (CV_TRANSITION_EVAL(215U, (int32_T)_SFD_CCP_CALL(215U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_ih_out) {
              *c1_stateChanged = TRUE;
            }
          }
          break;

         case c1_IN_stop:
          CV_STATE_EVAL(112, 0, 8);
          c1_jh_out = (CV_TRANSITION_EVAL(211U, (int32_T)_SFD_CCP_CALL(211U, 0,
                         (*c1_start)[_SFD_ARRAY_BOUNDS_CHECK(2U, *c1_i_i, 0, 3,
            1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_jh_out) {
            *c1_stateChanged = TRUE;
          }
          break;

         case c1_b_IN_tmp:
          CV_STATE_EVAL(112, 0, 9);
          c1_mb_temp = (_SFD_CCP_CALL(217U, 0, *c1_d_j == 0.0 != 0U, *c1_sfEvent)
                        != 0);
          if (c1_mb_temp) {
            c1_mb_temp = (_SFD_CCP_CALL(217U, 1, (*c1_dir)
              [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == -1 != 0U,
              *c1_sfEvent) != 0);
          }

          c1_kh_out = (CV_TRANSITION_EVAL(217U, (int32_T)c1_mb_temp) != 0);
          if (c1_kh_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_nb_temp = (_SFD_CCP_CALL(218U, 0, *c1_d_j == (real_T)
              c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent) != 0);
            if (c1_nb_temp) {
              c1_nb_temp = (_SFD_CCP_CALL(218U, 1, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
            }

            c1_lh_out = (CV_TRANSITION_EVAL(218U, (int32_T)c1_nb_temp) != 0);
            if (c1_lh_out) {
              *c1_stateChanged = TRUE;
            } else {
              c1_ob_temp = (_SFD_CCP_CALL(216U, 0, (*c1_dir)
                [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == 1 != 0U, *
                c1_sfEvent) != 0);
              if (c1_ob_temp) {
                c1_ob_temp = (_SFD_CCP_CALL(216U, 1, *c1_d_j < (real_T)
                  c1__s32_minus__(chartInstance, *c1_N, 1) != 0U, *c1_sfEvent)
                              != 0);
              }

              c1_pb_temp = c1_ob_temp;
              if (!c1_pb_temp) {
                c1_qb_temp = (_SFD_CCP_CALL(216U, 2, (*c1_dir)
                  [_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i_i, 0, 3, 1, 0)] == -1 !=
                  0U, *c1_sfEvent) != 0);
                if (c1_qb_temp) {
                  c1_qb_temp = (_SFD_CCP_CALL(216U, 3, *c1_d_j > 0.0 != 0U,
                    *c1_sfEvent) != 0);
                }

                c1_pb_temp = c1_qb_temp;
              }

              c1_mh_out = (CV_TRANSITION_EVAL(216U, (int32_T)c1_pb_temp) != 0);
              if (c1_mh_out) {
                *c1_stateChanged = TRUE;
              }
            }
          }
          break;

         case c1_IN_urgent_dec:
          CV_STATE_EVAL(112, 0, 10);
          c1_nh_out = (CV_TRANSITION_EVAL(207U, (int32_T)_SFD_CCP_CALL(207U, 0, *
            c1_d_v <= 0.1 != 0U, *c1_sfEvent)) != 0);
          if (c1_nh_out) {
            *c1_stateChanged = TRUE;
          }
          break;

         case c1_IN_urgent_inc:
          CV_STATE_EVAL(112, 0, 11);
          c1_oh_out = (CV_TRANSITION_EVAL(199U, (int32_T)_SFD_CCP_CALL(199U, 0, *
            c1_d_v >= *c1_d_maxv != 0U, *c1_sfEvent)) != 0);
          if (c1_oh_out) {
            *c1_stateChanged = TRUE;
          } else {
            c1_ph_out = (CV_TRANSITION_EVAL(205U, (int32_T)_SFD_CCP_CALL(205U, 0,
                           (*c1_urstop)[_SFD_ARRAY_BOUNDS_CHECK(12U, *c1_i_i, 0,
              3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
            if (c1_ph_out) {
              *c1_stateChanged = TRUE;
            }
          }
          break;

         case c1_IN_urgent_stop:
          CV_STATE_EVAL(112, 0, 12);
          c1_qh_out = (CV_TRANSITION_EVAL(202U, (int32_T)_SFD_CCP_CALL(202U, 0,
                         (*c1_urstart)[_SFD_ARRAY_BOUNDS_CHECK(11U, *c1_i_i, 0,
            3, 1, 0)] == 1.0 != 0U, *c1_sfEvent)) != 0);
          if (c1_qh_out) {
            *c1_stateChanged = TRUE;
          }
          break;

         default:
          CV_STATE_EVAL(112, 0, 0);
          *c1_is_Train2 = c1_IN_NO_ACTIVE_CHILD;
          break;
        }
      }
    }

    if (*c1_stateChanged) {
      *c1_zcVar = 1.0;
    } else {
      *c1_zcVar = -1.0;
    }
  }
}

static void derivatives_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  int32_T c1_i301;
  int32_T c1_i302;
  int32_T c1_i303;
  int32_T c1_i304;
  int32_T c1_i305;
  int32_T c1_i306;
  int32_T c1_i307;
  int32_T c1_i308;
  int32_T c1_i309;
  int32_T c1_i310;
  int32_T c1_i311;
  int32_T c1_i312;
  int32_T c1_i313;
  int32_T c1_i314;
  int32_T c1_i315;
  int32_T c1_i316;
  int32_T c1_i317;
  int32_T c1_i318;
  int32_T c1_i319;
  int32_T c1_i320;
  int32_T c1_i321;
  int32_T c1_i322;
  int32_T c1_i323;
  int32_T c1_i324;
  int32_T c1_i325;
  int32_T c1_i326;
  int32_T c1_i327;
  int32_T c1_i328;
  int32_T c1_i329;
  int32_T c1_i330;
  int32_T c1_i331;
  int32_T c1_i332;
  int32_T c1_i333;
  int32_T c1_i334;
  int32_T c1_i335;
  int32_T c1_i336;
  int32_T c1_i337;
  int32_T c1_i338;
  int32_T c1_i339;
  int32_T c1_i340;
  int32_T c1_i341;
  int32_T c1_i342;
  int32_T c1_i343;
  int32_T c1_i344;
  int32_T c1_i345;
  int32_T c1_i346;
  int32_T c1_i347;
  int32_T c1_i348;
  int32_T c1_i349;
  int32_T c1_i350;
  int32_T c1_i351;
  int32_T c1_i352;
  int32_T c1_i353;
  int32_T c1_i354;
  int32_T c1_i355;
  int32_T c1_i356;
  int32_T c1_i357;
  int32_T c1_i358;
  int32_T c1_i359;
  int32_T c1_i360;
  int32_T c1_i361;
  int32_T c1_i362;
  int32_T c1_i363;
  int32_T c1_i364;
  real_T *c1_t_dot;
  real_T *c1_z_dot;
  real_T *c1_v_dot;
  real_T *c1_time_dot;
  real_T *c1_distance_dot;
  real_T *c1_b_z_dot;
  real_T *c1_y1_dot;
  real_T *c1_b_y1_dot;
  real_T *c1_b_v_dot;
  real_T *c1_b_time_dot;
  real_T *c1_b_distance_dot;
  real_T *c1_c_z_dot;
  real_T *c1_d_z_dot;
  real_T *c1_c_v_dot;
  real_T *c1_c_time_dot;
  real_T *c1_c_distance_dot;
  real_T *c1_c_y1_dot;
  real_T *c1_d_v_dot;
  real_T *c1_d_time_dot;
  real_T *c1_d_distance_dot;
  real_T *c1_d_y1_dot;
  real_T *c1_y2_dot;
  real_T *c1_b_y2_dot;
  real_T *c1_c_y2_dot;
  real_T *c1_d_y2_dot;
  real_T *c1_e_y2_dot;
  real_T *c1_f_y2_dot;
  real_T *c1_g_y2_dot;
  real_T *c1_h_y2_dot;
  uint8_T *c1_is_Train0_door;
  uint8_T *c1_is_Screen_door00;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_Screen_door01;
  uint8_T *c1_is_Screen_door10;
  uint8_T *c1_is_Screen_door11;
  uint8_T *c1_is_Screen_door20;
  uint8_T *c1_is_Screen_door21;
  uint8_T *c1_is_Screen_door30;
  uint8_T *c1_is_Screen_door31;
  uint8_T *c1_is_Train1_door;
  uint8_T *c1_is_Train2_door;
  uint8_T *c1_is_Train3_door;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_Train3;
  real_T *c1_v;
  real_T *c1_acc;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_Train0;
  real_T *c1_b_v;
  real_T *c1_b_acc;
  uint8_T *c1_is_Train1;
  real_T *c1_c_v;
  real_T *c1_c_acc;
  uint8_T *c1_is_Train2;
  real_T *c1_d_v;
  real_T *c1_d_acc;
  int32_T *c1_i;
  int32_T *c1_b_i;
  int32_T *c1_c_i;
  int32_T *c1_d_i;
  real_T (*c1_y1_out)[4];
  real_T (*c1_v_shutTD)[4];
  real_T (*c1_y2_out)[8];
  real_T (*c1_v_shutPSD)[8];
  int32_T (*c1_dir)[4];
  real_T (*c1_distance_out)[4];
  int32_T *c1_sfEvent;
  c1_h_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 28);
  c1_g_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 27);
  c1_f_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 26);
  c1_e_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 25);
  c1_d_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 24);
  c1_c_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 23);
  c1_b_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 22);
  c1_y2_dot = (real_T *)(ssGetdX(chartInstance->S) + 21);
  c1_d_y1_dot = (real_T *)(ssGetdX(chartInstance->S) + 20);
  c1_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
  c1_d_distance_dot = (real_T *)(ssGetdX(chartInstance->S) + 19);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_d_time_dot = (real_T *)(ssGetdX(chartInstance->S) + 18);
  c1_d_v_dot = (real_T *)(ssGetdX(chartInstance->S) + 17);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1_dot = (real_T *)(ssGetdX(chartInstance->S) + 16);
  c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
  c1_c_distance_dot = (real_T *)(ssGetdX(chartInstance->S) + 15);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_c_time_dot = (real_T *)(ssGetdX(chartInstance->S) + 14);
  c1_c_v_dot = (real_T *)(ssGetdX(chartInstance->S) + 13);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_d_z_dot = (real_T *)(ssGetdX(chartInstance->S) + 12);
  c1_c_z_dot = (real_T *)(ssGetdX(chartInstance->S) + 11);
  c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
  c1_b_distance_dot = (real_T *)(ssGetdX(chartInstance->S) + 10);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_b_time_dot = (real_T *)(ssGetdX(chartInstance->S) + 9);
  c1_b_v_dot = (real_T *)(ssGetdX(chartInstance->S) + 8);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1_dot = (real_T *)(ssGetdX(chartInstance->S) + 7);
  c1_y1_dot = (real_T *)(ssGetdX(chartInstance->S) + 6);
  c1_b_z_dot = (real_T *)(ssGetdX(chartInstance->S) + 5);
  c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
  c1_distance_dot = (real_T *)(ssGetdX(chartInstance->S) + 4);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_time_dot = (real_T *)(ssGetdX(chartInstance->S) + 3);
  c1_v_dot = (real_T *)(ssGetdX(chartInstance->S) + 2);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_z_dot = (real_T *)(ssGetdX(chartInstance->S) + 1);
  c1_t_dot = (real_T *)(ssGetdX(chartInstance->S) + 0);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_v_shutPSD = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
  c1_v_shutTD = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_t_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_t_dot, 20U);
  *c1_z_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
  *c1_v_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
  *c1_time_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_time_dot, 33U);
  *c1_distance_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
  *c1_b_z_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
  *c1_y1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_y1_dot, 41U);
  *c1_b_y1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_y1_dot, 42U);
  *c1_b_v_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
  *c1_b_time_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_time_dot, 46U);
  *c1_b_distance_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
  *c1_c_z_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
  *c1_d_z_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
  *c1_c_v_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
  *c1_c_time_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_time_dot, 61U);
  *c1_c_distance_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
  *c1_c_y1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_y1_dot, 65U);
  *c1_d_v_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
  *c1_d_time_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_time_dot, 69U);
  *c1_d_distance_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
  *c1_d_y1_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_y1_dot, 73U);
  *c1_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_y2_dot, 74U);
  *c1_b_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_b_y2_dot, 75U);
  *c1_c_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_c_y2_dot, 76U);
  *c1_d_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_d_y2_dot, 77U);
  *c1_e_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_e_y2_dot, 78U);
  *c1_f_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_f_y2_dot, 79U);
  *c1_g_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_g_y2_dot, 80U);
  *c1_h_y2_dot = 0.0;
  _SFD_DATA_RANGE_CHECK(*c1_h_y2_dot, 81U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 89U, *c1_sfEvent);
  switch (*c1_is_Train0_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(89, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 90U, *c1_sfEvent);
    *c1_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_y1_dot, 41U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 90U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(89, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 91U, *c1_sfEvent);
    *c1_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_y1_dot, 41U);
    for (c1_i301 = 0; c1_i301 < 4; c1_i301++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i301], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 91U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(89, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 92U, *c1_sfEvent);
    *c1_y1_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_y1_dot, 41U);
    for (c1_i302 = 0; c1_i302 < 4; c1_i302++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i302], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 92U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(89, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 93U, *c1_sfEvent);
    *c1_y1_dot = (*c1_v_shutTD)[0];
    _SFD_DATA_RANGE_CHECK(*c1_y1_dot, 41U);
    for (c1_i303 = 0; c1_i303 < 4; c1_i303++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i303], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 93U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(89, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 89U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U, *c1_sfEvent);
  switch (*c1_is_Screen_door00) {
   case c1_IN_closed:
    CV_STATE_EVAL(36, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, *c1_sfEvent);
    *c1_d_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y2_dot, 77U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(36, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U, *c1_sfEvent);
    *c1_d_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y2_dot, 77U);
    for (c1_i304 = 0; c1_i304 < 8; c1_i304++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i304], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(36, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, *c1_sfEvent);
    *c1_d_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y2_dot, 77U);
    for (c1_i305 = 0; c1_i305 < 8; c1_i305++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i305], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(36, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, *c1_sfEvent);
    *c1_d_y2_dot = (*c1_v_shutPSD)[0];
    _SFD_DATA_RANGE_CHECK(*c1_d_y2_dot, 77U);
    for (c1_i306 = 0; c1_i306 < 8; c1_i306++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i306], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(36, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  switch (*c1_is_Controller0) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(0, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, *c1_sfEvent);
    *c1_b_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_z_dot, 37U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, *c1_sfEvent);
  switch (*c1_is_Screen_door01) {
   case c1_IN_closed:
    CV_STATE_EVAL(41, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, *c1_sfEvent);
    *c1_c_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y2_dot, 76U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(41, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, *c1_sfEvent);
    *c1_c_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y2_dot, 76U);
    for (c1_i307 = 0; c1_i307 < 8; c1_i307++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i307], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(41, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U, *c1_sfEvent);
    *c1_c_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y2_dot, 76U);
    for (c1_i308 = 0; c1_i308 < 8; c1_i308++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i308], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(41, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, *c1_sfEvent);
    *c1_c_y2_dot = (*c1_v_shutPSD)[4];
    _SFD_DATA_RANGE_CHECK(*c1_c_y2_dot, 76U);
    for (c1_i309 = 0; c1_i309 < 8; c1_i309++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i309], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(41, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U, *c1_sfEvent);
  switch (*c1_is_Screen_door10) {
   case c1_IN_closed:
    CV_STATE_EVAL(46, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, *c1_sfEvent);
    *c1_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_y2_dot, 74U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(46, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U, *c1_sfEvent);
    *c1_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_y2_dot, 74U);
    for (c1_i310 = 0; c1_i310 < 8; c1_i310++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i310], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(46, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, *c1_sfEvent);
    *c1_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_y2_dot, 74U);
    for (c1_i311 = 0; c1_i311 < 8; c1_i311++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i311], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(46, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U, *c1_sfEvent);
    *c1_y2_dot = (*c1_v_shutPSD)[1];
    _SFD_DATA_RANGE_CHECK(*c1_y2_dot, 74U);
    for (c1_i312 = 0; c1_i312 < 8; c1_i312++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i312], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(46, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U, *c1_sfEvent);
  switch (*c1_is_Screen_door11) {
   case c1_IN_closed:
    CV_STATE_EVAL(51, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U, *c1_sfEvent);
    *c1_b_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y2_dot, 75U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(51, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, *c1_sfEvent);
    *c1_b_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y2_dot, 75U);
    for (c1_i313 = 0; c1_i313 < 8; c1_i313++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i313], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(51, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U, *c1_sfEvent);
    *c1_b_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y2_dot, 75U);
    for (c1_i314 = 0; c1_i314 < 8; c1_i314++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i314], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(51, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U, *c1_sfEvent);
    *c1_b_y2_dot = (*c1_v_shutPSD)[5];
    _SFD_DATA_RANGE_CHECK(*c1_b_y2_dot, 75U);
    for (c1_i315 = 0; c1_i315 < 8; c1_i315++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i315], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(51, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U, *c1_sfEvent);
  switch (*c1_is_Screen_door20) {
   case c1_IN_closed:
    CV_STATE_EVAL(56, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, *c1_sfEvent);
    *c1_h_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_h_y2_dot, 81U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(56, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U, *c1_sfEvent);
    *c1_h_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_h_y2_dot, 81U);
    for (c1_i316 = 0; c1_i316 < 8; c1_i316++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i316], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(56, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U, *c1_sfEvent);
    *c1_h_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_h_y2_dot, 81U);
    for (c1_i317 = 0; c1_i317 < 8; c1_i317++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i317], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(56, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U, *c1_sfEvent);
    *c1_h_y2_dot = (*c1_v_shutPSD)[2];
    _SFD_DATA_RANGE_CHECK(*c1_h_y2_dot, 81U);
    for (c1_i318 = 0; c1_i318 < 8; c1_i318++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i318], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(56, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, *c1_sfEvent);
  switch (*c1_is_Screen_door21) {
   case c1_IN_closed:
    CV_STATE_EVAL(61, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U, *c1_sfEvent);
    *c1_g_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_g_y2_dot, 80U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(61, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U, *c1_sfEvent);
    *c1_g_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_g_y2_dot, 80U);
    for (c1_i319 = 0; c1_i319 < 8; c1_i319++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i319], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(61, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U, *c1_sfEvent);
    *c1_g_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_g_y2_dot, 80U);
    for (c1_i320 = 0; c1_i320 < 8; c1_i320++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i320], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(61, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U, *c1_sfEvent);
    *c1_g_y2_dot = (*c1_v_shutPSD)[6];
    _SFD_DATA_RANGE_CHECK(*c1_g_y2_dot, 80U);
    for (c1_i321 = 0; c1_i321 < 8; c1_i321++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i321], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(61, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U, *c1_sfEvent);
  switch (*c1_is_Screen_door30) {
   case c1_IN_closed:
    CV_STATE_EVAL(66, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U, *c1_sfEvent);
    *c1_e_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_e_y2_dot, 78U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(66, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U, *c1_sfEvent);
    *c1_e_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_e_y2_dot, 78U);
    for (c1_i322 = 0; c1_i322 < 8; c1_i322++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i322], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(66, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, *c1_sfEvent);
    *c1_e_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_e_y2_dot, 78U);
    for (c1_i323 = 0; c1_i323 < 8; c1_i323++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i323], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(66, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 70U, *c1_sfEvent);
    *c1_e_y2_dot = (*c1_v_shutPSD)[3];
    _SFD_DATA_RANGE_CHECK(*c1_e_y2_dot, 78U);
    for (c1_i324 = 0; c1_i324 < 8; c1_i324++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i324], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(66, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U, *c1_sfEvent);
  switch (*c1_is_Screen_door31) {
   case c1_IN_closed:
    CV_STATE_EVAL(71, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U, *c1_sfEvent);
    *c1_f_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_f_y2_dot, 79U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(71, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U, *c1_sfEvent);
    *c1_f_y2_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_f_y2_dot, 79U);
    for (c1_i325 = 0; c1_i325 < 8; c1_i325++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i325], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(71, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 74U, *c1_sfEvent);
    *c1_f_y2_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_f_y2_dot, 79U);
    for (c1_i326 = 0; c1_i326 < 8; c1_i326++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i326], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(71, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 75U, *c1_sfEvent);
    *c1_f_y2_dot = (*c1_v_shutPSD)[7];
    _SFD_DATA_RANGE_CHECK(*c1_f_y2_dot, 79U);
    for (c1_i327 = 0; c1_i327 < 8; c1_i327++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i327], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 75U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(71, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 107U, *c1_sfEvent);
  switch (*c1_is_Train1_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(107, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 108U, *c1_sfEvent);
    *c1_b_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y1_dot, 42U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 108U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(107, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 109U, *c1_sfEvent);
    *c1_b_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y1_dot, 42U);
    for (c1_i328 = 0; c1_i328 < 4; c1_i328++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i328], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 109U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(107, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 110U, *c1_sfEvent);
    *c1_b_y1_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_y1_dot, 42U);
    for (c1_i329 = 0; c1_i329 < 4; c1_i329++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i329], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 110U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(107, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 111U, *c1_sfEvent);
    *c1_b_y1_dot = (*c1_v_shutTD)[1];
    _SFD_DATA_RANGE_CHECK(*c1_b_y1_dot, 42U);
    for (c1_i330 = 0; c1_i330 < 4; c1_i330++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i330], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 111U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(107, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 107U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 125U, *c1_sfEvent);
  switch (*c1_is_Train2_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(125, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 126U, *c1_sfEvent);
    *c1_c_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y1_dot, 65U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 126U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(125, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 127U, *c1_sfEvent);
    *c1_c_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y1_dot, 65U);
    for (c1_i331 = 0; c1_i331 < 4; c1_i331++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i331], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 127U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(125, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 128U, *c1_sfEvent);
    *c1_c_y1_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_y1_dot, 65U);
    for (c1_i332 = 0; c1_i332 < 4; c1_i332++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i332], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 128U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(125, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 129U, *c1_sfEvent);
    *c1_c_y1_dot = (*c1_v_shutTD)[2];
    _SFD_DATA_RANGE_CHECK(*c1_c_y1_dot, 65U);
    for (c1_i333 = 0; c1_i333 < 4; c1_i333++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i333], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 129U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(125, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 125U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 143U, *c1_sfEvent);
  switch (*c1_is_Train3_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(143, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 144U, *c1_sfEvent);
    *c1_d_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y1_dot, 73U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 144U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(143, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 145U, *c1_sfEvent);
    *c1_d_y1_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y1_dot, 73U);
    for (c1_i334 = 0; c1_i334 < 4; c1_i334++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i334], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 145U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(143, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 146U, *c1_sfEvent);
    *c1_d_y1_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_y1_dot, 73U);
    for (c1_i335 = 0; c1_i335 < 4; c1_i335++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i335], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 146U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(143, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 147U, *c1_sfEvent);
    *c1_d_y1_dot = (*c1_v_shutTD)[3];
    _SFD_DATA_RANGE_CHECK(*c1_d_y1_dot, 73U);
    for (c1_i336 = 0; c1_i336 < 4; c1_i336++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i336], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 147U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(143, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 143U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 148U, *c1_sfEvent);
  switch (*c1_is_UrgentController) {
   case c1_IN_D1:
    CV_STATE_EVAL(148, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 150U, *c1_sfEvent);
    *c1_t_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_t_dot, 20U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 150U, *c1_sfEvent);
    break;

   case c1_IN_Delay:
    CV_STATE_EVAL(148, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 151U, *c1_sfEvent);
    *c1_t_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_t_dot, 20U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 151U, *c1_sfEvent);
    break;

   case c1_IN_tmp:
    CV_STATE_EVAL(148, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 153U, *c1_sfEvent);
    *c1_t_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_t_dot, 20U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 153U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(148, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 148U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 130U, *c1_sfEvent);
  switch (*c1_is_Train3) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(130, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 131U, *c1_sfEvent);
    *c1_d_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_time_dot, 69U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 131U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(130, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 132U, *c1_sfEvent);
    *c1_d_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_time_dot, 69U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 132U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(130, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 133U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = *c1_acc;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i337 = 0; c1_i337 < 4; c1_i337++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i337], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 133U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(130, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 134U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = -0.5;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i338 = 0; c1_i338 < 4; c1_i338++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i338], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 134U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(130, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 135U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i339 = 0; c1_i339 < 4; c1_i339++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i339], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 135U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(130, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 136U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 136U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(130, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 137U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i340 = 0; c1_i340 < 4; c1_i340++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i340], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 137U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(130, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 138U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 138U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(130, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 139U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 139U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(130, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 140U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = -1.5;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i341 = 0; c1_i341 < 4; c1_i341++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i341], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 140U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(130, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 141U, *c1_sfEvent);
    *c1_d_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_i, 0,
      3, 1, 0)] * *c1_v;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i342 = 0; c1_i342 < 4; c1_i342++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i342], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 141U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(130, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 142U, *c1_sfEvent);
    *c1_d_distance_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_distance_dot, 71U);
    *c1_d_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_v_dot, 66U);
    for (c1_i343 = 0; c1_i343 < 4; c1_i343++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i343], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 142U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(130, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 130U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, *c1_sfEvent);
  switch (*c1_is_Controller1) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(9, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(9, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, *c1_sfEvent);
    *c1_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_z_dot, 26U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, *c1_sfEvent);
  switch (*c1_is_Controller2) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(18, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(18, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(18, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(18, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(18, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(18, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(18, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(18, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, *c1_sfEvent);
    *c1_d_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_d_z_dot, 54U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(18, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, *c1_sfEvent);
  switch (*c1_is_Controller3) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(27, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(27, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(27, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(27, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(27, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(27, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(27, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(27, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, *c1_sfEvent);
    *c1_c_z_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_z_dot, 50U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 76U, *c1_sfEvent);
  switch (*c1_is_Train0) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(76, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 77U, *c1_sfEvent);
    *c1_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_time_dot, 33U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 77U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(76, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 78U, *c1_sfEvent);
    *c1_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_time_dot, 33U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 78U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(76, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 79U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = *c1_b_acc;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i344 = 0; c1_i344 < 4; c1_i344++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i344], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 79U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(76, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 80U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = -0.5;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i345 = 0; c1_i345 < 4; c1_i345++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i345], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 80U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(76, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 81U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i346 = 0; c1_i346 < 4; c1_i346++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i346], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 81U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(76, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 82U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 82U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(76, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 83U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i347 = 0; c1_i347 < 4; c1_i347++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i347], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 83U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(76, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 84U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 84U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(76, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 85U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(76, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 86U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = -1.5;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i348 = 0; c1_i348 < 4; c1_i348++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i348], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 86U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(76, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 87U, *c1_sfEvent);
    *c1_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_b_i, 0,
      3, 1, 0)] * *c1_b_v;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i349 = 0; c1_i349 < 4; c1_i349++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i349], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 87U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(76, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 88U, *c1_sfEvent);
    *c1_distance_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_distance_dot, 35U);
    *c1_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_v_dot, 30U);
    for (c1_i350 = 0; c1_i350 < 4; c1_i350++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i350], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(76, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 76U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 94U, *c1_sfEvent);
  switch (*c1_is_Train1) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(94, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 95U, *c1_sfEvent);
    *c1_b_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_time_dot, 46U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 95U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(94, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 96U, *c1_sfEvent);
    *c1_b_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_time_dot, 46U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 96U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(94, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 97U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = *c1_c_acc;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i351 = 0; c1_i351 < 4; c1_i351++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i351], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 97U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(94, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 98U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = -0.5;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i352 = 0; c1_i352 < 4; c1_i352++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i352], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 98U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(94, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 99U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i353 = 0; c1_i353 < 4; c1_i353++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i353], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(94, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 100U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 100U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(94, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 101U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i354 = 0; c1_i354 < 4; c1_i354++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i354], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 101U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(94, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 102U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 102U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(94, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 103U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 103U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(94, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 104U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = -1.5;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i355 = 0; c1_i355 < 4; c1_i355++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i355], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 104U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(94, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 105U, *c1_sfEvent);
    *c1_b_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_c_i,
      0, 3, 1, 0)] * *c1_c_v;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i356 = 0; c1_i356 < 4; c1_i356++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i356], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 105U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(94, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 106U, *c1_sfEvent);
    *c1_b_distance_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_distance_dot, 48U);
    *c1_b_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_b_v_dot, 43U);
    for (c1_i357 = 0; c1_i357 < 4; c1_i357++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i357], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(94, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 94U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 112U, *c1_sfEvent);
  switch (*c1_is_Train2) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(112, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 113U, *c1_sfEvent);
    *c1_c_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_time_dot, 61U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 113U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(112, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 114U, *c1_sfEvent);
    *c1_c_time_dot = 1.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_time_dot, 61U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 114U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(112, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 115U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = *c1_d_acc;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i358 = 0; c1_i358 < 4; c1_i358++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i358], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 115U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(112, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 116U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = -0.5;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i359 = 0; c1_i359 < 4; c1_i359++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i359], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 116U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(112, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 117U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i360 = 0; c1_i360 < 4; c1_i360++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i360], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 117U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(112, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 118U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 118U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(112, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 119U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i361 = 0; c1_i361 < 4; c1_i361++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i361], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 119U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(112, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 120U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 120U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(112, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 121U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 121U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(112, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 122U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = -1.5;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i362 = 0; c1_i362 < 4; c1_i362++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i362], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 122U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(112, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 123U, *c1_sfEvent);
    *c1_c_distance_dot = (real_T)(*c1_dir)[_SFD_ARRAY_BOUNDS_CHECK(17U, *c1_d_i,
      0, 3, 1, 0)] * *c1_d_v;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = 0.5;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i363 = 0; c1_i363 < 4; c1_i363++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i363], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 123U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(112, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 124U, *c1_sfEvent);
    *c1_c_distance_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_distance_dot, 63U);
    *c1_c_v_dot = 0.0;
    _SFD_DATA_RANGE_CHECK(*c1_c_v_dot, 58U);
    for (c1_i364 = 0; c1_i364 < 4; c1_i364++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i364], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(112, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 112U, *c1_sfEvent);
}

static void outputs_c1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  int32_T c1_i365;
  int32_T c1_i366;
  int32_T c1_i367;
  int32_T c1_i368;
  int32_T c1_i369;
  int32_T c1_i370;
  int32_T c1_i371;
  int32_T c1_i372;
  int32_T c1_i373;
  int32_T c1_i374;
  int32_T c1_i375;
  int32_T c1_i376;
  int32_T c1_i377;
  int32_T c1_i378;
  int32_T c1_i379;
  int32_T c1_i380;
  int32_T c1_i381;
  int32_T c1_i382;
  int32_T c1_i383;
  int32_T c1_i384;
  int32_T c1_i385;
  int32_T c1_i386;
  int32_T c1_i387;
  int32_T c1_i388;
  int32_T c1_i389;
  int32_T c1_i390;
  int32_T c1_i391;
  int32_T c1_i392;
  int32_T c1_i393;
  int32_T c1_i394;
  int32_T c1_i395;
  int32_T c1_i396;
  int32_T c1_i397;
  int32_T c1_i398;
  int32_T c1_i399;
  int32_T c1_i400;
  int32_T c1_i401;
  int32_T c1_i402;
  int32_T c1_i403;
  int32_T c1_i404;
  int32_T c1_i405;
  int32_T c1_i406;
  int32_T c1_i407;
  int32_T c1_i408;
  int32_T c1_i409;
  int32_T c1_i410;
  int32_T c1_i411;
  int32_T c1_i412;
  int32_T c1_i413;
  int32_T c1_i414;
  int32_T c1_i415;
  int32_T c1_i416;
  int32_T c1_i417;
  int32_T c1_i418;
  int32_T c1_i419;
  int32_T c1_i420;
  int32_T c1_i421;
  int32_T c1_i422;
  int32_T c1_i423;
  int32_T c1_i424;
  int32_T c1_i425;
  int32_T c1_i426;
  int32_T c1_i427;
  int32_T c1_i428;
  uint8_T *c1_is_Train0_door;
  real_T *c1_y1;
  uint8_T *c1_is_Screen_door00;
  real_T *c1_y2;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_Screen_door01;
  real_T *c1_b_y2;
  uint8_T *c1_is_Screen_door10;
  real_T *c1_c_y2;
  uint8_T *c1_is_Screen_door11;
  real_T *c1_d_y2;
  uint8_T *c1_is_Screen_door20;
  real_T *c1_e_y2;
  uint8_T *c1_is_Screen_door21;
  real_T *c1_f_y2;
  uint8_T *c1_is_Screen_door30;
  real_T *c1_g_y2;
  uint8_T *c1_is_Screen_door31;
  real_T *c1_h_y2;
  uint8_T *c1_is_Train1_door;
  real_T *c1_b_y1;
  uint8_T *c1_is_Train2_door;
  real_T *c1_c_y1;
  uint8_T *c1_is_Train3_door;
  real_T *c1_d_y1;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_Train3;
  int32_T *c1_i;
  real_T *c1_distance;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_Train0;
  int32_T *c1_b_i;
  real_T *c1_b_distance;
  uint8_T *c1_is_Train1;
  int32_T *c1_c_i;
  real_T *c1_c_distance;
  uint8_T *c1_is_Train2;
  int32_T *c1_d_i;
  real_T *c1_d_distance;
  real_T (*c1_y1_out)[4];
  real_T (*c1_y2_out)[8];
  real_T (*c1_distance_out)[4];
  int32_T *c1_sfEvent;
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 89U, *c1_sfEvent);
  switch (*c1_is_Train0_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(89, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 90U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 90U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(89, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 91U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i365 = 0; c1_i365 < 4; c1_i365++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i365], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 91U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(89, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 92U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i366 = 0; c1_i366 < 4; c1_i366++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i366], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 92U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(89, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 93U, *c1_sfEvent);
    (*c1_y1_out)[0] = *c1_y1;
    for (c1_i367 = 0; c1_i367 < 4; c1_i367++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i367], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 93U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(89, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 89U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U, *c1_sfEvent);
  switch (*c1_is_Screen_door00) {
   case c1_IN_closed:
    CV_STATE_EVAL(36, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(36, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 38U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i368 = 0; c1_i368 < 8; c1_i368++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i368], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(36, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i369 = 0; c1_i369 < 8; c1_i369++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i369], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(36, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U, *c1_sfEvent);
    (*c1_y2_out)[0] = *c1_y2;
    for (c1_i370 = 0; c1_i370 < 8; c1_i370++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i370], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(36, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  switch (*c1_is_Controller0) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(0, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(0, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(0, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(0, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, *c1_sfEvent);
  switch (*c1_is_Screen_door01) {
   case c1_IN_closed:
    CV_STATE_EVAL(41, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 42U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(41, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i371 = 0; c1_i371 < 8; c1_i371++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i371], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(41, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i372 = 0; c1_i372 < 8; c1_i372++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i372], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(41, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, *c1_sfEvent);
    (*c1_y2_out)[4] = *c1_b_y2;
    for (c1_i373 = 0; c1_i373 < 8; c1_i373++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i373], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(41, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 46U, *c1_sfEvent);
  switch (*c1_is_Screen_door10) {
   case c1_IN_closed:
    CV_STATE_EVAL(46, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(46, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i374 = 0; c1_i374 < 8; c1_i374++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i374], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(46, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i375 = 0; c1_i375 < 8; c1_i375++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i375], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(46, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 50U, *c1_sfEvent);
    (*c1_y2_out)[1] = *c1_c_y2;
    for (c1_i376 = 0; c1_i376 < 8; c1_i376++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i376], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(46, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U, *c1_sfEvent);
  switch (*c1_is_Screen_door11) {
   case c1_IN_closed:
    CV_STATE_EVAL(51, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(51, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i377 = 0; c1_i377 < 8; c1_i377++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i377], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(51, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 54U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i378 = 0; c1_i378 < 8; c1_i378++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i378], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(51, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U, *c1_sfEvent);
    (*c1_y2_out)[5] = *c1_d_y2;
    for (c1_i379 = 0; c1_i379 < 8; c1_i379++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i379], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(51, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U, *c1_sfEvent);
  switch (*c1_is_Screen_door20) {
   case c1_IN_closed:
    CV_STATE_EVAL(56, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(56, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 58U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i380 = 0; c1_i380 < 8; c1_i380++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i380], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(56, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i381 = 0; c1_i381 < 8; c1_i381++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i381], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(56, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U, *c1_sfEvent);
    (*c1_y2_out)[2] = *c1_e_y2;
    for (c1_i382 = 0; c1_i382 < 8; c1_i382++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i382], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(56, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, *c1_sfEvent);
  switch (*c1_is_Screen_door21) {
   case c1_IN_closed:
    CV_STATE_EVAL(61, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 62U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(61, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i383 = 0; c1_i383 < 8; c1_i383++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i383], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(61, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i384 = 0; c1_i384 < 8; c1_i384++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i384], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(61, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U, *c1_sfEvent);
    (*c1_y2_out)[6] = *c1_f_y2;
    for (c1_i385 = 0; c1_i385 < 8; c1_i385++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i385], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(61, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 66U, *c1_sfEvent);
  switch (*c1_is_Screen_door30) {
   case c1_IN_closed:
    CV_STATE_EVAL(66, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(66, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i386 = 0; c1_i386 < 8; c1_i386++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i386], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(66, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i387 = 0; c1_i387 < 8; c1_i387++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i387], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(66, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 70U, *c1_sfEvent);
    (*c1_y2_out)[3] = *c1_g_y2;
    for (c1_i388 = 0; c1_i388 < 8; c1_i388++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i388], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(66, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U, *c1_sfEvent);
  switch (*c1_is_Screen_door31) {
   case c1_IN_closed:
    CV_STATE_EVAL(71, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(71, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i389 = 0; c1_i389 < 8; c1_i389++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i389], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(71, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 74U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i390 = 0; c1_i390 < 8; c1_i390++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i390], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(71, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 75U, *c1_sfEvent);
    (*c1_y2_out)[7] = *c1_h_y2;
    for (c1_i391 = 0; c1_i391 < 8; c1_i391++) {
      _SFD_DATA_RANGE_CHECK((*c1_y2_out)[c1_i391], 15U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 75U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(71, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 107U, *c1_sfEvent);
  switch (*c1_is_Train1_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(107, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 108U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 108U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(107, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 109U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i392 = 0; c1_i392 < 4; c1_i392++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i392], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 109U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(107, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 110U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i393 = 0; c1_i393 < 4; c1_i393++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i393], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 110U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(107, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 111U, *c1_sfEvent);
    (*c1_y1_out)[1] = *c1_b_y1;
    for (c1_i394 = 0; c1_i394 < 4; c1_i394++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i394], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 111U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(107, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 107U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 125U, *c1_sfEvent);
  switch (*c1_is_Train2_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(125, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 126U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 126U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(125, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 127U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i395 = 0; c1_i395 < 4; c1_i395++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i395], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 127U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(125, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 128U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i396 = 0; c1_i396 < 4; c1_i396++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i396], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 128U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(125, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 129U, *c1_sfEvent);
    (*c1_y1_out)[2] = *c1_c_y1;
    for (c1_i397 = 0; c1_i397 < 4; c1_i397++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i397], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 129U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(125, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 125U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 143U, *c1_sfEvent);
  switch (*c1_is_Train3_door) {
   case c1_IN_closed:
    CV_STATE_EVAL(143, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 144U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 144U, *c1_sfEvent);
    break;

   case c1_IN_open:
    CV_STATE_EVAL(143, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 145U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i398 = 0; c1_i398 < 4; c1_i398++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i398], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 145U, *c1_sfEvent);
    break;

   case c1_IN_part:
    CV_STATE_EVAL(143, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 146U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i399 = 0; c1_i399 < 4; c1_i399++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i399], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 146U, *c1_sfEvent);
    break;

   case c1_IN_shut:
    CV_STATE_EVAL(143, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 147U, *c1_sfEvent);
    (*c1_y1_out)[3] = *c1_d_y1;
    for (c1_i400 = 0; c1_i400 < 4; c1_i400++) {
      _SFD_DATA_RANGE_CHECK((*c1_y1_out)[c1_i400], 14U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 147U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(143, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 143U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 148U, *c1_sfEvent);
  switch (*c1_is_UrgentController) {
   case c1_IN_D1:
    CV_STATE_EVAL(148, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 150U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 150U, *c1_sfEvent);
    break;

   case c1_IN_Delay:
    CV_STATE_EVAL(148, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 151U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 151U, *c1_sfEvent);
    break;

   case c1_IN_tmp:
    CV_STATE_EVAL(148, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 153U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 153U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(148, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 148U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 130U, *c1_sfEvent);
  switch (*c1_is_Train3) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(130, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 131U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 131U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(130, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 132U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 132U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(130, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 133U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i401 = 0; c1_i401 < 4; c1_i401++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i401], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 133U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(130, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 134U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i402 = 0; c1_i402 < 4; c1_i402++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i402], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 134U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(130, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 135U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i403 = 0; c1_i403 < 4; c1_i403++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i403], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 135U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(130, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 136U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 136U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(130, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 137U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i404 = 0; c1_i404 < 4; c1_i404++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i404], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 137U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(130, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 138U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 138U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(130, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 139U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 139U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(130, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 140U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i405 = 0; c1_i405 < 4; c1_i405++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i405], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 140U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(130, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 141U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i406 = 0; c1_i406 < 4; c1_i406++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i406], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 141U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(130, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 142U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_i, 0, 3, 1, 0)] =
      *c1_distance;
    for (c1_i407 = 0; c1_i407 < 4; c1_i407++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i407], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 142U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(130, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 130U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U, *c1_sfEvent);
  switch (*c1_is_Controller1) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(9, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(9, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(9, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(9, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(9, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(9, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(9, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(9, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(9, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U, *c1_sfEvent);
  switch (*c1_is_Controller2) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(18, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(18, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(18, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(18, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(18, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(18, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(18, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(18, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(18, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U, *c1_sfEvent);
  switch (*c1_is_Controller3) {
   case c1_IN_about_to_close1:
    CV_STATE_EVAL(27, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *c1_sfEvent);
    break;

   case c1_IN_about_to_close2:
    CV_STATE_EVAL(27, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open1:
    CV_STATE_EVAL(27, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *c1_sfEvent);
    break;

   case c1_IN_about_to_open2:
    CV_STATE_EVAL(27, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, *c1_sfEvent);
    break;

   case c1_IN_idle:
    CV_STATE_EVAL(27, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *c1_sfEvent);
    break;

   case c1_IN_open1:
    CV_STATE_EVAL(27, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *c1_sfEvent);
    break;

   case c1_IN_ring:
    CV_STATE_EVAL(27, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 34U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *c1_sfEvent);
    break;

   case c1_IN_start:
    CV_STATE_EVAL(27, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(27, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 76U, *c1_sfEvent);
  switch (*c1_is_Train0) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(76, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 77U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 77U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(76, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 78U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 78U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(76, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 79U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i408 = 0; c1_i408 < 4; c1_i408++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i408], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 79U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(76, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 80U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i409 = 0; c1_i409 < 4; c1_i409++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i409], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 80U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(76, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 81U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i410 = 0; c1_i410 < 4; c1_i410++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i410], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 81U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(76, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 82U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 82U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(76, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 83U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i411 = 0; c1_i411 < 4; c1_i411++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i411], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 83U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(76, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 84U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 84U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(76, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 85U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(76, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 86U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i412 = 0; c1_i412 < 4; c1_i412++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i412], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 86U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(76, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 87U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i413 = 0; c1_i413 < 4; c1_i413++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i413], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 87U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(76, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 88U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_b_i, 0, 3, 1, 0)] =
      *c1_b_distance;
    for (c1_i414 = 0; c1_i414 < 4; c1_i414++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i414], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(76, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 76U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 94U, *c1_sfEvent);
  switch (*c1_is_Train1) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(94, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 95U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 95U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(94, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 96U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 96U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(94, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 97U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i415 = 0; c1_i415 < 4; c1_i415++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i415], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 97U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(94, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 98U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i416 = 0; c1_i416 < 4; c1_i416++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i416], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 98U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(94, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 99U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i417 = 0; c1_i417 < 4; c1_i417++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i417], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(94, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 100U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 100U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(94, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 101U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i418 = 0; c1_i418 < 4; c1_i418++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i418], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 101U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(94, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 102U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 102U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(94, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 103U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 103U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(94, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 104U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i419 = 0; c1_i419 < 4; c1_i419++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i419], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 104U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(94, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 105U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i420 = 0; c1_i420 < 4; c1_i420++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i420], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 105U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(94, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 106U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_c_i, 0, 3, 1, 0)] =
      *c1_c_distance;
    for (c1_i421 = 0; c1_i421 < 4; c1_i421++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i421], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(94, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 94U, *c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 112U, *c1_sfEvent);
  switch (*c1_is_Train2) {
   case c1_IN_ChangeDirection:
    CV_STATE_EVAL(112, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 113U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 113U, *c1_sfEvent);
    break;

   case c1_IN_init:
    CV_STATE_EVAL(112, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 114U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 114U, *c1_sfEvent);
    break;

   case c1_IN_near:
    CV_STATE_EVAL(112, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 115U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i422 = 0; c1_i422 < 4; c1_i422++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i422], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 115U, *c1_sfEvent);
    break;

   case c1_IN_recover:
    CV_STATE_EVAL(112, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 116U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i423 = 0; c1_i423 < 4; c1_i423++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i423], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 116U, *c1_sfEvent);
    break;

   case c1_IN_run:
    CV_STATE_EVAL(112, 0, 5);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 117U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i424 = 0; c1_i424 < 4; c1_i424++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i424], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 117U, *c1_sfEvent);
    break;

   case c1_IN_select:
    CV_STATE_EVAL(112, 0, 6);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 118U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 118U, *c1_sfEvent);
    break;

   case c1_IN_stablerun:
    CV_STATE_EVAL(112, 0, 7);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 119U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i425 = 0; c1_i425 < 4; c1_i425++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i425], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 119U, *c1_sfEvent);
    break;

   case c1_IN_stop:
    CV_STATE_EVAL(112, 0, 8);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 120U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 120U, *c1_sfEvent);
    break;

   case c1_b_IN_tmp:
    CV_STATE_EVAL(112, 0, 9);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 121U, *c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 121U, *c1_sfEvent);
    break;

   case c1_IN_urgent_dec:
    CV_STATE_EVAL(112, 0, 10);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 122U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i426 = 0; c1_i426 < 4; c1_i426++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i426], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 122U, *c1_sfEvent);
    break;

   case c1_IN_urgent_inc:
    CV_STATE_EVAL(112, 0, 11);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 123U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i427 = 0; c1_i427 < 4; c1_i427++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i427], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 123U, *c1_sfEvent);
    break;

   case c1_IN_urgent_stop:
    CV_STATE_EVAL(112, 0, 12);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 124U, *c1_sfEvent);
    (*c1_distance_out)[_SFD_ARRAY_BOUNDS_CHECK(6U, *c1_d_i, 0, 3, 1, 0)] =
      *c1_d_distance;
    for (c1_i428 = 0; c1_i428 < 4; c1_i428++) {
      _SFD_DATA_RANGE_CHECK((*c1_distance_out)[c1_i428], 6U);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(112, 0, 0);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 112U, *c1_sfEvent);
}

static void initSimStructsc1_subwaycontrolsystem
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void c1_eml_ini_fcn_to_be_inlined_976
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void c1_eml_term_fcn_to_be_inlined_976
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  return c1_y;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance, *(real_T
    *)c1_inData), FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d92;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d92, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d92;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  *(real_T *)c1_outData = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_b_emlrt_marshallOut(chartInstance,
    *(int32_T *)c1_inData), FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_sj, const char_T *c1_identifier)
{
  int32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sj), &c1_thisId);
  sf_mex_destroy(&c1_sj);
  return c1_y;
}

static int32_T c1_d_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i429;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i429, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i429;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  *(int32_T *)c1_outData = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_subwaycontrolsystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[5];
  c1_ResolvedFunctionInfo (*c1_b_info)[5];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i430;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[5])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "abs";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c1_b_info)[0].fileTimeLo = 1286797094U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c1_b_info)[1].name = "eml_scalar_abs";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c1_b_info)[1].fileTimeLo = 1286797112U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context = "";
  (*c1_b_info)[2].name = "eml_int_forloop_overflow_check";
  (*c1_b_info)[2].dominantType = "";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c1_b_info)[2].fileTimeLo = 1332143472U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c1_b_info)[3].name = "intmax";
  (*c1_b_info)[3].dominantType = "char";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c1_b_info)[3].fileTimeLo = 1311233716U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context = "";
  (*c1_b_info)[4].name = "mtimes";
  (*c1_b_info)[4].dominantType = "int32";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[4].fileTimeLo = 1289494492U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c1_i430 = 0; c1_i430 < 5; c1_i430++) {
    c1_r0 = &c1_info[c1_i430];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i430);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i430);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static real_T c1_abs(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
                     real_T c1_x)
{
  return c1_eml_scalar_abs(chartInstance, c1_x);
}

static real_T c1_eml_scalar_abs(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, real_T c1_x)
{
  return muDoubleScalarAbs(c1_x);
}

static boolean_T c1_eml_int_forloop_overflow_check_helper
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_b)
{
  boolean_T c1_overflow;
  int32_T c1_q0;
  int32_T c1_q1;
  int32_T c1_qY;
  c1_q0 = c1_intmax(chartInstance);
  c1_q1 = 1;
  c1_qY = c1_q0 - c1_q1;
  if ((c1_q0 < 0) && ((c1_q1 >= 0) && (c1_qY >= 0))) {
    c1_qY = MIN_int32_T;
  } else {
    if ((c1_q0 >= 0) && ((c1_q1 < 0) && (c1_qY < 0))) {
      c1_qY = MAX_int32_T;
    }
  }

  if (0 > c1_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b > c1_qY);
  }

  return c1_overflow;
}

static int32_T c1_intmax(SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  return MAX_int32_T;
}

static void c1_eml_int_forloop_overflow_check
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_b)
{
  boolean_T c1_overflow;
  c1_overflow = c1_eml_int_forloop_overflow_check_helper(chartInstance, c1_b);
  c1_check_forloop_overflow_error(chartInstance, c1_overflow);
}

static void c1_check_forloop_overflow_error
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, boolean_T c1_overflow)
{
  int32_T c1_i431;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_cv1[34];
  int32_T c1_i432;
  static char_T c1_cv2[5] = { 'i', 'n', 't', '3', '2' };

  char_T c1_cv3[5];
  if (!c1_overflow) {
  } else {
    for (c1_i431 = 0; c1_i431 < 34; c1_i431++) {
      c1_cv1[c1_i431] = c1_cv0[c1_i431];
    }

    for (c1_i432 = 0; c1_i432 < 5; c1_i432++) {
      c1_cv3[c1_i432] = c1_cv2[c1_i432];
    }

    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_c_emlrt_marshallOut(chartInstance, c1_cv1), 14,
      c1_d_emlrt_marshallOut(chartInstance, c1_cv3)));
  }
}

static int32_T c1_mtimes(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
  int32_T c1_a, real_T c1_b)
{
  real_T c1_d93;
  int32_T c1_i433;
  c1_d93 = muDoubleScalarRound((real_T)c1_a * c1_b);
  if (c1_d93 < 2.147483648E+9) {
    if (c1_d93 >= -2.147483648E+9) {
      c1_i433 = (int32_T)c1_d93;
    } else {
      c1_i433 = MIN_int32_T;
    }
  } else if (c1_d93 >= 2.147483648E+9) {
    c1_i433 = MAX_int32_T;
  } else {
    c1_i433 = 0;
  }

  return c1_i433;
}

static void c1_common_checks(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
}

static void c1_integer_only_checks(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  return c1_y;
}

static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, char_T c1_u[34])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34), FALSE);
  return c1_y;
}

static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, char_T c1_u[5])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 5), FALSE);
  return c1_y;
}

static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, uint8_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_e_emlrt_marshallOut(chartInstance,
    *(uint8_T *)c1_inData), FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_is_UrgentController, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_is_UrgentController),
    &c1_thisId);
  sf_mex_destroy(&c1_is_UrgentController);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  *(uint8_T *)c1_outData = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_mxArrayInData), c1_varName);
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[4])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 1), FALSE);
  return c1_y;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i434;
  real_T c1_b_inData[4];
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i434 = 0; c1_i434 < 4; c1_i434++) {
    c1_b_inData[c1_i434] = (*(real_T (*)[4])c1_inData)[c1_i434];
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_f_emlrt_marshallOut(chartInstance,
    c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[8])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  return c1_y;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i435;
  int32_T c1_i436;
  int32_T c1_i437;
  real_T c1_b_inData[8];
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i435 = 0;
  for (c1_i436 = 0; c1_i436 < 2; c1_i436++) {
    for (c1_i437 = 0; c1_i437 < 4; c1_i437++) {
      c1_b_inData[c1_i437 + c1_i435] = (*(real_T (*)[8])c1_inData)[c1_i437 +
        c1_i435];
    }

    c1_i435 += 4;
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_g_emlrt_marshallOut(chartInstance,
    c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_start, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_start), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_start);
}

static void c1_h_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv0[4];
  int32_T c1_i438;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 4, 1);
  for (c1_i438 = 0; c1_i438 < 4; c1_i438++) {
    c1_y[c1_i438] = c1_dv0[c1_i438];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv1[4];
  int32_T c1_i439;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv1);
  for (c1_i439 = 0; c1_i439 < 4; c1_i439++) {
    (*(real_T (*)[4])c1_outData)[c1_i439] = c1_dv1[c1_i439];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, real_T c1_u[4])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  return c1_y;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i440;
  real_T c1_b_inData[4];
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i440 = 0; c1_i440 < 4; c1_i440++) {
    c1_b_inData[c1_i440] = (*(real_T (*)[4])c1_inData)[c1_i440];
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_h_emlrt_marshallOut(chartInstance,
    c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_stop, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_stop), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_stop);
}

static void c1_j_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv2[4];
  int32_T c1_i441;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i441 = 0; c1_i441 < 4; c1_i441++) {
    c1_y[c1_i441] = c1_dv2[c1_i441];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv3[4];
  int32_T c1_i442;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv3);
  for (c1_i442 = 0; c1_i442 < 4; c1_i442++) {
    (*(real_T (*)[4])c1_outData)[c1_i442] = c1_dv3[c1_i442];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_k_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_openPSD, const char_T *c1_identifier, real_T
  c1_y[8])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_openPSD), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_openPSD);
}

static void c1_l_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv4[8];
  int32_T c1_i443;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c1_i443 = 0; c1_i443 < 8; c1_i443++) {
    c1_y[c1_i443] = c1_dv4[c1_i443];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  real_T c1_dv5[8];
  int32_T c1_i444;
  int32_T c1_i445;
  int32_T c1_i446;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_dv5);
  c1_i444 = 0;
  for (c1_i445 = 0; c1_i445 < 2; c1_i445++) {
    for (c1_i446 = 0; c1_i446 < 4; c1_i446++) {
      (*(real_T (*)[8])c1_outData)[c1_i446 + c1_i444] = c1_dv5[c1_i446 + c1_i444];
    }

    c1_i444 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u[4])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 2, 4, 1), FALSE);
  return c1_y;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i447;
  int32_T c1_b_inData[4];
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i447 = 0; c1_i447 < 4; c1_i447++) {
    c1_b_inData[c1_i447] = (*(int32_T (*)[4])c1_inData)[c1_i447];
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_i_emlrt_marshallOut(chartInstance,
    c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_dir, const char_T *c1_identifier, int32_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dir), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dir);
}

static void c1_n_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[4])
{
  int32_T c1_iv0[4];
  int32_T c1_i448;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_iv0, 1, 6, 0U, 1, 0U, 2, 4, 1);
  for (c1_i448 = 0; c1_i448 < 4; c1_i448++) {
    c1_y[c1_i448] = c1_iv0[c1_i448];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  int32_T c1_iv1[4];
  int32_T c1_i449;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_iv1);
  for (c1_i449 = 0; c1_i449 < 4; c1_i449++) {
    (*(int32_T (*)[4])c1_outData)[c1_i449] = c1_iv1[c1_i449];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, int32_T c1_u[4])
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 6, 0U, 1U, 0U, 2, 1, 4), FALSE);
  return c1_y;
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i450;
  int32_T c1_b_inData[4];
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i450 = 0; c1_i450 < 4; c1_i450++) {
    c1_b_inData[c1_i450] = (*(int32_T (*)[4])c1_inData)[c1_i450];
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_j_emlrt_marshallOut(chartInstance,
    c1_b_inData), FALSE);
  return c1_mxArrayOutData;
}

static void c1_o_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_RelevantIndex, const char_T *c1_identifier,
  int32_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_RelevantIndex), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_RelevantIndex);
}

static void c1_p_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  int32_T c1_y[4])
{
  int32_T c1_iv2[4];
  int32_T c1_i451;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_iv2, 1, 6, 0U, 1, 0U, 2, 1, 4);
  for (c1_i451 = 0; c1_i451 < 4; c1_i451++) {
    c1_y[c1_i451] = c1_iv2[c1_i451];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  int32_T c1_iv3[4];
  int32_T c1_i452;
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_mxArrayInData), c1_varName,
                        c1_iv3);
  for (c1_i452 = 0; c1_i452 < 4; c1_i452++) {
    (*(int32_T (*)[4])c1_outData)[c1_i452] = c1_iv3[c1_i452];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_emlrt_marshallOut
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance)
{
  const mxArray *c1_y;
  int32_T c1_i453;
  real_T c1_dv6[4];
  int32_T c1_i454;
  real_T c1_dv7[4];
  int32_T c1_i455;
  real_T c1_dv8[8];
  int32_T c1_i456;
  real_T c1_dv9[4];
  int32_T c1_i457;
  real_T c1_dv10[8];
  int32_T c1_i458;
  int32_T c1_iv4[4];
  int32_T c1_i459;
  real_T c1_dv11[4];
  int32_T c1_i460;
  real_T c1_dv12[8];
  int32_T c1_i461;
  real_T c1_dv13[4];
  int32_T c1_i462;
  int32_T c1_iv5[4];
  int32_T c1_i463;
  real_T c1_dv14[8];
  int32_T c1_i464;
  real_T c1_dv15[4];
  int32_T c1_i465;
  real_T c1_dv16[4];
  int32_T c1_i466;
  real_T c1_dv17[4];
  int32_T c1_i467;
  real_T c1_dv18[4];
  int32_T c1_i468;
  real_T c1_dv19[4];
  int32_T c1_i469;
  real_T c1_dv20[4];
  int32_T c1_i470;
  real_T c1_dv21[4];
  int32_T *c1_N;
  real_T *c1_acc;
  real_T *c1_b_acc;
  real_T *c1_c_acc;
  real_T *c1_d_acc;
  int32_T *c1_dis;
  int32_T *c1_i;
  int32_T *c1_b_i;
  int32_T *c1_c_i;
  int32_T *c1_d_i;
  int32_T *c1_e_i;
  int32_T *c1_f_i;
  int32_T *c1_g_i;
  int32_T *c1_h_i;
  int32_T *c1_i_i;
  real_T *c1_j;
  real_T *c1_b_j;
  real_T *c1_c_j;
  real_T *c1_d_j;
  real_T *c1_maxv;
  real_T *c1_b_maxv;
  real_T *c1_c_maxv;
  real_T *c1_d_maxv;
  real_T *c1_side;
  real_T *c1_b_side;
  real_T *c1_c_side;
  real_T *c1_d_side;
  real_T *c1_stationid;
  real_T *c1_b_stationid;
  real_T *c1_c_stationid;
  real_T *c1_d_stationid;
  int32_T *c1_tdis;
  real_T *c1_distance;
  real_T *c1_b_distance;
  real_T *c1_c_distance;
  real_T *c1_d_distance;
  real_T *c1_t;
  real_T *c1_time;
  real_T *c1_b_time;
  real_T *c1_c_time;
  real_T *c1_d_time;
  real_T *c1_v;
  real_T *c1_b_v;
  real_T *c1_c_v;
  real_T *c1_d_v;
  real_T *c1_y1;
  real_T *c1_b_y1;
  real_T *c1_c_y1;
  real_T *c1_d_y1;
  real_T *c1_y2;
  real_T *c1_b_y2;
  real_T *c1_c_y2;
  real_T *c1_d_y2;
  real_T *c1_e_y2;
  real_T *c1_f_y2;
  real_T *c1_g_y2;
  real_T *c1_h_y2;
  real_T *c1_z;
  real_T *c1_b_z;
  real_T *c1_c_z;
  real_T *c1_d_z;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  uint8_T *c1_is_active_Train0_door;
  uint8_T *c1_is_active_Screen_door00;
  uint8_T *c1_is_active_Controller0;
  uint8_T *c1_is_active_Screen_door01;
  uint8_T *c1_is_active_Screen_door10;
  uint8_T *c1_is_active_Screen_door11;
  uint8_T *c1_is_active_Screen_door20;
  uint8_T *c1_is_active_Screen_door21;
  uint8_T *c1_is_active_Screen_door30;
  uint8_T *c1_is_active_Screen_door31;
  uint8_T *c1_is_active_Train1_door;
  uint8_T *c1_is_active_Train2_door;
  uint8_T *c1_is_active_Train3_door;
  uint8_T *c1_is_active_UrgentController;
  uint8_T *c1_is_active_Train3;
  uint8_T *c1_is_active_Controller1;
  uint8_T *c1_is_active_Controller2;
  uint8_T *c1_is_active_Controller3;
  uint8_T *c1_is_active_Train0;
  uint8_T *c1_is_active_Train1;
  uint8_T *c1_is_active_Train2;
  uint8_T *c1_is_Train0_door;
  uint8_T *c1_is_Screen_door00;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_Screen_door01;
  uint8_T *c1_is_Screen_door10;
  uint8_T *c1_is_Screen_door11;
  uint8_T *c1_is_Screen_door20;
  uint8_T *c1_is_Screen_door21;
  uint8_T *c1_is_Screen_door30;
  uint8_T *c1_is_Screen_door31;
  uint8_T *c1_is_Train1_door;
  uint8_T *c1_is_Train2_door;
  uint8_T *c1_is_Train3_door;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_Train3;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_Train0;
  uint8_T *c1_is_Train1;
  uint8_T *c1_is_Train2;
  real_T (*c1_urstopped)[4];
  real_T (*c1_urstop)[4];
  real_T (*c1_urstart)[4];
  real_T (*c1_stop)[4];
  real_T (*c1_start)[4];
  real_T (*c1_position)[4];
  real_T (*c1_openTD)[4];
  real_T (*c1_openPSD)[8];
  int32_T (*c1_dir)[4];
  real_T (*c1_closeTD)[4];
  real_T (*c1_closePSD)[8];
  real_T (*c1_S)[4];
  int32_T (*c1_RelevantIndex)[4];
  real_T (*c1_PSDClosed)[8];
  real_T (*c1_Delay)[4];
  real_T (*c1_y2_out)[8];
  real_T (*c1_y1_out)[4];
  real_T (*c1_distance_out)[4];
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
  c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
  c1_j = (real_T *)ssGetDWork(chartInstance->S, 90);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
  c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
  c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 86);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
  c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 84);
  c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
  c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
  c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
  c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 81);
  c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
  c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
  c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
  c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
  c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 76);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
  c1_side = (real_T *)ssGetDWork(chartInstance->S, 74);
  c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
  c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
  c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
  c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 69);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
  c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 67);
  c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
  c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_dis = (int32_T *)ssGetDWork(chartInstance->S, 65);
  c1_tdis = (int32_T *)ssGetDWork(chartInstance->S, 64);
  c1_RelevantIndex = (int32_T (*)[4])ssGetDWork(chartInstance->S, 63);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
  c1_position = (real_T (*)[4])ssGetDWork(chartInstance->S, 60);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_urstopped = (real_T (*)[4])ssGetDWork(chartInstance->S, 58);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
  c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
  c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
  c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
  c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
  c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
  c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
  c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
  c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
  c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
  c1_is_active_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 46);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_active_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 44);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_active_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 42);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_active_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 40);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_active_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 38);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_active_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 36);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_active_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 34);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_active_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 32);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_active_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 30);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_active_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 28);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_active_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 26);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_active_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 24);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_active_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 22);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_active_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 20);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_active_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 18);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_active_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 16);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_active_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 14);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_active_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 12);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_active_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 10);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_active_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 8);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_active_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 6);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(122), FALSE);
  for (c1_i453 = 0; c1_i453 < 4; c1_i453++) {
    c1_dv6[c1_i453] = (*c1_distance_out)[c1_i453];
  }

  sf_mex_setcell(c1_y, 0, c1_f_emlrt_marshallOut(chartInstance, c1_dv6));
  for (c1_i454 = 0; c1_i454 < 4; c1_i454++) {
    c1_dv7[c1_i454] = (*c1_y1_out)[c1_i454];
  }

  sf_mex_setcell(c1_y, 1, c1_f_emlrt_marshallOut(chartInstance, c1_dv7));
  for (c1_i455 = 0; c1_i455 < 8; c1_i455++) {
    c1_dv8[c1_i455] = (*c1_y2_out)[c1_i455];
  }

  sf_mex_setcell(c1_y, 2, c1_g_emlrt_marshallOut(chartInstance, c1_dv8));
  for (c1_i456 = 0; c1_i456 < 4; c1_i456++) {
    c1_dv9[c1_i456] = (*c1_Delay)[c1_i456];
  }

  sf_mex_setcell(c1_y, 3, c1_h_emlrt_marshallOut(chartInstance, c1_dv9));
  sf_mex_setcell(c1_y, 4, c1_b_emlrt_marshallOut(chartInstance, *c1_N));
  for (c1_i457 = 0; c1_i457 < 8; c1_i457++) {
    c1_dv10[c1_i457] = (*c1_PSDClosed)[c1_i457];
  }

  sf_mex_setcell(c1_y, 5, c1_g_emlrt_marshallOut(chartInstance, c1_dv10));
  for (c1_i458 = 0; c1_i458 < 4; c1_i458++) {
    c1_iv4[c1_i458] = (*c1_RelevantIndex)[c1_i458];
  }

  sf_mex_setcell(c1_y, 6, c1_j_emlrt_marshallOut(chartInstance, c1_iv4));
  for (c1_i459 = 0; c1_i459 < 4; c1_i459++) {
    c1_dv11[c1_i459] = (*c1_S)[c1_i459];
  }

  sf_mex_setcell(c1_y, 7, c1_h_emlrt_marshallOut(chartInstance, c1_dv11));
  sf_mex_setcell(c1_y, 8, c1_emlrt_marshallOut(chartInstance, *c1_acc));
  sf_mex_setcell(c1_y, 9, c1_emlrt_marshallOut(chartInstance, *c1_b_acc));
  sf_mex_setcell(c1_y, 10, c1_emlrt_marshallOut(chartInstance, *c1_c_acc));
  sf_mex_setcell(c1_y, 11, c1_emlrt_marshallOut(chartInstance, *c1_d_acc));
  for (c1_i460 = 0; c1_i460 < 8; c1_i460++) {
    c1_dv12[c1_i460] = (*c1_closePSD)[c1_i460];
  }

  sf_mex_setcell(c1_y, 12, c1_g_emlrt_marshallOut(chartInstance, c1_dv12));
  for (c1_i461 = 0; c1_i461 < 4; c1_i461++) {
    c1_dv13[c1_i461] = (*c1_closeTD)[c1_i461];
  }

  sf_mex_setcell(c1_y, 13, c1_f_emlrt_marshallOut(chartInstance, c1_dv13));
  for (c1_i462 = 0; c1_i462 < 4; c1_i462++) {
    c1_iv5[c1_i462] = (*c1_dir)[c1_i462];
  }

  sf_mex_setcell(c1_y, 14, c1_i_emlrt_marshallOut(chartInstance, c1_iv5));
  sf_mex_setcell(c1_y, 15, c1_b_emlrt_marshallOut(chartInstance, *c1_dis));
  sf_mex_setcell(c1_y, 16, c1_b_emlrt_marshallOut(chartInstance, *c1_i));
  sf_mex_setcell(c1_y, 17, c1_b_emlrt_marshallOut(chartInstance, *c1_b_i));
  sf_mex_setcell(c1_y, 18, c1_b_emlrt_marshallOut(chartInstance, *c1_c_i));
  sf_mex_setcell(c1_y, 19, c1_b_emlrt_marshallOut(chartInstance, *c1_d_i));
  sf_mex_setcell(c1_y, 20, c1_b_emlrt_marshallOut(chartInstance, *c1_e_i));
  sf_mex_setcell(c1_y, 21, c1_b_emlrt_marshallOut(chartInstance, *c1_f_i));
  sf_mex_setcell(c1_y, 22, c1_b_emlrt_marshallOut(chartInstance, *c1_g_i));
  sf_mex_setcell(c1_y, 23, c1_b_emlrt_marshallOut(chartInstance, *c1_h_i));
  sf_mex_setcell(c1_y, 24, c1_b_emlrt_marshallOut(chartInstance, *c1_i_i));
  sf_mex_setcell(c1_y, 25, c1_emlrt_marshallOut(chartInstance, *c1_j));
  sf_mex_setcell(c1_y, 26, c1_emlrt_marshallOut(chartInstance, *c1_b_j));
  sf_mex_setcell(c1_y, 27, c1_emlrt_marshallOut(chartInstance, *c1_c_j));
  sf_mex_setcell(c1_y, 28, c1_emlrt_marshallOut(chartInstance, *c1_d_j));
  sf_mex_setcell(c1_y, 29, c1_emlrt_marshallOut(chartInstance, *c1_maxv));
  sf_mex_setcell(c1_y, 30, c1_emlrt_marshallOut(chartInstance, *c1_b_maxv));
  sf_mex_setcell(c1_y, 31, c1_emlrt_marshallOut(chartInstance, *c1_c_maxv));
  sf_mex_setcell(c1_y, 32, c1_emlrt_marshallOut(chartInstance, *c1_d_maxv));
  for (c1_i463 = 0; c1_i463 < 8; c1_i463++) {
    c1_dv14[c1_i463] = (*c1_openPSD)[c1_i463];
  }

  sf_mex_setcell(c1_y, 33, c1_g_emlrt_marshallOut(chartInstance, c1_dv14));
  for (c1_i464 = 0; c1_i464 < 4; c1_i464++) {
    c1_dv15[c1_i464] = (*c1_openTD)[c1_i464];
  }

  sf_mex_setcell(c1_y, 34, c1_f_emlrt_marshallOut(chartInstance, c1_dv15));
  for (c1_i465 = 0; c1_i465 < 4; c1_i465++) {
    c1_dv16[c1_i465] = (*c1_position)[c1_i465];
  }

  sf_mex_setcell(c1_y, 35, c1_f_emlrt_marshallOut(chartInstance, c1_dv16));
  sf_mex_setcell(c1_y, 36, c1_emlrt_marshallOut(chartInstance, *c1_side));
  sf_mex_setcell(c1_y, 37, c1_emlrt_marshallOut(chartInstance, *c1_b_side));
  sf_mex_setcell(c1_y, 38, c1_emlrt_marshallOut(chartInstance, *c1_c_side));
  sf_mex_setcell(c1_y, 39, c1_emlrt_marshallOut(chartInstance, *c1_d_side));
  for (c1_i466 = 0; c1_i466 < 4; c1_i466++) {
    c1_dv17[c1_i466] = (*c1_start)[c1_i466];
  }

  sf_mex_setcell(c1_y, 40, c1_f_emlrt_marshallOut(chartInstance, c1_dv17));
  sf_mex_setcell(c1_y, 41, c1_emlrt_marshallOut(chartInstance, *c1_stationid));
  sf_mex_setcell(c1_y, 42, c1_emlrt_marshallOut(chartInstance, *c1_b_stationid));
  sf_mex_setcell(c1_y, 43, c1_emlrt_marshallOut(chartInstance, *c1_c_stationid));
  sf_mex_setcell(c1_y, 44, c1_emlrt_marshallOut(chartInstance, *c1_d_stationid));
  for (c1_i467 = 0; c1_i467 < 4; c1_i467++) {
    c1_dv18[c1_i467] = (*c1_stop)[c1_i467];
  }

  sf_mex_setcell(c1_y, 45, c1_h_emlrt_marshallOut(chartInstance, c1_dv18));
  sf_mex_setcell(c1_y, 46, c1_b_emlrt_marshallOut(chartInstance, *c1_tdis));
  for (c1_i468 = 0; c1_i468 < 4; c1_i468++) {
    c1_dv19[c1_i468] = (*c1_urstart)[c1_i468];
  }

  sf_mex_setcell(c1_y, 47, c1_f_emlrt_marshallOut(chartInstance, c1_dv19));
  for (c1_i469 = 0; c1_i469 < 4; c1_i469++) {
    c1_dv20[c1_i469] = (*c1_urstop)[c1_i469];
  }

  sf_mex_setcell(c1_y, 48, c1_f_emlrt_marshallOut(chartInstance, c1_dv20));
  for (c1_i470 = 0; c1_i470 < 4; c1_i470++) {
    c1_dv21[c1_i470] = (*c1_urstopped)[c1_i470];
  }

  sf_mex_setcell(c1_y, 49, c1_f_emlrt_marshallOut(chartInstance, c1_dv21));
  sf_mex_setcell(c1_y, 50, c1_emlrt_marshallOut(chartInstance, *c1_distance));
  sf_mex_setcell(c1_y, 51, c1_emlrt_marshallOut(chartInstance, *c1_b_distance));
  sf_mex_setcell(c1_y, 52, c1_emlrt_marshallOut(chartInstance, *c1_c_distance));
  sf_mex_setcell(c1_y, 53, c1_emlrt_marshallOut(chartInstance, *c1_d_distance));
  sf_mex_setcell(c1_y, 54, c1_emlrt_marshallOut(chartInstance, *c1_t));
  sf_mex_setcell(c1_y, 55, c1_emlrt_marshallOut(chartInstance, *c1_time));
  sf_mex_setcell(c1_y, 56, c1_emlrt_marshallOut(chartInstance, *c1_b_time));
  sf_mex_setcell(c1_y, 57, c1_emlrt_marshallOut(chartInstance, *c1_c_time));
  sf_mex_setcell(c1_y, 58, c1_emlrt_marshallOut(chartInstance, *c1_d_time));
  sf_mex_setcell(c1_y, 59, c1_emlrt_marshallOut(chartInstance, *c1_v));
  sf_mex_setcell(c1_y, 60, c1_emlrt_marshallOut(chartInstance, *c1_b_v));
  sf_mex_setcell(c1_y, 61, c1_emlrt_marshallOut(chartInstance, *c1_c_v));
  sf_mex_setcell(c1_y, 62, c1_emlrt_marshallOut(chartInstance, *c1_d_v));
  sf_mex_setcell(c1_y, 63, c1_emlrt_marshallOut(chartInstance, *c1_y1));
  sf_mex_setcell(c1_y, 64, c1_emlrt_marshallOut(chartInstance, *c1_b_y1));
  sf_mex_setcell(c1_y, 65, c1_emlrt_marshallOut(chartInstance, *c1_c_y1));
  sf_mex_setcell(c1_y, 66, c1_emlrt_marshallOut(chartInstance, *c1_d_y1));
  sf_mex_setcell(c1_y, 67, c1_emlrt_marshallOut(chartInstance, *c1_y2));
  sf_mex_setcell(c1_y, 68, c1_emlrt_marshallOut(chartInstance, *c1_b_y2));
  sf_mex_setcell(c1_y, 69, c1_emlrt_marshallOut(chartInstance, *c1_c_y2));
  sf_mex_setcell(c1_y, 70, c1_emlrt_marshallOut(chartInstance, *c1_d_y2));
  sf_mex_setcell(c1_y, 71, c1_emlrt_marshallOut(chartInstance, *c1_e_y2));
  sf_mex_setcell(c1_y, 72, c1_emlrt_marshallOut(chartInstance, *c1_f_y2));
  sf_mex_setcell(c1_y, 73, c1_emlrt_marshallOut(chartInstance, *c1_g_y2));
  sf_mex_setcell(c1_y, 74, c1_emlrt_marshallOut(chartInstance, *c1_h_y2));
  sf_mex_setcell(c1_y, 75, c1_emlrt_marshallOut(chartInstance, *c1_z));
  sf_mex_setcell(c1_y, 76, c1_emlrt_marshallOut(chartInstance, *c1_b_z));
  sf_mex_setcell(c1_y, 77, c1_emlrt_marshallOut(chartInstance, *c1_c_z));
  sf_mex_setcell(c1_y, 78, c1_emlrt_marshallOut(chartInstance, *c1_d_z));
  sf_mex_setcell(c1_y, 79, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_c1_subwaycontrolsystem));
  sf_mex_setcell(c1_y, 80, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train0_door));
  sf_mex_setcell(c1_y, 81, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door00));
  sf_mex_setcell(c1_y, 82, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Controller0));
  sf_mex_setcell(c1_y, 83, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door01));
  sf_mex_setcell(c1_y, 84, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door10));
  sf_mex_setcell(c1_y, 85, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door11));
  sf_mex_setcell(c1_y, 86, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door20));
  sf_mex_setcell(c1_y, 87, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door21));
  sf_mex_setcell(c1_y, 88, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door30));
  sf_mex_setcell(c1_y, 89, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Screen_door31));
  sf_mex_setcell(c1_y, 90, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train1_door));
  sf_mex_setcell(c1_y, 91, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train2_door));
  sf_mex_setcell(c1_y, 92, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train3_door));
  sf_mex_setcell(c1_y, 93, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_UrgentController));
  sf_mex_setcell(c1_y, 94, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train3));
  sf_mex_setcell(c1_y, 95, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Controller1));
  sf_mex_setcell(c1_y, 96, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Controller2));
  sf_mex_setcell(c1_y, 97, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Controller3));
  sf_mex_setcell(c1_y, 98, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train0));
  sf_mex_setcell(c1_y, 99, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train1));
  sf_mex_setcell(c1_y, 100, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_active_Train2));
  sf_mex_setcell(c1_y, 101, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Train0_door));
  sf_mex_setcell(c1_y, 102, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door00));
  sf_mex_setcell(c1_y, 103, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Controller0));
  sf_mex_setcell(c1_y, 104, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door01));
  sf_mex_setcell(c1_y, 105, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door10));
  sf_mex_setcell(c1_y, 106, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door11));
  sf_mex_setcell(c1_y, 107, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door20));
  sf_mex_setcell(c1_y, 108, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door21));
  sf_mex_setcell(c1_y, 109, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door30));
  sf_mex_setcell(c1_y, 110, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Screen_door31));
  sf_mex_setcell(c1_y, 111, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Train1_door));
  sf_mex_setcell(c1_y, 112, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Train2_door));
  sf_mex_setcell(c1_y, 113, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Train3_door));
  sf_mex_setcell(c1_y, 114, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_UrgentController));
  sf_mex_setcell(c1_y, 115, c1_e_emlrt_marshallOut(chartInstance, *c1_is_Train3));
  sf_mex_setcell(c1_y, 116, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Controller1));
  sf_mex_setcell(c1_y, 117, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Controller2));
  sf_mex_setcell(c1_y, 118, c1_e_emlrt_marshallOut(chartInstance,
    *c1_is_Controller3));
  sf_mex_setcell(c1_y, 119, c1_e_emlrt_marshallOut(chartInstance, *c1_is_Train0));
  sf_mex_setcell(c1_y, 120, c1_e_emlrt_marshallOut(chartInstance, *c1_is_Train1));
  sf_mex_setcell(c1_y, 121, c1_e_emlrt_marshallOut(chartInstance, *c1_is_Train2));
  return c1_y;
}

static void c1_q_emlrt_marshallIn(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c1_u)
{
  real_T c1_dv22[4];
  int32_T c1_i471;
  real_T c1_dv23[4];
  int32_T c1_i472;
  real_T c1_dv24[8];
  int32_T c1_i473;
  real_T c1_dv25[4];
  int32_T c1_i474;
  real_T c1_dv26[8];
  int32_T c1_i475;
  int32_T c1_iv6[4];
  int32_T c1_i476;
  real_T c1_dv27[4];
  int32_T c1_i477;
  real_T c1_dv28[8];
  int32_T c1_i478;
  real_T c1_dv29[4];
  int32_T c1_i479;
  int32_T c1_iv7[4];
  int32_T c1_i480;
  real_T c1_dv30[8];
  int32_T c1_i481;
  real_T c1_dv31[4];
  int32_T c1_i482;
  real_T c1_dv32[4];
  int32_T c1_i483;
  real_T c1_dv33[4];
  int32_T c1_i484;
  real_T c1_dv34[4];
  int32_T c1_i485;
  real_T c1_dv35[4];
  int32_T c1_i486;
  real_T c1_dv36[4];
  int32_T c1_i487;
  real_T c1_dv37[4];
  int32_T c1_i488;
  int32_T *c1_N;
  real_T *c1_acc;
  real_T *c1_b_acc;
  real_T *c1_c_acc;
  real_T *c1_d_acc;
  int32_T *c1_dis;
  int32_T *c1_i;
  int32_T *c1_b_i;
  int32_T *c1_c_i;
  int32_T *c1_d_i;
  int32_T *c1_e_i;
  int32_T *c1_f_i;
  int32_T *c1_g_i;
  int32_T *c1_h_i;
  int32_T *c1_i_i;
  real_T *c1_j;
  real_T *c1_b_j;
  real_T *c1_c_j;
  real_T *c1_d_j;
  real_T *c1_maxv;
  real_T *c1_b_maxv;
  real_T *c1_c_maxv;
  real_T *c1_d_maxv;
  real_T *c1_side;
  real_T *c1_b_side;
  real_T *c1_c_side;
  real_T *c1_d_side;
  real_T *c1_stationid;
  real_T *c1_b_stationid;
  real_T *c1_c_stationid;
  real_T *c1_d_stationid;
  int32_T *c1_tdis;
  real_T *c1_distance;
  real_T *c1_b_distance;
  real_T *c1_c_distance;
  real_T *c1_d_distance;
  real_T *c1_t;
  real_T *c1_time;
  real_T *c1_b_time;
  real_T *c1_c_time;
  real_T *c1_d_time;
  real_T *c1_v;
  real_T *c1_b_v;
  real_T *c1_c_v;
  real_T *c1_d_v;
  real_T *c1_y1;
  real_T *c1_b_y1;
  real_T *c1_c_y1;
  real_T *c1_d_y1;
  real_T *c1_y2;
  real_T *c1_b_y2;
  real_T *c1_c_y2;
  real_T *c1_d_y2;
  real_T *c1_e_y2;
  real_T *c1_f_y2;
  real_T *c1_g_y2;
  real_T *c1_h_y2;
  real_T *c1_z;
  real_T *c1_b_z;
  real_T *c1_c_z;
  real_T *c1_d_z;
  uint8_T *c1_is_active_c1_subwaycontrolsystem;
  uint8_T *c1_is_active_Train0_door;
  uint8_T *c1_is_active_Screen_door00;
  uint8_T *c1_is_active_Controller0;
  uint8_T *c1_is_active_Screen_door01;
  uint8_T *c1_is_active_Screen_door10;
  uint8_T *c1_is_active_Screen_door11;
  uint8_T *c1_is_active_Screen_door20;
  uint8_T *c1_is_active_Screen_door21;
  uint8_T *c1_is_active_Screen_door30;
  uint8_T *c1_is_active_Screen_door31;
  uint8_T *c1_is_active_Train1_door;
  uint8_T *c1_is_active_Train2_door;
  uint8_T *c1_is_active_Train3_door;
  uint8_T *c1_is_active_UrgentController;
  uint8_T *c1_is_active_Train3;
  uint8_T *c1_is_active_Controller1;
  uint8_T *c1_is_active_Controller2;
  uint8_T *c1_is_active_Controller3;
  uint8_T *c1_is_active_Train0;
  uint8_T *c1_is_active_Train1;
  uint8_T *c1_is_active_Train2;
  uint8_T *c1_is_Train0_door;
  uint8_T *c1_is_Screen_door00;
  uint8_T *c1_is_Controller0;
  uint8_T *c1_is_Screen_door01;
  uint8_T *c1_is_Screen_door10;
  uint8_T *c1_is_Screen_door11;
  uint8_T *c1_is_Screen_door20;
  uint8_T *c1_is_Screen_door21;
  uint8_T *c1_is_Screen_door30;
  uint8_T *c1_is_Screen_door31;
  uint8_T *c1_is_Train1_door;
  uint8_T *c1_is_Train2_door;
  uint8_T *c1_is_Train3_door;
  uint8_T *c1_is_UrgentController;
  uint8_T *c1_is_Train3;
  uint8_T *c1_is_Controller1;
  uint8_T *c1_is_Controller2;
  uint8_T *c1_is_Controller3;
  uint8_T *c1_is_Train0;
  uint8_T *c1_is_Train1;
  uint8_T *c1_is_Train2;
  real_T (*c1_y2_out)[8];
  real_T (*c1_PSDClosed)[8];
  real_T (*c1_closePSD)[8];
  real_T (*c1_openPSD)[8];
  real_T (*c1_urstopped)[4];
  real_T (*c1_urstop)[4];
  real_T (*c1_urstart)[4];
  real_T (*c1_stop)[4];
  real_T (*c1_start)[4];
  real_T (*c1_position)[4];
  real_T (*c1_openTD)[4];
  int32_T (*c1_dir)[4];
  real_T (*c1_closeTD)[4];
  real_T (*c1_S)[4];
  int32_T (*c1_RelevantIndex)[4];
  real_T (*c1_Delay)[4];
  real_T (*c1_y1_out)[4];
  real_T (*c1_distance_out)[4];
  c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
  c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
  c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
  c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
  c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
  c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
  c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
  c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
  c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
  c1_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
  c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
  c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
  c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
  c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
  c1_j = (real_T *)ssGetDWork(chartInstance->S, 90);
  c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
  c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
  c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
  c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
  c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
  c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
  c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
  c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 86);
  c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
  c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
  c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 84);
  c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
  c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
  c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
  c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 81);
  c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
  c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
  c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
  c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
  c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
  c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
  c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
  c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 76);
  c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
  c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
  c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
  c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
  c1_side = (real_T *)ssGetDWork(chartInstance->S, 74);
  c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
  c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
  c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
  c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
  c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
  c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
  c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
  c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 69);
  c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
  c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
  c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 67);
  c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
  c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
  c1_dis = (int32_T *)ssGetDWork(chartInstance->S, 65);
  c1_tdis = (int32_T *)ssGetDWork(chartInstance->S, 64);
  c1_RelevantIndex = (int32_T (*)[4])ssGetDWork(chartInstance->S, 63);
  c1_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
  c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
  c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
  c1_position = (real_T (*)[4])ssGetDWork(chartInstance->S, 60);
  c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
  c1_urstopped = (real_T (*)[4])ssGetDWork(chartInstance->S, 58);
  c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
  c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
  c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
  c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
  c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
  c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
  c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
  c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
  c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
  c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
  c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
  c1_is_active_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 46);
  c1_is_Train2 = (uint8_T *)ssGetDWork(chartInstance->S, 45);
  c1_is_active_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 44);
  c1_is_Train1 = (uint8_T *)ssGetDWork(chartInstance->S, 43);
  c1_is_active_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 42);
  c1_is_Train0 = (uint8_T *)ssGetDWork(chartInstance->S, 41);
  c1_is_active_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 40);
  c1_is_Screen_door10 = (uint8_T *)ssGetDWork(chartInstance->S, 39);
  c1_is_active_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 38);
  c1_is_Train3_door = (uint8_T *)ssGetDWork(chartInstance->S, 37);
  c1_is_active_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 36);
  c1_is_Train3 = (uint8_T *)ssGetDWork(chartInstance->S, 35);
  c1_is_active_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 34);
  c1_is_Train2_door = (uint8_T *)ssGetDWork(chartInstance->S, 33);
  c1_is_active_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 32);
  c1_is_Screen_door11 = (uint8_T *)ssGetDWork(chartInstance->S, 31);
  c1_is_active_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 30);
  c1_is_Screen_door01 = (uint8_T *)ssGetDWork(chartInstance->S, 29);
  c1_is_active_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 28);
  c1_is_Screen_door00 = (uint8_T *)ssGetDWork(chartInstance->S, 27);
  c1_is_active_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 26);
  c1_is_Controller2 = (uint8_T *)ssGetDWork(chartInstance->S, 25);
  c1_is_active_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 24);
  c1_is_Controller3 = (uint8_T *)ssGetDWork(chartInstance->S, 23);
  c1_is_active_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 22);
  c1_is_Screen_door30 = (uint8_T *)ssGetDWork(chartInstance->S, 21);
  c1_is_active_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 20);
  c1_is_Screen_door31 = (uint8_T *)ssGetDWork(chartInstance->S, 19);
  c1_is_active_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 18);
  c1_is_Train1_door = (uint8_T *)ssGetDWork(chartInstance->S, 17);
  c1_is_active_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 16);
  c1_is_Train0_door = (uint8_T *)ssGetDWork(chartInstance->S, 15);
  c1_is_active_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 14);
  c1_is_Screen_door21 = (uint8_T *)ssGetDWork(chartInstance->S, 13);
  c1_is_active_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 12);
  c1_is_Screen_door20 = (uint8_T *)ssGetDWork(chartInstance->S, 11);
  c1_is_active_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 10);
  c1_is_Controller0 = (uint8_T *)ssGetDWork(chartInstance->S, 9);
  c1_is_active_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 8);
  c1_is_Controller1 = (uint8_T *)ssGetDWork(chartInstance->S, 7);
  c1_is_active_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 6);
  c1_is_UrgentController = (uint8_T *)ssGetDWork(chartInstance->S, 5);
  c1_is_active_c1_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    4);
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                        "distance_out", c1_dv22);
  for (c1_i471 = 0; c1_i471 < 4; c1_i471++) {
    (*c1_distance_out)[c1_i471] = c1_dv22[c1_i471];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "y1_out", c1_dv23);
  for (c1_i472 = 0; c1_i472 < 4; c1_i472++) {
    (*c1_y1_out)[c1_i472] = c1_dv23[c1_i472];
  }

  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "y2_out", c1_dv24);
  for (c1_i473 = 0; c1_i473 < 8; c1_i473++) {
    (*c1_y2_out)[c1_i473] = c1_dv24[c1_i473];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
                        "Delay", c1_dv25);
  for (c1_i474 = 0; c1_i474 < 4; c1_i474++) {
    (*c1_Delay)[c1_i474] = c1_dv25[c1_i474];
  }

  *c1_N = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
    "N");
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
                        "PSDClosed", c1_dv26);
  for (c1_i475 = 0; c1_i475 < 8; c1_i475++) {
    (*c1_PSDClosed)[c1_i475] = c1_dv26[c1_i475];
  }

  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 6)),
                        "RelevantIndex", c1_iv6);
  for (c1_i476 = 0; c1_i476 < 4; c1_i476++) {
    (*c1_RelevantIndex)[c1_i476] = c1_iv6[c1_i476];
  }

  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 7)), "S",
                        c1_dv27);
  for (c1_i477 = 0; c1_i477 < 4; c1_i477++) {
    (*c1_S)[c1_i477] = c1_dv27[c1_i477];
  }

  *c1_acc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
    "acc");
  *c1_b_acc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    9)), "acc");
  *c1_c_acc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    10)), "acc");
  *c1_d_acc = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    11)), "acc");
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 12)),
                        "closePSD", c1_dv28);
  for (c1_i478 = 0; c1_i478 < 8; c1_i478++) {
    (*c1_closePSD)[c1_i478] = c1_dv28[c1_i478];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 13)),
                        "closeTD", c1_dv29);
  for (c1_i479 = 0; c1_i479 < 4; c1_i479++) {
    (*c1_closeTD)[c1_i479] = c1_dv29[c1_i479];
  }

  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 14)),
                        "dir", c1_iv7);
  for (c1_i480 = 0; c1_i480 < 4; c1_i480++) {
    (*c1_dir)[c1_i480] = c1_iv7[c1_i480];
  }

  *c1_dis = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    15)), "dis");
  *c1_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    16)), "i");
  *c1_b_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    17)), "i");
  *c1_c_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    18)), "i");
  *c1_d_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    19)), "i");
  *c1_e_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    20)), "i");
  *c1_f_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    21)), "i");
  *c1_g_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    22)), "i");
  *c1_h_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    23)), "i");
  *c1_i_i = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    24)), "i");
  *c1_j = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 25)),
    "j");
  *c1_b_j = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    26)), "j");
  *c1_c_j = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    27)), "j");
  *c1_d_j = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    28)), "j");
  *c1_maxv = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    29)), "maxv");
  *c1_b_maxv = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    30)), "maxv");
  *c1_c_maxv = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    31)), "maxv");
  *c1_d_maxv = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    32)), "maxv");
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 33)),
                        "openPSD", c1_dv30);
  for (c1_i481 = 0; c1_i481 < 8; c1_i481++) {
    (*c1_openPSD)[c1_i481] = c1_dv30[c1_i481];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 34)),
                        "openTD", c1_dv31);
  for (c1_i482 = 0; c1_i482 < 4; c1_i482++) {
    (*c1_openTD)[c1_i482] = c1_dv31[c1_i482];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 35)),
                        "position", c1_dv32);
  for (c1_i483 = 0; c1_i483 < 4; c1_i483++) {
    (*c1_position)[c1_i483] = c1_dv32[c1_i483];
  }

  *c1_side = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    36)), "side");
  *c1_b_side = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    37)), "side");
  *c1_c_side = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    38)), "side");
  *c1_d_side = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    39)), "side");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 40)),
                        "start", c1_dv33);
  for (c1_i484 = 0; c1_i484 < 4; c1_i484++) {
    (*c1_start)[c1_i484] = c1_dv33[c1_i484];
  }

  *c1_stationid = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 41)), "stationid");
  *c1_b_stationid = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 42)), "stationid");
  *c1_c_stationid = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 43)), "stationid");
  *c1_d_stationid = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 44)), "stationid");
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 45)),
                        "stop", c1_dv34);
  for (c1_i485 = 0; c1_i485 < 4; c1_i485++) {
    (*c1_stop)[c1_i485] = c1_dv34[c1_i485];
  }

  *c1_tdis = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    46)), "tdis");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 47)),
                        "urstart", c1_dv35);
  for (c1_i486 = 0; c1_i486 < 4; c1_i486++) {
    (*c1_urstart)[c1_i486] = c1_dv35[c1_i486];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 48)),
                        "urstop", c1_dv36);
  for (c1_i487 = 0; c1_i487 < 4; c1_i487++) {
    (*c1_urstop)[c1_i487] = c1_dv36[c1_i487];
  }

  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 49)),
                        "urstopped", c1_dv37);
  for (c1_i488 = 0; c1_i488 < 4; c1_i488++) {
    (*c1_urstopped)[c1_i488] = c1_dv37[c1_i488];
  }

  *c1_distance = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 50)), "distance");
  *c1_b_distance = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 51)), "distance");
  *c1_c_distance = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 52)), "distance");
  *c1_d_distance = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 53)), "distance");
  *c1_t = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 54)),
    "t");
  *c1_time = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    55)), "time");
  *c1_b_time = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    56)), "time");
  *c1_c_time = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    57)), "time");
  *c1_d_time = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    58)), "time");
  *c1_v = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 59)),
    "v");
  *c1_b_v = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    60)), "v");
  *c1_c_v = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    61)), "v");
  *c1_d_v = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    62)), "v");
  *c1_y1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 63)),
    "y1");
  *c1_b_y1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    64)), "y1");
  *c1_c_y1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    65)), "y1");
  *c1_d_y1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    66)), "y1");
  *c1_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 67)),
    "y2");
  *c1_b_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    68)), "y2");
  *c1_c_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    69)), "y2");
  *c1_d_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    70)), "y2");
  *c1_e_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    71)), "y2");
  *c1_f_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    72)), "y2");
  *c1_g_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    73)), "y2");
  *c1_h_y2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    74)), "y2");
  *c1_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 75)),
    "z");
  *c1_b_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    76)), "z");
  *c1_c_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    77)), "z");
  *c1_d_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    78)), "z");
  *c1_is_active_c1_subwaycontrolsystem = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 79)), "is_active_c1_subwaycontrolsystem");
  *c1_is_active_Train0_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 80)), "is_active_Train0_door");
  *c1_is_active_Screen_door00 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 81)), "is_active_Screen_door00");
  *c1_is_active_Controller0 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 82)), "is_active_Controller0");
  *c1_is_active_Screen_door01 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 83)), "is_active_Screen_door01");
  *c1_is_active_Screen_door10 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 84)), "is_active_Screen_door10");
  *c1_is_active_Screen_door11 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 85)), "is_active_Screen_door11");
  *c1_is_active_Screen_door20 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 86)), "is_active_Screen_door20");
  *c1_is_active_Screen_door21 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 87)), "is_active_Screen_door21");
  *c1_is_active_Screen_door30 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 88)), "is_active_Screen_door30");
  *c1_is_active_Screen_door31 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 89)), "is_active_Screen_door31");
  *c1_is_active_Train1_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 90)), "is_active_Train1_door");
  *c1_is_active_Train2_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 91)), "is_active_Train2_door");
  *c1_is_active_Train3_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 92)), "is_active_Train3_door");
  *c1_is_active_UrgentController = c1_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 93)), "is_active_UrgentController");
  *c1_is_active_Train3 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 94)), "is_active_Train3");
  *c1_is_active_Controller1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 95)), "is_active_Controller1");
  *c1_is_active_Controller2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 96)), "is_active_Controller2");
  *c1_is_active_Controller3 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 97)), "is_active_Controller3");
  *c1_is_active_Train0 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 98)), "is_active_Train0");
  *c1_is_active_Train1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 99)), "is_active_Train1");
  *c1_is_active_Train2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 100)), "is_active_Train2");
  *c1_is_Train0_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 101)), "is_Train0_door");
  *c1_is_Screen_door00 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 102)), "is_Screen_door00");
  *c1_is_Controller0 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 103)), "is_Controller0");
  *c1_is_Screen_door01 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 104)), "is_Screen_door01");
  *c1_is_Screen_door10 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 105)), "is_Screen_door10");
  *c1_is_Screen_door11 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 106)), "is_Screen_door11");
  *c1_is_Screen_door20 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 107)), "is_Screen_door20");
  *c1_is_Screen_door21 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 108)), "is_Screen_door21");
  *c1_is_Screen_door30 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 109)), "is_Screen_door30");
  *c1_is_Screen_door31 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 110)), "is_Screen_door31");
  *c1_is_Train1_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 111)), "is_Train1_door");
  *c1_is_Train2_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 112)), "is_Train2_door");
  *c1_is_Train3_door = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 113)), "is_Train3_door");
  *c1_is_UrgentController = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 114)), "is_UrgentController");
  *c1_is_Train3 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 115)), "is_Train3");
  *c1_is_Controller1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 116)), "is_Controller1");
  *c1_is_Controller2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 117)), "is_Controller2");
  *c1_is_Controller3 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 118)), "is_Controller3");
  *c1_is_Train0 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 119)), "is_Train0");
  *c1_is_Train1 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 120)), "is_Train1");
  *c1_is_Train2 = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 121)), "is_Train2");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 122)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_r_emlrt_marshallIn
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_s_emlrt_marshallIn
  (SFc1_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c1_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static int32_T c1__s32_d_(SFc1_subwaycontrolsystemInstanceStruct *chartInstance,
  real_T c1_b)
{
  int32_T c1_a;
  c1_a = (int32_T)c1_b;
  if ((real_T)c1_a != (c1_b < 0.0 ? muDoubleScalarCeil(c1_b) :
                       muDoubleScalarFloor(c1_b))) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c1_a;
}

static int32_T c1__s32_uminus__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b)
{
  if (c1_b < -2147483647) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return -c1_b;
}

static int32_T c1__s32_minus__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c)
{
  int32_T c1_a;
  c1_a = c1_b - c1_c;
  if (((c1_b ^ c1_a) & (c1_b ^ c1_c)) < 0) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c1_a;
}

static int32_T c1__s32_add__(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance, int32_T c1_b, int32_T c1_c)
{
  int32_T c1_a;
  c1_a = c1_b + c1_c;
  if (((c1_a ^ c1_b) & (c1_a ^ c1_c)) < 0) {
    sf_debug_overflow_detection(SFDB_OVERFLOW);
  }

  return c1_a;
}

static void init_dsm_address_info(SFc1_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_subwaycontrolsystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1552091191U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3576535715U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2541291026U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2238434098U);
}

mxArray *sf_c1_subwaycontrolsystem_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7FYHC0j7iIbpg6VTNez76B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_subwaycontrolsystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[88],T\"distance_out\",},{M[1],M[1082],T\"y1_out\",},{M[1],M[1083],T\"y2_out\",},{M[3],M[127],T\"Delay\",},{M[3],M[1068],T\"N\",},{M[3],M[1617],T\"PSDClosed\",},{M[3],M[1612],T\"RelevantIndex\",},{M[3],M[800],T\"S\",},{M[3],M[1420],T\"acc\",},{M[3],M[1638],T\"acc\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1684],T\"acc\",},{M[3],M[1730],T\"acc\",},{M[3],M[83],T\"closePSD\",},{M[3],M[799],T\"closeTD\",},{M[3],M[1327],T\"dir\",},{M[3],M[1624],T\"dis\",},{M[3],M[1325],T\"i\",},{M[3],M[1418],T\"i\",},{M[3],M[1457],T\"i\",},{M[3],M[1536],T\"i\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1560],T\"i\",},{M[3],M[1584],T\"i\",},{M[3],M[1636],T\"i\",},{M[3],M[1682],T\"i\",},{M[3],M[1728],T\"i\",},{M[3],M[1415],T\"j\",},{M[3],M[1633],T\"j\",},{M[3],M[1679],T\"j\",},{M[3],M[1725],T\"j\",},{M[3],M[1416],T\"maxv\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[1634],T\"maxv\",},{M[3],M[1680],T\"maxv\",},{M[3],M[1726],T\"maxv\",},{M[3],M[82],T\"openPSD\",},{M[3],M[798],T\"openTD\",},{M[3],M[1531],T\"position\",},{M[3],M[166],T\"side\",},{M[3],M[1535],T\"side\",},{M[3],M[1559],T\"side\",},{M[3],M[1583],T\"side\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[80],T\"start\",},{M[3],M[165],T\"stationid\",},{M[3],M[1534],T\"stationid\",},{M[3],M[1558],T\"stationid\",},{M[3],M[1582],T\"stationid\",},{M[3],M[81],T\"stop\",},{M[3],M[1623],T\"tdis\",},{M[3],M[920],T\"urstart\",},{M[3],M[921],T\"urstop\",},{M[3],M[1314],T\"urstopped\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[5],M[1419],T\"distance\",},{M[5],M[1637],T\"distance\",},{M[5],M[1683],T\"distance\",},{M[5],M[1729],T\"distance\",},{M[5],M[1264],T\"t\",},{M[5],M[1417],T\"time\",},{M[5],M[1635],T\"time\",},{M[5],M[1681],T\"time\",},{M[5],M[1727],T\"time\",},{M[5],M[1414],T\"v\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[5],M[1632],T\"v\",},{M[5],M[1678],T\"v\",},{M[5],M[1724],T\"v\",},{M[5],M[1050],T\"y1\",},{M[5],M[1051],T\"y1\",},{M[5],M[1052],T\"y1\",},{M[5],M[1053],T\"y1\",},{M[5],M[167],T\"y2\",},{M[5],M[168],T\"y2\",},{M[5],M[180],T\"y2\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[5],M[192],T\"y2\",},{M[5],M[204],T\"y2\",},{M[5],M[216],T\"y2\",},{M[5],M[228],T\"y2\",},{M[5],M[240],T\"y2\",},{M[5],M[76],T\"z\",},{M[5],M[1533],T\"z\",},{M[5],M[1557],T\"z\",},{M[5],M[1581],T\"z\",},{M[8],M[0],T\"is_active_c1_subwaycontrolsystem\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[11],T\"is_active_Train0_door\",},{M[8],M[31],T\"is_active_Screen_door00\",},{M[8],M[64],T\"is_active_Controller0\",},{M[8],M[169],T\"is_active_Screen_door01\",},{M[8],M[181],T\"is_active_Screen_door10\",},{M[8],M[193],T\"is_active_Screen_door11\",},{M[8],M[205],T\"is_active_Screen_door20\",},{M[8],M[217],T\"is_active_Screen_door21\",},{M[8],M[229],T\"is_active_Screen_door30\",},{M[8],M[241],T\"is_active_Screen_door31\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[290],T\"is_active_Train1_door\",},{M[8],M[578],T\"is_active_Train2_door\",},{M[8],M[650],T\"is_active_Train3_door\",},{M[8],M[1267],T\"is_active_UrgentController\",},{M[8],M[1421],T\"is_active_Train3\",},{M[8],M[1537],T\"is_active_Controller1\",},{M[8],M[1561],T\"is_active_Controller2\",},{M[8],M[1585],T\"is_active_Controller3\",},{M[8],M[1639],T\"is_active_Train0\",},{M[8],M[1685],T\"is_active_Train1\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[1731],T\"is_active_Train2\",},{M[9],M[11],T\"is_Train0_door\",},{M[9],M[31],T\"is_Screen_door00\",},{M[9],M[64],T\"is_Controller0\",},{M[9],M[169],T\"is_Screen_door01\",},{M[9],M[181],T\"is_Screen_door10\",},{M[9],M[193],T\"is_Screen_door11\",},{M[9],M[205],T\"is_Screen_door20\",},{M[9],M[217],T\"is_Screen_door21\",},{M[9],M[229],T\"is_Screen_door30\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[241],T\"is_Screen_door31\",},{M[9],M[290],T\"is_Train1_door\",},{M[9],M[578],T\"is_Train2_door\",},{M[9],M[650],T\"is_Train3_door\",},{M[9],M[1267],T\"is_UrgentController\",},{M[9],M[1421],T\"is_Train3\",},{M[9],M[1537],T\"is_Controller1\",},{M[9],M[1561],T\"is_Controller2\",},{M[9],M[1585],T\"is_Controller3\",},{M[9],M[1639],T\"is_Train0\",}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[9],M[1685],T\"is_Train1\",},{M[9],M[1731],T\"is_Train2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 122, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_subwaycontrolsystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
    chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_subwaycontrolsystemMachineNumber_,
           1,
           154,
           222,
           82,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_subwaycontrolsystemMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_subwaycontrolsystemMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_subwaycontrolsystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v_shutTD");
          _SFD_SET_DATA_PROPS(1,1,1,0,"v_shutPSD");
          _SFD_SET_DATA_PROPS(2,0,0,0,"start");
          _SFD_SET_DATA_PROPS(3,0,0,0,"stop");
          _SFD_SET_DATA_PROPS(4,0,0,0,"openPSD");
          _SFD_SET_DATA_PROPS(5,0,0,0,"closePSD");
          _SFD_SET_DATA_PROPS(6,2,0,1,"distance_out");
          _SFD_SET_DATA_PROPS(7,0,0,0,"Delay");
          _SFD_SET_DATA_PROPS(8,0,0,0,"openTD");
          _SFD_SET_DATA_PROPS(9,0,0,0,"closeTD");
          _SFD_SET_DATA_PROPS(10,0,0,0,"S");
          _SFD_SET_DATA_PROPS(11,0,0,0,"urstart");
          _SFD_SET_DATA_PROPS(12,0,0,0,"urstop");
          _SFD_SET_DATA_PROPS(13,0,0,0,"N");
          _SFD_SET_DATA_PROPS(14,2,0,1,"y1_out");
          _SFD_SET_DATA_PROPS(15,2,0,1,"y2_out");
          _SFD_SET_DATA_PROPS(16,0,0,0,"urstopped");
          _SFD_SET_DATA_PROPS(17,0,0,0,"dir");
          _SFD_SET_DATA_PROPS(18,0,0,0,"position");
          _SFD_SET_DATA_PROPS(19,0,0,0,"PSDClosed");
          _SFD_SET_DATA_PROPS(20,0,0,0,"t");
          _SFD_SET_DATA_PROPS(21,0,0,0,"i");
          _SFD_SET_DATA_PROPS(22,0,0,0,"RelevantIndex");
          _SFD_SET_DATA_PROPS(23,0,0,0,"tdis");
          _SFD_SET_DATA_PROPS(24,0,0,0,"dis");
          _SFD_SET_DATA_PROPS(25,8,0,0,"");
          _SFD_SET_DATA_PROPS(26,0,0,0,"z");
          _SFD_SET_DATA_PROPS(27,0,0,0,"stationid");
          _SFD_SET_DATA_PROPS(28,0,0,0,"side");
          _SFD_SET_DATA_PROPS(29,0,0,0,"i");
          _SFD_SET_DATA_PROPS(30,0,0,0,"v");
          _SFD_SET_DATA_PROPS(31,0,0,0,"j");
          _SFD_SET_DATA_PROPS(32,0,0,0,"maxv");
          _SFD_SET_DATA_PROPS(33,0,0,0,"time");
          _SFD_SET_DATA_PROPS(34,0,0,0,"i");
          _SFD_SET_DATA_PROPS(35,0,0,0,"distance");
          _SFD_SET_DATA_PROPS(36,0,0,0,"acc");
          _SFD_SET_DATA_PROPS(37,0,0,0,"z");
          _SFD_SET_DATA_PROPS(38,0,0,0,"stationid");
          _SFD_SET_DATA_PROPS(39,0,0,0,"side");
          _SFD_SET_DATA_PROPS(40,0,0,0,"i");
          _SFD_SET_DATA_PROPS(41,0,0,0,"y1");
          _SFD_SET_DATA_PROPS(42,0,0,0,"y1");
          _SFD_SET_DATA_PROPS(43,0,0,0,"v");
          _SFD_SET_DATA_PROPS(44,0,0,0,"j");
          _SFD_SET_DATA_PROPS(45,0,0,0,"maxv");
          _SFD_SET_DATA_PROPS(46,0,0,0,"time");
          _SFD_SET_DATA_PROPS(47,0,0,0,"i");
          _SFD_SET_DATA_PROPS(48,0,0,0,"distance");
          _SFD_SET_DATA_PROPS(49,0,0,0,"acc");
          _SFD_SET_DATA_PROPS(50,0,0,0,"z");
          _SFD_SET_DATA_PROPS(51,0,0,0,"stationid");
          _SFD_SET_DATA_PROPS(52,0,0,0,"side");
          _SFD_SET_DATA_PROPS(53,0,0,0,"i");
          _SFD_SET_DATA_PROPS(54,0,0,0,"z");
          _SFD_SET_DATA_PROPS(55,0,0,0,"stationid");
          _SFD_SET_DATA_PROPS(56,0,0,0,"side");
          _SFD_SET_DATA_PROPS(57,0,0,0,"i");
          _SFD_SET_DATA_PROPS(58,0,0,0,"v");
          _SFD_SET_DATA_PROPS(59,0,0,0,"j");
          _SFD_SET_DATA_PROPS(60,0,0,0,"maxv");
          _SFD_SET_DATA_PROPS(61,0,0,0,"time");
          _SFD_SET_DATA_PROPS(62,0,0,0,"i");
          _SFD_SET_DATA_PROPS(63,0,0,0,"distance");
          _SFD_SET_DATA_PROPS(64,0,0,0,"acc");
          _SFD_SET_DATA_PROPS(65,0,0,0,"y1");
          _SFD_SET_DATA_PROPS(66,0,0,0,"v");
          _SFD_SET_DATA_PROPS(67,0,0,0,"j");
          _SFD_SET_DATA_PROPS(68,0,0,0,"maxv");
          _SFD_SET_DATA_PROPS(69,0,0,0,"time");
          _SFD_SET_DATA_PROPS(70,0,0,0,"i");
          _SFD_SET_DATA_PROPS(71,0,0,0,"distance");
          _SFD_SET_DATA_PROPS(72,0,0,0,"acc");
          _SFD_SET_DATA_PROPS(73,0,0,0,"y1");
          _SFD_SET_DATA_PROPS(74,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(75,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(76,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(77,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(78,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(79,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(80,0,0,0,"y2");
          _SFD_SET_DATA_PROPS(81,0,0,0,"y2");
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,1);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,1);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,1);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,0);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,1);
          _SFD_STATE_INFO(37,0,0);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,1);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,0);
          _SFD_STATE_INFO(46,0,1);
          _SFD_STATE_INFO(47,0,0);
          _SFD_STATE_INFO(48,0,0);
          _SFD_STATE_INFO(49,0,0);
          _SFD_STATE_INFO(50,0,0);
          _SFD_STATE_INFO(51,0,1);
          _SFD_STATE_INFO(52,0,0);
          _SFD_STATE_INFO(53,0,0);
          _SFD_STATE_INFO(54,0,0);
          _SFD_STATE_INFO(55,0,0);
          _SFD_STATE_INFO(56,0,1);
          _SFD_STATE_INFO(57,0,0);
          _SFD_STATE_INFO(58,0,0);
          _SFD_STATE_INFO(59,0,0);
          _SFD_STATE_INFO(60,0,0);
          _SFD_STATE_INFO(61,0,1);
          _SFD_STATE_INFO(62,0,0);
          _SFD_STATE_INFO(63,0,0);
          _SFD_STATE_INFO(64,0,0);
          _SFD_STATE_INFO(65,0,0);
          _SFD_STATE_INFO(66,0,1);
          _SFD_STATE_INFO(67,0,0);
          _SFD_STATE_INFO(68,0,0);
          _SFD_STATE_INFO(69,0,0);
          _SFD_STATE_INFO(70,0,0);
          _SFD_STATE_INFO(71,0,1);
          _SFD_STATE_INFO(72,0,0);
          _SFD_STATE_INFO(73,0,0);
          _SFD_STATE_INFO(74,0,0);
          _SFD_STATE_INFO(75,0,0);
          _SFD_STATE_INFO(76,0,1);
          _SFD_STATE_INFO(77,0,0);
          _SFD_STATE_INFO(78,0,0);
          _SFD_STATE_INFO(79,0,0);
          _SFD_STATE_INFO(80,0,0);
          _SFD_STATE_INFO(81,0,0);
          _SFD_STATE_INFO(82,0,0);
          _SFD_STATE_INFO(83,0,0);
          _SFD_STATE_INFO(84,0,0);
          _SFD_STATE_INFO(85,0,0);
          _SFD_STATE_INFO(86,0,0);
          _SFD_STATE_INFO(87,0,0);
          _SFD_STATE_INFO(88,0,0);
          _SFD_STATE_INFO(89,0,1);
          _SFD_STATE_INFO(90,0,0);
          _SFD_STATE_INFO(91,0,0);
          _SFD_STATE_INFO(92,0,0);
          _SFD_STATE_INFO(93,0,0);
          _SFD_STATE_INFO(94,0,1);
          _SFD_STATE_INFO(95,0,0);
          _SFD_STATE_INFO(96,0,0);
          _SFD_STATE_INFO(97,0,0);
          _SFD_STATE_INFO(98,0,0);
          _SFD_STATE_INFO(99,0,0);
          _SFD_STATE_INFO(100,0,0);
          _SFD_STATE_INFO(101,0,0);
          _SFD_STATE_INFO(102,0,0);
          _SFD_STATE_INFO(103,0,0);
          _SFD_STATE_INFO(104,0,0);
          _SFD_STATE_INFO(105,0,0);
          _SFD_STATE_INFO(106,0,0);
          _SFD_STATE_INFO(107,0,1);
          _SFD_STATE_INFO(108,0,0);
          _SFD_STATE_INFO(109,0,0);
          _SFD_STATE_INFO(110,0,0);
          _SFD_STATE_INFO(111,0,0);
          _SFD_STATE_INFO(112,0,1);
          _SFD_STATE_INFO(113,0,0);
          _SFD_STATE_INFO(114,0,0);
          _SFD_STATE_INFO(115,0,0);
          _SFD_STATE_INFO(116,0,0);
          _SFD_STATE_INFO(117,0,0);
          _SFD_STATE_INFO(118,0,0);
          _SFD_STATE_INFO(119,0,0);
          _SFD_STATE_INFO(120,0,0);
          _SFD_STATE_INFO(121,0,0);
          _SFD_STATE_INFO(122,0,0);
          _SFD_STATE_INFO(123,0,0);
          _SFD_STATE_INFO(124,0,0);
          _SFD_STATE_INFO(125,0,1);
          _SFD_STATE_INFO(126,0,0);
          _SFD_STATE_INFO(127,0,0);
          _SFD_STATE_INFO(128,0,0);
          _SFD_STATE_INFO(129,0,0);
          _SFD_STATE_INFO(130,0,1);
          _SFD_STATE_INFO(131,0,0);
          _SFD_STATE_INFO(132,0,0);
          _SFD_STATE_INFO(133,0,0);
          _SFD_STATE_INFO(134,0,0);
          _SFD_STATE_INFO(135,0,0);
          _SFD_STATE_INFO(136,0,0);
          _SFD_STATE_INFO(137,0,0);
          _SFD_STATE_INFO(138,0,0);
          _SFD_STATE_INFO(139,0,0);
          _SFD_STATE_INFO(140,0,0);
          _SFD_STATE_INFO(141,0,0);
          _SFD_STATE_INFO(142,0,0);
          _SFD_STATE_INFO(143,0,1);
          _SFD_STATE_INFO(144,0,0);
          _SFD_STATE_INFO(145,0,0);
          _SFD_STATE_INFO(146,0,0);
          _SFD_STATE_INFO(147,0,0);
          _SFD_STATE_INFO(148,0,1);
          _SFD_STATE_INFO(150,0,0);
          _SFD_STATE_INFO(151,0,0);
          _SFD_STATE_INFO(153,0,0);
          _SFD_STATE_INFO(149,0,2);
          _SFD_STATE_INFO(152,0,2);
          _SFD_CH_SUBSTATE_COUNT(21);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,89);
          _SFD_CH_SUBSTATE_INDEX(1,36);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_CH_SUBSTATE_INDEX(3,41);
          _SFD_CH_SUBSTATE_INDEX(4,46);
          _SFD_CH_SUBSTATE_INDEX(5,51);
          _SFD_CH_SUBSTATE_INDEX(6,56);
          _SFD_CH_SUBSTATE_INDEX(7,61);
          _SFD_CH_SUBSTATE_INDEX(8,66);
          _SFD_CH_SUBSTATE_INDEX(9,71);
          _SFD_CH_SUBSTATE_INDEX(10,107);
          _SFD_CH_SUBSTATE_INDEX(11,125);
          _SFD_CH_SUBSTATE_INDEX(12,143);
          _SFD_CH_SUBSTATE_INDEX(13,148);
          _SFD_CH_SUBSTATE_INDEX(14,130);
          _SFD_CH_SUBSTATE_INDEX(15,9);
          _SFD_CH_SUBSTATE_INDEX(16,18);
          _SFD_CH_SUBSTATE_INDEX(17,27);
          _SFD_CH_SUBSTATE_INDEX(18,76);
          _SFD_CH_SUBSTATE_INDEX(19,94);
          _SFD_CH_SUBSTATE_INDEX(20,112);
          _SFD_ST_SUBSTATE_COUNT(89,4);
          _SFD_ST_SUBSTATE_INDEX(89,0,90);
          _SFD_ST_SUBSTATE_INDEX(89,1,91);
          _SFD_ST_SUBSTATE_INDEX(89,2,92);
          _SFD_ST_SUBSTATE_INDEX(89,3,93);
          _SFD_ST_SUBSTATE_COUNT(90,0);
          _SFD_ST_SUBSTATE_COUNT(91,0);
          _SFD_ST_SUBSTATE_COUNT(92,0);
          _SFD_ST_SUBSTATE_COUNT(93,0);
          _SFD_ST_SUBSTATE_COUNT(36,4);
          _SFD_ST_SUBSTATE_INDEX(36,0,37);
          _SFD_ST_SUBSTATE_INDEX(36,1,38);
          _SFD_ST_SUBSTATE_INDEX(36,2,39);
          _SFD_ST_SUBSTATE_INDEX(36,3,40);
          _SFD_ST_SUBSTATE_COUNT(37,0);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(0,8);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_INDEX(0,3,4);
          _SFD_ST_SUBSTATE_INDEX(0,4,5);
          _SFD_ST_SUBSTATE_INDEX(0,5,6);
          _SFD_ST_SUBSTATE_INDEX(0,6,7);
          _SFD_ST_SUBSTATE_INDEX(0,7,8);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(41,4);
          _SFD_ST_SUBSTATE_INDEX(41,0,42);
          _SFD_ST_SUBSTATE_INDEX(41,1,43);
          _SFD_ST_SUBSTATE_INDEX(41,2,44);
          _SFD_ST_SUBSTATE_INDEX(41,3,45);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,0);
          _SFD_ST_SUBSTATE_COUNT(45,0);
          _SFD_ST_SUBSTATE_COUNT(46,4);
          _SFD_ST_SUBSTATE_INDEX(46,0,47);
          _SFD_ST_SUBSTATE_INDEX(46,1,48);
          _SFD_ST_SUBSTATE_INDEX(46,2,49);
          _SFD_ST_SUBSTATE_INDEX(46,3,50);
          _SFD_ST_SUBSTATE_COUNT(47,0);
          _SFD_ST_SUBSTATE_COUNT(48,0);
          _SFD_ST_SUBSTATE_COUNT(49,0);
          _SFD_ST_SUBSTATE_COUNT(50,0);
          _SFD_ST_SUBSTATE_COUNT(51,4);
          _SFD_ST_SUBSTATE_INDEX(51,0,52);
          _SFD_ST_SUBSTATE_INDEX(51,1,53);
          _SFD_ST_SUBSTATE_INDEX(51,2,54);
          _SFD_ST_SUBSTATE_INDEX(51,3,55);
          _SFD_ST_SUBSTATE_COUNT(52,0);
          _SFD_ST_SUBSTATE_COUNT(53,0);
          _SFD_ST_SUBSTATE_COUNT(54,0);
          _SFD_ST_SUBSTATE_COUNT(55,0);
          _SFD_ST_SUBSTATE_COUNT(56,4);
          _SFD_ST_SUBSTATE_INDEX(56,0,57);
          _SFD_ST_SUBSTATE_INDEX(56,1,58);
          _SFD_ST_SUBSTATE_INDEX(56,2,59);
          _SFD_ST_SUBSTATE_INDEX(56,3,60);
          _SFD_ST_SUBSTATE_COUNT(57,0);
          _SFD_ST_SUBSTATE_COUNT(58,0);
          _SFD_ST_SUBSTATE_COUNT(59,0);
          _SFD_ST_SUBSTATE_COUNT(60,0);
          _SFD_ST_SUBSTATE_COUNT(61,4);
          _SFD_ST_SUBSTATE_INDEX(61,0,62);
          _SFD_ST_SUBSTATE_INDEX(61,1,63);
          _SFD_ST_SUBSTATE_INDEX(61,2,64);
          _SFD_ST_SUBSTATE_INDEX(61,3,65);
          _SFD_ST_SUBSTATE_COUNT(62,0);
          _SFD_ST_SUBSTATE_COUNT(63,0);
          _SFD_ST_SUBSTATE_COUNT(64,0);
          _SFD_ST_SUBSTATE_COUNT(65,0);
          _SFD_ST_SUBSTATE_COUNT(66,4);
          _SFD_ST_SUBSTATE_INDEX(66,0,67);
          _SFD_ST_SUBSTATE_INDEX(66,1,68);
          _SFD_ST_SUBSTATE_INDEX(66,2,69);
          _SFD_ST_SUBSTATE_INDEX(66,3,70);
          _SFD_ST_SUBSTATE_COUNT(67,0);
          _SFD_ST_SUBSTATE_COUNT(68,0);
          _SFD_ST_SUBSTATE_COUNT(69,0);
          _SFD_ST_SUBSTATE_COUNT(70,0);
          _SFD_ST_SUBSTATE_COUNT(71,4);
          _SFD_ST_SUBSTATE_INDEX(71,0,72);
          _SFD_ST_SUBSTATE_INDEX(71,1,73);
          _SFD_ST_SUBSTATE_INDEX(71,2,74);
          _SFD_ST_SUBSTATE_INDEX(71,3,75);
          _SFD_ST_SUBSTATE_COUNT(72,0);
          _SFD_ST_SUBSTATE_COUNT(73,0);
          _SFD_ST_SUBSTATE_COUNT(74,0);
          _SFD_ST_SUBSTATE_COUNT(75,0);
          _SFD_ST_SUBSTATE_COUNT(107,4);
          _SFD_ST_SUBSTATE_INDEX(107,0,108);
          _SFD_ST_SUBSTATE_INDEX(107,1,109);
          _SFD_ST_SUBSTATE_INDEX(107,2,110);
          _SFD_ST_SUBSTATE_INDEX(107,3,111);
          _SFD_ST_SUBSTATE_COUNT(108,0);
          _SFD_ST_SUBSTATE_COUNT(109,0);
          _SFD_ST_SUBSTATE_COUNT(110,0);
          _SFD_ST_SUBSTATE_COUNT(111,0);
          _SFD_ST_SUBSTATE_COUNT(125,4);
          _SFD_ST_SUBSTATE_INDEX(125,0,126);
          _SFD_ST_SUBSTATE_INDEX(125,1,127);
          _SFD_ST_SUBSTATE_INDEX(125,2,128);
          _SFD_ST_SUBSTATE_INDEX(125,3,129);
          _SFD_ST_SUBSTATE_COUNT(126,0);
          _SFD_ST_SUBSTATE_COUNT(127,0);
          _SFD_ST_SUBSTATE_COUNT(128,0);
          _SFD_ST_SUBSTATE_COUNT(129,0);
          _SFD_ST_SUBSTATE_COUNT(143,4);
          _SFD_ST_SUBSTATE_INDEX(143,0,144);
          _SFD_ST_SUBSTATE_INDEX(143,1,145);
          _SFD_ST_SUBSTATE_INDEX(143,2,146);
          _SFD_ST_SUBSTATE_INDEX(143,3,147);
          _SFD_ST_SUBSTATE_COUNT(144,0);
          _SFD_ST_SUBSTATE_COUNT(145,0);
          _SFD_ST_SUBSTATE_COUNT(146,0);
          _SFD_ST_SUBSTATE_COUNT(147,0);
          _SFD_ST_SUBSTATE_COUNT(148,3);
          _SFD_ST_SUBSTATE_INDEX(148,0,150);
          _SFD_ST_SUBSTATE_INDEX(148,1,151);
          _SFD_ST_SUBSTATE_INDEX(148,2,153);
          _SFD_ST_SUBSTATE_COUNT(150,0);
          _SFD_ST_SUBSTATE_COUNT(151,0);
          _SFD_ST_SUBSTATE_COUNT(153,0);
          _SFD_ST_SUBSTATE_COUNT(130,12);
          _SFD_ST_SUBSTATE_INDEX(130,0,131);
          _SFD_ST_SUBSTATE_INDEX(130,1,132);
          _SFD_ST_SUBSTATE_INDEX(130,2,133);
          _SFD_ST_SUBSTATE_INDEX(130,3,134);
          _SFD_ST_SUBSTATE_INDEX(130,4,135);
          _SFD_ST_SUBSTATE_INDEX(130,5,136);
          _SFD_ST_SUBSTATE_INDEX(130,6,137);
          _SFD_ST_SUBSTATE_INDEX(130,7,138);
          _SFD_ST_SUBSTATE_INDEX(130,8,139);
          _SFD_ST_SUBSTATE_INDEX(130,9,140);
          _SFD_ST_SUBSTATE_INDEX(130,10,141);
          _SFD_ST_SUBSTATE_INDEX(130,11,142);
          _SFD_ST_SUBSTATE_COUNT(131,0);
          _SFD_ST_SUBSTATE_COUNT(132,0);
          _SFD_ST_SUBSTATE_COUNT(133,0);
          _SFD_ST_SUBSTATE_COUNT(134,0);
          _SFD_ST_SUBSTATE_COUNT(135,0);
          _SFD_ST_SUBSTATE_COUNT(136,0);
          _SFD_ST_SUBSTATE_COUNT(137,0);
          _SFD_ST_SUBSTATE_COUNT(138,0);
          _SFD_ST_SUBSTATE_COUNT(139,0);
          _SFD_ST_SUBSTATE_COUNT(140,0);
          _SFD_ST_SUBSTATE_COUNT(141,0);
          _SFD_ST_SUBSTATE_COUNT(142,0);
          _SFD_ST_SUBSTATE_COUNT(9,8);
          _SFD_ST_SUBSTATE_INDEX(9,0,10);
          _SFD_ST_SUBSTATE_INDEX(9,1,11);
          _SFD_ST_SUBSTATE_INDEX(9,2,12);
          _SFD_ST_SUBSTATE_INDEX(9,3,13);
          _SFD_ST_SUBSTATE_INDEX(9,4,14);
          _SFD_ST_SUBSTATE_INDEX(9,5,15);
          _SFD_ST_SUBSTATE_INDEX(9,6,16);
          _SFD_ST_SUBSTATE_INDEX(9,7,17);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,8);
          _SFD_ST_SUBSTATE_INDEX(18,0,19);
          _SFD_ST_SUBSTATE_INDEX(18,1,20);
          _SFD_ST_SUBSTATE_INDEX(18,2,21);
          _SFD_ST_SUBSTATE_INDEX(18,3,22);
          _SFD_ST_SUBSTATE_INDEX(18,4,23);
          _SFD_ST_SUBSTATE_INDEX(18,5,24);
          _SFD_ST_SUBSTATE_INDEX(18,6,25);
          _SFD_ST_SUBSTATE_INDEX(18,7,26);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(26,0);
          _SFD_ST_SUBSTATE_COUNT(27,8);
          _SFD_ST_SUBSTATE_INDEX(27,0,28);
          _SFD_ST_SUBSTATE_INDEX(27,1,29);
          _SFD_ST_SUBSTATE_INDEX(27,2,30);
          _SFD_ST_SUBSTATE_INDEX(27,3,31);
          _SFD_ST_SUBSTATE_INDEX(27,4,32);
          _SFD_ST_SUBSTATE_INDEX(27,5,33);
          _SFD_ST_SUBSTATE_INDEX(27,6,34);
          _SFD_ST_SUBSTATE_INDEX(27,7,35);
          _SFD_ST_SUBSTATE_COUNT(28,0);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(32,0);
          _SFD_ST_SUBSTATE_COUNT(33,0);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(76,12);
          _SFD_ST_SUBSTATE_INDEX(76,0,77);
          _SFD_ST_SUBSTATE_INDEX(76,1,78);
          _SFD_ST_SUBSTATE_INDEX(76,2,79);
          _SFD_ST_SUBSTATE_INDEX(76,3,80);
          _SFD_ST_SUBSTATE_INDEX(76,4,81);
          _SFD_ST_SUBSTATE_INDEX(76,5,82);
          _SFD_ST_SUBSTATE_INDEX(76,6,83);
          _SFD_ST_SUBSTATE_INDEX(76,7,84);
          _SFD_ST_SUBSTATE_INDEX(76,8,85);
          _SFD_ST_SUBSTATE_INDEX(76,9,86);
          _SFD_ST_SUBSTATE_INDEX(76,10,87);
          _SFD_ST_SUBSTATE_INDEX(76,11,88);
          _SFD_ST_SUBSTATE_COUNT(77,0);
          _SFD_ST_SUBSTATE_COUNT(78,0);
          _SFD_ST_SUBSTATE_COUNT(79,0);
          _SFD_ST_SUBSTATE_COUNT(80,0);
          _SFD_ST_SUBSTATE_COUNT(81,0);
          _SFD_ST_SUBSTATE_COUNT(82,0);
          _SFD_ST_SUBSTATE_COUNT(83,0);
          _SFD_ST_SUBSTATE_COUNT(84,0);
          _SFD_ST_SUBSTATE_COUNT(85,0);
          _SFD_ST_SUBSTATE_COUNT(86,0);
          _SFD_ST_SUBSTATE_COUNT(87,0);
          _SFD_ST_SUBSTATE_COUNT(88,0);
          _SFD_ST_SUBSTATE_COUNT(94,12);
          _SFD_ST_SUBSTATE_INDEX(94,0,95);
          _SFD_ST_SUBSTATE_INDEX(94,1,96);
          _SFD_ST_SUBSTATE_INDEX(94,2,97);
          _SFD_ST_SUBSTATE_INDEX(94,3,98);
          _SFD_ST_SUBSTATE_INDEX(94,4,99);
          _SFD_ST_SUBSTATE_INDEX(94,5,100);
          _SFD_ST_SUBSTATE_INDEX(94,6,101);
          _SFD_ST_SUBSTATE_INDEX(94,7,102);
          _SFD_ST_SUBSTATE_INDEX(94,8,103);
          _SFD_ST_SUBSTATE_INDEX(94,9,104);
          _SFD_ST_SUBSTATE_INDEX(94,10,105);
          _SFD_ST_SUBSTATE_INDEX(94,11,106);
          _SFD_ST_SUBSTATE_COUNT(95,0);
          _SFD_ST_SUBSTATE_COUNT(96,0);
          _SFD_ST_SUBSTATE_COUNT(97,0);
          _SFD_ST_SUBSTATE_COUNT(98,0);
          _SFD_ST_SUBSTATE_COUNT(99,0);
          _SFD_ST_SUBSTATE_COUNT(100,0);
          _SFD_ST_SUBSTATE_COUNT(101,0);
          _SFD_ST_SUBSTATE_COUNT(102,0);
          _SFD_ST_SUBSTATE_COUNT(103,0);
          _SFD_ST_SUBSTATE_COUNT(104,0);
          _SFD_ST_SUBSTATE_COUNT(105,0);
          _SFD_ST_SUBSTATE_COUNT(106,0);
          _SFD_ST_SUBSTATE_COUNT(112,12);
          _SFD_ST_SUBSTATE_INDEX(112,0,113);
          _SFD_ST_SUBSTATE_INDEX(112,1,114);
          _SFD_ST_SUBSTATE_INDEX(112,2,115);
          _SFD_ST_SUBSTATE_INDEX(112,3,116);
          _SFD_ST_SUBSTATE_INDEX(112,4,117);
          _SFD_ST_SUBSTATE_INDEX(112,5,118);
          _SFD_ST_SUBSTATE_INDEX(112,6,119);
          _SFD_ST_SUBSTATE_INDEX(112,7,120);
          _SFD_ST_SUBSTATE_INDEX(112,8,121);
          _SFD_ST_SUBSTATE_INDEX(112,9,122);
          _SFD_ST_SUBSTATE_INDEX(112,10,123);
          _SFD_ST_SUBSTATE_INDEX(112,11,124);
          _SFD_ST_SUBSTATE_COUNT(113,0);
          _SFD_ST_SUBSTATE_COUNT(114,0);
          _SFD_ST_SUBSTATE_COUNT(115,0);
          _SFD_ST_SUBSTATE_COUNT(116,0);
          _SFD_ST_SUBSTATE_COUNT(117,0);
          _SFD_ST_SUBSTATE_COUNT(118,0);
          _SFD_ST_SUBSTATE_COUNT(119,0);
          _SFD_ST_SUBSTATE_COUNT(120,0);
          _SFD_ST_SUBSTATE_COUNT(121,0);
          _SFD_ST_SUBSTATE_COUNT(122,0);
          _SFD_ST_SUBSTATE_COUNT(123,0);
          _SFD_ST_SUBSTATE_COUNT(124,0);
        }

        _SFD_CV_INIT_CHART(21,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,8,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,8,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,8,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,8,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(36,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(37,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(44,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(45,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(46,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(47,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(48,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(49,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(50,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(51,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(52,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(53,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(54,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(55,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(56,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(57,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(58,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(59,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(60,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(61,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(62,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(63,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(64,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(65,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(66,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(67,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(68,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(69,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(70,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(71,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(72,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(73,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(74,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(75,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(76,12,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(77,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(78,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(79,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(80,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(81,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(82,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(83,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(84,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(85,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(86,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(87,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(88,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(89,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(90,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(91,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(92,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(93,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(94,12,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(95,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(96,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(97,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(98,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(99,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(100,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(101,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(102,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(103,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(104,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(105,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(106,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(107,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(108,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(109,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(110,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(111,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(112,12,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(113,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(114,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(115,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(116,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(117,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(118,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(119,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(120,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(121,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(122,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(123,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(124,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(125,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(126,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(127,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(128,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(129,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(130,12,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(131,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(132,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(133,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(134,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(135,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(136,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(137,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(138,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(139,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(140,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(141,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(142,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(143,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(144,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(145,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(146,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(147,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(148,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(150,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(151,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(153,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(149,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(152,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(82,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(85,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(86,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(83,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 11 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(84,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 11 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(147,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(144,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(110,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(111,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(112,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(113,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(114,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(115,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(116,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(117,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(118,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(119,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(120,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(143,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(21,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(18,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(12,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(109,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(13,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(14,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(16,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(149,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(148,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(45,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(43,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(42,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(41,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(40,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(51,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(49,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(48,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(47,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(46,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(63,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(61,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(60,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(59,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(58,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(64,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(65,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(66,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(67,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(69,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(57,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(55,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(54,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(53,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(52,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(24,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(22,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(39,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(37,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(36,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(35,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(146,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(132,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(133,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(134,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(135,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(136,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(137,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(138,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(139,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(140,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(141,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(142,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(145,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(121,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(122,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(123,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(124,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(125,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(126,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(127,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(128,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(129,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(130,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(131,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(31,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(30,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(29,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(81,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(80,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(79,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(78,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(77,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(76,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(108,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(107,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(106,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(105,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(104,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_TRANS(103,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(102,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(101,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(100,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(99,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(70,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(71,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(72,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(73,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(74,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(75,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(87,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(88,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(89,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(90,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(91,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(92,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(93,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(94,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(95,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(96,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(97,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(98,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(150,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(151,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(152,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(153,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(154,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(155,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(156,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(157,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(158,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(159,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(160,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(161,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(162,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(163,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(164,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(165,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(166,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(167,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_TRANS(168,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(169,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(170,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(171,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(172,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(173,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(174,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(175,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(176,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(177,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(178,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(179,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(180,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(181,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(182,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(183,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(184,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(185,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(186,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(187,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(188,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(189,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(190,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(191,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_TRANS(192,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(193,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(194,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(195,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(196,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(197,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(198,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(199,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(200,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(201,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(202,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(203,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(204,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(205,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(206,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(207,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(208,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(209,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(210,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(211,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(212,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(213,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(214,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(215,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_TRANS(216,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(217,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(218,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(219,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(220,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(221,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(149,1,1,2,0,0,0,1,0,4,2);
        _SFD_CV_INIT_EML_FCN(149,0,"CalDistance",0,-1,294);
        _SFD_CV_INIT_EML_IF(149,1,0,87,116,-1,280);
        _SFD_CV_INIT_EML_IF(149,1,1,147,204,-1,272);
        _SFD_CV_INIT_EML_FOR(149,1,0,24,40,284);

        {
          static int condStart[] = { 90, 100 };

          static int condEnd[] = { 96, 116 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(149,1,0,90,116,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 150, 188 };

          static int condEnd[] = { 184, 204 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(149,1,1,150,204,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(152,1,1,4,0,0,0,1,0,4,2);
        _SFD_CV_INIT_EML_FCN(152,0,"stopDecision",0,-1,482);
        _SFD_CV_INIT_EML_IF(152,1,0,77,115,-1,435);
        _SFD_CV_INIT_EML_IF(152,1,1,189,211,-1,416);
        _SFD_CV_INIT_EML_IF(152,1,2,228,239,-1,400);
        _SFD_CV_INIT_EML_IF(152,1,3,441,455,-1,480);
        _SFD_CV_INIT_EML_FOR(152,1,0,57,73,439);

        {
          static int condStart[] = { 80, 93 };

          static int condEnd[] = { 89, 115 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(152,1,0,80,115,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 192, 205 };

          static int condEnd[] = { 201, 211 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(152,1,1,192,211,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(82,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(82,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(85,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(85,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(86,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(86,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(83,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(83,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(84,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 11 };

          _SFD_TRANS_COV_MAPS(84,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(147,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 11 };

          _SFD_TRANS_COV_MAPS(147,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(144,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          _SFD_TRANS_COV_MAPS(144,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(110,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          _SFD_TRANS_COV_MAPS(110,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(111,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(111,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(112,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(112,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(113,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(113,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(114,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(114,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(115,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(115,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(116,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(116,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(117,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(117,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(118,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(118,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(119,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(119,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(120,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          _SFD_TRANS_COV_MAPS(120,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(143,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          _SFD_TRANS_COV_MAPS(143,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(21,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          _SFD_TRANS_COV_MAPS(21,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(20,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(20,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(17,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(17,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(18,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(18,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(12,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(12,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(19,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(19,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(109,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(109,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(13,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(13,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(15,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(15,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(14,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(14,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(16,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          _SFD_TRANS_COV_MAPS(16,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(149,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(149,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(28,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(28,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(11,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(11,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(44,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(44,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(148,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(148,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(45,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(45,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(43,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(43,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(42,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(42,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(41,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(41,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(40,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(40,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(51,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(51,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(50,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(50,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(49,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(49,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(48,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(48,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(47,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(47,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(46,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(46,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(63,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(63,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(62,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(62,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(61,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(61,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(60,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(60,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(59,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(59,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(58,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(58,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(64,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(64,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(65,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(65,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(66,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(66,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(67,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          _SFD_TRANS_COV_MAPS(67,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(68,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(68,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(69,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(69,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(57,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(57,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(56,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(56,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(55,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(55,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(54,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(54,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(53,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(53,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(52,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(52,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(10,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(10,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(8,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(8,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(9,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(9,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(7,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(7,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(27,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(27,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(26,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(26,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(25,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(25,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(24,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(24,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(23,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(23,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(22,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(22,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(39,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(39,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(38,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(38,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(37,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(37,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(36,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(36,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(35,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(35,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(146,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          _SFD_TRANS_COV_MAPS(146,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(132,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          _SFD_TRANS_COV_MAPS(132,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(133,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(133,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(134,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(134,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(135,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(135,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(136,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(136,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(137,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(137,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(138,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(138,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(139,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(139,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(140,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(140,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(141,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(141,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(142,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          _SFD_TRANS_COV_MAPS(142,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(145,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 30 };

          _SFD_TRANS_COV_MAPS(145,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(121,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          _SFD_TRANS_COV_MAPS(121,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(122,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(122,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(123,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(123,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(124,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(124,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(125,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          _SFD_TRANS_COV_MAPS(125,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(126,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(126,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(127,0,2,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(127,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(128,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(128,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(129,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(129,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(130,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 5 };

          _SFD_TRANS_COV_MAPS(130,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(131,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 8 };

          static unsigned int sEndGuardMap[] = { 6, 13 };

          _SFD_TRANS_COV_MAPS(131,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(34,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(34,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(33,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(33,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(32,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(32,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(31,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          _SFD_TRANS_COV_MAPS(31,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(30,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 25 };

          _SFD_TRANS_COV_MAPS(30,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(29,0,1,1,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          _SFD_TRANS_COV_MAPS(29,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(81,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(81,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(80,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(80,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(79,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          _SFD_TRANS_COV_MAPS(79,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(78,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(78,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(77,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(77,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(76,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(76,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(108,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(108,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(107,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(107,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(106,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(106,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(105,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          _SFD_TRANS_COV_MAPS(105,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(104,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(104,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(103,0,4,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          _SFD_TRANS_COV_MAPS(103,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(102,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(102,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(101,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(101,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(100,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(100,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(99,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(99,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(70,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(70,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(71,0,1,0,1);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(71,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              1,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(72,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(72,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(73,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 21 };

          _SFD_TRANS_COV_MAPS(73,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(74,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(74,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(75,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(75,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(87,0,0,7,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(87,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              7,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(88,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(88,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(89,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(89,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(90,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(90,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(91,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(91,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(92,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(92,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(93,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(93,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(94,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(94,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(95,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          _SFD_TRANS_COV_MAPS(95,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(96,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(96,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(97,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(97,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(98,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(98,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(150,0,0,7,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(150,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              7,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(151,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(151,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(152,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(152,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(153,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(153,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(154,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(154,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(155,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(155,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(156,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(156,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(157,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(157,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(158,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(158,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(159,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(159,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(160,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          _SFD_TRANS_COV_MAPS(160,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(161,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(161,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(162,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(162,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(163,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(163,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(164,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(164,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(165,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(165,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(166,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(166,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(167,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(167,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(168,0,4,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          _SFD_TRANS_COV_MAPS(168,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(169,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(169,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(170,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          _SFD_TRANS_COV_MAPS(170,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(171,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(171,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(172,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(172,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(173,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(173,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(174,0,0,7,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(174,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              7,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(175,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(175,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(176,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(176,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(177,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(177,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(178,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(178,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(179,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(179,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(180,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(180,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(181,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(181,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(182,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(182,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(183,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(183,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(184,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          _SFD_TRANS_COV_MAPS(184,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(185,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(185,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(186,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(186,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(187,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(187,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(188,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(188,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(189,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(189,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(190,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(190,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(191,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(191,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(192,0,4,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          _SFD_TRANS_COV_MAPS(192,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(193,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(193,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(194,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          _SFD_TRANS_COV_MAPS(194,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(195,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(195,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(196,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(196,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(197,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(197,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(198,0,0,7,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(198,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              7,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(199,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(199,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(200,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(200,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(201,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(201,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(202,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          _SFD_TRANS_COV_MAPS(202,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(203,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(203,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(204,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(204,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(205,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(205,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(206,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(206,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(207,0,1,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(207,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(208,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          _SFD_TRANS_COV_MAPS(208,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(209,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          _SFD_TRANS_COV_MAPS(209,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(210,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(210,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(211,0,1,2,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(211,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              2,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(212,0,1,3,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          _SFD_TRANS_COV_MAPS(212,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              3,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(213,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(213,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(214,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(214,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(215,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          _SFD_TRANS_COV_MAPS(215,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(216,0,4,1,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 13, 22, 34 };

          static unsigned int sEndGuardMap[] = { 11, 18, 32, 37 };

          _SFD_TRANS_COV_MAPS(216,
                              0,NULL,NULL,
                              4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(217,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 7 };

          static unsigned int sEndGuardMap[] = { 5, 17 };

          _SFD_TRANS_COV_MAPS(217,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(218,0,2,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1, 9 };

          static unsigned int sEndGuardMap[] = { 7, 18 };

          _SFD_TRANS_COV_MAPS(218,
                              0,NULL,NULL,
                              2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(219,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(219,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(220,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          _SFD_TRANS_COV_MAPS(220,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(221,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          _SFD_TRANS_COV_MAPS(221,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)
            c1_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)
            c1_g_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)
            c1_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)
            c1_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_h_sf_marshallOut,(MexInFcnForType)
            c1_h_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(23,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(70,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(79,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(80,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(81,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));

        {
          int32_T *c1_N;
          real_T *c1_t;
          int32_T *c1_i;
          int32_T *c1_tdis;
          int32_T *c1_dis;
          real_T *c1_z;
          real_T *c1_stationid;
          real_T *c1_side;
          int32_T *c1_b_i;
          real_T *c1_v;
          real_T *c1_j;
          real_T *c1_maxv;
          real_T *c1_time;
          int32_T *c1_c_i;
          real_T *c1_distance;
          real_T *c1_acc;
          real_T *c1_b_z;
          real_T *c1_b_stationid;
          real_T *c1_b_side;
          int32_T *c1_d_i;
          real_T *c1_y1;
          real_T *c1_b_y1;
          real_T *c1_b_v;
          real_T *c1_b_j;
          real_T *c1_b_maxv;
          real_T *c1_b_time;
          int32_T *c1_e_i;
          real_T *c1_b_distance;
          real_T *c1_b_acc;
          real_T *c1_c_z;
          real_T *c1_c_stationid;
          real_T *c1_c_side;
          int32_T *c1_f_i;
          real_T *c1_d_z;
          real_T *c1_d_stationid;
          real_T *c1_d_side;
          int32_T *c1_g_i;
          real_T *c1_c_v;
          real_T *c1_c_j;
          real_T *c1_c_maxv;
          real_T *c1_c_time;
          int32_T *c1_h_i;
          real_T *c1_c_distance;
          real_T *c1_c_acc;
          real_T *c1_c_y1;
          real_T *c1_d_v;
          real_T *c1_d_j;
          real_T *c1_d_maxv;
          real_T *c1_d_time;
          int32_T *c1_i_i;
          real_T *c1_d_distance;
          real_T *c1_d_acc;
          real_T *c1_d_y1;
          real_T *c1_y2;
          real_T *c1_b_y2;
          real_T *c1_c_y2;
          real_T *c1_d_y2;
          real_T *c1_e_y2;
          real_T *c1_f_y2;
          real_T *c1_g_y2;
          real_T *c1_h_y2;
          real_T (*c1_v_shutTD)[4];
          real_T (*c1_v_shutPSD)[8];
          real_T (*c1_start)[4];
          real_T (*c1_stop)[4];
          real_T (*c1_openPSD)[8];
          real_T (*c1_closePSD)[8];
          real_T (*c1_distance_out)[4];
          real_T (*c1_Delay)[4];
          real_T (*c1_openTD)[4];
          real_T (*c1_closeTD)[4];
          real_T (*c1_S)[4];
          real_T (*c1_urstart)[4];
          real_T (*c1_urstop)[4];
          real_T (*c1_y1_out)[4];
          real_T (*c1_y2_out)[8];
          real_T (*c1_urstopped)[4];
          int32_T (*c1_dir)[4];
          real_T (*c1_position)[4];
          real_T (*c1_PSDClosed)[8];
          int32_T (*c1_RelevantIndex)[4];
          c1_h_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 28);
          c1_g_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 27);
          c1_f_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 26);
          c1_e_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 25);
          c1_d_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 24);
          c1_c_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 23);
          c1_b_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 22);
          c1_y2 = (real_T *)(ssGetContStates(chartInstance->S) + 21);
          c1_d_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 20);
          c1_d_acc = (real_T *)ssGetDWork(chartInstance->S, 93);
          c1_d_distance = (real_T *)(ssGetContStates(chartInstance->S) + 19);
          c1_i_i = (int32_T *)ssGetDWork(chartInstance->S, 92);
          c1_d_time = (real_T *)(ssGetContStates(chartInstance->S) + 18);
          c1_d_maxv = (real_T *)ssGetDWork(chartInstance->S, 91);
          c1_d_j = (real_T *)ssGetDWork(chartInstance->S, 90);
          c1_d_v = (real_T *)(ssGetContStates(chartInstance->S) + 17);
          c1_c_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 16);
          c1_c_acc = (real_T *)ssGetDWork(chartInstance->S, 89);
          c1_c_distance = (real_T *)(ssGetContStates(chartInstance->S) + 15);
          c1_h_i = (int32_T *)ssGetDWork(chartInstance->S, 88);
          c1_c_time = (real_T *)(ssGetContStates(chartInstance->S) + 14);
          c1_c_maxv = (real_T *)ssGetDWork(chartInstance->S, 87);
          c1_c_j = (real_T *)ssGetDWork(chartInstance->S, 86);
          c1_c_v = (real_T *)(ssGetContStates(chartInstance->S) + 13);
          c1_g_i = (int32_T *)ssGetDWork(chartInstance->S, 85);
          c1_d_side = (real_T *)ssGetDWork(chartInstance->S, 84);
          c1_d_stationid = (real_T *)ssGetDWork(chartInstance->S, 83);
          c1_d_z = (real_T *)(ssGetContStates(chartInstance->S) + 12);
          c1_f_i = (int32_T *)ssGetDWork(chartInstance->S, 82);
          c1_c_side = (real_T *)ssGetDWork(chartInstance->S, 81);
          c1_c_stationid = (real_T *)ssGetDWork(chartInstance->S, 80);
          c1_c_z = (real_T *)(ssGetContStates(chartInstance->S) + 11);
          c1_b_acc = (real_T *)ssGetDWork(chartInstance->S, 79);
          c1_b_distance = (real_T *)(ssGetContStates(chartInstance->S) + 10);
          c1_e_i = (int32_T *)ssGetDWork(chartInstance->S, 78);
          c1_b_time = (real_T *)(ssGetContStates(chartInstance->S) + 9);
          c1_b_maxv = (real_T *)ssGetDWork(chartInstance->S, 77);
          c1_b_j = (real_T *)ssGetDWork(chartInstance->S, 76);
          c1_b_v = (real_T *)(ssGetContStates(chartInstance->S) + 8);
          c1_b_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 7);
          c1_y1 = (real_T *)(ssGetContStates(chartInstance->S) + 6);
          c1_d_i = (int32_T *)ssGetDWork(chartInstance->S, 75);
          c1_b_side = (real_T *)ssGetDWork(chartInstance->S, 74);
          c1_b_stationid = (real_T *)ssGetDWork(chartInstance->S, 73);
          c1_b_z = (real_T *)(ssGetContStates(chartInstance->S) + 5);
          c1_acc = (real_T *)ssGetDWork(chartInstance->S, 72);
          c1_distance = (real_T *)(ssGetContStates(chartInstance->S) + 4);
          c1_c_i = (int32_T *)ssGetDWork(chartInstance->S, 71);
          c1_time = (real_T *)(ssGetContStates(chartInstance->S) + 3);
          c1_maxv = (real_T *)ssGetDWork(chartInstance->S, 70);
          c1_j = (real_T *)ssGetDWork(chartInstance->S, 69);
          c1_v = (real_T *)(ssGetContStates(chartInstance->S) + 2);
          c1_b_i = (int32_T *)ssGetDWork(chartInstance->S, 68);
          c1_side = (real_T *)ssGetDWork(chartInstance->S, 67);
          c1_stationid = (real_T *)ssGetDWork(chartInstance->S, 66);
          c1_z = (real_T *)(ssGetContStates(chartInstance->S) + 1);
          c1_dis = (int32_T *)ssGetDWork(chartInstance->S, 65);
          c1_tdis = (int32_T *)ssGetDWork(chartInstance->S, 64);
          c1_RelevantIndex = (int32_T (*)[4])ssGetDWork(chartInstance->S, 63);
          c1_i = (int32_T *)ssGetDWork(chartInstance->S, 62);
          c1_t = (real_T *)(ssGetContStates(chartInstance->S) + 0);
          c1_PSDClosed = (real_T (*)[8])ssGetDWork(chartInstance->S, 61);
          c1_position = (real_T (*)[4])ssGetDWork(chartInstance->S, 60);
          c1_dir = (int32_T (*)[4])ssGetDWork(chartInstance->S, 59);
          c1_urstopped = (real_T (*)[4])ssGetDWork(chartInstance->S, 58);
          c1_y2_out = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_y1_out = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_N = (int32_T *)ssGetDWork(chartInstance->S, 57);
          c1_urstop = (real_T (*)[4])ssGetDWork(chartInstance->S, 56);
          c1_urstart = (real_T (*)[4])ssGetDWork(chartInstance->S, 55);
          c1_S = (real_T (*)[4])ssGetDWork(chartInstance->S, 54);
          c1_closeTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 53);
          c1_openTD = (real_T (*)[4])ssGetDWork(chartInstance->S, 52);
          c1_Delay = (real_T (*)[4])ssGetDWork(chartInstance->S, 51);
          c1_distance_out = (real_T (*)[4])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c1_closePSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 50);
          c1_openPSD = (real_T (*)[8])ssGetDWork(chartInstance->S, 49);
          c1_stop = (real_T (*)[4])ssGetDWork(chartInstance->S, 48);
          c1_start = (real_T (*)[4])ssGetDWork(chartInstance->S, 47);
          c1_v_shutPSD = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 1);
          c1_v_shutTD = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_v_shutTD);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_v_shutPSD);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_start);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_stop);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_openPSD);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_closePSD);
          _SFD_SET_DATA_VALUE_PTR(6U, *c1_distance_out);
          _SFD_SET_DATA_VALUE_PTR(7U, *c1_Delay);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_openTD);
          _SFD_SET_DATA_VALUE_PTR(9U, *c1_closeTD);
          _SFD_SET_DATA_VALUE_PTR(10U, *c1_S);
          _SFD_SET_DATA_VALUE_PTR(11U, *c1_urstart);
          _SFD_SET_DATA_VALUE_PTR(12U, *c1_urstop);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_N);
          _SFD_SET_DATA_VALUE_PTR(14U, *c1_y1_out);
          _SFD_SET_DATA_VALUE_PTR(15U, *c1_y2_out);
          _SFD_SET_DATA_VALUE_PTR(16U, *c1_urstopped);
          _SFD_SET_DATA_VALUE_PTR(17U, *c1_dir);
          _SFD_SET_DATA_VALUE_PTR(18U, *c1_position);
          _SFD_SET_DATA_VALUE_PTR(19U, *c1_PSDClosed);
          _SFD_SET_DATA_VALUE_PTR(20U, c1_t);
          _SFD_SET_DATA_VALUE_PTR(21U, c1_i);
          _SFD_SET_DATA_VALUE_PTR(22U, *c1_RelevantIndex);
          _SFD_SET_DATA_VALUE_PTR(23U, c1_tdis);
          _SFD_SET_DATA_VALUE_PTR(24U, c1_dis);
          _SFD_SET_DATA_VALUE_PTR(26U, c1_z);
          _SFD_SET_DATA_VALUE_PTR(27U, c1_stationid);
          _SFD_SET_DATA_VALUE_PTR(28U, c1_side);
          _SFD_SET_DATA_VALUE_PTR(29U, c1_b_i);
          _SFD_SET_DATA_VALUE_PTR(30U, c1_v);
          _SFD_SET_DATA_VALUE_PTR(31U, c1_j);
          _SFD_SET_DATA_VALUE_PTR(32U, c1_maxv);
          _SFD_SET_DATA_VALUE_PTR(33U, c1_time);
          _SFD_SET_DATA_VALUE_PTR(34U, c1_c_i);
          _SFD_SET_DATA_VALUE_PTR(35U, c1_distance);
          _SFD_SET_DATA_VALUE_PTR(36U, c1_acc);
          _SFD_SET_DATA_VALUE_PTR(37U, c1_b_z);
          _SFD_SET_DATA_VALUE_PTR(38U, c1_b_stationid);
          _SFD_SET_DATA_VALUE_PTR(39U, c1_b_side);
          _SFD_SET_DATA_VALUE_PTR(40U, c1_d_i);
          _SFD_SET_DATA_VALUE_PTR(41U, c1_y1);
          _SFD_SET_DATA_VALUE_PTR(42U, c1_b_y1);
          _SFD_SET_DATA_VALUE_PTR(43U, c1_b_v);
          _SFD_SET_DATA_VALUE_PTR(44U, c1_b_j);
          _SFD_SET_DATA_VALUE_PTR(45U, c1_b_maxv);
          _SFD_SET_DATA_VALUE_PTR(46U, c1_b_time);
          _SFD_SET_DATA_VALUE_PTR(47U, c1_e_i);
          _SFD_SET_DATA_VALUE_PTR(48U, c1_b_distance);
          _SFD_SET_DATA_VALUE_PTR(49U, c1_b_acc);
          _SFD_SET_DATA_VALUE_PTR(50U, c1_c_z);
          _SFD_SET_DATA_VALUE_PTR(51U, c1_c_stationid);
          _SFD_SET_DATA_VALUE_PTR(52U, c1_c_side);
          _SFD_SET_DATA_VALUE_PTR(53U, c1_f_i);
          _SFD_SET_DATA_VALUE_PTR(54U, c1_d_z);
          _SFD_SET_DATA_VALUE_PTR(55U, c1_d_stationid);
          _SFD_SET_DATA_VALUE_PTR(56U, c1_d_side);
          _SFD_SET_DATA_VALUE_PTR(57U, c1_g_i);
          _SFD_SET_DATA_VALUE_PTR(58U, c1_c_v);
          _SFD_SET_DATA_VALUE_PTR(59U, c1_c_j);
          _SFD_SET_DATA_VALUE_PTR(60U, c1_c_maxv);
          _SFD_SET_DATA_VALUE_PTR(61U, c1_c_time);
          _SFD_SET_DATA_VALUE_PTR(62U, c1_h_i);
          _SFD_SET_DATA_VALUE_PTR(63U, c1_c_distance);
          _SFD_SET_DATA_VALUE_PTR(64U, c1_c_acc);
          _SFD_SET_DATA_VALUE_PTR(65U, c1_c_y1);
          _SFD_SET_DATA_VALUE_PTR(66U, c1_d_v);
          _SFD_SET_DATA_VALUE_PTR(67U, c1_d_j);
          _SFD_SET_DATA_VALUE_PTR(68U, c1_d_maxv);
          _SFD_SET_DATA_VALUE_PTR(69U, c1_d_time);
          _SFD_SET_DATA_VALUE_PTR(70U, c1_i_i);
          _SFD_SET_DATA_VALUE_PTR(71U, c1_d_distance);
          _SFD_SET_DATA_VALUE_PTR(72U, c1_d_acc);
          _SFD_SET_DATA_VALUE_PTR(73U, c1_d_y1);
          _SFD_SET_DATA_VALUE_PTR(74U, c1_y2);
          _SFD_SET_DATA_VALUE_PTR(75U, c1_b_y2);
          _SFD_SET_DATA_VALUE_PTR(76U, c1_c_y2);
          _SFD_SET_DATA_VALUE_PTR(77U, c1_d_y2);
          _SFD_SET_DATA_VALUE_PTR(78U, c1_e_y2);
          _SFD_SET_DATA_VALUE_PTR(79U, c1_f_y2);
          _SFD_SET_DATA_VALUE_PTR(80U, c1_g_y2);
          _SFD_SET_DATA_VALUE_PTR(81U, c1_h_y2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_subwaycontrolsystemMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ANSPwN0kP6tKPTgoG8K0MB";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_subwaycontrolsystem_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_subwaycontrolsystem
    ((SFc1_subwaycontrolsystemInstanceStruct*) chartInstanceVar);
  initialize_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  enable_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  disable_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_zeroCrossings_c1_subwaycontrolsystem(void
  *chartInstanceVar)
{
  zeroCrossings_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_outputs_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  outputs_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_derivatives_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  derivatives_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  sf_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_subwaycontrolsystem(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_subwaycontrolsystem(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_subwaycontrolsystem
    ((SFc1_subwaycontrolsystemInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_subwaycontrolsystem();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_subwaycontrolsystem(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_subwaycontrolsystem();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_subwaycontrolsystem(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_subwaycontrolsystem(S);
}

static void sf_opaque_set_sim_state_c1_subwaycontrolsystem(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_subwaycontrolsystem(S, st);
}

static void sf_opaque_terminate_c1_subwaycontrolsystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_subwaycontrolsystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_subwaycontrolsystem_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_subwaycontrolsystem((SFc1_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_subwaycontrolsystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_subwaycontrolsystem
      ((SFc1_subwaycontrolsystemInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_subwaycontrolsystem_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x10'varName','path'{{T\"is_active_c1_subwaycontrolsystem\",T\"is_active_c1_subwaycontrolsystem\"},{T\"is_UrgentController\",T\"UrgentController.is_UrgentController\"},{T\"is_active_UrgentController\",T\"UrgentController.is_active_UrgentController\"},{T\"is_Controller1\",T\"Controller1.is_Controller1\"},{T\"is_active_Controller1\",T\"Controller1.is_active_Controller1\"},{T\"is_Controller0\",T\"Controller0.is_Controller0\"},{T\"is_active_Controller0\",T\"Controller0.is_active_Controller0\"},{T\"is_Screen_door20\",T\"Screen_door20.is_Screen_door20\"},{T\"is_active_Screen_door20\",T\"Screen_door20.is_active_Screen_door20\"},{T\"is_Screen_door21\",T\"Screen_door21.is_Screen_door21\"}}",
    "100 S1x10'varName','path'{{T\"is_active_Screen_door21\",T\"Screen_door21.is_active_Screen_door21\"},{T\"is_Train0_door\",T\"Train0_door.is_Train0_door\"},{T\"is_active_Train0_door\",T\"Train0_door.is_active_Train0_door\"},{T\"is_Train1_door\",T\"Train1_door.is_Train1_door\"},{T\"is_active_Train1_door\",T\"Train1_door.is_active_Train1_door\"},{T\"is_Screen_door31\",T\"Screen_door31.is_Screen_door31\"},{T\"is_active_Screen_door31\",T\"Screen_door31.is_active_Screen_door31\"},{T\"is_Screen_door30\",T\"Screen_door30.is_Screen_door30\"},{T\"is_active_Screen_door30\",T\"Screen_door30.is_active_Screen_door30\"},{T\"is_Controller3\",T\"Controller3.is_Controller3\"}}",
    "100 S1x10'varName','path'{{T\"is_active_Controller3\",T\"Controller3.is_active_Controller3\"},{T\"is_Controller2\",T\"Controller2.is_Controller2\"},{T\"is_active_Controller2\",T\"Controller2.is_active_Controller2\"},{T\"is_Screen_door00\",T\"Screen_door00.is_Screen_door00\"},{T\"is_active_Screen_door00\",T\"Screen_door00.is_active_Screen_door00\"},{T\"is_Screen_door01\",T\"Screen_door01.is_Screen_door01\"},{T\"is_active_Screen_door01\",T\"Screen_door01.is_active_Screen_door01\"},{T\"is_Screen_door11\",T\"Screen_door11.is_Screen_door11\"},{T\"is_active_Screen_door11\",T\"Screen_door11.is_active_Screen_door11\"},{T\"is_Train2_door\",T\"Train2_door.is_Train2_door\"}}",
    "100 S1x10'varName','path'{{T\"is_active_Train2_door\",T\"Train2_door.is_active_Train2_door\"},{T\"is_Train3\",T\"Train3.is_Train3\"},{T\"is_active_Train3\",T\"Train3.is_active_Train3\"},{T\"is_Train3_door\",T\"Train3_door.is_Train3_door\"},{T\"is_active_Train3_door\",T\"Train3_door.is_active_Train3_door\"},{T\"is_Screen_door10\",T\"Screen_door10.is_Screen_door10\"},{T\"is_active_Screen_door10\",T\"Screen_door10.is_active_Screen_door10\"},{T\"is_Train0\",T\"Train0.is_Train0\"},{T\"is_active_Train0\",T\"Train0.is_active_Train0\"},{T\"is_Train1\",T\"Train1.is_Train1\"}}",
    "100 S1x3'varName','path'{{T\"is_active_Train1\",T\"Train1.is_active_Train1\"},{T\"is_Train2\",T\"Train2.is_Train2\"},{T\"is_active_Train2\",T\"Train2.is_active_Train2\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 43, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"double\",,,,,,M[0],M1x2[1 4]},{T\"double\",,,,,,M[0],M1x2[4 2]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"double\",,,,,,M[0],M1x2[4 2]},{T\"double\",,,,,,M[0],M1x2[1 4]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"double\",,,,,,M[0],M1x2[1 4]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"int32\",,,,,,M[0],M1x2[4 1]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"double\",,,,,,M[0],M1x2[4 1]},{T\"double\",,,,,,M[0],M1x2[4 2]},{T\"int32\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M1x2[1 4]},{T\"int32\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]}}",
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"double\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]},{T\"int32\",,,,,,M[0],M[]},{T\"double\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 94, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 1560899134U, 2209417536U, 66547092U,
    2527300442U };

  return checksum;
}

static void mdlSetWorkWidths_c1_subwaycontrolsystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_subwaycontrolsystem_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2827932642U));
  ssSetChecksum1(S,(1071811351U));
  ssSetChecksum2(S,(1792862400U));
  ssSetChecksum3(S,(1121225607U));
  ssSetNumContStates(S,29);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_subwaycontrolsystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_subwaycontrolsystem(SimStruct *S)
{
  SFc1_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_subwaycontrolsystemInstanceStruct *)malloc(sizeof
    (SFc1_subwaycontrolsystemInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_subwaycontrolsystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_subwaycontrolsystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_subwaycontrolsystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_subwaycontrolsystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_subwaycontrolsystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_subwaycontrolsystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_subwaycontrolsystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_subwaycontrolsystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_subwaycontrolsystem;
  chartInstance->chartInfo.zeroCrossings =
    sf_opaque_zeroCrossings_c1_subwaycontrolsystem;
  chartInstance->chartInfo.outputs = sf_opaque_outputs_c1_subwaycontrolsystem;
  chartInstance->chartInfo.derivatives =
    sf_opaque_derivatives_c1_subwaycontrolsystem;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_subwaycontrolsystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_subwaycontrolsystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_subwaycontrolsystem;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_subwaycontrolsystem;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_subwaycontrolsystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_subwaycontrolsystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_subwaycontrolsystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_subwaycontrolsystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_subwaycontrolsystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
