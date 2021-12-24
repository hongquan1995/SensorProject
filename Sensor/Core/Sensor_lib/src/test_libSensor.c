/*
 * test_libSensor.c
 *
 *  Created on: Oct 19, 2021
 *      Author: 0
 */

#include "SOIL_MTEC.h"
#include "my_lib.h"
#include "NH3.h"
#include "CO2.h"
#include "EC_TDS.h"
#include "H2S.h"
#include "PAR.h"
#include "PH.h"
#include "TURB.h"
#include "CHLOR.h"
#include "ParseModbus.h"
#include "test_libSensor.h"
uint8_t ret;
read_sensorCO2_t dat_Co2;
read_sensorEcTds_t dat_ectds;
read_sensorH2S_t dat_h2s;
read_sensornNH3_t dat_nh3;
read_sensorPh_t dat_ph;
read_sensorMtec_t dat_mtec;
read_sensorTurb_t dat_turb;
read_sensorChlor_t dat_chlor;
extern float dataPAR;
extern SENSORS Chlorine[];
extern SENSORS Turbidity[];
extern SENSORS PH[];

void test_CO2(){
	  ret = getCO2(&dat_Co2.vr_CO2);
	  ret = getVERCO2(&dat_Co2.vr_hardVer, &dat_Co2.vr_softVer);
	  ret = getModSlaveAddCO2(&dat_Co2.vr_modSlave);
	  ret = getBaudRateCO2(&dat_Co2.vr_baudrate);
	  ret = getParityCO2(&dat_Co2.vr_parityBits);
	  ret = getStopBitsCO2(&dat_Co2.vr_stopBits);
	  ret = getModProtocolCO2(&dat_Co2.vr_modProtocol);
	  ret = getDelayResponseCO2(&dat_Co2.vr_delayResponse);
	  ret = getWarmUpTimeCO2(&dat_Co2.vr_warmUptime);
}

void test_ECTDS(){
	  ret = getECTDSTemp(&dat_ectds.vr_temp);
	  ret = getECTDSElectricalCond(&dat_ectds.vr_eletrCond);
	  ret = getECTDSalinity(&dat_ectds.vr_salinity);
	  ret = getTDS(&dat_ectds.vr_tds);
	  ret = getEcrawad(&dat_ectds.vr_ecrawad);
	  ret = getECTDSTempCompen(&dat_ectds.vr_tempCompen);
	  ret = getEcTempCoff(&dat_ectds.vr_tempCoff);
	  ret = getECTDSalinitycoff(&dat_ectds.vr_salinitycoff);
	  ret = getTDSCoff(&dat_ectds.vr_TdsCoff);
	  ret = getECTDSelectroConst(&dat_ectds.vr_electroConst);
	  ret = getECTDSlaAddress(&dat_ectds.vr_slaAddress);
	  ret = getECTDSBaudrate(&dat_ectds.vr_baudrate);
	  ret = getECTDSProtocol(&dat_ectds.vr_protocol);
	  ret = getECTDSParity(&dat_ectds.vr_parity);
	  ret = getECTDSdatabits(&dat_ectds.vr_databits);
	  ret = getECTDStopbits(&dat_ectds.vr_stopbits);
	  ret = getECTDSResponDelay(&dat_ectds.vr_responDelay);
	  ret = getECTDEAoi(&dat_ectds.vr_aoi);
}

void test_H2S(){
	  ret = getH2STemperatureValue(&dat_h2s.vr_temp);
	  ret = getH2SHumidityValue(&dat_h2s.vr_humi);
	  ret =	getH2S(&dat_h2s.vr_h2s);
	  ret = getH2SMaxrange(&dat_h2s.vr_maxRange);
}

void test_NH3(){
	  ret = getNH3TemperatureValue(&dat_nh3.vr_temp);
	  ret = getNH3HumidityValue(&dat_nh3.vr_humi);
	  ret =	getNH3(&dat_nh3.vr_nh3);
	  ret = getNH3Maxrange(&dat_nh3.vr_maxRange);
}

