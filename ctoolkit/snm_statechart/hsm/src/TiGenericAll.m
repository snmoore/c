/* *************************************************************************** */
/* ************************ ADD CLASS INT MACROS FILES *********************** */
/* *************************************************************************** */

#include "c_ui_general/src/MuiApplicationInt.m"
#include "c_ui_general/src/MuiEnterPinCodeInt.m"
#include "c_ui_general/src/MuiVerifyPinInt.m"
#include "c_ui_general/src/MuiDisplayMessageInt.m"
#include "c_ui_general/src/MuiFileSelectorDlgInt.m"
/* 05/12/03 Cosmobic Philip Added new class for VT call for VTB-616. (Start) */
#include "c_ui_general/src/MuiVideoCallInt.m"
/* 05/12/03 Cosmobic Philip Added new class for VT call for VTB-616. (End)   */

#ifndef WIN32
#include "c_ui_general/src/MuiAppIconsInt.m"
#include "c_ui_general/src/MuiAppKeyPadInt.m"
#endif

#include "c_ui_phonebook/src/MuiPhoneBookInterfaceInt.m"
#include "c_ui_phonebook/src/MuiPbkGetResourceInt.m"
#include "c_ui_phonebook/src/MuiPbkViewInt.m"
#include "c_ui_phonebook/src/MuiPbkSearchInt.m"
#include "c_ui_phonebook/src/MuiPbkStatusInt.m"
#include "c_ui_phonebook/src/MuiPbkCreateInt.m"
#include "c_ui_phonebook/src/MuiPbkSelectLocationInt.m"
#include "c_ui_phonebook/src/MuiEnterDetailsInt.m"
#include "c_ui_phonebook/src/MuiPbkDeleteInt.m"
#include "c_ui_phonebook/src/MuiPbkEditInt.m"
#include "c_ui_phonebook/src/MuiPbkMoveCopyInt.m"
#include "c_ui_phonebook/src/MuiPbkSwapInt.m"
#include "c_ui_phonebook/src/MuiPbkGroupsInt.m"
#include "c_ui_phonebook/src/MuiPbkGroupEditInt.m"
#include "c_ui_phonebook/src/PhoneBookInterfaceInt.m"
#include "c_ui_phonebook/src/MuiPbkAttributesInt.m"
#include "c_ui_phonebook/src/MuiPbkDmApiInt.m"
#include "c_ui_phonebook/src/MuiPbkProfilesInt.m"

#include "c_ui_pow/src/MuiPowerInterfaceInt.m"
#include "c_ui_pow/src/MuiPowerUpInt.m"
#include "c_ui_pow/src/MuiPowerDownInt.m"
#include "c_ui_pow/src/MuiRestoreDefaultsInt.m"

#include "c_ui_voicecalls/src/MuiVoiceCallsInterfaceInt.m"
#include "c_ui_voicecalls/src/MuiAppCallClearingInt.m"
#include "c_ui_voicecalls/src/MuiAppCallTimerInt.m"

#include "c_ui_ss/src/MuiSsInterfaceInt.m"
#include "c_ui_ss/src/MuiBarringInt.m"
#include "c_ui_ss/src/MuiDivertInt.m"
#include "c_ui_ss/src/MuiCwInt.m"
#include "c_ui_ss/src/MuiClirInt.m"
#include "c_ui_ss/src/MuiUnsolicitedSsInt.m"
#include "c_ui_ss/src/MuiUnsolicitedSsParentInt.m"
#include "c_ui_ss/src/MuiPssInt.m"
#include "c_ui_ss/harness/MuiPssTestHarnessInt.m"
#include "c_ui_ss/src/MuiSsLibInt.m"
#include "c_ui_ss/src/MuiAutocheckInt.m"
#include "c_ui_ss/src/MuiCallInfoInt.m"

#include "c_ui_idle/src/MuiIdleInterfaceInt.m"
#include "c_ui_idle/src/MuiEmergencyCallInt.m"
#include "c_ui_idle/src/MuiModeInt.m"

#include "c_ui_data_calls/src/MuiDataCallsInterfaceInt.m"
#include "c_ui_data_calls/src/MuiDatacallsInt.m"
#include "c_ui_data_calls/src/MuiCallDeflectionInt.m"
#include "c_ui_data_calls/src/MuiDataSettingsInt.m"
#include "c_ui_data_calls/src/MuiDataAlarmInt.m"
#include "c_ui_data_calls/src/MuiDataCallsApnsAccessInt.m"

#include "c_ui_voicemail/src/MuiAppVoiceMailMenuInt.m"
#include "c_ui_voicemail/src/MuiAppVoiceMailDialOnDeliveryInt.m"

