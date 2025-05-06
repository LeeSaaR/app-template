#include "appfontdata.h"

#include <QFontDatabase>
#include <QDebug>

void AppFontData::initApplicationFonts()
{
    //QFontDatabase::removeAllApplicationFonts(); // <-- Only for Deployment
    // Lato
    addToFontDatabase(":/fonts/Lato/Lato-Regular.ttf");     // Lato
    addToFontDatabase(":/fonts/Lato/Lato-Bold.ttf");        // Lato
    addToFontDatabase(":/fonts/Lato/Lato-BoldItalic.ttf");  // Lato
    addToFontDatabase(":/fonts/Lato/Lato-Italic.ttf");      // Lato
    addToFontDatabase(":/fonts/Lato/Lato-Black.ttf");       // Lato Black
    addToFontDatabase(":/fonts/Lato/Lato-BlackItalic.ttf"); // Lato Black
    addToFontDatabase(":/fonts/Lato/Lato-Light.ttf");       // Lato Light
    addToFontDatabase(":/fonts/Lato/Lato-LightItalic.ttf"); // Lato Light
    addToFontDatabase(":/fonts/Lato/Lato-Thin.ttf");        // Lato Hairline
    addToFontDatabase(":/fonts/Lato/Lato-ThinItalic.ttf");  // Lato Hairline

    // Ubuntu
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-R.ttf");  // Ubuntu
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-B.ttf");  // Ubuntu
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-RI.ttf"); // Ubuntu
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-BI.ttf"); // Ubuntu
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-L.ttf");  // Ubuntu Light
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-LI.ttf"); // Ubuntu Light
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-M.ttf");  // Ubuntu Light
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-MI.ttf"); // Ubuntu Light
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-Th.ttf"); // Ubuntu Thin
    addToFontDatabase(":/fonts/Ubuntu/Ubuntu-C.ttf");  // Ubuntu Condensed

    // Arial
    addToFontDatabase(":/fonts/Arial/arial.ttf");   // Arial
    addToFontDatabase(":/fonts/Arial/arialbd.ttf"); // Arial
    addToFontDatabase(":/fonts/Arial/arialbi.ttf"); // Arial
    addToFontDatabase(":/fonts/Arial/ariali.ttf");  // Arial
    addToFontDatabase(":/fonts/Arial/ariblk.ttf");  // Arial Black

    // Monospace
    // IBM Plex Mono
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Regular.ttf");          // IBM Plex Mono
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Bold.ttf");             // IBM Plex Mono
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Italic.ttf");           // IBM Plex Mono
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-BoldItalic.ttf");       // IBM Plex Mono
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Thin.ttf");             // IBM Plex Mono Thin
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-ThinItalic.ttf");       // IBM Plex Mono Thin
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-ExtraLight.ttf");       // IBM Plex Mono ExtraLight
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-ExtraLightItalic.ttf"); // IBM Plex Mono ExtraLight
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Light.ttf");            // IBM Plex Mono Light
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-LightItalic.ttf");      // IBM Plex Mono Light
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-Medium.ttf");           // IBM Plex Mono Medium
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-MediumItalic.ttf");     // IBM Plex Mono Medium
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-SemiBold.ttf");         // IBM Plex Mono SemiBold
    addToFontDatabase(":/fonts/Monospace/IBM_Plex_Mono/IBMPlexMono-SemiBoldItalic.ttf");   // IBM Plex Mono SemiBold
}

void AppFontData::addToFontDatabase(const QString &fontFileName)
{
    int id = QFontDatabase::addApplicationFont(fontFileName);
    //QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    //qDebug() << "family:" << id << family;
    if (id == -1)
        qDebug() << "Could not load:" << fontFileName;
}
