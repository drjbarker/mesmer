#include "mesmerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
mesmerApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

mesmerApp::mesmerApp(InputParameters parameters) : MooseApp(parameters)
{
  mesmerApp::registerAll(_factory, _action_factory, _syntax);
}

mesmerApp::~mesmerApp() {}

void
mesmerApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"mesmerApp"});
  Registry::registerActionsTo(af, {"mesmerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
mesmerApp::registerApps()
{
  registerApp(mesmerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mesmerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mesmerApp::registerAll(f, af, s);
}
extern "C" void
mesmerApp__registerApps()
{
  mesmerApp::registerApps();
}
