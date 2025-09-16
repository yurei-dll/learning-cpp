#include <iostream>
#include <args.hxx>
using namespace std;

int main(int argc, char **argv)
{
    args::ArgumentParser parser("This program greets a user.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Positional<std::string> name(parser, "name", "The name to greet");
    args::CompletionFlag completion(parser, {"complete"});

    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Completion &e)
    {
        std::cout << e.what();
        return 0;
    }
    catch (const args::Help &)
    {
        std::cout << parser;
        return 0;
    }
    catch (const args::ParseError &e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if (name)
        cout << "Hello " << name.Get() << endl;
    return 0;
}