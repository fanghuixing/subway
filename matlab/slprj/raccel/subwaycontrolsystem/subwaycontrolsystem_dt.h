#include "__cf_subwaycontrolsystem.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . mgreqddwbk
) , 0 , 0 , 32 } , { ( char_T * ) ( & rtDWork . csmhj2mobz ) , 0 , 0 , 85 } ,
{ ( char_T * ) ( & rtDWork . bllphsg2bd . LoggedData ) , 11 , 0 , 2 } , { (
char_T * ) ( & rtDWork . jxt0tifn1m ) , 6 , 0 , 22 } , { ( char_T * ) ( &
rtDWork . cj4jryemsn ) , 3 , 0 , 44 } , { ( char_T * ) ( & rtDWork .
fwktsfwhv4 ) , 8 , 0 , 4 } } ; static DataTypeTransitionTable rtBTransTable =
{ 6U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . b3_Value ) , 0 , 0 , 24 } , { ( char_T * ) ( & rtP .
TDV_CurrentSetting ) , 3 , 0 , 12 } } ; static DataTypeTransitionTable
rtPTransTable = { 2U , rtPTransitions } ;
