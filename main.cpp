#include "Ui.hpp"

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment &env)
{
  return std::make_unique<Ui>(env);
}

int main(int argc, char **argv)
{
  try {
    Wt::WServer server{argc, argv, WTHTTP_CONFIGURATION};

    server.addEntryPoint(Wt::EntryPointType::Application, createApplication);
    Session session_("Wt.db");

    session_.configureAuth();

    server.run();
  } catch (Wt::WServer::Exception& e) {
    std::cerr << e.what() << '\n';
  } catch (Wt::Dbo::Exception &e) {
    std::cerr << "Dbo exception: " << e.what() << '\n';
  } catch (std::exception &e) {
    std::cerr << "exception: " << e.what() << '\n';
  }
}