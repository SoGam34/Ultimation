#include <Wt/Auth/Login.h>
#include <Wt/Auth/Dbo/UserDatabase.h>
#include <Wt/Auth/Dbo/AuthInfo.h>
#include <Wt/Auth/AuthService.h>
#include <Wt/Auth/HashFunction.h>
#include <Wt/Auth/PasswordService.h>
#include <Wt/Auth/PasswordStrengthValidator.h>
#include <Wt/Auth/PasswordVerifier.h>
#include <Wt/Dbo/backend/Sqlite3.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/ptr.h>

#include "User.hpp"


namespace dbo = Wt::Dbo;

using UserDatabase = Wt::Auth::Dbo::UserDatabase<AuthInfo>;

namespace {
  Wt::Auth::AuthService myAuthService;
  Wt::Auth::PasswordService myPasswordService(myAuthService);
}

class Session : public dbo::Session
{
public:
  explicit Session(const std::string& sqliteDb);

  Wt::Auth::Login& login() { return login_; }


Wt::Auth::AbstractUserDatabase& users()
{
  return *users_;
}

const Wt::Auth::AuthService& auth()
{
  return myAuthService;
}

const Wt::Auth::PasswordService& passwordAuth()
{
  return myPasswordService;
}

 void configureAuth();
private:
  std::unique_ptr<UserDatabase> users_;
  Wt::Auth::Login login_;

};