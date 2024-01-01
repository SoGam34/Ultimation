#include <Wt/WApplication.h>
#include <Wt/WBootstrap2Theme.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WServer.h>

#include <Wt/Auth/AuthWidget.h>
#include <Wt/Auth/PasswordService.h>

#include "Session.hpp"

class Ui : public Wt::WApplication {
public:
  explicit Ui(const Wt::WEnvironment& env)
    : Wt::WApplication(env),
      session_(appRoot() + "Wt.db")
  {
    session_.login().changed().connect(this, &Ui::authEvent);

    root()->addStyleClass("container");
    setTheme(std::make_shared<Wt::WBootstrap2Theme>());

    useStyleSheet("css/style.css");

    auto authWidget = std::make_unique<Wt::Auth::AuthWidget>(
            session_.auth(), session_.users(), session_.login());

    authWidget->model()->addPasswordAuth(&session_.passwordAuth());
    authWidget->setRegistrationEnabled(true);

    authWidget->processEnvironment();

    root()->addWidget(std::move(authWidget));
  }

  void authEvent() {
    if (session_.login().loggedIn()) {
      const Wt::Auth::User& u = session_.login().user();
      log("notice")
        << "User " << u.id()
        << " (" << u.identity(Wt::Auth::Identity::LoginName) << ")"
        << " logged in.";
    } else
      log("notice") << "User logged out.";
  }

private:
  Session session_;
};