#ifndef __c2_subwaycontrolsystem_h__
#define __c2_subwaycontrolsystem_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc2_subwaycontrolsystemInstanceStruct
#define typedef_SFc2_subwaycontrolsystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc2_subwaycontrolsystemInstanceStruct;

#endif                                 /*typedef_SFc2_subwaycontrolsystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_subwaycontrolsystem_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_subwaycontrolsystem_get_check_sum(mxArray *plhs[]);
extern void c2_subwaycontrolsystem_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
