/*
 * test_libSensor.c
 *
 *  Created on: Oct 19, 2021
 *      Author: 0
 */

#include "my_lib.h"
#include "NH3.h"
#include "CO2.h"
#include "EC_TDS.h"
#include "H2S.h"
#include "PAR.h"
#include "PH.h"
#include "MTEC.h"
#include "TURB.h"

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

void test_CO2(){
	  ret = getCO2(&dat_Co2.vr_CO2);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getVERCO2(&dat_Co2.vr_hardVer, &dat_Co2.vr_softVer);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getModSlaveAddCO2(&dat_Co2.vr_modSlave);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getBaudRateCO2(&dat_Co2.vr_baudrate);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getParityCO2(&dat_Co2.vr_parityBits);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getStopBitsCO2(&dat_Co2.vr_stopBits);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getModProtocolCO2(&dat_Co2.vr_modProtocol);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getDelayResponseCO2(&dat_Co2.vr_delayResponse);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getWarmUpTimeCO2(&dat_Co2.vr_warmUptime);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");
}

void test_ECTDS(){
	  ret = getECTDSTemp(&dat_ectds.vr_temp);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSElectricalCond(&dat_ectds.vr_eletrCond);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSalinity(&dat_ectds.vr_salinity);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getTDS(&dat_ectds.vr_tds);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getEcrawad(&dat_ectds.vr_ecrawad);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSTempCompen(&dat_ectds.vr_tempCompen);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getEcTempCoff(&dat_ectds.vr_tempCoff);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSalinitycoff(&dat_ectds.vr_salinitycoff);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getTDSCoff(&dat_ectds.vr_TdsCoff);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSelectroConst(&dat_ectds.vr_electroConst);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSlaAddress(&dat_ectds.vr_slaAddress);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSBaudrate(&dat_ectds.vr_baudrate);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSProtocol(&dat_ectds.vr_protocol);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSParity(&dat_ectds.vr_parity);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSdatabits(&dat_ectds.vr_databits);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDStopbits(&dat_ectds.vr_stopbits);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDSResponDelay(&dat_ectds.vr_responDelay);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getECTDEAoi(&dat_ectds.vr_aoi);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");
}

void test_H2S(){
	  ret = getH2STemperatureValue(&dat_h2s.vr_temp);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getH2SHumidityValue(&dat_h2s.vr_humi);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret =	getH2S(&dat_h2s.vr_h2s);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getH2SMaxrange(&dat_h2s.vr_maxRange);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");
}

void test_NH3(){
	  ret = getNH3TemperatureValue(&dat_nh3.vr_temp);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getNH3HumidityValue(&dat_nh3.vr_humi);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret =	getNH3(&dat_nh3.vr_nh3);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");

	  ret = getNH3Maxrange(&dat_nh3.vr_maxRange);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");
}

void test_PAR(){
	  ret = getPAR(&dataPAR);
	  if(ret != 0)
		my_printf("receive data successfully");
	  else
		my_printf("not receive data");
}

void test_PH(){
	ret = getPHTemperature(&dat_ph.vr_temp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPH(&dat_ph.vr_ph);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHTemcompensateen(&dat_ph.vr_temcomp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHCalibrawad0(&dat_ph.vr_calibrawad0);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHCalibrawad1(&dat_ph.vr_calibrawad1);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHCalibrawad2(&dat_ph.vr_calibrawad2);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHSlaveaddress(&dat_ph.vr_slaAddress);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHBaudrate(&dat_ph.vr_baudrate);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHProtocol(&dat_ph.vr_protocol);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHParity(&dat_ph.vr_parity);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHDatabits(&dat_ph.vr_databits);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHStopbits(&dat_ph.vr_stopbits);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHResponsedelay(&dat_ph.vr_responDelay);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPHAOI(&dat_ph.vr_aoi);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");
}

void test_mtec(){
	ret = getTEMPsoil(&dat_mtec.vr_temp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getVWCsoil(&dat_mtec.vr_vwc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getECsoil(&dat_mtec.vr_ec);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getSALINITYsoil(&dat_mtec.vr_salinity);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTDSsoil(&dat_mtec.vr_tds);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getEPSILONsoil(&dat_mtec.vr_epsilon);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTEMPUNITsoil(&dat_mtec.vr_tempunit);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getECTEMPCOFFsoil(&dat_mtec.vr_ectemcoff);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getSALINITYCOFFsoil(&dat_mtec.vr_salinitycoff);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTDSCOFFsoil(&dat_mtec.vr_tdscoff);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getSLAVEADDRsoil(&dat_mtec.vr_slaAddress);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getBAUDRATEsoil(&dat_mtec.vr_baudrate);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPROTOCOLsoil(&dat_mtec.vr_protocol);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getPARITYsoil(&dat_mtec.vr_parity);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getDATABITSsoil(&dat_mtec.vr_databits);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getSTOPBITSsoil(&dat_mtec.vr_stopbits);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getRESPONSEDELAYsoil(&dat_mtec.vr_responDelay);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getAOIsoil(&dat_mtec.vr_aoi);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");
}

void test_turb(){
	ret = getTURBmeasure(&dat_turb.vr_measure);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBWorkingState(&dat_turb.vr_workingstate);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBAdc(&dat_turb.vr_adc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFirstCalib(&dat_turb.vr_firstcalib);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFirstAdc(&dat_turb.vr_firstadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBSecondCalib(&dat_turb.vr_secondcalib);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBSecondAdc(&dat_turb.vr_secondadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBThirdCalib(&dat_turb.vr_thirdcalib);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBThirdAdc(&dat_turb.vr_thirdadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaFirstCal(&dat_turb.vr_fafirstcal);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaFirstAdc(&dat_turb.vr_fafirstadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaSecondCal(&dat_turb.vr_fasecondcal);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaSecondAdc(&dat_turb.vr_fasecondadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaThirdCal(&dat_turb.vr_fathirdcal);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBFaThirdAdc(&dat_turb.vr_fathirdadc);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getTURBDeviceAdd(&dat_turb.vr_devideadd);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");
}

void test_chlor(){
	ret = getCHloMeasure(&dat_chlor.vr_measure);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloTemperature(&dat_chlor.vr_temperature);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloOuputVal(&dat_chlor.vr_outputval);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloWarning(&dat_chlor.vr_warning);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloUpperMeasure(&dat_chlor.vr_uppermeasure);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloLowerMeasure(&dat_chlor.vr_lowermeasure);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloUpperTemp(&dat_chlor.vr_uppertemp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloLowerTemp(&dat_chlor.vr_lowertemp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloMesOffset(&dat_chlor.vr_mesoffset);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloTempOffset(&dat_chlor.vr_tempoffset);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloDampCoeff(&dat_chlor.vr_dampcoeff);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloAddSlave(&dat_chlor.vr_addslave);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloBaudrate(&dat_chlor.vr_baudrate);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloStandSolution(&dat_chlor.vr_standsolution);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloPhCompen(&dat_chlor.vr_phcompen);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloManualTemp(&dat_chlor.vr_manualtemp);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");

	ret = getCHloMeasureAd(&dat_chlor.vr_measuread);
	if(ret != 0)
		my_printf("receive data successfully");
	else
		my_printf("not receive data");
}
