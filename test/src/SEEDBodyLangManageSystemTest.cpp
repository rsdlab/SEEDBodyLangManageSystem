// -*- C++ -*-
/*!
 * @file  SEEDBodyLangManageSystemTest.cpp
 * @brief SEEDBodyLangManageSystem
 * @date $Date$
 *
 * $Id$
 */

#include "SEEDBodyLangManageSystemTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* seedbodylangmanagesystem_spec[] =
  {
    "implementation_id", "SEEDBodyLangManageSystemTest",
    "type_name",         "SEEDBodyLangManageSystemTest",
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
SEEDBodyLangManageSystemTest::SEEDBodyLangManageSystemTest(RTC::Manager* manager)
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
SEEDBodyLangManageSystemTest::~SEEDBodyLangManageSystemTest()
{
}



RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("waistmovement", m_waistmovementOut);
  
  // Set service provider to Ports
  m_RightManipulatorCommonInterface_CommonPort.registerProvider("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_RightManipulatorCommonInterface_MiddlePort.registerProvider("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  m_LeftManipulatorCommonInterface_CommonPort.registerProvider("LeftManipulatorCommonInterface_Common", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common", m_LeftManipulatorCommonInterface_Common);
  m_LeftManipulatorCommonInterface_MiddlePort.registerProvider("LeftManipulatorCommonInterface_Middle", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle", m_LeftManipulatorCommonInterface_Middle);
  m_SeedWaistInterfacePort.registerProvider("SeedWaistInterface", "SeedWaist::SeedWaistInterface", m_SeedWaistInterface);
  m_SeedNeckInterfacePort.registerProvider("SeedNeckInterface", "SeedNeck::SeedNeckInterface", m_SeedNeckInterface);
  
  // Set service consumers to Ports
  m_actionmanagePort.registerConsumer("ActionManage", "Action::ActionManage", m_ActionManageProvider);
  
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
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SEEDBodyLangManageSystemTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SEEDBodyLangManageSystemTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(seedbodylangmanagesystem_spec);
    manager->registerFactory(profile,
                             RTC::Create<SEEDBodyLangManageSystemTest>,
                             RTC::Delete<SEEDBodyLangManageSystemTest>);
  }
  
};