#include "c_ui_call_logs/src/MuiCallLogsInterfaceInt.m"
#include "c_ui_sat_app/src/SataPerformCmdsInt.m"
#include "c_ui_sat_app/src/SataSetupMenuInt.m"
#include "c_ui_sat_app/src/SataSelectItemInt.m"
#include "c_ui_sat_app/src/SataSetupEventlistInt.m"
#include "c_ui_sat_app/src/SataSetupIdleModeTextInt.m"
#include "c_ui_sat_app/src/SataSendSmsInt.m"
#include "c_ui_sat_app/src/SataDttPltInt.m"
#include "c_ui_sat_app/src/MuiSatInterfaceInt.m"
#include "c_ui_sat_app/src/SataGetInputInkeyInt.m"
#include "c_ui_sat_app/src/SataMoreTimeInt.m"
#include "c_ui_sat_app/src/SataGetFocusInt.m"
#include "c_ui_sat_app/src/SataEnvelopeInt.m"
#include "c_ui_sat_app/src/SataRefreshInt.m"
#include "c_ui_sat_app/src/SataSendDtmfInt.m"
#include "c_ui_sat_app/src/SataCallControlInt.m"


#include "c_ui_nwrk_reg/harness/UttTestNwrkInt.m"
#include "c_ui_nwrk_reg/src/MuiNwrkRegInterfaceInt.m"
#include "c_ui_nwrk_reg/src/MuiNwrkRegPrefPlmnInt.m"
#include "c_ui_nwrk_reg/src/MuiNwrkRegSelectionInt.m"

#include "c_ui_test/src/MuiTestAppInt.m"

#include "c_ui_config/src/MuiCntPanelInt.m"
#include "c_ui_config/src/MuiClockInt.m"
#include "c_ui_config/src/MuiModeSelectInt.m"
#include "c_ui_config/src/MuiModeConfigureInt.m"
#include "c_ui_config/src/MuiConfigureInterfaceInt.m"
#include "c_ui_config/harness/TestConfigureInt.m"    /* testing for MODE function */

#include "c_ui_security/src/MuiSecurityPinInterfaceInt.m"
#include "c_ui_security/src/MuiSecurityMenuInt.m"
#include "c_ui_security/src/MuiUpdatePinCodeInt.m"
#include "c_ui_security/src/MuiChangePinCodeInt.m"
#include "c_ui_security/src/MuiDialLockInt.m"
#include "c_ui_security/src/MuiPinVerificationInt.m"
#include "c_ui_security/src/MuiPowerUpChecksInt.m"
#include "c_ui_security/src/MuiPinEnableControlInt.m"
#include "c_ui_security/src/MuiSecurityInterfaceInt.m"
#include "c_ui_security/harness/MuiSecurityTestInt.m" /* Testing for Security */

#include "c_ui_als/src/MuiAppAlsMenuInt.m"
#include "c_ui_als/src/MuiAlsInterfaceInt.m"
#include "c_ui_lcs/src/MuiLcsInt.m"

/* *******************************************************************
**  LISA STATE MACHINES
** **************************************************************** */

#include "c_sl_network_reg/src/SlCsregistrationInt.m"
#include "c_sl_network_reg/src/SlRxlevelInt.m"
#include "c_sl_network_reg/src/SlPlmnbuilderInt.m"

#include "c_xx_test/src/SmTestInt.m"


/* SAT Server addition */
#include "c_ap_sat_server/src/SatsPcmdSessionInt.m"
#include "c_ap_sat_server/src/SatsPerformPcommandsInt.m"


#include "c_sl_security/src/ScsVerifyPhoneCodeInt.m"

//#include "c_sm_app_manager/src/SmApmApplicationInt.m"
//#include "c_sm_app_manager/src/SmApplicationManagerInt.m"

/* PS simulator */
#include "c_ps_layer3_simulator/src/PssCallInt.m"
#include "c_ps_layer3_simulator/src/PssCallControlInt.m"
#include "c_ps_layer3_simulator/src/PssNwrkServiceInt.m"
#include "c_ps_layer3_simulator/src/PssNwrkRxlevelInt.m"


#include "c_pl_ppp/src/c_ppp_manager/src/PppManagerInt.m"
#include "c_pl_ppp/src/c_ppp_fsm/src/PppCtrlProtFsmInt.m"
#include "c_pl_ppp/src/c_ppp_pap/src/PppPapInt.m"
#include "c_pl_ppp/src/c_ppp_chap/src/PppChapInt.m"

/* OMP addition */
#include "c_pl_omp/src/OmpL1Int.m"
#include "c_pl_omp/src/OmpL2Int.m"
#include "c_pl_omp/src/OmpL3Int.m"
#include "c_pl_omp/src/OmpConfigInt.m"
#include "c_pl_omp/src/OmpScmInt.m"
#include "c_pl_omp/src/OmpScmsearchInt.m"
#include "c_pl_omp/src/OmpStcontrolInt.m"


/* AoC addition */
#include "c_sl_connection/src/CnmAocInt.m"


#include "../../anf_poc/src/c_dr_udp_recv/src/UdpSockRecvCoreInt.m"