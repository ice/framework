
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SSS(result, op1, op2, op3) \
	 zephir_concat_sss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SVSS(result, op1, op2, op3, op4) \
	 zephir_concat_svss(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_SVSS(result, op1, op2, op3, op4) \
	 zephir_concat_svss(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 0);
#define ZEPHIR_SCONCAT_SVSV(result, op1, op2, op3, op4) \
	 zephir_concat_svsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, 1);

#define ZEPHIR_CONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 0);
#define ZEPHIR_SCONCAT_SVSVSV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_svsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, 1);

#define ZEPHIR_CONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 0);
#define ZEPHIR_SCONCAT_SVSVSVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, 1);

#define ZEPHIR_CONCAT_SVSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvsvsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, 0);
#define ZEPHIR_SCONCAT_SVSVSVSVSV(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10) \
	 zephir_concat_svsvsvsvsv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, sizeof(op7)-1, op8, op9, sizeof(op9)-1, op10, 1);

#define ZEPHIR_CONCAT_SVSVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, 0);
#define ZEPHIR_SCONCAT_SVSVSVV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_svsvsvv(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, op6, op7, 1);

#define ZEPHIR_CONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 0);
#define ZEPHIR_SCONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 1);

#define ZEPHIR_CONCAT_SVVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svvsvsvs(result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 0);
#define ZEPHIR_SCONCAT_SVVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_svvsvsvs(result, op1, sizeof(op1)-1, op2, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_VSVSVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, 0);
#define ZEPHIR_SCONCAT_VSVSVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, 1);

#define ZEPHIR_CONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 0);
#define ZEPHIR_SCONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 1);

#define ZEPHIR_CONCAT_VSVVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvvs(result, op1, op2, sizeof(op2)-1, op3, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_VSVVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvvs(result, op1, op2, sizeof(op2)-1, op3, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VVS(result, op1, op2, op3) \
	 zephir_concat_vvs(result, op1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 0);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 1);

#define ZEPHIR_CONCAT_VVVS(result, op1, op2, op3, op4) \
	 zephir_concat_vvvs(result, op1, op2, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VVVS(result, op1, op2, op3, op4) \
	 zephir_concat_vvvs(result, op1, op2, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VVVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvsv(result, op1, op2, op3, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_VVVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvsv(result, op1, op2, op3, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 1);

#define ZEPHIR_CONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(result, op1, op2, op3, op4, op5, 0);
#define ZEPHIR_SCONCAT_VVVVV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vvvvv(result, op1, op2, op3, op4, op5, 1);

#define ZEPHIR_CONCAT_VVVVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vvvvvv(result, op1, op2, op3, op4, op5, op6, 0);
#define ZEPHIR_SCONCAT_VVVVVV(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vvvvvv(result, op1, op2, op3, op4, op5, op6, 1);


void zephir_concat_sss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var);
void zephir_concat_svs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_svss(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, int self_var);
void zephir_concat_svsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var);
void zephir_concat_svsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, int self_var);
void zephir_concat_svsvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, int self_var);
void zephir_concat_svsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, int self_var);
void zephir_concat_svsvsvsvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, zval *op10, int self_var);
void zephir_concat_svsvsvv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, zval *op7, int self_var);
void zephir_concat_svv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, int self_var);
void zephir_concat_svvsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var);
void zephir_concat_vsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, int self_var);
void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, int self_var);
void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, int self_var);
void zephir_concat_vsvsvv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, zval *op6, int self_var);
void zephir_concat_vsvv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, zval *op4, int self_var);
void zephir_concat_vsvvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, zval *op4, const char *op5, uint32_t op5_len, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, int self_var);
void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var);
void zephir_concat_vvvs(zval *result, zval *op1, zval *op2, zval *op3, const char *op4, uint32_t op4_len, int self_var);
void zephir_concat_vvvsv(zval *result, zval *op1, zval *op2, zval *op3, const char *op4, uint32_t op4_len, zval *op5, int self_var);
void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_vvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, int self_var);
void zephir_concat_vvvvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, zval *op5, zval *op6, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
