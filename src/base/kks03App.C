#include "kks03App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
kks03App::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

kks03App::kks03App(InputParameters parameters) : MooseApp(parameters)
{
  kks03App::registerAll(_factory, _action_factory, _syntax);
}

kks03App::~kks03App() {}

void
kks03App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"kks03App"});
  Registry::registerActionsTo(af, {"kks03App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
kks03App::registerApps()
{
  registerApp(kks03App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
kks03App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  kks03App::registerAll(f, af, s);
}
extern "C" void
kks03App__registerApps()
{
  kks03App::registerApps();
}
