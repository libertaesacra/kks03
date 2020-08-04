//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "kks03TestApp.h"
#include "kks03App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
kks03TestApp::validParams()
{
  InputParameters params = kks03App::validParams();
  return params;
}

kks03TestApp::kks03TestApp(InputParameters parameters) : MooseApp(parameters)
{
  kks03TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

kks03TestApp::~kks03TestApp() {}

void
kks03TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  kks03App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"kks03TestApp"});
    Registry::registerActionsTo(af, {"kks03TestApp"});
  }
}

void
kks03TestApp::registerApps()
{
  registerApp(kks03App);
  registerApp(kks03TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
kks03TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks03TestApp::registerAll(f, af, s);
}
extern "C" void
kks03TestApp__registerApps()
{
  kks03TestApp::registerApps();
}
