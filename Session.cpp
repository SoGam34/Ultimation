#include "Session.hpp"

Session::Session(const std::string& sqliteDb)
{
  auto connection = std::make_unique<Wt::Dbo::backend::Sqlite3>(sqliteDb);
  setConnection(std::move(connection_));

  mapClass<User>("user");
  mapClass<AuthInfo>("auth_info");
  mapClass<AuthInfo::AuthIdentityType>("auth_identity");
  mapClass<AuthInfo::AuthTokenType>("auth_token");

  try {
    createTables();
    std::cerr << "Created database.\n";
  } catch (Wt::Dbo::Exception& e) {
    std::cerr << e.what() << '\n';
    std::cerr << "Using existing database\n";
  }

  users_ = std::make_unique<UserDatabase>(*this);
}

void Session::configureAuth()
{
  myAuthService.setAuthTokensEnabled(true, "logincookie");
  myAuthService.setEmailVerificationEnabled(true);
  myAuthService.setEmailVerificationRequired(true);

  auto verifier = std::make_unique<Wt::Auth::PasswordVerifier>();
  verifier->addHashFunction(std::make_unique<Wt::Auth::BCryptHashFunction>(13));
  myPasswordService.setVerifier(std::move(verifier));
  myPasswordService.setAttemptThrottlingEnabled(true);
  myPasswordService.setStrengthValidator(
    std::make_unique<Wt::Auth::PasswordStrengthValidator>());
}