void test_PAR(){
	  ret = getPAR(&dataPAR);
}

void test_read_ph(){
	ret = getSensorData(PH, 0, (RETURN_VAL*)&dat_ph.vr_temp, RET_FLOAT);
	ret = getSensorData(PH, 1, (RETURN_VAL*)&dat_ph.vr_ph, RET_FLOAT);
	ret = getSensorData(PH, 2, (RETURN_VAL*)&dat_ph.vr_temcomp, RET_U16);
	ret = getSensorData(PH, 3, (RETURN_VAL*)&dat_ph.vr_calibrawad0, RET_I16);
	ret = getSensorData(PH, 4, (RETURN_VAL*)&dat_ph.vr_calibrawad1, RET_I16);
	ret = getSensorData(PH, 5, (RETURN_VAL*)&dat_ph.vr_calibrawad2, RET_I16);
	ret = getSensorData(PH, 6, (RETURN_VAL*)&dat_ph.vr_slaAddress, RET_U16);
	ret = getSensorData(PH, 7, (RETURN_VAL*)&dat_ph.vr_baudrate, RET_U16);
	ret = getSensorData(PH, 8, (RETURN_VAL*)&dat_ph.vr_protocol, RET_U16);
	ret = getSensorData(PH, 9, (RETURN_VAL*)&dat_ph.vr_parity, RET_U16);
	ret = getSensorData(PH, 10, (RETURN_VAL*)&dat_ph.vr_databits, RET_U16);
	ret = getSensorData(PH, 11, (RETURN_VAL*)&dat_ph.vr_stopbits, RET_U16);
	ret = getSensorData(PH, 12, (RETURN_VAL*)&dat_ph.vr_responDelay, RET_U16);
	ret = getSensorData(PH, 13, (RETURN_VAL*)&dat_ph.vr_aoi, RET_U16);
}

//void test_mtec(){
//	ret = getTEMPsoil(&dat_mtec.vr_temp);
//	ret = getVWCsoil(&dat_mtec.vr_vwc);
//	ret = getECsoil(&dat_mtec.vr_ec);
//	ret = getSALINITYsoil(&dat_mtec.vr_salinity);
//	ret = getTDSsoil(&dat_mtec.vr_tds);
//	ret = getEPSILONsoil(&dat_mtec.vr_epsilon);
//	ret = getTEMPUNITsoil(&dat_mtec.vr_tempunit);
//	ret = getECTEMPCOFFsoil(&dat_mtec.vr_ectemcoff);
//	ret = getSALINITYCOFFsoil(&dat_mtec.vr_salinitycoff);
//	ret = getTDSCOFFsoil(&dat_mtec.vr_tdscoff);
//	ret = getSLAVEADDRsoil(&dat_mtec.vr_slaAddress);
//	ret = getBAUDRATEsoil(&dat_mtec.vr_baudrate);
//	ret = getPROTOCOLsoil(&dat_mtec.vr_protocol);
//	ret = getPARITYsoil(&dat_mtec.vr_parity);
//	ret = getDATABITSsoil(&dat_mtec.vr_databits);
//	ret = getSTOPBITSsoil(&dat_mtec.vr_stopbits);
//	ret = getRESPONSEDELAYsoil(&dat_mtec.vr_responDelay);
//	ret = getAOIsoil(&dat_mtec.vr_aoi);
//}

