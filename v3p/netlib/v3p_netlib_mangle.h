#ifndef v3p_netlib_mangle_h
#define v3p_netlib_mangle_h

/*

This header file mangles all symbols exported from the v3p_netlib
library.  It is included in all files while building the library.

The following command was used to obtain the symbol list:

nm libv3p_netlib.a |grep " [TR] "

*/

/* Functions */

#define balanc_ v3p_netlib_balanc_
#define balbak_ v3p_netlib_balbak_
#define caxpy_ v3p_netlib_caxpy_
#define ccopy_ v3p_netlib_ccopy_
#define cdiv_ v3p_netlib_cdiv_
#define cdotc_ v3p_netlib_cdotc_
#define cqrdc_ v3p_netlib_cqrdc_
#define cqrsl_ v3p_netlib_cqrsl_
#define cscal_ v3p_netlib_cscal_
#define csrot_ v3p_netlib_csrot_
#define csvdc_ v3p_netlib_csvdc_
#define cswap_ v3p_netlib_cswap_
#define dasum_ v3p_netlib_dasum_
#define daxpy_ v3p_netlib_daxpy_
#define dcabs1_ v3p_netlib_dcabs1_
#define dcopy_ v3p_netlib_dcopy_
#define ddot_ v3p_netlib_ddot_
#define dgpfa2f_ v3p_netlib_dgpfa2f_
#define dgpfa3f_ v3p_netlib_dgpfa3f_
#define dgpfa5f_ v3p_netlib_dgpfa5f_
#define dgpfa_ v3p_netlib_dgpfa_
#define dlabax_ v3p_netlib_dlabax_
#define dlabcm_ v3p_netlib_dlabcm_
#define dlabfc_ v3p_netlib_dlabfc_
#define dlaeig_ v3p_netlib_dlaeig_
#define dlager_ v3p_netlib_dlager_
#define dlaran_ v3p_netlib_dlaran_
#define dmvpc_ v3p_netlib_dmvpc_
#define dnlaso_ v3p_netlib_dnlaso_
#define dnppla_ v3p_netlib_dnppla_
#define dnrm2_ v3p_netlib_dnrm2_
#define dnwla_ v3p_netlib_dnwla_
#define dortqr_ v3p_netlib_dortqr_
#define dpoco_ v3p_netlib_dpoco_
#define dpodi_ v3p_netlib_dpodi_
#define dpofa_ v3p_netlib_dpofa_
#define dposl_ v3p_netlib_dposl_
#define dqrdc_ v3p_netlib_dqrdc_
#define dqrsl_ v3p_netlib_dqrsl_
#define drot_ v3p_netlib_drot_
#define drotg_ v3p_netlib_drotg_
#define dscal_ v3p_netlib_dscal_
#define dsvdc_ v3p_netlib_dsvdc_
#define dswap_ v3p_netlib_dswap_
#define dvsort_ v3p_netlib_dvsort_
#define dznrm2_ v3p_netlib_dznrm2_
#define elmhes_ v3p_netlib_elmhes_
#define eltran_ v3p_netlib_eltran_
#define epslon_ v3p_netlib_epslon_
#define gpfa2f_ v3p_netlib_gpfa2f_
#define gpfa3f_ v3p_netlib_gpfa3f_
#define gpfa5f_ v3p_netlib_gpfa5f_
#define gpfa_ v3p_netlib_gpfa_
#define hqr2_ v3p_netlib_hqr2_
#define hqr_ v3p_netlib_hqr_
#define pythag_ v3p_netlib_pythag_
#define rebak_ v3p_netlib_rebak_
#define reduc_ v3p_netlib_reduc_
#define rg_ v3p_netlib_rg_
#define rs_ v3p_netlib_rs_
#define rsg_ v3p_netlib_rsg_
#define saxpy_ v3p_netlib_saxpy_
#define scnrm2_ v3p_netlib_scnrm2_
#define scopy_ v3p_netlib_scopy_
#define sdot_ v3p_netlib_sdot_
#define setdgpfa_ v3p_netlib_setdgpfa_
#define setgpfa_ v3p_netlib_setgpfa_
#define snrm2_ v3p_netlib_snrm2_
#define sqrdc_ v3p_netlib_sqrdc_
#define sqrsl_ v3p_netlib_sqrsl_
#define srot_ v3p_netlib_srot_
#define srotg_ v3p_netlib_srotg_
#define sscal_ v3p_netlib_sscal_
#define ssvdc_ v3p_netlib_ssvdc_
#define sswap_ v3p_netlib_sswap_
#define tql1_ v3p_netlib_tql1_
#define tql2_ v3p_netlib_tql2_
#define tqlrat_ v3p_netlib_tqlrat_
#define tred1_ v3p_netlib_tred1_
#define tred2_ v3p_netlib_tred2_
#define urand_ v3p_netlib_urand_
#define zaxpy_ v3p_netlib_zaxpy_
#define zcopy_ v3p_netlib_zcopy_
#define zdotc_ v3p_netlib_zdotc_
#define zdrot_ v3p_netlib_zdrot_
#define zqrdc_ v3p_netlib_zqrdc_
#define zqrsl_ v3p_netlib_zqrsl_
#define zscal_ v3p_netlib_zscal_
#define zsvdc_ v3p_netlib_zsvdc_
#define zswap_ v3p_netlib_zswap_

#endif
