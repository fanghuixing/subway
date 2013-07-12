/* Include files */

#include "blascompat32.h"
#include "subwaycontrolsystem_sfun.h"
#include "c2_subwaycontrolsystem.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "subwaycontrolsystem_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "j", "k", "nargin", "nargout",
  "u", "y" };

/* Function Declarations */
static void initialize_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void initialize_params_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void enable_c2_subwaycontrolsystem(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance);
static void disable_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void ext_mode_exec_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void set_sim_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void sf_c2_subwaycontrolsystem(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance);
static void initSimStructsc2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[8]);
static void c2_b_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_subwaycontrolsystem, const
  char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_subwaycontrolsystem;
  c2_is_active_c2_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_subwaycontrolsystem = 0U;
}

static void initialize_params_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void enable_c2_subwaycontrolsystem(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_subwaycontrolsystem(chartInstance);
}

static const mxArray *get_sim_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[8];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T *c2_is_active_c2_subwaycontrolsystem;
  real_T (*c2_d_y)[8];
  c2_d_y = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 8; c2_i0++) {
    c2_u[c2_i0] = (*c2_d_y)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_is_active_c2_subwaycontrolsystem;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[8];
  int32_T c2_i1;
  boolean_T *c2_doneDoubleBufferReInit;
  uint8_T *c2_is_active_c2_subwaycontrolsystem;
  real_T (*c2_y)[8];
  c2_y = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_subwaycontrolsystem = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 8; c2_i1++) {
    (*c2_y)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_is_active_c2_subwaycontrolsystem = c2_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_subwaycontrolsystem");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_subwaycontrolsystem(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void sf_c2_subwaycontrolsystem(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T c2_u[8];
  uint32_T c2_debug_family_var_map[6];
  real_T c2_j;
  real_T c2_k;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y[8];
  int32_T c2_i5;
  int32_T c2_i;
  real_T c2_b_i;
  int32_T c2_i6;
  int32_T *c2_sfEvent;
  real_T (*c2_b_y)[8];
  real_T (*c2_b_u)[8];
  c2_b_y = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 8; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_u)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 8; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_y)[c2_i3], 1U);
  }

  *c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 8; c2_i4++) {
    c2_u[c2_i4] = (*c2_b_u)[c2_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_j, 0U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_k, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_u, 4U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_y, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  for (c2_i5 = 0; c2_i5 < 8; c2_i5++) {
    c2_y[c2_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_j = 1.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_k = 1.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 6);
  c2_i = 0;
  while (c2_i < 8) {
    c2_b_i = 1.0 + (real_T)c2_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, *c2_sfEvent, 7);
    c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)_SFD_INTEGER_CHECK("j", c2_j),
           1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("y", (int32_T)
             _SFD_INTEGER_CHECK("k", c2_k), 1, 2, 2, 0) - 1) << 2)) - 1] =
      c2_u[_SFD_EML_ARRAY_BOUNDS_CHECK("u", (int32_T)_SFD_INTEGER_CHECK("i",
      c2_b_i), 1, 8, 1, 0) - 1];
    _SFD_EML_CALL(0U, *c2_sfEvent, 8);
    if (CV_EML_IF(0, 1, 0, c2_k == 2.0)) {
      _SFD_EML_CALL(0U, *c2_sfEvent, 9);
      c2_k = 1.0;
      _SFD_EML_CALL(0U, *c2_sfEvent, 10);
      c2_j++;
    } else {
      _SFD_EML_CALL(0U, *c2_sfEvent, 12);
      c2_k++;
    }

    c2_i++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  for (c2_i6 = 0; c2_i6 < 8; c2_i6++) {
    (*c2_b_y)[c2_i6] = c2_y[c2_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_subwaycontrolsystemMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_subwaycontrolsystem
  (SFc2_subwaycontrolsystemInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  real_T c2_b_inData[8];
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i7 = 0;
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
      c2_b_inData[c2_i9 + c2_i7] = (*(real_T (*)[8])c2_inData)[c2_i9 + c2_i7];
    }

    c2_i7 += 4;
  }

  c2_i10 = 0;
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
      c2_u[c2_i12 + c2_i10] = c2_b_inData[c2_i12 + c2_i10];
    }

    c2_i10 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_y, const char_T *c2_identifier, real_T
  c2_b_y[8])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
}

