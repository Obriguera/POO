#ifndef SALUDOS_GLOBAL_H
#define SALUDOS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SALUDOS_LIBRARY)
#  define SALUDOS_EXPORT Q_DECL_EXPORT
#else
#  define SALUDOS_EXPORT Q_DECL_IMPORT
#endif

#endif // SALUDOS_GLOBAL_H
