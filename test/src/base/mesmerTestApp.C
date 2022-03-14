//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "mesmerTestApp.h"
#include "mesmerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
mesmerTestApp::validParams()
{
  InputParameters params = mesmerApp::validParams();
  return params;
}

mesmerTestApp::mesmerTestApp(InputParameters parameters) : MooseApp(parameters)
{
  mesmerTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

mesmerTestApp::~mesmerTestApp() {}

void
mesmerTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  mesmerApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"mesmerTestApp"});
    Registry::registerActionsTo(af, {"mesmerTestApp"});
  }
}

void
mesmerTestApp::registerApps()
{
  registerApp(mesmerApp);
  registerApp(mesmerTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
mesmerTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mesmerTestApp::registerAll(f, af, s);
}
extern "C" void
mesmerTestApp__registerApps()
{
  mesmerTestApp::registerApps();
}
