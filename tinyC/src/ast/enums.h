#ifndef _ENUMS_H_
#define _ENUMS_H_

enum BuiltInFunct {
    FN_TIMECLOCK,
    FN_RANDSEED,
    FN_RANDINT
};

enum ExprKind {
  LT_EXPR,
  LTE_EXPR,
  GT_EXPR,
  GTE_EXPR,
  NE_EXPR,
  EQ_EXPR,
  ADD_EXPR,
  SUB_EXPR,
  MULT_EXPR,
  DIV_EXPR,
  MOD_EXPR,
  EXPT_EXPR,
  NUM_EXPR,
  ID_EXPR,
  STRING_EXPR,
  INPUT_EXPR,
  CALL_EXPR,
  CHAR_EXPR,
  TERNARY_EXPR,
  ASSIGN_EXPR,
  MULT_ASSIGN_EXPR,
  DIV_ASSIGN_EXPR,
  MOD_ASSIGN_EXPR,
  ADD_ASSIGN_EXPR,
  SUB_ASSIGN_EXPR,
  LEFT_ASSIGN_EXPR,
  RIGHT_ASSIGN_EXPR,
  AND_ASSIGN_EXPR,
  XOR_ASSIGN_EXPR,
  OR_ASSIGN_EXPR,
  SHIFT_LEFT_EXPR,
  SHIFT_RIGHT_EXPR,
  BIT_AND_EXPR,
  XOR_EXPR,
  BIT_OR_EXPR,
  AND_EXPR,
  OR_EXPR,
  ACCESS_ARRAY_EXPR,
  CALL_FUNC_EXPR,
  POST_INC_EXPR,
  POST_DEC_EXPR,
  PRE_INC_EXPR,
  PRE_DEC_EXPR,
  POSITIVE_NUM_EXPR,
  NEGATIVE_NUM_EXPR,
  BIT_NOT_EXPR,
  LOGIC_NOT_EXPR,
  SIZEOF_EXPR,
  SIZEOF_TYPE_EXPR,
  LOGIC_OR_EXPR,
  LOGIC_AND_EXPR
};

enum SemanticValidType
{
    INT_TYPE,
    CHAR_TYPE,
    VOID_TYPE,
    ARRAY_INT_TYPE,
    ARRAY_CHAR_TYPE,
    STRING_TYPE
};

enum StatementKind {
    BLOCK_STATEMENT,
    PRINT_STATEMENT,
    ASSIGN_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    PASS_STATEMENT,
    CALL_STATEMENT,
    VAR_DEC_STATEMENT,
    FUNC_DEC_STATEMENT
};

enum DeclaratorKind
{
  ID_K,
  ARRAY,
  FUNC_PROTOTYPE
};

#endif