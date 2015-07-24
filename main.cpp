#include <cstdlib>
 
#include <KDE/KApplication>
#include <KDE/KAboutData>
#include <KDE/KCmdLineArgs>
#include <KDE/KMessageBox>
#include <KDE/KLocale>
 
int main (int argc, char *argv[])
{
    KAboutData aboutData(
                         // The program name used internally.
                         "TestQt",
                         // The message catalog name
                         // If null, program name is used instead.
                         0,
                         // A displayable program name string.
                         ki18n("Test"),
                         // The program version string.
                         "1.0",
                         // Short description of what the app does.
                         ki18n("Displays a KMessageBox popup"),
                         // The license this code is released under
                         KAboutData::License_GPL,
                         // Copyright Statement
                         ki18n("(c) 2015"),
                         // Optional text shown in the About box.
                         // Can contain any information desired.
                         ki18n("Some text..."),
                         // The program homepage string.
                         "https://github.com/montimaj",
                         // The bug report email address
                         "submit@bugs.kde.org");
 
    KCmdLineArgs::init( argc, argv, &aboutData );
    KApplication app;
    KGuiItem yesButton( i18n( "Hello" ), QString(),
                        i18n( "This is Sparta!" ),
                        i18n( "You're dead" ) );
    return 
        KMessageBox ::questionYesNo 
        (0, i18n( "Hello World" ), i18n("!"),yesButton ) 
        == KMessageBox ::Yes? EXIT_SUCCESS: EXIT_FAILURE;
}