static void c2_b_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[8])
{
  real_T c2_dv1[8];
  int32_T c2_i13;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c2_i13 = 0; c2_i13 < 8; c2_i13++) {
    c2_y[c2_i13] = c2_dv1[c2_i13];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[8];
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  c2_i14 = 0;
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
      (*(real_T (*)[8])c2_outData)[c2_i16 + c2_i14] = c2_b_y[c2_i16 + c2_i14];
    }

    c2_i14 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i17;
  real_T c2_b_inData[8];
  int32_T c2_i18;
  real_T c2_u[8];
  const mxArray *c2_y = NULL;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i17 = 0; c2_i17 < 8; c2_i17++) {
    c2_b_inData[c2_i17] = (*(real_T (*)[8])c2_inData)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 8; c2_i18++) {
    c2_u[c2_i18] = c2_b_inData[c2_i18];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_subwaycontrolsystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i19;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i19, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i19;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_is_active_c2_subwaycontrolsystem, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_subwaycontrolsystem), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_subwaycontrolsystem);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_subwaycontrolsystemInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_subwaycontrolsystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(441764613U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2468066293U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(248014138U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2452215505U);
}

mxArray *sf_c2_subwaycontrolsystem_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uUW9fvBuZcivOP0I413ORE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_subwaycontrolsystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_subwaycontrolsystem\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_subwaycontrolsystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
    chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_subwaycontrolsystemMachineNumber_,
           2,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,156);
        _SFD_CV_INIT_EML_IF(0,1,0,85,92,125,152);
        _SFD_CV_INIT_EML_FOR(0,1,0,54,64,156);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T (*c2_u)[8];
          real_T (*c2_y)[8];
          c2_y = (real_T (*)[8])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_y);
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
  return "XBkeqmIerf2oq2JfULQ6D";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_subwaycontrolsystem_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 2, "dworkChecksum");
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

static void sf_opaque_initialize_c2_subwaycontrolsystem(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_subwaycontrolsystem
    ((SFc2_subwaycontrolsystemInstanceStruct*) chartInstanceVar);
  initialize_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_subwaycontrolsystem(void *chartInstanceVar)
{
  enable_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_subwaycontrolsystem(void *chartInstanceVar)
{
  disable_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_subwaycontrolsystem(void *chartInstanceVar)
{
  sf_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_subwaycontrolsystem(void
  *chartInstanceVar)
{
  ext_mode_exec_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_subwaycontrolsystem(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_subwaycontrolsystem
    ((SFc2_subwaycontrolsystemInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_subwaycontrolsystem();/* state var info */
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

extern void sf_internal_set_sim_state_c2_subwaycontrolsystem(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_subwaycontrolsystem();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_subwaycontrolsystem(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_subwaycontrolsystem(S);
}

static void sf_opaque_set_sim_state_c2_subwaycontrolsystem(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_subwaycontrolsystem(S, st);
}

static void sf_opaque_terminate_c2_subwaycontrolsystem(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_subwaycontrolsystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_subwaycontrolsystem_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_subwaycontrolsystem((SFc2_subwaycontrolsystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_subwaycontrolsystem(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_subwaycontrolsystem
      ((SFc2_subwaycontrolsystemInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_subwaycontrolsystem_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_subwaycontrolsystem\",T\"is_active_c2_subwaycontrolsystem\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c2_subwaycontrolsystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_subwaycontrolsystem_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4163911660U));
  ssSetChecksum1(S,(866136773U));
  ssSetChecksum2(S,(1072163050U));
  ssSetChecksum3(S,(1381657839U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_subwaycontrolsystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_subwaycontrolsystem(SimStruct *S)
{
  SFc2_subwaycontrolsystemInstanceStruct *chartInstance;
  chartInstance = (SFc2_subwaycontrolsystemInstanceStruct *)malloc(sizeof
    (SFc2_subwaycontrolsystemInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_subwaycontrolsystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_subwaycontrolsystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_subwaycontrolsystem;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_subwaycontrolsystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_subwaycontrolsystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_subwaycontrolsystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_subwaycontrolsystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_subwaycontrolsystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_subwaycontrolsystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_subwaycontrolsystem;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_subwaycontrolsystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_subwaycontrolsystem;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_subwaycontrolsystem;
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

void c2_subwaycontrolsystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_subwaycontrolsystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_subwaycontrolsystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_subwaycontrolsystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_subwaycontrolsystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
