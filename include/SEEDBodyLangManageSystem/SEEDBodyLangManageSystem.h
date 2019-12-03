// -*- C++ -*-
/*!
 * @file  SEEDBodyLangManageSystem.h
 * @brief SEEDBodyLangManageSystem
 * @date  $Date$
 *
 * $Id$
 */

#ifndef SEEDBODYLANGMANAGESYSTEM_H
#define SEEDBODYLANGMANAGESYSTEM_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "ActionManageSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "ManipulatorCommonInterface_CommonStub.h"
#include "ManipulatorCommonInterface_MiddleStub.h"
#include "LeftManipulatorCommonInterface_CommonStub.h"
#include "LeftManipulatorCommonInterface_MiddleLevelStub.h"
#include "SeedWaistInterfaceStub.h"
#include "SeedNeckInterfaceStub.h"
#include "BasicDataTypeStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

//ロールピッチヨー
typedef struct
{
  double roll;
  double pitch;
  double yaw;
}Frame;

/*!
 * @class SEEDBodyLangManageSystem
 * @brief SEEDBodyLangManageSystem
 *
 */
class SEEDBodyLangManageSystem
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  SEEDBodyLangManageSystem(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~SEEDBodyLangManageSystem();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  ActionMode
   * - DefaultValue: Execution
   */
  std::string m_ActionMode;
  /*!
   * 
   * - Name:  BodyLangList
   * - DefaultValue: ../../data.csv
   */
  std::string m_BodyLangList;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedDouble m_waistmovement;
  /*!
   */
  RTC::InPort<RTC::TimedDouble> m_waistmovementIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_RightManipulatorCommonInterface_CommonPort;
  /*!
   */
  RTC::CorbaPort m_RightManipulatorCommonInterface_MiddlePort;
  /*!
   */
  RTC::CorbaPort m_LeftManipulatorCommonInterface_CommonPort;
  /*!
   */
  RTC::CorbaPort m_LeftManipulatorCommonInterface_MiddlePort;
  /*!
   */
  RTC::CorbaPort m_SeedWaistInterfacePort;
  /*!
   */
  RTC::CorbaPort m_SeedNeckInterfacePort;
  /*!
   */
  RTC::CorbaPort m_actionmanagePort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  /*!
   */
  Action_ActionManageSVC_impl m_ActionManageProvider;
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM::ManipulatorCommonInterface_Common> m_ManipulatorCommonInterface_Common;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM::ManipulatorCommonInterface_Middle> m_ManipulatorCommonInterface_Middle;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common> m_LeftManipulatorCommonInterface_Common;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle> m_LeftManipulatorCommonInterface_Middle;
  /*!
   */
  RTC::CorbaConsumer<SeedWaist::SeedWaistInterface> m_SeedWaistInterface;
  /*!
   */
  RTC::CorbaConsumer<SeedNeck::SeedNeckInterface> m_SeedNeckInterface;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

  JARA_ARM::RETURN_ID_var m_rid_right;
  JARA_ARM_LEFT::RETURN_ID_var m_rid_left;
  SeedNeck::RETURN_ID_var m_rid_neck;
  SeedWaist::RETURN_ID_var m_rid_waist;

};


extern "C"
{
  DLL_EXPORT void SEEDBodyLangManageSystemInit(RTC::Manager* manager);
};

#endif // SEEDBODYLANGMANAGESYSTEM_H
