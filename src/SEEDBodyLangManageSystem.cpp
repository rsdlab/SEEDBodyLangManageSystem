// -*- C++ -*-
/*!
 * @file  SEEDBodyLangManageSystem.cpp
 * @brief SEEDBodyLangManageSystem
 * @date $Date$
 *
 * $Id$
 */

#include "SEEDBodyLangManageSystem.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

// Module specification
// <rtc-template block="module_spec">
static const char* seedbodylangmanagesystem_spec[] =
  {
    "implementation_id", "SEEDBodyLangManageSystem",
    "type_name",         "SEEDBodyLangManageSystem",
    "description",       "SEEDBodyLangManageSystem",
    "version",           "1.0.0",
    "vendor",            "hiroyasu",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.ActionMode", "Execution",
    "conf.default.BodyLangList", "../../data.csv",

    // Widget
    "conf.__widget__.ActionMode", "radio",
    "conf.__widget__.BodyLangList", "text",
    // Constraints
    "conf.__constraints__.ActionMode", "(Execution,Generation)",

    "conf.__type__.ActionMode", "string",
    "conf.__type__.BodyLangList", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SEEDBodyLangManageSystem::SEEDBodyLangManageSystem(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_waistmovementIn("waistmovement", m_waistmovement),
    m_RightManipulatorCommonInterface_CommonPort("RightManipulatorCommonInterface_Common"),
    m_RightManipulatorCommonInterface_MiddlePort("RightManipulatorCommonInterface_Middle"),
    m_LeftManipulatorCommonInterface_CommonPort("LeftManipulatorCommonInterface_Common"),
    m_LeftManipulatorCommonInterface_MiddlePort("LeftManipulatorCommonInterface_Middle"),
    m_SeedWaistInterfacePort("SeedWaistInterface"),
    m_SeedNeckInterfacePort("SeedNeckInterface"),
    m_actionmanagePort("actionmanage")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SEEDBodyLangManageSystem::~SEEDBodyLangManageSystem()
{
}



RTC::ReturnCode_t SEEDBodyLangManageSystem::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("waistmovement", m_waistmovementIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_actionmanagePort.registerProvider("ActionManage", "Action::ActionManage", m_ActionManageProvider);
  
  // Set service consumers to Ports
  m_RightManipulatorCommonInterface_CommonPort.registerConsumer("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_RightManipulatorCommonInterface_MiddlePort.registerConsumer("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  m_LeftManipulatorCommonInterface_CommonPort.registerConsumer("LeftManipulatorCommonInterface_Common", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common", m_LeftManipulatorCommonInterface_Common);
  m_LeftManipulatorCommonInterface_MiddlePort.registerConsumer("LeftManipulatorCommonInterface_Middle", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle", m_LeftManipulatorCommonInterface_Middle);
  m_SeedWaistInterfacePort.registerConsumer("SeedWaistInterface", "SeedWaist::SeedWaistInterface", m_SeedWaistInterface);
  m_SeedNeckInterfacePort.registerConsumer("SeedNeckInterface", "SeedNeck::SeedNeckInterface", m_SeedNeckInterface);
  
  // Set CORBA Service Ports
  addPort(m_RightManipulatorCommonInterface_CommonPort);
  addPort(m_RightManipulatorCommonInterface_MiddlePort);
  addPort(m_LeftManipulatorCommonInterface_CommonPort);
  addPort(m_LeftManipulatorCommonInterface_MiddlePort);
  addPort(m_SeedWaistInterfacePort);
  addPort(m_SeedNeckInterfacePort);
  addPort(m_actionmanagePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ActionMode", m_ActionMode, "Execution");
  bindParameter("BodyLangList", m_BodyLangList, "../../data.csv");
  // </rtc-template>
  m_ActionManageProvider.GRobotBodyLangData = m_BodyLangList.c_str();
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SEEDBodyLangManageSystem::onActivated(RTC::UniqueId ec_id)
{

  return RTC::RTC_OK;
}


RTC::ReturnCode_t SEEDBodyLangManageSystem::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SEEDBodyLangManageSystem::onExecute(RTC::UniqueId ec_id)
{
  int a,b,c,e,f;
  double d[22];
  std::string bodylanguagename;

//************  BodyLanguageGeneration (ボディーランゲージ生成)  ************
  if (m_ActionMode == "Generation"){
    while(e != 2){
      std::cout << "GenerationStart" << std::endl;
      std::cout << "ボディーランゲージ設計手法を選択してください" << std::endl;
      std::cout << "1 : OFFLINE Teaching (オフラインティーチング)" << std::endl;
      std::cout << "2 : Direct Teaching (ダイレクトティーチング)" << std::endl;
      std::cout << "3 : 終了" << std::endl;

      std::cout << "  >>  ";
      std::cin >> a;
      std::cout << std::endl;

      //************  OFFLINE Teaching (オフラインティーチング)  ************
      if (a == 1){
	a = 0;
	while(b != 2){
	  std::cout << "各関節角度を入力してください" << std::endl;
	  for (int r = 0; r < 7; r++){
	    std::cout << "右腕第" << r+1 << "関節角度" << std::endl;
	    std::cout << ">>";
	    std::cin >> d[r];
	    std::cout << std::endl;
	  }
	  for (int l = 7; l < 14; l++){
	    std::cout << "左腕第" << l-6 << "関節角度" << std::endl;
	    std::cout << ">>";
	    std::cin >> d[l];
	    std::cout << std::endl;
	  }

	  std::cout << "右ハンドの開度 (0〜100)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[14];
	  std::cout << std::endl;

	  std::cout << "左ハンドの開度 (0〜100)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[15];
	  std::cout << std::endl;

	  std::cout << "首ヨー(回転)角度 (-90〜90)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[16];
	  std::cout << std::endl;
      
	  std::cout << "首ピッチ(前後)角度 (-20〜60)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[17];
	  std::cout << std::endl;
	
	  std::cout << "首ロール(左右)角度 (-20〜20)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[18];
	  std::cout << std::endl;

	  std::cout << "腰ヨー(回転)角度 (-90〜90)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[19];
	  std::cout << std::endl;

	  std::cout << "腰ピッチ(前後)角度 (-9〜39)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[20];
	  std::cout << std::endl;

	  std::cout << "腰ロール(左右)角度 (-9〜9)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[21];
	  std::cout << std::endl;

	  //RightArm
	  JARA_ARM::ManipInfo_var Rminfovar;
	  JARA_ARM::ManipInfo Rminfo;
	  JARA_ARM::JointPos RjointPoint;
	  m_ManipulatorCommonInterface_Common->getManipInfo(Rminfovar);
	  Rminfo = Rminfovar;
	  RjointPoint.length(Rminfo.axisNum);
	  RjointPoint[0] = d[0];
	  RjointPoint[1] = d[1];
	  RjointPoint[2] = d[2];
	  RjointPoint[3] = d[3];
	  RjointPoint[4] = d[4];
	  RjointPoint[5] = d[5];
	  RjointPoint[6] = d[6];
	  m_rid_right=m_ManipulatorCommonInterface_Middle->movePTPJointAbs(RjointPoint);

	  JARA_ARM::ULONG RangleRatio;
	  RangleRatio = d[14];
	  m_rid_right=m_ManipulatorCommonInterface_Middle->moveGripper(RangleRatio);

	  //LeftArm
	  JARA_ARM_LEFT::ManipInfo_var Lminfovar;
	  JARA_ARM_LEFT::ManipInfo Lminfo;
	  JARA_ARM_LEFT::JointPos LjointPoint;
	  m_LeftManipulatorCommonInterface_Common->getManipInfo(Lminfovar);
	  Lminfo = Lminfovar;
	  LjointPoint.length(Lminfo.axisNum);
	  LjointPoint[0] = d[7];
	  LjointPoint[1] = d[8];
	  LjointPoint[2] = d[9];
	  LjointPoint[3] = d[10];
	  LjointPoint[4] = d[11];
	  LjointPoint[5] = d[12];
	  LjointPoint[6] = d[13];
	  m_rid_left=m_LeftManipulatorCommonInterface_Middle->movePTPJointAbs(LjointPoint);

	  JARA_ARM_LEFT::ULONG LangleRatio;
	  LangleRatio = d[15];
	  m_rid_left=m_LeftManipulatorCommonInterface_Middle->moveGripper(LangleRatio);

	  SeedNeck::NeckPos neckPoint;
	  neckPoint.length(3);

	  //頭ヨー(回転)-90~90
	  neckPoint[0] = d[16];
	  //頭ピッチ(前後)-20~+60
	  neckPoint[1] = d[17];
	  //頭ロール(左右)-20~+20
	  neckPoint[2] = d[18];
	  m_rid_neck=m_SeedNeckInterface->movePTPNeckAbs(neckPoint);

	  SeedWaist::WaistPos waistPoint;
	  waistPoint.length(3);
	  
	  //腰ヨー(回転)-90~90
	  waistPoint[0] = d[19];
	  //腰ピッチ(前後)-9~+39
	  waistPoint[1] = d[20];
	  //腰ロール(左右)-9~+9
	  waistPoint[2] = d[21];
	  m_rid_waist=m_SeedWaistInterface->movePTPWaistAbs(waistPoint);
	  
	  std::cout << "入力を完了しますか" << std::endl;
	  std::cout << "1 : データ入力のリセット" << std::endl;
	  std::cout << "2 : 終了" << std::endl;
	  
	  std::cout << "  >>  ";
	  std::cin >> b;
	  std::cout << std::endl;
	}
	b = 0;
	while (c != 2){
	  c = 0;
	  std::cout << "ボディーランゲージ名を入力して下さい" << std::endl;
	  std::cout << "  >>  ";
	  std::cin >> bodylanguagename;
	  std::cout << std::endl;
	  
	  std::vector<std::string> data;
	  std::ifstream ifs(m_BodyLangList.c_str());
	  std::string str;
	  
	  while(getline(ifs, str)){
	    std::istringstream stream(str);
	    std::string field;
	    while(getline(stream, field, ',')){
	      data.push_back(field);
	    }
	  }
	  for(std::vector<std::string>::size_type i = 23; i < data.size(); i+=23){
	    if(data[i] == bodylanguagename){
	      std::cout << " 重複しているボディーランゲージ名があります " << std::endl;
	      bodylanguagename = "";
	      c = 1;
	    }
	  }
	  if (c != 1){
	    c = 2;
	  }
	}
	c = 0;
	std::ofstream ofs(m_BodyLangList.c_str(), std::ios::app);
	ofs << bodylanguagename << "," << d[0] << "," << d[1] << "," << d[2] << "," << d[3]
	    << "," << d[4] << "," << d[5] << "," << d[6] << "," << d[7]<< "," << d[8]
	    << "," << d[9] << "," << d[10] << "," << d[11] << "," << d[12] << "," << d[13]
	    << "," << d[14] << "," << d[15] << "," << d[16] << "," << d[17] << "," << d[18]
	    << "," << d[19] << "," << d[20] << "," << d[21]
	    << "," << std::endl;
	std::cout << " BodyLanguageGenerated " << std::endl;

	std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	std::cout << "1 : 新規ボディーランゲージ設定" << std::endl;
	std::cout << "2 : 終了" << std::endl;
	
	std::cout << "  >>  ";
	std::cin >> e;
	std::cout << std::endl;
      }
      //************  Direct Teaching (ダイレクトティーチング)  ************
      else if (a == 2){
	a = 0;
	while (b != 2){
	  m_rid_right=m_ManipulatorCommonInterface_Common->servoOFF();
	  if(m_rid_right->id != 0){//Error
	    std::cout<<"Servo OFF ERROR"<<std::endl;
	    std::cout<<m_rid_right->comment<<std::endl<<std::endl;
	  }
	  m_rid_left=m_LeftManipulatorCommonInterface_Common->servoOFF();
	  if(m_rid_left->id != 0){//Error
	    std::cout<<"Servo OFF ERROR"<<std::endl;
	    std::cout<<m_rid_left->comment<<std::endl<<std::endl;
	  }
	  std::cout << "ボディーランゲージ設定を終了する場合は1を入力して下さい" << std::endl;
	  std::cout << "1 : 設定終了" << std::endl;
	  std::cout << "  >>  ";
	  std::cin >> f;
	  std::cout << std::endl;
	  
	  if (f == 1){
	    m_rid_right=m_ManipulatorCommonInterface_Common->servoON();
	    if(m_rid_right->id != 0){//Error
	      std::cout<<"Servo ON ERROR"<<std::endl;
	      std::cout<<m_rid_right->comment<<std::endl<<std::endl;
	    }
	    m_rid_left=m_LeftManipulatorCommonInterface_Common->servoON();
	    if(m_rid_left->id != 0){//Error
	      std::cout<<"Servo ON ERROR"<<std::endl;
	      std::cout<<m_rid_left->comment<<std::endl<<std::endl;
	    }
	    f = 0;
	  }
	  
	  JARA_ARM::JointPos_var Rightposvar;
	  JARA_ARM::JointPos Rightpos;
	  JARA_ARM_LEFT::JointPos_var Leftposvar;
	  JARA_ARM_LEFT::JointPos Leftpos;
	  SeedNeck::NeckPos_var Neckposvar;
	  SeedNeck::NeckPos Neckpos;
	  SeedWaist::WaistPos_var Waistposvar;
	  SeedWaist::WaistPos Waistpos;
	  Rightpos.length(7);
	  Leftpos.length(7);
	  Neckpos.length(3);
	  Waistpos.length(3);
	  
	  //右腕
	  m_rid_right=m_ManipulatorCommonInterface_Common->getFeedbackPosJoint(Rightposvar);
	  if(m_rid_right->id != 0){//Error
	    std::cout<<"RightgetFeedbackPosJoint ERROR"<<std::endl;
	    std::cout<<m_rid_right->comment<<std::endl<<std::endl;
	  }
	  Rightpos = Rightposvar;
	  for(int r = 0; r < 7; r++){
	    std::cout <<"RightArmpos["<<r<<"] = "<<Rightpos[r]<<std::endl;
	    d[r] = Rightpos[r];
	  }
	  //左腕
	  m_rid_left=m_LeftManipulatorCommonInterface_Common->getFeedbackPosJoint(Leftposvar);
	  if(m_rid_left->id != 0){//Error
	    std::cout<<"LeftgetFeedbackPosJoint ERROR"<<std::endl;
	    std::cout<<m_rid_left->comment<<std::endl<<std::endl;
	  }
	  Leftpos = Leftposvar;
	  for(int l = 0; l<7; l++){
	    std::cout <<"LeftArmpos["<<l<<"] = "<<Leftpos[l]<<std::endl;
	    d[l+7] = Leftpos[l];
	  }
	  
	  //首
	  m_rid_neck=m_SeedNeckInterface->getFeedbackPosNeck(Neckposvar);
	  if(m_rid_neck->id != 0){//Error
	    std::cout<<"NeckgetFeedbackPosNeck ERROR"<<std::endl;
	    std::cout<<m_rid_neck->comment<<std::endl<<std::endl;
	  }
	  Neckpos = Neckposvar;
	  for(int k = 0; k < 3; k++){
	    std::cout <<"Neckpos["<<k<<"] = "<<Neckpos[k]<<std::endl;
	    d[k+16] = Neckpos[k];
	  }
	  
	  //腰
	  m_rid_waist=m_SeedWaistInterface->getFeedbackPosWaist(Waistposvar);
	  if(m_rid_waist->id != 0){//Error
	    std::cout<<"getFeedbackPosWaist ERROR"<<std::endl;
	    std::cout<<m_rid_waist->comment<<std::endl<<std::endl;
	  }
	  Waistpos = Waistposvar;
	  for(int h = 0; h < 3; h++){
	    std::cout <<"Waistpos["<<h<<"] = "<<Waistpos[h]<<std::endl;
	    d[h+19] = Waistpos[h];
	  }
	  
	  std::cout << "右ハンドの開度 (0〜100)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[14];
	  std::cout << std::endl;
	  
	  std::cout << "左ハンドの開度 (0〜100)" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[15];
	  std::cout << std::endl;
	  	  
	  std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	  std::cout << "1 : ボディーランゲージ設定のやり直し" << std::endl;
	  std::cout << "2 : 終了" << std::endl;
	  
	  std::cout << "  >>  ";
	  std::cin >> b;
	  std::cout << std::endl;
	}
	b = 0;
	while (c != 2){
	  c = 0;
	  std::cout << "ボディーランゲージ名を入力して下さい" << std::endl;
	  std::cout << "  >>  ";
	  std::cin >> bodylanguagename;
	  std::cout << std::endl;
	  
	  std::vector<std::string> data;
	  std::ifstream ifs(m_BodyLangList.c_str());
	  std::string str;
	  
	  while(getline(ifs, str)){
	    std::istringstream stream(str);
	    std::string field;
	    while(getline(stream, field, ',')){
	      data.push_back(field);
	    }
	  }
	  for(std::vector<std::string>::size_type i = 23; i < data.size(); i+=23){
	    if(data[i] == bodylanguagename){
	      std::cout << " 重複しているボディーランゲージ名があります " << std::endl;
	      bodylanguagename = "";
	      c = 1;
	    }
	  }
	  if (c != 1){
	    c = 2;
	  }
	}
	c = 0;
	std::ofstream ofs(m_BodyLangList.c_str(), std::ios::app);
	ofs << bodylanguagename << "," << d[0] << "," << d[1] << "," << d[2] << "," << d[3]
	    << "," << d[4] << "," << d[5] << "," << d[6] << "," << d[7]<< "," << d[8]
	    << "," << d[9] << "," << d[10] << "," << d[11] << "," << d[12] << "," << d[13]
	    << "," << d[14] << "," << d[15] << "," << d[16] << "," << d[17] << "," << d[18]
	    << "," << d[19] << "," << d[20] << "," << d[21]
	    << "," << std::endl;
	std::cout << " BodyLanguageGenerated " << std::endl;
	
	std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	std::cout << "1 : 新規ボディーランゲージ設定" << std::endl;
	std::cout << "2 : 終了" << std::endl;
	
	std::cout << "  >>  ";
	std::cin >> e;
	std::cout << std::endl;
	
      }
      
      //************  終了  ************
      else if (a == 3){
	std::cout << "END" << std::endl;
	std::cout << "システムをDeactivateしてください" <<std::endl;
	deactivate(ec_id);
      }
    }
    e = 0;
    std::cout << "END" << std::endl;
    std::cout << "システムをDeactivateしてください" <<std::endl;
    deactivate(ec_id);
  }
  
  //************  BodyLanguageExecution (ボディーランゲージ実行)  ************
  if (m_ActionMode == "Execution" && m_ActionManageProvider.Flag == 1){
    sleep(1);
    std::cout << "ExecutionStart" << std::endl;
    //RightArm
    JARA_ARM::ManipInfo_var Rminfovar;
    JARA_ARM::ManipInfo Rminfo;
    JARA_ARM::JointPos RjointPoint;
    m_ManipulatorCommonInterface_Common->getManipInfo(Rminfovar);
    Rminfo = Rminfovar;
    RjointPoint.length(Rminfo.axisNum);
    RjointPoint[0] = m_ActionManageProvider.Rarm0;
    RjointPoint[1] = m_ActionManageProvider.Rarm1;
    RjointPoint[2] = m_ActionManageProvider.Rarm2;
    RjointPoint[3] = m_ActionManageProvider.Rarm3;
    RjointPoint[4] = m_ActionManageProvider.Rarm4;
    RjointPoint[5] = m_ActionManageProvider.Rarm5;
    RjointPoint[6] = m_ActionManageProvider.Rarm6;
    m_rid_right=m_ManipulatorCommonInterface_Middle->movePTPJointAbs(RjointPoint);
    
    JARA_ARM::ULONG RangleRatio;
    RangleRatio = m_ActionManageProvider.handparaR;
    m_rid_right=m_ManipulatorCommonInterface_Middle->moveGripper(RangleRatio);
    
    //LeftArm
    JARA_ARM_LEFT::ManipInfo_var Lminfovar;
    JARA_ARM_LEFT::ManipInfo Lminfo;
    JARA_ARM_LEFT::JointPos LjointPoint;
    m_LeftManipulatorCommonInterface_Common->getManipInfo(Lminfovar);
    Lminfo = Lminfovar;
    LjointPoint.length(Lminfo.axisNum);
    LjointPoint[0] = m_ActionManageProvider.Larm0;
    LjointPoint[1] = m_ActionManageProvider.Larm1;
    LjointPoint[2] = m_ActionManageProvider.Larm2;
    LjointPoint[3] = m_ActionManageProvider.Larm3;
    LjointPoint[4] = m_ActionManageProvider.Larm4;
    LjointPoint[5] = m_ActionManageProvider.Larm5;
    LjointPoint[6] = m_ActionManageProvider.Larm6;
    m_rid_left=m_LeftManipulatorCommonInterface_Middle->movePTPJointAbs(LjointPoint);
    
    JARA_ARM_LEFT::ULONG LangleRatio;
    LangleRatio = m_ActionManageProvider.handparaL;
    m_rid_left=m_LeftManipulatorCommonInterface_Middle->moveGripper(LangleRatio);
    
    SeedNeck::NeckPos neckPoint;
    neckPoint.length(3);
    
    //頭ヨー(回転)-90~90
    neckPoint[0] = m_ActionManageProvider.neckyoo;
    //頭ピッチ(前後)-20~+60
    neckPoint[1] = m_ActionManageProvider.neckpich;
    //頭ロール(左右)-20~+20
    neckPoint[2] = m_ActionManageProvider.neckrole;
    m_rid_neck=m_SeedNeckInterface->movePTPNeckAbs(neckPoint);
    
    SeedWaist::WaistPos waistPoint;
    waistPoint.length(3);
    if (m_waistmovementIn.isNew()){
      m_waistmovementIn.read();
      waistPoint[0] = -1 * m_waistmovement.data;
      std::cout << "Moveamount" << waistPoint[0] << std::endl;
    }
    else {
      //腰ヨー(回転)-90~90
      waistPoint[0] = m_ActionManageProvider.waistyoo;
    }
    //腰ピッチ(前後)-9~+39
    waistPoint[1] = m_ActionManageProvider.waistpich;
    //腰ロール(左右)-9~+9
    waistPoint[2] = m_ActionManageProvider.waistrole;
    m_rid_waist=m_SeedWaistInterface->movePTPWaistAbs(waistPoint);
    
    m_ActionManageProvider.Flag = 0;
    
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystem::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SEEDBodyLangManageSystemInit(RTC::Manager* manager)
  {
    coil::Properties profile(seedbodylangmanagesystem_spec);
    manager->registerFactory(profile,
                             RTC::Create<SEEDBodyLangManageSystem>,
                             RTC::Delete<SEEDBodyLangManageSystem>);
  }
  
};


