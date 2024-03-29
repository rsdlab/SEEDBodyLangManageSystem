﻿// -*- C++ -*-
/*!
 * @file  SEEDBodyLangManageSystemTest.h
 * @brief SEEDBodyLangManageSystem
 * @date  $Date$
 *
 * $Id$
 */

#ifndef SEEDBODYLANGMANAGESYSTEM_TEST__H
#define SEEDBODYLANGMANAGESYSTEM_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "ManipulatorCommonInterface_CommonSVC_impl.h"
#include "ManipulatorCommonInterface_MiddleSVC_impl.h"
#include "LeftManipulatorCommonInterface_CommonSVC_impl.h"
#include "LeftManipulatorCommonInterface_MiddleLevelSVC_impl.h"
#include "SeedWaistInterfaceSVC_impl.h"
#include "SeedNeckInterfaceSVC_impl.h"
#include "BasicDataTypeSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "ActionManageStub.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class SEEDBodyLangManageSystemTest
 * @brief SEEDBodyLangManageSystem
 *
 */
class SEEDBodyLangManageSystemTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  SEEDBodyLangManageSystemTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~SEEDBodyLangManageSystemTest();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
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
   * former rtc_stopping_entry()
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
   * former rtc_active_entry()
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
   * former rtc_active_exit()
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
   * former rtc_active_do()
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
   * former rtc_aborting_entry()
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
   * former rtc_error_do()
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
   * This is same but different the former rtc_init_entry()
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
   * no corresponding operation exists in OpenRTm-aist-0.2.0
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
   * no corresponding operation exists in OpenRTm-aist-0.2.0
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
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedDouble m_waistmovement;
  /*!
   */
  RTC::OutPort<RTC::TimedDouble> m_waistmovementOut;
  
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
  ManipulatorCommonInterface_CommonSVC_impl m_ManipulatorCommonInterface_Common;
  /*!
   */
  ManipulatorCommonInterface_MiddleSVC_impl m_ManipulatorCommonInterface_Middle;
  /*!
   */
  LeftManipulatorCommonInterface_CommonSVC_impl m_LeftManipulatorCommonInterface_Common;
  /*!
   */
  LeftManipulatorCommonInterface_MiddleSVC_impl m_LeftManipulatorCommonInterface_Middle;
  /*!
   */
  SeedWaistInterfaceSVC_impl m_SeedWaistInterface;
  /*!
   */
  SeedNeckInterfaceSVC_impl m_SeedNeckInterface;
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<Action::ActionManage> m_ActionManageProvider;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void SEEDBodyLangManageSystemTestInit(RTC::Manager* manager);
};

#endif // SEEDBODYLANGMANAGESYSTEM_TEST_H