void test_read_turb(){
	ret = getSensorData(Turbidity, 0, (RETURN_VAL*)&dat_turb.vr_devideadd, RET_U16);
	ret = getSensorData(Turbidity, 1, (RETURN_VAL*)&dat_turb.vr_measure, RET_U32);
	ret = getSensorData(Turbidity, 2, (RETURN_VAL*)&dat_turb.vr_workingstate, RET_U16);
	ret = getSensorData(Turbidity, 3, (RETURN_VAL*)&dat_turb.vr_adc, RET_U32);
	ret = getSensorData(Turbidity, 4, (RETURN_VAL*)&dat_turb.vr_firstcalib, RET_U32);
	ret = getSensorData(Turbidity, 5, (RETURN_VAL*)&dat_turb.vr_firstadc, RET_U32);
	ret = getSensorData(Turbidity, 6, (RETURN_VAL*)&dat_turb.vr_secondcalib, RET_U32);
	ret = getSensorData(Turbidity, 7, (RETURN_VAL*)&dat_turb.vr_secondadc, RET_U32);
	ret = getSensorData(Turbidity, 8, (RETURN_VAL*)&dat_turb.vr_thirdcalib, RET_U32);
	ret = getSensorData(Turbidity, 9, (RETURN_VAL*)&dat_turb.vr_thirdadc, RET_U32);
	ret = getSensorData(Turbidity, 10, (RETURN_VAL*)&dat_turb.vr_fafirstcal, RET_U32);
	ret = getSensorData(Turbidity, 11, (RETURN_VAL*)&dat_turb.vr_fafirstadc, RET_U32);
	ret = getSensorData(Turbidity, 12, (RETURN_VAL*)&dat_turb.vr_fasecondcal, RET_U32);
	ret = getSensorData(Turbidity, 13, (RETURN_VAL*)&dat_turb.vr_fasecondadc, RET_U32);
	ret = getSensorData(Turbidity, 14, (RETURN_VAL*)&dat_turb.vr_thirdcalib, RET_U32);
	ret = getSensorData(Turbidity, 15, (RETURN_VAL*)&dat_turb.vr_thirdadc, RET_U32);
}

void test_read_chlor(){
	ret = getSensorData(Chlorine, 0, (RETURN_VAL*)&dat_chlor.vr_measure, RET_FLOAT);
	ret = getSensorData(Chlorine, 1, (RETURN_VAL*)&dat_chlor.vr_temperature, RET_FLOAT);
	ret = getSensorData(Chlorine, 2, (RETURN_VAL*)&dat_chlor.vr_outputval, RET_FLOAT);
	ret = getSensorData(Chlorine, 3, (RETURN_VAL*)&dat_chlor.vr_warning, RET_U16);
	ret = getSensorData(Chlorine, 4, (RETURN_VAL*)&dat_chlor.vr_uppermeasure, RET_FLOAT);
	ret = getSensorData(Chlorine, 5, (RETURN_VAL*)&dat_chlor.vr_lowermeasure, RET_FLOAT);
	ret = getSensorData(Chlorine, 6, (RETURN_VAL*)&dat_chlor.vr_uppertemp, RET_FLOAT);
	ret = getSensorData(Chlorine, 7, (RETURN_VAL*)&dat_chlor.vr_lowertemp, RET_FLOAT);
	ret = getSensorData(Chlorine, 8, (RETURN_VAL*)&dat_chlor.vr_mesoffset, RET_FLOAT);
	ret = getSensorData(Chlorine, 9, (RETURN_VAL*)&dat_chlor.vr_tempoffset, RET_FLOAT);
	ret = getSensorData(Chlorine, 10, (RETURN_VAL*)&dat_chlor.vr_dampcoeff, RET_U16);
	ret = getSensorData(Chlorine, 11, (RETURN_VAL*)&dat_chlor.vr_addslave, RET_U16);
	ret = getSensorData(Chlorine, 12, (RETURN_VAL*)&dat_chlor.vr_baudrate, RET_U16);
	ret = getSensorData(Chlorine, 14, (RETURN_VAL*)&dat_chlor.vr_standsolution, RET_FLOAT);
	ret = getSensorData(Chlorine, 15, (RETURN_VAL*)&dat_chlor.vr_phcompen, RET_FLOAT);
	ret = getSensorData(Chlorine, 16, (RETURN_VAL*)&dat_chlor.vr_manualtemp, RET_FLOAT);
	ret = getSensorData(Chlorine, 19, (RETURN_VAL*)&dat_chlor.vr_measuread, RET_U16);
}
