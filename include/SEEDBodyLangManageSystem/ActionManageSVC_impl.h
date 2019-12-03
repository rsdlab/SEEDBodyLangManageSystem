// -*-C++-*-
/*!
 * @file  ActionManageSVC_impl.h
 * @brief Service implementation header of ActionManage.idl
 *
 */

#include "ActionManageSkel.h"
#include <iostream>

#ifndef ACTIONMANAGESVC_IMPL_H
#define ACTIONMANAGESVC_IMPL_H
 
/*!
 * @class Action_ActionManageSVC_impl
 * Example class implementing IDL interface Action::ActionManage
 */
class Action_ActionManageSVC_impl
 : public virtual POA_Action::ActionManage,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~Action_ActionManageSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   Action_ActionManageSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~Action_ActionManageSVC_impl();

   // attributes and operations
   void read(const char* actionid);

   std::string GRobotBodyLangData;

   int Flag;

   double Rarm0;
   double Rarm1;
   double Rarm2;
   double Rarm3;
   double Rarm4;
   double Rarm5;
   double Rarm6;
   double Larm0;
   double Larm1;
   double Larm2;
   double Larm3;
   double Larm4;
   double Larm5;
   double Larm6;
   double handparaR;
   double handparaL;
   double neckyoo;
   double neckpich;
   double neckrole;
   double waistyoo;
   double waistpich;
   double waistrole;

};



#endif // ACTIONMANAGESVC_IMPL_H


